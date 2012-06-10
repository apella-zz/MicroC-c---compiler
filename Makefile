# $Id$
# plain simple Makefile to build exprtest

CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -ansi -g
LDFLAGS = 
YACCFLAGS = --debug --verbose --warning=all
LEXFLAGS = --align
#flex arguments
# --align	trade off larger tables for better memory alignment
# --debug	enable debug mode in scanner
# --verbose	write summary of scanner statistics to stdout


HEADERS = driver.h parser.h scanner.h Node.h \
    y.tab.h FlexLexer.h location.hh position.hh stack.hh \
		compiler.h compiler_x86.h compiler_TAC.h

all: exprtest

# Generate scanner and parser

parser.cc: parser.yy
	$(YACC) $(YACCFLAGS) -o parser.cc --defines=parser.h parser.yy
scanner.cc: scanner.ll
	$(LEX) -o scanner.cc scanner.ll

# Implicit rule to compile c++ files

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link executable

exprtest: main.o parser.o scanner.o driver.o compiler_x86.o compiler_TAC.o
	$(CXX) $(LDFLAGS) -o $@ main.o parser.o scanner.o driver.o compiler_x86.o compiler_TAC.o

clean:
	rm -f main *.o

extraclean: clean
	rm -f parser.cc parser.h scanner.cc parser.tab.hh parser.tab.cc parser.tab.hh location.hh position.hh stack.hh
