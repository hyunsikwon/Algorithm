//
//  main.cpp
//  튜플_2019 카카오 겨울 인턴
//
//  Created by 원현식 on 2020/05/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a.length() < b.length();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> group;
    string str;
    
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || i == s.length() - 1) continue;
        
        if (s[i] == '{') str = "";
        else if (s[i] == '}') group.push_back(str);
        else if ((s[i] >= '0' && s[i] <= '9') || s[i] == ',') str += s[i];
    }
    
    sort(group.begin(), group.end(), compare);
    
    for (int i = 0; i < group.size(); i++) {
        if (i == 0) answer.push_back(atoi(group[i].c_str()));
        else {
            string tempStr = "";
            vector<int> tempInts;
            for (int j = 0; j < group[i].size(); j++) {
                if (group[i][j] >= '0' && group[i][j] <= '9') {
                    if (j == group[i].size() - 1) {
                        tempStr += group[i][j];
                        tempInts.push_back(atoi(tempStr.c_str()));
                    } else {
                        tempStr += group[i][j];
                    }
                    
                } else if (group[i][j] == ',') {
                    tempInts.push_back(atoi(tempStr.c_str()));
                    tempStr = "";
                }
            }
            bool flag = false;
            int diff;
            for (int k = 0; k < tempInts.size(); k++) {
                for (int t = 0; t < answer.size(); t++) {
                    if (tempInts[k] == answer[t]) {
                        flag = true; break;
                    } else {
                        diff = tempInts[k];
                        flag = false;
                    }
                }
                
                if (flag == false) {
                    answer.push_back(diff);
                    break;
                }
            }
            
            tempInts.clear();
            
            
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    string s = "{{20,111},{111}}";

    vector<int> answer =  solution(s);
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}
