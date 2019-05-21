#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(){
	fstream inOut("copyOut.txt",fstream::ate | fstream::in | fstream::out);
	if(!inOut){
		cerr << "Unable to open file!"<<endl;
		return EXIT_FAILURE;
	}
	auto end_mark = inOut.tellg();
	inOut.seekg(0,fstream::beg);
	size_t cnt = 0;
	string line;
	//int w[] = {4,3,3,3};
	int first = 0;
	int second = 0;
	int third = 0;
	while(inOut && inOut.tellg() != end_mark && getline(inOut,line)){
		cout<<"line:"<<line<<endl;
		cnt += line.size() + 1;
		auto mark = inOut.tellg();
		inOut.seekp(0,fstream::end);
		inOut<<cnt;
		if(mark != end_mark) inOut << " ";
		inOut.seekg(mark);
		if(first == 0){
			cout<<"first"<<endl;
			inOut.seekg(-3,fstream::cur);
		}
		if(first ==1 && second == 1&&third ==0){
			cout<<"third"<<endl;
			inOut.seekg(-1,fstream::cur);
			third = 1;
		}
		if(first == 1 && second == 0){
			cout<<"second"<<endl;
			inOut.seekg(-2,fstream::cur);
			second = 1;
		}
		
		first = 1;
	}
	inOut.seekp(0,fstream::end);
	//inOut<<"\n";
	return 0;	
}