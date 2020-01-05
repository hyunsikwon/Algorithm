//
//  main.cpp
//  AC_#5430
//
//  Created by 원현식 on 2020/01/05.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {
    int T; // test case 갯수
    string p; // 함수
    int n; // 배열의 크기
    string arr; // 배열
    deque<int> dq; // 덱
    
    cin >> T;
    
    string temp;
    for (int i = 0; i < T; i++) {
        cin >> p ;
        cin >> n;
        cin >> arr;
        
        for (int j = 1; j < arr.length(); j++) {
            if (arr[j] >= '0' && arr[j] <= '9') {
                temp += arr[j];
            } else if(arr[j] == ',' || arr[j] == ']') {
                if (!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        
        
        bool forward = true;
        bool error = false;
        
        for (int k = 0; k < p.length(); k++) {
            
            if (p[k] == 'R') {
                forward = !forward;
            } else if(p[k] == 'D') {
                if(dq.empty()) {
                    error = true;
                    break;
                }
                if (forward) {
                    dq.pop_front();
                } else dq.pop_back();
            }
            
        }
        
        if (error) {
            printf("error\n");
        } else {
            printf("[");
            if (!forward) {
                while (!dq.empty()) {
                    printf("%d",dq.back());
                    dq.pop_back();
                    if (!dq.empty()) cout << ",";
                }
            } else {
                while (!dq.empty()) {
                    printf("%d",dq.front());
                    dq.pop_front();
                    if (!dq.empty()) cout << ",";
                }
            }
            printf("]");
        }
        
    }
    
}

