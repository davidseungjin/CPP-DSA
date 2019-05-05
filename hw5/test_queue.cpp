#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Queue
{
public:
    Queue(){};
    virtual void enque(string w)=0;
    virtual string deque()=0;
    virtual string f_position()=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    ~Queue(){};
};

class QueueArray:public Queue
{
    string* buf;        // base of circular array
    int capacity, front, rear;
public:
    QueueArray(int maxsize)
    :capacity(maxsize+1), front(0), rear(0), buf(new string[maxsize+1]){}
    
    ~QueueArray(){}
    void enque(string w)
    { buf[rear] = w; rear = (rear+1)%capacity;}
    
    string deque() { string david = buf[front]; front=(front + 1)%capacity;return david; }
    string f_position() { return buf[front]; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear+1)%capacity == front;}
};

class LinkedQueue:public Queue
{
    struct ListNode{
        string info;
        ListNode* next;
        ListNode(string new_info, ListNode *new_next)
        :info(new_info), next(new_next){}
    };
    ListNode* head;
    ListNode* tail;
public:
    LinkedQueue()
    :head(nullptr), tail(nullptr){}
    ~LinkedQueue(){}
    void enque(string w)
    {
        ListNode* newNode = new ListNode(w, nullptr);
        if(isEmpty()){
            head = newNode;}
        else{
            tail->next = newNode;}
        tail = newNode;
    }
    string deque();
    string f_position() { return head->info; }
    bool isEmpty() { return head == nullptr; }
    bool isFull() { return false; }
};


class BaseFlowException
{
public:
    BaseFlowException(){}
    ~BaseFlowException(){}
};

class ContainerOverFlow:public BaseFlowException
{
private:
    string of_msg;
public:
    ContainerOverFlow(string error)
    :of_msg(error){}
    const char* getError(){ return of_msg.c_str(); }
    ~ContainerOverFlow(){}
};


class ContainerUnderFlow:public BaseFlowException
{
private:
    string uf_msg;
public:
    ContainerUnderFlow(string error)
    :uf_msg(error) {}
    const char* getError(){ return uf_msg.c_str(); }
    ~ContainerUnderFlow(){}
};



string LinkedQueue::deque(){
    ListNode* p = head;
    string w = head->info; 
    head = head -> next;
    delete p;
    return w; 
}

void fillAll(string file_name, Queue& L){
    ifstream f(file_name.c_str());
    string w;
    
    if(f.is_open()){
        while(getline(f, w)){
            try{
                if(L.isFull()){
                    throw ContainerOverFlow("OverFlow Error");
                } else {
                    L.enque(w);
                }
            }
            catch(ContainerOverFlow& exception){
                cerr <<    exception.getError() << endl;
		break;
            }
        }
    }
    f.close();
}

void emptyAll(Queue& L, string output_file)
{
    ofstream f(output_file.c_str(), ios::app); 
    try{
        if(L.isEmpty()){
            throw ContainerUnderFlow("UnderFlow Error");
        } else {
                while(L.isEmpty() == 0){
                    f << L.f_position() << endl;
                    L.deque();
                }
                f.close();
        }
    }
    catch(ContainerUnderFlow& exception){
        cerr << "An Exception Occurred: " << exception.getError() << endl;
    }
}

void Queue_test(string file_name, Queue& L, string output_file)
{
    fillAll(file_name, L);
    emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
    const char* input_file = argv[1];
    const char* output_file1 = argv[2];
    const char* output_file2 = argv[3];

    
    QueueArray a(45500);
    LinkedQueue b;

    Queue& q = a;
    Queue& r = b;
    
    Queue_test(input_file, q, output_file1);
    Queue_test(input_file, r, output_file2);
    
    return 0;
}

