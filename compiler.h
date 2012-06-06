/* an abstract compiler class */
#include "Node.h"
#include <iostream>
#define compile_def(CLASSNAME) \
  virtual void compile(CLASSNAME__*, std::ostream) = 0
class Abstract_compiler {
 protected:

  compile_def(NProgram);
  compile_def(NBlock);
  compile_def(NFun_declaration);
  compile_def(NVar_declaration);

};
