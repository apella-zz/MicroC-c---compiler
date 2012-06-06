/* compiles the node ast to x86 assembly */

#include "compiler.h"

class Compiler_x86: public abstract_compiler {
 protected:
  void compile(NProgram*, std::ostream);
  void compile(NBlock*, std::ostream);
  void compile(NFun_declaration*, std::ostream);
  void compile(NVar_declaration*, std::ostream);

};
