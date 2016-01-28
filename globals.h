#ifndef GLOBALS_H
#define GLOBALS_H

typedef struct bfpp_datatype{
	char m_type;
	union {
		char* m_string;
		int m_int;
		float m_float;
	} data;
};

#endif