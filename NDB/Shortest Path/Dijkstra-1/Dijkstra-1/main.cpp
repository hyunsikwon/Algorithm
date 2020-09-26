//
//  main.cpp
//  Dijkstra-1
//
//  Created by 원현식 on 2020/09/26.
//

#include <iostream>
#include <vector>

using namespace std;

int INF = 987654321;

int graph[6][6]  = {
    {0, 2, 5, 1, INF, INF},
    {INF, 0, 3, 2, INF, INF},
    {INF, 3, 0, INF, INF, 5},
    {INF, INF, 3, 0, 1, INF},
    {INF, INF, 1, INF, 0, 2},
    {INF, INF, INF, INF, INF, 0}
    
};

int result[6] = {0,};
bool visited[6] = {false, };


int getSmallDistance() {
    int min = INF;
    int node = 0;
    
    for (int i = 0; i < 6; i++) {
        if(!visited[i] && result[i] < min) {
            node = i;
            min = result[i];
            
        }
    }
    
    return node;
}

void dijkstra(int start) {
    for (int i = 0; i < 6; i++) {
        result[i] = graph[start][i];
    }
    visited[start] = true;

    for (int i = 0; i < 6; i++) {
        int currentNode = getSmallDistance();
        visited[currentNode] = true;
        
        for (int j = 0; j < 6; j++) {
            if (!visited[j]) {
                if (result[currentNode] + graph[currentNode][j] < result[j]) {
                    result[j] = result[currentNode] + graph[currentNode][j];
                }
                
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    
    dijkstra(0);
    for (int i = 0; i < 6; i++) {
        cout << result[i] << ' ';
    }
    
}
