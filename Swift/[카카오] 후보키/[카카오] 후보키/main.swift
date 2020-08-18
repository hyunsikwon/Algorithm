//
//  main.swift
//  [카카오] 후보키
//
//  Created by 원현식 on 2020/08/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let relation = [
    ["100","ryan","music","2"],
    ["200","apeach","math","2"],
    ["300","tube","computer","3"],
    ["400","con","computer","4"],
    ["500","muzi","music","3"],
    ["600","apeach","music","2"]
]

// OUTPUT: 2
print(solution(relation))

func solution(_ relation:[[String]]) -> Int {
    var candidateKey = [Int]()
    
    var row = relation.count
    var col = relation[0].count
    
    for i in 1 ..< Int(pow(2.0, Double(col))) {
        var tempSet = Set<String>()
        
        for j in 0..<row {
            var tmp = ""
            for k in 0..<col {
                if (i & (1 << k)) != 0 { // 0 0 1 1 이면 0001, 0010 일 때 0이 안됨. 즉 1의 위치의 값을 더하는 것
                    tmp += relation[j][k]
                }
            }
            tempSet.insert(tmp)
        }
        
        
        if tempSet.count == row {
            var contains = true
            
            // 후보키의 최소성 판정
            for num in candidateKey {
                if (num & i) == num {
                    contains = false
                    break
                }
            }
            
            if contains {
                candidateKey.append(i)
            }
        }
        
        
    }
    return candidateKey.count
}

