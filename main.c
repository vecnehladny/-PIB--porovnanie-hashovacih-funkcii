//
//  main.c
//  [DSA] zadanie2
//
//  Created by vecnehladny on 03/11/19.
//  Copyright © 2019 vecnehladny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "zadanie2.h"



int main(int argc, const char * argv[]) {
	
	NODE *r = testBvs(3);
	printBvs(r, 0);
	
	return 0;
}
