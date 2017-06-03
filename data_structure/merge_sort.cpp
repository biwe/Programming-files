/*
 * merge_sort.cpp
 * this is just a excise program.it is a ascending sort.
 * input: an integer array
 * output: sorted array
 *
 * Created on: June 2, 2017
 * Author: bv_user
 */

#include <iostream>
using namespace std;

void merge(int* arr, int beg, int mid, int end){
	// put a large number at the tailer
	int* left = new int[mid-beg+1+1];// extra allocate a space
	int* right = new int[end-mid+1];
	for(int i=beg;i< mid+1; i++)
		left[i-beg] = arr[i];
	left[mid-beg+1] = 100000;

	for(int i=mid+1;i< end+1; i++)
		right[i-mid-1] = arr[i];
	right[end-mid] = 100000;

	int m=0, n=0;
	for(int i=beg; i<end+1; i++){
		if(left[m]<right[n])
			arr[i] = left[m++];
		else
			arr[i] = right[n++];
	}
	delete [] left;
	delete [] right;
}
// duplicate data in merge function, just remember .......
void merge_sort(int* arr, int beg, int end){
	if(beg >= end) // forget once, ensure back condition
		return;
	int mid = (beg+end)/2;
	merge_sort(arr, beg, mid);
	merge_sort(arr, mid+1, end);
	merge(arr, beg, mid, end);
}

int main(){
	int arr[] = {12, 23, 1, 25, 5, 8, 4, 10, 65, 0, 1, 5};
	int num = sizeof(arr)/sizeof(int);
	cout << num << endl;
	merge_sort(arr, 0, num-1);
	for(int i=0; i<num; i++)
		cout<< arr[i] << '\t';
	return 0;
}

