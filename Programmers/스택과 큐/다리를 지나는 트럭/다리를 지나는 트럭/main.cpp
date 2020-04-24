//
//  main.cpp
//  다리를 지나는 트럭
//
//  Created by 원현식 on 2020/04/24.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    stack<int> trucks;
    queue<int> bridge;
    int sec = 0;
    int currentBridgeState = 0;
    int trucksCount = truck_weights.size();
    vector<int> temp;
    
    while (!truck_weights.empty()) {
        trucks.push(truck_weights.back());
        truck_weights.pop_back();
    }
    
    bridge.push(trucks.top());
    sec++;
    currentBridgeState += trucks.top();
    trucks.pop();
    
    while (!bridge.empty()) {
        sec++;
        
        if (bridge.size() == bridge_length) {
            if (bridge.front() > 0) {
                currentBridgeState -= bridge.front();
                temp.push_back(bridge.front());
            }
            
            bridge.pop();
        }
        
        if (temp.size() == trucksCount) break;
        
        if (!trucks.empty() && currentBridgeState + trucks.top() <= weight) {
            bridge.push(trucks.top());
            currentBridgeState += trucks.top();
            trucks.pop();
        } else {
            
            bridge.push(0);

        }
        
    }
    
    
    answer = sec;
    return answer;
}

