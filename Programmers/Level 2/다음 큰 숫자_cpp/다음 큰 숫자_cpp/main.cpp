//
//  main.cpp
//  다음 큰 숫자_cpp
//
//  Created by 원현식 on 2020/10/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int count = 0;
    int temp = n;
    while(temp > 0) {
        if(temp%2 == 1) {
            count++;
        }
        temp /= 2;
    }
    
    int answer = n+1;
    for(int i = n+1; i < 1000001; i++) {
        int temp = i;
        int tmpCount = 0;
        while(temp > 0) {
            if(temp % 2 == 1) {
                tmpCount++;
            }
            temp/=2;
        }
        
        if(tmpCount == count) {
            answer = i;
            break;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
