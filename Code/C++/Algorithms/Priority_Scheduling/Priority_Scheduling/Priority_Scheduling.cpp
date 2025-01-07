// Priority_Scheduling.cpp | 
// https://www.youtube.com/watch?v=MFa2NvJOI54&list=PLm0fFUL4gEt9QZ5gGl63ty4qSwrmzVvH_&index=31&t=222s
// C++ program for implementation of FCFS scheduling 

#include <iostream>
#include <windows.h> 
#include <algorithm>
using namespace std;

struct Process {
    int pid; // Process ID 
    int bt; // CPU Burst time required 
    int priority; // Priority of this process 
};

// Function to sort the Process acc. to priority 
bool comparison(Process a, Process b)
{
    return (a.priority > b.priority);
}

// Function to find the waiting time for all 
// processes 
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process is 0 
    wt[0] = 0;

    // calculating waiting time 
    for (int i = 1; i < n; i++)
        wt[i] = proc[i - 1].bt + wt[i - 1];
}

// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n, int wt[],
    int tat[])
{
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time 
void findavgTime(Process proc[], const int n)
{
    int* wt = new int( (sizeof(int) * n) );
    int* tat = new int( (sizeof(int) * n) );

    int total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes 
    findWaitingTime(proc, n, wt);

    // Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat);

    // Display processes along with all details 
    std::cout << "\nProcesses  "
        << " Burst time  "
        << " Waiting time  "
        << " Turn around time\n";

    // Calculate total waiting time and total turn 
    // around time 
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + *(wt + i);
        total_tat = total_tat + *(tat + i);
        std::cout << "   " << proc[i].pid << "\t\t" << proc[i].bt
            << "\t    " << wt[i] << "\t\t  " << tat[i]
            << std::endl;
    }

    std::cout << "\nAverage waiting time = "
        << (float)total_wt / (float)n;
    std::cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], const int n)
{
    // Sort processes by priority 
    std::sort(proc, proc + n, comparison);

    std::cout << "Order in which processes gets executed \n";
    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";

    findavgTime(proc, n);
}

// Driver code 
int main()
{
    Process proc[]
        = { { 1, 10, 2 }, { 2, 5, 0 }, { 3, 8, 1 } };
    size_t a = sizeof(proc) / sizeof (proc[0]);
    const int n = a;
    priorityScheduling(proc, n);
    system("pause");
}