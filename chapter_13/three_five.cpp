#include <set>
#include <cmath>
#include <iostream>

using namespace std;

class numbered{
	friend void f(const numbered &s);
	public:
		numbered(){
			int number = 0;
			while(serial_numbers.find(number)!=serial_numbers.end()){
				++number;
			}
			serial_numbers.insert(number);
			mysn = number;
		}
		numbered(const numbered &num){
			int number = 0;
			while(serial_numbers.find(number)!=serial_numbers.end()){
				++number;
			}
			serial_numbers.insert(number);
			mysn = number;
		}
		static set<int> serial_numbers;
		//set<int> serial_numbers;
	private:
		int mysn;
};

set<int> numbered::serial_numbers;

void f(const numbered &s) {
	cout<<s.mysn<<endl;
}

int main()
{
	numbered a,b=a,c=b;
	f(a);f(b);f(c);
}