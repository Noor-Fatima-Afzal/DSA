#include <iostream>
#include <stack>
using namespace std;

class queue{
	stack<int> stack1;
	stack<int> stack2;
	public:
		//1
		void enqueue(int x){
        	stack1.push(x);
    	}
    	//2
    	int dequeue(){
    		if(stack1.empty() && stack2.empty()){
    			cout<<"Queue is empty"<<endl;
    			return -1;
			}
			// Move elements from stack1 to stack2 if stack2 is empty
			if (stack2.empty()) {
	            while (!stack1.empty()) {
	                stack2.push(stack1.top());
	                stack1.pop();
	            }
	        }
	        int front = stack2.top();
	        stack2.pop();
	        return front;
		}
		//3
		bool isEmpty() {
	        return stack1.empty() && stack2.empty();
    	}
    	//4
	    int front(){
	    	if(stack1.empty() && stack2.empty()){
	    			cout<<"Queue is empty"<<endl;
	    			return -1;
				}
			if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            	}
        	}
			return stack2.top();
		}
    
};

int main(){
	queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout<< "Dequeued: "<< q.dequeue()<<endl; // Output: 1
    std::cout<< "Front: "<< q.front()<<endl; // Output: 2
    q.enqueue(4);
    std::cout << "Dequeued: "<< q.dequeue()<<endl; // Output: 2
}
