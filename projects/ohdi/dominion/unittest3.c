
//CITE OSU CS362 Summer 2018 Class - Update Coins Example 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int fail =0; 
void checker(struct gameState *Game1, int expected)
{
if(Game1->coins == expected)
{
printf("\n"); 
printf("TEST SUCCESS: Game coins matched expected amount \n"); 
printf("\n");

}
else

{
printf("\n");

printf("TEST FAIL:  Game coins did not match expected amount \n"); 
fail =1; 
printf("\n");

}

}
int main()

{



int handCount=5; 
struct gameState  Game1;
printf("UPDATE COINS TEST  \n"); 

int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1);

printf("Starting with 0 coins for player 0. Adding 5 bonus cards only. \n"); 

Game1.coins = 0; 
Game1.handCount[0] = 0; 

printf("Current number of coins = %d \n", Game1.coins);

//int temp = Game1.coins; 
printf("Updating coins \n");	
updateCoins(0, &Game1, 5); 

printf("Actual number of coins = %d, expected = %d\n", Game1.coins, 5);

checker( &Game1, 5);

//temp  = Game1.coins; 

printf( "Testing hand with silvers only \n"); 

//Game1.coins = 0; 
Game1.handCount[0] = handCount; 

int i; 
for (i=0; i <5; i++)
{

Game1.hand[0][i] = silver;

}


updateCoins(0, &Game1, 0); 

printf("Actual number of coins = %d, expected = %d\n\n", Game1.coins, handCount *2);

checker( &Game1, handCount * 2);

printf( "Testing hand with gold only \n");

for (i=0; i <5; i++)
{
Game1.hand[0][i] = gold; 

}

updateCoins(0, &Game1, 0); 

printf("Actual number of coins = %d, expected = %d\n\n", Game1.coins, handCount *3);

checker( &Game1, handCount * 3);
 
printf( "Testing hand with coppers only \n"); 


for (i=0; i <5; i++)
{
Game1.hand[0][i] = copper; 

}

updateCoins(0, &Game1, 0); 

printf("Actual number of coins = %d, expected = %d\n\n", Game1.coins, handCount *1);

checker( &Game1, handCount);


printf( "Testing mixed hand: 1 copper, 2 gold, 2 silvers + 2 bonus \n"); 

Game1.hand[0][0] =copper; 

Game1.hand[0][1] =gold; 

Game1.hand[0][2] = gold; 

Game1.hand[0][3] = silver; 

Game1.hand[0][4] = silver; 

updateCoins(0, &Game1, 2); 

printf("Actual number of coins = %d, expected = %d\n\n", Game1.coins, 13);

checker( &Game1, 13);


if (fail ==1)
{
printf("TEST FAILURE: Test had errors \n"); 

}

else 
{
printf("TEST SUCCESS: Test had no errors \n");

}


return 0; 
}
