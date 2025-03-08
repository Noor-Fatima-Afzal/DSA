#include <iostream>
using namespace std;

#define n 10

class queue{
	public:
		int* arr;
		int top;
		int back;
		 queue(){
		 	arr=new int[n];
		 	top=-1;
		 	back=-1;
		 }
		void push(int x){
			if(back==n-1){
				cout<<"overflow"<<endl;
				return;
			}
			back++;
			arr[back]=x;
			
			if(top==-1){
				top++; //we are removing from top (i mean first in, first out)
			}
		}
		void pop(){
			if(top==-1 || top>back){
				cout<<"No elements present"<<endl;
				return;
			}
			top++;
		}
		int peak(){
			if(top==-1 || top>back){
				cout<<"No elements present"<<endl;
				return -1;
			}
			return arr[top];
		}
		bool empty(){
			if(top==-1 || top>back){
				cout<<"No elements present"<<endl;
				return true;
			}
			return false;
		}
};

int main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	cout<<q.peak()<<endl;
}
