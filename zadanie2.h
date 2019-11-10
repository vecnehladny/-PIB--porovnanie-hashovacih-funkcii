//
//  zadanie2.h
//  [DSA] zadanie2
//
//  Created by vecnehladny on 03/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#ifndef zadanie2_h
#define zadanie2_h

#define SPACE 8
#define ATTEMPTS 20
#define INTERVAL 30

extern int isDEBUG;

//-----------------struktura stromu-----------------

typedef struct node {
	int data;
	char color;
	struct node *left, *right, *parent;
	int height;
} NODE;

//-----------------struktura stromu-----------------



//------------struktura hash-retazenie--------------

typedef struct chain {
	char *data;
	struct chain *next;
	int height;
} CHAIN;

//------------struktura hash-retazenie--------------



//---------------BVS bez vyvazovania----------------

NODE *bvsInit(int root);
NODE *bvsNew(int number);
NODE *bvsInsert(NODE *bvs, int number);
void printBvs(NODE *root, int space);
NODE *testBvs(int root);
NODE *searchBVS(NODE *bvs, int number);

//---------------BVS bez vyvazovania----------------



//--------------Červeno-čierny strom----------------
//https://framagit.org/awoimbee_42/libft/tree/7fac487e9aff2381c8d87b79a5cf36fdc8bf064f/src/t_rbtree

void leftRotateRBT(NODE **root, NODE *x);
void rightRotateRBT(NODE **root, NODE *y);
void insertRBT(NODE **root, int data);
void insertfixRBT(NODE **root, NODE *z);
NODE *searchRBT(NODE **root, int key);

//--------------Červeno-čierny strom----------------



//-------------------AVL strom----------------------

NODE *rotationAVL(NODE *node, int isLeft);
NODE *doubleRotationAVL(NODE *node, int isLeft);
NODE *insertAVL(NODE *node, int number);
NODE *searchAVL(NODE *node, int number);
NODE *initAVL(int root);

int getHeigthAVL(NODE *node);
int getHeigthValAVL(NODE *node);
int balanceFactorAVL(NODE *node);

//-------------------AVL strom----------------------



//-----------------hash-retazenie-------------------

void initHashtableChain(CHAIN **initialize, int size);
int insertHashCh(CHAIN **hashtable, char *key);
int hashFunctionCh(char *key);
CHAIN *searchHashCh(CHAIN **hashtable, char *key);
void printHashtable(CHAIN **hashtable);
CHAIN *rehashCh(CHAIN **newHashtable, CHAIN **oldHashtable, int sizeOldHashtable);

//-----------------hash-retazenie-------------------



//--------------------ostatne-----------------------

int getGreater(int i, int j);

//--------------------ostatne-----------------------


#endif /* zadanie2_h */
