//Perform following string operations with and without  pointers: 1. Length 2. Copy 3.Concat 4. Compare 5.Reverse.
//program is compiling 
#include<iostream>
using namespace std;
//we will use seperate function for pointer and without pointer
int length(char string[])
{
    //position in the beginning ↓
    int lengthofthestring=0;
    for(int i=0;string[i]!='\0';i++)  //count loop basic
    {
        lengthofthestring++;
    }
    cout<<"\n Length of the string - "<<lengthofthestring;
}
int length2(char* string)
{
    //position in the beginning ↓
    int lengthofthestring1=0;
    while(*string!='\0'){           //count loop basic using while format 
        lengthofthestring1++;
        string++;
    }
   cout<<"\n Length of the string with pointer is-"<<lengthofthestring1;
}
string copyfunc(char string[]){
    char c[length(string)];
    //position in the beginning ↓
    int i=0;
    for(i=0;string[i]!='\0';i++)     //count loop 
    {
        c[i]=string[i];             //assigning
    }
    c[i]='\0';
    cout<<"Copied string is-"<<c;
}
string copyfunc1(char* string){
    char c[length(string)];
    char* ptr1;                 //assigning pointers 
    char* ptr2;
    ptr1=string;                    
    ptr2=c;                     
    while(*ptr1!='\0'){
        *ptr2=*ptr1;
        ptr1++;                 //loop
        ptr2++;
    }
    *ptr2='\0';
    cout<<"Copied string with pointer is-"<<ptr2;
}
string concatfunc(char string[],char string1[]){
    char c[length(string)+length(string1)+1];       //add text
    //position in the beginning ↓
    int i=0,j=0;
    while(string[i]!='\0'){
        c[j]=string[i];
        i++;
        j++;
    }
    //position in the beginning ↓
    i=0;    
    while(string1[i]!='\0'){
        c[j]=string1[i];
        i++;
        j++;
    }
    c[j]='\0';
    cout<<"COncatenated part is --"<<c;
}
string concatfunc1(char* string,char* string1)
{
    char c[length(string)+length(string1)+1];
    char* ptr=string;
    char*  ptr1=string1;
    int i=0;
    while(*ptr!='\0'){
        c[i]=*ptr;
        ptr++;
        i++;
    }
    while(*ptr1!='\0'){
        c[i]=*ptr1;
        i++;
        ptr1++;
    }
    c[i]='\0';
    cout<<"Concatenated part with pointer is--"<<c;
}
string reversefunc(char string[40],char string1[40])
   {
     //position in the beginning ↓
     int i=0,j;
      
      while(string[i]!='\0')
      {
          i++;
      }
      for(j=0;j<i;j++)                      
      {
        string1[j]=string[i-j-1];       //reversing the string
      }
      string1[j]='\0';
       cout<<"\n Reversed string:"<<string1;
}
string reversefunc1(char* string1)
{
    char c[length(string1)+1];
    char* ptr=string1;
    int i=length(string1);
    c[i]='\0';
    i--;
    while(*ptr!='\0'){
        c[i]=*ptr;
        ptr++;
        i--;
    }
    cout<<"Reverse of the string with pointer is-"<<c;
}
void compare(char string[40],char string1[40])
   {
    //position in the beginning ↓
    int i=0,count=0;
    for(i=0;string[i]!='\0' || string1[i]!='\0';i++){
    if(string[i]>string1[i])
    {
        cout<<string<<" Is Greater than "<<string1<<endl;
        count++;
        break;
    }
    else if(string[i]<string1[i]){
        cout<<string<<" Is Smaller than "<<string1<<endl;
        count++;
        break;
        }
    }
    if(count==0){
        cout<<string<<" Is Equal to "<<string1<<endl;
        }
    }
int main()
{
    //it will print all the answrs using function call
    //using do while loop to accept choice of the user and continue if required
    char string[40],string1[40],c;
    int choice;
    do
    {
      cout<<" string operations:\n 1.Length\n 2.Copy\n 3.Concatenate \n 4.Reverse \n 5.Compare \n Enter your choice";
      cin>>choice;
      switch(choice)
      {
        case 1:
            cout<<"\nEnter String:";
            cin>>string;
            cout<<"\n Length:"<<length(string);
            break;
        case 2:
            cout<<"\n Enter string:";
            cin>>string;
            copyfunc(string);
            
            break;
        case 3:
             cout<<"\n Enter strings:";
             cin>>string;
             cout<<"\n Enter another string:";
             cin>>string1;
             concatfunc(string,string1);
             cout<<string;
             break;
        case 4:
            cout<<"\n Enter string:";
            cin>>string;
            reversefunc(string,string1);
           
            break;
        case 5:
            cout<<"\n Enter string:";
            cin>>string;
            cout<<"\n Enter another string:";
            cin>>string1;
            compare(string,string1);
            break;
      }cout<<"\n Do you want to continue(y/n)"<<endl;
      cin>>c;
    }while(c=='y'||c=='Y');
    return 0;
}




