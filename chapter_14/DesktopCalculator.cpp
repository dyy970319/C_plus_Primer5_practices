#include <map>
#include <functional>
#include <string>

using namespace std

int main()
{
	map<string,function<int(int,int)>>binops;
	binops["+"] = [][int i,int j]{
		return i+j;
	}
	binops["-"] = [][int i,int j]{
		return i-j;
	}
	binops["/"] = [][int i,int j]{
		return i/j;
	}
	binops["*"] = [][int i,int j]{
		return i*j;
	}
	binops["%"] = [][int i,int j]{
		return i%j;
	}
	
}