#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void f1(vector<int> &aim){
	for(auto p=aim.begin();p!=aim.end();p++){
		if(*p%2==0){
			aim.erase(p);
			p--;
		}
	}
}
void f2(vector<int> &aim){
	for(auto p=aim.begin();p!=aim.end();p++){
		if(*p>53){
			aim.erase(p);
			p--;//由于删除了一个元素，不知为何这里似乎p会移向下一个元素？所以自减退回上一个 
		}
	}
}
void f3(vector<int> &aim,vector<int> prim){
	for(auto p=aim.begin();p!=aim.end();p++){
		for(auto pri:prim){
			if(*p-2==pri){
				aim.erase(p);
				p--;
			}
		}
	}
}
bool assist_function(vector<int> &aim,int tp){
	int count=0;
	for(int i=2;i<sqrt(tp);i++){
		if(tp%i==0){
			for(auto p:aim){
				if(p==i+tp/i){
					count++;
					break;
				}
			}
		}
	}
	if(count==1){
		return true;
	}else{
		return false;
	}
}//辅助函数，用于判断p分解形式是否能够满足条件2。 
void f4(vector<int> &aim){
	int temp_product;
	int temp_sum;
	for(auto p:aim){
		cout<<p<<": ";
		for(int i=2;i<p/2;i++){
			temp_product=i*(p-i);
			if(assist_function(aim,temp_product)){
				cout<<"( "<<i<<", "<<p-i<<" )   ";
			}
		}
		cout<<endl;
	}
}//此函数用于展示符合条件2的分解方式 
int main(){
	vector<int> aim_A;
	vector<int> aim_B;
	vector<int> prime_nums;
	//制作质数表（2~99）
	for(int i=2;i<100;i++){
		for(int j=2;j<=i;j++){
			if(i%j==0&&i!=j){
				break;
			}else if(i==j){
				prime_nums.push_back(i);
			}
		}
	}
	//先把5~197送入A的可能值中。 
	for(int i=5;i<=197;i++)
	aim_A.push_back(i);
	//接着运行各种判断条件的函数来删除不符合条件的值
	f1(aim_A);
	f2(aim_A);
	f3(aim_A,prime_nums);
	cout<<"C"<<endl;
	for(auto p:aim_A)
	cout<<p<<endl;
	cout<<endl;
	f4(aim_A);
}
