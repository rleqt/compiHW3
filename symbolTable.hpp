#ifndef HW_SYMBOL_TABLE_H
#define HW_SYMBOL_TABLE_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "yysType.hpp"
#include "hw3_output.hpp"
using namespace output;
extern int yylineno ;


struct var{
public:
	string name;
	string type;
//    vector<string> argNames;
//    vector<string> argTypes;

	var()=default;
	var(string name,string type):name(name),type(type){


	}

};

class func{
public:
	string name;
	vector<string> argTypes;
	vector<string> argNames;
	string returnType;
	func(string name, vector<string> argTypes, vector<string> argNames, string returnType){
		this->name = name;
		this->returnType = returnType;
		for(int i =0; i < argTypes.size(); i++ ){
			this->argTypes.push_back(argTypes[i]);
			this->argNames.push_back(argNames[i]);
		}
	}
};

class funcStack{
public:
	vector<func*> funcs;
	funcStack(): funcs() {

	}
	void addFunc(string name, vector<string> argTypes, vector<string> argNames, string returnType){
		funcs.push_back(new func(name, argTypes, argNames, returnType));
	}
};


class oneStack{
public:
	bool first;     // if it's the first scope I don't want to go above it.
	bool amIInALoop;
	string returnType;// currently not working
	vector<var*> varStack;
	oneStack(bool isLoop = false, bool isFirst = false): first(isFirst), amIInALoop(isLoop){}

};


class globalStack{
public:
	vector<oneStack*> scopes;
	funcStack functions;
	string returnType;
	int offset;
	int curOffset;
	bool isFirst;
	bool wasThereAMain;

	vector<int> offsets;



	globalStack(): scopes(),functions(),returnType("NONE"),offset(0), curOffset(0), isFirst(true), wasThereAMain(false), offsets(){}

	bool isFuncInTable(string name){
		for( int j=0;j<functions.funcs.size();j++)
		{
			if (functions.funcs[j]->name == name)
				return true;
		}
		errorUndef(yylineno,name);
		exit(1);
	}
	void isFuncNotInTable(string name){
		for( int j=0;j<functions.funcs.size();j++)
		{
			if (functions.funcs[j]->name == name)
			{
				errorDef(yylineno,name);
				exit(1);
			}
		}

	}
	bool isTypesMatchingFunc(string name ,vector<string> argTypes) /// assume func exists
	{
		func* dest= NULL;
		for( int j=0;j<functions.funcs.size();j++)
		{
			if (functions.funcs[j]->name == name)
				dest = functions.funcs[j];
		}
		for (int i = 0; i < argTypes.size(); ++i) {
			bool found = false;
			for (int j = 0; j < dest->argTypes.size(); ++j) {
				if(argTypes[i] == dest->argTypes[j]){
					found = true;
				}
				if(!found){
					errorPrototypeMismatch(yylineno, dest->name, dest->argTypes);
				}
			}
		}
		return true;

	}
	void addFunc(string name, vector<string> argTypes, vector<string> argNames, string returnType, bool print){
		if(name == "main"){
			wasThereAMain = true;
		}
		this->functions.addFunc(name, argTypes, argNames, returnType);
		if(!print) {
			for (int i = 0; i < argTypes.size(); ++i) {
				scopes.back()->varStack.push_back(new var(argNames[i], argTypes[i]));
				this->curOffset++;
			}
			this->returnType = returnType;
		}
	}
	void printAndExitScope(){
		endScope();
		for (int i = 0; i < this->scopes.back()->varStack.size(); ++i) {
			printID(scopes.back()->varStack[i]->name, offset+i,scopes.back()->varStack[i]->type);
		}
		offset = offsets.back();
		offsets.pop_back();
		scopes.pop_back();
	}
	void closeFinal(){
		for (int i = 0; i < this->functions.funcs.size(); ++i) {
			cout<< this->functions.funcs[i]->name <<" "<< makeFunctionType(this->functions.funcs[i]->returnType,this->functions.funcs[i]->argTypes)<<" 0"<< endl;
		}
	}
	void checkRetType(string s="VOID") {

		if(returnType!=s)
		{
			errorMismatch(yylineno);
			exit(1);
		}
//        if(scopes.back()->returnType!=s)
//        {
//            errorMismatch(yylineno);
//            exit(1);
//        }
	}
	string getRetType(string s) {///assume func exists
		for( int j=0;j<functions.funcs.size();j++)
		{
			if (functions.funcs[j]->name == s)
				return functions.funcs[j]->returnType;
		}


	}
	// ready
	void openScope( bool inLoop, int numParams = 0){
		if(scopes.size() == 0){
			offset = -numParams;
			scopes.push_back(new oneStack(false, true));
			offsets.push_back(0);
		}
		else {
			if (scopes[scopes.size() - 1]->amIInALoop) {
				inLoop = true;
			}
			scopes.push_back(new oneStack(inLoop, false));
			offsets.push_back(offset);
			offset = curOffset;
		}
	}
	void addToCurrentStack(string name, string type){
		scopes.back()->varStack.push_back(new var(name, type));
		this->curOffset++;
	}
	bool isInLoop(){
		return scopes[scopes.size()-1]->amIInALoop;
	}
	string getType(string name){// assume exists
		for( int i=scopes.size()-1;i>=0 ;i--)
		{
			for( int j=0;j<scopes[i]->varStack.size();j++)
			{
				if (scopes[i]->varStack[j]->name == name)
					return scopes[i]->varStack[j]->type;
			}
		}
		return "wtf are u doing here";
	}
	bool isVarInTable(string name){

		for( int i=scopes.size()-1;i>=0 ;i--)
		{
			for( int j=0;j<scopes[i]->varStack.size();j++)
			{
				if (scopes[i]->varStack[j]->name == name)
					return true;
			}
		}
		errorUndef(yylineno,name);
		exit(1);
	}
	void printing(){
		std::cout <<(functions.funcs[0]->name)<<endl;
		std::cout <<(functions.funcs[1]->name);
	}

};



/*bool isVarInTable(std::string name)
{

    sstack.isVarInTableStack(name);
}*/




#endif //HW_SYMBOL_TABLE_H