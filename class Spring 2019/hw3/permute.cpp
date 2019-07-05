

#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

#define NWORDS 50000

string buf[NWORDS];
int length = 0;

void removeAndPrintRandom(ostream & out)
{
    unsigned long i = rand() % length;
    out << buf[i] << endl;
    buf[i] = buf[--length];
}

int main()
{
    ifstream in("words.txt");
    ofstream out("random.txt");
    while (in >> buf[length])
        length++;
    while (length > 0)
        removeAndPrintRandom(out);
    in.close();
    out.close();
}
