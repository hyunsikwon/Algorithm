//
//  main.cpp
//  팀 결성
//
//  Created by 원현식 on 2020/10/03.
//

#include <iostream>

using namespace std;

int findTeam(int team[], int x) {
    if (team[x] != x) {
        team[x] = findTeam(team, team[x]);
    }
    return team[x];
}

void unionTeam(int team[], int a, int b) {
    a = findTeam(team, a);
    b = findTeam(team, b);
    
    if (a < b) {
        team[b] = a;
    } else {
        team[a] = b;
    }
}

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    int team[N+1];
    for (int i = 1; i <= N; i++) {
        team[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        
        if (op == 0) { // 합치기
            unionTeam(team, a, b);
        } else { // 깉은 팀 여부
            if (findTeam(team, a) == findTeam(team, b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            
        }
        
    }
    
}

/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
 */
