/*
 * Quicksort.cpp
 * this is just a excise program.it is a ascending sort.
 * input: an integer array
 * output: sorted array
 *
 * Created on: June 3, 2017
 * Author: bv_user
 */

#include <iostream>
using namespace std;

void quicksort(int* arr, int beg, int end){
	if(beg>=end)
		return;
	int pivot = arr[beg];
	int low = beg, high = end;

	while(low < high){
		// ****check low < high at any time*****
		while(arr[high] >= pivot && low < high)
			high--;
		arr[low] = arr[high];

		while(arr[low] < pivot && low < high)
			low++;
		arr[high] = arr[low];
	}
	// pivot position is changeable, must keep this
	arr[low] = pivot;

	quicksort(arr, beg, low-1);//keep subtract one number
	quicksort(arr, low+1, end);


}

int main(){
	int arr[] = {12, 23, 1, 25, 5, 8, 4, 10, 65, 0, 1, 5};
	int num = sizeof(arr)/sizeof(int);
	cout << num << endl;
	quicksort(arr, 0, num-1);
	for(int i=0; i<num; i++)
		cout<< arr[i] << '\t';
	return 0;
}

