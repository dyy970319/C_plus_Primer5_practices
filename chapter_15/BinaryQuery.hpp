#ifndef __BinaryQuery_H__
#define __BinaryQuery_H__
#include "Query.hpp"

class BinaryQuery:public Query_base{
	protected:
		BinaryQuery(const Query &l,const Query &r,std::string s):
			lhs(l),rhs(r),opSym(s){
				cout<<"BinaryQuery(const Query &l,const Query &r,std::string s)"<<endl;
				}
		std::string rep() const {
			cout<<"BinaryQuery::rep()"<<endl;
			return "(" + lhs.rep() +" "
							+ opSym + " "
							+ rhs.rep() + ")";}
		Query lhs,rhs;
		std::string opSym;
};

#endif