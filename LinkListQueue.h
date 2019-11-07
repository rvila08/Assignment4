#ifndef LinkListQueue_H
#define LinkListQueue_H

#include "DubLinkedList.h"

template <class T>
class LinkListQueue{

  public:
    //GenQueue(int maxSize);
    LinkListQueue();
    ~LinkListQueue();
    void insert(T data);
    T remove();
    T peek();
    //bool isFull();
    bool isEmpty();
    int getSize();

  private:
    int mSize;
    int numElements;
    DubLinkedList<T> *list;
};

template <class T>
LinkListQueue<T>::LinkListQueue(){
  list = new DubLinkedList<T>();
}

template <class T>
void LinkListQueue<T>::insert(T data){
  list->insertBack(data);
}

template <class T>
T LinkListQueue<T>::remove(){
  return list->removeFront();
}

template <class T>
T LinkListQueue<T>::peek(){
  return list->front->data;
}

template <class T>
bool LinkListQueue<T>::isEmpty(){
  return list->isEmpty();
}

template <class T>
int LinkListQueue<T>::getSize(){
  return list->getSize();
}
#endif
