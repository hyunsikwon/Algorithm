//
//  main.cpp
//  프린터_cpp
//
//  Created by 원현식 on 2020/09/30.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> values;
    queue<int> p;
    
    for (int i = 0; i < priorities.size(); i++) {
        values.push(i);
        p.push(priorities[i]);
    }
    
    while (!priorities.empty()) {
        int front = values.front(); // 알파벳
        int priority = priorities[front]; // 우선순위
        bool check = false;
        
        for (int j = 0; j < priorities.size(); j++) {
            if (front != j) {
                if (priorities[j] > priority) {
                    check = true;
                    break;
                }
            }
        }
        
        if (check == true) {
            values.pop();
            values.push(front);
        } else {
            for (int i = 0; i < priorities.size(); i++) {
                if (i == front) {
                    priorities[i] = -1;
                    break;
                }
            }
            answer++;
            values.pop();
            if (front == location) {
                break;
            }
        }
        
    }
    
    
    return answer;
}

int main() {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;
    
    cout << solution(priorities, location) << '\n';
}
