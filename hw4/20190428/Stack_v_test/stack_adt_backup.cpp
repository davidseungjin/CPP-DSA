#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Stack
{
public:
    Stack(){};
    virtual void push(string w)=0;
    virtual string pop()=0;
    virtual string top()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual void print()=0;
    ~Stack(){};
};

class StackArray:public Stack
{
    string* buf;
    int tp;
    int capacity;
public:
    StackArray(int maxsize)
    :capacity(maxsize=100), tp(0), buf(new string[maxsize]){
        cout << "Constructor is created\n";}
    ~StackArray(){ cout << "Destructor is called\n";}
    void push(string w) { cout<< "push function working?" << endl; buf[tp++] = w; }
    string pop() { return buf[--tp]; }
    string top() { return buf[tp-1]; cout << buf[tp-1] << endl; }
    bool isEmpty() { return tp <= 0; }
    bool isFull() { return tp >= capacity;}
    void print();                 // after confirming insert/remove&creating file works well, delete
};


class LinkedStack:public Stack
{
    struct ListNode{
        string info;
        ListNode* next;
        ListNode(string new_info, ListNode *new_next)
        :info(new_info), next(new_next){}
        
    };
    ListNode* head;
public:
    LinkedStack()
    :head(nullptr){}
    ~LinkedStack(){}
    //    void push(string w) { if(isFull()) error ("Push on full stack"); head = new ListNode(w, head); }
    void push(string w) { head = new ListNode(w, head); }
    string pop();
    //    string top() { if(isEmpty()) error("top on empty stack"); return head->info; }
    string top() { return head->info; }
    bool isEmpty() { return head == nullptr; }
    bool isFull() { return false; }
    void print();                 // after confirming insert/remove&creating file works well, delete
};

string LinkedStack::pop(){
    //    if(isEmpty())error("pop on empty stack");
    ListNode* p = head;
    string w = head->info;
    head = head -> next;
    delete p;
    return w;
}


void StackArray::print(){
    int i=0;
    cout << "print function is working" << endl;
    for (;i < tp ; i++)
        cout << "buf[" << i << "] is " << buf[i] << endl;
}

void LinkedStack::print(){
    ListNode* cur=head;
    for (cur = head; cur->next != NULL; cur=cur->next)
    {
        cout << cur->info << "\n";
    }
}

void fillAll(string file_name, Stack& L){
    ifstream f(file_name.c_str());
    string w;
    if(f.is_open()){
        while(getline(f, w)){
            L.push(w);
        }
    }
    f.close();
    cout << "insert_all_word done \n" << endl;
    L.print();
}

void emptyAll(Stack& L, string& output_file)
{
    ofstream f(output_file.c_str(), ios::out);        //David: is there any other way that doesn't use ios::app?
    //    f.open(output_file);
    
    while(L.isEmpty() == 0)
    {
        f << L.top() << endl;
        L.pop();
    }
    f.close();
}


void Stack_test(string file_name, Stack& L, string output_file)
{
    cout << "\n Testing StackArray==== " << endl;
    fillAll(file_name, L);
    emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
    const char* input_file = argc == 2? argv[1]: "random_1000.txt";
    const char* output_file1 = "StackArrayOutput.txt";
    const char* output_file2 = "LinkedStackOutput.txt";
    
    StackArray a(2000);
    LinkedStack b;

    Stack& s = a;
    Stack& t = b;

    Stack_test(input_file, a, output_file1);
    Stack_test(input_file, s, output_file2);

    
    return 0;
}

