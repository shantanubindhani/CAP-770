#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include "utils.cpp"

#include<iostream>
using namespace std;

template<class T>
int partitionArray(T input[], int start, int end, bool desc = false) {
	int pivot = start;
	while(start < end){
		swap_them(input[start], input[end]);
		if(desc){
			while (input[start] >= input[pivot])
				++start;
			while (input[end] < input[pivot])
				--end;
		}
		else{
			while (input[start] <= input[pivot])
				++start;
			while (input[end] > input[pivot])
				--end;
		}
		
    }
	swap_them(input[pivot], input[end]);
	return end;

}

// args : arr[], start_index, end_index, descending(true/false)
template<class T>
void quickSort(T input[], int start, int end, bool desc = false) {
	if (start < end) {
		int sorted_idx = partitionArray<T>(input, start, end, desc);
		quickSort<T>(input, start, sorted_idx - 1, desc);
		quickSort<T>(input, sorted_idx + 1, end, desc);
	}
}


void quickSort_demo(){
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int len = sizeof(arr)/sizeof(arr[0]);
	display<int>(arr, len);
	quickSort<int>(arr,0, len-1);
	display<int>(arr, len);
	quickSort<int>(arr,0, len-1, true);
	display<int>(arr, len);
}

#endif