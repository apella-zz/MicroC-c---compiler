#include "compiler_x86.h"
#include <vector>
#include <deque>

#define COMPILE_VECTOR_ELEMENTS(vec, out)   \
  for (unsigned int i = 0; i < (vec)->size(); ++i)	\
    compile((vec)->at(i), out)

typedef std::pair<const char*, int> varType;
static int varPos; // how deep on the stack is the variable?
static unsigned int nrOfVarsInCurrentScope; // how many variables are there in the current scope?
static int scope;
static std::deque<std::pair<const char*, int> > variables;

static void initialize() {
	scope = 0;
	varPos = 0;
	nrOfVarsInCurrentScope = 0;
	variables = std::deque<std::pair<const char*, int> >();
}
/* two spaces per depth */
void write_spaces(int depth, std::ostream& out) {
  for (int i = 0; i < depth; ++i)
    out << "  ";
}

void write_line(const char* text, std::ostream& out) {
  write_spaces(scope, out);
  out << text << "\n";
}

void write_prologue(std::ostream& out) {
  write_line(".section .text", out);
  write_line(".globl _start\n", out);// extra new line
  write_line("_start:", out);
  ++scope;
  write_line("call main", out);
  write_line("jmp exit", out);
  --scope;    
}

void write_epilogue(std::ostream& out) {
  write_line(".type exit, @function", out);
	write_line("exit:", out);
	++scope;
	write_line("movl $0, %ebx", out);
	write_line("movl $1, %eax", out);
	write_line("int $0x80", out);
}

void Compiler_x86::compile(const NProgram* node, std::ostream& out) {
	initialize();
	write_prologue(out);

	VariableList* vars = node->variables;
	FunctionList* funs = node->functions;
	COMPILE_VECTOR_ELEMENTS(vars, out);
	COMPILE_VECTOR_ELEMENTS(funs, out);
        write_epilogue(out);
  //COMPILE_VECTOR_ELEMENTS(declarations, out);
  //for (unsigned int i = 0; i < declarations->size(); ++i)
  //  compile(declarations->at(i), out);

}

void Compiler_x86::compile(const NBlock* node, std::ostream& out) {
	//VariableList* var_decl = node->var_declarations;
	COMPILE_VECTOR_ELEMENTS(node->var_declarations, out );
	// TODO: make statements unambiguous.
	// StatementList* stlst = node->statements;
	// COMPILE_VECTOR_ELEMENTS(stlst, out); 
}
void Compiler_x86::compile(const NFun_declaration* node, std::ostream& out) {
  /* type definition */
  out <<".globl " << node->name << "\n";
  out << ".type " << node->name << ", @function\n";
  /* todo: might want to add some extra info about the function in commentary*/
  out << node->name << ":";
  scope += 1;
  write_line("pushl %ebp # save frame pointer on the stack", out); 
  write_line("movl %esp, %ebp # set frame pointer", out);
  /* handle the arguments */
  COMPILE_VECTOR_ELEMENTS(node->formal_pars, out);
  /* compile the function body */
  compile(node->block, out);
  /* TODO: there might be some extra code necessary at the end of a function, check this.*/
  write_line("movl %ebp, %esp", out);
  write_line("popl %ebp% # restore old frame pointer", out);
  
  // pop the variables defined in the formal pars back from the stack
  for (unsigned int i = 0; i < nrOfVarsInCurrentScope; ++i) {
    variables.pop_back();
  }

  scope -= 1;
}
void Compiler_x86::compile(const NVar_declaration* node, std::ostream& /*out*/) {
	const char *name = node->name;
	varPos -= 4; // move the position further for the next adress
	variables.push_back(varType(name, varPos));
        nrOfVarsInCurrentScope++;
}

void Compiler_x86::compile(const NStatement_if* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NStatement_if_double* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NStatement_while* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NStatement_assign* node, std::ostream& out) {
  //compile(node->left_expression, out);
  
}
void Compiler_x86::compile(const NStatement_write* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NStatement_read* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NStatement_return* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NArray_access* /*node*/, std::ostream& /*out*/) {
	
}
void Compiler_x86::compile(const NBinary_op* node, std::ostream& out) {
	// TODO: make expressions unambiguous
	//compile(node->left, out);
	//compile(node->right, out);
	write_line("popl %eax", out); // get the result of left in eax
	int op = node->operation;
	switch(op) {
	case 0: // minus
		write_line("subl %eax, (%esp)", out);
		break;
	case 1: // plus
		write_line("addl %eax, (%esp)", out);
		break;
	case 2: // times
		write_line("imul %eax, (%esp)", out);
		break;
	case 3: // divide
		break;
	case 4: // equal
		break;
	case 5: // nequal
		break;
	case 6: // greater
		break;
	case 7: // less
		break;
	default: //error
		//TODO do something on error.
		break;
	}
}

void Compiler_x86::compile(const NUnary_op* /*node*/, std::ostream& /*out*/) {
}


void Compiler_x86::compile(const NLength* /*node*/, std::ostream& /*out*/) {
}
