#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#include "rngs.h"

/* Testing SeaHag*/

int fail=0; 
void assert(int value)
{

	if (value == 6)
	{
		printf("FAILED TEST:");
		fail =1; 
	}

	else {
		printf("FAILED TEST. RETURN VALUE SHOULD BE %d\n", value);
		fail =1; 
	}
}


int main()
{
	//printf(" Each other player discards the top card of their deck, then gains a curse into their deck."\n);
printf("SEAHAG CARD BEING TESTED \n\n");
//	int gameStatus;
	int prevPlayer1DeckCount, prevPlayer2DeckCount, prevPlayer3DeckCount;
//	int  prevPlayer1DiscardCount;
	int bonus = 0;
	/* GameState unit test */
	int i;
	struct gameState  Game1;

	int kingdomCards[10] = { baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall };

	initializeGame(3, kingdomCards, 5, &Game1);

	int currentPlayer = whoseTurn(&Game1);

	printf("Current player is %d \n", currentPlayer);


		Game1.deckCount[0] = 4;

	Game1.discardCount[0] = 4;

	prevPlayer1DeckCount = Game1.deckCount[0];
//	prevPlayer1DiscardCount = Game1.discardCount[0];


	/* Discard an estate for +4 */
	Game1.deck[0][0] = estate;
	Game1.deck[0][1] = copper;
	Game1.deck[0][2] = province;
	Game1.deck[0][3] = copper;

	Game1.discard[0][0] = smithy;
	Game1.discard[0][1] = copper;
	Game1.discard[0][2] = adventurer;
	Game1.discard[0][3] = copper;


	Game1.deckCount[1] = 4;
	Game1.discardCount[1] = 4;

	prevPlayer2DeckCount = Game1.deckCount[1];
//	prevPlayer2DiscardCount = Game1.discardCount[1];
		/* Discard an estate for +4 */
		Game1.deck[1][0] = smithy;
	Game1.deck[1][1] = copper;
	Game1.deck[1][2] = cutpurse;
	Game1.deck[1][3] = copper;

	Game1.discard[1][0] = smithy;
	Game1.discard[1][1] = copper;
	Game1.discard[1][2] = adventurer;
	Game1.discard[1][3] = copper;

	Game1.deckCount[2] = 4;
	Game1.discardCount[2] = 4;

	prevPlayer3DeckCount = Game1.deckCount[2];
	//prevPlayer3DiscardCount = Game1.discardCount[2];

	Game1.deck[2][0] = village;
	Game1.deck[2][1] = remodel;
	Game1.deck[2][2] = smithy;
	Game1.deck[2][3] = copper;

	Game1.discard[2][0] = smithy;
	Game1.discard[2][1] = copper;
	Game1.discard[2][2] = adventurer;
	Game1.discard[2][3] = copper;

	for (i = 0; i < Game1.deckCount[0]; i++)
	{

		printf("Player 1 Deck: %d\n", Game1.deck[0][i]);

	}


	printf(" \n");

	for (i = 0; i < Game1.discardCount[0]; i++)
	{

		printf("Player 1 Discard: %d\n", Game1.discard[0][i]);

	}

	printf("\n \n");



	for (i = 0; i < Game1.deckCount[1]; i++)
	{

		printf("Player 2 Deck: %d\n", Game1.deck[1][i]);

	}


	printf(" \n");

	for (i = 0; i < Game1.discardCount[1]; i++)
	{

		printf("Player 2 Discard: %d\n", Game1.discard[1][i]);

	}


	printf("\n \n");

	for (i = 0; i < Game1.deckCount[2]; i++)
	{

		printf("Player 3 Deck: %d\n", Game1.deck[2][i]);



		printf(" \n");

		for (i = 0; i < Game1.discardCount[2]; i++)
		{

			printf("Player 3 Discard: %d\n", Game1.discard[2][i]);

		}
		printf("\n \n");
	}

	cardEffect(25, 0, 0, 0, &Game1, 0, &bonus);


	printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

	/*State of other players */

	printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);


	printf("Number of cards in player 3 hand: %d, cards in player 3 deck: %d, cards in player 3 discard pile %d \n\n", Game1.handCount[2], Game1.deckCount[2], Game1.discardCount[2]);

	printf("After calling sea hag function. Affected players get top part of their deck replaced by curse card. \n");

	printf("\n");



	if (Game1.deckCount[1] != prevPlayer2DeckCount || Game1.deckCount[2] != prevPlayer3DeckCount)
	{
	printf("\n");

		assert(6);
		printf("Other players deck size  should be same as before sea hag was played. \n");

	printf("\n");

	}

	if (Game1.deckCount[0] != prevPlayer1DeckCount )
	{
	printf("\n");

		assert(6);
		printf("Player 1 deck count should be the same as before card was played. \n");

	printf("\n");

	}


	if (Game1.deckCount[1] > 0 && Game1.deckCount[2] > 0)
	{
		if (Game1.deck[1][0] != 0 || Game1.deck[2][0] != 0)
		{
			assert(6);

				printf("Other players deck size should be same as before sea hag was played. \n");

		}

	}


	for (i = 0; i < Game1.deckCount[0]; i++)
	{

		printf("Player 1 Deck: %d\n", Game1.deck[0][i]);

	}


	printf(" \n");

	for (i = 0; i < Game1.discardCount[0]; i++)
	{

		printf("Player 1 Discard: %d\n", Game1.discard[0][i]);

	}

	printf("\n \n");



	for (i = 0; i < Game1.deckCount[1]; i++)
	{

		printf("Player 2 Deck: %d\n", Game1.deck[1][i]);

	}


	printf(" \n");

	for (i = 0; i < Game1.discardCount[1]; i++)
	{

		printf("Player 2 Discard: %d\n", Game1.discard[1][i]);

	}


	printf("\n \n");

	for (i = 0; i < Game1.deckCount[2]; i++)
	{

		printf("Player 3 Deck: %d\n", Game1.deck[2][i]);


		printf(" \n");

		for (i = 0; i < Game1.discardCount[2]; i++)
		{

			printf("Player 3 Discard: %d\n", Game1.discard[2][i]);

		}
		printf("\n \n");
	}


	printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

	/*State of other players */

	printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);


	printf("Number of cards in player 3 hand: %d, cards in player 3 deck: %d, cards in player 3 discard pile %d \n\n", Game1.handCount[2], Game1.deckCount[2], Game1.discardCount[2]);

if(fail ==1)
{
printf("TEST FAILURE. TEST CONTAINED  ONE OR MORE ERRORS.\n");
}
else
{
printf("TEST SUCCESSFUL. NO ERRORS FOUND.\n"); 
}
	return 0;
}
