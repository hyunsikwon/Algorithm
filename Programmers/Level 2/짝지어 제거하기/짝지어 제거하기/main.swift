//
//  main.swift
//  짝지어 제거하기
//
//  Created by 원현식 on 2020/08/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let s = "cdcd"

print(solution(s))

func solution(_ s:String) -> Int{
    if s.count == 1 {
        return 0
    }
    
    var stack = [String]()
    
    for char in s {
        if !stack.isEmpty && stack.last! == String(char) {
            stack.removeLast()
        } else {
            stack.insert(String(char), at: stack.count)
        }
    }
    
    
    return stack.isEmpty ? 1 : 0
}

