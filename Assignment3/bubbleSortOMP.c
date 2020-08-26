#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void swap(int *num1,int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(){
	int arraySize = 32767;
	int  arr[arraySize];
	
	//Random numbers generation
	for(int i=0; i < arraySize; i++){
		arr[i] = rand();
	}
	//Array without Sorting
//	for(int i=0; i < arraySize; i++){
//		printf("%d ", arr[i]); 
//	}
	
	double start,end;
	start=omp_get_wtime();
	
	#pragma omp parallel for default(none),shared(arr,arraySize)
	for(int i=0;i < arraySize; i++){
		
		for(int j=0; j < arraySize-i-1; j++){
			
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	end=omp_get_wtime();
	
	//array after sorting
//	printf("\n Sorted array: \n");
//	for(int i=0; i < arraySize; i++){
//		printf("%d ", arr[i]); 
//	}
	
	printf("\n------------------------------\n Time Parallel= %f",(end-start));
	printf(" sec");
	
	return 0;
}




