//
//  main.swift
//  이중우선수위큐
//
//  Created by 원현식 on 2020/09/01.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ operations:[String]) -> [Int] {
    var queue = [Int]()

    for str in operations {
        var temp = str.split(separator: " ")
        let oper = String(temp.first!)
        let num = Int(temp.last!)!
        
        if oper == "I" {
            queue.append(num)
            queue.sort()
        } else {
            if queue.isEmpty {
                continue
            }
            
            if num == 1 {
                queue.removeLast()
            } else {
                queue.removeFirst()
            }
        }
    }
    
    if queue.isEmpty {
        return [0, 0]
    } else {
        return [queue.max()!, queue.min()!]
    }
    
}

let operations = ["I 16","D 1"]
// ["I 7","I 5","I -5","D -1"] [7,5]

// OUTPUT: [0, 0]
print(solution(operations))
