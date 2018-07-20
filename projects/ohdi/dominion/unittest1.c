#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



void assert( int value)
{

printf("FAILED TEST. RETURN VALUE SHOULD BE %d\n",value);

}



int main()
{

printf("Is Game Over Test \n");

int gameStatus; 
/* GameState unit test */ 

struct gameState  Game1; 

int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 

/* Test game  that just started */
 printf("Initialized game. Testing to see if the gameStatus is 0 as the game just started. \n");


gameStatus = isGameOver(&Game1); 

printf("Is game over? 1: Yes 0:No  Status:%d \n", gameStatus); 

if (gameStatus == 0)
{
printf ("TEST SUCCESSFUL!\n\n");

}

else 

{

assert(1); 
}

//TEST IF PROVINCE SUPPLY IS EMPTY

printf("Current province count: %d\n", Game1.supplyCount[province]);

printf("Province supply not set to 0 \n"); 
Game1.supplyCount[province]=0; 

gameStatus = isGameOver(&Game1); 

printf("Is game over? 1: Yes 0:No  Status:%d \n", gameStatus); 

//gameStatus=0; 
if (gameStatus == 1)
{
printf ("TEST SUCCESSFUL!\n\n");

}

else 

{

assert(1); 
}


//Hard coded 3 empty supply piles 

printf("Setting the curse pile, estate pile, and duchy pile to 0 \n");

Game1.supplyCount[curse]=0;
Game1.supplyCount[estate]=0;
Game1.supplyCount[duchy]=0;

gameStatus = isGameOver(&Game1); 

printf("Is game over? 1: Yes 0:No  Status:%d \n", gameStatus); 

//gameStatus=0; 
if (gameStatus == 1)
{
printf ("TEST SUCCESSFUL!\n\n");

}

else 

{

assert(1); 
}




return 0; 
}
