#include <stdio.h>
#include <stdlib.h>
#include "libs/heap.h"

typedef unsigned char UCHAR;

typedef struct h_tree{
	UCHAR simbol;
	int frequency;
	struct h_tree *left;
	struct h_tree *right;
} No;

typedef No* NO;

NO create_no(){
	NO htree = (NO) malloc(sizeof(No));
	htree->left = NULL;
	htree->right = NULL;
	int frequency = 0;
	return htree;
}


void** create_htree_array(int i){
	void** array = (void**) malloc(sizeof(void*));
	return array;
}


short compare_nos(void* m, void* n){
	NO a, b;
	a = (NO) m;
	b = (NO) n;
	if (a->frequency < b->frequency) return 1;
	return 0;
}


int main(){

	return 0;
}
