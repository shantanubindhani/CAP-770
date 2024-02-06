#include<iostream>
using namespace std;

int binarySearch(int arr[],int target, int head, int tail);

int main(){
    int n; cin>>n;
    int *nums = new int[n];
    for(int i = 0; i<n; ++i) cin>>nums[i];
    for(int i = 0; i<n; ++i) cout<<nums[i]<<" "; cout<<endl;
    int target; cin>>target;
    int res = binarySearch(nums, target, 0, n-1);
    if(res == -1) cout<<"Not Found.";
    else cout<<"Found at : "<<res<<endl;

    return 0;

}

int binarySearch(int arr[],int target, int head, int tail){
    int mid = head + (tail-head)/2;
    // cout<<head<<" "<<mid<<" "<<tail<<endl;
    if(target < arr[mid]) return binarySearch(arr, target, head, mid-1);
    if(target > arr[mid]) return binarySearch(arr, target, mid+1, tail);
    if(arr[mid] == target) return mid;
    return -1;
}
