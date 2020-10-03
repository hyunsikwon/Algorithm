//
//  main.cpp
//  커리큘럼
//
//  Created by 원현식 on 2020/10/03.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int inDegree[N+1];
    vector<int> graph[N+1];
    int time[N+1];
    int result[N+1];
    
    for (int i = 1; i<=N; i++) {
        inDegree[i] = 0;
    }

    for (int i = 1; i <= N; i++)  {
        int a;
        cin >> a;
        time[i] = a; // 강의 시간
        result[i] = a;
        while (1) {
            int b;
            cin >> b;
            if (b == -1) {
                break;
            }
            inDegree[i]++;
            graph[b].push_back(i);
            
        }
    }
    

    queue<int> q;
    for (int i = 1; i<=N; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int front = q.front(); q.pop();
        
        for (int i = 0; i < graph[front].size(); i++) {
            int child = graph[front][i];
            result[child] = max(result[child], result[front] + time[child]);
            inDegree[child]--;
            
            if (inDegree[child] == 0) {
                q.push(child);
            }
        }
    }
    
    for (int i = 1; i<=N; i++) {
        cout << result[i] << '\n';
    }
    
}

/*
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1
*/
