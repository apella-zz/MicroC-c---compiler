/* compiles the nodes to three-address code instrucitons */
#include "Node.h"
#include <iostream>
#include <vector>

void Compiler_TAC::compile(NProgram* node, std::ostream out) {
  for (int i = 0; i < node->declarations->length(); ++i) {
    compile(node->declarations->at(i), out); }
}

void Compiler_TAC::compile(NFun_declaration* node, std::ostream out) {
  
}

void Compiler_TAC::compile(NVar_declaration* node, std::ostream out) {
  
}
void Compiler_TAC::compile(NBlock* node, std::ostream out) {

}
