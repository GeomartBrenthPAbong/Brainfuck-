#include "heap.h"

int create_heap(int p_size, int p_heap_type){
	if (p_size <= 0)
		return 0;

	g_heap = calloc(p_size, sizeof(carrier));
	g_last_heap_node = 0;
	g_heap_size = p_size;

	if (p_heap_type == 0)		// min heap
		g_compare_func = min_datum;
	else						// max heap
		g_compare_func = max_datum;

	return 1;
}

void insert(int p_datum, int p_priority_number){
	if (g_last_heap_node == g_heap_size)
		return;

	if (g_heap[g_last_heap_node] == 0)
		g_heap[g_last_heap_node] = calloc(1, sizeof(carrier));

	g_heap[g_last_heap_node]->m_datum = p_datum;
	g_heap[g_last_heap_node]->m_priority_num = p_priority_number;

	g_last_heap_node++;
	bubble_up(g_last_heap_node - 1);
}

int remove_top(void){
	if (g_last_heap_node == 0)
		return -1;
	
	int value = g_heap[0]->m_datum;

	free(g_heap[0]);
	g_heap[0] = g_heap[g_last_heap_node - 1];
	g_heap[g_last_heap_node - 1] = 0;
	g_last_heap_node--;

	bubble_down(0);
	return value;
}

void clean_heap(void){
	for (int i = 0; i < g_last_heap_node; i++) 
			free(g_heap[i]);
	free(g_heap);
}

void bubble_up(int p_current_node){
	if (p_current_node == 0)
		return;

	int parent = (p_current_node - 1) / 2;

	if (compare_func(p_current_node, parent)){
		swap(p_current_node, parent);
		bubble_up(parent);
	}
}

void bubble_down(int p_current_node){
	if (p_current_node >= g_last_heap_node)
		return;

	int left_child = 2 * p_current_node + 1;

	if (left_child >= g_last_heap_node)
		return;

	int right_child = 2 * p_current_node + 2;
	int target_child;

	if (right_child >= g_last_heap_node)
		target_child = left_child;
	else
		target_child = g_compare_func(left_child, right_child);

	if (compare_func(target_child, p_current_node)){
		swap(target_child, p_current_node);
		bubble_down(target_child);
	}
}
