//
//  main.cpp
//  스택_#10828
//
//  Created by 원현식 on 2019/12/26.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    
    stack<int> s;
    
    int a;
    cin >> a;
    
    for(int i = 0 ; i < a; i++){
        string str;
        // 명령어
        cin >> str;

        if(str == "push") {
            int num;
            cin >> num;
            s.push(num);
            
        } else if (str == "pop") {
            if(s.empty()) {
                printf("-1\n");
            } else {
                printf("%d\n",s.top());
                s.pop();
            }

        } else if (str == "size") {
            printf("%d\n",s.size());

        } else if (str == "empty") {
            printf("%d\n", s.empty());

        } else if (str == "top"){
            s.empty() ? printf("-1\n") : printf("%d\n", s.top());

        }

    }
    
    
}
