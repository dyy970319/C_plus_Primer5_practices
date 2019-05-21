#include <iostream>
#include <string>

using namespace std;

struct Sales_data{
	double book_number;
	float price;
	int count;
	string name;
	
	};

int main()
{
	Sales_data items[10];
	int count = 3;
	for(int i = 0;i < count;i++){
		cin>>items[i].name>>items[i].count>>items[i].price;
	}
	for(int i = 0;i< count;i++){
		cout<<items[i].name<<items[i].count<<items[i].price<<endl;
		}
	string first_name = items[0].name;
	int total_count = items[0].count;
	float total_price = items[0].count*items[0].price;
	//for(int i = 1;i< count;i++){
		//if(items[i].name != first_name)
		//	break;
		//else{
	//		total_count += items[i].count;
	//		total_price += items[1].count*items[1].price;
	//		}
	//}
	//cout<<first_name<<" "<<total_count<<" "<<total_price<<" "<<total_price/total_count<<endl;
	
	for(int i = 1;i < count;i++){
		if(items[i].name == first_name){
			total_count += items[i].count;
		}else{
			cout<<first_name<<" "<<total_count<<endl;
			first_name = items[i].name;
			total_count = items[i].count;
		}
	}
	cout<<first_name<<" "<<total_count<<endl;
	
	
	//Sales_data zhang,zhou;
	//cin>>zhang.name>>zhang.count>>zhang.price;
	//cin>>zhou.name>>zhou.count>>zhou.price;
	//cout<<zhang.name<<zhang.count<<zhang.price<<endl;
	//cout<<zhou.name<<zhou.count<<zhou.price<<endl;
	//cout<<zhang.name<<zhang.count+zhou.count<<endl;
	
	return 0;
}					