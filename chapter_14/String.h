#include <string>
#include <cstring>
#include <memory>

using namespace std;

class String{
	friend ostream &operator<<(ostream &,const String&);
	friend bool operator == (const String&,const String&);
	friend bool operator != (const String&,const String&);
	friend bool operator < (const String&,const String&);
	friend bool operator > (const String&,const String&);
	public:
		String():
			elements(nullptr),first_free(nullptr),cap(nullptr){
				}
		String(char* cptr){
			for(int i = 0;i != strlen(cptr);++i)
			{
				push_back(*cptr);
			}			
		}
		~String(){
			free();
		}
		String(String &&)noexcept;
		String(const String &);
		String &operator=(String &&);
		String &operator=(const String &);
		char &operator[](size_t n)
			{return elements[n];}
		void push_back(const char c);
		size_t size() const {return first_free - elements;}
		size_t capacity() const {return cap - elements;}
		char *begin() const {return elements;}
		char *end() const {return first_free;}
	private:
		static allocator<char> alloc;
		void chk_n_alloc()
			{if (size() == capacity()) reallocate();}
		pair<char*,char*>alloc_n_copy(const char*,const char*);
		void free();
		void reallocate();
		char *elements ;
		char *first_free ;
		char *cap;
};

allocator<char> String::alloc;