//
//  main.swift
//  최댓값과 최솟값
//
//  Created by 원현식 on 2020/08/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let s = "-1 -2 3 4"

print(solution(s))

func solution(_ s:String) -> String {
    var answer = ""
    var arr = [Int]()
    
    for value in s.split(separator: " ") {
        arr.append(Int(value)!)
    }
    
    answer += "\(arr.min()!) \(arr.max()!)"

    return answer
}

