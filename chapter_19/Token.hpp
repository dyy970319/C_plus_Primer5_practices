#include <string>

using std::string;

class Sales_data{
	
};

class Token{
	public:
		Token():tok(INT),ival(0){}
		Token(const Token &t):tok(t.tok){copyUnion(t);}\
		Token(Token &&t) noexcept{
			switch(t.tok){
				case INT:
					ival = t.ival;
					break;
				case CHAR:
					cval = t.cval;
					break;
				case DBL:
					dval = t.dval;
					break;
				case STR:
					sval = t.sval;
					break;
				case SALESDATA:
					sdval = t.sdval;
					break;
				t.~Token();
			}
		}
		Token &operator =(Token &&t)noexcept;
		Token &operator=(const Token&);
		~Token(){if(tok==STR) sval.~string();}
		Token &operator=(const string &);
		Token &operator=(char);
		Token &operator=(int);
		Token &operator=(double);
	private:
		enum {INT,CHAR,DBL,STR,SALESDATA}tok;\
		union{
			char cval;
			int ival;
			double dval;
			string sval;
			Sales_data sdval;
		};
		void copyUnion(const Token &);
};

Token &Token::operator=(const string &s){
	sval = s;
	tok = STR;
	return *this;
}

Token &Token::operator=(double i){
	if(tok == STR) sval.~string();
	dval = i;
	tok = DBL;
	return *this;
}

Token &Token::operator=(int i){
	if(tok == STR) sval.~string();
	ival = i;
	tok = INT;
	return *this;
}

Token &Token::operator=(char c){
	if(tok == STR) sval.~string();
	cval = c;
	tok = CHAR;
	return *this;
}

Token &Token::operator =(Token &&t)noexcept{
	if(this != &t){
		this->~Token();
		switch(t.tok){
			case INT:
				ival = t.ival;
				break;
			case CHAR:
				cval = t.cval;
				break;
			case DBL:
				dval = t.dval;
				break;
			case STR:
				sval = t.sval;
				break;
			case SALESDATA:
				sdval = t.sdval;
				break;
			t.~Token();
		}
	}
	return *this;
}

void Token::copyUnion(const Token &t){
	switch(t.tok){
		case INT:
			ival = t.ival;
			break;
		case CHAR:
			cval = t.cval;
			break;
		case DBL:
			dval = t.dval;
			break;
		case STR:
			new(&sval) string(t.sval);
			break;
		case SALESDATA:
			sdval = t.sdval;
			break;
	}
}

Token &Token::operator=(const Token&t){
	if(tok == STR && t.tok !=STR)sval.~string();
	if(tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
	
}