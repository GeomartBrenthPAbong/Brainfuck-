#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<string.h>
#include "generator.h"
#include "bfcell.h"

void convert(char p_from_type, int p_to_type, struct bfpp_datatype* p_val){
	if (p_from_type == 'I'){
		if (p_to_type == 1){
			p_val->m_type = 'F';
			p_val->data.m_float = (float)p_val->data.m_int;
		}
		else if (p_to_type == 2){
			p_val->m_type = 'S';
			int old_val = p_val->data.m_int;

			p_val->data.m_string = malloc(sizeof(char)* 100);
			sprintf(p_val->data.m_string, "%d", old_val);
		}
	}
	else if (p_from_type == 'F'){
		if (p_to_type == 0){
			p_val->m_type = 'I';
			p_val->data.m_int = (int)p_val->data.m_float;
		}
		else if (p_to_type == 2){
			p_val->m_type = 'S';
			float old_val = p_val->data.m_float;

			p_val->data.m_string = malloc(sizeof(char)* 100);
			sprintf(p_val->data.m_string, "%f", old_val);
		}
	}
	else{
		if (p_to_type == 0){
			p_val->m_type = 'I';
			p_val->data.m_int = atoi(p_val->data.m_string);
		}
		else if (p_to_type == 1){
			p_val->m_type = 'F';
			p_val->data.m_float = (float) atof(p_val->data.m_string);
		}
	}
}

void fetch_execute_cycle(){
	reset_code_itr();
	//print_code();
	instruction current_instruction;
	while (is_valid_itr()){
		current_instruction = code_itr_item();

		switch (current_instruction.m_op){
			case P_VAL:
				store_to_cell(current_instruction.m_arg);
				break;

			case P_CONV:{
				struct bfpp_datatype* current_val = get_cell_value();
				if (!current_val)
					break;

				int to_type = code_itr_item().m_arg->data.m_int;
				char from_type = current_val->m_type;

				if ((to_type == 0 && from_type == 'I') ||
					(to_type == 1 && from_type == 'F') || 
					(to_type == 2 && from_type == 'S'))
					break;

				convert(from_type, to_type, current_val);
				break;
			}
			case P_MOVR:
				move_cells_forth(1);
				break;

			case P_MOVL:
				move_cells_back(1);
				break;

			case P_INCR: {
				struct bfpp_datatype* current_val = get_cell_value();
				if (current_val->m_type == 'I')
					current_val->data.m_int += 1;
				else if (current_val->m_type == 'F')
					current_val->data.m_float += 1.0;
				break;
			}

			case P_DECR: {
				struct bfpp_datatype* current_val = get_cell_value();
				if (current_val->m_type == 'I')
					current_val->data.m_int -= 1;
				else if (current_val->m_type == 'F')
					current_val->data.m_float -= 1.0;
				break;
			}

			case P_WRITE: {
				struct bfpp_datatype* current_val = get_cell_value();
				if (!current_val){
					printf("No value\n");
				}
				else if (current_val->m_type == 'I'){
					printf("%d\n", current_val->data.m_int);
				}
				else if (current_val->m_type == 'F'){
					printf("%f\n", current_val->data.m_float);
				}
				else if(current_val->m_type == 'S')
					printf("%s\n", current_val->data.m_string);

				break;
			}

			case P_READ: {
				struct bfpp_datatype* in = malloc(sizeof(struct bfpp_datatype));
				in->m_type = 'S';
				in->data.m_string = malloc(sizeof(char)* (100));

				scanf("%s", in->data.m_string);
				
				store_to_cell(in);

				printf("\n");
				break;
			}

			case P_IF_COND: {
				struct bfpp_datatype* current_val = get_cell_value();
				struct bfpp_datatype* current_code = code_itr_item().m_arg;

				code_itr_forth();
				struct bfpp_datatype* rel_op = code_itr_item().m_arg;
				code_itr_forth();
				struct bfpp_datatype* value = code_itr_item().m_arg;

				if (!current_val ||
					(rel_op->data.m_int == 0 && current_val->data.m_int != value->data.m_int) ||
					(rel_op->data.m_int == 1 && current_val->data.m_int >= value->data.m_int) ||
					(rel_op->data.m_int == 2 && current_val->data.m_int <= value->data.m_int)){
					set_code_itr(current_code->data.m_int);
				}

				break;
			}

			case P_COND: {
				struct bfpp_datatype* current_val = get_cell_value();

				if (!current_val || current_val->m_type == 'S' || current_val->data.m_int <= 0)
					set_code_itr(code_itr_item().m_arg->data.m_int);
				break;
			}

			case P_JUMP_COND:
				set_code_itr(code_itr_item().m_arg->data.m_int - 1);
				break;

			default:
				printf("Not registered command\n");
				break;
		}

		code_itr_forth();
	}
}

#endif