//
//  moj-vyvazeny.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 04/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "zadanie2.h"

NODE *leftRotationAVL(NODE *node){
	
	NODE *temp = node->left;
	
	node->left = temp->right;
	temp->right = node;
	
	return NULL;
}

NODE *rightRotationAVL(NODE *node){
	return NULL;
}

NODE *insertAVL(NODE *node, int number){
	return NULL;
}

NODE *searchAVL(NODE *node, int number){
	return NULL;
}
