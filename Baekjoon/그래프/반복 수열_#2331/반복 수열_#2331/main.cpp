//
//  main.cpp
//  반복 수열_#2331
//
//  Created by 원현식 on 2020/02/26.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;


int D[354294];
bool visited[354294];
int A,P;
int temp = 0;


int main(int argc, const char * argv[]) {
    
    cin >> A >> P;
    
    D[1] = A;
    visited[D[1]] = true;
    
    int i = 2;
    while (1) {
        int a = D[i-1];
        int sum = 0;
        
        while (a > 0) {
            int c = a % 10;
            int v = pow(c, P);
            
            sum += v;
            a /= 10;
        }
        
        if (visited[sum] == false) {
            D[i] = sum;
            visited[sum] = true;
        } else {
            D[i] = sum;
            temp = sum;
            break;
        }
        i++;
    }

    i = 1;
    int count = 0;
    while (1) {
        if (D[i] == temp) {
            break;
        }
        i++;
        count++;
    }
    
    cout << count << '\n';
    
}
