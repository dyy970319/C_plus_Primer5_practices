#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr{
	friend void swap(HasPtr&,HasPtr&);
	public:
		//¿‡÷µ∞Ê±æ
		HasPtr(const string &s = string()):
			ps(new string(s)),i(0),use(new size_t(1)){ }
		HasPtr(const HasPtr &hp):
			ps(new string(*hp.ps)),i(hp.i),use(hp.use){
				cout<<"copy constructor"<<endl;
				++*use; }
		HasPtr(HasPtr &&hp):
			ps(hp.ps),i(hp.i),use(hp.use){
				cout<<"move constructor"<<endl;
				hp.ps = 0;}
		HasPtr& operator=(HasPtr hp){
			
			swap(*this,hp);
			return *this;
		}
		/*HasPtr& operator=(HasPtr &&hp){
			if(this != &hp){
				ps = hp.ps;
				i = hp.i;
				use = hp.use;
			}
			return *this;
		}
		HasPtr& operator=(const HasPtr &hp){
			ps = hp.ps;
			i = hp.i;
			use = hp.use;
			return *this;
		}*/
		
		bool operator <(const HasPtr &p){
			cout<<*ps<<endl;
			cout<<*p.ps<<endl;
			if(*ps < *p.ps){
				cout<<"true"<<endl;
				return true;
			}
			else{
				cout<<"false"<<endl;
				return false;
			}
		}
		~HasPtr(){ delete ps;}
	private:
		string *ps;
		int i;
		size_t *use;
};

inline void swap(HasPtr &lhs,HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps,rhs.ps);
	swap(lhs.i,rhs.i);
	swap(lhs.use,rhs.use);
	cout<<"change HasPtr's object"<<endl;
}
