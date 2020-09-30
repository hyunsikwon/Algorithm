//
//  main.cpp
//  Floyd-Warshall
//
//  Created by 원현식 on 2020/09/27.
//

#include <iostream>

using namespace std;
int INF = 987654321;

int graph[4][4] = {
    {0, 4, INF, 6},
    {3, 0, 7, INF},
    {5, INF, 0, 4},
    {INF, INF, 2, 0}
};


int result[4][4];

int main(int argc, const char * argv[]) {
    
    
    for (int i = 0; i < 4; i++) { // 거쳐가는 노드
        for (int j = 0; j < 4; j++) { // 출발 노드
            for (int k = 0; k < 4; k++) { // 도착 노드
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    
}
