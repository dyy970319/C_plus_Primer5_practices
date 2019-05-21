#include "StrBlob.cpp"

class StrBlobPtr{
	friend bool operator==(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&,const StrBlobPtr&);
	friend StrBlobPtr& operator+(StrBlobPtr&,size_t );
	friend StrBlobPtr& operator-(StrBlobPtr&,size_t);
	public:
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlob &a,size_t sz = 0):
			wptr(a.data),curr(sz){}
		string& deref() const;
		StrBlobPtr& incr(); //Ç°×ºµÝÔö
		size_t cursize() {return curr;}
		string &operator[](size_t n)
			{return (*wptr.lock())[n];}
		StrBlobPtr& operator++();	
		StrBlobPtr& operator--();
		StrBlobPtr operator++(int);	
		StrBlobPtr operator--(int);
		string& operator*()const{
			auto p = check(curr,"dereference past end");
			return (*p)[curr];
		}
		string* operator->()const{
			return & this->operator*();
		}
	private:
		shared_ptr<StrVec> check(size_t,const string&)const;
		weak_ptr<StrVec> wptr;
		size_t curr;
};