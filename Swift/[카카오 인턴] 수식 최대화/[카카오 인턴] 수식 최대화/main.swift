//
//  main.swift
//  [카카오 인턴] 수식 최대화
//
//  Created by 원현식 on 2020/08/09.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let expression = "100-200*300-500+20"

// OUTPUT: 60420
print(solution(expression))

func solution(_ expression:String) -> Int64 {
    var answer: Int64 = 0
    var operators = ["*", "+", "-"]
    var priorities = [[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 1, 0], [2, 0, 1]]
    var opers = [String]()
    var nums = [Int]()
    
    var temp = ""
    for char in expression {
        if String(char) == "*" || String(char) == "+" || String(char) == "-" {
            opers.append(String(char))
            nums.append(Int(temp)!)
            temp = ""
        } else {
            temp += String(char)
        }
        
    }
    nums.append(Int(temp)!)
    

    for priority in priorities {
        for p in priority {
            var op = operators[p]
            
            for i in 0..<opers.count {
                if op == opers[i] {
                    
                }
            }
            
        }
    }
    
    
    return answer
}

