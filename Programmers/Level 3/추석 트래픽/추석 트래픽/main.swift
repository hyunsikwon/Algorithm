//
//  main.swift
//  추석 트래픽
//
//  Created by 원현식 on 2020/05/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

// INPUT
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
// OUTPUT: 7
print(solution(lines))

func solution(_ lines:[String]) -> Int {
    
    var timeLogs = [(start: Date, end: Date)]()
    var timeStamps = [Date]()
    
    getTime(lines, &timeLogs, &timeStamps)
    
    return getMax(timeLogs, timeStamps)
}

func getTime(_ lines: [String],
             _ timelogs: inout [(start: Date, end: Date)],
             _ timeStamps: inout [Date] )
{
    let formatter = DateFormatter()
    formatter.dateFormat = "yyy-MM-dd HH:mm:ss.SSS"
    
    lines.forEach { log in
        let logList = log.split(separator: " ")
        let day = logList[0]
        let time = logList[1]
        
        if let endDate = formatter.date(from: "\(day) \(time)"),
            let proccessTime = Double(logList[2].dropLast()){
            let startDate = endDate.addingTimeInterval(-proccessTime + 0.001)
            
            timelogs.append((startDate,endDate))
            timeStamps.append(startDate)
            timeStamps.append(endDate)
        }
    }
}

func getMax(_ timeLogs: [(start: Date, end: Date)], _ timeStamp: [Date]) -> Int {
    var max = 0
    
    for i in 0..<timeStamp.count { // 시작 시간, 종료 시간
        var count = 0
        for j in 0..<timeLogs.count
            where timeLogs[j].start <= timeStamp[i].addingTimeInterval(0.999) && timeLogs[j].end >= timeStamp[i]
            {
                count += 1
            }
        
        if count > max {
            max = count
        }
        
    }
    
    return max
}
