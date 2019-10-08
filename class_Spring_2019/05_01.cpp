/* In this section, we present a concrete C++ implementation of the above pseudocode specification by means of a class, called ArrayStack. our approach is to store the elements of a stack in an array. To keep the code simple, we have omitted the standard housekeeping utilities, such as a destructor, an assignment operator, and a copy constructor. We leave their implementation as an exercise.
*/

template <typename E>
clas ArrayStack {
	enum {DEF_CAPACITY = 100;}

public:
	ArrayStack{int cap=DEF_CAPACITY);
	int size() const;
	bool 

