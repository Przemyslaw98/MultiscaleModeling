#ifndef IMAGESTACK_H
#define IMAGESTACK_H
#include <cstddef>

class imageStack{
  public:
    imageStack(int** i=NULL);
    virtual ~imageStack();
    void push(int**);
    int** pop();
    int** peek();
    void clear();
    bool isOne();
    bool isEmpty();
  protected:
    imageStack* next;
    int** image;
};

#endif // IMAGESTACK_H
