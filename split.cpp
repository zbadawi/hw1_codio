/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
Node* helper (Node* in, Node* odds, Node* evens);

void split(Node*& in, Node*& odds, Node*& evens)
{


  // Node* startE = evens;
  // Node* startO = odds;




helper (in, odds, evens);

//repurposed to helper function

// if (in == nullptr){
//   return;
// }

// if (in->value %2 ==0){
//   evens = in; //is this correct with pointers
// } else {
//   odds = in; //is this correct with pointers
// }

// if (in->next){
//   if (in->next->value %2 ==0) {
//     if (evens) {
//       evens->next = split(in->next, odds, evens->next);
//     } else {
//       evens = split(in->next, odds, evens);
//     }
//   } else {
//     if (odds) {
//       odds->next = split(in->next, odds->next, evens);
//     } else {
//       odds = split(in->next, odds, evens);
//     }
//   }

//   return in;
// }

// evens->next = helper(in->next, odds, evens);
// odds->next = helper(in->next, odds, evens);


// //#1

// if (in == nullptr){
//   return;
// } else {
//   Node* temp = in; //is this right?
//   if (temp->value %2 ==0) { //if even
//     if (evens == nullptr){ //checks if evens is empty
//       evens = temp;
//       startE = evens; //is this necessary?
//       //IMPLEMENT remove node from in
//     } else {
//       startE->next = temp; //adding in to list of evens
//       startE = startE->next; //updating the start of list: is this right?
//       //IMPLEMENT remove node from in
//     }
// } else { //if odd
//     if (odds == nullptr){ //checks if odds is empty
//       odds = temp;
//       startO = odds; //is this necessary?
//       //IMPLEMENT remove node from in
//     } else {
//       startO->next = temp; //adding in to the list of odds
//       startO = startO->next; //updating the start of list: is this right
//       //IMPLEMENT remove node from in
//     }
//   }

//   split (in->next, odds, evens);
// }

// //#2

//   if (in->next == nullptr){
//     if (in->value %2 ==0) { //if even
//       if (evens == nullptr){ //checks if evens is empty
//         evens = in;
//         startE = in;
//         //IMPLEMENT remove node from in
//       } else {
//         startE->next = in; //adding in to list of evens
//         startE = in; //updating the start of list: is this right?
//         //IMPLEMENT remove node from in
//       }
//     } else { //if odd
//       if (odds == nullptr){ //checks if odds is empty
//         odds = in;
//         startO = in;
//         //IMPLEMENT remove node from in
//       } else {
//         startO->next = in; //adding in to the list of odds
//         startO = in; //updating the start of list: is this right
//       //IMPLEMENT remove node from in
//       }
//     }
//   } else {
//     split (in->next, odds, evens);
//   }
}

/* If you needed a helper function, write it here */
Node* helper (Node* in, Node* odds, Node* evens){
  if (in == nullptr){
    return nullptr;
  } else if (in->value %2){
    odds = in;
    return helper (in->next, in->next, evens);
  } else {
    evens = in;
    return helper(in->next, odds, in->next);
  }

  if (in->value %2 ==0){
    evens = in; //is this correct with pointers
  } else {
    odds = in; //is this correct with pointers
  }

  if (in->next != nullptr){
    if (in->next->value %2 ==0) {
      if (evens) {
        evens->next = helper(in->next, odds, evens->next);
      } else {
        evens = helper(in->next, odds, evens);
      }
    } else {
      if (odds) {
        odds->next = helper(in->next, odds->next, evens);
      } else {
        odds = helper(in->next, odds, evens);
      }
    }

    return in;
  }

  // evens->next = helper (in->next, odds, evens);
  // odds->next = helper (in->next, odds, evens);
}