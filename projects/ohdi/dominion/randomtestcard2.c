#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#include "rngs.h"

/* Testing SeaHag*/
int NUMTRIES = 2;
int fail = 0;

int prevHandCount0, prevDeckCount0, prevDiscardCount0, prevHandCount1, prevDeckCount1, prevDiscardCount1,
prevHandCount2, prevDeckCount2, prevDiscardCount2;

int i;  int original[5]; int returnRandom(int lower, int 
upper) {
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}
void playerLineStatus(int playerNumber, struct gameState *state) {
	int i = 0; int player = 0;
	for (i = 0; i < playerNumber; i++)
	{
		player = i + 1;

		printf("Number of cards in player %d hand: %d, deck: %d, discard pile %d \n\n", player, state->handCount[i], state->deckCount[i], state->discardCount[i]);
	}
}



void supplyAndCards(struct gameState *state) {
	printf("Number of estate cards: %d \n", 
state->supplyCount[estate]);
	printf("Number of duchy cards: %d \n", state->supplyCount[duchy]);
	printf("Number of province cards: %d \n", 
state->supplyCount[province]);
	printf("Kingdom Cards \n");
	printf("Number of baron cards: %d \n", state->supplyCount[baron]);
	printf("Number of feast cards: %d \n", state->supplyCount[feast]);
	printf("Number of garden cards: %d \n", 
state->supplyCount[gardens]);
	printf("Number of remodel cards: %d \n", 
state->supplyCount[remodel]);
	printf("Number of council room cards: %d \n", 
state->supplyCount[council_room]);
	printf("Number of mine cards: %d \n", state->supplyCount[mine]);
	printf("Number of village cards: %d \n", 
state->supplyCount[village]);
	printf("Number of smithy cards: %d \n", 
state->supplyCount[smithy]);
	printf("Number of adventurer cards: %d \n", 
state->supplyCount[adventurer]);
	printf("Number of great hall cards: %d \n", 
state->supplyCount[great_hall]);
	printf("\n");
}
void assert(int value) {
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
	for (i = 0; i < state->deckCount[chosenPlayer]; i++)
	{
		printf("Player %d Deck: %d\n", chosenPlayer, 
state->deck[chosenPlayer][i]);
	}
	printf("\n");
	for (i = 0; i < state->discardCount[chosenPlayer]; i++)
	{
		printf("Player %d Discard: %d\n", chosenPlayer, 
state->discard[chosenPlayer][i]);
	}
	printf("\n");
/*
	for (i = 0; i < state->handCount[chosenPlayer]; i++)
	{
		printf("Player %d Hand: %d\n", chosenPlayer, 
state->hand[chosenPlayer][i]);
	}

*/
	printf("\n");
}
void chosenPlayerRandomize(int chosenPlayer, struct gameState *state) 
{
	int i;
	//	int handCount = rand() % MAX_HAND;
	int handCount = returnRandom(5, 10);
	state->handCount[chosenPlayer] = handCount;
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
	}
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
//int	prevHandCount = state->handCount[chosenPlayer];
//int 	prevDeckCount = state->deckCount[chosenPlayer];
//int 	prevDiscardCount = state->discardCount[chosenPlayer];
}





