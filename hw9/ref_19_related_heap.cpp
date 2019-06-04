
#include <iostream>

using namespace std;


void min_heapify (int arr[] , int i, int N)
{
    int left  = 2*i;
    cout << "1. min heap" << endl;
    int right = 2*i+1;
    cout << "2. min heap" << endl;
    int smallest;
    if(left < N && arr[left] < arr[ i ] ){
        smallest = left;
        cout << "3. min heap" << endl;
    }else{
        smallest = i;
        cout << "4. min heap" << endl;
    }
    if(right < N && arr[right] < arr[smallest] ){
        cout << "5. min heap" << endl;
        smallest = right;
    }
    if(smallest != i){
        cout << "6. min heap" << endl;
        swap (arr[i], arr[smallest]);
        cout << "      test      \n";
        min_heapify (arr, smallest, N/2);
    }
}

void build_minheap (int arr[], int N)
{
    
    for( int i = N/2 ; i >= 1 ; i--){
        cout << "7. min heap" << endl;
        min_heapify (arr, i, N);
    }

    for(int i = 0;;i++){
        cout << "8. min heap" << endl;
        if(arr[i]){cout << "arr[" << i << "] is " << arr[i] << endl;
        
        }else{
            break;
        }
    }
}

int main()
{
    int arr[] = {1,3,5,4,2};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << "N is " << N << endl;
    
    build_minheap(arr, N);
    
    return 0;
}
