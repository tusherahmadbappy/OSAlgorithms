#include<stdio.h>
#include<string.h>

int main(){


    char pn[10][10],t[10];
    int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,j,num,temp;
    int totwt=0,tottat=0;

    //user input the total number of process
    printf("Enter the number of processes:");
    scanf("%d",&num);

    //user input pname,arraival time & burst time
    for(i=0;i<num;i++)
    {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf("%s%d%d",pn[i],&arr[i],&bur[i]);
    }

    //loop using swapping
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(arr[i]<arr[j])
            {
                //swapping arraival
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;

                //swapping burst time
                temp=bur[i];
                bur[i]=bur[j];
                bur[j]=temp;


                //swapping pname
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
        {
            star[i]=arr[i];
        }
        else{
            star[i]=finish[i-1];

        }


        wt[i]=star[i]-arr[i];
        finish[i]=star[i]+bur[i];
        tat[i]=finish[i]-arr[i];

    }

    printf("\nPName Arrtime Burtime WaitTime StartTime TATT  FinishT");
    for(i=0;i<num;i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%3d\t%3d",pn[i],arr[i],bur[i],wt[i],star[i],tat[i],finish[i]);
        totwt+=wt[i];
        tottat+=tat[i];
    }

    printf("\nAverage Waiting time:%f",(float)totwt/num);
    printf("\nAverage Turn Around Time:%f\n",(float)tottat/num);


    return 0;


}