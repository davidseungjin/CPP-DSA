#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class QueueArray
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

void insert_all_words(string file_name, QueueArray& L){
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

void remove_all_words(QueueArray& L, string output_file)
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

void test_QueueArray(string file_name, QueueArray& L, string output_file)
{
	cout << "\n Testing StackArray==== " << endl;
	insert_all_words(file_name, L);
	remove_all_words(L, output_file);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2? argv[1]: "random_5.txt";
	const char* output_file = "QueueArrayOutput.txt";

	QueueArray a(3);

	test_QueueArray(input_file, a, output_file);

	return 0;
}

