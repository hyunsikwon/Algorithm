//
//  main.swift
//  문자열 압축
//
//  Created by 원현식 on 2020/07/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let s = "xa"

// OUTPUT: 17
print(solution(s))

func solution(_ s: String) -> Int {
    if s.count <= 1 {
        return 1
    }
    
    let length = s.count
    var arr = [String]()
    var answer = length // 최대 값
    
    for char in s {
        arr.append(String(char))
    }
    
    for i in 1...length-1 {
        var temp = ""
        var j = 0
        for str in arr {
            if j != 0 && j % i == 0 {
                temp += "-"
            }
            j+=1
            temp += str
        }
        
        var splited = temp.split(separator: "-")
        
        var result = ""
        var current = splited[0]
        var count = 1
        
        for k in 1..<splited.count {
            if current == splited[k] {
                count += 1
            } else {
                if count == 1 {
                    result += "\(current)"
                    
                } else {
                    result += "\(count)\(current)"
                }
                
                current = splited[k]
                count = 1
            }
            
            if k == splited.count-1 {
                if count == 1 {
                    result += "\(current)"
                    
                } else {
                    result += "\(count)\(current)"
                    
                }
            }
        }
        answer = result.count < answer ? result.count : answer
        
    }
    
    return answer
}

