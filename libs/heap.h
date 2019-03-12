#ifndef _HEAP_H_
#define _HEAP_H_

#define MAX_HEAP_SIZE 256

typedef struct heap{
	int size;
	void **data;
} Heap;

typedef Heap* HEAP;

HEAP create_heap(void** (*create_array_data_type)(int));

int get_parent_index(int i);

int get_left_index(int i);

int get_right_index(int i);

int heap_is_empty(HEAP heap);

void enqueue(HEAP heap, void *item,
		short (*compare)(void*, void*));

void max_heapify(HEAP heap, int i,
		short (*compare)(void*, void*));

void* dequeue(HEAP heap,
		short (*compare)(void*, void*));

#endif
