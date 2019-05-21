#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

class Example{
	public:
		 static constexpr double rate = 6.5;
		static const int vecSize = 20;
		static vector<double> vec;
};

constexpr double Example::rate;
const int Example::vecSize; 
vector<double> Example::vec(vecSize);

int main()
{
	//vector<int> test(1,10);
}
	
