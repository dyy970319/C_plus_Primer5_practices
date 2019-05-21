

class Base{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};

struct Pub_Derv:public Base{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};

struct Priv_Derv:private Base{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};

struct Prot_Derv:protected Base{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};

struct Derived_from_Public:public Pub_Derv{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};

struct Derived_from_Private:public Priv_Derv{
	public:
		/*void memfcn(Base &b){
			b = *this;
		}*/
};

struct Derived_from_Protected:public Prot_Derv{
	public:
		void memfcn(Base &b){
			b = *this;
		}
};


