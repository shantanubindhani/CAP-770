#include<iostream>
using namespace std;

template<class T>
int linearSearch(T arr[],int size, T target){
    for(int i = 0; i<size; ++i){
        if(arr[i] == target) return i;
    }
    return -1;
}

int main(int argc, char* argv[]){
    string s = "demo";
    if((argv[1] == s)){
        int n; 
        cout<<"How many ? : ";cin>>n;

        int *nums = new int[n];
        for(int i = 0; i<n; ++i) {cout<<"["<<i+1<<"]:";cin>>nums[i];}

        cout<<"\n[";
        for(int i = 0; i<n-1; ++i) cout<<nums[i]<<", ";
        cout<<nums[n-1]<<"]  size :"<<n<<endl;
        int target; 
        cout<<"What to search ? : ";cin>>target;
        
        int res = linearSearch<int>(nums, n, target);
        
        if(res == -1) cout<<"Not Found."<<endl;
        else cout<<"Found at : "<<res<<endl;
    }
    return 0;

}

