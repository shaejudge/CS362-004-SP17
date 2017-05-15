#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "asserttrue.h"

int testAdventurer(int p, struct gameState *state){
	//set current deck size to variable
	int currentDeck = state->deckCount[0];
	int afterDeck;
	int deckDif;
	
	int temphand[MAX_HAND];
	int drawntreasure=0;
	int cardDrawn;
	int z = 0;
	
	printf("Deck Size Before: %d\n", currentDeck);
	
	//draw Adventurer
	useAdventurer(drawntreasure, 0, state, cardDrawn, temphand, z);
		
	//check to see if deck size decreased by 3
	afterDeck = state->deckCount[0];
	printf("Deck Size After: %d\n", afterDeck);	
		
	deckDif = currentDeck - afterDeck;
	printf("Player should have 3 less cards, and has %d less cards\n", deckDif);
	assertTrue(deckDif == 3);
	
	return 0;
}

int main(int argc, char **argv){
	int i, n, r, p, deckCount, discardCount, handCount;

	int k[10] = {village, estate, duchy, province, copper, silver, smithy, gold, adventurer,  gardens};

	struct gameState G;

	printf ("Testing Adventurer.\n");

	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);
	
	G.deck[0][0] = k[5];

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		testAdventurer(p, &G);
	}
}