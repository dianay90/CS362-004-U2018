#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>

/* Testing Adventurer */
int NUMTRIES = 4;
int fail = 0, i =0; 
int prevHandCount, prevDeckCount, prevDiscardCount;

void playerLineStatus(int playerNumber, struct gameState *state)
{
	int i = 0; int player=0;
	
	for (i = 0; i < playerNumber; i++)
	{
		player = i + 1;
		printf("Number of cards in player %d hand: %d, deck: %d, discard pile %d \n\n", player, state->handCount[i], state->deckCount[i], state->discardCount[i]);
	}
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

int returnRandom(int lower, int upper)
{

	int num = (rand() % (upper - lower + 1)) + lower;
	return num; 
}





void chosenPlayerRandomize(int chosenPlayer, struct gameState *state)
{
	int i;

//	int handCount = rand() % MAX_HAND;
	int handCount = returnRandom(5,10); 

	state->handCount[chosenPlayer] = handCount;

	int maxCoins = returnRandom(2, 5);

//	int maxDeckCount = rand() % MAX_DECK;
	int maxDeckCount = returnRandom(5,10);

	state->deckCount[chosenPlayer] = maxDeckCount;

	int maxDiscardCount = returnRandom(5,10); 
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

void printGameStatus(struct gameState *state, int chosenPlayer)
{
	for (i = 0; i < state->deckCount[chosenPlayer]; i++)
	{

		printf("Player Deck: %d\n", state->deck[chosenPlayer][i]);

	}

	printf("\n");

	for (i = 0; i < state->discardCount[chosenPlayer]; i++)
	{

		printf("Player Discard: %d\n", state->discard[chosenPlayer][i]);

	}

	printf("\n");


	for (i = 0; i < state->handCount[chosenPlayer]; i++)
	{

		printf("Player  Hand: %d\n", state->hand[chosenPlayer][i]);

	}

	printf("\n");



}





int main()
{
	srand(time(0));

	//int bonus=0; 
	printf("ADVENTURER RANDOMIZER TEST\n\n");

	struct gameState  Game1;

	int kingdomCards[10] = { baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall };

	/*Randomly choose 2 to 4 players */

	while (NUMTRIES > 0)

	{
		int playerNumber = rand() % 3 + 2;

		initializeGame(playerNumber, kingdomCards, 5, &Game1);
		printf("Current player: %d \n", whoseTurn(&Game1));

		/* Choose random player from total number of players */
		int chosenPlayer = rand() % playerNumber;

		chosenPlayerRandomize(chosenPlayer, &Game1);

		printf("Player one deck contains at least TWO treasure cards\n");

		printf("\n");

		printGameStatus(&Game1, chosenPlayer);


		int treasure = 0;
		int reject = 0;
		int deckMinus;

		for (i = 0; i < Game1.deckCount[chosenPlayer]; i++)
		{
			if (Game1.deck[chosenPlayer][i] == copper || Game1.deck[chosenPlayer][i] == silver || Game1.deck[chosenPlayer][i] == gold)
			{
				treasure++;

				if (treasure == 2)
				{
					break;
				}
			}
			else
			{
				reject++;
			}
		}

		deckMinus = treasure + reject;

		printGameStatus(&Game1, chosenPlayer);

		printf("Adventure function called\n");

		cardEffect(adventurer, 0, 0, 0, &Game1, 0, 0);

		printf("\n");
		//int i; 

		printGameStatus(&Game1, chosenPlayer);

		playerLineStatus(playerNumber, &Game1);


		if (Game1.discardCount[chosenPlayer] != prevDiscardCount + reject)
		{

			assert(6);
			printf("Discard pile does not have the right number of rejected cards\n");
			fail = 1;
		}


		if (Game1.handCount[chosenPlayer] != prevHandCount + treasure)
		{
			assert(6);
			printf("Hand  does not have the right number of treasure cards\n");
			fail = 1;
		}


		if (Game1.deckCount[chosenPlayer] != prevDeckCount - deckMinus)
		{
			assert(6);
			printf("Deck does not have the right number of cards subtracted. \n");
			fail = 1;
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
		treasure = 0; 
		reject = 0; 
		deckMinus = 0; 
		fail = 0; 
	}

	return 0;
}
