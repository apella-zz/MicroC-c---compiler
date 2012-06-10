// $Id: exprtest.cc 18 2007-08-19 19:51:52Z tb $

#include <iostream>
#include <fstream>

#include "driver.h"
#include "Node.h"
#include "compiler_x86.h"
#include "compiler_TAC.h"

using namespace miniC;
int main(int argc, char *argv[])
{
	NProgram* program = 0;
	Driver driver(program);
        driver.trace_parsing = driver.trace_scanning = true;
	bool readfile = false;
	
	/*for(int ai = 1; ai < argc; ++ai) {
	  if (argv[ai] == std::string ("-p")) {
	    driver.trace_parsing = true;
	  }
	  else if (argv[ai] == std::string ("-s")) {
	    driver.trace_scanning = true;
	  }
	  else {*/
	    // read a file with expressions
	    std::fstream infile("./test.c");
	    //std::fstream infile(argv[ai]);
	    if (!infile.good()) {
	      //std::cerr << "Could not open file: " << argv[ai] << std::endl;
	      return 0;
	    }
	    bool result = driver.parse_file("./test.c");
	    //bool result = driver.parse_stream(infile, argv[ai]);

	    if (result) {
	      std::cout << "succes!\n";
	      // if the parsing succeeded, program will now be filled with the AST.
              program = driver.programBlock;
	      //Compiler_x86 compiler;
              Compiler_TAC compiler;
	      compiler.compile(program, std::cout);
	    }
	    
	    readfile = true;
            //  }
            //}
	if (readfile) return 0;
}
