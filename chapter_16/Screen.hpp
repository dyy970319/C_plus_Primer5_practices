#include <iostream>

using namespace std;

template <unsigned w,unsigned h> class Screen;
template<unsigned w,unsigned h> std::ostream &operator<<
		(ostream &,const Screen<w,h>&);
template<unsigned w,unsigned h>std::istream &operator>>
		(istream &,Screen<w,h>&);

template <unsigned w,unsigned h> class Screen {
	 friend std::ostream &operator<< <w,h>
		(ostream &,const Screen<w,h>&);
	friend std::istream &operator>> <w,h>
		(istream &,Screen<w,h>&);
	public:
		Screen();
		~Screen();		
	private:
		int width = w,height = h;
};

template<unsigned w,unsigned h> 
	std::ostream &operator<<(ostream &os,const Screen<w,h>&s){
	os<<"width:"<<s.width<<",height"<<s.height;
}

template<unsigned w,unsigned h>
	std::istream &operator>>(istream &is,Screen<w,h>&s){
	is>>s.width>>s.height;
}