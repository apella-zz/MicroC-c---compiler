#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED

/* an abstract compiler class */
#include "Node.h"
#include <iostream>
#define compile_def(CLASSNAME) \
  virtual void compile(const CLASSNAME *, std::ostream&) = 0
class Abstract_compiler {
 public:

  compile_def(NProgram);
  compile_def(NBlock);
  compile_def(NFun_declaration);
  compile_def(NVar_declaration);
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
