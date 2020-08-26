//
//  main.swift
//  디스크 컨트롤러
//
//  Created by 원현식 on 2020/08/26.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let jobs = [[0,10], [4, 10], [5,11], [15, 2]]
// 10 -> 26 -> 33 -> 61
// 10 -> 20 -> 22 -> 33

// OUTPUT: 9
print(solution(jobs))

func solution(_ jobs:[[Int]]) -> Int {
    
    var sortedJobs = jobs.sorted { (a, b) -> Bool in
        if a[1] == b[1] {
            return a[0] < b[0]
        } else {
            return a[1] < b[1]
        }
    }
   
    var current = 0
    var total = 0
    while !sortedJobs.isEmpty {
        print(sortedJobs)
        for i in 0..<sortedJobs.count {
            let arrivalTime = sortedJobs[i][0]
            let duration = sortedJobs[i][1]
            
            if arrivalTime <= current {
                total += current - arrivalTime + duration
                current += duration
                sortedJobs.remove(at: i)
                break
            }
            
            if i == sortedJobs.count-1 {
                current += 1
            }
            
        }
        
        
    }
    
    return total / jobs.count
}

