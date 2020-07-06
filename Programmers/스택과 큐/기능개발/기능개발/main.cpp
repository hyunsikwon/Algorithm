//
//  main.cpp
//  기능개발
//
//  Created by 원현식 on 2020/07/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    
    for (int i = 0; i < progresses.size(); i++) {
        int n = 1;
        int progress = progresses[i];
        while (progress + speeds[i]*n < 100) {
            n++;
        }
        
        day.push(n);
    }
    
    if (day.size() == 1) {
        answer.push_back(1);
        return answer;
    } else if (day.size() > 1) {
        int front = day.front();
        day.pop();
        int count = 1;
        while (!day.empty()) {
            if (front >= day.front()) {
                count++;
                day.pop();
            } else {
                answer.push_back(count);
                count = 1;
                front = day.front();
                day.pop();
            }
            
            if (day.empty()) {
                answer.push_back(count);
            }
            
        }
        
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
   vector<int> progresses = {93, 30, 55};
   vector<int> speeds = {1, 30, 5};
    
    vector<int> result = solution(progresses, speeds);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
}
