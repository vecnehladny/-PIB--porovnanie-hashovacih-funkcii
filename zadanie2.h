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
	struct node *left, *right;
} NODE;


NODE *bvsInit(int root);

NODE *bvsNew(int number);

NODE *bvsInsert(NODE *bvs, int number);

void printBvs(NODE *root, int space);

NODE *testBvs(int root);

NODE *searchBVS(NODE *bvs, int number);


#endif /* zadanie2_h */
