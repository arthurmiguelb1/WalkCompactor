#include <stdio.h>
#include <stdlib.h>
#include "libs/heap.h"

typedef unsigned char UCHAR;

typedef struct h_tree{
	UCHAR symbol;
	int frequency;
	struct h_tree *left;
	struct h_tree *right;
} No;

typedef No* NO;

NO create_no(){
	NO htree = (NO) malloc(sizeof(No));
	htree->left = NULL;
	htree->right = NULL;
	htree->frequency = 0;
	return htree;
}


void** create_htree_array(int size){
	void** array = (void**) malloc(size * sizeof(void*));
	return array;
}


short compare_nos(void* m, void* n){
	NO a, b;
	a = (NO) m;
	b = (NO) n;
	if (a->frequency < b->frequency) return 1;
	return 0;
}


NO construct_h_tree(HEAP heap){
	while (heap->size != 1){
		NO smaller1, smaller2, merge;
		smaller1 = (NO) dequeue(heap, compare_nos);
		smaller2 = (NO) dequeue(heap, compare_nos);

		merge = create_no();
		merge->left = smaller1;
		merge->right = smaller2;
		merge->frequency =
			smaller1->frequency + smaller2->frequency;
		// verificar se eh esse simbolo que deve ser usado
		merge->symbol = '*';
		enqueue(heap, (void*) merge, compare_nos);
	}
	return (NO) dequeue(heap, compare_nos);
}


int main(){

	return 0;
}
