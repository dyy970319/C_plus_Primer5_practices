#include <vector>
#include <initializer_list>
#include <string>
#include <memory>
#include "StrVec.cpp"

using namespace std;

class StrBlob;

class StrBlobPtr;
class StrBlob{
	friend class StrBlobPtr;
	//friend class ConstStrBlobPtr;
	public:
		typedef vector<string>::size_type size_type;
		StrBlob();
		StrBlob(initializer_list<string> il);
		StrBlob(const StrBlob& sb){
			auto temp_data = *sb.data;
			data = make_shared<StrVec>(temp_data);
		}
		StrBlob operator=(const StrBlob& sb){
			auto temp_data = *sb.data;
			data = make_shared<StrVec>(temp_data);
			return *this;
		}
		size_type size() const {return data->size();}
		bool empty() const { return data -> empty();}
		//添加和删除元素
		void push_back(const string &t){data -> push_back(t);}
		void push_back(string &&t){data -> push_back(std::move(t));}
		void pop_back();
		//元素访问
		string& front();
		string& front () const;
		string& back();
		string& back() const;
		StrBlobPtr begin();
		StrBlobPtr end();
	private:
		shared_ptr<StrVec> data ;//= make_shared<StrVec>();
		//如果data[i]不合法，抛出一个异常
		void check(size_type i,const string &msg)const;
	//StrBlobPtr begin();
	//StrBlobPtr end();
	/*ConstStrBlobPtr begin();
	ConstStrBlobPtr end();*/
};
