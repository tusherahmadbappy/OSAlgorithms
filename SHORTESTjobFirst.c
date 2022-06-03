#include<stdio.h>
#include<string.h>

int main()
{
    int et[20],arrt[10],st[10],ft[10],wt[10],ta[10],num,i,j,temp;
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];

    //user input total number of process
    printf("Enter the number of process:");
    scanf("%d",&num);

    //user input of process name, arrival time & execution time using loop
    for(i=0;i<num;i++)
    {
        printf("Enter process name, arrival time & execution time:");
        scanf("%s %d %d",pn[i],&arrt[i],&et[i]);
    }

    //loop using swapping
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(et[i]<et[j])
            {
                //swapping arrt
                temp=arrt[i];
                arrt[i]=arrt[j];
                arrt[j]=temp;

                //swapping et
                temp=et[i];
                et[i]=et[j];
                et[j]=temp;

                //swapping pn
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    }

    //loop using calculation
    for(i=0;i<num;i++)
    {
        if(i==0)
            st[i]=arrt[i];
        else
            st[i]=ft[i-1];

        wt[i]=st[i]-arrt[i];
        ft[i]=st[i]+et[i];
        ta[i]=ft[i]-arrt[i];

        totwt+=wt[i];
        totta+=ta[i];

    }

    awt=(float)totwt/num;
    ata=(float)totta/num;

    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0;i<num;i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],arrt[i],et[i],wt[i],ta[i]);

    printf("\nAverage waiting time is: %f",awt);
    printf("\nAverage turnaroundtime is: %f\n",ata);

    return 0;

}