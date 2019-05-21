#include "Blob.hpp"

template <typename T> 
	bool operator==(const BlobPtr<T>&,const BlobPtr<T>&);
template<typename T>class BlobPtr{
	friend bool operator==<T>
		(const BlobPtr<T>&,const BlobPtr<T>&);
	public:
		BlobPtr() try:curr(0) { }catch(const std::bad_alloc &e){
		//handle_out_of_memory(e);
	}
		BlobPtr(Blob<T> &a,size_t sz = 0) try:
			wptr(a.data),curr(sz) { }catch(const std::bad_alloc &e){
		//handle_out_of_memory(e);
	}
		T& operator*() const
		{
			auto p = check(curr,"dereference past end");
			return (*p)[curr];
		}
		BlobPtr& operator++();
		BlobPtr& operator--();
		BlobPtr operator++(int);
		BlobPtr operator--(int);
	private:
		std::shared_ptr<std::vector<T>>
			check(std::size_t,const std::string&) const;
		std::weak_ptr<std::vector<T>> wptr;
		std::size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr,"increment past end of BlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr,"decline past begin of BlobPtr");
	--curr;
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;
	--*this;
	return ret;
}