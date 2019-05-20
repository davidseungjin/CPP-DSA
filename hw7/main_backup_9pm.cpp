#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Sorting{

public:
    Sorting();
//    Sorting(int maxsize)
//        : arr(new string[maxsize]), index(0), low(0), high(maxsize){
//            cout << "Sorting constructor called" << endl;
//    }

//    insertAllFromFile(int partition, char *fileName);        // should be implemented in this
//    void print(ostream & out);                               // should be implemented in this
//    virtual void sort()=0;           // it is pure virtual. should not be implemented in this
    virtual void sort(string arr[], int low, int high)=0;
    virtual void push(string w)=0;
    virtual void print_test()=0;
    ~Sorting(){
        cout << "Sorting destructor called" << endl;
    }
};
/*
class Insertionsort:public Sorting{
    string* arr;
    int index;
    int capacity;
public:
    virtual void push(string w) { arr[index++] = w; }
    Insertionsort(int maxsize)
    : arr(new string[maxsize]), index(0), capacity(maxsize){
        cout << "Insertionsort constructor called" << endl;
    }
    virtual void sort(){
        int i, j;
        string key;
        
        for (i = 1; i < capacity; i++)
        {
            key = arr[i];
            j = i - 1;
            
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    
    void printArray(string arr[], int capacity);
    virtual void print_test(){
        for(int i=0; i<capacity; i++)
            cout << arr[i] << endl;
    }
    ~Insertionsort(){
        cout << "Insertionsort destructor called" << endl;
    }
};

*/

class Quicksort:public Sorting{
    string* arr;
    int low;
    int high;
    int index;

public:
    Quicksort(int maxsize)
    : arr(new string[maxsize]), index(0), low(0), high(maxsize){
        cout << "Quicksort constructor called" << endl;
    }
    virtual void push(string w) { arr[index++] = w; }

    
    void swap(string* a, string* b){
        string t = *a;
        *a = *b;
        *b = t;
    }

    string median_of_three(string* arr, int low, int high){
        int mid = low + (high - low)/2;
        if (arr[mid] < arr[low]) swap( &arr[low], &arr[mid] );
        if (arr[high] < arr[mid]) swap( &arr[mid], &arr[high] );
        return arr[mid];
    }
    
    int partition (string* arr, int low, int high){
        int mid = low + (high - low)/2;
        string pivot = arr[mid]; // pivot
        int i = (low - 1); // Index of smaller element
        
        for (int j = low; j <= high- 1; j++){
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot){
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    virtual void sort(string* arr, int low, int high){
        if (low < high){
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }
    void printArray(string arr[], int high);


    virtual void print_test(){
        for(int i=0; i<high; i++)
            cout << arr[i] << endl;
    }
    ~Quicksort(){
        cout << "Quicksort destructor called" << endl;
    }
    
};


class Heapsort:public Sorting{
    string* arr;
    int low;
    int high;
    int index;
    
public:
    Heapsort(int maxsize)
    : arr(new string[maxsize]), index(0), low(0), high(maxsize){
        cout << "Heapsort constructor called" << endl;
    }

    virtual void push(string w) { arr[index++] = w; }
    
    void heapify(string arr[], int high, int low)
    {
        int largest = low; // Initialize largest as root
        int l = 2 * low + 1; // left = 2*i + 1
        int r = 2 * low + 2; // right = 2*i + 2
        
        // If left child is larger than root
        if (l < high && arr[l] > arr[largest])
            largest = l;
        
        // If right child is larger than largest so far
        if (r < high && arr[r] > arr[largest])
            largest = r;
        
        // If largest is not root
        if (largest != low) {
            swap(arr[low], arr[largest]);
            
            // Recursively heapify the affected sub-tree
            heapify(arr, high, largest);
        }
    }
    
    // main function to do heap sort
    virtual void sort(string arr[], int high, int low)
    {
        // Build heap (rearrange array)
        for (int i = high / 2 - 1; i >= 0; i--)
            heapify(arr, high, i);
        
        // One by one extract an element from heap
        for (int i = high - 1; i >= 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
            
            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
 
    virtual void print_test(){
        for(int i=0; i<high; i++)
            cout << arr[i] << endl;
    }

 
    void printArray(string arr[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
    
    ~Heapsort(){
        cout << "Heapsort destructor called" << endl;
    }
    
};

void makearray(string file_name, Sorting& L){
    ifstream f(file_name.c_str());
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            L.push(w);
        }
        f.close();
    }
}
    
    
int main(){
    const char* input_file = "random_5.txt";

//    Insertionsort A(6);
//
//    Sorting& s = A;
//    makearray(input_file, s);
//    s.print_test();
//
//    s.sort();
//    s.print_test();
//
    
    Quicksort B(5);
    
    Sorting& t = B;
    makearray(input_file, t);
    t.print_test();
    cout << "\nSorted below\n" << endl;
    
//    t.sort(arr, 0, 6);
    t.print_test();

    
    Heapsort C(5);
    
    Sorting& u = C;
    makearray(input_file, u);
    u.print_test();
    cout << "\nSorted below\n" << endl;
    
//    t.sort(arr, 0, 6);
    u.print_test();

    
    
    return 0;

}
