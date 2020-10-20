//
//  main.cpp
//  큰 수 만들기_cpp
//
//  Created by 원현식 on 2020/10/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) {
    if (number.size()-1 == k) {
        int max = 0;
        for(char c: number) {
            if (c - '0' > max) {
                max = c - '0';
            }
        }
        return to_string(max);
    }
    
    string answer = "";
    int count = 0;
    stack<int> stack;
    for(int i = 0; i < number.size(); i++) {
        while (count < k && !stack.empty() && stack.top() < number[i]-'0') {
            stack.pop();
            count++;
        }
        
        if (count >= k) {
            for (int j = i; j < number.size(); j++) {
                stack.push(number[j]-'0');
            }
            break;
        } else {
            stack.push(number[i]-'0');
        }
        
    }
    
    while (!stack.empty()) {
        answer = to_string(stack.top()) + answer;
        stack.pop();
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    string number = "111119";
    int k = 3;
    
    cout << solution(number, k); // 775841
}
