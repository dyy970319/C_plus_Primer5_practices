#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	/*unsigned aCnt = 0,eCnt = 0,iCnt = 0,oCnt = 0,uCnt = 0;
	unsigned spaceCnt = 0,tableCnt = 0,lineCnt = 0;
	unsigned ffCnt = 0,flCnt =0,fiCnt = 0;
	char ch;
	char ch2;
	while(cin>>ch){
		if(ch == 'a'|| ch == 'A')
			++aCnt;
		else if (ch == 'e'|| ch == 'E')
			++eCnt;
		else if (ch == 'i'|| ch == 'I')
			++iCnt;
		else if (ch == 'o'|| ch == 'O')
			++oCnt;
		else if (ch == 'u'|| ch == 'U')
			++uCnt;
		else if (ch == '\0')
			++spaceCnt;
		else if (ch == '\t')
			++tableCnt;
		else if (ch == '\n')
			++lineCnt;
		else if (ch == 'f'){
			cin>>ch2;
			if (ch2 == 'f')
				ffCnt++;
			}
		else if (ch == 'f'){
			cin>>ch2;
			if (ch2 == 'l')
				flCnt++;
			}
		else if (ch == 'f'){
			cin>>ch2;
			if (ch2 == 'i')
				fiCnt++;
			}
	}
	cout<<aCnt<<eCnt<<iCnt<<oCnt<<uCnt<<endl;
	cout<<spaceCnt<<tableCnt<<lineCnt<<endl;
	cout<<ffCnt<<flCnt<<fiCnt<<endl;*/
	/*int i = 0;
	switch(i){
		case 1:
			break;
		default:
			cout<<sizeof(int)<<endl;
	}*/
	const unsigned ival = 512,jval = 1024,kval = 4096;
	unsigned bufsize;
	unsigned swt = 512;
	switch(swt){
		case ival:
			bufsize = ival * sizeof(int);
			break;
		case jval:
			bufsize = jval * sizeof(int);
			break;
		case kval:
			bufsize = kval * sizeof(int);
			break;
	}
}