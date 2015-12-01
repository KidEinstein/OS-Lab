//
//  main.cpp
//  MemoryAllocation
//
//  Created by Anirudh Shekhawat on 01/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;
int blocksAvailable;
int* availableBlockSize;
int numRequests;
int* requiredBlockSize;
int* availableBlockSizeInitial;

void bestFit() {
    for (int i = 0; i < numRequests; i++) {
        int minSize = 999;
        int minIndex = -1;
        for (int j = 0; j < blocksAvailable; j++) {
            if (availableBlockSize[j] > requiredBlockSize[i] && availableBlockSize[j] < minSize) {
                minSize = availableBlockSize[j];
                minIndex = j;
            }
        }
        if (minIndex == -1) {
            cout << "Cannot accommodate request " << i << endl;
            continue;
        }
        availableBlockSize[minIndex] = -1;
        cout << "Block " << minIndex << " allocated to request " << i << endl;
    }
}

void worstFit() {
    for (int i = 0; i < numRequests; i++) {
        int maxSize = -1;
        int maxIndex = -1;
        for (int j = 0; j < blocksAvailable; j++) {
            if (availableBlockSize[j] > requiredBlockSize[i] && availableBlockSize[j] > maxSize) {
                maxSize = availableBlockSize[j];
                maxIndex = j;
            }
        }
        if (maxIndex == -1) {
            cout << "Cannot accommodate request " << i << endl;
            continue;
        }
        availableBlockSize[maxIndex] = -1;
        cout << "Block " << maxIndex << " allocated to request " << i << endl;
    }
}

void firstFit() {
    for (int i = 0; i < numRequests; i++) {
        bool allocated = false;
        for (int j = 0; j < blocksAvailable; j++) {
            if (availableBlockSize[j] > requiredBlockSize[i]) {
                availableBlockSize[j] = -1;
                allocated = true;
                cout << "Block " << j << " allocated to request " << i << endl;
                break;
            }
        }
        if (!allocated) {
            cout << "Cannot accommodate request " << i << endl;
            continue;
        }
    }
}
void reset() {
    for (int i = 0; i < blocksAvailable; i++) {
        availableBlockSize[i] = availableBlockSizeInitial[i];
    }
}

int main() {
    cout << "Enter number of available blocks: ";
    cin >> blocksAvailable;
    
    cout << "Enter size of each available block: ";
    availableBlockSizeInitial = new int[blocksAvailable];
    availableBlockSize = new int[blocksAvailable];
    for (int i = 0; i < blocksAvailable; i++) {
        cin >> availableBlockSizeInitial[i];
    }
    
    cout << "Enter number of request to be served: ";
    cin >> numRequests;
    
    requiredBlockSize = new int[numRequests];
    cout << "Enter the size of required block for each process: ";
    for (int i = 0; i < numRequests; i++) {
        cin >> requiredBlockSize[i];
    }
    
    reset();
    cout << "Best fit\n";
    bestFit();
    reset();
    cout << "First fit\n";
    firstFit();
    reset();
    cout << "Worst fit\n";
    worstFit();

    
}
