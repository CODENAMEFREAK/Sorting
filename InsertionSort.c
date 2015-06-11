#include<stdio.h>

/**
Worst Case O(n^2) performance, Works good with partially sorted lists.
*/
void insertionSort(int *list, int n)
{
    int currCard, pos;
    for(int i=1;i<n;i++)
    {
        currCard = list[i];
        pos = i-1;
        while(pos>=0)
        {
            if(list[pos]>currCard)
                {
                   // printf("Shift %d over %d\n",list[pos],list[pos+1] );
                    list[pos+1]=list[pos];
                    pos--;
                }
                else
                    break;
        }
        list[pos+1]=currCard;
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
    scanf("%d",&n);

    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    /**
     Invoke Sorting function here.
     */
     insertionSort(a,n);

    for(int i=0;i<n;i++)
        printf("%d",*(a+i));
}
