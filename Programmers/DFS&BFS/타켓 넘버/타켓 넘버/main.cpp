//
//  main.cpp
//  타켓 넘버
//
//  Created by 원현식 on 2020/05/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int sum, int count ,int target, vector<int> numbers) {
    if (count == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    dfs(sum+numbers[count], count+1, target, numbers);
    dfs(sum-numbers[count], count+1, target, numbers);
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    cout << solution(numbers, target);
}
