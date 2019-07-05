#include<iostream>
#define MAX_SIZE 15

int sorted[MAX_SIZE];		// additional storage is necessary

/* integer declaration
 * i: index in the left sorted
 * j: index in the right sorted
 * k: index in the list
*/
void merge(int list[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while(i <= mid && j <= right){
		if(list[i] <= list[j]){sorted[k++] = list[i++];}
		else{sorted[k++] = list[j++];}
	}

	if(i > mid){
		for(l = j; l <= right; l++){sorted[k++] = list[l];}
	}else{
		for(l = i; l <= mid ; l++){sorted[k++] = list[l];}
	}

	for(l = left; l <= right; l++){
		list[l] = sorted[l];
	}
}


void merge_sort(int list[], int left, int right){
	int mid;
	if(left < right){
		mid = (right - left)/2 + left;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}


int main(){
	int i;
	int n = MAX_SIZE;
	int list[n] = {50,40,30,20,15,25,35,45,46,22,32,1,3,5,6};

	merge_sort(list, 0, n-1);

	for(i = 0; i < n; i++){
		std::cout << list[i] << std::endl;
	}

	return 0;
}
	
