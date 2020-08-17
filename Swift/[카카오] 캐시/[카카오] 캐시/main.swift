//
//  main.swift
//  [카카오] 캐시
//
//  Created by 원현식 on 2020/08/17.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let cacheSize = 2
let cities =  ["Jeju", "Pangyo", "NewYork", "newyork"]

// OUTPUT: 50
print(solution(cacheSize, cities))

func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    if cacheSize == 0 {
        return (cities.count * 5)
    }
    var cache = [String]()
    var answer = 0
    
    for i in 0..<cities.count {
        let current = cities[i].lowercased()
        
        if cache.contains(current) { // cache hit
            answer += 1
            if cache.count > 1 {
                for j in 0..<cache.count {
                    if cache[j] == current {
                        cache.remove(at: j)
                        break
                    }
                }
                cache.insert(current, at: 0)
            }
        } else { // miss
            answer += 5
            if cache.count == cacheSize { // 꽉 차있으면
                cache.removeLast()
                cache.insert(current, at: 0)
            } else {
                cache.insert(current, at: 0)
            }
           
        }
        
    }
    
    return answer
}

