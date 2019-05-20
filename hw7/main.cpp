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
    void insertAllFromFile(int partition, string file_name){
        Timer t;
        double eTime;
        
        ifstream f(file_name.c_str());
        t.start();
        string w;
        if(f.is_open()){
            for(int i = 0; i< partition*50000; i++){
                getline(f, w);
                push(w);
                cout << "intentional line   " << i << endl;
            }
        }
        t.elapsedUserTime(eTime);
        f.close();
    }
    
    virtual void sort(int low, int high)=0;
    
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
//    string* arr;
//    int index;
//    int low;
//    int high;
// When inheritance, it isn't necessary to declare multiple times.
    
public:
    Insertionsort(int maxsize)
    : Sorting(maxsize)
    {
        cout << "Insertionsort constructor called" << endl;
    }
    virtual void sort(int low, int high){
        int i, j;
        string key;
        cout << "\t\ntest whether it is working\n";
        for (i = 1; i < high; i++)
        {
            key = arr[i];
            cout << "arr[i]  " << arr[i] << endl;
            j = i - 1;
            cout << "i in for loop = " << i << endl;
            cout << "j in for loop = " << j << endl;
            while (j >= 0 && arr[j] > key)
            {
                cout << "key is " << key << endl;
                cout << "arr[j] is " << arr[j] << endl;
                
                arr[j + 1] = arr[j];
                j = j - 1;
                cout << "j in for and while loop = " << j << endl;
                
            }
            arr[j + 1] = key;
        }
    }
    ~Insertionsort(){
        cout << "Insertionsort destructor called" << endl;
    }
};

class Quicksort:public Sorting{
    
public:
    Quicksort(int maxsize)
    : Sorting(maxsize)
    {
        cout << "Quicksort constructor called" << endl;
    }

    void swap(string* a, string* b)
    {
        string t = *a;
        *a = *b;
        *b = t;
    }
    
    int partition (int low, int high)
    {
        string pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element
        
        for (int j = low; j <= high- 1; j++)
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
        if (low < high)
        {
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


/*
void measureAll(string file_name)
{
    for (int partition = 1; partition <= 1; partition++){
        cout << " ========= " << "Partition" << partition << " ========= " << endl;
        cout << "insertion sort" << endl;
        T.insertAllFromFile(partition, file_name);         // insertion sort
//        cout << "\nquick sort" << endl;
//        b.insertAllFromFile(partition, file_name);         // Quick sort
//        cout << "\nheap sort" << endl;
//        c.insertAllFromFile(partition, file_name);         // Heap sort
    }
}
*/


int main(int argc, char* argv[])
{
    const char* input_file = argc == 2 ? argv[1]: "random.txt";
    
    Insertionsort t(50000);
    Sorting& T1 = t;
    
    // because measureAll funtion is not working....
    for(int i = 1 ; i < 2 ; i++){
        T1.insertAllFromFile(i, input_file);
    }
    
    T1.print();
    cout << "\nbefore sorted\n" << endl;
    
    T1.sort(0, 50000);
    cout << "\nafter sorted\n" << endl;
    T1.print();

    
    /*
    
    Quicksort u(10);
    Sorting& T2 = u;
    
    
    // because measureAll funtion is not working....
    for(int i = 1 ; i < 2 ; i++){
        T2.insertAllFromFile(i, input_file);
    }
    
    T2.print();
    cout << "\nbefore sorted\n" << endl;
    
    T2.sort(0, 50000);
    cout << "\nafter sorted\n" << endl;
    T2.print();

    
    Heapsort v(10);
    Sorting& T3 = v;
    
    
    // because measureAll funtion is not working....
    for(int i = 1 ; i < 2 ; i++){
        T3.insertAllFromFile(i, input_file);
    }
    
    T3.print();
    cout << "\nbefore sorted\n" << endl;
    
    T3.sort(0, 50000);
    cout << "\nafter sorted\n" << endl;
    T3.print();
    
    */
    

    return 0;

}
