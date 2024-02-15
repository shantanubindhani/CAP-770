#include<iostream>
#include<math.h>
using namespace std;

template<class T>
int jumpSearch(T arr[],int size, T target){
    int jump = sqrt(size);
    int i = 0;
    for(; i<size; i += jump){
        
        printf("Searching [%d](%d) and under...\n", i, arr[i]);
        
        if(arr[i] == target) return i;
        else if(target < arr[i]){
            for(int j = i-1; j>(i-jump); --j){
                if(arr[j] == target) return j;
            }
        }
    }
    for(; i<size; ++i){
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
        
        int res = jumpSearch<int>(nums, n, target);
        
        if(res == -1) cout<<"Not Found."<<endl;
        else cout<<"Found at : "<<res<<endl;
    }
    return 0;

}

