//
//  main.cpp
//  DeadlockDetection
//
//  Created by Anirudh Shekhawat on 01/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

int numResources;

bool lessThan(int a[], int b[]) {
    for (int i = 0; i < numResources; i++) {
        if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Enter number of resources: ";
    cin >> numResources;
    
    cout << "Enter the available vector:\n";
    int *available = new int[numResources];
    for (int i = 0; i < numResources; i++) {
        cin >> available[i];
    }
    
    cout << "Enter number of processes: ";
    int numProcesses;
    cin >> numProcesses;
    
    int** allocation = new int*[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = new int[numResources];
    }
    
    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> allocation[i][j];
        }
    }
    
    int** request = new int*[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        request[i] = new int[numResources];
    }
    
    cout << "Enter the request matrix:\n";
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            cin >> request[i][j];
        }
    }
    
    bool* marked = new bool[numProcesses]();

    for (int i = 0; i < numProcesses; i++) {
        bool empty = true;
        for (int j = 0; j < numResources; j++) {
            if (allocation[i][j] != 0) {
                empty = false;
                break;
            }
        }
        if (empty) marked[i] = true;
    }
    bool rowsLeft = true;
    
    while (rowsLeft) {
        rowsLeft = false;
        for (int i = 0; i < numProcesses; i++) {
            if (marked[i]) continue;
            if (lessThan(request[i], available)) {
                rowsLeft = true;
                for (int j = 0; j < numResources; j++) {
                    available[j] += allocation[i][j];
                }
                marked[i] = true;
            }
            for (int j = 0; j < numProcesses; j++) {
                cout << marked[j] << " ";
            }
            cout << endl;
        }
    }
    
    cout << "Following processes are deadlocked: \n";
    for (int i = 0; i < numProcesses; i++) {
        if (!marked[i]) {
            cout << i << "\t";
        }
    }
    return 0;
}
