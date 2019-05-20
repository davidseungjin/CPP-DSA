// C++ program for insertion sort
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class Insertionsort{
    string* arr;
    int index;
    int capacity;
public:
    void push(string w) { arr[index++] = w; }
    Insertionsort(int maxsize)
        : arr(new string[maxsize]), index(0), capacity(maxsize){
            cout << "constructor called" << endl;
        }
    void insertionSort();
    void printArray(string arr[], int capacity);
    void print_test(){
        for(int i=0; i<capacity; i++)
            cout << arr[i] << endl;
    }
    ~Insertionsort(){
        cout << "destructor called" << endl;
    }
};
/* Function to sort an array using insertion sort*/
void Insertionsort::insertionSort()
{
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

void makearray(string file_name, Insertionsort& L){
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

    Insertionsort a(10);
//    Sorting& s = a;
    
    makearray(input_file, a);
    a.print_test();
    
    a.insertionSort();
    a.print_test();
    
    return 0;
}
