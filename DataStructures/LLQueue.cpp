#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	
	node(int val){
		data=val;
		next=NULL;
	}
};

class queue{
	node* front;
	node* back;
	public:
	queue(){
		front=NULL;
		back=NULL;
	}
	void push(int x){
		node* n=new node(x);
		if(front==NULL){
			back=n;
			front=n;
			return;
		}
		back->next=n;
		back=n;
	}
	void pop(){
		if(front==NULL){
			cout<<"Queue Underflow"<<endl;
			return;
		}
		node* todelete=front;
		front=front->next;
		
		delete todelete;
	}
	int peak(){
		if(front==NULL){
			cout<<"NO Value"<<endl;
			return -1;
		}
		return front->data;
	}
	bool empty(){
		if(front==NULL){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.peak()<<endl;
	q.pop();
	cout<<q.peak()<<endl;
	
}
