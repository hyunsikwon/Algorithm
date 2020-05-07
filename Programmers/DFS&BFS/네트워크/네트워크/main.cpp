//
//  main.cpp
//  네트워크
//
//  Created by 원현식 on 2020/05/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visit[201];
void dfs(int start, vector<vector<int>> computers) {
    if (visit[start] == true) return;
    visit[start] = true;
    
    for (int i = 0; i < computers[start].size(); i++) {
        if (i == start) continue;
        
        if (computers[start][i] == 1) {
            dfs(i, computers);
        }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            dfs(i, computers);
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 3;
    vector<vector<int>> computers = {{1,1,0},{1,1,1},{0,1,1}};
    cout << solution(n, computers);
}
