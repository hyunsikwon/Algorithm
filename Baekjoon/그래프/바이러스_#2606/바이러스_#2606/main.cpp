//
//  main.cpp
//  바이러스_#2606
//
//  Created by 원현식 on 2020/02/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

int computers,connects,countVirus;
vector<int> graph[101];
int visited[101];

void virus(int start) {
    int a = start;
    visited[a] = true;
    
    for (int i = 0; i < graph[a].size(); i++) {
        int child = graph[a][i];
        if (!visited[child]) {
            countVirus++;
            virus(child);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> computers >> connects;
    
    for (int i = 0; i < connects; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    virus(1);
    cout << countVirus << '\n';
}
