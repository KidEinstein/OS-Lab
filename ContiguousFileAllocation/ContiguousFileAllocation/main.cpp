//
//  main.cpp
//  ContiguousFileAllocation
//
//  Created by Anirudh Shekhawat on 14/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//


#include <iostream>
using namespace std;

int main() {
    int memSize, blockSize;
    cout << "Enter memory size";
    cin >> memSize;
    cout << "Enter block size";
    cin >> blockSize;
    int totalBlocks = memSize / blockSize;
    int *x = new int[100];
    cout << "Enter filled and empty blocks: " << totalBlocks << endl;
    for (int i = 0; i < totalBlocks; i++) {
        cin >> x[i];
    }
    cout << "Enter size of contiguous block required: ";
    int fileSize;
    cin >> fileSize;
    int numBlocksReqd = (fileSize % blockSize) ? fileSize / blockSize + 1: fileSize / blockSize;
    int free = 0;
    int i;
    for (i = 0; i < totalBlocks; i++) {
        if (x[i] == 0) {
            free++;
        }
        else {
            free = 0;
        }
        if (free == numBlocksReqd) {
            break;
        }
    }
    int startBlock = i - free + 1;
    int endBlock = i;
    cout << "Start: " << startBlock << "End: " << endBlock << endl;
    for (int i = 0; i < totalBlocks; i++) {
        if (i >= startBlock && i <= endBlock) {
            cout << "\033[31m" << x[i] << "\033[0m";
        }
        else {
            cout << x[i];
        }
        
    }
    
    
}
