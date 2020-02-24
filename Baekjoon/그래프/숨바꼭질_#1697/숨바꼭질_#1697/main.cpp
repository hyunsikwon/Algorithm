//
//  main.cpp
//  숨바꼭질_#1697
//
//  Created by 원현식 on 2020/02/24.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N, K; // 수빈이의 위치, 동생의 위치
int counting = 0;
bool visited[100001];
queue<pair<int, int>> q;

int checkTime(int n, int k) {
    
    q.push(make_pair(n, counting));
    visited[n] = true;
    
    int position;
    int time;
    while (!q.empty()) {
        position = q.front().first;
        time = q.front().second;
        q.pop();
        
        if (position == k) break;
        
        if (position < 100000 && visited[position+1] == false) {
            q.push(make_pair(position+1, time+1));
            visited[position+1] = true;
        }
        
        if (position > 0 && visited[position-1] == false) {
            q.push(make_pair(position-1, time+1));
            visited[position-1] = true;
        }
        
        if (position <= 50000 && visited[position*2] == false ) {
            q.push(make_pair(position*2, time+1));
            visited[position*2] = true;
        }
        
    }
    
    return time;
}

int main(int argc, const char * argv[]) {
    cin >> N >> K;
    
    cout << checkTime(N, K) << '\n';
    
}
