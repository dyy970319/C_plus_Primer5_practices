#include "StrBlob.cpp"

class StrBlobPtr{
	public:
		StrBlobPtr(): curr(0) { }
		StrBlobPtr(StrBlob &a,size_t sz = 0):
			wptr(a.data),curr(sz){}
		string& deref() const;
		StrBlobPtr& incr(); //Ç°×ºµÝÔö
		size_t cursize() {return curr;}
	private:
		shared_ptr<StrVec> check(size_t,const string&)const;
		weak_ptr<StrVec> wptr;
		size_t curr;
};