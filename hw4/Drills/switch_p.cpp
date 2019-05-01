#include <iostream>
using namespace std;

char switchtest(char c){

	if (c=='{') { c='}';}
	else if (c == '(') { c=')';}
	else if (c == '[') { c=']';}
	else {c='>';}

	cout << "test " << endl;

	if (c=='{'||'(') { cout << "compared"; return false; }




/*
	switch(c){
		case '{':
			c = '}';
			return c;
		case '[':
			return ']';
		case '(':
			return ')';
		case '<':
			return '>';
	}
*/
	cout << "test complete" << endl;
	return 0;
}

int main(){
	char* c;
	c = new char;
	string* s;
	s = new string[];
	cout << "input brakets:  ";
	cin >> c;
	cout << "input string : ";
	cin >> s;
	cout << "*c is " << *c << endl;
	cout << "c is " << c << endl;
	cout << "*s is " << *s << endl;
	cout << "s is " << s << endl;
	
	int i;	
	for (i=0 ; i < strlen(c) ; i++){
		cout << "c[i] is " << c[i] << endl;
		switchtest(c[i]);
		cout << "switch(c[i]) is " << c[i] << endl;
	}

	return 0;

}			
