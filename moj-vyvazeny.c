//
//  moj-vyvazeny.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 04/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zadanie2.h"

int pridanych = 0;

NODE *RotationAVL(NODE *node, int isLeft){
	
	if(isLeft){ //lava
		NODE *temp = node->left;
		
		node->left = temp->right;
		temp->right = node;
		
		node->height = getGreater(getHeightAVL(node->left), getHeightAVL(node->right)) + 1;
		temp->height = getGreater(getHeightAVL(temp->left), node->height) + 1;
		
		return temp;
	}
	
	if(!isLeft){ //prava
		NODE *temp = node->right;
		
		node->right = temp->left;
		temp->left = node;
		
		node->height = getGreater(getHeightAVL(node->left), getHeightAVL(node->right)) + 1;
		temp->height = getGreater(getHeightAVL(temp->right), node->height) + 1;
		
		return temp;
	}
	
	return NULL;
}

NODE *doubleRotationAVL(NODE *node, int isLeft){
	
	if(isLeft){ //lava
		node->left = RotationAVL(node->left, 0);
		return RotationAVL(node, 1);
	}
	
	if(!isLeft){ //prava
		node->right = RotationAVL(node->left, 1);
		return RotationAVL(node, 0);
	}
	
	return NULL;
}

NODE *insertAVL(NODE *node, int number){
	pridanych++;
	
	if(node == NULL){
		return initAVL(number);
	}
	
	else {
		if(number <= node->data){
			node->left = insertAVL(node->left, number);
			if(balanceFactorAVL(node) == 2){
				if(number <= node->left->data){
					node = RotationAVL(node, 1);
				}
				
				else {
					node = doubleRotationAVL(node, 1);
				}
			}
		}
		
		if(number > node->data){
			node->right = insertAVL(node->right, number);
			if(balanceFactorAVL(node) == 2){
				if(number > node->right->data){
					node = RotationAVL(node, 0);
				}
				
				else {
					node = doubleRotationAVL(node, 0);
				}
			}
		}
	}
	
	node->height = getHeightAVL(node);
	
	return node;
}

NODE *searchAVL(NODE *node, int number){
	return NULL;
}

NODE *initAVL(int root){
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = root;
	new->height= 0;
	new->left = new->right = NULL;
	return new;
}

int getHeightAVL(NODE *node){
	
	int leftHeight;
	int rightHeight;
	
	if(node == NULL){
		return 0;
	}
	
	if(node->left == NULL){
		leftHeight = 0;
	}
	
	else {
		leftHeight = 1 + node->left->height;
	}
	
	if(node->right == NULL){
		rightHeight = 0;
	}
	
	else {
		rightHeight = 1 + node->right->height;
	}
		
	return getGreater(leftHeight, rightHeight);
}

int getHeightValAVL(NODE *node){
	
	if(node == NULL){
		return 0;
	}
	
	else {
		return node->height;
	}
	
}


int balanceFactorAVL(NODE *node){
	
	int leftHeight;
	int rightHeight;
	
	if(node == NULL){
		return 0;
	}
	
	if(node->left == NULL){
		leftHeight = 0;
	}
	
	else {
		leftHeight = 1 + getHeightValAVL(node->left);
	}
	
	if(node->right == NULL){
		rightHeight = 0;
	}
	
	else {
		rightHeight = 1 + getHeightValAVL(node->right);
	}
	
	return leftHeight - rightHeight;
	
	
}
