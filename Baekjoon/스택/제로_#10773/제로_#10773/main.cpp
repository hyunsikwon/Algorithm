//
//  main.cpp
//  제로_#10773
//
//  Created by 원현식 on 2019/12/26.
//  Copyright © 2019 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    stack<int> s;
    
    int k;
    scanf("%d\n",&k);
    
    int n;
    for (int i = 0; i < k; i++) {
        scanf("%d\n",&n);
        if(n == 0) {
            s.pop();
        } else {
            s.push(n);
        }
    }
    
    int sum = 0;
    
    while (!s.empty()) {
        int a = s.top();
        s.pop();
        sum += a;
    }
    
    printf("%d\n",sum);
}
