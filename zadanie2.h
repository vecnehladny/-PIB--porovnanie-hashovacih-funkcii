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

typedef struct node {
	int data;
	char color;
	struct node *left, *right, *parent;
} NODE;

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

void leftrotateRBT(NODE **root, NODE *x);
void rightrotateRBT(NODE **root, NODE *y);
void insertRBT(NODE **root, int data);
void insertfixRBT(NODE **root, NODE *z);

//--------------Červeno-čierny strom----------------



#endif /* zadanie2_h */
