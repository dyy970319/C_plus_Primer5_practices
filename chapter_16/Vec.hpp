#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

template<typename V> class Vec{
	public:
		Vec():
			elements(nullptr),first_free(nullptr),cap(nullptr){
				}
		//Vec();
		Vec(initializer_list<V> lst){
			for(auto beg = lst.begin();beg != lst.end();++beg)
			{
				reallocate();
				push_back(*beg);
			}
		}
		Vec(const Vec&);
		Vec(Vec &&) noexcept;
		Vec &operator=(Vec&&);
		Vec &operator=(const Vec&);
		~Vec();
		void push_back(const V&);
		void pop_back();
		V& returnStr(size_t n){
			return *(begin()+n);
		}
		size_t size() const {return first_free - elements;}
		size_t capacity() const {return cap - elements;}
		V *begin() const {return elements;}
		V *end() const {return first_free;}
		bool empty(){
			if(size() == 0)
				return false;
			else
				return true;
		}
		void reserve(int);
		void resize(int);
		void resize(int,V);
		template<class... Args>void emplace_back(Args&&...);
	private:
		static allocator<V> alloc;
		void chk_n_alloc()
			{if (size() == capacity()) reallocate();}
		pair<V*,V*> alloc_n_copy
			(const V*,const V*);
		void free();
		void reallocate();
		V *elements;
		V *first_free;
		V *cap;	
};
template<typename V>
	allocator<V> Vec<V>::alloc;

template<typename V>
	void Vec<V>::push_back(const V&s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);
}

template<typename V>
	void Vec<V>::pop_back()
{
	alloc.destroy(--first_free);
}

template<typename V>
	pair<V*,V*>Vec<V>::alloc_n_copy(const V *b,const V *e)
{
	auto data = alloc.allocate(e - b);
	return {data,uninitialized_copy(b,e,data)};
}

template<typename V>
	void Vec<V>::free()
{
	if(elements){
		auto p = first_free;
		//for_each(first_free,elements,[&p](V s){alloc.destroy(--p);});
		for(auto p = first_free;p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements,cap - elements);
	}
}

template<typename V>
	Vec<V>::Vec(const Vec<V> &s)
{
	auto newdata = alloc_n_copy(s.begin(),s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename V>
Vec<V>::Vec(Vec<V> &&s)  noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

template<typename V>Vec<V>::~Vec(){free();}

template<typename V>
	Vec<V> &Vec<V>::operator=(const Vec<V> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename V>
	Vec<V> &Vec<V>::operator=(Vec<V> &&rhs)
{
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

template<typename V>
	void Vec<V>::reallocate()
{
	/*auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size();++i)
		alloc.construct(dest++,move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;*/
	auto newcapacity = size() ? 2 *size():1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()),
						make_move_iterator(end()),
						first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
}
template<typename V>
void Vec<V>::reserve(int i)
{
	alloc.allocate(i);
}
template<typename V>
void Vec<V>::resize(int i)
{
	if(capacity() < i){
		while(capacity() < i){
			reallocate();
			alloc.construct(first_free++," ");
		}
	}
	else{
		while(capacity() > i)
			alloc.destroy(--first_free);
	}
}
template<typename V>
void Vec<V>::resize(int i,V s)
{
	if(capacity() < i){
		while(capacity() < i){
			reallocate();
			alloc.construct(first_free++,s);
		}
	}
	else{
		while(capacity() > i)
			alloc.destroy(--first_free);
	}
}

template<typename V>
	template<class... Args>
	inline void Vec<V>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++,std::forward<Args>(args)...);
}
