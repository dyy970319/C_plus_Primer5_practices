#include "StrBlob.h"

class ConstStrBlobPtr{
	public:
		ConstStrBlobPtr(): curr(0) { }
		ConstStrBlobPtr(const StrBlob &a,size_t sz = 0):
			wptr(a.data),curr(sz){}
		string& deref() const;
		ConstStrBlobPtr& incr(); //Ç°×ºµÝÔö
		size_t cursize() {return curr;}
		const string& operator*()const{
			auto p = check(curr,"dereference past end");
			return (*p)[curr];
		}
		const string* operator->()const{
			return & this->operator*();
		}
	private:
		shared_ptr<StrVec> check(size_t,const string&)const;
		weak_ptr<StrVec> wptr;
		size_t curr;
};

/*ConstStrBlobPtr StrBlob::begin(){
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end(){
	auto ret = ConstStrBlobPtr(*this,data->size());
	return ConstStrBlobPtr(*this);
}*/