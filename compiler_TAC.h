#ifndef COMPILER_TAC_H_INCLUDED
#define COMPILER_TAC_H_INCLUDED
/* compiles the nodes to three-address code instructions */
#include "Node.h"
#include <iostream>
#include "compiler.h"
#define compile_def(C) \
	virtual void compile(const C *, std::ostream&)

class Compiler_TAC : public Abstract_compiler {
public:
  compile_def(NProgram);
  compile_def(NBlock);
  compile_def(NFun_declaration);
  compile_def(NVar_declaration);
  compile_def(NExpression);
  compile_def(NStatement);
  compile_def(NStatement_if);
  compile_def(NStatement_if_double);
  compile_def(NStatement_while);
  compile_def(NStatement_assign);
  compile_def(NStatement_write);
  compile_def(NStatement_read);
  compile_def(NStatement_return);
  compile_def(NArray_access);
  compile_def(NBinary_op);
  compile_def(NUnary_op);
  compile_def(NLength);	
};
#undef compile_def
#endif
