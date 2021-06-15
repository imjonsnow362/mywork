//only transpose part is to be fixed rest of the program works 
#include <iostream>
#include<math.h>
using namespace std;
int main(){
    int m1[3][3],i,j,k=0,c=0;
    cout << "Enter the matrix elements"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>m1[i][j];
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(m1[i][j]!=0)
            {
                c++;
            }
        }
    }
    int m2[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3; j++)
        {
            if(m1[i][j]!=0)
    {
        m2[0][j]=i;
        m2[1][k]=j;
        m2[2][k]=m1[i][j];
        k++;
    }
        }
    }
    cout << "FOr sparse matrix representation"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<c;j++)
        {
            cout<<m2[i][j]<<"";
        }
        cout<<endl;
    }
}
    void transpose(){
        for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
       transpose[i][j] = m2[j][i];
    }
}
}

}
        










