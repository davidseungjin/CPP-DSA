#include<iostream>
#include<string>
#include<fstream>
#include "Timer.h"

using namespace std;


class Sorting{
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
            for(int i = 0; i< partition*10; i++){
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
        for(int i = 0 ; i < high ; i++)
            cout << arr[i] << endl;
    }
    ~Sorting(){
        cout << "Sorting destructor called" << endl;
    }
};

class Insertionsort:public Sorting{
    string* arr;
    int index;
    int low;
    int high;
public:
    Insertionsort(int maxsize)
    : arr(new string[maxsize]), index(0), low(0), high(maxsize){
        cout << "Insertionsort constructor called" << endl;
    }
    virtual void sort(int low, int high){
        int i, j;
        string key;
        
        for (i = 1; i < high; i++)
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
    ~Insertionsort(){
        cout << "Insertionsort destructor called" << endl;
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

/*
    Sorting s(10);
    Sorting& T = s;
    
    for(int i = 1 ; i < 2 ; i++){
        T.insertAllFromFile(i, input_file);
    }
//    measureAll(input_file);

    T.print();
    cout << "test" << endl;
    
    T.sort(0, 10);
    cout << "test 222 " << endl;
    T.print();
*/
    
    Insertionsort t(10);
    Sorting& T1 = t;
    
    for(int i = 1 ; i < 2 ; i++){
        T1.insertAllFromFile(i, input_file);
    }
    
    T1.print();
    cout << "test" << endl;
    
    T1.sort(0, 10);
    cout << "test 222 " << endl;
    T1.print();

    
    return 0;

}
