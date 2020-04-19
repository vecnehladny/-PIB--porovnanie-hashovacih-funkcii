//
//  functions.h
//  [PIB] Porovnavanie Hashov
//
//  Created by vecnehladny on 08/04/20.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#ifndef functions_h
#define functions_h

#define SPACE 8
#define ATTEMPTS 20
#define INTERVAL 30

extern int isDEBUG;
extern int PRIME;


typedef struct HashNode{
	int value;
	int key;
} HASHNODE;

typedef struct HashMap{
	HASHNODE **array;
	int capacity;
	int size;
	HASHNODE *dummy;
} HASHMAP;


typedef struct chain {
	char *data;
	struct chain *next;
} CHAIN;


//-----------------hash-retazenie-------------------

void initHashtableChain(CHAIN **initialize, int size);
int insertHashCh(CHAIN **hashtable, char *key);
double hashFunctionCh(char *key);
CHAIN *searchHashCh(CHAIN **hashtable, char *key);
void printHashtable(CHAIN **hashtable);
CHAIN *rehashCh(CHAIN **newHashtable, CHAIN **oldHashtable, int sizeOldHashtable);
void testUniqueCh(CHAIN **hashtable, int howMuch);
void testNonUniqueCh(CHAIN **hashtable, int howMuch);


//--------------hash-volne retazenie----------------

void initHashOA(HASHMAP *hashmap, int capacity, int size);
int hashFunctionOA(HASHMAP *hashmap, int key);
void insertHashOA(HASHMAP *hashmap, int key, int value);
int deleteHashOA(HASHMAP *hashmap, int key);
HASHNODE *getHashOA(HASHMAP *hashmap, int key);
void displayHashOA(HASHMAP *hashmap);
int sizeOfTableHashOA(HASHMAP *hashmap);
int isEmptyHashOA(HASHMAP *hashmap);


//--------------------ostatne-----------------------

int getGreater(int i, int j);


#endif /* functions_h */
