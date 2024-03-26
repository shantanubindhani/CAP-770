#include<iostream>
using namespace std;

void arrayRemove(){

    int arr[100];
    int n;
    cout<<"enter no of elements : "; cin >>n;
    if(n<100 && n >=0){
        for(int i = 0; i<n; ++i){
            printf("[%d]-> ",i+1); cin>>arr[i];
        }
    }
    int idx;
    cout<<"\nfrom where to remove ? : "; cin>>idx;
    if(n>0 && idx<100 && idx >=0){
        cout<<endl<<endl;
        for(int i = idx; i<n; ++i){
            arr[i] = arr[i+1];
        }
        --n;
        for( int i = 0; i<n; ++i) cout<<arr[i]<<", ";


    }
    else cout<<"array is empty.";
    cout<<endl;

}