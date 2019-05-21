#include<iostream>
#include<string>
#include<fstream>
#include "Timer.h"

using namespace std;


class Sorting{
public:
    string* arr;
    int index;
    int low;
    int high;
public:
//    Sorting();
    Sorting(int maxsize)
        : arr(new string[maxsize]), index(0), low(0), high(maxsize){
            cout << "Sorting constructor called" << endl;
    }
    virtual void push(string w) { arr[index++] = w; }
    virtual void sort(int low, int high)=0;

    void insertAllFromFile(int partition, string file_name){
        Timer t;
        double eTime;
        
        ifstream f(file_name.c_str());
        t.start();
        string w;
        f.is_open();
        for(int i = 0; i< partition*4500; i++){
            getline(f, w);
            push(w);
//                cout << "intentional line   " << i << endl;
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
        cout << "Sorting destructor called" << endl;
    }
};

class Insertionsort:public Sorting{
    
public:
    Insertionsort(int maxsize)
    : Sorting(maxsize)
    {
        cout << "Insertionsort constructor called" << endl;
    }
    virtual void sort(int low, int high){
        int i, j;
        string key;
//        cout << "\t\ntest whether it is working\n";
        for (i = 1; i < high; i++)
        {
            key = arr[i];
//            cout << "arr[i]  " << arr[i] << endl;
            j = i - 1;
//            cout << "i in for loop = " << i << endl;
//            cout << "j in for loop = " << j << endl;
            while (j >= 0 && arr[j] > key)
            {
//                cout << "key is " << key << endl;
//                cout << "arr[j] is " << arr[j] << endl;
//
                arr[j + 1] = arr[j];
                j = j - 1;
//                cout << "j in for and while loop = " << j << endl;
                
            }
            arr[j + 1] = key;
        }
    }
    ~Insertionsort(){
        cout << "Insertionsort destructor called" << endl;
    }
};

class Quicksort:public Insertionsort{
    
public:
    Quicksort(int maxsize)
    : Insertionsort(maxsize)
    {
        cout << "Quicksort constructor called" << endl;
    }

    
    void swap(string* a, string* b)
    {
        string t = *a;
        *a = *b;
        *b = t;
    }
    
    string median_of_three( int low, int high )
    {
        int mid = low + (high - low) / 2;
        if ( arr[mid] < arr[low] ) swap( &arr[low], &arr[mid] );
        if ( arr[mid] > arr[high] ) swap( &arr[mid], &arr[high] );
//        cout << "arr[mid] is " << arr[mid] << " and mid index is " << mid << endl;
        return arr[mid];
    }

    
    int partition (int low, int high)
    {
        string pivot = median_of_three(low, high); // pivot
//        cout << "pivot value is " << pivot << endl;
        
        int i = (low-1); // Index of smaller element
        
        for (int j = low; j < high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    void sort(int low, int high)
    {
////        cout << "quicksort start " << endl;
//        int K = 10;
//        if(high-low < K){
////            cout << "high / low / difference is " << high << "\t" <<  low <<
////            "\t" << high - low << endl;
////            cout << "change to Insertionsort" << endl;
//            Insertionsort::sort(low, high);
//        }
        if (low < high)
        {
//            cout << "high / low / difference is " << high << "\t" <<  low <<
//            "\t" << high - low << endl;
//            cout << "continue to use quicksort" << endl;
            /* pi is partitioning index, arr[p] is now
             at right place */
            int pi = partition(low, high);
            
            // Separately sort elements before
            // partition and after partition
            sort(low, pi - 1);
            sort(pi + 1, high);
        }
    }
    
    ~Quicksort(){
        cout << "Quicksort destructor called" << endl;
    }
};


class Heapsort:public Sorting{
    
public:
    Heapsort(int maxsize)
    : Sorting(maxsize)
    {
        cout << "Heapsort constructor called" << endl;
    }

    void heapify(int high, int low)
    {
        int i = low;
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        
        // If left child is larger than root
        if (l < high && arr[l] > arr[largest])
            largest = l;
        
        // If right child is larger than largest so far
        if (r < high && arr[r] > arr[largest])
            largest = r;
        
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            
            // Recursively heapify the affected sub-tree
            heapify(high, largest);
        }
    }
    
    // main function to do heap sort
    void sort(int low, int high)
    {
        // Build heap (rearrange array)
        for (int i = (high / 2) - 1; i >= 0; i--)
            heapify(high, i);
        
        // One by one extract an element from heap
        for (int i = high - 1; i >= 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
            
            // call max heapify on the reduced heap
            heapify(i, 0);
        }
    }
    
    ~Heapsort(){
        cout << "Heapsort destructor called" << endl;
    }
};



void measureAll(string file_name)
{
    

    
    for (int partition = 1; partition <= 10; partition++){
        cout << " ========= " << "Partition" << partition << " ========= " << endl;
        
        cout << "insertion sort" << endl;
        Insertionsort t(partition*4500);
        Sorting& T1 = t;

        T1.insertAllFromFile(partition, file_name);         // insertion sort

//        T1.print();           printing function

        cout << "\nquick sort" << endl;
        Quicksort u(partition*4500);
        Sorting& T2 = u;
        
        T2.insertAllFromFile(partition, file_name);         // Quick sort

        cout << "Heap sort" << endl;
        Heapsort v(partition*4500);
        Sorting& T3 = v;

        T3.insertAllFromFile(partition, file_name);         // Heap sort
        

    }
}



int main(int argc, char* argv[])
{
    const char* input_file = argc == 2 ? argv[1]: "random.txt";

    measureAll(input_file);
    
    return 0;

}
