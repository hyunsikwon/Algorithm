//
//  main.swift
//  여행경로
//
//  Created by 원현식 on 2020/08/27.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let tickets =  [["ICN", "D"], ["D", "C"], ["C","ICN"], ["ICN","B"], ["B", "E"]]

// OUTPUT: ICN, ATL, ICN, SFO, ATL, SFO
print(solution(tickets))

func dfs(_ count: Int,
         _ current: String,
         _ tickets: [[String]],
         _ visited: inout [Bool],
         _ route: inout [String] ,
         _ temp: inout [String]) {
    
    temp.append(current)
    
    if count == tickets.count {
        route = temp
        return
    }
    
    for i in 0..<tickets.count where route.isEmpty {
        let departures = tickets[i][0]
        let arrivals = tickets[i][1]
        
        if departures == current, visited[i] == false {
            visited[i] = true
            dfs(count+1, arrivals, tickets, &visited, &route, &temp)
            visited[i] = false
        }
        
    }
    
    temp.removeLast()
}

func solution(_ tickets:[[String]]) -> [String] {
    var route = [String]()
    var visited = Array(repeating: false, count: tickets.count)
    var temp = [String]()
    var sortedTickets = tickets.sorted{ $0[1] < $1[1] }
    print(sortedTickets)
    dfs(0, "ICN", sortedTickets, &visited, &route, &temp)
    
    return route
}



// 실패 코드
//func solution(_ tickets:[[String]]) -> [String] {
//    var route = [String]()
//    var ticketsInfo: [String: [String]] = [:]
//
//    for ticket in tickets {
//        if ticketsInfo[ticket[0]] == nil {
//            ticketsInfo[ticket[0]] = [ticket[1]]
//        } else {
//            ticketsInfo[ticket[0]]?.append(ticket[1])
//            ticketsInfo[ticket[0]]!.sort()
//        }
//
//    }
//
//    var temp = [String]()
//    temp.append("ICN")
//
//    while !temp.isEmpty  {
//        let current = temp.first!
//        temp.removeFirst()
//        route.append(current)
//
//        if ticketsInfo[current] != nil {
//            if !ticketsInfo[current]!.isEmpty {
//                for i in 0..<ticketsInfo[current]!.count {
//                    let destination = ticketsInfo[current]![i]
//
//                    if ticketsInfo[destination] == nil || ticketsInfo[destination]!.isEmpty {
//                        if ticketsInfo[current]!.count == 1 {
//                            temp.append(destination)
//                            break
//                        } else {
//                            continue
//                        }
//
//                    } else {
//                        temp.append(destination)
//                        ticketsInfo[current]!.remove(at: i)
//
//                        break
//                    }
//
//                }
//
//            }
//        }
//
//    }
//
//
//    return route
//}
