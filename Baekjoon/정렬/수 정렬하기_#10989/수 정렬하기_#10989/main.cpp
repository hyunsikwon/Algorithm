//
//  main.cpp
//  수 정렬하기_#10989
//
//  Created by 원현식 on 2020/01/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>

int counting[10001];
int N;
int value;

int main(int argc, const char * argv[]) {
    
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &value);
        counting[value]++;
    }
    
    
    for (int i = 1; i <= 10000; i++) {
        if (counting[i] != 0) {
            for (int j = 0; j < counting[i]; j++) {
                printf("%d\n",i);
            }
        }
    }

    
}
