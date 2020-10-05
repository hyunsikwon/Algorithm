//
//  main.cpp
//  [카카오] 문자열 압축_cpp
//
//  Created by 원현식 on 2020/10/05.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    if (s.length() < 2) {
        return 1;
    }
    
    int answer = s.length();
    
    for (int i = 1; i <= s.length()/2; i++) {
        int remainder = s.length() % i;
        string former = "";
        for (int j = 0; j < i; j++) {
            former += string(1, s[j]);
        }
        
        string current = "";
        int temp = 0;
        int formerCount = 1;
        
        for (int j = i; j < s.length()-remainder; j++) {
            current += string(1, s[j]);
            
            if (current.length() == former.length()) {
                if (former == current) {
                    formerCount++;
                    if (j == s.length()-remainder-1) {
                        temp += former.length() + to_string(formerCount).length();
                    }
                    
                } else {
                    if (formerCount == 1) {
                        temp += former.length();
                    } else {
                        temp += former.length() + to_string(formerCount).length();
                    }
                    
                    if (j == s.length()-remainder-1) {
                        temp += current.length();
                    }
                    
                    former = current;
                    formerCount = 1;

                }
                current = "";
            }
            
        }
        
        temp += remainder;
        
        if (temp < answer) {
            answer = temp;
        }
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    string s = "ababcdcdababcdcd"; 
    cout << solution(s); // 9
}
