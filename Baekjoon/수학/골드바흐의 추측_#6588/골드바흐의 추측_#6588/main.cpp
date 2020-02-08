//
//  main.cpp
//  골드바흐의 추측_#6588
//
//  Created by 원현식 on 2020/02/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

const int MAX = 1000000;
bool prime[MAX+1];

int main() {
    
    for (int i=2; i*i<=MAX; i++) {
        if (!prime[i]) {
            for (int j=(i*i)%MAX; j<=MAX; j+=i) {
                prime[j] = true;
            }
        }
    }
    
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        
        for (int i=2; i<=MAX; i++) {
            if (!prime[i]) {
                int j = n-i;
                if (!prime[j]) {
                    printf("%d = %d + %d\n", n, i, j);
                    break;
                }
            }
        }
        
    }

}

