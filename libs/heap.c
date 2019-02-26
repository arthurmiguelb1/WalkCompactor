#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

HEAP create_heap(void** (*create_array)(int)){
	HEAP h = (HEAP) malloc(sizeof(Heap));
	h->size = 0;
	h->data = create_array(MAX_HEAP_SIZE);
	return h;
}


int get_parent_index(int i){
	return i >> 1;
}


int get_left_index(int i){
	return i << 1;
}


int get_right_index(int i){
	return (i << 1) + 1;
}


void enqueue(HEAP heap, void *item,
		short (*compare)(void*, void*)){

	if (heap->size >= MAX_HEAP_SIZE){
		return;
	}
	heap->data[++heap->size] = item;
	int item_index = heap->size;
	int parent_index = get_parent_index(item_index);

	void *c;
	while (parent_index >= 1 &&
			compare(heap->data[item_index], heap->data[parent_index])){

		c = heap->data[parent_index];
		heap->data[parent_index] = heap->data[item_index];
		heap->data[item_index] = c;

		item_index = parent_index;
		parent_index = get_parent_index(item_index);
	}
}


void* dequeue(HEAP heap,
		short (*compare)(void*, void*)){
	if (heap->size == 0){
		printf("Heap underflow");
	}
	void* item = heap->data[1];
	heap->data[1] = heap->data[heap->size];
	heap->size -= 1;

	max_heapify(heap, 1, compare);
	return item;
}


void max_heapify(HEAP heap, int i,
		short (*compare)(void*, void*)){

	int largest;
	int left_index = get_left_index(i);
	int right_index = get_right_index(i);

	if (left_index <= heap->size &&
			compare(heap->data[left_index], heap->data[i])){
		largest = left_index;
	}else{
		largest = i;
	}

	if (right_index <= heap->size &&
			compare(heap->data[right_index], heap->data[largest])){
		largest = right_index;
	}

	/* A função compare, devido aos outros usos, deve ser
	 * uma comparação utilizando > ou <, então
	 * ~((a > b) v (b < a)) <-> a == b */
	void *c;
	if ((compare(heap->data[largest], heap->data[i]) ||
				compare(heap->data[i], heap->data[largest]))){

		c = heap->data[largest];
		heap->data[largest] = heap->data[i];
		heap->data[i] = c;

		max_heapify(heap, largest, compare);
	}
}

