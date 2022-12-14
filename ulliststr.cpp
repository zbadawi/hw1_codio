#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) //COMPLETED
{
  if (!head_){ //if no head and tail (first item), create new item for head
    head_ = new Item();
    tail_ = head_; //head and tail are same item
  }

  if (tail_->last != ARRSIZE) { //back of tail is not full
    tail_->val[tail_->last] = val;
    (tail_->last)++;
    } else{ //back of tail is full
      Item* newTail = new Item();
      tail_->next = newTail;
      newTail->prev = tail_;
      tail_ = newTail;
      tail_->val[(tail_->first)] = val;
      tail_->last++;
    }
  
  size_ ++; //increase size
}

void ULListStr::push_front(const std::string& val) //COMPLETED
{
  if (!head_){ //if no head and tail (first item), create new item for head
    head_ = new Item();
    tail_ = head_; //head and tail are same item
  }

 if ((head_->first) != 0) { //front of head is not full
  head_->val[(head_->first) -1] = val;
  head_->first--; //push first front
  } else{ //front of head is full
    Item* newHead = new Item();
    newHead->next = head_;
    head_->prev = newHead;
    head_ = newHead;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1; //correct placement for first member of new item
    head_->last = ARRSIZE; //correct placement for last element
  }
  
  size_ ++; //increase size
}

void ULListStr::pop_back()
{ //COMPLETED
  tail_->val[(tail_->last) -1] = "";
  (tail_->last)--;
  if ((tail_->last) == 0){ //if this is the last index of the array to be emptied, deallocate item
    Item* previous = tail_->prev;
    if (previous != nullptr){
      previous->next = nullptr;
    }
    tail_->prev = nullptr;
    delete tail_;
    tail_ = previous;
  }

  size_--; //decrease size
}

void ULListStr::pop_front()//COMPLETED
{
  // std::cout <<"popping: "  << head_->val[head_->first]; << endl; //comment out!!
  head_->val[head_->first] = "";
  (head_->first)++;
  if ((head_->first) == ARRSIZE){ //removed all the members of the array, deallocate item
    Item* nextN = head_->next;
    if ((head_->next) != nullptr){
      head_->next->prev = nullptr;
    }
    head_->next = nullptr;
    delete head_;
    head_ = nextN;
  } 

  size_--; //decrease size
}

const std::string& ULListStr::back() const //COMPLETED
{
  std::string* backTotal = &(tail_->val[(tail_->last) -1]); //deallocate?
  return *backTotal;
}

const std::string& ULListStr::front() const
{
  std::string* frontTotal = &(head_->val[(head_->first)]); //deallocate?
  return *frontTotal;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc>=size_ || loc<0){
    return nullptr;
  }

  size_t currentIndex = head_->first;
  Item* currentItem = head_;

  size_t count =0;
  
  while (count<size_){
    if (count == loc){
      std::string* valReturn = &(currentItem->val[currentIndex]);
      return valReturn;
    } else {
      count++;
      currentIndex++;
      if (currentIndex == ARRSIZE){
        currentIndex = currentItem->next->first;
        currentItem = currentItem->next;
      }
    }
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}