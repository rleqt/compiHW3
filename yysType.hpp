//
// Created by Admin on 06/12/2022.
//

#ifndef HW3_YYSTYPE_HPP
#define HW3_YYSTYPE_HPP
#include <string>
#include <vector>
using namespace std;
extern int yylineno ;

//int current_offset;
//globalStack sstack;


class stype{
public:
	int intVal ;
	string name;
	string type;
	vector<string> varTypes;
	vector<string> varNames;
	~stype() = default;
	stype() = default;
	stype(std::string typ, std::string name = "haha", int num = 0):intVal(num), varTypes(), varNames() {
		this->type = typ;
		this->name = name;
		//intVal = vval;
	}
};


class listOfYYstype : public stype{
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
};


class functionValue : public stype {
	bool val;
	string return_type; // ?? is the location right
	// types type;
	functionValue(std::string  value):stype("FUNC") {
		//val = value;
		//type = bool1;
	}
};
/*void insertVar(string name, string type)
{

   // current_offset++;
    //sstack.insert(name,current_offset,type);
}*/






#endif //HW3_YYSTYPE_HPP
