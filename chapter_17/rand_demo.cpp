#include <random>
#include <iostream>

using namespace std;

unsigned int random_uns_int(auto seed,auto min_value,auto max_value){
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(min_value,max_value);
	return u(e);
}

bool play(bool b)
{
	if(b) 
		return true;
	else
		return false;
}

int main()
{
	string resp;
	default_random_engine e;
	bernoulli_distribution b;
	do{
		bool first = b(e);
		cout << (first ? "We go first":"You get to go first")<<endl;
		cout<<((play(first))?"sorry,you lost":"congrats,you won")<<endl;
		cout<<"play again?Enter 'yes' or 'no'"<<endl;
	}while(cin>>resp && resp[0] == 'y');
}