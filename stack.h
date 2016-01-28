#ifndef STACK_H
#define STACK_H

#include<stdlib.h>

int* g_stack;
int g_stack_size;
int g_top;

__inline void create_stack(int p_size){
	g_stack = calloc(p_size, sizeof(int));
	g_stack_size = p_size;
	g_top = 0;
}

__inline void push(int p_data){
	g_stack[g_top++] = p_data;
}

__inline void pop(){
	g_top--;
}

__inline int top(){
	return g_stack[g_top-1];
}

__inline int is_stack_empty(){
	return (g_top == 0);
}

__inline int is_stack_full(){
	return (g_top == g_stack_size);
}

__inline clean_stack(){
	free(g_stack);
}

#endif