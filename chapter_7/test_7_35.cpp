#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

typedef string Type;
Type initVal();
class Exercise {
	public:
		typedef double Type;
		Type setVal(Type);
		Type initVal(){return 2;}
	private:
		int val;
};

Exercise::Type Exercise::setVal(Type parm){
	val = parm + initVal();
	return val;
}

int main()
{

}
	
