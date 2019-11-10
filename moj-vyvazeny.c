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

int getGreater(int i, int j){
	
	if(i > j){
		return i;
	}
	
	else {
		return j;
	}
}

int getHeigthAVL(NODE *node){
	
	int leftHeight;
	int rightHeight;
	
	if(node == NULL){
		return 0;
	}
	
	if(node->left == NULL){
		leftHeight = 0;
	}
	
	else{
		leftHeight = 1 + node->left->height;
	}
	
	if(node->right == NULL){
		rightHeight = 0;
	}
	
	else{
		rightHeight = 1 + node->right->height;
	}
	
	return getGreater(leftHeight, rightHeight);
}

int getHeigthValAVL(NODE *node){
	
	if(node == NULL){
		return 0;
	}
	
	else{
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
	
	else{
		leftHeight = 1 + getHeigthValAVL(node->left);
	}
	
	if(node->right == NULL){
		rightHeight = 0;
	}
	
	else{
		rightHeight = 1 + getHeigthValAVL(node->right);
	}
	
	return leftHeight - rightHeight;
	
	
}

NODE *initAVL(int root){
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = root;
	new->height= 0;
	new->left = new->right = NULL;
	return new;
}

NODE *rotationAVL(NODE *node, int isLeft){
	
	if(isLeft){ //lava
		NODE *temp = node->left;
		
		node->left = temp->right;
		temp->right = node;
		
		node->height = getGreater(getHeigthAVL(node->left), getHeigthAVL(node->right)) + 1;
		temp->height = getGreater(getHeigthAVL(temp->left), node->height) + 1;
		
		return temp;
	}
	
	if(!isLeft){ //prava
		NODE *temp = node->right;
		
		node->right = temp->left;
		temp->left = node;
		
		node->height = getGreater(getHeigthAVL(node->left), getHeigthAVL(node->right)) + 1;
		temp->height = getGreater(getHeigthAVL(temp->right), node->height) + 1;
		
		return temp;
	}
	
	return NULL;
}

NODE *doubleRotationAVL(NODE *node, int isLeft){
	
	if(isLeft){ //lava
		node->left = rotationAVL(node->left, 0);
		return rotationAVL(node, 1);
	}
	
	if(!isLeft){ //prava
		node->right = rotationAVL(node->left, 1);
		return rotationAVL(node, 0);
	}
	
	return NULL;
}

NODE *insertAVL(NODE *node, int number){
	pridanych++;
	
	if(node == NULL){
		return initAVL(number);
	}
	
	else{
		if(number <= node->data){
			node->left = insertAVL(node->left, number);
			if(balanceFactorAVL(node) == 2){
				if(number <= node->left->data){
					node = rotationAVL(node, 1);
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
					node = rotationAVL(node, 0);
				}
				
				else{
					node = doubleRotationAVL(node, 0);
				}
			}
		}
	}
	
	node->height = getHeigthAVL(node);
	
	return node;
}

NODE *searchAVL(NODE *node, int number){
	if(node->data == number){
		return node;
	}
		
	if(node->data > number){
		searchBVS(node->left, number);
	}
		
	if(node->data < number){
		searchBVS(node->right, number);
	}
		
	return NULL;
}
