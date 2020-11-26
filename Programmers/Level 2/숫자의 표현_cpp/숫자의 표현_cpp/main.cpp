//
//  main.cpp
//  숫자의 표현_cpp
//
//  Created by 원현식 on 2020/11/26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 연속한 자연수! 14 + 1 = 15 면 안되는 것.

int solution(int n) {
    int answer = 1; // 자기 자신으로 만든다.
    int middle = (n+1)/2;
    
    int current = 1;

    while (current < middle) {
        int temp = current;
        for (int j = current+1; j <= (n+1)/2; j++) {
            if (temp + j > n) break;
            else {
                temp += j;
            }
            
            if (temp == n) {
                answer++;
                break;
            }
        }
        
        current++;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    int n = 15;
    cout << solution(n) << '\n';
    cout << "result: " << 4 << '\n';
}
