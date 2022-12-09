//
// Created by Admin on 06/12/2022.
//

#ifndef HW3_YYSTYPE_HPP
#define HW3_YYSTYPE_HPP
#include "hw3_output.hpp"
using std::string;
using std::vector;
extern int yylineno ;
//#include "tokens.hpp"





struct stype{

    int intVal ;
    string name;
    string type;
     //~stype() = default;
    /*stype(std::string typ) {
        type = typ;
        //intVal = vval;
    }*/
};
#define YYSTYPE stype

/*class listOfYYstype : public stype{
    std::vector<stype> exps;
    void addyystype(stype exp){
        exps.push_back(exp);
    }
};

class booleanValue : public stype{
    bool val;
    booleanValue(bool value): stype("BOOL"){
        val = value;
    }
};
class byteValue : public stype{
    int val;
    byteValue(int value): stype("BYTE"){
        val = value;
    }
};
class integerValue : public stype{
    int val;
    integerValue(int value): stype("INT"){
        val = value;
    }
};*/

/*
class functionValue : public stype {
    bool val;
   // types type;
    functionValue(std::string  value):stype("FUNC") {
        //val = value;
        //type = bool1;
    }
};*/

/*
void isValidByte(int n)
{
    if (n>255)
    {
        output::errorMismatch(yylineno);
        exit(1);
    }
}*/




#endif //HW3_YYSTYPE_HPP
