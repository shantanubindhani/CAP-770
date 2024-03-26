#include<iostream>
#include<math.h>

void generatePrimeNumbers(){
    int n;
    std::cout<<" upper bound for finding all the prime numbers :> ";
    std::cin>>n;
    std::cout<<"\n ";
    int nums[n];
    for(int i = 0; i<n; ++i) nums[i] = i+1;
    nums[0] = 0;
    for(int i = 1; i<n;++i){
        
            if(nums[i]){
                for(int j = i+1; j < n; ++j){
                    if(nums[j]%nums[i] == 0) nums[j] = 0;
                }
               std::cout<<nums[i]<<", ";
            }
    }
    std::cout<<std::endl;
}