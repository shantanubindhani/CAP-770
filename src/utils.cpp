#ifndef UTILS_CPP
#define UTILS_CPP

template<class T>
void swap_them(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void display(T arr[], int size){
    cout<<"[";
    for(int i = 0; i<size-1; ++i) cout<<arr[i]<<", ";
    cout<<arr[size-1]<<"]  size :"<<size<<endl;
}

#endif