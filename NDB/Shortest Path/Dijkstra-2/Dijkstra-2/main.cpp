//
//  main.cpp
//  Dijkstra-2
//
//  Created by 원현식 on 2020/09/26.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int SIZE = 6;
int INF = 987654321;

vector<pair<int, int>> graph[6];
int result[6];

void dijkstra(int start) {
    result[start] = 0;
    // 거리, 노드
    priority_queue<pair<int, int>> pq; // 최대 힙
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int distance = -pq.top().first; // start부터 현재 노드까지의 거리
        pq.pop();
        
        for (int i = 0; i < graph[currentNode].size(); i++) {
            int childNode = graph[currentNode][i].first;
            int currentToChild = graph[currentNode][i].second;
            
            if (distance + currentToChild < result[childNode]) {
                result[childNode] = distance + currentToChild;
                pq.push(make_pair(-(currentToChild + distance), childNode));
            }
        
            
        }
        
    }
    
    
}

int main(int argc, const char * argv[]) {

    for (int i = 0; i < SIZE; i++) {
        result[i] = INF;

    }

    graph[0].push_back(make_pair(1, 2));
    graph[0].push_back(make_pair(2, 5));
    graph[0].push_back(make_pair(3, 1));

    graph[1].push_back(make_pair(2, 3));
    graph[1].push_back(make_pair(3, 2));

    graph[2].push_back(make_pair(1, 3));
    graph[2].push_back(make_pair(5, 5));

    graph[3].push_back(make_pair(2, 3));
    graph[3].push_back(make_pair(4, 1));

    graph[4].push_back(make_pair(2, 1));
    graph[4].push_back(make_pair(5, 2));

    dijkstra(0);

    for (int i = 0; i < SIZE; i++) {
        cout << result[i] << ' ';

    }
    
    priority_queue<pair<int, int>> pq; // 최대 힙
    
}
