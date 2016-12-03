#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    heap h(5);
    h.insert(3);
    h.insert(10);
    h.insert(3);
    h.insert(5);
    h.insert(14);
    h.removeMin();
    h.print();
    return 0;
}
