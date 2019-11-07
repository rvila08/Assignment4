#ifndef DubLinkedList_H
#define DubLinkedList_H

using namespace std;

template <class T>
class ListNode{
  public:
      T data;
      ListNode *next;
      ListNode *prev;
      ListNode();
      ListNode(T d);
      ~ListNode();
};

template <class T>
ListNode<T>::ListNode(){

}
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = nullptr; //nullptr
  prev = nullptr;

}
template <class T>
ListNode<T>::~ListNode(){
  next = nullptr;
  prev = nullptr;
}


template <class T>
class DubLinkedList{
  public:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
    DubLinkedList();
    ~DubLinkedList();

    void insertBack(T d);
    T removeFront();

    bool isEmpty();
};

template <class T>
DubLinkedList<T>::DubLinkedList(){
  size = 0;
  front = nullptr;
  back = nullptr;
}

template <class T>
void DubLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    front = node;
  }
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}
template <class T>
T DubLinkedList<T>::removeFront(){

  ListNode<T> *ft = front;
  if(isEmpty()){
      //throw runtime_error("List is empty. Unable to remove.");
  }
  if(size == 1){
    //one node in the list
    back = nullptr;
  }
  else{
    front ->next->prev = nullptr;
  }

  front = front ->next;
  ft ->next = nullptr;
  T temp = ft -> data;
  delete ft;

  size --;
  return temp;
}
template <class T>
bool DubLinkedList<T>::isEmpty(){
  if(front==nullptr){
    return true;
  }
  return false;
}
#endif
