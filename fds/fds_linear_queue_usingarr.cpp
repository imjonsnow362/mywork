//Implement Linear queue using array
//working code 
//using switch case to input choice instead of invoking function in the int main
#include <iostream>
using namespace std;
int queue[100], n = 50, front = - 1, rear = - 1;
// to insert function at the rear 
void enqueue() {
   int value;
   //to check if the queue is full ro not 
   if (rear == n - 1)
   cout<<"queue is full"<<endl;
   //insert element 
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert element-- "<<endl;
      cin>>value;
      rear++;
      queue[rear] = value;
   }
}
//to delete the element from the front 
void dequeue() {
  //to check if queue is full or not 
  if (front == - 1 || front > rear) {
      cout<<"queue is not full ";
      return ;
   } else {
      cout<<"Deleted element is  --"<< queue[front] <<endl;
      front++;;
   }
}
void display() {
   if (front == - 1)
   cout<<"EMpty queue--"<<endl;
   else {
      //displaying elements in one row like a queue
      cout<<"the elements are-- ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int choice;
   cout<<"1) INSERT element"<<endl;
   cout<<"2) DELETE element"<<endl;
   cout<<"3) DISPLAY elements"<<endl;
   cout<<"4) EXIT"<<endl;
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
         default: cout<<"Wrong choice"<<endl;
      }
   } while(choice!=4);
   return 0;
}



