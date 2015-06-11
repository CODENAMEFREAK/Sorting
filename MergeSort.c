#include<stdio.h>

/**
    O(nlog(n)) order algorithm.
*/
void Merge(int * list, int start, int mid, int end)
{

    /**
    When list[mid]<=list[mid+1] then that portion of list is alredy sorted, in that case simply return.
    */
    if(!(list[mid] <= list[mid+1]))
    {
        //printf("Merging list from %d to %d and %d to %d\n",start,mid,mid+1,end );

        int outPlaceListSize = end-start+1;
        int outPlaceList[outPlaceListSize];
      //  printf("Outplace List size %d\n", outPlaceListSize);

        int pos = 0;
        int leftIndex= start;
        int rightIndex =mid+1;
        while((leftIndex<=mid) && (rightIndex<=end))
        {
                //printf("LeftIndex: %d Right Index: %d\n",leftIndex,rightIndex);
                //printf("Comparing %d with %d\n",list[leftIndex],list[rightIndex]);
                if(list[leftIndex]< list[rightIndex])
                {
                    //printf("%d < %d\n",list[leftIndex],list[rightIndex]);
                    outPlaceList[pos++] =list[leftIndex++];
                }
                else if(list[leftIndex] > list[rightIndex])
                {
                    //printf("%d > %d\n",list[leftIndex],list[rightIndex]);
                    outPlaceList[pos++] = list[rightIndex++];
                }
                else
                {
                    //printf("%d = %d\n",list[leftIndex],list[rightIndex]);
                    //i.e. when both are equal add to outPlaceList
                    outPlaceList[pos++] = list[leftIndex++];
                    outPlaceList[pos++] = list[rightIndex++];
                }
        }
        //printf("LeftIndex = %d mid = %d and RightIndex = %d\n",leftIndex,mid,rightIndex);
        //Now copy remaining if any left.
        if(leftIndex<=mid)
        {
            while(leftIndex<=mid)
                outPlaceList[pos++] = list[leftIndex++];
        }
        else if(rightIndex<=end)
        {
            while(rightIndex<=end)
                outPlaceList[pos++] = list[rightIndex++];
        }
        //printf("LeftIndex = %d mid = %d and RightIndex = %d\n",leftIndex,mid,rightIndex);

        /**
            Now till here for all items between list[start] to list [end]
            including both ends, are sorted in outPlaceList.
            So will copy this list back to list between list[start] to list [end].
            */

        //printf("OutPlaceListSize %d",outPlaceListSize);
       /* for(int i=0;i<outPlaceListSize;i++)
        {
            printf("%d\n",outPlaceList[i]);
        }*/
        for( pos = 0; pos<outPlaceListSize ; pos++ )
        {
            list[start + pos]=outPlaceList[pos];
        }
    }
    return ;
}



void MergeSort(int * list, int start, int end)
{
    if(start==end)
        return ;
    else
    {
    int mid = start + (end - start)/2;
    //printf("Splitting in Left from: %d to: %d and Right from: %d to: %d\n",start,mid,mid+1,end);
    MergeSort(list,0, mid);
    MergeSort(list, mid+1, end);
    Merge(list, start,mid, end);
    }
}



void mergeSort(int * list ,int n)
{
    MergeSort(list, 0,n-1);
}


/**
If getting compilation errors set -std=c99 in compiler options.
*/
/**
Uncomment commented printf for better understanding*/
int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    /**
    Invoke Sorting function here.
    */
    mergeSort(a,n);

    for(int i=0;i<n;i++)
        printf("%d",*(a+i));

}
