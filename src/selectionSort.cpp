#include "utils.cpp"

#include<iostream>
using namespace std;

template<class T>
void selectionSort(T arr[],int len, bool desc = false){
    int idx = len-1;
    for(int i = 0; i<len; ++i){
        int current = 0;
        for(int j = 0; j <= idx; ++j){
                current = (!desc)?
                (arr[current]<arr[j]?j:current)
                :(arr[current]>arr[j]?j:current);
        }
        swap_them<T>(arr[current], arr[idx]);
        --idx;
    }
}

void selectionSort_demo(){
    int arr[] = {9, 8, 7, 16, 5, 4, 3, 2, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    display<int>(arr, len);
    selectionSort<int>(arr, len);
    display<int>(arr, len);
    selectionSort<int>(arr, len, true);
    display<int>(arr, len);
}
