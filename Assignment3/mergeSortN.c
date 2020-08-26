#include <stdio.h>
#include <stdlib.h>
#include<time.h>


void merge(long int *arr, long int s, long int e){
	long int mid = (s+e)/2;
	
	long int i = s; 			//Start of subarray1
	long int j = mid+1;		//Start of subarray2
	long int k = s;			//Start of temp array
	
	long int temp[190000];
	while(i<=mid && j<=e){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		} else
		{
			temp[k++] = arr[j++];
		}
	}
	
	while(i <= mid){
		temp[k++] = arr[i++];
	}
	
	while(j <= e){
		temp[k++] = arr[j++];
	}
	
	//copy all elements to original array
	for(long int i = s; i<=e; i++){
		arr[i] = temp[i];
	}
}

void mergeSort(long int arr[],long int i, long int j){
	if(i != j){
		long int mid = (i+j)/2;
		mergeSort(arr, i, mid);
		mergeSort(arr, mid+1, j);
		merge(arr, i, j);
	}
}

int main(){
	clock_t start, end; 
	long int arraySize = 190000;
	long int arr[arraySize];
	
	for(long int i=0; i < arraySize ; i++){
		arr[i] = rand();
	}
	
	start = clock(); 
		mergeSort(arr, 0, arraySize-1);
	end = clock(); 
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//print SOrted elements
//	for(long int i=0; i < arraySize ; i++){
//		printf("%d ",arr[i]);
//	}
	
	printf("\n--------------------------------------------\n");
	printf("Time: %0.8f",time_taken);
	printf(" sec");
	
	return 0;
}
