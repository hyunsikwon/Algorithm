//
//  main.cpp
//  JadenCase 문자열 만들기_cpp
//
//  Created by 원현식 on 2020/10/23.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool prevBlank = true;
    
    for(char c: s) {
        if (c == ' ') {
            answer += c;
            prevBlank = true;
            continue;
        }
        
        
        if (c - '0' >= 0 && c - '0' < 10) {
            answer += c;
            
        } else {
            if (prevBlank) {
                answer += toupper(c);
            } else {
                answer += tolower(c);
            }
        }
        
        prevBlank = false;
    }
    
    
    return answer;
}

int main(int argc, const char * argv[]) {
    string s = "3people unFollowed me";
    
    cout << solution(s) << '\n';
    
}
