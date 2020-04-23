//
//  main.cpp
//  완주하지 못한 선수
//
//  Created by 원현식 on 2020/04/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> participantArr;
vector<string> completionArr;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    }
    
    return participant[participant.size()-1];
}

