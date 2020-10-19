//
//  main.swift
//  [카카오] 오픈채팅방
//
//  Created by 원현식 on 2020/08/18.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let record = ["Enter uid1234 Muzi",
              "Enter uid4567 Prodo",
              "Leave uid1234",
              "Enter uid1234 Prodo",
              "Change uid4567 Ryan"]

// OUTPUT:
print(solution(record))
/*
 ["Prodo님이 들어왔습니다.",
 "Ryan님이 들어왔습니다.",
 "Prodo님이 나갔습니다.",
 "Prodo님이 들어왔습니다."]
 */

func solution(_ record:[String]) -> [String] {
    var answer = [String]()
    let enter = "님이 들어왔습니다."
    let leave = "님이 나갔습니다."
    var dic = [String: String]()
        
    for str in record {
        let tmp = str.split(separator: " ")
        let state = String(tmp[0])
        let uid = String(tmp[1])
        if state == "Enter" {
            dic[uid] = String(tmp[2])
            
        } else if state == "Change" {
            dic[uid] = String(tmp[2])
        }
    }
    
    for str in record {
        let tmp = str.split(separator: " ")
        let state = String(tmp[0])
        let uid = String(tmp[1])
        let nickname = dic[uid]!
        
        if state == "Enter" {
            answer.append("\(nickname)\(enter)")
            
        } else if state == "Leave" {
            answer.append("\(nickname)\(leave)")
        }
    }
    
    return answer
}

