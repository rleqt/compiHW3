//
// Created by Admin on 06/12/2022.
//

#include "symbolTable.hpp"
extern int yylineno ;


scopeStack sstack;


bool scopeStack::isVarInTableStack(std::string name)
{
    for( int i=0;i<stack.size();i++)
    {
        if(stack[i]->name==name)
            return true;
    }
    return false;

}

bool scopeStack::isFuncInTable(string name)
{
 for( int i=0;i<sstack.stack.size();i++)
    {
        if(sstack.stack[i]->name==name&&sstack.stack[i]->type=="Func")
            {return true;}
    }
    return false;

}

int scopeStack::closeScope() {

}

int scopeStack::insert(string name, int offset, string type ) {
    var v=var(name,offset,type);
    stack.push_back(&v);
}

int scopeStack::openScope() {

}

scopeStack::scopeStack() {


}
bool isVarInTable(std::string name)
    {
        sstack.isVarInTableStack(name);
    }
