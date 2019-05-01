#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
	ifstream file("random_brief.txt");
	string* david;
	david = new string[10];
	if(file.is_open())
	{
		for (int i=0; i<10; i++)
		{
			file >> david[i];
		}
	}
	file.close();
  
//David question: it is what I did insertion using text file. 
//However in function provided (for ex, void insert_all_words(string file_name, UnorderedArrayList& L){}
//What confuses me are two
// 1. when you see hw2 at google doc, page 1, Instructor said 
//"DO NOT ADD ANY OTHER METHODS TO YOUR CLASS IMPLEMENTATIONS. and this is referring to insert_all_words... 
//blabla." when looking at arguments in function, there is UnorderedLinkedList object reference.
// can you interprete "string file_name" for me?



// David comment:
// below is added just because I wanted to see code works correctly.
// they are not the core. core it above.
	
	cout << "david string array cout" << endl;
	for (int i=0; i<10; i++)
		cout << "david[" << i << "] is : " << david[i] << endl;


	string test;
	
	for (int i=0; i <10; i++)
		test.insert(test.end(), david[i], "\n");

	cout << "insert function test result is below: \n" << test << endl;

	return 0;
}