int main()
{
	//printf(" Each other player discards the top card of their deck, then gains a curse into their deck."\n);
	printf("SEAHAG CARD BEING TESTED \n\n");
int randSeed; 

	while (NUMTRIES > 0)

	{

	randSeed =rand(); 
		//	int gameStatus;
		//	int  prevPlayer1DiscardCount;
		int bonus = 0;
		/* GameState unit test */
		int i;
		struct gameState  Game1;

		int kingdomCards[10] = { baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall };

		initializeGame(3, kingdomCards, randSeed, &Game1);

		int playerNumber = rand() % 3 + 2;
		if (playerNumber == 4)
		{
			playerNumber--;
		}
		printf("Number of players: %d \n", playerNumber);
		initializeGame(playerNumber, kingdomCards, 5, &Game1);
		/* Choose random player from total number of players */
		//int chosenPlayer = rand() % playerNumber;
		int chosenPlayer = whoseTurn(&Game1);
		printf("Chosen Player playing SeaHag Card: %d \n", chosenPlayer);
		
		for (i = 0; i < playerNumber; i++)
		{
			chosenPlayerRandomize(i, &Game1);
		}


		if (playerNumber == 2)
		{
			 prevHandCount0 = Game1.handCount[0];
			 prevDeckCount0 = Game1.deckCount[0];
			 prevDiscardCount0 = Game1.discardCount[0];

			 prevHandCount1 = Game1.handCount[1];
			 prevDeckCount1 = Game1.deckCount[1];
			 prevDiscardCount1 = Game1.discardCount[1];
		}

		else if (playerNumber == 3)
		{
			 prevHandCount0 = Game1.handCount[0];
			 prevDeckCount0 = Game1.deckCount[0];
			 prevDiscardCount0 = Game1.discardCount[0];

			 prevHandCount1 = Game1.handCount[1];
			 prevDeckCount1 = Game1.deckCount[1];
			 prevDiscardCount1 = Game1.discardCount[1];

			 prevHandCount2 = Game1.handCount[2];
			 prevDeckCount2 = Game1.deckCount[2];
			 prevDiscardCount2 = Game1.discardCount[2];

		}


		printf("Chosen Player playing SeaHag Card: %d \n", chosenPlayer);

		int k;
		for (k = 0; k < playerNumber; k++)
		{
			//	printf ("in here");
			printGameStatus(&Game1, k);
		}


		for (k = 0; k < playerNumber; k++)
		{
			playerLineStatus(k, &Game1);

		}
		cardEffect(25, 0, 0, 0, &Game1, 0, &bonus);

		printf("SEAHAG CALLED. After calling sea hag function. Affected players get top part of their deck replaced by curse card. \n");

		printf("\n");
		for (k = 0; k < playerNumber; k++)
		{
			//	printf ("in here");
			printGameStatus(&Game1, k);
		}


		for (k = 0; k < playerNumber; k++)
		{
			playerLineStatus(k, &Game1);

		}

	
		if (playerNumber == 2)
		{

			if (chosenPlayer == 0)
			{
				if (prevDeckCount1 != Game1.deckCount[1])
				{
					printf("\n");

					assert(6);
					printf("Other players deck size  should be same as before sea hag was played. \n");

					printf("\n");

				}
			}

			else if (chosenPlayer == 1)
			{
				if (prevDeckCount0 != Game1.deckCount[0])
				{
					printf("\n");

					assert(6);
					printf("Other players deck size  should be same as before sea hag was played. \n");

					printf("\n");

				}


			}
			

		}

		else if (playerNumber == 3)
		{
			if (chosenPlayer == 0)
			{
				if (prevDeckCount1 != Game1.deckCount[1] || prevDeckCount2 != Game1.deckCount[2])
				{
					printf("\n");

					assert(6);
					printf("Other players deck size  should be same as before sea hag was played. \n");

					printf("\n");

				}

			}

			else if (chosenPlayer == 1)
			{

				if (prevDeckCount0 != Game1.deckCount[0] || prevDeckCount2 != Game1.deckCount[2])
				{
					printf("\n");

					assert(6);
					printf("Other players deck size  should be same as before sea hag was played. \n");

					printf("\n");

				}
			}

			else if (chosenPlayer == 2)
			{
				if (prevDeckCount0 != Game1.deckCount[0] || prevDeckCount1 != Game1.deckCount[1])
				{
					printf("\n");

					assert(6);
					printf("Other players deck size  should be same as before sea hag was played. \n");

					printf("\n");

				}

			}

		}

		
		printf("Chosen Player playing SeaHag Card: %d \n", chosenPlayer);


		/* Curse card? 2 player situation 0,1 and 3 players situation  0,1, 2*/


		if (playerNumber == 2)
		{

			if (chosenPlayer == 0)
			{
				if (Game1.deck[1][0] != curse)
				{
					printf("\n");

					assert(6);
					printf("Other players deck size should contain a curse card . \n");

					printf("\n");

				}
			}

			else if (chosenPlayer == 1)
			{
				if (Game1.deck[0][0] != curse)
				{
					printf("\n");

					assert(6);
					printf("Other players deck size should contain a curse card . \n");

					printf("\n");

				}


			}


		}

		else if (playerNumber == 3)
		{
			if (chosenPlayer == 0)
			{
				if (Game1.deck[1][0] != curse || Game1.deck[2][0] != curse)
				{
					printf("\n");

					assert(6);
					printf("Other players deck size should contain a curse card . \n");

					printf("\n");

				}


			}

			else if (chosenPlayer == 1)
			{

				if (Game1.deck[0][0] != curse || Game1.deck[2][0] != curse)
				{
					printf("\n");

					assert(6);
					printf("Other players deck size should contain a curse card . \n");

					printf("\n");

				}
			}

			else if (chosenPlayer == 2)
			{
				if (Game1.deck[1][0] != curse || Game1.deck[0][0] != curse)
				{
					printf("\n");

					assert(6);
					printf("Other players deck size should contain a curse card . \n");

					printf("\n");

				}

			}

		}







		printf("\n");
		for (k = 0; k < playerNumber; k++)
		{
			//	printf ("in here");
			printGameStatus(&Game1, k);
		}


		for (k = 0; k < playerNumber; k++)
		{
			playerLineStatus(k, &Game1);

		}




		if (fail == 1)
		{
			printf("TEST FAILURE. TEST CONTAINED  ONE OR MORE ERRORS.\n");
		}
		else
		{
			printf("TEST SUCCESSFUL. NO ERRORS FOUND.\n");
		}

NUMTRIES--; 
	}
	return 0;
}
