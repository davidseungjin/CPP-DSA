#include<iostream>
#define MAX_SIZE 9
#define SWAP(x, y, temp)((temp)=(x), (x)=(y), (y)=(temp))


/*
 * divide two sublist from pivot
 * move everything less than pivot to left, grater than pivot to right
*/

int partition(int list[], int left, int right){
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];		// this mean pivot is far left index of the list

	do{		// repeat until low and high intersect
		do{	// if list[low] is less than pivot, increase low
			low++;		// low starts at left+1
		}while(low <= right && list[low] < pivot);
		
		do{	// if list[high] is greater than pivot, decrease high
			high--;		// high starts at right
		}while(high >= left && list[high] > pivot);

		if(low < high){		// exchange list[low] and list[high] unless these doesn't intersect
			SWAP(list[low], list[high], temp);
		}
	}while(low< high);

	// if low and high intersect, exit the loop above and exchange list[left] and list[high].

	SWAP(list[left], list[high], temp);

	// return the index of pivot, which is high

	return high;
}

void quick_sort(int list[], int left, int right){
	if(left<right){
		int q = partition(list, left, right);
		quick_sort(list, left, q-1);
		quick_sort(list, q+1, right);
	}
}

void show(int list[], int n){
	for(int i=0; i<n; i++){
		std::cout << list[i] << std::endl;
	}
}

int main(){
	int i;
	int n = MAX_SIZE;
	int list[n]={5,3,8,4,9,1,6,2,7};


	quick_sort(list, 0, n-1);

	show(list, n);

	return 0;
}
