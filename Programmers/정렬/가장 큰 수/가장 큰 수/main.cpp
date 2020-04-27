//
//  main.cpp
//  가장 큰 수
//
//  Created by 원현식 on 2020/04/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a+b > b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    
    for (int i = 0; i < numbers.size(); i++) {
        string str = to_string(numbers[i]);
        strings.push_back(str);
    }
    
    sort(strings.begin(), strings.end(),compare);
    
    for (int i = 0; i < strings.size(); i++) {
        answer += strings[i];
    }
    if (answer[0] == '0') return answer = "0";
    return answer;
}

int main(int argc, const char * argv[]) {
//    vector<int> numbers = {6, 10, 2};
//      vector<int> numbers = {1, 9, 3, 7};
    vector<int> numbers = {3, 30, 34, 5, 9};
    
    string a = "10";
    string b = "2";
    if (a > b) {
        cout << "Hello";
    } else {
        cout << "Hi";
    }
    
    cout << solution(numbers);
}
