//
//  main.swift
//  [카카오] n진수 게임
//
//  Created by 원현식 on 2020/08/22.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// 진법, 미리 구할 숫자의 갯수, 참여 인원, 순서
let n = 16, t = 16, m = 2, p = 2

// OUTPUT: 0111
print(solution(n, t, m, p))

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var result = ""
    let maxLength = m * t
    var nums = [String]()
    nums.append("0")
    nums.append("1")

    var currentLength = 2
    
    var i = 2
    while currentLength < maxLength {
        let a = String(i, radix: n)
        currentLength += a.count
        i += 1
        
        for char in a {
            nums.append(String(char).uppercased())
        }
    }
    
    print(nums)
    var j = p
    while result.count < t {
        result += nums[j-1]
        j+=m
    }
    
    return result
}
