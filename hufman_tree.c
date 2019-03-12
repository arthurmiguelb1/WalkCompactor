#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libs/heap.h"

#define MAX_SIZE 256

typedef unsigned char Byte;

typedef struct h_tree{
	Byte simbol;
	int frequency;
	struct h_tree *left;
	struct h_tree *right;
} Node;

typedef Node* NODE;

NODE create_node(){
	NODE htree = (NODE) malloc(sizeof(Node));
	htree->left = NULL;
	htree->right = NULL;
	htree->frequency = 0;
	return htree;
}


void** create_htree_array(int size){
	void** array = (void**) malloc(size * sizeof(void*));
	return array;
}

// void initialize_array(int *array, int size, int i)
// {
//     if (i < size)
//     {
//         array[i] = 0;
//         i += 1;
//         initialize_array(array, size, i);
//     }
// }

short compare_nodes(void* m, void* n){
	NODE a, b;
	a = (NODE) m;
	b = (NODE) n;
	if (a->frequency < b->frequency) return 1;
	return 0;
}

int *create_frequency_array(char arq[])
{
    FILE *file = fopen(arq, "rb");

    int *freq = (int *)calloc(MAX_SIZE, sizeof(int));

    int i;
    while (1)
    {
        if (!feof(file))
        {
            Byte c = fgetc(file);
            i = (int)c;
            freq[i] += 1;
        }
        else
        {
            break;
        }
    }

    return freq;
}

void printing_frequency_array(int *array)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (array[i])
        {
            printf("%c %d\n", i, array[i]);
        }
    }
}

NODE construct_h_tree(HEAP heap){
	while (heap->size != 1){
		NODE smaller1, smaller2, merge;
		smaller1 = (NODE) dequeue(heap, compare_nodes);
		smaller2 = (NODE) dequeue(heap, compare_nodes);

		merge = create_no();
		merge->left = smaller1;
		merge->right = smaller2;
		merge->frequency =
			smaller1->frequency + smaller2->frequency;
		// verificar se eh esse simbolo que deve ser usado
		merge->symbol = '*';
		enqueue(heap, (void*) merge, compare_nodes);
	}
	return (NODE) dequeue(heap, compare_nodes);
}


int main(){

	return 0;
}
