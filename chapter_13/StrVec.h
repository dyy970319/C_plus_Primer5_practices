#include <string>
#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

class StrVec{
	public:
		StrVec():
			elements(nullptr),first_free(nullptr),cap(nullptr){
				}
		//StrVec();
		StrVec(initializer_list<string> lst){
			for(auto beg = lst.begin();beg != lst.end();++beg)
			{
				reallocate();
				push_back(*beg);
			}
		}
		StrVec(const StrVec&);
		StrVec(StrVec &&) noexcept;
		StrVec &operator=(StrVec&&);
		StrVec &operator=(const StrVec&);
		~StrVec();
		void push_back(const string&);
		void pop_back();
		string& returnStr(size_t n){
			return *(begin()+n);
		}
		size_t size() const {return first_free - elements;}
		size_t capacity() const {return cap - elements;}
		string *begin() const {return elements;}
		string *end() const {return first_free;}
		bool empty(){
			if(size() == 0)
				return false;
			else
				return true;
		}
		void reserve(int);
		void resize(int);
		void resize(int,string);
	private:
		static allocator<string> alloc;
		void chk_n_alloc()
			{if (size() == capacity()) reallocate();}
		pair<string*,string*> alloc_n_copy
			(const string*,const string*);
		void free();
		void reallocate();
		string *elements;
		string *first_free;
		string *cap;	
};
allocator<string> StrVec::alloc;
