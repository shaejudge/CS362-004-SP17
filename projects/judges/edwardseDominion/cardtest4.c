#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "asserttrue.h"

int main(){
	printf("Card Test 4 - Great Hall\n");
	
	//initialize
	struct gameState state;
		
	int card[] = {great_hall, estate, duchy, province, copper, silver, smithy, gold, adventurer, feast, gardens};
		
	initializeGame(2, card, 1, &state);

	state.hand[0][0] = card[0];
	
	state.handCount[0] = 1;

	//Draw great hall card
	printf("Play Great Hall\n");
	playSmithy(0, &state);

	//Check
	printf("Player should have 2 cards, and has %d cards\n", state.handCount[0]);
	assertTrue(state.handCount[0] == 2);
	
	return 0;
}