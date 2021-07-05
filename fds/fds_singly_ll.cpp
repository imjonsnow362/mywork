//Create a Singly linked list for employee data and perform a. insertion b. deletion c. search d. modify
// program works and compiles succesfully 
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#define MAX 30

using namespace std;
// structure for declaring all the values 
struct empdata
{
    int  emp_no,emp_sal;
    char emp_name[MAX],emp_dept[MAX];
    struct empdata *next;
};
 
// insert details function
struct empdata *insert(struct empdata *head, int id,int salary, char name[],char dept[])
{
    struct empdata *newnode;
 
    newnode = (struct empdata*)malloc(sizeof(struct empdata));
 
    if (newnode == NULL)
    {
        cout<<"Allocation failed"<<endl;
        exit(2);
    }
    newnode->emp_no = id;
    newnode->emp_sal=salary;
    strcpy(newnode->emp_name, name);
    strcpy(newnode->emp_dept, dept);
    newnode->next = head;
    head = newnode;
    return(head);
}
// will print the details after input 
//this function will be used in delete function to show which node has been removed with details of the employee
//it will also be used in display function to display the details
void printNode(struct empdata *p)
{
    cout<<"Employee Details--"<<endl;
    cout<<"Employee ID--"<<p->emp_no<<endl;
    cout<<"Salary of the employee--"<<p->emp_sal<<endl;
    cout<<"Name of the employee--"<<p->emp_name<<endl;
    cout<<"Department of the employee--"<<p->emp_dept<<endl;   
}

// update details function
void updati(struct empdata *p,int key,char name[],char dept[]){
    struct empdata *ptr;
 
    for (ptr =p; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->emp_no == key)
        {
            int salry;
            cout<<"Enter salary--"<<endl;
            cin>>salry;
            cout<<"Enter Name--"<<endl;
            cin>>name;
            cout<<"eNTER Department"<<endl;
            cin>>dept;
             ptr->emp_sal=salry;
            strcpy(ptr->emp_name, name);
            strcpy(ptr->emp_dept, dept);
            return;
        }
    }
    cout<<"EMployee ID not found"<<key<<endl;
}
//delete details function
struct empdata* deleteemp(struct empdata *head, int id)
{
    struct empdata *ptr;
    struct empdata *bptr;
 
    if (head->emp_no == id)
    {
        ptr = head;
        cout<<"Node deleted"<<endl;
        printNode(head);
        head = head->next;
        free(ptr);
        return(head);
    }
    for (ptr = head->next, bptr = head; ptr != NULL; ptr = ptr->next,bptr = bptr->next)
    {
        if (ptr->emp_no == id)
        {
            cout<<"Node deleted"<<endl;
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(head);
        }
    }
    cout<<"Employee ID not found"<<id<<endl;
    return(head);
}
//search details function
void search(struct empdata *head, int key)
{
    struct empdata *ptr;
 
    for (ptr = head; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->emp_no == key)
        {
            cout<<"Found the data!!"<<endl;
            printNode(ptr);
            return;
        }
    }
    cout<<"EMployee ID not found"<<key<<endl;
}
//display details function
void display(struct empdata  *head)
{
    struct empdata *ptr;
 
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}

void menu()
{
    
    cout<<"Press 1 for Insert"<<endl;
    cout<<"Press 2 for Delete"<<endl;
    cout<<"Press 3 for Display"<<endl;
    cout<<"Press 4 for Search"<<endl;
    cout<<"Press 5 for Update"<<endl;
    cout<<"Press 6 for EXIT"<<endl;
}

char option()
{
    char choice;
    cout<<"ENter the choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':   return(choice);
        default :   cout<<"Wrong choice!"<<endl;
    }
    return choice;
}

int main()
{
    struct empdata *linkList;
    char name[21], department[51];
    char choice;
    int empnumber,salry;
 
    linkList = NULL;
    cout<<"Singly Linked List---"<<endl;
    menu();
    do
    {
        /*  choose oeration to be performed */
        choice = option();
        switch(choice)
        {
        case '1':
            cout<<"Enter Emp ID"<<endl;
            cin>>empnumber;
            cout<<"ENter salary--"<<endl;
            cin>>salry;
            cout<<"Enter Name--"<<endl;
            cin>>name;
            cout<<"eNTER Department"<<endl;
            cin>>department;
            linkList = insert(linkList, empnumber, salry , name, department);
            break;
        case '2':
            cout<<"Enter employee ID to be deleted"<<endl;
            cin>>empnumber;
            linkList = deleteemp(linkList, empnumber);
            break;
        case '3':
            if (linkList == NULL)
            {
                cout<<"List empty"<<endl;
                break;
            }
            display(linkList);
            break;
        case '4':
            cout<<"Enter emp ID to be searched"<<endl;
            cin>>empnumber;
            search(linkList, empnumber);
            break;
        case '5':
            cout<<"Enter the emp ID to be updated"<<endl;
            cin>>empnumber;
            updati(linkList, empnumber,name,department);
            break;
        }
    } while (choice != '5');
}




