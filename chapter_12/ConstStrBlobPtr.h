#include "StrBlobPtr.cpp"

class ConstStrBlobPtr{
	public:
		ConstStrBlobPtr(): curr(0) { }
		ConstStrBlobPtr(const StrBlob &a,size_t sz = 0):
			wptr(a.data),curr(sz){}
		string& deref() const;
		ConstStrBlobPtr& incr(); //Ç°×ºµÝÔö
		size_t cursize() {return curr;}
	private:
		shared_ptr<vector<string>> check(size_t,const string&)const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
};

ConstStrBlobPtr StrBlob::begin(){
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end(){
	auto ret = ConstStrBlobPtr(*this,data->size());
	return ConstStrBlobPtr(*this);
}