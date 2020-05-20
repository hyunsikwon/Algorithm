//
//  main.swift
//  Skill Check Lv.1
//
//  Created by 원현식 on 2020/05/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let n = 6
let arr1 = [46, 33, 33 ,22, 31, 50]
let arr2 = [27 ,56, 19, 14, 14, 10]
print(solution(n,arr1,arr2))

func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer: [String] = []
    var arr1Binary = [String]()
    var arr2Binary = [String]()
    
    for value in arr1 {
        var i  = value
        var tempStr = ""
        while i > 0 {
            tempStr += String(i % 2)
            i/=2
        }
        while tempStr.count < n {
            tempStr += "0"
        }
        arr1Binary.append(tempStr)
        
    }
    for value in arr2 {
        var i  = value
        var tempStr = ""
        while i > 0 {
            tempStr += String(i % 2)
            i/=2
        }
        while tempStr.count < n {
            tempStr += "0"
        }
        arr2Binary.append(tempStr)
        
    }
    
    for i in 0..<arr1Binary.count {
        var value1 = arr1Binary[i]
        var value2 = arr2Binary[i]
        var tempStr = ""
        for _ in 0..<value1.count {
            if value1.last! == "1" || value2.last == "1" {
                tempStr += "#"
            } else {
                tempStr += " "
            }
            value1.removeLast()
            value2.removeLast()
        }
        answer.append(tempStr)
    }
    
    return answer
}

