#include <iostream>
#include <stack>
using namespace std;

void reverseStackIterativeMethod(stack<int> &st){
	stack<int> tempstack;
	while(!st.empty()){
		tempstack.push(st.top());
		st.pop();
	}
	st=tempstack; 
}
void insertAtBottom(stack<int> &st, int ele){
	if(st.empty()){
		st.push(ele);
		return;
	}
	int topEle=st.top();
	st.pop();
	insertAtBottom(st,ele);
	st.push(topEle);
}
void reverseStackRecursiveMethod(stack<int> &st){
	
	if(st.empty()){
		return;
	}
	
	int ele=st.top();
	st.pop();
	reverseStackRecursiveMethod(st);
	insertAtBottom(st,ele);
}
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
	stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    cout << "Original Stack: ";
    printStack(st);

//    reverseStackIterativeMethod(st);
	reverseStackRecursiveMethod(st);

    cout << "Reversed Stack: ";
    printStack(st);
}
