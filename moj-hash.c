//
//  moj-hash.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 09/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "zadanie2.h"

int HASHTABLESIZE = 0;
int isDEBUG;
void initHashtableChain(CHAIN **initialize, int size){
	
	HASHTABLESIZE = size;
	
	for(int i = 0; i < size;i++){
		initialize[i]=NULL;
	}
}

int hashFunctionCh(char *key){
	int len = (int)strlen(key);
	int hash = 0;
	
	for(int i = 1; i <= len; i++){
		hash += abs(((int)key[i-1] * i));
		if(isDEBUG){
			printf("\t%c(%d) * %d = %d\n",key[i-1],(int)key[i-1],i,abs((int)key[i-1] * i));
		}
	}
		if(isDEBUG) {
			printf("\tHASH: %d\n\n",hash%HASHTABLESIZE);
		}
	
	return hash%HASHTABLESIZE;
}

int insertHashCh(CHAIN **hashtable, char *key){
	
	int index = hashFunctionCh(key);
		if(isDEBUG){
			printf(">INSERT [%d] -> %s (#%d)\n",index,key,index);
			printf("\n");
		}
	CHAIN *new = (CHAIN*)malloc(sizeof(CHAIN));
	new->data = key;
	new->next = NULL;
	
	if(hashtable[index] == NULL){
		hashtable[index] = new;
		return index;
	}
	
	else{
		CHAIN *temp = hashtable[index];
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = new;
	}

	return index;
}

CHAIN *searchHashCh(CHAIN **hashtable, char *key){
	
	int index = hashFunctionCh(key);
	CHAIN *current = hashtable[index];
	
	while(current != NULL){
		if(current->data == key){
				if(isDEBUG){
					printf(">FOUND [%d] -> %s (#%d)\n",index,current->data,index);
				}
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void printHashtable(CHAIN **hashtable){
	for (int i = 0; i < HASHTABLESIZE; i++) {
		if(hashtable[i] == NULL){
			printf("[%d] -> NULL\n",i);
		}
		else{
			CHAIN *temp = hashtable[i];
			printf("[%d] -> %s (#%d)",i,hashtable[i]->data,i);
			while(temp->next != NULL){
				printf(" -> %s (#%d)",temp->data,i);
				temp = temp->next;
			}
			printf("\n");
		}
	}
	printf("\n");
}










