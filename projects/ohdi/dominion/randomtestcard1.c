#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Testing Smithy */
int NUMTRIES = 2;
int prevHandCount, prevDeckCount, prevDiscardCount;
int i;
int fail = 0; int original[5]; int returnRandom(int lower, int upper) {
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}


void playerLineStatus(int playerNumber, struct gameState *state) {
	int i = 0; int player = 0;
	for (i = 0; i < playerNumber; i++)
	{
		player = i + 1;
		printf("Number of cards in player %d hand: %d, deck: %d, discard pile %d \n\n", player, state->handCount[i], state->deckCount[i],
			state->discardCount[i]);
	}
}


void supplyAndCards(struct gameState *state)
{
	printf("Number of estate cards: %d \n", state->supplyCount[estate]);
	printf("Number of duchy cards: %d \n", state->supplyCount[duchy]);
	printf("Number of province cards: %d \n", state->supplyCount[province]);

	printf("Kingdom Cards \n");
	printf("Number of baron cards: %d \n", state->supplyCount[baron]);
	printf("Number of feast cards: %d \n", state->supplyCount[feast]);
	printf("Number of garden cards: %d \n", state->supplyCount[gardens]);
	printf("Number of remodel cards: %d \n", state->supplyCount[remodel]);
	printf("Number of council room cards: %d \n", state->supplyCount[council_room]);
	printf("Number of mine cards: %d \n", state->supplyCount[mine]);
	printf("Number of village cards: %d \n", state->supplyCount[village]);
	printf("Number of smithy cards: %d \n", state->supplyCount[smithy]);
	printf("Number of adventurer cards: %d \n", state->supplyCount[adventurer]);
	printf("Number of great hall cards: %d \n", state->supplyCount[great_hall]);
	printf("\n");
}


void assert(int value)
{

	if (value == 6)
	{
		printf("FAILED TEST:");
		fail = 1;
	}

	else {
		printf("FAILED TEST. RETURN VALUE SHOULD BE %d\n", value);
		fail = 1;
	}
}


void printGameStatus(struct gameState *state, int chosenPlayer) {

printf("game status printing %d \n", chosenPlayer);
	for (i = 0; i < state->deckCount[chosenPlayer]; i++)
	{

	
		printf("Player %d Deck: %d\n", chosenPlayer, state->deck[chosenPlayer][i]);
	}
	printf("\n");
	for (i = 0; i < state->discardCount[chosenPlayer]; i++)
	{
		printf("Player %d Discard: %d\n", chosenPlayer, state->discard[chosenPlayer][i]);
	}
	printf("\n");
	for (i = 0; i < state->handCount[chosenPlayer]; i++)
	{
		printf("Player %d Hand: %d\n", chosenPlayer, state->hand[chosenPlayer][i]);
	}
	printf("\n");
}



void chosenPlayerRandomize(int chosenPlayer, struct gameState *state) {
	int i;
	//	int handCount = rand() % MAX_HAND;
	int handCount = returnRandom(5, 10);
	state->handCount[chosenPlayer] = handCount;
	//printf("printing hand count %d \n",state->handCount[chosenPlayer]); 
	int maxCoins = returnRandom(2, 5);

	//	int maxDeckCount = rand() % MAX_DECK;
	int maxDeckCount = returnRandom(5, 10);
	state->deckCount[chosenPlayer] = maxDeckCount;

	int maxDiscardCount = returnRandom(5, 10);
	state->discardCount[chosenPlayer] = maxDiscardCount;

	int totalHandCount = handCount + maxCoins;
	int coins[3] = { copper, silver, gold };

	int otherCards[24] = {
		curse,
		estate,
		duchy,
		province,
		adventurer,
		council_room,
		feast,
		gardens,
		mine,
		remodel,
		smithy,
		village,
		baron,
		great_hall,
		minion,
		steward,
		tribute,
		ambassador,
		cutpurse,
		embargo,
		outpost,
		salvager,
		sea_hag,
		treasure_map };
	/*Set hand */
	for (i = 0; i < totalHandCount - maxCoins; i++)
{



		state->hand[chosenPlayer][i] = otherCards[rand() % 24];
		
//printf("hand of chosen player %d, %d \n", chosenPlayer, state->hand[chosenPlayer][i]);	

}

state->hand[chosenPlayer][1]= smithy; 
state->hand[chosenPlayer][2]= smithy;

	int trackI = i + 1;
	for (i = 0; i < maxCoins; i++)
	{
		state->hand[chosenPlayer][trackI++] = coins[rand() % 3];
	}
	for (i = 0; i < 5; i++)
	{
		original[i] = state->hand[chosenPlayer][i];
	}
	/*Set discard*/
	for (i = 0; i < maxDiscardCount; i++)
	{
		state->discard[chosenPlayer][i] = otherCards[rand() % 24];
	}
	/*Set deck count */
	for (i = 0; i < maxDeckCount; i++)
	{
		state->deck[chosenPlayer][i] = otherCards[rand() % 24];
	}
	prevHandCount = state->handCount[chosenPlayer];
	prevDeckCount = state->deckCount[chosenPlayer];
	prevDiscardCount = state->discardCount[chosenPlayer];
}




