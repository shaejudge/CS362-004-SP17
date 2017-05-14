#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "asserttrue.h"

int main(){
	printf("Card Test 1 - Adventurer\n");
	
	//initialize
	struct gameState state;
	
	int temphand[MAX_HAND];// moved above the if statement
	int drawntreasure=0;
	int cardDrawn;
	int z = 0;
		
	int card[] = {village, estate, duchy, province, copper, silver, smithy, gold, adventurer, feast, gardens};
		
	initializeGame(2, card, 1, &state);

	state.deck[0][0] = card[5];
	
	state.deckCount[0] = 10;

	//Draw smithy card
	printf("Play Adventurer\n");
	useAdventurer(drawntreasure, 0, &state, cardDrawn, temphand, z);

	//Check
	printf("Player should have 8 cards, and has %d cards\n", state.deckCount[0]);
	assertTrue(state.deckCount[0] == 8);
	
	return 0;
}