//
//  main.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 03/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zadanie2.h"



int main(int argc, const char * argv[]) {
	isDEBUG = 0;
	//NODE *r = testBvs(3);
	//printBvs(r, 0);
	
	CHAIN *hashtable[100];
	CHAIN **newhashtable;
	initHashtableChain(hashtable, 100);
	
	testUniqueCh(hashtable, 100);
	
	printHashtable(hashtable);
	//searchHashCh(hashtable, "HtJU8uFCrK");
	//newhashtable = rehashCh(newhashtable, hashtable, 100);
	//printHashtable(newhashtable);
	return 0;
}
