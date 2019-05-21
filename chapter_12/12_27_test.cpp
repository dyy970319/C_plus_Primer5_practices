
using namespace std;

class test1;

class test2{
	friend test1;
	public:
		int var3 = 1;
	private:
		int var1 = 1;
};

class test1{
	public:
		void test_void(){
			int var2 = var1;
		}
		//int var2 = var1;//this->var1;
};

int main()
{
	
}