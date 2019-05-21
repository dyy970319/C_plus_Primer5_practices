
template <typename T,typename D>
class unique_ptr_dyy{
	public:
		unique_ptr_dyy(unique_ptr_dyy<T> *ptr):p(ptr->p){
			
		}
		~unique_ptr_dyy(){
			del(p);
		}
	private:
		T *p;
		D del;
		
};