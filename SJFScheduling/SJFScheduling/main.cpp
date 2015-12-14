//
//  main.cpp
//  SJFScheduling
//
//  Created by Anirudh Shekhawat on 14/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

struct Process {
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

bool compareBurstTime(struct Process p1, struct Process p2) {
    return p1.burstTime > p2.burstTime;
}

int main() {
    cout << "Enter the number of processes";
    int numProcesses;
    cin >> numProcesses;
    
    struct Process* processes = new struct Process[numProcesses];
    
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i].burstTime;
    }
    
    sort(processes, processes + numProcesses, &compareBurstTime);
    
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    processes[0].waitingTime = 0;
    processes[0].turnAroundTime = processes[0].burstTime;
    for (int i = 1; i < numProcesses; i++) {
        processes[i].waitingTime = processes[i-1].turnAroundTime;
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnAroundTime;
    }
    int avgWaitingTime = totalWaitingTime / numProcesses;
    int avgTurnaroundTime = totalTurnaroundTime / numProcesses;
    
    cout << "Average waiting time: " << avgWaitingTime;
    cout << "Average turnaround time: " << avgTurnaroundTime;
    
    
}
