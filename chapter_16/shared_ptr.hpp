
#include <iostream>

template <typename T>
class shared_ptr_dyy{
	public:
		shared_ptr_dyy() = default;
		shared_ptr_dyy(shared_ptr_dyy<T> *ptr):p(ptr->p){
			
		}
		shared_ptr_dyy(const shared_ptr_dyy<T> &ptr):p(ptr.p){
			
		}
		~shared_ptr_dyy(){
			std::cout<<"delete dyy"<<std::endl;
			//del?del(p):delete p;
			delete p;
		}
	private:
		T *p;
		//D *del;
};

template <typename T>
shared_ptr_dyy<T> make_shared_dyy(){
	return new shared_ptr_dyy<T>();
}
