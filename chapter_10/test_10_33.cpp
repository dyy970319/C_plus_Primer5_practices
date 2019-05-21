#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
	ifstream infile("input.txt");
	istream_iterator<int> inFile(infile),eof;
	ofstream outfile1("output1.txt"),outfile2("output2.txt");
	ostream_iterator<int> outFile1(outfile1," "),outFile2(outfile2,"\n");
	while(inFile != eof)
	{
		if(*inFile % 2 == 0)
			outFile1= *inFile;
		else
			outFile2= *inFile;
		++inFile;
	}
}