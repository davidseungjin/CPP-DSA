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
            }
        }
        t.elapsedUserTime(eTime);
        f.close();
    }
    

    void sort(int low, int high){};
    
    void print(){      // should be implemented in this
        for(int i = 0 ; i < high ; i++)
            cout << arr[i] << endl;
    }
    ~Sorting(){
        cout << "Sorting destructor called" << endl;
    }
};


void measureAll(string file_name)
{
    for (int i=1; i<=3; ++i)
    {
        cout << " ========= " << "Partition" << i << " ========= " << endl;
        cout << "insertion sort" << endl;
        T.insertAllFromFile(i, file_name);         // insertion sort
//        cout << "\nquick sort" << endl;
//        b.insertAllFromFile(i, file_name);         // Quick sort
//        cout << "\nheap sort" << endl;
//        c.insertAllFromFile(i, file_name);         // Heap sort
    }
}

int main(int argc, char* argv[])
{
    const char* input_file = argc == 2 ? argv[1]: "random_5.txt";
    
    Sorting s(6);

    Sorting& T = s;
    
    T.insertAllFromFile(int partition, input_file);
    T.print();

    
    T.sort(0, 6);
    T.print();

    measureAll(input_file);
    
    return 0;

}
