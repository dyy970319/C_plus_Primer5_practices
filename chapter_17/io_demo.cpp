#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	//cout<<unitbuf;
	cout<<showbase
		<<"hex and uppercase"<<hex<<uppercase<<100 * sqrt(2.0)<<dec<<nouppercase<<noshowbase<<endl;
	cout<<right<<hex<<uppercase<<showbase;
	cout<<setw(12)<<1.1<<endl;
	cout<<setw(12)<<2.3<<endl;
	cout<<setw(12)<<3.5<<endl;
	cout<<left<<dec<<nouppercase<<noshowbase;
	cout<<"default bool values: "<<true<<" "<<false
		<<"\nalpha bool values: "<<boolalpha<<true
		<<" "<<false<<endl<<noboolalpha;
	
	cout<<showbase;
	cout<<"\ndefault: "<<20<<" "<<1024<<endl;
	cout<<"in octal: "<<oct<<20<<" "<<1024<<endl;
	cout<<"in hex: "<<hex<<100.2<<" "<<1024<<endl;
	cout<<"in decimal: "<<dec<<20<<" "<<1024<<endl;
	cout<<noshowbase;
	
	cout<<showpoint;
	cout<<"\nshowpoint:"<<10.0<<noshowpoint<<endl;
	
	cout<<showpos;
	cout<<"\nshowpos:"<<1<<noshowpos<<endl;
	
	cout<<uppercase<<showbase;
	cout<<"\nuppercase in hex:"<<hex<<20<<" "<<1024<<endl;
	cout<<dec<<nouppercase<<noshowbase;
	
	int i = -16;
	double d = 3.14159;
	cout<<"\ni: "<<setw(12)<<i<<"next col"<<'\n'
		<<"d: "<<setw(12)<<d<<"next col"<<'\n';
	cout<<left
		<<"i: "<<setw(12)<<i<<"next col"<<'\n'
		<<"d: "<<setw(12)<<d<<"next col"<<'\n';
	cout<<right
		<<"i: "<<setw(12)<<i<<"next col"<<'\n'
		<<"d: "<<setw(12)<<d<<"next col"<<'\n';
	cout<<internal
		<<"i: "<<setw(12)<<i<<"next col"<<'\n'
		<<"d: "<<setw(12)<<d<<"next col"<<'\n';
	cout<<setfill('#')
		<<"i: "<<setw(12)<<i<<"next col"<<'\n'
		<<"d: "<<setw(12)<<d<<"next col"<<'\n'
		<<setfill(' ');
		
	cout<<showbase<<"\ndefault format: "<<100 * sqrt(2.0)<<'\n'
		<<"scientific: "<<scientific<<100 * sqrt(2.0)<<'\n'
		<<"fixed decimal: "<<fixed<<100 * sqrt(2.0)<<'\n'
		<<"hexadecimal: "<<hexfloat<<100 * sqrt(2.0)<<'\n'
		<<"use defaults: "<<defaultfloat<<100 * sqrt(2.0)<<"\n\n"
		<<"hex and uppercase"<<hex<<uppercase<<100 * sqrt(2.0)<<dec<<nouppercase<<noshowbase<<endl;
	
	cout<<"\nPrecision: "<<cout.precision()
		<<", Value: "<<sqrt(2.0)<<endl;
	cout.precision(12);
	cout<<"\nPrecision: "<<cout.precision()
		<<", Value: "<<sqrt(2.0)<<endl;
	cout<<setprecision(3);
	cout<<"\nPrecision: "<<cout.precision()
		<<", Value: "<<sqrt(2.0)<<endl;

	cout<<setbase(8)<<100<<endl;
		
	cin>>noskipws;
	char ch;
	while(cin>>ch)
		cout<<ch;
	cin>>skipws;
}