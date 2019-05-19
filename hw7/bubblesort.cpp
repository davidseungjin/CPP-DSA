#include<iostream>
#define MAX_SIZE 10

void bubble_sort(int list[], int n){
	int i, j, temp;

	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(list[j] < list[j+1]){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
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
	int list[n] = {20,30,7, 4, 40, 5, 1, 50, 3};

	bubble_sort(list, n);

	show(list, n);

	return 0;
}

