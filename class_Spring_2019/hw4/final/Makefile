CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant

all: test_stack test_queue

test_stack: test_stack.cpp
	g++ $(CXXFLAGS) test_stack.cpp -o test_stack

test_queue: test_queue.cpp
	g++ $(CXXFLAGS) test_queue.cpp -o test_queue
