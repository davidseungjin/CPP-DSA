// ostream& practice.
/* Output streams use the insertion << operator for standard types. 
You can also overload the << operator for your own classes.
The write function example showed the use of a Data structure. 
A date is an ideal candidate for a C++ class in which the data members (month, day, and year) are hidden from view.
An output stream is the logical destination for displaying such as structure. 
To get cout to accept a Data object after the insertion operator, 
overloaded insertion operator to recognize an ostream object on the left and a Data on the right.
The overloaded << operator function must then be declared as a friend of class Date so it can access the private data with a Data object. 
*/

/* David interpretation. 
ex1) when public function(constructor or other function) call privite member in calss: no problem.
ex2) when function outside of class try to access to public memeber data: no problem.
ex3) when function outside of calss try to access to private member data: error
ex4) together with friend, when function outside of class try to access to private member data: possible.
*/

// EXAMPLE 1

#include<iostream>
using namespace std;

class Data
{ 

private:
	int mo, da, yr;
public:
	Data(int m, int d, int y)
	{
		mo=m; da=d; yr=y;
		cout<< mo << '/' << da << '/' << yr << "\n";
	}
};

int main()
{
	Data dt(5,6,92);
}	

// EXAMPLE 2
#include<iostream>
using namespace std;

class Data
{ 
public: 
	int mo, da, yr;
public:
	Data(int m, int d, int y)
	{
		mo=m; da=d; yr=y;
	}
};

int main()
{
	Data dt(5,6,92);
	cout << dt.mo << '/' << dt.da << '/' << dt.yr << "\n";
}	

// EXAMPLE 3
#include<iostream>
using namespace std;

class Data
{ 

private:
	int mo, da, yr;
public:
	Data(int m, int d, int y)
	{
		mo=m; da=d; yr=y;
	}
};

int main()
{
	Data dt(5,6,92);
	cout << dt.mo << '/' << dt.da << '/' << dt.yr << "\n";
}	


// EXAMPLE 4
#include<iostream>
using namespace std;

class Data
{ 

private:
	int mo, da, yr;
public:
	Data(int m, int d, int y)
	{
		mo=m; da=d; yr=y;
	}
	friend ostream& operator<<(ostream& os, const Data& dt);
};

ostream& operator<<(ostream& os, const Data& dt)
{
	os << dt.mo << '/' << dt.da << '/' << dt.yr;
	return os;
}

int main()
{
	Data dt(5,6,92);
	cout << dt << "\n";
}	



