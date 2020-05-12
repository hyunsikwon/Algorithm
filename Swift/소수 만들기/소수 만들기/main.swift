//
//  main.swift
//  소수 만들기
//
//  Created by 원현식 on 2020/05/12.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let nums = [1,2,7,6,4]

print(solution(nums))

func isPrime(_ a: Int) -> Bool {
    for i in 2..<a {
        if a % i == 0 {
            return false
        }
    }
    return true
}

func solution(_ nums:[Int]) -> Int {
    var answer = 0

    for i in 0..<nums.count {
        for j in i+1..<nums.count {
            for k in j+1..<nums.count {
                let sum = nums[i] + nums[j] + nums[k]
                print("\(nums[i]) \(nums[j]) \(nums[k])")
                if isPrime(sum) {
                    answer+=1
                }
            }
        }
    }
    
    return answer
}
