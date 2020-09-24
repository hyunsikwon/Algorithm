//
//  main.cpp
//  멀쩡한 사각형_cpp
//
//  Created by 원현식 on 2020/09/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b%a, b);
    
}

long long solution(int w,int h) {
    long long answer = 1;
    
    int max = w > h ? w : h;
    int i = 1;
    int gcd = 0;
    
    while(i <= max) {
        if (w % i == 0 && h % i == 0) {
            gcd = i;
        }
        i++;
    }
    
    long long lw = w, lh = h;
    
    answer = lw*lh - (lw+lh - gcd);
    
    return answer;
}

int main(void) {
    int W = 8, H = 12;
    // result: 80
    cout << solution(W, H) << '\n';

    
}
