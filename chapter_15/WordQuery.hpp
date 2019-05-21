#include "Query.hpp"

class WordQuery:public Query_base{
	friend class Query;
	WordQuery(const std::string &s):query_word(s){
		cout<<"WordQuery(const std::string &s)"<<endl;
		}
	QueryResult eval(const TextQuery &t) const
		{return t.query(query_word);}
	std::string rep() const {
		cout<<"WordQuery::rep()"<<endl;
		return query_word;}
	std::string query_word;
};

inline Query::Query(const std::string &s):q(new WordQuery(s)){}