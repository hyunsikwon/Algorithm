//
//  main.swift
//  올바른 괄호
//
//  Created by 원현식 on 2020/08/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let s = "(())()"

print(solution(s))

func solution(_ s:String) -> Bool {
    var ans: Bool = false
    var leftCount = 0
    var rightCount = 0
    
    for char in s {
        if String(char) == "(" {
            leftCount += 1
        } else {
            if leftCount > 0 {
                leftCount -= 1
            } else {
                ans = false
                return false
            }
        }
    }
    
    if leftCount > 0 {
        ans = false
    } else {
        ans = true
    }

    return ans
}
