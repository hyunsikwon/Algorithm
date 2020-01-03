//
//  main.cpp
//  프린터 큐_#1966
//
//  Created by 원현식 on 2020/01/03.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//
// 풀이를 생각해냈지만 코드를 짜지 못함.

#include <iostream>
#include <queue>
#include <limits.h>
#define LENGTH(a) sizeof(a)/sizeof(a[0])

using namespace std;

//n개의 문서 중 m번째 문서는 몇번째로 출력되나?
int main(void) {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int n, m;
        cin >> n >> m;
        int count = 0;
        
        queue<pair<int, int>> q; // index와 중요도
        priority_queue<int> pq; // 문서
        
        for (int i = 0; i < n; i++) {
            int a; // 중요도
            cin >> a;
            q.push({i, a});
            pq.push(a);
            
        }
        
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            
            if (pq.top() == value) {
                pq.pop(); count++;
                if (index == m) {
                    break;
                }
                
            } else {
                q.push({index, value});
            }
        }
        
        cout << count << '\n';
        
    }
    
    
    
    
}
