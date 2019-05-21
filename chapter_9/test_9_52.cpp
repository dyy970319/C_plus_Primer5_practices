#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
	string s = "3(1+1)";
	stack<char> intStack;
	short left_par_number = 0; 
	for(int i = 0; i < s.size();++i){
		if(s[i] == '(')
			++left_par_number;
		intStack.push(s[i]);
	}
	string result;
	while(intStack.top() != '('){
		if(intStack.top() == ')')
			intStack.pop();
		else{
			result.insert(result.begin(),intStack.top());
			intStack.pop();
		}
	}
	intStack.pop();
	cout<<intStack.top()<<endl;
	string symbols = "+-*/";
	string numbers = "0123456789";
	int result_value = stoi(result);
	int symbol_first_index = result.find_first_of(symbols);
	int number_first_index = result.find_first_of(numbers,symbol_first_index);
	char symbol = result[symbol_first_index];
	result = string(result,number_first_index);
	if(symbol == '+'){
		result_value += stoi(result);
	}
	cout<<result_value<<endl;
	char result_ch = to_string(result_value)[0];
	//cout<<intStack.top()<<endl;
	intStack.push(result_ch);
	cout<<intStack.top()<<endl;
}