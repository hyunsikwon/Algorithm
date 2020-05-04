//
//  main.cpp
//  소수 찾기
//
//  Created by 원현식 on 2020/05/04.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

bool isContain(string primeNumber, string numbers) {
    int count = 0;
    for (int i = 0; i < numbers.length(); i++) {
        for (int j = 0; j < primeNumber.length(); j++) {
            if (primeNumber[j] == numbers[i]) {
                primeNumber[j] = '.';
                count++;
                break;
            }
        }
    }
    
    if (count == primeNumber.length()) return true;
    return false;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> primeNumbers;
    
    // MARK: - 한자릿수 숫자카드들로 만들수 있는 가장 큰수 "011" -> 110
    sort(numbers.begin(), numbers.end(),greater<int>());
    int max = atoi(numbers.c_str());
    
    // MARK: - ~max 까지의 소수들
    for (int i = 2; i <= max; i++) {
        if (isPrime(i)) primeNumbers.push_back(i);
    }
    
    for (int i = 0; i < primeNumbers.size(); i++) {
        string primeNum = to_string(primeNumbers[i]);
        if (isContain(primeNum, numbers))answer++;
    }
    
    return answer;
}

int main(void) {
    string numbers = "17";
    cout << solution(numbers);
}
