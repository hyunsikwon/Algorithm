//
//  main.swift
//  위장
//
//  Created by 원현식 on 2020/07/09.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let clothes = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]

// OUTPUT: 5
print(solution(clothes))

func solution(_ clothes:[[String]]) -> Int {
    var hash = [String: Int]()

    clothes.forEach { element in
        if hash.keys.contains(element[1]) {
            hash[element[1]]! += 1
        } else {
            hash[element[1]] = 1
        }
    }
    
    var answer = 1
    for value in hash.values { // 1: A, B, * 2: C, * --> (A,C) / (A, *) / (B, C) / (B, *) / (*, *) 1을 빼는 이유
        answer *= (value+1)
    }
  
    
    return answer - 1
}


