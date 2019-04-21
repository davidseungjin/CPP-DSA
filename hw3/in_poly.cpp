#include <iostream>

using namespace std;

class Progression {
public:
	Progression(long f=0)
		:first(f), cur(f){}
	virtual ~Progression(){};		//David: look at this. virtual
	void printProgression(int n);
Protected:
	virtual long firstValue();		// reset
	virtual long nextValue();		// advance
protected:
	long first;				// first value
	long cur;				// current value
};

// The member function printProgression is public and is defined below. 

void Progression::printProgression(int n){
	cout<<firstValue();
	for (int i=2; i<=n; i++)
		cout << ' ' << nextValue();
	cout << endl;
}

// in contrast, the member function firstValue and nextValue are intended as utilities that will only be invoked from within this class or its derived classes.
// for this reason, we declare them to be protected. They are defined below.

long Progression::firstValue(){
	cur=first;
	return cur;
}

long Progression::nextValue(){
	return ++cur;
}



class ArithProgression : public Progression {
public:
	ArithProgression(long i = 1);		// constructor
protected:
	virtual long nextValue();		// advance
protected:
	long inc;				// increment
};

// The constructor and the new member function nextValue are defined below.
// Observe that the constructor invokes the base class constructor Progression to initialize the base object in addition to initializing the value of inc.

ArithProgression::ArithProgression(long i)
	:Progression() inc(i) {}

long ArithProgression::nextValue(){
	cur+=inc;
	return cur;
}

// To be continued.
// ddddddddddddddddddddddd

