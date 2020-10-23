//
//  main.cpp
//  짝지어 제거하기_cpp
//
//  Created by 원현식 on 2020/10/23.
//

#include <iostream>
#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            temp += s[i];
            continue;
        }
        
        if (s[i] == temp.back()) {
            temp.pop_back();
        } else {
            temp += s[i];
        }
        
    }
        
    return temp.empty() ? 1 : 0;;
}

int main(int argc, const char * argv[]) {
    string s = "cdcd";
    
    cout << solution(s) << '\n'; // 1
}
