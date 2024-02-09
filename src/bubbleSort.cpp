#include<iostream>
using namespace std;

template<class T>
void swap_them(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void bubbleSort(T arr[], int size, bool desc = false){
    if(size == 0) return;
    if(size < 0) cout<<"[ERROR] : Invalid Size!."<<endl;
    for(int i = 0; i<size-1; ++i){
        if(!desc){
            if(arr[i] > arr[i+1]) swap_them<T>(arr[i], arr[i+1]);
        }
        else{
            if(arr[i] < arr[i+1]) swap_them<T>(arr[i], arr[i+1]);

        }
        bubbleSort<T>(arr, size-1, desc);
    }
}

template<class T>
void display(T arr[], int size){
    cout<<"[";
    for(int i = 0; i<size-1; ++i) cout<<arr[i]<<", ";
    cout<<arr[size-1]<<"]  size :"<<size<<endl;
}

int main(int argc, char* argv[]){
    string s = "demo";
    if((argv[1]==s)){
        int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        int len = sizeof(arr)/sizeof(arr[0]);
        display<int>(arr, len);
        bubbleSort<int>(arr, len);
        display<int>(arr, len);
        bubbleSort<int>(arr, len, true);
        display<int>(arr, len);
    }
    return 0;
}