#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"



void assert()
{

printf("FAILED TEST \n");

}


int main()
{

int array[20];

/* GameState unit test */ 

struct gameState  Game1; 

int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 

/* Test game  that just started */

printf("Initialized game. Testing shuffle card function. \n");

Game1.deckCount[0]= 20; 


printf ("Contents of deck:\n");
int i; 
for (i=0 ; i<20; i++)
{
printf("%d \n", Game1.deck[0][i]); 
array[i] = Game1.deck[0][i];

}


printf("Player 1 has 20 cards. Calling shuffling function.\n\n"); 

printf("Shuffling deck\n");

shuffle(0, &Game1); 

printf ("Contents of deck:\n");
 
for (i=0 ; i<20; i++)
{
printf("%d \n", Game1.deck[0][i]); 

}


 /*
for (i=0 ; i<20; i++)
{
printf("arrrr %d \n", array[i]); 

}
*/

int similar =0; 

/* Track the number of similar instances between unshuffled deck vs shuffled deck */
for (i =0; i< 6; i++)
{
if(Game1.deck[0][i] == array[i])
{
similar++;
}
}


if (similar > 4)
{
assert(); 
}

else

{
printf("TEST SUCCESSFULLY PASSED. SHUFFLING COMPLETE.\n"); 
}


return 0; 
}
