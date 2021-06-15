#include<iostream>
using namespace std;

struct student
{
    char name[50];
    int rollno;
    int delete;
    int search;
    float marks;
    char grade[5];
} classroom[10];

int main()
{
    //add record
    cout<<"Enter information of students--" <<endl;
    //using for loop to store record of 10 students 
    for(int i=0;i<10;++i)
    {
        classroom[i].rollno = i +1;
        cout << "For roll number" << classroom[i].rollno << "," << endl;
        
        cout<<"Enter name of the student-";
        cin >> classroom[i].name;
        
        cout<<"Enter roll number of the student-";
        cin>>classroom[i].rollno;
        
        cout<<"Enter marks of the student";
        cin>>classroom[i].marks;
        
        cout<<"Enter grade of the student";
        cin>>classroom[i].grade;
        
        cout<< endl;
    }
    //display database
    cout << "Displaying Database" <<endl;
    //using for loop again with same values 
    for(int i=0; i<10; ++i)
    {
        cout << "Name -" << classroom[i].name << endl;
        cout << "Roll no-" << classroom[i].rollno << endl;
        cout << "Marks--" << classroom[i].marks << endl;
        cout << "Grade--" << classroom[i].grade << endl;
    }
    //search record
    cout << "Enter roll number , name , marks or grade to search"<<endl;
    cin>>search;
    for(int i=0; i<10; ++i)
     if(search==classroom[i].name){
        if(i<10)
        cout<< "Name found"<<endl; 
     }
     else {
     cout << "Name not found"<<endl;
     }
}
    else {
        if(search==classroom[i].rollno){
        if(i<10)
        cout<< "Roll no found"<<endl; 
     }
     else {
     cout << "Roll number not found"<<endl;
     }
    }
    else{
         if(search==classroom[i].marks){
        if(i<10)
        cout<< "Marks found"<<endl; 
     }
     else {
     cout << "Marks not found"<<endl;
     }
    }
    else{
         if(search==classroom[i].grade){
        if(i<10)
        cout<< "Grade-- found"<<endl; 
     }
     else {
     cout << "Grade not found"<<endl;
     }
    }
     
     
    
     //delete record 
    cout<<"Enter element to be delete : ";
	cin>>delete;
	for(int i=0; i<10; i++)
	{
	    switch (ch)
	    {
	        case 1:if(classroom[i].name==del)
		{
			for(int j=i; j<(10-1); j++)
			{
				arr[j]=arr[j+1];
			}
			count++;
			break;
		}
	}
	if(count==0)
	{
		cout<<"Element not found..!!";
	}
	else
	{
		cout<<"Item deleted from the record"<<endl;
		cout<<"Now the new array is :"<<endl;
		for(i=0; i<(10-1); i++)
		{
			cout<<classroom[i].name<<" ";
		}
	}
	    case 2: if(classroom[i].rollno==del)
		{
			for(int j=i; j<(10-1); j++)
			{
				arr[j]=arr[j+1];
			}
			count++;
			break;
		}
	}
	if(count==0)
	{
		cout<<"Element not found..!!";
	}
	else
	{
		cout<<"Item deleted from the record"<<endl;
		cout<<"Now the new array is :"<<endl;
		for(i=0; i<(10-1); i++)
		{
			cout<<classroom[i].rollno<<" ";
		}
	}
	    case 3:if(classroom[i].marks==del)
		{
			for(int j=i; j<(10-1); j++)
			{
				arr[j]=arr[j+1];
			}
			count++;
			break;
		}
	}
	if(count==0)
	{
		cout<<"Element not found..!!";
	}
	else
	{
		cout<<"Item deleted from the record"<<endl;
		cout<<"Now the new array is :"<<endl;
		for(i=0; i<(10-1); i++)
		{
			cout<<classroom[i].marks<<" ";
		}
	}
	    case 4: if(classroom[i].grade==del)
		{
			for(int j=i; j<(10-1); j++)
			{
				arr[j]=arr[j+1];
			}
			count++;
			break;
		}
	}
	if(count==0)
	{
		cout<<"Element not found..!!";
	}
	else
	{
		cout<<"Item deleted from the record"<<endl;
		cout<<"Now the new array is :"<<endl;
		for(i=0; i<(10-1); i++)
		{
			cout<<classroom[i].grade<<" ";
		}
	}
	    }
		
}
} 
}




