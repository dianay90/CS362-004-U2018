#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Testing Adventurer */

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


//int bonus=0; 
printf("ADVENTURER TEST\n\n");


//int gameStatus; 
/* GameState unit test */ 

struct gameState  Game1; 

//int hand = Game1.handCount[0]; 
//int deck =Game1.deckCount[0];
 
int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 
printf("Current player: %d \n", whoseTurn(&Game1));

Game1.handCount[0]= 4; 

Game1.hand[0][0]= smithy;
Game1.hand[0][1]= copper; 
Game1.hand[0][2]= smithy;
Game1.hand[0][3]= copper; 

int prevHandCount = Game1.handCount[0];

Game1.deckCount[0]=5;
int prevDeckCount = Game1.deckCount[0];

Game1.discardCount[0] =2; 
int prevDiscardCount = Game1.discardCount[0];

Game1.deck[0][0] = estate; 
Game1.deck[0][1] = copper; 
Game1.deck[0][2] = smithy; 
Game1.deck[0][3] = silver; 
Game1.deck[0][4] = remodel; 

Game1.discard[0][0]= smithy;
Game1.discard[0][1]= copper; 

printf("Player one deck contains TWO treasure cards, one copper(4) and one silver(5).\n");

printf("\n");
int i; 
for (i = 0; i < Game1.deckCount[0]; i++)
{

	printf("Player 1 Deck: %d\n", Game1.deck[0][i]);

}

printf("\n");

for (i = 0; i < Game1.discardCount[0]; i++)
{

	printf("Player 1 Discard: %d\n", Game1.discard[0][i]);

}

printf("\n");


for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);

}

printf("\n");


int treasure =0; 
int reject = 0; 
int deckMinus; 

for(i =0; i< Game1.deckCount[0]; i++)
{
	if (Game1.deck[0][i] == copper || Game1.deck[0][i] == silver || Game1.deck[0][i] == gold)
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

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*State of other players */ 

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);

/*Victory Card piles and kingdom card piles */ 

//int temphand[MAX_HAND];
//adventurerCardEffect( &Game1, 0, temphand);  

printf("Adventure function called\n");

cardEffect(adventurer, 0,0,0, &Game1,0, 0);


printf("\n");
//int i; 
for (i = 0; i < Game1.deckCount[0]; i++)
{

	printf("Player 1 Deck: %d\n", Game1.deck[0][i]);

}

printf("\n");

for (i = 0; i < Game1.discardCount[0]; i++)
{

	printf("Player 1 Discard: %d\n", Game1.discard[0][i]);

}

printf("\n");


for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);

}

printf("\n");



printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);


/* No state should occur for other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);




if (Game1.discardCount[0] != prevDiscardCount + reject)
{

	assert(6);
	printf("Discard pile does not have the right number of rejected cards\n");
}

else
{
	printf("TEST SUCCESS: Discard pile has the right number of rejected cards\n");


}



if (Game1.handCount[0] != prevHandCount + treasure)
{
	printf("Hand  does not have the right number of treasure cards\n");
}

else
{
	printf("TEST SUCCESS: Hand pile has the right number of treasure cards\n");


}


if (Game1.deckCount[0] != prevDeckCount - deckMinus)
{
	printf("Deck does not have the right number of cards subtracted\n");
}

else
{
	printf("TEST SUCCESS:Deck has the right number of cards subtracted\n");


}











/* No state change should occur to the victory card piles and kingdom card piles */

printf("\n");

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
