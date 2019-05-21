//#include "StrBlobPtr.cpp"
#include "ConstStrBlobPtr.cpp"
#include <iostream>
#include <sstream>

int main()
{
	//istream line;
	string line;
	string word;
	ifstream infile("input.txt");
	StrBlob str_blob;
	while(getline(infile,line)){
		istringstream is_str(line);
		while(is_str >> word)
			str_blob.push_back(word);
	}
	const StrBlob const_str_blob(str_blob);
	ConstStrBlobPtr str_blob_ptr(const_str_blob);
	while(str_blob_ptr.deref() != str_blob.back()){
		cout<<str_blob_ptr.deref()<<endl;
		str_blob_ptr.incr();
	}
	cout<<str_blob_ptr.deref()<<endl;
	return 0;
}