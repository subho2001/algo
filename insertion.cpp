#include<iostream>
using namespace std;

void insertion(float a[], int n){
    for(int j=1 ; j<n; j++){
        float key= a[j];
        int i= j-1;
        while(i>=0 && key<a[i]){
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] =key;
    }
}

int main(){
    cout<<"Enter array size : ";
    int n;
    cin>>n;
    float a[n];
    cout<<"Enter number : ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    insertion(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

