//working program 
#include <iostream>
using namespace std;
struct node {
   int info;
   struct node *ptr;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
//enqueue using ll func
void enqueue() {
   int number;
   cout<<"Insert your number-- "<<endl;
   cin>>number;
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->ptr = NULL;
      rear->info = number;
      front = rear;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      rear->ptr = temp;
      temp->info = number;
      temp->ptr = NULL;
      rear = temp;
   }
}
//dequeue using ll func
void dequeue() {
   temp = front;
   if (front == NULL) {
      cout<<"Error!! queue is empty"<<endl;
      return;
   }
   else
   if (temp->ptr != NULL) {
      temp = temp->ptr;
      cout<<"Dequed value is --- "<<front->info<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Dequed value is--- "<<front->info<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
//displaying using ll func
void display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"EMpty queue!!!"<<endl;
      return;
   }
   cout<<"Elements ---- ";
   while (temp != NULL) {
      cout<<temp->info<<" ";
      temp = temp->ptr;
   }
   cout<<endl;
}
//using switch case to input choice and data you want to insert
int main() {
   int choice;
   cout<<"Press 1 for Enqueue"<<endl;
   cout<<"Press 2 for Dequeue"<<endl;
   cout<<"Press 3 for Displaying"<<endl;
   cout<<"Press 4 Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>choice;
      switch (choice) {
         case 1: enqueue();
                 break;
         case 2: dequeue();
                 break;
         case 3: display();
                 break;
         case 4: cout<<"Exit"<<endl;
                 break;
         default: cout<<"Wrong choice!!!"<<endl;
      }
   } while(choice!=4);
   return 0;
}
