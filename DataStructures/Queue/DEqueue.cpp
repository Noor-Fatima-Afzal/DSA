#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	node(int val){
		data=val;
		next=NULL;
		prev=NULL;
	}
};

class DEqueue{
	public:
	node* front;
	node* rear;
	int count;
	DEqueue(){
		front=NULL;
		rear=NULL;
		count=0;
	}
	void push_front(int val){
		node* newNode=new node(val);
		if(empty()){
			front=rear=newNode;
		}
		else{
			newNode->next=front;
			front->prev=newNode;
			front=newNode;
		}
		count++;
	}
	void push_back(int val){
		node* newNode=new node(val);
		if(empty()){
			front=rear=newNode;
		}
		else{
			newNode->prev=rear;
			rear->next=newNode;
			rear=newNode;
		}
		count++;
	}
	void pop_front(){
		if(empty()){
			cout<<"empty"<<endl;
			return;
		}
		node* temp=front;
		front=front->next;
		if(front){
			front->prev=NULL;
		}
		else{
			rear=NULL;
		}
		delete temp;
		count--;
	}
	void pop_back(){
		if(empty()){
			cout<<"empty"<<endl;
			return;
		}
		node* temp=rear;
		rear=rear->prev;
		if(rear){
			rear->next=NULL;
		}
		else{
			front=NULL;
		}
		delete temp;
		count--;
	}
	int getfront(){
		if(empty()){
			cout<<"empty"<<endl;
			return -1;
		}
		return front->data;
	}
	int getrear(){
		if(empty()){
			cout<<"empty"<<endl;
			return -1;
		}
		return rear->data;
	}
	int at(int index){
		if(index<0 || index>count){
			cout<<"out of range"<<endl;
			return -1;
		}
		node* temp=front;
		for(int i=0; i<index; i++){
			temp=temp->next;
		}
		return temp->data;
	}
	int size(){
		return count;
	}
	bool empty(){
		return count==0;
	}
	void display(){
		node* temp=front;
		cout<<"DEqueue is: ";
		while(temp){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(){
	DEqueue dq;
	
	dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);
    dq.push_front(1);
    
    dq.display();
}
