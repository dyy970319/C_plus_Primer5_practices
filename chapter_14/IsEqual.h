
class IsEqual{
	public:
		bool operator()(auto formal_para_1,auto formal_para_2)const
		{
			if(formal_para_1 == formal_para_2)
				return true;
			else
				return false;
		}
};