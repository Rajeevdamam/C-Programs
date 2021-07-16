// Online C++ compiler to run C++ program online

// Write a program to read 2D array as input which contains only unique elements, then replace max element’s position with min element’s position.
// Input :
// 1 2 3
// 4 5 6
// 7 8 9
// Output :
// 9 2 3
// 4 5 6
// 7 8 1


#include <iostream>
#include <climits>
using namespace std;

int **maxAndMinOfArray(int **a,int rows,int columns){
    int min=INT_MAX,max=INT_MIN,minRow,minCol,maxRow,maxCol;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(a[i][j]<min){
                min=a[i][j];
                minRow=i;
                minCol=j;
            }
            if(a[i][j]>max){
                max=a[i][j];
                maxRow=i;
                maxCol=j;
            }
        }
    }
    a[maxRow][maxCol]=min;
    a[minRow][minCol]=max;
    
    return a;
}

int main3() {
    int rows,columns;
    cout<<"enter number of rows and coulmns:"<<endl;
    cin>>rows>>columns;
    int **array=new int*[rows];
    cout<<"enter elements of 2D array:"<<endl;
    for(int i=0;i<rows;i++){
        array[i]=new int[columns];
        for(int j=0;j<columns;j++){
            cin>>array[i][j];
        }
    }
    int **output=new int*[rows];
    for(int i=0;i<columns;i++){
        output[i]=new int[columns];
    }
    output=maxAndMinOfArray(array,rows,columns);
    cout<<"Resultant array:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}