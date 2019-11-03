//
//  bvs.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 03/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zadanie2.h"

NODE *bvsInit(int root){
	NODE *bvs;
	
	bvs = (NODE *)malloc(sizeof(NODE));
	bvs->data = root;
	bvs->left=NULL;
	bvs->right=NULL;
	
	return bvs;
}

NODE *bvsNew(int number){
	NODE *new = (NODE *)malloc(sizeof(NODE));
	
	new->data = number;
	new->left = NULL;
	new->right = NULL;
	
	return new;
}

NODE *bvsInsert(NODE *bvs, int number){
	
	if(bvs == NULL){
		return bvsNew(number);
	}
	
	if(bvs->data <= number) {
		bvs->right = bvsInsert(bvs->right, number);
	}
	
	else if(bvs->data > number){
		bvs->left = bvsInsert(bvs->left, number);
	}
	
	return bvs;
}

void printBvs(NODE *root, int space){
	
	if (root == NULL)
		return;
	
	space += SPACE;
	
	printBvs(root->right, space);
	
	printf("\n");
	
	for (int i = SPACE; i < space; i++){
		printf(" ");
	}
	
	printf("%d\n", root->data);
	
	printBvs(root->left, space);
}

NODE *testBvs(int root){
	srand(time(NULL));
	NODE *new = bvsInit(root);
	for (int i = 0; i < ATTEMPTS; i++) {
		int r = rand()%INTERVAL;
		bvsInsert(new, r);
	}
	
	return new;
}



