#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "asserttrue.h"

int main(){
	printf("Card Test 1 - Smithy\n");
	
	//initialize
	struct gameState state;
		
	int card[] = {village, estate, duchy, province, copper, silver, smithy, gold, adventurer, feast, gardens};
		
	initializeGame(2, card, 1, &state);

	state.hand[0][0] = card[6];
	
	state.handCount[0] = 1;

	//Draw smithy card
	printf("Play Smithy\n");
	useSmithy(0, &state);

	//Check
	printf("Player should have 4 cards, and has %d cards\n", state.handCount[0]);
	assertTrue(state.handCount[0] == 4);
	
	return 0;
}