//
//  moj-hash.c
//  [PIB] Porovnavanie Hashov
//
//  Created by vecnehladny on 08/04/20.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "functions.h"

int PRIME=487;

int HASHTABLESIZE = 0;
int isDEBUG;
const char *UNIQ[] = {"tczIOX5iJq","F98pubxqRM","FDDwpZlvyU","QR7MqmTSrm","MOOJ9IsbsC","aUVg9zfwTG","HiPNKSQSTS","QId8kAObkw","UIzxxwpl5U","I6dYzepxJu","5UiqvTcp7I","RJXN9asVVQ","wzaEtjwKhB","eROQXGxUqs","kXp2BOTavI","4um1XvWtMU","ZsbJs97A1s","R8fkNCXSCS","olPb5XRBt8","hUBVjC515S","iKo50eYJLX","5bp2zSL9pL","EpuyfF5GIE","9u79Z9qTge","9llQuMTtZS","vJSHp9SW8L","QeS4izvJsW","sAyrMIjC9j","97w0fQqgzf","HtJU8uFCrK","y2XxENg6rK","wErxFDGpRC","1LyDfRa5wf","v2RMBVXjD3","om1fDl8GD6","POC9ckBvW4","LIwstAy3GZ","tvMBmX6O2b","0XdVBCmdQG","PJezBRugw9","ERCpmeeURd","JKzC6ZR6S1","w5vbwtko6i","2IR0bFfgK2","eG6QClfhLr","hiKKYivwd8","1seCFGBG4z","r2oWs8D2FW","JETHB39z7A","pYQWyPurrj","4hWkiaUFqc","rlYsZvleHJ","lZawXMa7gA","WIA1FTBAxs","OBih0aQ8Qa","9MulrNF7yG","TKT930xLfr","cozb7Nhmju","UdYERtRTxs","xH2ra4cq5c","BUk1925iSw","kKEvseG6s3","yGATMcDd5V","WvxEY3ZrPv","oj7q27AVkj","1EiyeXqcLc","5V7QGrcJdM","RkbrTTZNJv","NPOPlPm8YL","2LRn05izXa","xodZewh0TL","VubJqFvwxs","Zn2qpdQ45V","oXdhDZRKuH","HTHjRoqcOb","1o6CTdNvIh","Blj6eeXwDZ","Js8nk3gP0o","YHnTFl2AGA","LWF9rehk8c","31k49eLcNw","Irsl3maamr","oRX6496Gl9","09IXqxPQWw","GyEbEYzhpG","Z300YSTfFN","D4A832BwwA","gMb0Dq07WF","9R1Hju9bzW","Lj8WwxijKa","qWs1wDJYbY","Lcj6nPmgCe","NqFeoDx3zr","CrysfiqNUE","WCJpbsln1a","dqcUrNNT0B","33dZll8zSi","SKgORZ0uw3","5DUxNEy9Nl","ZQMQ7VYl2o"};
const char *NONUNIQ[] = {"AErhKyeHi8","H1i9gAeNrj","xAPnHJSNQL","YfYUMPcrGo","a1IEbhx6N8","JgLMa2LnGK","LQeNoypBAb","hnD1BldNg1","yDsgrHSJVU","g5o5zeRob0","rsqi55PJCo","kgUYdinefy","tjbsY6hc0O","Rs3zK2PX1a","I0TtFgqEPz","iGE2LMZr4d","81yndzi2S6","DYHzitR1BF","aPOXqtD3H3","rzLd857hRg","Xa3NDBT9s4","EUvvjm2CKJ","9hSg8tRAEj","oxpzHihbYe","x1fK4PmSTt","XrEZNMzWzv","5j9JTmYzAf","4KgY6h0QlF","kLLay19tBy","FrByNBAFsC","lvVTJoaRdA","aOZ65lBKyZ","zFvpHd8m43","0p4gxq5MzA","nHbFfknxJP","WQ1mkGWuhH","lzB9ukbZjM","kT54qp5Fb8","c6SZhyu6KW","Agj4rjILhB","RWZ09ut44u","As1w6bfZEV","o1B2OVjikD","D8qfuEwEiQ","FqIc1fSo7f","rOotIRERNC","nyh4iG45G4","7AeIlNckvM","TmTRnYXycc","03DVDv33Ed","4tJgV721Fj","saCba9zWnc","d14jWx2Zvj","8tTfS6TLhy","Aykgb4edux","NpnhhMugcF","WjhTnp9RYM","oV5cyqLLcv","I1eKkRg2Zi","CB27FCozZf","kdAWNZoYJV","26PYBRWVUQ","kKZOc0EniW","hq87m821oy","cx9EeP2Up5","KwWQ9AB4I0","k90lqpZ54N","cW2WamxNo1","jRD09eFyBf","8Sb2iwbgnl","OOW4IsmT9w","FWBoI08pad","K8LxEEYixt","Br8RQWcGGR","eQjdmHvTXF","Hp3nxZ2Pvq","W7Msm0L0WY","oEg5FtFxQX","wLP2WpHLFc","Mh5mCf4n2Q","qWAbGQct6A","zh5KDkubIR","IMz33DoTCg","DqcMQtYdET","0z8so0AvWD","ClzgU7eV0V","6GCaHDsi2D","qOApHQ0ZdO","A3YvidZV51","XSRE2mHAYa","G3gQXbxnRf","76ym0vrka9","Js3A8ZqI14","mG6ATTAHrP","Iv4ZHInOqK","bf5r36uHdA","t1zTxu1LJm","ZvImJ6CiDT","Q6tQAgipv0","vv1WbXUwEE"};

