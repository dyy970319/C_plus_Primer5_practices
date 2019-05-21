#include <set>

using namespace std;

class Message;

class Folder{
	public:
		void addMsg(Message *m)
		{
			messages.insert(m);
		}
		void remMsg(Message *m)
		{
			messages.erase(m);
		}
	private:
		set<Message*> messages;
	
};