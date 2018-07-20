#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



int fail = 0;


int main() 

{
int count =0; 
int smithyCount =4;
struct gameState Game1; 

Game1.numPlayers=2; 

/* Test when hand count contains 4 smithy */

Game1.handCount[0] = 5; 
Game1.discardCount[0]= 0; 
Game1.deckCount[0]=0;

int i; 
for (i=0; i< 4; i++)
{

Game1.hand[0][i]= smithy; 

}

Game1.hand[0][4]= adventurer; 

count = fullDeckCount(0, smithy, &Game1); 

printf("FULL DECK COUNT UNIT TEST: Testing full deck count function to see how many smithys' there are \n");


printf("\n");


for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);

}

printf("\n");


printf( "Actual result: %d, Expected result: %d \n\n", count, 4); 
if (count == smithyCount)
{

	printf("TEST SUCCESS: Right number of cards found \n");
}
else
{
	//assert(); 
fail =1; 
	printf("TEST FAILED: Right number of cards not found \n");
}

/* Test amongst a variety */


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
