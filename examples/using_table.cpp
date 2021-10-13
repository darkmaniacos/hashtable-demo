#include <stdio.h>
#include "mine_hashtable.h"

#define MAX_PLAYERS_STORE 20

int main()
{
	Hashtable<int> players_cash(MAX_PLAYERS_STORE);
	
	cstring tag1 = "DragonSlayer9966";
	cstring tag2 = "GoatOfSparta1";
	cstring tag3 = "BigMusclesOriginal";
	
	players_cash.Add(tag1, 2021);
	players_cash.Add(tag2, 10000);
	players_cash.Add(tag3, 333);
	
	printf("{tag: \'%s\', value: \'%i\'}\n", tag1, *players_cash.Get(tag1));
	printf("{tag: \'%s\', value: \'%i\'}\n", tag2, *players_cash.Get(tag2));
	printf("{tag: \'%s\', value: \'%i\'}\n", tag3, *players_cash.Get(tag3));
	
	return 0;
}