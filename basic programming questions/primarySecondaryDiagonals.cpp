// Question 3
// Create a matrix of order 3*3 and return the average of odd numbers present in both primary and secondary diagonals of the matrix. 
// Example:
// Input:
// 1 2 4
// 3 5 6
// 7 8 9
// Output:
// Primary diagonal odd numbers average: (1 + 5 + 9) / 3 = 5
// Secondary diagonal odd numbers average: (5 + 7) /2 = 6


/*
psuedo code
1. take a 2d array input from the user.
2. write a function to find primary diagonals by traversing dialgonally from initial points of both rows and columns and return the average of odd numbers
3. write a function to find secondary diagonals by traversing reverse dialgonally from points of both rows and columns and return the average of odd numbers
4. print the results

*/

#include<iostream>

using namespace std;

int primaryDiagonals(int **input,int rows,int columns){
    int count=0,sum_of_odd=0,i=0,j=0;
    while(i<rows && j<columns){
        if(input[i][j]%2!=0){
            sum_of_odd+=input[i][j];
            count++;
        }
        i++;j++;
    }
    int result=sum_of_odd/count;
    return result;
}

int secondaryDiagonals(int **input,int rows,int columns){
    int count=0,sum_of_odd=0,i=0,j=columns-1;
    while(i<rows && j>=0){
        if(input[i][j]%2!=0){
            sum_of_odd+=input[i][j];
            count++;
        }
        i++;
        j--;
    }
    int result=sum_of_odd/count;
    return result;
}

int main(){
    int rows=0,columns=0;
    cout<<"Enter the number of rows and columns in matrix"<<endl;
    cin>>rows;
    cin>>columns;
    int **input=new int*[rows];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<rows;i++){
        input[i]=new int[columns];
        for(int j=0;j<columns;j++){
            cin>>input[i][j];
        }
    }
    int primaryDiagonalAns=primaryDiagonals(input,rows,columns);
    int secondaryDiagonalAns=secondaryDiagonals(input,rows,columns);
    cout<<"Primary Diagonals:"<<primaryDiagonalAns<<endl;
    cout<<"Secondary Diagonals:"<<secondaryDiagonalAns<<endl;
    for(int i=0;i<rows;i++){
        delete input[i];
    }
    delete []input;
    return 0;
}