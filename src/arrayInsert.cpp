#include<iostream>
using namespace std;

void arrayInsert(){

    int arr[100];
    int n;
    cout<<"enter no of elements : "; cin >>n;
    if(n<100 && n >=0){
        for(int i = 0; i<n; ++i){
            printf("[%d]-> ", i+1); cin>>arr[i];
        }
    }
    int data, idx, temp, flag = 0;
    cout<<"\nwhat to insert ? : "; cin>>data;
    cout<<"\nwhere to insert ? : "; cin>>idx;
    if(n<100 && idx<100 && idx >=0){
        cout<<endl<<endl;
        for(int i = n-1; i>=idx; --i){
            arr[i+1] = arr[i];
        }
        arr[idx] = data;
        ++n;
        for( int i = 0; i<n; ++i) cout<<arr[i]<<", ";

    }
    else cout<<"array is full.";
    cout<<endl;

}