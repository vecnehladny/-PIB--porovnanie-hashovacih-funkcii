//
//  cudzi-vyvazeny.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 03/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "zadanie2.h"

void leftRotateRBT(NODE **root, NODE *x){
	
	if(!x || !x->right){
		return;
	}
	
	NODE *y = x->right;
	x->right = y->left;

	if(x->right != NULL){
		x->right->parent = x;
	}

	y->parent = x->parent;
	
	if(x->parent == NULL){
		(*root) = y;
	}
	
	else if(x == x->parent->left){
		x->parent->left = y;
	}
	
	else {
		x->parent->right = y;
	}
	
	y->left = x;
	x->parent = y;
}

void rightRotateRBT(NODE **root, NODE *y){
	
	if(!y || !y->left){
		return;
	}
	
	NODE *x = y->left;
	y->left = x->right;
	
	if(x->right != NULL){
		x->right->parent = y;
	}
	
	x->parent = y->parent;
	
	if(x->parent == NULL){
		(*root) = x;
	}
	
	else if(y == y->parent->left){
		y->parent->left = x;
	}
	
	else{
		y->parent->right = x;
	}
	
	x->right = y;
	y->parent = x;
}

void insertfixRBT(NODE **root, NODE *z){
	// iterate until z is not the root and z's parent color is red
	while (z != *root && z != (*root)->left && z != (*root)->right && z->parent->color == 'R')
	{
		NODE *y;
		
		// Find uncle and store uncle in y
		if (z->parent && z->parent->parent && z->parent == z->parent->parent->left)
			y = z->parent->parent->right;
		else
			y = z->parent->parent->left;
		
		// If uncle is RED, do following
		// (i)  Change color of parent and uncle as BLACK
		// (ii) Change color of grandparent as RED
		// (iii) Move z to grandparent
		if (!y)
			z = z->parent->parent;
		else if (y->color == 'R')
		{
			y->color = 'B';
			z->parent->color = 'B';
			z->parent->parent->color = 'R';
			z = z->parent->parent;
		}
		
		// Uncle is BLACK, there are four cases (LL, LR, RL and RR)
		else
		{
			// Left-Left (LL) case, do following
			// (i)  Swap color of parent and grandparent
			// (ii) Right Rotate Grandparent
			if (z->parent == z->parent->parent->left &&
				z == z->parent->left)
			{
				char ch = z->parent->color ;
				z->parent->color = z->parent->parent->color;
				z->parent->parent->color = ch;
				rightRotateRBT(root,z->parent->parent);
			}
			
			// Left-Right (LR) case, do following
			// (i)  Swap color of current node  and grandparent
			// (ii) Left Rotate Parent
			// (iii) Right Rotate Grand Parent
			if (z->parent && z->parent->parent && z->parent == z->parent->parent->left &&
				z == z->parent->right)
			{
				char ch = z->color ;
				z->color = z->parent->parent->color;
				z->parent->parent->color = ch;
				leftRotateRBT(root,z->parent);
				rightRotateRBT(root,z->parent->parent);
			}
			
			// Right-Right (RR) case, do following
			// (i)  Swap color of parent and grandparent
			// (ii) Left Rotate Grandparent
			if (z->parent && z->parent->parent &&
				z->parent == z->parent->parent->right &&
				z == z->parent->right)
			{
				char ch = z->parent->color ;
				z->parent->color = z->parent->parent->color;
				z->parent->parent->color = ch;
				leftRotateRBT(root,z->parent->parent);
			}
			
			// Right-Left (RL) case, do following
			// (i)  Swap color of current node  and grandparent
			// (ii) Right Rotate Parent
			// (iii) Left Rotate Grand Parent
			if (z->parent && z->parent->parent && z->parent == z->parent->parent->right &&
				z == z->parent->left)
			{
				char ch = z->color ;
				z->color = z->parent->parent->color;
				z->parent->parent->color = ch;
				rightRotateRBT(root,z->parent);
				leftRotateRBT(root,z->parent->parent);
			}
		}
	}
	(*root)->color = 'B'; //keep root always black
}

void insertRBT(NODE **root, int data){
	
	// Allocate memory for new node
	NODE *z = (NODE*)malloc(sizeof(NODE));
	z->data = data;
	z->left = z->right = z->parent = NULL;
	
	//if root is null make z as root
	if (*root == NULL){
		z->color = 'B';
		(*root) = z;
	}
	else{
		NODE *y = NULL;
		NODE *x = (*root);
		
		// Follow standard BST insert steps to first insert the node
		while (x != NULL)
		{
			y = x;
			if (z->data < x->data)
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if (z->data > y->data)
			y->right = z;
		else
			y->left = z;
		z->color = 'R';
		
		// call insertFixUp to fix reb-black tree's property if it
		// is voilated due to insertion.
		insertfixRBT(root,z);
	}
}

NODE *searchRBT(NODE **root, int key){
	if((*root)->data == key){
		return *root;
	}
	
	if((*root)->data > key){
		searchRBT(&((*root)->left), key);
	}
	
	if((*root)->data < key){
		searchRBT(&((*root)->right), key);
	}
	
	return NULL;
}

void printRBT(NODE *root){
	if (root == NULL)
		return;
	printRBT(root->left);
	printf("%d\n", root->data);
	printRBT(root->right);
}


