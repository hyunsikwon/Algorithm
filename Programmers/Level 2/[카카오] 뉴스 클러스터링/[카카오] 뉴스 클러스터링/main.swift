//
//  main.swift
//  [카카오] 뉴스 클러스터링
//
//  Created by 원현식 on 2020/08/13.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let str1 = "french dd"
let str2 = "FRANCE DDD"

//OUTPUT: 16384
print(solution(str1, str2))

func solution(_ str1:String, _ str2:String) -> Int {
    var answer = 0.0
    
    let dic1 = makeDictionary(str1)
    let dic2 = makeDictionary(str2)

    var intersection = [String]()
    var union = [String]()
    
//    print(dic1)
//    print(dic2)
    
    if dic1.count == 0 && dic2.count == 0 {
        return 1*65536
    }
    
    for a in dic1 {
        let key = a.key
        let value = a.value

        if dic2[key] != nil {
            let min = value < dic2[key]! ? value : dic2[key]!
            let max = value > dic2[key]! ? value : dic2[key]!
            for _ in 0..<min {
                intersection.append(key)
            }
            for _ in 0..<max {
                union.append(key)
            }
        } else {
            for _ in 0..<value {
             union.append(key)
            }
        }
    }
    
    for a in dic2 {
        let key = a.key
        let value = a.value
        
        if !union.contains(key) {
            for _ in 0..<value {
             union.append(key)
            }
        }
        
    }

//    print(intersection)
//    print(union)
    
    answer = (Double(intersection.count)/Double(union.count))*65536
    
    return Int(answer)
}

func makeDictionary(_ str: String) -> [String: Int] {
    let lowerStr = str.lowercased()
    var arr = [String]()
    var temp = ""
    
    for char in lowerStr {
        let ch = String(char)
        
        if ch >= "a" && ch <= "z" {
            if temp.count < 2 {
                temp += ch
                if temp.count == 2 {
                    arr.append(temp)
                    temp = ch
                }
            }
        } else {
            temp = ""
        }
    }
    
    var dic = [String: Int]()
    for i in 0..<arr.count {
        let value = arr[i]
        var count = 0
        for v in arr {
            if value == v {
                count += 1
            }
        }
        dic[value] = count
    }
    return dic
}
