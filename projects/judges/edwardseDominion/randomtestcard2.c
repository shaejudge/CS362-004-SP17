#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "asserttrue.h"

int testVillage(int p, struct gameState *state){
	//set current deck size to variable
	int currentDeck = state->handCount[p];
	int afterDeck;
	int deckDif;
	
	printf("Deck Size Before: %d\n", currentDeck);
	
	//draw Village
	playVillage(state, p);
		
	//check to see if deck size increased by 1
	afterDeck = state->handCount[p];
	printf("Deck Size After: %d\n", afterDeck);	
		
	deckDif = afterDeck - currentDeck;
	printf("Player should have 1 more card, and has %d more cards\n", deckDif);
	assertTrue(deckDif == 1);
	
	return 0;
}

int main(int argc, char **argv){
	int i, n, r, p, deckCount, discardCount, handCount;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
		   remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf ("Testing Village.\n");

	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
		  ((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.deckCount[p] = floor(Random() * MAX_DECK);
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * MAX_HAND);
		testVillage(p, &G);
	}
}