void initHashtableChain(CHAIN **initialize, int size){
	
	HASHTABLESIZE = size;
	
	for(int i = 0; i < size;i++){
		initialize[i]=NULL;
	}
}

double hashFunctionCh(char *key){
	int len = (int)strlen(key);
	double hash = 0;
	
	for(int i = 1; i <= len; i++){
		hash += ((int)key[i-1] * pow(31,i));
		if(isDEBUG){
			printf("\t%c(%d) * 31^%d = %lf\n",key[i-1],(int)key[i-1],i,(int)key[i-1] * pow(31,i));
		}
	}
		if(isDEBUG) {
			printf("\tHASH: %lf\n\n",fmod(hash, PRIME));
		}
	
	return fmod(hash, PRIME);
}

int insertHashCh(CHAIN **hashtable, char *key){
	
	int index = fmod(hashFunctionCh(key),HASHTABLESIZE);
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
	
	int index = fmod(hashFunctionCh(key),HASHTABLESIZE);
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

CHAIN *rehashCh(CHAIN **newHashtable, CHAIN **oldHashtable, int sizeOldHashtable){
	int sizeNewHashtable = 2 * sizeOldHashtable;
	newHashtable = malloc(sizeNewHashtable * sizeof(CHAIN*));
	HASHTABLESIZE = sizeNewHashtable;
	
	for (int i = 0; i < sizeOldHashtable; i++) {
		if(oldHashtable[i] == NULL){
			continue;
		}
		else {
			CHAIN *temp = oldHashtable[i];
			while(temp->next != NULL){
				insertHashCh(newHashtable, temp->data);
				temp = temp->next;
			}
			insertHashCh(newHashtable, temp->data);
		}
	}
	return newHashtable;
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
				temp = temp->next;
				printf(" -> %s (#%d)",temp->data,i);
				
			}
			printf("\n");
		}
	}
	printf("\n");
}

void testUniqueCh(CHAIN **hashtable, int howMuch){
	for(int i = 0; i < howMuch;i++){
		insertHashCh(hashtable, UNIQ[i%HASHTABLESIZE]);
	}
}

void testNonUniqueCh(CHAIN **hashtable, int howMuch){
	for(int i = 0; i < howMuch;i++){
		insertHashCh(hashtable, NONUNIQ[i%HASHTABLESIZE]);
	}
}










