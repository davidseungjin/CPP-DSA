#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Sorting{
public:
    Sorting(){
        cout << "Sorting constructor called" << endl;
    }

//    insertAllFromFile(int partition, char *fileName);        // should be implemented in this
//    void print(ostream & out);                               // should be implemented in this
    virtual void sort()=0;           // it is pure virtual. should not be implemented in this
    virtual void push(string w)=0;
    virtual void print_test()=0;
    ~Sorting(){
        cout << "Sorting destructor called" << endl;
    }
};

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
            
            /* Move elements of arr[0..i-1], that are
             greater than key, to one position ahead
             of their current position */
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


class Quicksort:public Sorting{
    string* arr;
    int index;
    int capacity;

public:
    Quicksort(int maxsize)
    : arr(new string[maxsize]), index(0), capacity(maxsize){
        cout << "Quicksort constructor called" << endl;
    }

    void swap(string* a, string* b)
    {
        string t = *a;
        *a = *b;
        *b = t;
    }

    string median_of_three(string arr[], int low, int high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] < arr[low]) swap( arr[low], arr[mid] );
        if (arr[high] < arr[mid]) swap( arr[mid], arr[high] );
        return A[mid];
    }

    
    virtual void push(string w) { arr[index++] = w; }
    
    int partition (string arr[], int low, int high)
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
    virtual void sort(string arr[], int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
             at right place */
            int pi = partition(arr, low, high);
            
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    void printArray(string arr[], int capacity);
    virtual void print_test(){
        for(int i=0; i<capacity; i++)
            cout << arr[i] << endl;
    }
    ~Quicksort(){
        cout << "Quicksort destructor called" << endl;
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
    
    
int main(int argc, char* argv[]){
    const char* input_file = argc == 2? argv[1] : "random_5.txt";

    Insertionsort A(6);
    
    Quicksort B(6);
    
    Sorting& s = A;
    makearray(input_file, s);
    s.print_test();
        
    s.sort();
    s.print_test();
    
    Sorting& t = B;
    makearray(input_file, t);
    t.print_test();
    
    t.sort();
    t.print_test();
    
    return 0;
}
