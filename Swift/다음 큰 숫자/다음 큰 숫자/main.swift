//
//  main.swift
//  다음 큰 숫자
//
//  Created by 원현식 on 2020/08/07.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 15

print(solution(n))

func solution(_ n:Int) -> Int {
    var answer = n + 1
    
    var count1 = 0
    var a = n
    
    while a > 0 {
        if a % 2 == 1 {
            count1 += 1
        }
        a /= 2
    }
    
    while answer > n {
        var temp = answer
        var count = 0
        
        while temp > 0 {
            if temp % 2 == 1 {
                count += 1
            }
            temp /= 2
        }
    
        if count == count1 {
            break
        }

        answer += 1
    }
    
    return answer
}

