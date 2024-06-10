#include<iostream>
using namespace std;

void bubble(float a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                float tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
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
    bubble(a, n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
