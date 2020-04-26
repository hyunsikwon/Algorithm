//
//  main.cpp
//  K번째수
//
//  Created by 원현식 on 2020/04/26.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> tempArr;
        
        for (int j = commands[i][0]-1; j <= commands[i][1]-1; j++) {
            tempArr.push_back(array[j]);
        }
        
        sort(tempArr.begin(), tempArr.end());
        
        answer.push_back(tempArr[commands[i][2]-1]);
 
    }

    return answer;
}


int main(void) {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    
    vector<int> answer;
    answer = solution(array, commands);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    
}
