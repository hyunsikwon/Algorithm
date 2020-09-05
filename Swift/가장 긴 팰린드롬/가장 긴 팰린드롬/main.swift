//
//  main.swift
//  가장 긴 팰린드롬
//
//  Created by 원현식 on 2020/09/03.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

func solution(_ s:String) -> Int {
    
    var max = 1
    let arr: [Character] = []+s
    if arr.count < 2 { return arr.count }
    
    for i in 1..<arr.count {
        
        if i != arr.count - 1 && arr[i-1] == arr[i+1] {
            var length = 2
            while i-length > -1 && i+length < arr.count {
                if arr[i-length] != arr[i+length] {
                    break
                }
                
                length += 1
            }
            length -= 1
            if length*2+1 > max {
                max = length*2+1
            }
        }
        
        if arr[i-1] == arr[i] { // abba 같은 경우
            var length = 1
            while i-length-1 > -1 && i+length < arr.count {
                if arr[i-length-1] != arr[i+length] {
                    break
                }
                length += 1
            }
            length -= 1
            if length*2+2 > max {
                max = length*2+2
            }
            
        }
        
    }
    
    return max
}

//let s = "abcdcba"
//// ANSWER: 7
//print(solution(s))


let s = "aa"
// ANSWER: 3
print(solution(s))
