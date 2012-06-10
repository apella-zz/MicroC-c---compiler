#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
//
//  Node.h
//  TinyC
//
//  Created by Bart Spiers on 03/04/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#include <vector>

enum NodeType {
  NPROGRAM,
  NBLOCK,
  NFUN_DECLARATION,
  NVAR_DECLARATION,
  NIF,
  NIF_DOUBLE,
  NWHILE,
  NASSIGN,
  NFUN_CALL,
  NWRITE,
  NREAD,
  NRETURN,
  NVAR,
  NARRAY_ACCESS,
  NBINOP,
  NUNOP,
  NNUMBER,
  NQCHAR,
  NLENGTH,

};

class NDeclaration;
class NExpression;
class NStatement;
class NVar_declaration;
class NFun_declaration;

typedef std::vector<NVar_declaration*> VariableList;
typedef std::vector<NFun_declaration*> FunctionList;
typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
//typedef std::vector<NDeclaration*> DeclarationList;

template <class T>
void deleteContents(std::vector<T> *vec){
    int size = vec->size();
    for (int i = 0; i < size; ++i)
        delete(vec->at(i));
}

class Node {

public:
  NodeType Ntype;
  Node(){}
  virtual ~Node() {}
 protected:
 Node(NodeType t):Ntype(t){}
};

class NStatement: public Node {
 protected:
 NStatement(NodeType t)
   :Node(t){}
 public:
  NStatement(){}
};

class NExpression: public Node {
 protected:
  NExpression(NodeType t)
    :Node(t){}
 public:
  NExpression(){}
};

class NType : public Node {
};

class NType_int : public NType {
};
class NType_char : public NType {
};
class NType_array : public NType {
public:
    NType* type;
    NExpression* expression;
    NType_array(NType* Type, NExpression* Expression)
      : type(Type), expression(Expression){}
    virtual ~NType_array() {
        delete type;
        delete expression;
    }
};

class NLeft_expression: public NExpression {
 protected:
  NLeft_expression(NodeType t)
    :NExpression(t){}
 public:
  NLeft_expression(){}
};

class NProgram: public Node {
public:
  //DeclarationList* declarations;
  VariableList* variables;
  FunctionList* functions;
  
  //NProgram(DeclarationList* Declarations):
  //declarations(Declarations){}
 NProgram(VariableList* Vars, FunctionList* Funcs)
   :variables(Vars), functions(Funcs){}
  //NProgram():declarations(new DeclarationList()){}
 NProgram()
   :variables(new VariableList()), functions(new FunctionList()){}
  virtual ~NProgram() {
    //deleteContents<NDeclaration*>(declarations);
    //delete declarations;
    deleteContents<NVar_declaration*>(variables);
    deleteContents<NFun_declaration*>(functions);
    delete variables;
    delete functions;
  }
};

class NDeclaration: public Node {
 protected:
  NDeclaration(NodeType t)
    :Node(t){}
public:
  NDeclaration(){}
    virtual ~NDeclaration() {}
};
class NBlock: public NStatement {
public:
    VariableList* var_declarations;
    StatementList* statements;
    NBlock(VariableList* Var_declarations, StatementList* Statements)
      :NStatement(NBLOCK), var_declarations(Var_declarations), statements(Statements) {}
    virtual ~NBlock() { 
        deleteContents<NVar_declaration*>(var_declarations);
        deleteContents<NStatement*>(statements);
        delete var_declarations;
        delete statements;
    }
};

class NFun_declaration: public NDeclaration {
public:
    NType* type;
    char* name;
    VariableList* formal_pars;
    NBlock* block;
    NFun_declaration(NType* Type, char* Name, VariableList* Formal_pars, NBlock* Block)
      :NDeclaration(NFUN_DECLARATION), type(Type), name(Name), formal_pars(Formal_pars), block(Block) {}

    virtual ~NFun_declaration() {
        delete type;
        delete name;
        deleteContents<NVar_declaration*>(formal_pars);
        delete formal_pars;
        delete block;
    }
};

class NVar_declaration: public NDeclaration {
public:
    NType* type;
    char* name;
    NVar_declaration(NType* Type, char* Name)
      :NDeclaration(NVAR_DECLARATION), type(Type), name(Name){}
    virtual ~NVar_declaration() { 
        delete type; 
        delete name;
    }
};

