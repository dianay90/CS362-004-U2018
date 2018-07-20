#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"

#include "rngs.h"

/* Testing Adventurer */

void assert( int value)
{

printf("FAILED TEST. RETURN VALUE SHOULD BE %d\n",value);

}


int main()
{

int gameStatus; 

int bonus =0; 
/* GameState unit test */ 
int i;
struct gameState  Game1; 

//int hand = Game1.handCount[0]; 
//int deck =Game1.deckCount[0];
 
int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 

Game1.handCount[0]= 4; 
Game1.deckCount[0]=0;
Game1.discardCount[0] =0; 

/* Discard an estate for +4 */
Game1.hand[0][0] = estate; 
Game1.hand[0][1] = copper; 
Game1.hand[0][2] = province; 
Game1.hand[0][3] = copper; 
//Game1.deck[0][4] = smithy; 
int purse=0; 

int count = Game1.deckCount[0];



printf("FIRST TEST: DISCARD AN ESTATE FOR FOUR COINS \n\n");


printf("Coin  value: %d\n\n", purse); purse =0; 
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



cardEffect(15, 1,0, 0 ,&Game1, 0, &bonus); 

printf("After estate card, case discard estate  called \n");




printf("Contents of new hand - should be one less \n"); 


for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);
	if (Game1.hand[0][i] == 1)
	{
		//countEstate++; 
	}
}



//int i; 
int estateFlag; 

for(i=0; i< Game1.handCount[0]; i++)
{
//printf("Card: %d \n", Game1.handCount[0][i]"); 


if (Game1.hand[0][i] == 1)
{
 printf("TEST FAILURE: Estate card is still in hand \n");
estateFlag =0; 
break;
}

}



if (estateFlag !=0)
{
printf("TEST SUCCESS: ESTATE CARD REMOVED  \n");
}


printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);


/* No state should occur for other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);


/*TEST FOR THE SECOND CASE FOR BARON CARD */ 

printf(" \n\n");









printf("SECOND  TEST: GAIN AN ESTATE \n\n");

printf("Now testing when player wants to gain an estate card instead");


Game1.handCount[0] = 4;
Game1.deckCount[0] = 0;
Game1.discardCount[0] = 0;

/* Discard an estate for +4 */
Game1.hand[0][0] = estate;
Game1.hand[0][1] = silver;
Game1.hand[0][2] = province;
Game1.hand[0][3] = silver;
//Game1.deck[0][4] = smithy; 
 purse = 0;

count = Game1.deckCount[0];

for (i = 0; i< Game1.handCount[0]; i++)

{
	if (Game1.hand[0][i] == copper)
	{
		purse += 1;
	}


	if (Game1.hand[0][i] == silver)
	{
		purse += 2;

	}

	if (Game1.hand[0][i] == gold)
	{
		purse += 3;
	}

}



for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);
	if (Game1.hand[0][i] == 1)
	{
		//countEstate++; 
	}
}


printf("Coin  value: %d\n\n", purse); purse =0; 

printf("Player one deck contains one estate, two silvers, and one province card\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*State of other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);





cardEffect(15, 0, 0, 0, &Game1, 0, &bonus);

printf("Contents of player 1 hand \n");

int countEstate = 0; 
for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);
	if (Game1.hand[0][i] == 1)
	{
		countEstate++; 
	}
}



if (countEstate == 2)
{

	printf("TEST SUCCESSFUL ONE MORE ESTATE VALUE ADDED \n");
}

else
{
	printf("TEST FAILURE: ADDITIONAL ESTATE NOT FOUND \n");
}



for (i = 0; i< Game1.handCount[0]; i++)

{
	if (Game1.hand[0][i] == copper)
	{
		purse += 1;
	}


	if (Game1.hand[0][i] == silver)
	{
		purse += 2;

	}

	if (Game1.hand[0][i] == gold)
	{
		purse += 3;
	}



}

//Coin value should remain the same 
printf("Coin  value: %d\n", purse);



printf("Player one deck contains one estate, two silvers, and one province card\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*State of other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);





return 0; 
}
