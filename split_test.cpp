#include "split.h"
#include <iostream>
#include <fstream>
using namespace std;

int main () {
//    ifstream input("input.txt");
//    input.open("input.txt");
//    char c;

//    Node* head = nullptr;

//    while (input.get(c)){
//     Node* test = new Node(c, nullptr);

//     if (head == nullptr){
//         head = test;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr){
//             temp = temp->next;
//         }
//         temp->next = test;
//     }
//    }


Node* eight = new Node(28, nullptr);
Node* seven= new Node(19, eight);
Node* six= new Node(16, seven);
Node* five= new Node(14, six);
Node* four= new Node(7, five);
Node* three= new Node(6, four);
Node* two= new Node(3, three);
Node* head= new Node(1, two);

   Node* evens = nullptr;
   Node* odds = nullptr;

   split(head, odds, evens);

   while (evens != nullptr){
    cout << evens->value;
    cout << " ";
    evens = evens->next;
   }

   while (odds->next != nullptr){
    cout << odds->value;
    cout << " ";
    odds = odds->next;
   }

   if(!head){
    while (head != nullptr) {
        cout << head->value;
        cout << " ";
        head = head->next;
    }
   }

   return 0;
}