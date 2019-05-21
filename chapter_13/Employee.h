#include <string>

using namespace std;

class Employee{
	static unsigned int count;
	public:
		Employee(){
			++count;
			employee_number = count;
		}
		Employee(string s):name(s){
			++count;
			employee_number = count;
		}
		
	private:
		unsigned int employee_number;
		string name;
	
};