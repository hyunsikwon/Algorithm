//
//  main.cpp
//  위상 정렬
//
//  Created by 원현식 on 2020/10/03.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4
 */

int main(int argc, const char * argv[]) {
    int V, E;
    
    cin >> V >> E;
    
    int inDegree[V+1];
    vector<int> graph[V+1];
    vector<int> result;
    
    for (int i = 1; i <= V; i++) {
        inDegree[i] = 0;
    }
    
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        inDegree[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        result.push_back(front);
        
        for (int i = 0; i < graph[front].size(); i++) {
            int child = graph[front][i];
            inDegree[child]--;
            
            if (inDegree[child] == 0) {
                q.push(child);
            }
        }
        
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    
}
