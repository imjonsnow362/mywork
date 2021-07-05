//Implement stack for expression conversion (infix to postfix) 
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<cstring>
using namespace std;

char infix[20],postfix[20];
int front;
int stack[200];

int pop();
int precede(char sym);
int itisempty();
void func_inftopostf();
int check(char sym);
void push(long int sym);

int main()
{
    int count,length;
    char temp;
    front=-1;
    cout<<"INPUT EXPRESSION (INFIX)"<<endl;
    cin>>infix;
    func_inftopostf();
    cout<<"POSTFIX EXPRESSION FOR THIS--"<<endl;
    return 0;
}
void func_inftopostf()
{
    unsigned int count,temp=0;
    char next;
    char sym;
    for(count=0; count<strlen(infix); count++)
    {
        sym=infix[count];
        if(!check(sym));
        {
            switch(sym)
            {
                case '(': push(sym);
                break;
                case ')':
                while((next = pop()) != '(')
                {
                    postfix[temp++]=next;
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                while(!itisempty()&& precede(stack[front])>=precede(sym))
                postfix[temp++] = pop();
                push(sym);
                break;
                default:
                        postfix[temp++] = sym;
            }
        }
    }
    while(itisempty())
    {
        postfix[temp++]=pop();
    }
        postfix[temp]='\0';
    }


int precede(char sym)
{
    switch(sym)
    {
        case '(': return 0;
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

int check(char sym)
{
    if(sym == '\t' || sym == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(long int sym)
{
    if(front > 20)
    {
        cout<<"OVERFLOW!!"<<endl;
        exit(1);
    }
    front = front +1;
    stack[front] = sym;
}

int itisempty()
{
    if(front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if(itisempty())
    {
        cout<<"EMPTY STACK!!"<<endl;
        exit(1);
    }
    return(stack[front--]);
}



