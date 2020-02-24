//
//  main.cpp
//  토마토_#7576
//
//  Created by 원현식 on 2020/02/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int M,N; //가로 세로
int tomatoHouse[1001][1001];
int days = 0;

queue<pair<int, int>> q;

void bfs() {
    
    int frontN = 0;
    int frontM = 0;
    while (!q.empty()) {
        frontN = q.front().first;
        frontM = q.front().second;
        q.pop();
        
        
        // ↓
        if (frontN < N - 1 && tomatoHouse[frontN+1][frontM] == 0) {
            tomatoHouse[frontN+1][frontM] = tomatoHouse[frontN][frontM] + 1;
            q.push(make_pair(frontN+1, frontM));
            
        }
        
        // ↑
         if (frontN > 0 && tomatoHouse[frontN-1][frontM] == 0) {
            tomatoHouse[frontN-1][frontM] = tomatoHouse[frontN][frontM] + 1;
            q.push(make_pair(frontN-1, frontM));

        }
        
        // →
        if (frontM < M - 1 && tomatoHouse[frontN][frontM+1] == 0) {
            tomatoHouse[frontN][frontM+1] = tomatoHouse[frontN][frontM] + 1;
            q.push(make_pair(frontN, frontM+1));
        }
        
        // ←
        if (frontM > 0 && tomatoHouse[frontN][frontM-1] == 0) {
            tomatoHouse[frontN][frontM-1] = tomatoHouse[frontN][frontM] + 1;
            q.push(make_pair(frontN, frontM-1));

        }

        days = tomatoHouse[frontN][frontM] - 1;
        
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> M >> N;
    
    int lineData;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lineData;
            if (lineData == 1) {
                q.push(make_pair(i, j));
            }
            tomatoHouse[i][j] = lineData;
        }
    }
    
    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomatoHouse[i][j] == 0) {
                days = -1;
            }
        }
        
    }
    
    cout << days << '\n';
    
    //MARK: - 확인용 출력
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << tomatoHouse[i][j] << ' ';
//        }
//        cout << '\n';
//    }

}
