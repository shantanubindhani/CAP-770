#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int nums[n];
    for(int i = 0; i<n; ++i) nums[i] = i+1;
    nums[0] = 0;
    for(int i = 1; i<n; ++i){
        
            if(nums[i]){
                for(int j = i+1; j < n; ++j){
                    if(nums[j]%nums[i] == 0) nums[j] = 0;
                }
               cout<<nums[i];
            }
            else cout<<" - ";
            cout<<" ";
    }
    cout<<endl;
    return 0;
}