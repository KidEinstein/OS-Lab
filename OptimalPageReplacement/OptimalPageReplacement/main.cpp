//
//  main.cpp
//  OptimalPageReplacement
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
int numRequests;

bool searchPages(int request) {
    for (int i = 0; i < numPages; i++) {
        if (request == pages[i]) {
            return true;
        }
    }
    return false;
}


int getNextUse(int currentPage, int x) {
    for (int i = x; i < numRequests; i++) {
        if (requests[i] == currentPage) {
            return i;
        }
    }
    return 999;
}
int getFurthestPageIndex(int x) {
    int furthestPageIndex = -1;
    int furthestPageUse = -1;
    for (int i = 0; i < numPages; i++) {
        int currentPage = pages[i];
        int currentPageUse = getNextUse(currentPage, x);
        if (currentPageUse > furthestPageUse) {
            furthestPageIndex = i;
            furthestPageUse = currentPageUse;
        }
    }
    return furthestPageIndex;
}


int main() {
    
    cout << "Enter number of pages in memory: ";
    cin >> numPages;
    pages = new int[numPages];
    
    for (int i = 0; i < numPages; i++) {
        pages[i] = -1;
    }
    
    cout << "Enter number of request: ";
    cin >> numRequests;
    requests = new int[numRequests];
    cout << "Enter sequence of page requests: ";
    for (int i = 0; i < numRequests; i++) {
        cin >> requests[i];
    }
    
    int numPageFaults;

    for (int i = 0; i < numRequests; i++) {
        if(!searchPages(requests[i])) {
            numPageFaults++;
            int position = getFurthestPageIndex(i);
            pages[position] = requests[i];
        }
        
        for (int i = 0; i < numPages; i++) {
            cout << pages[i] << " ";
        }
        cout << endl;
    }
    
    cout << "Number of page faults: " << numPageFaults;
    
}

