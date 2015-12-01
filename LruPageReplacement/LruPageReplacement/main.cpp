//
//  main.cpp
//  LruPageReplacement
//
//  Created by Anirudh Shekhawat on 02/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <deque>
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

int getIndex(int request) {
    for (int i = 0; i < numPages; i++) {
        if (request == pages[i]) {
            return i;
        }
    }
    return -1;
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
    
    deque<int> fulfilledRequests;
    int numPageFaults;
    for (int i = 0; i < numPages; i++) {
        pages[i] = requests[i];
        fulfilledRequests.push_back(requests[i]);
        numPageFaults++;
        for (int j = 0; j < numPages; j++) {
            cout << pages[j] << " ";
        }
        cout << endl;
    }
    for (int i = numPages; i < numRequests; i++) {
        for (int j = 0; j < fulfilledRequests.size(); j++) {
            if (fulfilledRequests[j] == requests[i]) {
                fulfilledRequests.erase(fulfilledRequests.begin() + j);
            }
        }
        fulfilledRequests.push_back(requests[i]);
        if(!searchPages(requests[i])) {
            numPageFaults++;
            int removedPage = fulfilledRequests.front();
            fulfilledRequests.pop_front();
            int position = getIndex(removedPage);
            pages[position] = requests[i];
        }
        
        for (int i = 0; i < numPages; i++) {
            cout << pages[i] << " ";
        }
        cout << endl;
    }
    
    cout << "Number of page faults: " << numPageFaults;
    
}
