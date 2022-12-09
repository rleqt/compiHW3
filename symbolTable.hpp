#ifndef HW_SYMBOL_TABLE_H
#define HW_SYMBOL_TABLE_H
#include <string>
#include <vector>
#include "yysType.hpp"

struct var{
public:
    std::string name;
    int offset;
    std::string type;


    var()=default;
    var(string name,int offset,string type):name(name),offset(offset),type(type){}

};

class scopeStack{
    std::vector<var*> stack;
    int currentIndex;
    std::vector<int> offsets; // every enter to a new scope we push the offset here.
    int currentOffset;
    int currentScope;

public:
    scopeStack();
    int insert(string name, int offset, string type);
    bool isVarInTableStack(std::string name);
    bool isFuncInTable(string name);
    int closeScope();
    int openScope();


};
bool isVarInTable(std::string name);




#endif //HW_SYMBOL_TABLE_H