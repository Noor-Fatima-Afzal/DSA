#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
	queue<int> q;
	// Push operation (Costly)
    void push(int x){
        int size = q.size();
        q.push(x);  // Push the element

        // Rotate the queue to make the last pushed element the front element
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow"<<endl;
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty"<<endl;
            return -1;
        }
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
int main(){
	Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element after pop: "<<s.top()<<endl;

    s.pop();
    s.pop();
    s.pop();  // Stack Underflow
}
