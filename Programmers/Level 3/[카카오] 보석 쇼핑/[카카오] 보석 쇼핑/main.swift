//
//  main.swift
//  [카카오] 보석 쇼핑
//
//  Created by 원현식 on 2020/10/24.
//

import Foundation



func solution(_ gems:[String]) -> [Int] {
    var set = Set<String>()
    var answer = [Int](repeating: 0, count: 2)
    for gem in gems {
        set.insert(gem)
    }
    
    let k = set.count
    var i = 0, j = 0
    
    if k == 1 {
        return [1, 1]
    }
    
    if k == gems.count {
        return [1, gems.count]
    }
    
    var temp = [String: Int]()
    var range = 100000
    temp[gems[i]] = 1
    while true {
        if temp.count >= k {
            if abs(i-j) < range {
                range = abs(i-j)
                answer[0] = i+1
                answer[1] = j+1
            }
            
            if temp[gems[i]]! > 1 {
                temp[gems[i]]! -= 1
            } else if temp[gems[i]]! == 1{
                temp[gems[i]] = nil

            }
            i+=1
        } else {
            j+=1
            if j >= gems.count {
                break
            }
            
            if temp[gems[j]] == nil {
                temp[gems[j]] = 1
            } else {
                temp[gems[j]]! += 1

            }
        }
        

        
    }
 
    return answer
}

let gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]

print(solution(gems)) // 3 7


