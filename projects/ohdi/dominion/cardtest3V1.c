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
Game1.deck[0][0] = estate; 
Game1.deck[0][1] = silver; 
Game1.deck[0][2] = province; 
Game1.deck[0][3] = silver; 
//Game1.deck[0][4] = smithy; 
int purse=0; 

int count = Game1.deckCount[0];

for ( i =0; i< Game1.handCount[0] ; i++)

{
if (Game1.hand[0][i] == copper)
{
purse +=1; 
}


if (Game1.hand[0][i] == silver)
{
purse +=2;
 
}

if (Game1.hand[0][i] == gold)
{
purse +=3; 
}



}


printf("Coin  value: %d\n", purse); 




printf("Player one deck contains one estate, two silvers, and one province card\n");

printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*State of other players */ 

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);

/*Victory Card piles and kingdom card piles */ 
/*
printf("Number of estate cards: %d \n", Game1.supplyCount[estate]);
printf("Number of duchy cards: %d \n", Game1.supplyCount[duchy]);
printf("Number of province cards: %d \n", Game1.supplyCount[province]);

printf("Kingdom Cards \n");

printf("Number of baron cards: %d \n", Game1.supplyCount[baron]);
printf("Number of feast cards: %d \n", Game1.supplyCount[feast]);
printf("Number of garden cards: %d \n", Game1.supplyCount[gardens]);
printf("Number of remodel cards: %d \n", Game1.supplyCount[remodel]);
printf("Number of council room cards: %d \n", Game1.supplyCount[council_room]);
printf("Number of mine cards: %d \n", Game1.supplyCount[mine]);
printf("Number of village cards: %d \n", Game1.supplyCount[village]);
printf("Number of smithy cards: %d \n", Game1.supplyCount[smithy]);
printf("Number of adventurer cards: %d \n", Game1.supplyCount[adventurer]);
printf("Number of great hall cards: %d \n", Game1.supplyCount[great_hall]);
*/
//adventurerCardEffect( &Game1, 0);  

cardEffect(15, 1,0, 0 ,&Game1, 0, &bonus); 

printf("After estate card, case discard estate  called \n");

printf("Contents of new hand - should be one less \n"); 

//int i; 
int estateFlag = 0; 

for(i=0; i< Game1.handCount[0]; i++)
{
//printf("Card: %d \n", Game1.handCount[0][i]"); 


if (Game1.hand[0][i] == 1)
{
 printf("TEST FAILURE: Estate card is still in hand \n");

break;
}
estateFlag =1; 
//break; 
}



if (estateFlag ==1)
{
printf("TEST SUCCESS: ESTATE CARD REMOVED  \n");
}


for ( i =0; i< Game1.handCount[0] ; i++)

{
if (Game1.hand[0][i] == copper)
{
purse +=1; 
}


if (Game1.hand[0][i] == silver)
{
purse +=2;
 
}

if (Game1.hand[0][i] == gold)
{
purse +=3; 
}



}


printf("Coin  value: %d\n", purse); 


printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);


/* No state should occur for other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);


/*TEST FOR THE SECOND CASE FOR BARON CARD */ 

printf(" \n\n");

printf(" Now testing when player wants to gain an estate card instead\n");

/* No state change should occur to the victory card piles and kingdom card piles */
/*
printf("Number of estate cards: %d \n", Game1.supplyCount[estate]);
printf("Number of duchy cards: %d \n", Game1.supplyCount[duchy]);
printf("Number of province cards: %d \n", Game1.supplyCount[province]);

printf("Kingdom Cards \n");

printf("Number of baron cards: %d \n", Game1.supplyCount[baron]);
printf("Number of feast cards: %d \n", Game1.supplyCount[feast]);
printf("Number of garden cards: %d \n", Game1.supplyCount[gardens]);
printf("Number of remodel cards: %d \n", Game1.supplyCount[remodel]);
printf("Number of council room cards: %d \n", Game1.supplyCount[council_room]);
printf("Number of mine cards: %d \n", Game1.supplyCount[mine]);
p
rintf("Number of village cards: %d \n", Game1.supplyCount[village]);
printf("Number of smithy cards: %d \n", Game1.supplyCount[smithy]);
printf("Number of adventurer cards: %d \n", Game1.supplyCount[adventurer]);
printf("Number of great hall cards: %d \n", Game1.supplyCount[great_hall]);

*/




return 0; 
}
