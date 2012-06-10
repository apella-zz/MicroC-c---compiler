#ifndef COMPILER_X86_INCLUDED
#define COMPILER_X86_INCLUDED
/* compiles the node ast to x86 assembly */

#include "compiler.h"
#define compile_def(C) \
	virtual void compile(const C *, std::ostream&)

class Compiler_x86: public Abstract_compiler {
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
