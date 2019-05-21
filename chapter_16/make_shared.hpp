#include <memory>

using namespace std;

template<typename T,typename... Args>
shared_ptr<T> make_shared(Args&&... args){
	T t(std::forward<T>(args)...);
	return shared_ptr<T>(t);
}