#ifndef BRAINFUCK_CELL_H
#define BRAINFUCK_CELL_H

#include<stdlib.h>

struct bfpp_datatype** g_cells;
int g_bf_size;
int g_current_index;

__inline void create_bf_cells(int p_size){
	g_cells = calloc(p_size, sizeof(struct bfpp_datatype));
	g_bf_size = p_size;
	g_current_index = 0;
}

__inline void store_to_cell(struct bfpp_datatype* p_datum){
	g_cells[g_current_index] = p_datum;
}

__inline struct bfpp_datatype* get_cell_value(){
	return g_cells[g_current_index];
}

__inline void move_cells_forth(int p_num_of_cells){
	g_current_index += p_num_of_cells;

	if (g_current_index > g_bf_size)
		g_current_index = 0;
}

__inline void move_cells_back(int p_num_of_cells){
	g_current_index -= p_num_of_cells;

	if (g_current_index < 0)
		g_current_index = g_bf_size - 1;
}

__inline void clean_cells(){
	for (int i = 0; i < g_bf_size; i++)
		if (g_cells[i])
			free(g_cells[i]);
	free(g_code);
}

#endif