//
//  main.cpp
//  회전하는 큐_#1021
//
//  Created by 원현식 on 2020/01/04.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    int n, m; //n 크기의 큐에서 m개의 원소를 뽑겠다.
    cin >> n >> m;
    deque<int> dq;
    
    for (int i = 1; i <= n; i++) {
        dq.push_back(i); //큐이므로 뒤에서부터 넣어야..
    }
    
    // pop은 front에서만 해야함.
    // 뽑아야할 값(초기 인덱스 1~n)가 front와 back중 어디에 더 가까이 있는가.
    int count = 0;
    
    for (int i = 0; i < m; i++) {
        int num; // 찾는 값.
        cin >> num;
        int index = 0;
        
        // 뽑아야할 값은 현재 큐에서 어느 위치에 있는가
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == num) {
                index = j;
                break;
            }
        }
        
        // 왼쪽에 더 가깝다면 2번 방법 사용 왼쪽 회전
        if (index < dq.size() - index) { // 인덱스는 0부터 시작 -> 왼쪽에서부터 거리 = 인덱스값
            while (dq.front() != num) {
                int a = dq.front();
                dq.pop_front();
                dq.push_back(a);
                count++;
            }
            dq.pop_front();
            
        } else { // 오른쪽에 더 가깝다면 3번 방법 사용 오른쪽 회전
            while (dq.front() != num) {
                int a = dq.back();
                dq.pop_back();
                dq.push_front(a);
                count++;
            }
            dq.pop_front();
        }
        
    }
    
    cout << count << '\n';
    
}

