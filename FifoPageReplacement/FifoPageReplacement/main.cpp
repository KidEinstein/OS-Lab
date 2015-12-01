//
//  main.cpp
//  FifoPageReplacement
//
//  Created by Anirudh Shekhawat on 02/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
using namespace std;

int* pages;
int* requests;
int numPages;
bool searchPages(int request) {
    for (int i = 0; i < numPages; i++) {
        if (request == pages[i]) {
            return true;
        }
    }
    return false;
}
int main() {
    
    cout << "Enter number of pages in memory: ";
    cin >> numPages;
    pages = new int[numPages];
    
    for (int i = 0; i < numPages; i++) {
        pages[i] = -1;
    }

    cout << "Enter number of request: ";
    int numRequests;
    cin >> numRequests;
    requests = new int[numRequests];
    cout << "Enter sequence of page requests: ";
    for (int i = 0; i < numRequests; i++) {
        cin >> requests[i];
    }
    
    int numPageFaults;
    int index = -1;
    for (int i = 0; i < numRequests; i++) {
        if(!searchPages(requests[i])) {
            numPageFaults++;
            index = (index + 1) % numPages;
            pages[index] = requests[i];
        }
        for (int i = 0; i < numPages; i++) {
            cout << pages[i] << " ";
        }
        cout << endl;
    }
    
    cout << "Number of page faults: " << numPageFaults;
    
}
