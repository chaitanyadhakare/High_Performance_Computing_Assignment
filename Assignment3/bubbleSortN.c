#include<stdio.h>
#include<time.h>

void swap(int *num1,int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(){
	clock_t start, end; 
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
	
	start = clock(); 
	for(int i=0;i < arraySize; i++){
		
		for(int j=0; j < arraySize-i-1; j++){
			
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	end = clock(); 
	double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//array after sorting
//	printf("\n Sorted array: \n");
//	for(int i=0; i < arraySize; i++){
//		printf("%d ", arr[i]); 
//	}
	
	printf("\n--------------------------------------------\n");
	printf("Time: %0.8f",time_taken);
	printf(" sec");
	
	return 0;
}




