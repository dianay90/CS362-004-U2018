#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Testing Smithy */

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

printf("SMITHY TEST\n\n");
//int gameStatus; 
/* GameState unit test */ 

struct gameState  Game1; 


int kingdomCards[10] = {baron,  feast, gardens, remodel, council_room, mine, village, smithy, adventurer, great_hall  };

initializeGame(2, kingdomCards, 5, &Game1); 

int prevEstateSupplyCount = Game1.supplyCount[estate];
int prevDuchySupplyCount= Game1.supplyCount[duchy];
int prevPrivinceSupplyCount = Game1.supplyCount[province];
/*Current Player should receive exactly 3 cards*/

/* 3 cards should come from his own pile */


printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/*Add smithy card to player 1 hand */ 

printf("Smithy card added \n");
Game1.handCount[0] = 5; 
Game1.handCount[1] = 3; 

int prevplayer2HandCount = Game1.handCount[1];

int original[5] = {estate, copper, smithy, silver, remodel}; 

Game1.hand[0][0] = estate;
Game1.hand[0][1] = copper;
Game1.hand[0][2] = smithy;
Game1.hand[0][3] = silver;
Game1.hand[0][4] = remodel;

int hand = Game1.handCount[0];
//int deck = Game1.deckCount[0];
int i; 
for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);

}

Game1.handCount[0]=5;
/*State of other players */ 

//printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game2.handCount[0], Game2.deckCount[0], Game2.discardCount[0]);

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);

/*Victory Card piles and kingdom card piles */ 
printf("\n");

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

//smithyCardEffect( &Game1,2, 0);  
//		smithyCardEffect(state, handPos, currentPlayer);
cardEffect(smithy, 0, 0, 0, &Game1, 2, 0);


printf("After Smithy card added and implemented \n"); 
for (i = 0; i < Game1.handCount[0]; i++)
{

	printf("Player 1 Hand: %d\n", Game1.hand[0][i]);

}

printf("\n");

if (Game1.handCount[0] != hand +3)
{
	assert(6);
	printf("Hand count did not increment by 3. \n");
	
}

else
{
if (original[0] == Game1.hand[0][0] && original[1] == Game1.hand[0][1] && original[2] == Game1.hand[0][2] && original[3] == Game1.hand[0][3] && original[4] == Game1.hand[0][4])
{
	printf("TEST SUCCESS:Hand count incremented by 3. \n");

}

else{
assert(6);
printf("Hand count did not succesfully increment by 3 with proper values \n");
}
}

if (Game1.handCount[1] != prevplayer2HandCount)
{

	assert(6);
	printf("Player 2 hand count changed after smithy used. \n");
}

else
{

	printf("TEST SUCCESS: Player 2 hand count not changed after smithy used. \n");

}


 prevEstateSupplyCount = Game1.supplyCount[estate];
prevDuchySupplyCount = Game1.supplyCount[duchy];
prevPrivinceSupplyCount = Game1.supplyCount[province];

if (prevDuchySupplyCount != Game1.supplyCount[duchy] || prevDuchySupplyCount != Game1.supplyCount[estate] || prevEstateSupplyCount != Game1.supplyCount[province] || prevPrivinceSupplyCount)
{
	assert(6);
	printf("Supply counts differnet after function call \n");

}


else
{
	printf("TEST SUCCESS: Supply counts same after function call \n");


}
printf("\n");



printf("Number of cards in player 1 hand: %d, cards in player 1 deck: %d, cards in player 1 discard pile %d \n", Game1.handCount[0], Game1.deckCount[0], Game1.discardCount[0]);

/* Bug is here*/ 


/* No state should occur for other players */

printf("Number of cards in player 2 hand: %d, cards in player 2 deck: %d, cards in player 2 discard pile %d \n\n", Game1.handCount[1], Game1.deckCount[1], Game1.discardCount[1]);


printf("\n");
/* No state change should occur to the victory card piles and kingdom card piles */

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


printf("\n");

if (fail == 1)
{
	printf("TEST FAILURE. TEST CONTAINED  ONE OR MORE ERRORS.\n");
}

else
{
	printf("TEST SUCCESSFUL. NO ERRORS FOUND.\n");

}


//printf("."); 

return 0; 


}


