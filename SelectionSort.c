#include<stdio.h>

/**
    O(n^2) Algorithm.
    */
void selectionSort(int * list , int n)
{
    if(list==NULL || n<2)
        return;

    int temp; //For swapping
    int maxValue = 0 ; //For index of maximum

    for(int i=0;i<n-1;i++)//As after finding n-1 maximums list will be sorted.
    {
        maxValue = 0;
        for(int j=1;j<=n-1-i;j++)//Comparing from 0th index to (n-1- i)th index and put the maximum at that index. j is starting from 1 so as to save one comparison as maxValue is always 0 after inner loop is terminated. Replace j with 0 and remove commented printf to see yourself.
        {
            //printf("Comparing %d with %d.\n",list[j], list[maxValue]);
            if(list[j]>list[maxValue])
                {
                    maxValue = j;
                }
        }
        //printf("Swapping %d and %d.\n",list[maxValue],list[n-1-i]);
        temp = list[maxValue];
        list[maxValue] = list[n-1-i];//As after termination of inner loop j = n-1-i
        list[n-1-i]=temp;
    }
    return;
    }




/**
If getting compilation errors set -std=c99 in compiler options.
*/
/**
Uncomment commented printf for better understanding
*/
int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    /**
        Call sorting funtion here.
    */
    selectionSort(a,n);


    for(int i=0;i<n;i++)
        printf("%d",*(a+i));

    return 0;
}
