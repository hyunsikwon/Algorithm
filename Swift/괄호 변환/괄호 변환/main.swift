//
//  main.swift
//  괄호 변환
//
//  Created by 원현식 on 2020/07/08.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let p = "()))((()" // "(()())()"

// OUTPUT: (()())()"
print(solution(p))

// 올바른 문자열 확인
func isProper(_ p: String) -> Bool {
    let arr = p.map{String($0)}
    var stack = [String]()
    
    for value in arr {
        if value == "(" {
            stack.append(value)
        } else {
            if stack.isEmpty {
                return false
            } else {
                stack.removeLast()
            }
        }
    }
    
    if stack.isEmpty {
        return true
    }
    return false
}

// 균형잡인 문자열 확인
func isBalanced(_ p: String) -> Bool {
    var countLeft = 0
    var countRight = 0
    for char in p {
        if String(char) == "(" {
            countLeft += 1
        } else {
            countRight += 1
        }
    }
    
    return countLeft == countRight
}

func reversed(_ u: String) -> String {
    var temp = ""
    for char in u {
        if String(char) == "(" {
            temp += ")"
        } else {
            temp += "("
        }
    }
    return temp
}


func solution(_ p:String) -> String {
    if p == "" {
        return ""
    }
    
    if isProper(p) {
        return p
    }
    
    // 균형잡인 괄호 문자열 u,v로 나누기
        // u는 더 이상 나눠질 수 없는 균형잡인 문자열
        // v는 p에서 u를 뺀 나머지
    var u = ""
    var v = ""
    for i in 1...p.count {
        if isBalanced(String(p.prefix(i))) {
            u = String(p.prefix(i))
            v = p
            for j in 0..<i {
                v.removeFirst()
            }
            break
        }
    }
    

    if isProper(u) { // u가 올바른 괄호 문자열이라면
        u += solution(v)
        return u
    } else {  // 아니라면
        var temp = "("
        temp += solution(v)
        temp += ")"
        u.removeFirst()
        u.removeLast()
        let a = reversed(u)
        temp += a
        return temp
    }
    
}

