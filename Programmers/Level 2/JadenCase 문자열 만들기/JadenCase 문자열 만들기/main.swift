//
//  main.swift
//  JadenCase 문자열 만들기
//
//  Created by 원현식 on 2020/08/11.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let s = "for the last week"

print(solution(s))

func solution(_ s: String) -> String {
    var answer = ""
    var check = true
    
    for char in s {
        if check == true {
            answer += String(char).uppercased()
            check = false
        } else {
            answer += String(char).lowercased()
        }
        
        if String(char) == " " {
            check = true
        }
    }

    return answer
}

