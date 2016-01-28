/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BFPP_PARSER_H_INCLUDED
# define YY_YY_BFPP_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MOVR = 258,
    MOVL = 259,
    INCR = 260,
    DECR = 261,
    WRITE = 262,
    READ = 263,
    OPEN_BLK = 264,
    CLOSE_BLK = 265,
    INTEGER = 266,
    FLOAT = 267,
    STRING = 268,
    IF_START = 269,
    IF_BLK = 270,
    ELSE_START = 271,
    TO_INT = 272,
    TO_FLOAT = 273,
    TO_STRING = 274,
    LT = 275,
    GT = 276,
    EQ = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
#line 30 "bfpp_parser.y" /* yacc.c:1909  */
cell
 YYSTYPE;
union 
#line 30 "bfpp_parser.y" /* yacc.c:1909  */
cell

{
#line 30 "bfpp_parser.y" /* yacc.c:1909  */

	struct bfpp_datatype* m_datatype;
	struct loop_addr* m_loop_addr;
	int m_int;

#line 87 "bfpp_parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BFPP_PARSER_H_INCLUDED  */
