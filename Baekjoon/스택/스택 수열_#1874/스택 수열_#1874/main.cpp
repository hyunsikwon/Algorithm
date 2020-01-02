//
//  main.cpp
//  스택 수열_#1874
//
//  Created by 원현식 on 2019/12/30.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//
// 풀이 : 입력 받은 수열의 값과 stack의 맨 윗 값을 비교해 가며 진행.
// 비교했을 때 true이면 수열의 다음 값과 stack의 맨 윗 값을 또 비교.. 설명하기 힘들다..

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    //수열 저장
    vector<int> a;
    
    // 수열 입력
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        a.push_back(s);
    }
    
    stack<int> s;
    int j = 0;
    
    // 결과
    vector<char> result;
    
    for (int i = 1; i <= n; i++) {
        s.push(i);
        result.push_back('+');
        
        while(!s.empty() && s.top() == a[j]) { // && 앞,뒤 순서 중요. cpp에서 stack이 비어있을 때 s.top을 하면 에러가 남.
            s.pop();
            result.push_back('-');
            j++;
            
        }
        
    }
//    'endl' 을 사용하면 버퍼를 비우기 때문에 매우 느리다. --> 시간 초과
//    '\n' 을 사용해야 한다.
    if (s.empty()) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
}
