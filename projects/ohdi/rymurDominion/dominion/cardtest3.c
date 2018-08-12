#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#include "rngs.h"


/* Testing Baron*/


int fail = 0;
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



int main()
{

//int gameStatus; 

int bonus =0; 
/* GameState unit test */ 
int i;
struct gameState  Game1; 

//int hand = Game1.handCount[0]; 
//int deck =Game1.deckCount[0];
 
int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 

 
Game1.deckCount[0]=0;
Game1.discardCount[0] =0; 

/* Discard an estate for +4 */
Game1.hand[0][0] = estate; 
Game1.hand[0][1] = copper; 
Game1.hand[0][2] = province; 
Game1.hand[0][3] = copper; 
//Game1.deck[0][4] = smithy; 
//int purse=0; 

int prevCoins;

prevCoins = Game1.coins; 
int prevHandCount = Game1.handCount[0];

//	
//int count = Game1.deckCount[0];



printf("FIRST TEST: DISCARD AN ESTATE FOR FOUR COINS \n\n");



printf("Player one deck contains one estate, two silvers, and one province card\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*State of other players */ 

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);



for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);
	if (Game1.hand[0][i] == 1)
	{
		//countEstate++; 
	}
}

printf (" Number of coins: %d \n",Game1.coins );


cardEffect(15, 1,0, 0 ,&Game1, 0, &bonus); 

printf("FUNCTION CALLED.  \n");


printf("Contents of new hand - should be one less \n"); 

printf("\n");


for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);
	if (Game1.hand[0][i] == 1)
	{
		//countEstate++; 
	}
}



int estateFlag; 



printf("\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);


/* No state should occur for other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);

printf ("Number of coins: %d \n",Game1.coins );


int j; 
for(j =0; j< Game1.handCount[0]; j++) 
{
if (Game1.hand[0][j] == 15)
{

	assert(6);
	printf("Baron card is still in hand \n");
	estateFlag = 0;
	break;
}

}


if (estateFlag != 0)
{
	printf("TEST SUCCESS: BARON CARD REMOVED  \n");
}


if (prevCoins + 4 == Game1.coins)
{
	printf("TEST SUCCESS: +4 coins added  \n");

}

else
{
	assert(6);
	printf("+4 coins not added  \n");
}


if (prevHandCount == 1 + Game1.handCount[0])
{
	printf("TEST SUCCESS: NEW HAND COUNT IS ONE LESS \n");
}

else
{
	assert(6); 
	printf("NEW HAND COUNT IS NOT ONE LESS \n");
}










/*TEST FOR THE SECOND CASE FOR BARON CARD */ 

printf(" \n\n");

struct gameState  Game2;

//int hand = Game1.handCount[0]; 
//int deck =Game1.deckCount[0];

int kingdomCards2[10] = { baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall };

initializeGame(2, kingdomCards2, 5, &Game2);





printf("SECOND  TEST: GAIN AN ESTATE \n\n");

printf("Now testing when player wants to gain an estate card instead\n");

printf("\n");


Game2.handCount[0] = 4;
Game2.deckCount[0] = 0;
Game2.discardCount[0] = 0;

/* Discard an estate for +4 */
Game2.hand[0][0] = silver;
Game2.hand[0][1] = silver;
Game2.hand[0][2] = province;
Game2.hand[0][3] = silver;
//Game2.deck[0][4] = smithy; 
// purse = 0;

//int count = Game2.deckCount[0];

int prevGame2Coins = Game2.coins; 


for (i = 0; i < Game2.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game2.hand[0][i]);
	if (Game2.hand[0][i] == 1)
	{
		//countEstate++; 
	}
}



for (i = 0; i < Game2.deckCount[0]; i++)
{

	printf("Player 1 Deck: %d\n", Game2.deck[0][i]);
	if (Game2.deck[0][i] == 1)
	{
//		countEstate++; 
	}
}



for (i = 0; i < Game2.discardCount[0]; i++)
{

	printf("Player 1 Discard: %d\n", Game2.discard[0][i]);
	if (Game2.discard[0][i] == 1)
	{
	//	countEstate++; 
	}
}


printf("\n");



printf("Player one deck contains one estate, two silvers, and one province card\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game2.handCount[0], Game2.deckCount[0], Game2.discardCount[0]);

/*State of other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game2.handCount[1], Game2.deckCount[1], Game2.discardCount[1]);




cardEffect(15, 0, 0, 0, &Game2, 0, &bonus);


printf("Contents of player 1 hand \n");

int countEstate = 0; 
for (i = 0; i < Game2.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game2.hand[0][i]);
	if (Game2.hand[0][i] == 1)
	{
		countEstate++; 
	}
}



for (i = 0; i < Game2.deckCount[0]; i++)
{

	printf("Player 1 Deck: %d\n", Game2.deck[0][i]);
	if (Game2.deck[0][i] == 1)
	{
		countEstate++; 
	}
}

printf("\n");

for (i = 0; i < Game2.discardCount[0]; i++)
{

	printf("Player 1 Discard: %d\n", Game2.discard[0][i]);
	if (Game2.discard[0][i] == 1)
	{
		countEstate++; 
	}
}




if (prevGame2Coins == Game2.coins)
{
	printf("TEST SUCCESS: COINS UNAFFECTED\n");
}

else
{
	assert(6); 
	printf(" COIN NUMBER AFFECTED\n");

}



if (countEstate == 1)
{

	printf("TEST SUCCESSFUL ONE MORE ESTATE VALUE ADDED IN DISCARD PILE. ESTATE CARD ENUM IS 1\n");
}

else
{
	assert(6);
	printf(" ADDITIONAL ESTATE NOT FOUND \n");
}




printf("\n");


printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game2.handCount[0], Game2.deckCount[0], Game2.discardCount[0]);

/*State of other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game2.handCount[1], Game2.deckCount[1], Game2.discardCount[1]);


if (fail == 1)
{
	printf("TEST FAILURE. TEST CONTAINED  ONE OR MORE ERRORS.\n");
}
else
{
	printf("TEST SUCCESSFUL. NO ERRORS FOUND.\n");
}



return 0; 
}
