//
//  main.cpp
//  더 맵게
//
//  Created by 원현식 on 2020/04/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int> > pq(scoville.begin(),scoville.end());
    
    while (pq.top() < K) {
        answer++;

        if (pq.size() < 2) {
            answer = -1;
            break;
        }
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int newValue = first + (second*2);
        pq.push(newValue);
    }

    return answer;
}
