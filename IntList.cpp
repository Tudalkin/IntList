#include <iostream>
#include "IntList.h"
using namespace std;



//functions for intlisgt
void IntList::print(){
  ListNode *nodePtr=nullptr;
  nodePtr=head;
  while(nodePtr){
    cout<<nodePtr->value<<" ";
    nodePtr=nodePtr->next;
  }
  cout<<endl<<endl;
}

void IntList::insertNode(int num){
  ListNode *nodePtr;
  ListNode *newNode;
  ListNode *previousNode=nullptr;

  newNode= new ListNode;
  newNode->value=num;

  if(!head){
    head=newNode;
    newNode->next=nullptr;
  }
  else{
    nodePtr=head;
    previousNode=nullptr;
    while(nodePtr!=nullptr&&nodePtr->value<num){
      previousNode=nodePtr;
      nodePtr=nodePtr->next;
    }
    if(previousNode==nullptr){
      head=newNode;
      newNode->next=nodePtr;
    }
    else{
      previousNode->next=newNode;
      newNode->next=nodePtr;
    }
  }
}
void IntList::deleteNode(int num){
  ListNode *nodePtr, *previousNode=nullptr;
  if(!head)
    return;
  if(head->value==num){
    nodePtr=head->next;
    delete head;
    head=nodePtr;
  }
  else{
    nodePtr=head;
    while(nodePtr!=nullptr&&nodePtr->value!=num){
      previousNode=nodePtr;
      nodePtr=nodePtr->next;
    }
    if(nodePtr){
      previousNode->next=nodePtr->next;
      delete nodePtr;
    }
  }
}
void IntList::reverse(){
  ListNode *newHead=nullptr,*newNode,*nodePtr=head,*tempPtr;
  while(nodePtr){
    newNode=new ListNode;
    newNode->value=nodePtr->value;
    newNode->next=nullptr;
    if(newHead!=nullptr){
      tempPtr=newHead;
      newHead=newNode;
      newNode->next=tempPtr;
    }
    else{
      newHead=newNode;
    }
    nodePtr=nodePtr->next;
  }
  destroy();
  head=newHead;
}
void IntList::destroy(){
  ListNode *nodePtr,*nextNode=nullptr;
  nodePtr=head;
  while(nodePtr!=nullptr){
    nextNode=nodePtr->next;
    delete nodePtr;
    nodePtr=nextNode;
  }
  head=nullptr;
}
IntList::~IntList(){
  destroy();
}

void IntList::removeByPos(int pos){
  ListNode *p=head;
  if(p==nullptr) return;
  while(pos>0&&p){
    p=p->next;
    pos--;
  }
  if (p==head){
    head=head->next;
    delete p;
    return;
  }
  else{
    if(p==nullptr)return;
    ListNode *trailer=head;
    while(trailer->next !=p)
      trailer=trailer->next;
    trailer->next=p->next;
    delete p;
  }
}