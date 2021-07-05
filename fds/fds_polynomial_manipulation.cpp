//Implement polynomial using Doubly Linked List and perform  Addition/ Multiplication of Polynomials
//working program 
#include <iostream>
using namespace std;

typedef struct node
{
    int coef;
    int power;
    struct node *next;
    struct node *prev;
}node;
node* createnewnode(int c, int p)
{
    node *t = new node();
    t->coef = c;
    t->power =p;
    t->next=0;
    t->prev=0;
    return t;
}

node* read(node *head, node*term)
{
    if(head==0)
    {
        return term;
    }
    else
    {
        node *temp=head;
        while(temp->next !=0)
            temp = temp->next;
        temp->next = term;
        term->prev=temp;
        return head;
    }
}
void print(node *temp)
{

    while(temp->next!=0)
    {
        cout<<temp->coef<<"x^"<<temp->power<<"+";
        temp=temp->next;
    }
    cout<<temp->coef<<"x^"<<temp->power<<endl;
    cout<<endl;
}
node *addition(node *p1,node *p2)
{
	node *ptr1=p1, *ptr2=p2 , *poly_add=0;
	int coef,power;
	while(ptr1!=0 && ptr2!=0)
	{
		if(p1->power==p2->power)
		{
			power=p1->power;
			coef=p1->coef+p2->coef;
			poly_add=read(poly_add,createnewnode(coef,power));
			p1=p1->next;
			p2=p2->next;
			ptr1=p1;
			ptr2=p2;
		}
		else if(p1->power > p2->power)
		{
			power=p1->power;
			coef=p1->coef;
			poly_add=read(poly_add,createnewnode(coef,power));
			p1=p1->next;
			ptr1=p1;
		}
		else
		{
			power=p2->power;
			coef=p2->coef;
			poly_add=read(poly_add,createnewnode(coef,power));
			p2=p2->next;
			ptr2=p2;
		}
	}
	while(ptr1!=0)
	{
		power=p1->power;
		coef=p1->coef;
		poly_add=read(poly_add,createnewnode(coef,power));
		p1=p1->next;
		ptr1=p1;
	}
	while(ptr2!=0)
	{
		power=p2->power;
		coef=p2->coef;
		poly_add=read(poly_add,createnewnode(coef,power));
		p2=p2->next;
		ptr2=p2;
	}
		return poly_add;
}
node *multiplication(node *p1,node *p2)
{
	node *ptr1 =p1 ,*ptr2=p2;
	node *poly_mul=0;
	while(ptr1!=0)
	{
		while(ptr2!=0)
		{
			int coef,power;
			coef=ptr1->coef*ptr2->coef;
			power=ptr1->power+ptr2->power;
			poly_mul=read(poly_mul,createnewnode(coef,power));
			ptr2=ptr2->next;
		}
		ptr2=p2;
		ptr1=ptr1->next;
	}
	return(poly_mul);
}
node* insertcoeff(node* first)
{
    node *ptr1, *ptr2, *temp;
    ptr1 = first;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {

            if (ptr1->power == ptr2->next->power) {

                ptr1->coef = ptr1->coef + ptr2->next->coef;
                temp = ptr2->next;
                ptr2->next = ptr2->next->next;
                ptr2->next->prev= ptr2;

                delete (temp);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return first;
}
int main()
{
	int k=0,p,c;
	node *poly1=0;
	node *poly2=0;
	node *poly_mul=0;
	node *poly_add=0;
	cout<<"Enter Power and Coefficient for First equation --\n\n";
	do
	{
		cout<<"Enter power --";
		cin>>p;
		cout<<"Enter coefficient-- ";
		cin>>c;
		poly1=read(poly1,createnewnode(c,p));
		cout<<"Press 1 if you want to add more coefficient and power to equation --";
		cin>>k;
	}while(k==1);
	cout<<"Enter Power and Coefficient for Second equation --\n\n";
	do
	{
		cout<<"Enter power --";
		cin>>p;
		cout<<"Enter coefficient-- ";
		cin>>c;
		poly2=read(poly2,createnewnode(c,p));
		cout<<"Press 1 to insert more coeffs --";
		cin>>k;
	}while(k==1);
	cout<<"\n";
	cout<<"First equation  is-- ";
	print(poly1);
	cout<<"\n";
	cout<<"Second equation is-- ";
	print(poly2);
	cout<<"\n";
	poly_add=addition(poly1,poly2);
	cout<<"Addition is-"<<endl;
	print(poly_add);
	poly_mul=multiplication(poly1,poly2);
	print(poly_mul);
	poly_mul = insertcoeff(poly_mul);
    cout<<"Multiplication is--\n\n";
    print(poly_mul);
	return 0;
}

