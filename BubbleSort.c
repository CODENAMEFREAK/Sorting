#include<stdio.h>

/**
    O(n^2) sorting.
*/
void bubbleSort(int * list , int n)
{
    if(list == NULL || n<2)
        return;
    int numOfSwaps=0;
    int temp;
    //In every iteration of this loop we will find next maximum; so only need to find N-1
    //Maximums.
    for(int i=0;i<=n-1;i++)
        {
            //numOfSwaps is to count the num of swaps; if 0 then it indicates that list is in non decreasing order and in that case we just return.
            numOfSwaps = 0;
            //Finding next maximum in only remaining list;
            for(int j=0; j<n-1-i; j++)
            {
            //    printf("Comparing %d with %d",list[j] ,list[j+1]);
                //In bubble sort we simply compare with just next element
                if(list[j]> list[j+1])
                    {
          //              printf(" Swapping. \n");
                        temp = list[j];
                        list[j] = list[j+1];
                        list[j+1] = temp;
                        numOfSwaps++;
                    }
                    else{
        //                printf(" No Swapping \n");
                    }
            }
            if(numOfSwaps == 0)
            {
      //          printf("Sorted after %d passes. ", i);
                return;
            }


        }

    //printf("Sorted after %d passes. ", n-1);
    return;

}


/**
If getting compilation errors set -std=c99 in compiler options.
*/
/**
Uncomment commented printf for better understanding*/
int main()
{

    int n; //Size of list to be sorted
    scanf("%d", &n);

    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    /**
        Call the sort function.
    */
    bubbleSort(a,n);


    for(int i=0;i<n;i++)
        printf("%d",*(a+i));


    return 0;
}
