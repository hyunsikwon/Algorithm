//
//  main.cpp
//  서로소 집합
//
//  Created by 원현식 on 2020/10/02.
//

#include <iostream>

using namespace std;

int findParent(int parent[], int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionParent(int parent[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a < b) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

/*
 6 4
 1 4
 2 3
 2 4
 5 6
 */
int main(int argc, const char * argv[]) {
    int parent[7];
    int V, E;
    cin >> V >> E;
    
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < E ; i++) {
        int a, b;
        cin >> a >> b;
        unionParent(parent, a, b);
    }
    
    // 노드가 속한 집합
    for (int i = 1; i <= V; i++) {
        cout << findParent(parent, i) << ' ';
    }
    
    cout << '\n';
    
    // 부모 테이블
    for (int i = 1; i <= V; i++) {
        cout << parent[i] << ' ';
    }
    
}
