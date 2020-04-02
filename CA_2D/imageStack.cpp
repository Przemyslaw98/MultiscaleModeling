#include "imageStack.h"
#include <cstddef>

imageStack::imageStack(int** i){
  image=i;
  next=NULL;
}
imageStack::~imageStack(){
  delete image;
  delete next;
}
void imageStack::push(int** i){
  imageStack* pnt=this;
  while(pnt->next!=NULL)
    pnt=pnt->next;
  pnt->next=new imageStack(i);
}
int** imageStack::pop(){
  if(next==NULL)
    return NULL;
  imageStack* pnt=this;
  while(pnt->next->next!=NULL)
    pnt=pnt->next;
  int** i=pnt->next->image;
  pnt->next->~imageStack();
  pnt->next=NULL;
  return i;
}
int** imageStack::peek(){
  if(next==NULL)
    return NULL;
  imageStack* pnt=this;
  while(pnt->next->next!=NULL)
    pnt=pnt->next;
  int** i=pnt->next->image;
  return i;
}
void imageStack::clear(){
  while(next!=NULL)
    pop();
}
bool imageStack::isOne(){
  if(next->next==NULL)
    return true;
  else return false;
}
bool imageStack::isEmpty(){
  if(next==NULL)
    return true;
  else return false;
}
