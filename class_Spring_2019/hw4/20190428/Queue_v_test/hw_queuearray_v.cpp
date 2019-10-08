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
    virtual void print()=0;
    ~Queue(){};
};

class QueueArray:public Queue
{
	string* buf;		// base of circular array
	int capacity, front, rear;
public:
	QueueArray(int maxsize)
	:capacity(maxsize+1), front(0), rear(0), buf(new string[maxsize+1]){}

	
	~QueueArray(){ cout << "Destructor is called\n";}
	void enque(string w) 
	{ cout<< "push function working?" << endl; buf[rear] = w; rear = (rear+1)%capacity;}

	string deque() { string david = buf[front]; front=(front + 1)%capacity;return david; }
	string f_position() { return buf[front]; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear+1)%capacity == front;}
	void print(); 	// after confirming insert/remove&creating file works well, delete
};

void QueueArray::print(){
	int i=0;
	cout << "print function is working. Regardless of front/rear position" << endl;
	for (;i < capacity ; i++)
		cout << "buf[" << i << "] is " << buf[i] << endl;
}

void fillAll(string file_name, Queue& L){
	ifstream f(file_name.c_str());
	string w;
	
	if(f.is_open()){
		while(getline(f, w)){	
			L.enque(w);
			L.print();
		}
	}
	f.close();
	cout << "insert_all_word done \n" << endl;
//	L.print();
}

void emptyAll(Queue& L, string output_file)
{
	ofstream f(output_file, ios::app);		//David: is there any other way that doesn't use ios::app?
//	f << "2.     test before open" << endl;
//	f.open(output_file);
//	f << "3.       test right after open" << endl;

	while(L.isEmpty() == 0)
	{
		f << L.f_position() << endl;
		L.deque();
		L.print();
	}
	f.close();
}

void Queue_test(string file_name, Queue& L, string output_file)
{
	fillAll(file_name, L);
	emptyAll(L, output_file);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_1000.txt";
	const char* output_file = "QueueArrayOutput.txt";

	QueueArray b(500);
    
    Queue& r = b;
    
	Queue_test(input_file, r, output_file);

	return 0;
}

