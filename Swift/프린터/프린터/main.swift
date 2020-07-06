//
//  main.swift
//  프린터
//
//  Created by 원현식 on 2020/07/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let priorities = [2, 1, 3, 2] // [1, 1, 9, 1, 1, 1]
let location = 2 // 0

print(solution(priorities, location))

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var answer = 0
    
    var sets = [(Int,Int)]() // 우선순위, 초기 위치
    
    for i in 0..<priorities.count {
        sets.append((priorities[i],i))
    }
    
    var results = [(Int,Int)]() // 인쇄 결과
    
    while !sets.isEmpty {
        let frontValue = sets.first!
        sets.removeFirst()
        var isMax = true
        
        for set in sets {
            if frontValue.0 < set.0 {
                isMax = false
                break
            }
        }
        
        if isMax == false {
            sets.insert(frontValue, at: sets.count)
        } else {
            results.append(frontValue)
        }
        
    }
    
    for i in 0..<results.count {
        if results[i].1 == location {
            answer = i+1
            break
        }
    }
    
    return answer
}
