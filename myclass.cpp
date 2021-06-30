#include "myclass.hpp"
#include <stdlib.h>
// private implementation

static myclass *ptr_priv; // pointer to store where memory has been allocated
static int init_ctr = 0; // indicates init

void cleanup(void); // cleanup function

class myclass_priv : public myclass // private declaration
{
private:
    int p;

public:
    int a;
    myclass_priv()
    {
        p = 0;
        a = -p;
        atexit(cleanup);
    }
    int addVal(int x);
    int *getPtr(void);
    int getVal();
};
int myclass_priv::addVal(int x) // private implementation
{
    p = -x;
    a = x;
    return p;
}
int *myclass_priv::getPtr(void)
{
    return &p;
}
int myclass_priv::getVal(void)
{
    return p;
}

int myclass::listClass(myclass **ptr) // public method to get new objects, can be made more robust to allow for new object calls
{
    *ptr = new myclass_priv;
    ptr_priv = *ptr;
    init_ctr = 1;
    return 1;
}

void cleanup() // cleanup at exit
{
    if (init_ctr)
    {
        delete (ptr_priv);
        init_ctr = 0;
    }
}