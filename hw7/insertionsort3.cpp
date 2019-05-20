#include<iostream>
#define MAX_SIZE 5

void insertion_sort(int list[], int n){
	int i, j, key;

	for(i = 1; i < n; i++){			// it assume index[0] is already sorted
		key = list[i];

		for(j = i-1; j >= 0 && list[j] > key ; j--){
			list[j+1] = list[j];
		}

		list[j+1] = key;
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
	int list[n] = {8,5,6,2,4};

	insertion_sort(list, n);

	show(list, n);

	return 0;
}
