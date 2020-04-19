//
//  main.c
//  [PIB] Porovnavanie Hashov
//
//  Created by vecnehladny on 08/04/20.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"



int main(int argc, const char * argv[]) {
	isDEBUG = 0;
	
	CHAIN *hashtable[100];
	CHAIN **newhashtable;
	initHashtableChain(hashtable, 100);
	
	testUniqueCh(hashtable, 100);
	
	printHashtable(hashtable);
	searchHashCh(hashtable, "HtJU8uFCrK");
	newhashtable = rehashCh(newhashtable, hashtable, 100);
	printHashtable(newhashtable);
	return 0;
}
