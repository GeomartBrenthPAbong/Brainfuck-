#ifndef GENERATOR_H
#define GENERATOR_H

enum op{
	P_MOVR, P_MOVL, P_INCR, P_DECR, P_WRITE, P_READ, P_COND, P_JUMP_COND,
	P_VAL, P_CONV, P_IF_COND, P_REL_OP
};

char * labels[] = {
	"MOVR", "MOVL", "INCR", "DECR", "WRITE", "READ", "COND", "JUMP_COND",
	"VAL", "CONV"
};

typedef struct{
	enum op m_op; 
	struct bfpp_datatype* m_arg;
} instruction;

instruction g_code[999];
int g_code_runner = 0;
int g_code_size = 0;

__inline int reserve_loc(){
	g_code_size++;
	return g_code_runner++;
}

__inline void set_code_itr(int p_index){
	g_code_runner = p_index;
}

__inline int get_code_itr(){
	return g_code_runner;
}

__inline void code_itr_forth() {
	g_code_runner++;
}

__inline void code_itr_back() {
	g_code_runner--;
}

__inline instruction code_itr_item() {
	return g_code[g_code_runner];
}

__inline void back_patch(int p_addr, enum op p_op, struct bfpp_datatype* p_arg){
	g_code[p_addr].m_op = p_op;
	g_code[p_addr].m_arg = p_arg;
}

__inline int is_valid_itr() {
	return (g_code_runner >= 0 && g_code_runner <= g_code_size);
}

__inline void reset_code_itr(){
	g_code_runner = 0;
}

__inline void store_code(enum op p_op, struct bfpp_datatype* p_arg){
	g_code[g_code_runner].m_op = p_op;
	g_code[g_code_runner++].m_arg = p_arg;
	g_code_size++;
}

__inline void print_code(){
	g_code_runner = 0;
	while (g_code_runner <= g_code_size){
		printf("Addr: %d Op: %s\n", g_code_runner, labels[g_code[g_code_runner].m_op]);
		g_code_runner++;
	}

	reset_code_itr();
}


#endif