int main()
{

	printf("SMITHY TEST\n\n");
	//int gameStatus; 
	/* GameState unit test */


int randSeed; 


	while (NUMTRIES > 0)

	{

		struct gameState  Game1;

		int kingdomCards[10] = { baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall };

		randSeed  = rand(); 
		/* 2-4 players*/
		int playerNumber = rand() % 3 + 2;

		printf("Number of players: %d \n", playerNumber);
		initializeGame(playerNumber, kingdomCards, randSeed, &Game1);

		/* Choose random player from total number of players */
		//int chosenPlayer = rand() % playerNumber;
		int chosenPlayer = whoseTurn(&Game1);

	
		printf("Chosen Player playing Smithy Card: %d \n", chosenPlayer);

		for (i = 0; i < playerNumber; i++)
		{
			chosenPlayerRandomize(i, &Game1);
			printf("in chosen players randomize loop \n"); 
		}
		int hand = Game1.handCount[chosenPlayer];
		/*keep track of supply count*/
		int prevEstateSupplyCount = Game1.supplyCount[estate];
		int prevDuchySupplyCount = Game1.supplyCount[duchy];
		int prevPrivinceSupplyCount = Game1.supplyCount[province];
		/*Current Player should receive exactly 3 cards*/

		/* 3 cards should come from his own pile */

		printf("\n");

		/* print game status of random players */
		printf("Chosen Player playing Smithy Card: %d \n", chosenPlayer);


printf("player number right before game stauts %d\n", playerNumber);
	int k; 	
	for (k = 0; k < playerNumber; k++)
		{
		//	printf ("in here");
			printGameStatus(&Game1, k);
		}



//printGameStatus( &Game1, 1);
		supplyAndCards(&Game1);

		cardEffect(smithy, 0, 0, 0, &Game1, 2, 0);

		printf("After Smithy card called \n");


 	
	for (k = 0; k < playerNumber; k++)
		{
			printf ("in here");
			printGameStatus(&Game1, k);
		}



		supplyAndCards(&Game1);


		if (Game1.handCount[chosenPlayer] != hand + 3)
		{
			assert(6);
			printf("Hand count did not increment by 3. \n");

		}

		else
		{
			if (original[0] == Game1.hand[chosenPlayer][0] && original[1] == Game1.hand[chosenPlayer][1] && original[2] == Game1.hand[chosenPlayer][2] && original[3] == Game1.hand[chosenPlayer][3] && original[4] == Game1.hand[chosenPlayer][4])
			{
				printf("TEST SUCCESS:Hand count incremented by 3. \n");

			}

			else {
				assert(6);

				printf("Hand count did not succesfully increment by 3 with proper values \n");
			}
		}


		printf("Chosen Player playing Smithy Card: %d \n", chosenPlayer);

		if (prevDuchySupplyCount != Game1.supplyCount[duchy] || prevDuchySupplyCount != Game1.supplyCount[estate] || prevEstateSupplyCount != Game1.supplyCount[province] || prevPrivinceSupplyCount)
		{
			assert(6);
			printf("Supply counts different after function call \n");
			fail = 1;
		}


		else
		{
			printf("TEST SUCCESS: Supply counts same after function call \n");


		}
		printf("\n");






		if (fail == 1)
		{
			printf("TEST FAILURE. TEST CONTAINED  ONE OR MORE ERRORS.\n");
		}

		else
		{
			printf("TEST SUCCESSFUL. NO ERRORS FOUND.\n");

		}

		NUMTRIES--;
		fail = 0;
	}
	//printf("."); 

	return 0;


}
