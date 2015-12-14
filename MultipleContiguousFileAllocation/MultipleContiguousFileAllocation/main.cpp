//
//  main.cpp
//  MultipleContiguousFileAllocation
//
//  Created by Anirudh Shekhawat on 15/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

struct File {
    string name;
    int size;
    int numBlocksReqd;
};
int main() {
    int memSize, blockSize;
    cout << "Enter memory size";
    cin >> memSize;
    cout << "Enter block size";
    cin >> blockSize;
    int totalBlocks = memSize / blockSize;
    int *x = new int[totalBlocks];
    cout << "Enter filled and empty blocks: " << totalBlocks << endl;
    for (int i = 0; i < totalBlocks; i++) {
        cin >> x[i];
    }
    
    cout << "Enter number of files: ";
    int numFiles;
    cin >> numFiles;
    
    struct File* files = new File[numFiles];
    
    cout << "Enter file name and size for each file\n";
    for (int i = 0; i < numFiles; i++) {
        cin >> files[i].name >> files[i].size;
        files[i].numBlocksReqd = (files[i].size % blockSize) ? files[i].size / blockSize + 1: files[i].size / blockSize;
    }
    
    for (int i = 0; i < numFiles; i++) {
        int numBlocksAlloted = 0;
        cout << files[i].name << endl;
        while (numBlocksAlloted < files[i].numBlocksReqd) {
            if (x[index] == 0) {
                cout << index << " ";
                numBlocksAlloted++;
            }
            index++;
        }
    }
    
    
}