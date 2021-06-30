#include <iostream>
#include "myclass.hpp"

int main()
{
    myclass *a; // pointer to class
    myclass::listClass(&a); // listclass really allocates memory and sets up private backend
    a->addVal(10); // execute private method
    std::cout << a->getPtr() << "::" << a->getVal() << std::endl; // get more private methods
    return 0; // exit
}