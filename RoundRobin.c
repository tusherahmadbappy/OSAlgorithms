//Round Robin is the premetive process scheduling algorithm
//Each process is provided a fix time to execute, it is called quantam.
//Once a process is execute for a given time preiod it is premetive and other process
//execute for a given time preiod.
//Context swiching is used to save states of preemptev process.

#include<stdio.h>

int main()
{
    int et[30],ts,n,i,x=0,tot=0;
    char pn[10][10];

    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the time quantum:");
    scanf("%d",&ts);
    for(i=0;i<n;i++)
    {
        printf("enter process name & estimated time:");
        scanf("%s %d",pn[i],&et[i]);
    }
    printf("The processes are:");
    for(i=0;i<n;i++)
        printf("process %d: %s\n",i+1,pn[i]);
    for(i=0;i<n;i++)
        tot=tot+et[i];
    while(x!=tot)
    {
        for(i=0;i<n;i++)
        {
            if(et[i]>ts)
            {x=x+ts;
                printf("\n %s -> %d",pn[i],ts);
                et[i]=et[i]-ts;
            }
            else
            if((et[i]<=ts)&&et[i]!=0)
            {
                x=x+et[i];
                printf("\n %s -> %d",pn[i],et[i]);
                et[i]=0;}
        }
    }
    printf("\n Total Estimated Time:%d",x);

}
