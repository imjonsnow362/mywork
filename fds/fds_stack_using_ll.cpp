//
//Perform implementation of STACK using Linked List

//a. Push an element on to stack

//b. Pop an element

//c. Demonstrate overflow simulations on stack

//d. Display stack
//working code 
#include<iostream>
using namespace std;
//defining struct for node 
struct node
{
    int data;
    node *next;
};
//the class
class stack 
{
    node *top;
    public : 
            stack();
            bool itisempty();
            void push(int value);
            void pop();
            void display();
};

stack::stack()
{
    top=NULL;
}
//defining the push function 
void stack::push(int value)
{
    node *ptr=new node();
    cout<<"Enter the no you want to insert"<<endl;
    cin>>value;
    ptr->data=value;
    ptr->next=top;
    top=ptr;
}
//defining empty function
bool stack::itisempty()
{
    if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//defining pop function to remove the element
void stack::pop()
{
    if(itisempty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        struct node *temp=top;
        top=top->next;
        delete(temp);
    }
}
//defining dispkay function here..
void stack::display()
{
    if(itisempty())
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        cout<<top->data;
    }
}

int main()
{
    stack object;
    int ch;
    int value;
    do{
        cout<<"Choose!!"<<endl;
        cout<<"\n1.PUSH  \n2.POP  \n3.DISPLAY"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                    object.push(value);
                    cout<<"PUSHED ELEMENT IN THE STACK ARE----"<<endl;
                    break;
            case 2:
                    object.pop();
                    cout<<"ELEMENT POPPED---"<<endl;
                    break;
            case 3:
                    cout<<"DISPLAY--"<<endl;
                    object.display();
                    cout<<"\n";
                    break;
            default:
                    cout<<"WRONG CHOICE!!!"<<endl;
        }
    }while(ch!=4);
}
