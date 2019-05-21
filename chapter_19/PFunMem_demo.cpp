#include <string>

class Screen{
	public:
		typedef std::string::size_type pos;
		char get_cursor() const {return contents[cursor];}
		char get() const{}
		char get(pos ht,pos wd)const{}
		Screen& home(){}
		Screen& forward(){}
		Screen& back(){}
		Screen& up(){}
		Screen& down(){}
		using Action = Screen& (Screen::*)();
		enum Directions{HOME,FORWARD,BACK,UP,DOWN};
		Screen& move(Directions);
		
		using pGet = char (Screen::*)();
		using pGet2 = char (Screen::*)(pos,pos);
		
	private:
		static Action Menu[];
		std::string contents;
		pos cursor;
		pos height,width;
};

Screen::Action Screen::Menu[] = {&Screen::home,
	&Screen::forward,&Screen::back,&Screen::up,&Screen::down};

int main(){
	
}