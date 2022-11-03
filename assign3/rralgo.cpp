#include<iostream>
using namespace std;
 
// Finds the waiting time for all processes
void findWT(int p[], int n, //p stores the process value
            int bt[], int wt[], int q) //q stores the quantum value, (4 ms in our example)
{
    // A copy of burst times bt[] is made to store the remaining burst times.
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];
 
    int t = 0; // This is the current time
 
    // Keep traversing until each process is done
    while (1)
    {
        bool done = true;
 
        // Traverse all processes one at a time, and continue again
        for (int i = 0 ; i < n; i++)
        {
      // If burst time of a process is <= 0, don't process further
            if (rem_bt[i] > 0)
            {
                done = false; // Some pending process
 
                if (rem_bt[i] > q)
                {
    // Increase the value of t to see the time for which a process has been processed
                    t += q;
 
       // Reduce the burst_time of running process by quantum
                    rem_bt[i] -= q;
                }
 
       // If burst time is <= q, last cycle of this process
                else
                {
        // Increase the value of t
                    t = t + rem_bt[i];
 
      // Waiting time = current time - time used by the process
                    wt[i] = t - bt[i];
 
  // As the process gets over, its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }
 
 // If all processes are completely executed
        if (done == true)
        break;
    }
}
 
// To calculate the turnaround time
void findTAT(int p[], int n,
                        int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
// To calculate average time
void findAT(int p[], int n, int bt[], int q)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // To find waiting time of all processes
    findWT(p, n, bt, wt, q);
 
    // To find turn around time for all processes
    findTAT(p, n, bt, wt, tat);
 
    // To display all processes and other details
    cout << "Processes "<< " Burst Time "
        << " Waiting Time " << " Turn Around Time\n";
 
    // To Calculate total waiting time and total turnaround time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average Waiting Time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage Turn Around Time = "
        << (float)total_tat / (float)n;
}
 
// Driver code
int main()
{
    // ith process 
    int p[] = { 1, 2, 3};
    int n = sizeof p / sizeof p[0];
 
    // Burst time
    int burst_time[] = {24, 3, 3};
 
    // Time quantum (maximum time for which a process can be run once)
    int q = 4;
    findAT(p, n, burst_time, q);
    return 0;
} 
