#include<stdio.h>


void CountSort(int *A,int n)
{
    int maxValue=A[0];
    for(int i=0;i<n;i++)
        maxValue = (maxValue>A[i])?(maxValue):A[i];

    int B[maxValue+1];
    for(int i=0;i<maxValue+1;i++)
        B[i]=0;

    for(int i=0;i<n;i++)
        B[A[i]]++;

    int C[maxValue+1];
    C[0]=B[0];
    for(int i=1;i<maxValue+1;i++)
        C[i]= C[i-1]+B[i];

    for(int i=maxValue;i>=0;i--)
    {
        while(C[i]){
        A[C[i]-1]=i;
        C[i]--;
        }
    }
}


int main()
{
    int n ;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
      scanf("%d",(a+i));

    CountSort(a,n);

    for(int i=0;i<n;i++)
        printf("%d ",*(a+i));

    return 0;
}
