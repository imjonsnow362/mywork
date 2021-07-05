//Pizza parlor accepting maximum n orders. Orders are served in FCFS basis. Order once placed can’t be cancelled. Write C++ program to simulate the system using circular Queue. 
#include<iostream>
using namespace std;
const int maximumord=5;

class pizza
{
    int front,rear;
    int pizzaorder[maximumord];
    public:
            pizza()
            {
                front=rear=-1;
            }
            int itisfull()
            {
                if((front==0&&rear==4)||(rear+1==front))
                {
                    return 1;  
                }
                else
                {
                    return 0;   
                }
                
            }
            int itisempty()
            {
                if(front==-1&&rear==-1)
                {
                    return 1;
                }
                else 
                {
                    return 0;    
                }
                
            }
void addorder(int item)
{
    if(itisfull()==1)
    cout<<"!!! NO MORE ORDERS WE ARE FULL!!!!"<<endl;
    else
    {
        if(front==-1)
        {
            front=rear=0;
        }
        else 
        {
            rear=(rear+1)%maximumord;
        }
        pizzaorder[rear]=item;
    }
}
void serve(int nofpizzasiwant)
{
    int item;
    char ans;
    int n;
    if(itisempty()==1)
    cout<<"!!! SORRY THERE ARE NO ORDERS!!!"<<endl;
    else 
    cout<<"!!! ORDERS THAT ARE GOING TO BE DELIVERED!!!"<<endl;
    for(int i=0;i<n;i++)
    {
        item=pizzaorder[front];
        if(front=rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%maximumord;
        }
        cout<<"\t"<<item;
    }
    cout<<"!!! AMOUNT TO PAY---"<<n*100;
    cout<<"!! THANK YOU !!"<<endl;
}
void checkanddsiplay()
    {
        int temp;
        if(itisempty())
        {
            cout<<"!!! NO PENDING ORDERS !!!"<<endl;
        }
        else 
        {
            temp=front;
            cout<<"!! PENDING ORDER--- !!!!"<<endl;
            while(temp!=rear)
            {
                cout<<"\t"<<pizzaorder[temp];
                temp=(temp+1)%maximumord;
            }
            cout<<"\t"<<pizzaorder[temp];
        }
    }
};
    int main()
    {
        pizza first;
        int choice,thepizzaiwant,nofpizzasiwant;
        do
        {
            cout<<"!!WELCOME TO SWIGGY!!"<<endl;
            cout<<"ENTER YOUR CHOICE--1.ORDER PIZZA 2.RECEIVE AND PAY 3.CHECK ORDERS"<<endl;
            cin>>choice;
            switch(choice)
            {
                case 1:
                        cout<<"THIS IS THE PIZZAS WE SERVE"<<endl;
                        cout<<"\tPepperoni Pizza \tCheese Pizza  \tChicken Pizza  \tMushroom Pizza"<<endl;
                        cin>>thepizzaiwant;
                        first.addorder(thepizzaiwant);
                        break;
                case 2:
                        cout<<"HOW MANY PIZZAS DO YOU WANT!!!"<<endl;
                        cin>>nofpizzasiwant;
                        first.serve(nofpizzasiwant);
                        break;
                case 3:
                        cout<<"ORDER LIST PENDING AND TO BE DELIVERED--"<<endl;
                        first.checkanddsiplay();
                        break;
            }
        }
            while(choice!=4);
            return 0;
    }
