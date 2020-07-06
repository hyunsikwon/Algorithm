//
//  main.swift
//  기능개발
//
//  Created by 원현식 on 2020/07/06.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let progresses = [5, 5, 5]
let speeds = [21, 25, 20]

// Output: [2, 1]
print(solution(progresses, speeds))

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var result = [Int]()
    var release = [Int]()
    
    for i in 0..<progresses.count {
        var n = 1
        let progress = progresses[i]
        while progress + speeds[i]*n < 100 {
            n += 1
        }
        release.append(n)
    }
    

    
    if release.count == 1 {
        return [1]
        
    } else if release.count > 1{
        var front = release[0]
        var count = 1
        for i in 1..<release.count {
            if front >= release[i] {
                count += 1
            } else {
                result.append(count)
                front = release[i]
                count = 1
            }
            if i == release.count - 1 {
                result.append(count)
            }
        }
        
        return result
    }
    
    return result
}
