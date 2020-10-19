//
//  main.swift
//  큰 수 만들기
//
//  Created by 원현식 on 2020/07/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let number = "999"
let k = 2

// OUTPUT: 94
print(solution(number, k))


func solution(_ number:String, _ k:Int) -> String {
    
    var numbers = number.map{ String($0) }
    var stack = [String]()
    var count = 0
    
    for i in 0..<number.count {
        while count < k && !stack.isEmpty && stack.last! < numbers[i] {
            stack.removeLast()
            count += 1
        }
        
        if count >= k {
            print(numbers[i...])
            stack.append(contentsOf: numbers[i...])
            break
        } else {
            stack.append(numbers[i])
        }
    }
    
    var answer = String(stack.joined().prefix(number.count-k)) // 모든 수가 같을 때 예를들어 999, 2이면 9가 나오게 하기 위해서

    
    return answer
}

