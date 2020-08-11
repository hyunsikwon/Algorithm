//
//  main.swift
//  예상 대진표
//
//  Created by 원현식 on 2020/08/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 16, a = 1, b = 12 // 참가자 수, 참가자 번호, 경쟁자 번호

/*
 8강
        1
    1        2
   1 2      3 4
 1 2 3 4  5 6 7 8
 
 
 16강
                1
       1                    2
   1       2           3          4
 1   2   3   4      5    6     7     8
1 2 3 4 5 6 7 8   9 10 11 12 13 14 15 16
 
 */

// OUTPUT: 3
print(solution(n, a, b))


func solution(_ n:Int, _ a:Int, _ b:Int) -> Int {
    var answer = 0
    
    // 다른 시드
    if a <= (n/2) && b > (n/2) || b <= (n/2) && a > (n/2) {
        var temp = n/2
      
        while temp > 0 {
            temp /= 2
            answer += 1
        }
        
    } else { // 같은 시드면
        var newA = a > n/2 ? a-(n/2) : a
        var newB = b > n/2 ? b-(n/2) : b
        
        return solution(n/2, newA, newB)
    }
    
    return answer
}

