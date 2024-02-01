//
//  main.c
//  merge_sort
//
//  Created by melih can durmaz on 10.01.2024.
//

#include<stdio.h>
#include<stdlib.h>


void merge(int A[], int l, int mid, int h){
    int B[100],i,j,k;
    i = l;
    j = mid+1;
    k = i;
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    for(;i<=mid;i++)
    {
        B[k++] = A[i];
    }
    for(;j<=h;j++)
    {
        B[k++] = A[j];
    }
    for(int i=l;i<=h;i++)
    {
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n)
{
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
}



int main(void)
{
    
    
    int A[5] = {55,43,77,99,11};
        int i;
        IMergeSort(A,5);
        for(i=0;i<5;i++)
        {
            printf("%d ",A[i]);
        }
    
    return 0;
}
