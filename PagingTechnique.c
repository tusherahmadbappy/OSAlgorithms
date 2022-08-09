// The biggest advantage of paging is that it is easy to use memory management
//algorithm. 
// Paging may cause internal fragmentation.
// Segmentation method works almost similarly to paging, only difference between the two
//is that segments are of variable-length whereas, in the paging method, pages are always
//of fixed size.
// Swapping is easy between equal-sized pages and page frames.


#include<stdio.h>
#include<stdlib.h>

main()
{
    int np,ps,i;
    int *sa;

    printf("enter how many pages\n");
    scanf("%d",&np);
    printf("enter the page size \n");
    scanf("%d",&ps);
    sa=(int*)malloc(2*np);
    for(i=0;i<np;i++)
    {
        sa[i]=(int)malloc(ps);
        printf("page%d\t address %u\n",i+1,sa[i]);
    }

}