class NStatement_if: public NStatement {
public:
  NExpression* condition;
  NStatement* consequent;
 NStatement_if(NExpression* Condition, NStatement* Consequent)
   :NStatement(NIF), condition(Condition), consequent(Consequent){}
  virtual ~NStatement_if() {
    delete condition;
    delete consequent;
  }
};
class NStatement_if_double: public NStatement {
public:
  NExpression* condition;
  NStatement* consequent;
  NStatement* antecedent;
 NStatement_if_double(NExpression* Condition, NStatement* Consequent, NStatement* Antecedent)
   :NStatement(NIF_DOUBLE), condition(Condition), consequent(Consequent), antecedent(Antecedent){}
  virtual ~NStatement_if_double() {
    delete condition;
    delete consequent;
    delete antecedent;
  }
};

class NStatement_while: public NStatement {
public:
    NExpression* condition;
    NStatement* body;
    NStatement_while(NExpression* Condition, NStatement* Body)
      :NStatement(NWHILE), condition(Condition), body(Body){}
    virtual ~NStatement_while() {
        delete condition;
        delete body;
    }
};
class NStatement_assign: public NStatement {
public:
    NLeft_expression* left_expression;
    NExpression* expression;
    NStatement_assign(NLeft_expression* Left_expression, NExpression* Expression)
      :NStatement(NASSIGN), left_expression(Left_expression), expression(Expression){}
    virtual ~NStatement_assign() {
        delete left_expression;
        delete expression;
    }
};
class NFunction_call: public NStatement, public NExpression {
public:
    char* name;
    ExpressionList* parameters;
    NFunction_call(char* Name, ExpressionList* Parameters):
        name(Name), parameters(Parameters){}
    virtual ~NFunction_call() {
        delete name;
        deleteContents<NExpression*>(parameters);
        delete parameters;
    }
};
class NStatement_write: public NStatement {
public:
    NExpression* expression;
    NStatement_write(NExpression* Expression)
      :NStatement(NWRITE), expression(Expression){}
    virtual ~NStatement_write() {
        delete expression;
    }
};
class NStatement_read: public NStatement {
public: 
    NLeft_expression* expression;
    NStatement_read(NLeft_expression* Expression)
      :NStatement(NREAD), expression(Expression){}
    virtual ~NStatement_read() {
        delete expression;
    }
};
class NStatement_return: public NStatement {
public:
    NExpression* exp;
    NStatement_return(NExpression* Exp)
      :NStatement(NRETURN), exp(Exp){}
    virtual ~NStatement_return() {
        delete exp;
    }
};

class NVar: public NLeft_expression {
public:
    const char* name;
    NVar(const char* Name)
      :NLeft_expression(NVAR), name(Name){}
 
    virtual ~NVar() {
        delete name;
    }
};
class NArray_access: public NLeft_expression {
public:
    NLeft_expression* var_name;
    NExpression* index;
    NArray_access(NLeft_expression* Var_name, NExpression* Index)
      :NLeft_expression(NARRAY_ACCESS), var_name(Var_name), index(Index){}
    virtual ~NArray_access() {
        delete var_name;
        delete index;
    }
};
class NBinary_op: public NExpression {
public:
    NExpression* left;
    NExpression* right;
    int operation;
    NBinary_op(NExpression* Left, NExpression* Right, int Operation)
      :NExpression(NBINOP), left(Left), right(Right), operation(Operation){}

    virtual ~NBinary_op() {
        delete left;
        delete right;
    }
};
class NUnary_op: public NExpression {
public:
    NExpression* expression;
    int operation;
    NUnary_op(NExpression* Expression, int Operation)
      :NExpression(NUNOP), expression(Expression), operation(Operation){}
    virtual ~NUnary_op() {
        delete expression;
    }
};
class NNumber: public NExpression {
public:
    int value;
    NNumber(int Value)
      :NExpression(NNUMBER), value(Value){}
};
class NQchar: public NExpression {
public:
  char value;
 NQchar(char Value)
   :NExpression(NQCHAR), value(Value){}
};
class NLength: public NExpression {
public:
    NLeft_expression* expression;
    NLength(NLeft_expression* Expression)
      :NExpression(NLENGTH), expression(Expression){}
    virtual ~NLength() {
        delete expression;
    }
};
#endif
