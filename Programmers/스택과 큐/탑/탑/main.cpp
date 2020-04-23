//
//  main.cpp
//  탑
//
//  Created by 원현식 on 2020/04/23.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> temp;
    
    for (int i = heights.size()-1; i > 0 ; i--) {
        bool check = true;
        for (int j = i-1; j >= 0; j--) {
            if (heights[i] < heights[j]) {
                temp.push_back(j+1);
                check = false;
                break;
            }
        }
        if (check) {
            temp.push_back(0);
        }
    }
    temp.push_back(0);
    
    for (int i = temp.size()-1; i >= 0; i--) {
        answer.push_back(temp[i]);
    }
    
    return answer;
}

