#include <vector>
#include <initializer_list>
#include <string>
#include <memory>

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
		size_type size() const {return data->size();}
		bool empty() const { return data -> empty();}
		//��Ӻ�ɾ��Ԫ��
		void push_back(const string &t){data -> push_back(t);}
		void pop_back();
		//Ԫ�ط���
		string& front();
		string& front () const;
		string& back();
		string& back() const;
		StrBlobPtr begin();
		StrBlobPtr end();
	private:
		shared_ptr<vector<string>> data;
		//���data[i]���Ϸ����׳�һ���쳣
		void check(size_type i,const string &msg)const;
	//StrBlobPtr begin();
	//StrBlobPtr end();
	/*ConstStrBlobPtr begin();
	ConstStrBlobPtr end();*/
};