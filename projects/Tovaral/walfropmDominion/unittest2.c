#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main (int argc, char** argv)	{
	struct gameState G;
	printf("\n******Start Unit Test 2: Testing Buy Card******\n");
	
	G.numBuys = 2;
	G.coins = 2;
	printf("Testing too few coins\n");
 	int test = buyCard(2, &G);
		if(test == -1)
			printf("\nPassed\n");
		else
			printf("\nError\n");
	printf("Test a flawless purchase\n");
	G.coins = 10;
	test = buyCard(2, &G);
		if(test == 0)
			printf("\nPassed\n");
		else
			printf("\Error\n");
 	printf("Test exact amount\n");
 	test = buyCard(2, &G);
		if(test == 0)
			printf("\nPassed\n");
		else
			printf("\nError\n");
 	printf("Testing to see if the user does not have any buys left\n");
 	G.coins = 6;
	test = buyCard(2, &G);
		if(test == -1)
			printf("\nPassed\n");
		else
			printf("\nError\n");
		
 	printf("\n******End Unit Test 2: Testing Buy Card******\n"); 
	
 	return 0;	
}