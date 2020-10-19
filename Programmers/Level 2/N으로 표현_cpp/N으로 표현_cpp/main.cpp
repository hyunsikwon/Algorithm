//
//  main.cpp
//  N으로 표현_cpp
//
//  Created by 원현식 on 2020/10/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 9;

void dfs(int count, int currentValue, int targetNum, int N) {
    if (count > 8) {
        return;
    }
    
    if (currentValue == targetNum) {
        answer = min(answer, count);
        return;
    }
    
    int tmp = 0;
    for (int i = 0; i < 8-count; i++) {
        tmp = tmp*10 + N;
        dfs(count+1+i, currentValue+tmp, targetNum, N);
        dfs(count+1+i, currentValue-tmp, targetNum, N);
        dfs(count+1+i, currentValue*tmp, targetNum, N);
        dfs(count+1+i, currentValue/tmp, targetNum, N);

    }
  
}

int solution(int N, int number) {
    if (number == N) return 1;
    
    dfs(0, 0, number, N);
    
    if (answer > 8) return -1;
    
    return answer;
}


int main(int argc, const char * argv[]) {
    int N = 5;
    int number = 12;
    cout << solution(N, number);
}
