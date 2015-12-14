//
//  main.cpp
//  LinkedFileAllocation
//
//  Created by Anirudh Shekhawat on 14/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

struct mem {
    bool filled;
    struct mem* next;
    bool linked;
};
int main() {
    int memSize, blockSize;
    cout << "Enter memory size: ";
    cin >> memSize;
    cout << "Enter block size: ";
    cin >> blockSize;
    int totalBlocks = memSize / blockSize;
    struct mem* blocks = new struct mem[totalBlocks];
    cout << "Enter filled and empty blocks: " << totalBlocks << endl;
    for (int i = 0; i < totalBlocks; i++) {
        cin >> blocks[i].filled;
        blocks[i].next = NULL;
        blocks[i].linked = false;
        //struct mem = new struct mem();
    }
    cout << "Enter size of contiguous block required: ";
    int fileSize, count = 0;
    int previous = 0;
    cin >> fileSize;
    int numBlocksReqd = (fileSize % blockSize) ? fileSize / blockSize + 1: fileSize / blockSize;
    int first = 0;
    for (int i = 0; i < totalBlocks; i++) {
        if (!blocks[i].filled) {
            blocks[i].linked = true;
            if (count != 0) {
                blocks[previous].next =  &blocks[i];
            }
            else {
                first = i;
            }
            previous = i;
            count++;
            if (count == numBlocksReqd) {
                break;
            }
        }
    }
    int i = first;
    struct mem* current;
    current = &blocks[i];
    while(current) {
        cout << current << "->";
        current = current->next;
    }
    
    
    
}

