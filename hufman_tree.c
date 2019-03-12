#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libs/heap.h"

#define MAX_SIZE 256

typedef unsigned char UCHAR;

typedef struct h_tree{
	UCHAR simbol;
	int frequency;
	struct h_tree *left;
	struct h_tree *right;
} Node;

typedef Node* NODE;

NODE create_no(){
	NODE htree = (NODE) malloc(sizeof(Node));
	htree->left = NULL;
	htree->right = NULL;
	int frequency = 0;
	return htree;
}


void** create_htree_array(int size){
	void** array = (void**) malloc(size * sizeof(void*));
	return array;
}

void initialize_array(int *array, int size, int i)
{
    if (i < size)
    {
        array[i] = 0;
        i += 1;
        initialize_array(array, size, i);
    }
}

short compare_nos(void* m, void* n){
	NODE a, b;
	a = (NODE) m;
	b = (NODE) n;
	if (a->frequency < b->frequency) return 1;
	return 0;
}


int main(){

	return 0;
}
