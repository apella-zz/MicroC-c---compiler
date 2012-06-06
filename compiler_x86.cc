#include "compiler_x86.h"

#define COMPILE_VECTOR_ELEMENTS(vector, out)   \
  for (int i = 0; i < vector__->length(); ++i) \
    compile(vector->at(i), out)


static int scope;

void write_prologue(std::ostream out) {
  
}

void write_epilogue(std::ostream out) {
  out << "movl %epb, %esp\n";
  out << "popl %ebp /* restore old frame pointer */\n";
  out << "ret\n";
}
/* two spaces per depth */
void write_spaces(int depth, std::ostream out) {
  for (int i = 0; i < depth; ++i)
    out << "  ";
}

void write_line(char* text, std::ostream out) {
  write_spaces(scope, out);
  out << text << "\n";
}

void Compiler_x86::compile(NProgram* node, std::ostream out) {
  scope = 0; /* this is the root node*/
  COMPILE_VECTOR_ELEMENTS(node->declarations, out);
}

void Compiler_x86::compile(NBlock* node, std::ostream out) {
  COMPILE_VECTOR_ELEMENTS(node->var_declarations, out);
  COMPILE_VECTOR_ELEMENTS(node->statements, out); 
}
void Compile_x86::compile(NFun_declaration* node, std::ostream out) {
  /* type definition */
  out << ".type " << node->name << ", @function/n";
  /* todo: might want to add some extra info about the function in commentary*/
  out << node->name << ":";
  scope += 1;
  write_line("pushl %ebp # save frame pointer", out); 
  write_line("movl %esp, %ebp # set frame pointer", out);
  /* handle the arguments */
  COMPILE_VECTOR_ELEMENTS(node->formal_pars, out);
  /* compile the function body */
  compile(node->block, out);
  /* TODO: there might be some extra code necessary at the end of a function, check this.*/
  scope -= 1;
}

