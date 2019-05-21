#include <string>
#include <cstring>
#include <memory>

using namespace std;

class String{
	public:
		String() = default;
		String(char* cptr){
			auto p = alloc.allocate(strlen(cptr));
			alloc.construct(p,cptr);
		}
		String(String &&);
		String(const String &);
		String &operator=(String &&);
		String &operator=(const String &);
	private:
		static allocator<char*> alloc;		
};

allocator<char*> String::alloc;