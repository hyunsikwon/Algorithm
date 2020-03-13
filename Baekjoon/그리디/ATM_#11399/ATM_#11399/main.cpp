//
//  main.cpp
//  ATM_#11399
//
//  Created by 원현식 on 2020/03/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>


using namespace std;

int N;
int P[1001];
priority_queue<int,vector<int>,greater<int>> pq;

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        pq.push(p);
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pq.top();
        P[i] = sum;
        pq.pop();
    }
    
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += P[i];
    }
    
    cout << sum;
    
}
