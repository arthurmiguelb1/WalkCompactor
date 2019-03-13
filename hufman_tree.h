#ifndef_HUFMAN_TREE_H_
#defin _HUFMAN_TREE_H_

#define MAX_SIZE 256

typedef unsigned char Byte;

typedef struct h_tree{
	Byte symbol;
	int frequency;
	struct h_tree *left;
	struct h_tree *right;
} Node;

typedef Node* NODE;


NODE create_node();

void** create_htree_array(int size);

short compare_nodes(void* m, void* n);

int* create_frequency_array(char *arq);

NODE construct_h_tree(HEAP heap);

#endif
