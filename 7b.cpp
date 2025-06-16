#include<stdio.h>
int main(){
    int nop,wt[10],tat[10],bt[10],t;
    int twt = 0,ttat = 0;
    float awt,atat;
    int i,j;
    printf("Emter the number of process");
    scanf(%d,&nop);
    for(i=0;i<nop;i++){
        printf("Enter the burst time%d",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<nop;i++){
        for(j=i+1;j<nop;j++){
            if(bt[i]>bt[j]){
                t = bt[i];
                bt[i] = bt[j];
                bt[j] = t;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    twt = wt[0];
    ttat = tat[0];
    for(i=1;i<nop;i++){
        wt[i] = wt[i - 1]+bt[i - 1];
        tat[i] = wt[i] + bt[i];
        twt+=wt[i];
        ttat +=tat[i];
    }
    awt = (float)twt/nop;
    atat =(float)ttat/nop;
    printf("\nProcess ID\tBurst Time \tWaiting Time\tTurnaround Time\n");
    for(i=0;i<nop;i++){
        printf("%d\t%d\t\t%d\n",i,bt[i],wt[i],tat[i]);
    }
    printf("\nTotal Waiting time: %d\n", twt);
    printf("Total Turnaround time %d\n",ttat);
    printf("Average Waiting Time %.2f\n", awt);
    printf("Average Turn arooung time%.2f\n",atat);
    return 0;
}
