//
//  main.cpp
//  불량 사용자_2019 카카오 겨울 인턴
//
//  Created by 원현식 on 2020/05/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> canMakeStr;

    for (int i = 0; i < banned_id.size(); i++) {
        string banned = banned_id[i];
        vector<int> starLocation;
        
        // banned_id에서 *의 위치
        for (int j = 0; j < banned.length(); j++) {
            if (banned[j] == '*') {
                starLocation.push_back(j);
            }
        }
        
        vector<int> tempV;
        for (int k = 0; k < user_id.size(); k++) {
            if (banned.length() == user_id[k].length()) {
                
                for (int t = 0; t < starLocation.size(); t++) {
                    banned[starLocation[t]] = user_id[k][starLocation[t]];
                }
                
                if (banned == user_id[k]) {
                    tempV.push_back(k);
                }
                
            }
        }
        canMakeStr.push_back(tempV);
        tempV.clear();
    }
    
    return answer;
}



int main(int argc, const char * argv[]) {
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "*rodo", "******", "******"};
    
    cout << solution(user_id, banned_id) << '\n';
}
