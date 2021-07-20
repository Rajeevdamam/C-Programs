// void spiralPrint(int **input, int nRows, int nCols)
// {
//     int rowStart = 0, rowEnd = nRows-1, colStart = 0, colEnd = nCols-1, count=0;
//     while(count != (nRows*nCols)){
//         for(int i=colStart; i<=colEnd;i++){
//             cout<<input[rowStart][i]<<" ";
//             count++;
//         }
//         rowStart++;
//         for(int i=rowStart; i<=rowEnd;i++){
//             cout<<input[i][colEnd]<<" ";
//             count++;
//         }
//         colEnd--;
//         for(int i=colEnd; i>=colStart;i--){
//             cout<<input[rowEnd][i]<<" ";
//             count++;
//         }
//         rowEnd--;
//         for(int i=rowEnd; i>=rowStart;i--){
//             cout<<input[i][colStart]<<" ";
//             count++;
//         }
//         colStart++;
//     }
// }



void spiralPrint(int **input, int nRows, int nCols)
{
    int rowStart=0,rowEnd=nRows-1,colStart=0,colEnd=nCols-1,count=0,totalElements=nRows*nCols;
    
    while(count<totalElements){
        for(int i=colStart;i<=colEnd;i++){
            cout<<input[rowStart][i]<<" ";
            count++;
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++){
            cout<<input[i][colEnd]<<" ";
            count++;
        }
        colEnd--;
        for(int i=colEnd;i>=colStart;i--){
            cout<<input[rowEnd][i]<<" ";
            count++;
        }
        rowEnd--;
        for(int i=rowEnd;i>=rowStart;i--){
            cout<<input[i][colStart]<<" ";
            count++;
        }
        colStart++;
    }
}


