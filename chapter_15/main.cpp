#include "Basket.hpp"
#include <vector>
#include <memory>
#include "WordQuery.hpp"
#include "NotQuery.hpp"
#include "AndQuery.hpp"
#include "OrQuery.hpp"

int main()
{
	Query test1("a"),test2("b");
	/*AndQuery *aq = new AndQuery(test1,test2);
	Query_base *qb = *aq;
	*/
	ifstream infile("input.txt");
	TextQuery tq(infile,1,2);
	//Query q = Query("fiery") & Query("bird") | Query("wind");
	//AndQuery *test = new AndQuery(test1,test2);
	AndQuery test(test1,test2);
	//Query_base *qb = test;
	//Query_base *qb;
	//*qb = *test;
	Query_base &qb = test;
	Query_base &qb1 = test;
	if(typeid(qb) == typeid(AndQuery)){
		cout<<"you're so handsome"<<endl;
	}
	if(typeid(qb) == typeid(Query_base)){
		cout<<"you're so handsome too"<<endl;
	}
	if(typeid(qb) == typeid(qb1)&&typeid(qb)==typeid(AndQuery))
		cout<<"you're so handsome three"<<endl;
	//auto result = q.eval(tq);
	//print(cout,result);
	//cout<<q;
	//BinaryQuery a = Query("fiery") & Query("bird");
	//AndQuery b = Query("fiery") & Query("bird");
	//OrQuery c = Query("fiery") & Query("bird");
	/*Basket basket;
	basket.add_item(make_shared<Quote>("0-201-824",40));
	basket.add_item(make_shared<Quote>("0-201-824",40));
	basket.add_item(make_shared<Bulk_quote>("0-201",50,
		10,.25));
	basket.add_item(make_shared<Bulk_quote>("0-201",30,
		10,.25));
	basket.total_receipt(cout);*/
}