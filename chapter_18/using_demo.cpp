namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//using namespace Exercise;
//using  Exercise::limit;
//using  Exercise::ivar;
void manip(){
	using namespace Exercise;
	//using  Exercise::limit;
	//using  Exercise::ivar;
	double dvar = 3.1416;
	int iobjc = limit + 1;
	++ivar;
	++::ivar;
}

int main(){
	//limit ++;
}