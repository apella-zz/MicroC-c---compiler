#include "compiler_TAC.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>
#include <exception>

typedef std::pair<const char*, const char* > varType;

#define COMPILE_VECTOR_ELEMENTS(vec, out)   \
  for (unsigned int i = 0; i < (vec)->size(); ++i)	\
    compile((vec)->at(i), out)

#define COMPILE_ON_TYPE(N_TYPE, R_TYPE)                 \
  case N_TYPE:{                                         \
  const R_TYPE* x = static_cast<const R_TYPE*>(node);   \
  compile(x, out);                                      \
  break;}


unsigned int id;
std::stack< varType > vars;

void initialize() {
  id = 0;
  
}
const char* get_new_variable() {
  char* result = new char[8];
  sprintf(result, "var%3u", id++);
  
  return result;
}
varType make_var(const char* name = NULL) {
  const char* varName = get_new_variable();
  if (name == NULL) // it's a hidden variable
    name = varName;
  return std::make_pair<const char*, const char* >(varName, name);
}

void Compiler_TAC::compile(const NProgram* node, std::ostream& out) {
  initialize();
  COMPILE_VECTOR_ELEMENTS(node->variables, out);
  COMPILE_VECTOR_ELEMENTS(node->functions, out);
}

void Compiler_TAC::compile(const NBlock* node, std::ostream& out) {
  COMPILE_VECTOR_ELEMENTS(node->var_declarations, out);
  COMPILE_VECTOR_ELEMENTS(node->statements, out);
}

void Compiler_TAC::compile(const NFun_declaration* node, std::ostream& out) {
  out << node->name << ":\n";
  //node->formal_pars
  //compile(node->formal_pars, out);
  COMPILE_VECTOR_ELEMENTS(node->formal_pars, out);
  compile(node->block, out);
}

void Compiler_TAC::compile(const NVar_declaration* node, std::ostream& out) {
  //const char* varName = get_new_variable();
  varType var = make_var(node->name);
  vars.push(var);
  out << var.first << ":= 0\n";
  
}

void Compiler_TAC::compile(const NExpression* node, std::ostream& out) {
  /* check what type the node really is and call the accompanying compile method*/
  NodeType t = node->Ntype;
  switch(t){
    // is currently ambiguous
    //COMPILE_ON_TYPE(NFUN_CALL, NFunction_call);
    COMPILE_ON_TYPE(NVAR, NVar);
    COMPILE_ON_TYPE(NARRAY_ACCESS, NArray_access);
    COMPILE_ON_TYPE(NBINOP, NBinary_op);
    COMPILE_ON_TYPE(NUNOP, NUnary_op);
    COMPILE_ON_TYPE(NNUMBER, NNumber);
    COMPILE_ON_TYPE(NQCHAR, NQchar);
    COMPILE_ON_TYPE(NLENGTH, NLength);  
  default:
    throw "not an expression!";
  };
}


void Compiler_TAC::compile(const NStatement* node, std::ostream& out) {
  /* check what type the node really is and call the accompanying compile method*/
  NodeType t = node->Ntype;  
  switch(t){
    COMPILE_ON_TYPE(NBLOCK, NBlock);
    //COMPILE_ON_TYPE(NFUN_DECLARATION, NFun_declaration);
    //COMPILE_ON_TYPE(NVAR_DECLARATION, NVar_declaration);
    COMPILE_ON_TYPE(NIF, NStatement_if);
    COMPILE_ON_TYPE(NIF_DOUBLE, NStatement_if_double);
    COMPILE_ON_TYPE(NWHILE, NStatement_while);
    COMPILE_ON_TYPE(NASSIGN, NStatement_assign);
    // currently ambiguous
    //COMPILE_ON_TYPE(NFUN_CALL, NFunction_call);
    COMPILE_ON_TYPE(NWRITE, NStatement_write);
    COMPILE_ON_TYPE(NREAD, NStatement_read);
    COMPILE_ON_TYPE(NRETURN, NStatement_return);
  
    default:
      throw "not a statement!";
  };
}

void Compiler_TAC::compile(const NStatement_if* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_if_double* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_while* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_assign* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_write* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_read* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NStatement_return* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NArray_access* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NBinary_op* node, std::ostream& out) {
  	compile(node->left, out);
        varType first = vars.top();
        //std::pair<const char*, const char*> first = vars.top();
        vars.pop();
        //const char* first = ids.top();
        //vars.pop();
	compile(node->right, out);
        varType second = vars.top();
        //const char* second = ids.pop();
        vars.pop();
                
	//write_line("popl %eax", out); // get the result of left in eax
	int op = node->operation;
        
        const char* cop;
	switch(op) {
	case 0: // minus
          cop = "-";
		break;
	case 1: // plus
          cop = "+";
		break;
	case 2: // times
          cop = "*";
		break;
	case 3: // divide
          cop = "/";
		break;
	case 4: // equal
          cop = "==";
		break;
	case 5: // nequal
          cop = "!=";
		break;
	case 6: // greater
          cop = ">";
		break;
	case 7: // less
          cop = "<";
		break;
	default: //error
          cop = "?";
          throw std::exception();
		//TODO do something on error.
		break;
	}
        const char *varName = get_new_variable();
        varType var = make_var(varName);
        vars.push(var);
                
        out << varName << ":= " << first.first << cop << second.first << "\n";
}

void Compiler_TAC::compile(const NUnary_op* /*node*/, std::ostream& /*out*/) {
  
}

void Compiler_TAC::compile(const NLength* /*node*/, std::ostream& /*out*/) {
  
}

