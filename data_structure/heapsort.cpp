/*
 * Heapsort.cpp
 * this is just a excise program.it is a ascending sort.
 * input: an integer array
 * output: sorted array
 *
 * Created on: June 4, 2017
 * Author: bv_user
 */

#include <iostream>
using namespace std;

#define left_child(i)	(i<<1)+1
#define right_child(i)	(i<<1)+2

void exchange(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maintain_heap(int *arr, int num, int key){
	if(left_child(key) > num)
		return;
	if(right_child(key) > num){//only has left child
		if(arr[key] < arr[left_child(key)])
			exchange(&arr[key], &arr[left_child(key)]);
		return;
	}

	// just compare the value of left and right
	if(arr[left_child(key)] < arr[right_child(key)]){
		if(arr[key] < arr[right_child(key)]){
			exchange(&arr[key], &arr[right_child(key)]);
			key = right_child(key);
			maintain_heap(arr, num, key);
		}
	}// this { } is important avoid "else" confused
	else{
		if(arr[key] < arr[left_child(key)]){
			exchange(&arr[key], &arr[left_child(key)]);
			key = left_child(key);
			maintain_heap(arr, num, key);
		}
	}

}

void buildheap(int* arr, int num){
	for(int i=(num-1)/2; i>=0; i--){
		maintain_heap(arr, num, i);
	}
}

void heapsort(int* heap_arr, int num){
	for(int i=num; i>0; i--){
		exchange(&heap_arr[0], &heap_arr[i]);
		maintain_heap(heap_arr, i-1, 0); // caution this ......
	}
}

int main(){
	int arr[] = {12, 23, 1, 25, 5, 8, 4, 10, 65, 0, 1, 5};
	int num = sizeof(arr)/sizeof(int);
	cout << num << endl;
	buildheap(arr, num-1);
	heapsort(arr, num-1);
	for(int i=0; i<num; i++)
		cout<< arr[i] << '\t';
	return 0;
}

