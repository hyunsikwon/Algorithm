//
//  main.cpp
//  체육복
//
//  Created by 원현식 on 2020/05/04.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    answer += n - lost.size();
    
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                reserve[i] = -1;
                lost[j] = -1;
            }
        }
    }
    
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                answer++;
                lost[j] = -1;
                break;
            }
            if (reserve[i]-1 == lost[j]) {
                answer++;
                lost[j] = -1;
                break;
            }
            if (reserve[i]+1 == lost[j]) {
                answer++;
                lost[j] = -1;
                break;
            }
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    int n = 5;
    vector<int> lost = {2,4};
    vector<int> reserve = {3};
    
    cout << solution(n, lost, reserve);
}
