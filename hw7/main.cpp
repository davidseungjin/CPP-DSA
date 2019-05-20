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

    Insertionsort A(6);

    Sorting& s = A;
    makearray(input_file, s);
    s.print_test();

    s.sort();
    s.print_test();

  
    
    
    return 0;

}
