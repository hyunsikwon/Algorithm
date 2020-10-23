//
//  main.cpp
//  소수 만들기_cpp
//
//  Created by 원현식 on 2020/10/23.
//

#include <vector>
#include <iostream>
using namespace std;

int num = 0;

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void comb(vector<int> nums, int depth, int current, int &answer) {
    if (depth == 3) {
        if (isPrime(num)) answer++;
        return;
    }
    
    for (int i = current; i < nums.size(); i++) {
        num += nums[i];
        comb(nums, depth+1, i+1, answer);
        num -= nums[i];
    }
    
}

int solution(vector<int> nums) {
    int answer = 0;
    comb(nums, 0, 0, answer);
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,7,6,4};
    
    cout << solution(nums) << '\n';
}
