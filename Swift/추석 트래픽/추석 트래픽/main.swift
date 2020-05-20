//
//  main.swift
//  추석 트래픽
//
//  Created by 원현식 on 2020/05/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let lines = [
"2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"
]
print(solution(lines))

func solution(_ lines:[String]) -> Int {
    
    var endTime = lines
    var proccessingTime = lines
    
    for i in 0..<endTime.count {
        for _ in 0..<11 {
            endTime[i].removeFirst()
        }
        for _ in 0..<7 {
            endTime[i].removeLast()
        }
    }
    for i in 0..<proccessingTime.count {
        for _ in 0..<24 {
            proccessingTime[i].removeFirst()
        }
        proccessingTime[i].removeLast()
    }
    
    print(endTime)
    print(proccessingTime)
    

    return 0
}

