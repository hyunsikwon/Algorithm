//
//  main.cpp
//  미래 도시
//
//  Created by 원현식 on 2020/09/27.
//

#include <iostream>

using namespace std;

int cities[101][101];
int INF = 987654321;

int main(int argc, const char * argv[]) {
    int N,M,X, K;
    
    cin >> N >> M;
    
    for (int i = 1; i <= M ; i++) {
        int city1, city2;
        
        cin >> city1 >> city2;
        cities[city1][city2] = 1;
        cities[city2][city1] = 1;
    }
    
    cin >> X >> K;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j<=N; j++) {
            if (i != j && cities[i][j] == 0) {
                cities[i][j] = INF;
            }
        }
    }
    
    for (int t = 1; t <= N; t++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                cities[a][b] = min(cities[a][b], cities[a][t] + cities[t][b]);
            }
        }
    }
    
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j<=N; j++) {
//            cout << cities[i][j] << ' ';
//
//        }
//        cout << '\n';
//    }
//
    
    if (cities[1][K] + cities[K][X] < INF ) {
        cout << cities[1][K] + cities[K][X];
    } else {
        cout << -1;
    }
    
    
}

/* input
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5
*/
