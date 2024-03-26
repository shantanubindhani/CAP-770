#ifndef BINARYSEARCH_CPP
#define BINARYSEARCH_CPP

#include<iostream>
using namespace std;

template<class T>
int binarySearch(T arr[],T target, int head, int tail){
    int mid = head + (tail-head)/2;
    // cout<<head<<" "<<mid<<" "<<tail<<endl;
    if(target < arr[mid]) return binarySearch<T>(arr, target, head, mid-1);
    if(target > arr[mid]) return binarySearch<T>(arr, target, mid+1, tail);
    if(arr[mid] == target) return mid;
    return -1;
}

void binarySearch_demo(){
    int n; 
    cout<<"How many ? : ";cin>>n;

    int *nums = new int[n];
    cout<<"[ONLY SORTED!]"<<endl;
    for(int i = 0; i<n; ++i) {cout<<"["<<i+1<<"]:";cin>>nums[i];}

    cout<<"[";
    for(int i = 0; i<n-1; ++i) cout<<nums[i]<<", ";
    cout<<nums[n-1]<<"]  size :"<<n<<endl;
    int target; 
    cout<<"What to search ? : ";cin>>target;
    
    int res = binarySearch<int>(nums, target, 0, n-1);
    
    if(res == -1) cout<<"Not Found.";
    else cout<<"Found at : "<<res<<endl;
}

#endif

