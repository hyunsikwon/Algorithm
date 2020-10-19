//
//  main.cpp
//  괄호 변환_cpp
//
//  Created by 원현식 on 2020/10/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isBalanced(string s) {
    int left = 0, right = 0;
    
    for(char c: s) {
        if (c == '(') {
            left++;
        } else {
            right++;
        }
    }
    return left == right;
}

bool isCorrect(string s) {
    stack<char> stck;
    
    for(char c: s) {
        if (c == '(') {
            stck.push(c);
        } else {
            if (stck.empty()) {
                return false;
            } else {
                stck.pop();
            }
        }
    }
    
    if (stck.empty()) {
        return true;
    }
    
    return false;
}

string reversed(string s) {
    string reversed = "";
   
    
    for(int i = 1; i < s.size()-1; i++) {
        if (s[i] == '(') {
            reversed += ')';
        } else {
            reversed += '(';
        }
    }
    
    return reversed;
}

string solution(string p) {
    if(p == "") return "";
    
    string answer = "";
    string u = "";
    string v = "";
 
    for (int i = 0; i < p.size(); i++) {
        if (i == 0) {
            u += p[i];
            continue;
        }
        
        if (isBalanced(u)) {
            v += p[i];
        } else {
            u += p[i];
        }
        
    }

    if (isCorrect(u)) {
        answer += u;
        while (answer.size() != p.size()) {
            answer += solution(v);
        }
    } else {
        string temp = "(";
        temp += solution(v);
        temp += ")";
        temp += reversed(u);
        
        answer = temp;
    }

    return answer;
}



int main(int argc, const char * argv[]) {
    string p = "()))((()";
    
    cout << solution(p) << '\n';
  

}
