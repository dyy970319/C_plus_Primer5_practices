#ifndef __Query_Hpp__
#define __Query_Hpp__
#include <string>
#include "Query_base.hpp"

using namespace std;

	class Query{
		friend Query operator~(const Query &);
		friend Query operator|(const Query &,const Query &);
		friend Query operator&(const Query &,const Query &);
		public:
			Query(const string&);
			QueryResult eval(const TextQuery &t)const 
				{return q->eval(t);}
			string rep() const {
				cout<<"Query::rep()"<<endl;
				return q->rep();}
			void setRange(size_t min,size_t max){
				q -> setRange(min,max);
			}
		private:
			/*Query(shared_ptr<Query_base> query):q(query){
				cout<<"Query(shared_ptr<Query_base> query)"<<endl;}*/
			Query(Query_base *query):q(query){
				cout<<"Query(Query_base &query)"<<endl;}
			//shared_ptr<Query_base> q;
			Query_base *q;
	};

	std::ostream &operator<<(std::ostream &os,const Query &query)
	{
		return os<<query.rep();
	}


#endif