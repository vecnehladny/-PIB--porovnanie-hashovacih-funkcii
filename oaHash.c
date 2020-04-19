//
//  cudzi-hash.c
//  [PIB] Porovnavanie Hashov
//
//  Created by vecnehladny on 08/04/20.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "functions.h"

void initHashOA(HASHMAP *hashmap, int capacity, int size){
	
	HASHNODE *arr[capacity];
	HASHNODE *dummy = (HASHNODE*)malloc(sizeof(HASHNODE));
	dummy->key = -1;
	dummy->value = -1;
	
	hashmap->capacity = capacity;
	hashmap->size = size;
	hashmap->array = arr;
	hashmap->dummy = dummy;
}

int hashFunctionOA(HASHMAP *hashmap, int key){
	return key%hashmap->capacity;
}

void insertHashOA(HASHMAP *hashmap, int key, int value){
	HASHNODE *temp = (HASHNODE*)malloc(sizeof(HASHNODE));
	int hashIndex = hashFunctionOA(hashmap, key);
	
	while(hashmap->array[hashIndex] != NULL && hashmap->array[hashIndex]->key != key && hashmap->array[hashIndex]->key != -1){
		hashIndex++;
		hashIndex %= hashmap->capacity;
	}
	
	if(hashmap->array[hashIndex] == NULL || hashmap->array[hashIndex]->key == -1){
		hashmap->size++;
	}
	hashmap->array[hashIndex] = temp;
}

int deleteHashOA(HASHMAP *hashmap, int key){
	int hashIndex = hashFunctionOA(hashmap, key);
	
	while(hashmap->array[hashIndex] != NULL){
		if(hashmap->array[hashIndex]->key == key){
			HASHNODE *temp = hashmap->array[hashIndex];
			hashmap->array[hashIndex]=hashmap->dummy;
			hashmap->size--;
			return temp->value;
		}
		hashIndex++;
		hashIndex %= hashmap->capacity;
	}
	return -1;
}

HASHNODE *getHashOA(HASHMAP *hashmap, int key){
	
	int hashIndex = hashFunctionOA(hashmap, key);
	
	int counter = 0;
	
	while(hashmap->array[hashIndex] != NULL){
		counter = 0;
		if(counter++>hashmap->capacity){
			return NULL;
		}
		
		if(hashmap->array[hashIndex]->key == key){
			return hashmap->array[hashIndex]->value;
		}
		hashIndex++;
		hashIndex %= hashmap->capacity;
	}
	
	return NULL;
}

int sizeOfTableHashOA(HASHMAP *hashmap){
	return hashmap->size;
}

int isEmptyHashOA(HASHMAP *hashmap){
	if (hashmap->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void displayHashOA(HASHMAP *hashmap){
	for(int i = 0; i < hashmap->capacity;i++){
		if (hashmap->array[i] != NULL && hashmap->array[i]->key != -1) {
			printf("key = %d\nvalue = %d\n\n",hashmap->array[i]->key, hashmap->array[i]->value);
		}
	}
}





























