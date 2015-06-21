#include<stdio.h>

int partition(int *list, int lower, int upper)
{
    int pivotValue = list[lower];
    int temp=0, i,j;
    for(i=lower+1, j= lower+1;(i<=upper &&  j<=upper) ;)
    {
        while(list[i]<=pivotValue && i<=upper)
        {
            //find next value which is greater than pivotValue
            ++i;
        }
        j=i;
        while(list[j]>=pivotValue && j<= upper)
            {
                ++j;
            }
        if(i>upper || j>upper) {break;}

        temp = list[i];
        list[i]=list[j];
        list[j]=temp;
        ++i;
        ++j;
    }
    i--;
    temp= list[i];
    list[i]=pivotValue;
    list[lower]= temp;
    return i;
}

void QuickSort(int * list, int lower, int upper)
{
    if(lower >= upper)
        return;
    int pivot=partition(list, lower, upper);
    if(upper!= lower+1)
    {
    QuickSort(list, lower, pivot-1);
    QuickSort(list, pivot+1, upper);
    }
}



int main()
{
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    QuickSort(a, 0, n-1);

    for(int i=0;i<n;i++)
        printf("%d ",*(a+i));
    return 0;
}
