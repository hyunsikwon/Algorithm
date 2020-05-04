//
//  main.cpp
//  모의고사
//
//  Created by 원현식 on 2020/04/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> supo1 = {1,2,3,4,5};
vector<int> supo2 = {2,1,2,3,2,4,2,5};
vector<int> supo3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int supoCnt[4] = {0,};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == supo1[i % supo1.size()]) supoCnt[1]++;
        if (answers[i] == supo2[i % supo2.size()]) supoCnt[2]++;
        if (answers[i] == supo3[i % supo3.size()]) supoCnt[3]++;
    }
    
    int maxValue = 0;
    for (int i = 1; i <=3; i++) {
        if (maxValue <= supoCnt[i] ) maxValue = supoCnt[i];
    }
    
    for (int i = 1; i <= 3; i++) {
        if (supoCnt[i] == maxValue) {
            answer.push_back(i);
        }
    }
    
    if(answer.size() > 1) sort(answer.begin(), answer.end());
    return answer;
}
