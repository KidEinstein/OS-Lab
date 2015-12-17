//
//  main.cpp
//  ProducerConsumer
//
//  Created by Anirudh Shekhawat on 01/12/15.
//  Copyright © 2015 Anirudh Shekhawat. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
using namespace std;

mutex m;
queue<int> buffer;
int bufferItems = 0;
int bufferCapacity;
int num = 0;

void produce() {
    while (true) {
        if (bufferItems >= bufferCapacity) {
            cout << "Buffer full" << endl;
            sleep(1);
            continue;
        }
        m.lock();
            bufferItems++;
            buffer.push(num);
            cout << "Produced: " << num <<endl;
            num++;
        m.unlock();
        sleep(5);
    }
}

void consume() {
    while (true) {
        if (bufferItems == 0) {
            cout << "Buffer empty" << endl;
            sleep(1);
            continue;
        }
        m.lock();
            bufferItems--;
            int value = buffer.front();
            buffer.pop();
            cout << "Consumed: " << value << endl;
        m.unlock();
        sleep(1);
    }
}
int main() {
    cout << "Enter buffer capacity: ";
    cin >> bufferCapacity;
    
    thread p(produce);
    thread c(consume);

    p.join();
    c.join();
}
