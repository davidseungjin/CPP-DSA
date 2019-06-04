#include<iostream>
#include<string>
#include<fstream>
#include "Timer.h"

using namespace std;


class Sorting{
public:
    string* arr;
    int low;
    int high;
public:
    Sorting(int maxsize)
        : arr(new string[maxsize]), low(0), high(maxsize){
    }
    virtual void push(string w) { arr[low++] = w; }
    virtual void sort(int low, int high)=0;

    void insertAllFromFile(int partition, string file_name){
        Timer t;
        double eTime;
        
        ifstream f(file_name.c_str());
        t.start();
        string w;
        f.is_open();
        for(int i = 0; i< partition*10; i++){
            getline(f, w);
            push(w);
        }
        sort(low, high);
        f.close();
        t.elapsedUserTime(eTime);
        cout << file_name << " partition " << partition <<
        " insert and sort time is " << eTime << endl;
    }
    
    void print(){      // should be implemented in this
        for(int i = 0 ; i < high ; i++){
            cout << arr[i] << endl;
        }
        cout << "\nSorting class print function\n" << endl;
    }
    ~Sorting(){
	delete[] arr;}
};

class Heapsort:public Sorting{
    
public:
    Heapsort(int maxsize)
    : Sorting(maxsize)
    {}

    void heapify(int high, int low)
    {
        int i = low;
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        
        if (l < high && arr[l] > arr[largest])
            largest = l;
        
        if (r < high && arr[r] > arr[largest])
            largest = r;
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            
            heapify(high, largest);
        }
    }
    
    void sort(int low, int high){
        for (int i = (high / 2) - 1; i >= 0; i--)
            heapify(high, i);
        
        for (int i = high - 1; i >= 0; i--){
            swap(arr[0], arr[i]);
            
            heapify(i, 0);
        }
    }
    
//    void print(){
//        for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]));i++){
//            cout << arr[i] << endl;
//        }
//    }
    
    ~Heapsort(){}
};

void measureAll(string file_name){
    for (int partition = 1; partition <= 1; partition++){
        cout << " ========= " << "Partition" << partition << " ========= " << endl;
/*
        cout << "Insertion sort\t";
        Insertionsort t(partition*4500);
        Sorting& T1 = t;
        T1.insertAllFromFile(partition, file_name);         // Insertion sort
//        T1.print();           printing function


        cout << "Quick sort\t";
        Quicksort u(partition*4500);
        Sorting& T2 = u;
        T2.insertAllFromFile(partition, file_name);         // Quick sort
*/
        cout << "Heap sort\t";
        Heapsort v(partition*10);
        Sorting& T3 = v;
        T3.insertAllFromFile(partition, file_name);         // Heap sort
        T3.print();
    }
}

int main(int argc, char* argv[]){
    const char* input_file = argc == 2 ? argv[1]: "random_q.txt";

    measureAll(input_file);
    
    return 0;
}
