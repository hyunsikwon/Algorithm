//
//  main.swift
//  [카카오] 방금그곡
//
//  Created by 원현식 on 2020/08/19.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let m = "ABC#"
let musicinfos = ["03:00,03:30,FOO,ABCABC#", "04:00,04:08,BAR,ABC#C"]

// OUTPUT: HELLO
print(solution(m, musicinfos))


func solution(_ m:String, _ musicinfos:[String]) -> String {
    var result = "'(None)'"
    var musicInfo = [[String]]()

    
    for str in musicinfos {
        let arr = str.split(separator: ",")
        
        // 시간 구하기
        let startTime = arr[0].split(separator: ":")
        let endTime = arr[1].split(separator: ":")
        let interval = (Int(endTime[0])!-Int(startTime[0])!)*60 + Int(endTime[1])!-Int(startTime[1])!
        // 악보 구하기
        let melody = String(arr[3])
        var former = ""
        var scores = [String]()
        
        for char in melody {
            if String(char) == "#" {
                if former >= "A" && former <= "G" {
                    former = former.lowercased()
                }
            } else {
                if former != "" {

                    scores.append(former)
                }
                former = String(char)
            }
            
        }
        scores.append(former)
        print(scores)
        
        var temp = ""
        for i in 0..<interval {
            temp += scores[(i % scores.count)]
        }
        
        let musicName = String(arr[2])
        musicInfo.append([temp, musicName,String(interval)])
    }
    
    print(musicInfo)
    
    
    // 치환 과정
    var M = ""
    var former = ""
    for char in m {
        if String(char) == "#" {
            if former >= "A" && former <= "G" {
                former = former.lowercased()
            }
        } else {
            if former != "" {
                M += former
            }
            former = String(char)
        }
        
    }
    
    M += former
    var max = 0
    for arr in musicInfo {
        let interval = Int(arr[2])!
        if arr[0].contains(M) {
            if interval > max {
                result = arr[1]
                max = interval
            }
            
        }
    }
    
    return result
}
