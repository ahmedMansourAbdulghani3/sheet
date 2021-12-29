// CPU-Scheduling-Algorithm-In-C
// Round Robin Scheduling Algorithm(Pre-emptive)

#include<stdio.h>
#include<malloc.h>

void main()
{

    int ar_time; 
    int num_of_proc, i, tempn, count, terminaltime=0, initialtime, qunatum_t, flag=0, *bt, *wt, *tat, *tempbt;
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &num_of_proc);
    tempn = num_of_proc;

    tempbt = (int*)malloc(num_of_proc*sizeof(int));
    bt = (int*)malloc(num_of_proc*sizeof(int));
    wt = (int*)malloc(num_of_proc*sizeof(int));
    tat = (int*)malloc(num_of_proc*sizeof(int));
    
    printf("\n Enter the Quantum Time : ");
    scanf("%d", &qunatum_t);
    
    printf("\n Enter the arrival Time : ");
    scanf("%d", &ar_time);
    
    
    printf("\n Enter the burst time for each process \n\n");
    for(i=0; i<num_of_proc; i++)
    {
        printf(" Burst time of P%d : ", i+1);
        scanf("%d", &bt[i]);
        tempbt[i] = bt[i];  //pointer to save urst time
        
    }

    wt[0] = 0;  //wating time for p 1 start with 0
    printf("\n\t GAANT CHART \n");
    printf("\ntimestart     proc      time_end");
    printf("\n-------------------------------------\n");
    
    for(terminaltime=ar_time, count=0; tempn!=0;) {
        initialtime = terminaltime;
        if(tempbt[count] <= qunatum_t && tempbt[count] > 0) {
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - ar_time - bt[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if(tempbt[count] > qunatum_t) {
            tempbt[count] -= qunatum_t;
            terminaltime += qunatum_t;
        }
        if(tempbt[count] == 0 && flag == 1) {
            tempn--;
            flag=0;
        }
        if(initialtime != terminaltime) {
            printf(" %d\t      ||P%d ||\t%d\n", initialtime, count, terminaltime);
        }
        if(count == num_of_proc-1)
            count = 0;
        else
            ++count;
    }

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("-----------------------------------------------------------------\n");
    for(i=0; i<num_of_proc; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
         avgwt += wt[i];
        avgtat += tat[i]; 
    }

   
    avgwt = avgwt/num_of_proc;
    avgtat = avgtat/num_of_proc;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);
}
