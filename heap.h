#ifndef __HEAP__H
#define __HEAP__H

#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

struct carrier{
	int m_datum;
	int m_priority_num;
};

typedef struct carrier carrier;

carrier** g_heap;
int g_last_heap_node;
int g_heap_size;
int (*g_compare_func)(int, int);

int create_heap(int p_size, int p_heap_type);
void insert(int p_datum, int p_priority_num);
int remove_top(void);
void clean_heap(void);

void bubble_up(int p_current_node);
void bubble_down(int p_current_node);
void swap(int p_index_one, int p_index_two);

__inline int is_empty(){
	return g_last_heap_node == 0;
}

__inline int min_datum(int p_datum_one, int p_datum_two){
	if (g_heap[p_datum_one]->m_priority_num < g_heap[p_datum_two]->m_priority_num)
		return p_datum_one;
	return p_datum_two;
}

__inline int max_datum(int p_datum_one, int p_datum_two){
	if (g_heap[p_datum_one]->m_priority_num > g_heap[p_datum_two]->m_priority_num)
		return p_datum_one;
	return p_datum_two;
}

__inline int compare_func(int p_datum_one, int p_datum_two){
	return g_compare_func(p_datum_one, p_datum_two) == p_datum_one;
}

__inline void swap(int p_index_one, int p_index_two){
	carrier* temp = g_heap[p_index_one];
	g_heap[p_index_one] = g_heap[p_index_two];
	g_heap[p_index_two] = temp;
}

#endif