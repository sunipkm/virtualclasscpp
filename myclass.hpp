#pragma once

// public interface
class myclass {
    public:
    int a;
    static int listClass(myclass **ptr);
    virtual int addVal(int x) = 0;
    virtual int *getPtr() = 0;
    virtual int getVal(void) = 0;
};