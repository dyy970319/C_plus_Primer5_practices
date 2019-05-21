
using namespace std;

class IfThenElse{
	public:
		auto operator()(auto formal_para_1,auto formal_para_2,auto formal_para_3)
		{
			if(formal_para_1)
				return formal_para_2;
			else
				return formal_para_3;
		}
	private:
	
};
