#include <iostream>
using namespace std;
#include <stack>
#include <cmath> 

int prefixEvaluation(string s){
	stack<int> st;
	for(int i=s.length()-1; i>=0; i--){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			if(st.size()<2){
				return -1;
			}
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch (s[i]){
				case '+':
					st.push(op1+op2);
					break;
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case '/':
					if (op2 == 0) return -1;
					st.push(op1/op2);
					break;
				case '^':
					st.push(pow(op1,op2));
					break;
			}
		}
	}
	return st.top();
}

int main(){
	cout<<prefixEvaluation("-+7*45+20");
	
}
