/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
# define YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
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
    ID = 258,
    ADD = 259,
    MINUS = 260,
    MUL = 261,
    DIV = 262,
    MOD = 263,
    INC = 264,
    DEC = 265,
    EQ = 266,
    NEQ = 267,
    GEQ = 268,
    LEQ = 269,
    G = 270,
    L = 271,
    BIT_AND = 272,
    BIT_OR = 273,
    BIT_XOR = 274,
    BIT_NEG = 275,
    LOGIC_AND = 276,
    LOGIC_OR = 277,
    LOGIC_NOT = 278,
    DECIMAL = 279,
    OCTAL = 280,
    HEX = 281,
    STRING = 282,
    INT = 283,
    DOUBLE = 284,
    FLOAT = 285,
    CHAR = 286,
    VOID = 287,
    STRUCT = 288,
    IF = 289,
    ELSE = 290,
    WHILE = 291,
    FOR = 292,
    RETURN = 293,
    BREAK = 294,
    CONTINUE = 295,
    CONST = 296,
    ASSIGN = 297,
    TRUE = 298,
    FALSE = 299,
    LBRACE = 300,
    RBRACE = 301,
    LPARENTHESIS = 302,
    RPARENTHESIS = 303,
    LSQUARE = 304,
    RSQUARE = 305,
    SEMICOLON = 306,
    DOT = 307,
    COMMA = 308,
    LE = 309,
    GE = 310,
    THEN = 311
  };
#endif
/* Tokens.  */
#define ID 258
#define ADD 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define INC 264
#define DEC 265
#define EQ 266
#define NEQ 267
#define GEQ 268
#define LEQ 269
#define G 270
#define L 271
#define BIT_AND 272
#define BIT_OR 273
#define BIT_XOR 274
#define BIT_NEG 275
#define LOGIC_AND 276
#define LOGIC_OR 277
#define LOGIC_NOT 278
#define DECIMAL 279
#define OCTAL 280
#define HEX 281
#define STRING 282
#define INT 283
#define DOUBLE 284
#define FLOAT 285
#define CHAR 286
#define VOID 287
#define STRUCT 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define RETURN 293
#define BREAK 294
#define CONTINUE 295
#define CONST 296
#define ASSIGN 297
#define TRUE 298
#define FALSE 299
#define LBRACE 300
#define RBRACE 301
#define LPARENTHESIS 302
#define RPARENTHESIS 303
#define LSQUARE 304
#define RSQUARE 305
#define SEMICOLON 306
#define DOT 307
#define COMMA 308
#define LE 309
#define GE 310
#define THEN 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "./src/frontend/parser/parser.ypp" /* yacc.c:1909  */

    compiler::basic_type                btype;
    compiler::Item_root*                item_root;               // root
    compiler::Item_decl*                item_decl;
    compiler::Item_stmt*                item_stmt;
    compiler::Item_stmt_decl*           item_stmt_decl;
    compiler::Item_func_def*            item_func_def;
    compiler::Item_expr*                item_expr;
    compiler::Item_expr_comma*          item_expr_comma;
    compiler::Item_ident*               item_ident;
    compiler::Item_ident_array*         item_ident_array;
    compiler::Item_ident_pointer*       item_ident_pointer;
    compiler::Item_decl_array_init*     item_decl_array_init;
    compiler::Item_literal*             item_literal;
    compiler::Item_literal_array_init*  item_literal_array_init;
    compiler::Item_decl_var*            item_decl_var;
    compiler::Item_decl_var_init*       item_decl_var_init;
    compiler::Item_func_def_list*       item_func_def_list;
    compiler::Item_func_def_arg*        item_func_def_arg;
    compiler::Item_func_call_list*      item_func_call_list;
    compiler::Item_block*               item_block;
    std::string*                        raw_string;
    double                              raw_number;
    char                                raw_char;

#line 192 "./src/frontend/parser/parser.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED  */
