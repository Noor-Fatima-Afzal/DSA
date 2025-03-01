#include <iostream>
using namespace std;

void OutplaceInsertionSort(int A[], int B[], int n){
	for(int i=0; i<n; i++){
		int key=A[i];
		int j=i-1;
	while(j>=0 && B[j]>key){
		B[j+1]=B[j];
		j--;
	}
	B[j+1]=key;
	}
}
bool isSorted(int A[], int n){
	for(int i=0; i<n-1; i++){
		if(A[i]>A[i+1]){
			return false;
		}
	}
	return true;
}

int main(){
	int A[]={5,3,5,1,9,4};
	int n=6;
    int B[n];
    
    OutplaceInsertionSort(A,B,n);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
    
    if (isSorted(B, n)) {
        cout << "The array is sorted correctly." << endl;
    } else {
        cout << "Sorting failed." << endl;
    }
}
