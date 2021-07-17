#include<cmath>
#include<climits>
// void findLargest(int **a, int m, int n)
// {
//     int i,j,idx1=0,idx2=0,row[m],col[n],row_max=INT_MIN,sum=0,col_max=INT_MIN;
//     if(m==0 && n==0){
//         cout<<"row"<<" "<<idx1<<" "<<row_max;
//     }
//     else{
//     for(i=0;i<m;i++){
//         sum=0;
//         for(j=0;j<n;j++){
//             sum+=a[i][j];
//         }
//         row[i]=sum;
//     }
//     for(i=0;i<n;i++){
//         sum=0;
//         for(j=0;j<m;j++){
//             sum+=a[j][i];
//         }
//         col[i]=sum;
//     }
//     row_max=row[0];
//     for(i=1;i<m;i++){
//         if(row[i]>row_max){
//             row_max=row[i];
//             idx1=i;
//         }
//     }
//     col_max=col[0];
//     for(i=1;i<n;i++){
//         if(col[i]>col_max){
//             col_max=col[i];
//             idx2=i;
//         }
//     }
//     if(row_max>col_max){
//         cout<<"row"<<" "<<idx1<<" "<<row_max;
//     }
//     else if(col_max>row_max){
//         cout<<"column"<<" "<<idx2<<" "<<col_max;
//     }else if(row_max==col_max){
//         cout<<"row"<<" "<<idx1<<" "<<row_max;
//     }
//     }
// }

void findLargest(int **a, int m, int n)
{
    int i,j,rowsum=0,rowmax=INT_MIN,colmax=INT_MIN,colsum=0,rowidx=0,colidx=0;
    if(m==0 && n==0){
        cout<<"row"<<" "<<rowidx<<" "<<rowmax;
        return;
    }
    else{
        for(i=0;i<m;i++){
            rowsum=0;
            for(j=0;j<n;j++){
                rowsum+=a[i][j];
            }
            if(rowsum>rowmax){
                rowmax=rowsum;
                rowidx=i;
            }
        }
        for(i=0;i<n;i++){
            colsum=0;
            for(j=0;j<m;j++){
            	colsum+=a[j][i];
            }
            if(colsum>colmax){
                colmax=colsum;
                colidx=i;
            }
        }
    }
    if(colmax>rowmax){
        cout<<"column"<<" "<<colidx<<" "<<colmax;
    }
    else if(rowmax>colmax){
        cout<<"row"<<" "<<rowidx<<" "<<rowmax;
    }
    else{
        cout<<"row"<<" "<<rowidx<<" "<<rowmax;
    }
}