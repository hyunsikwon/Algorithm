//
//  main.cpp
//  124 나라의 숫자_cpp
//
//  Created by 원현식 on 2020/11/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int c124[] = {1, 2, 4};

string solution(int n) {
    string answer = "";

    while (true) {
        n -= 1;
        int r = n % 3;
        answer = to_string(c124[r]) + answer;
        n/=3;
        
        if (n <= 0) {
            break;
        }
        
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    int n = 13;
    
    cout << solution(n) << '\n';

}
