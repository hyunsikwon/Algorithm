//
//  main.swift
//  [카카오] 압축
//
//  Created by 원현식 on 2020/08/20.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

let msg =  "ABABABABABABABAB"

//"KAKAO" // 11, 1, 27, 15
// OUTPUT: [1, 2, 27, 29, 28, 31, 30]

print(solution(msg))

func solution(_ msg:String) -> [Int] {
    var result = [Int]()
    
    var dictionary = [
        "A", "B", "C", "D", "E", "F",
        "G", "H", "I", "J", "K", "L",
        "M", "N", "O", "P", "Q", "R",
        "S", "T", "U", "V", "W", "X",
        "Y", "Z" ]
    
    var message = [String]()
    
    for char in msg {
        message.append(String(char))
    }
    
    var w = message[0]
    var c = ""
    var i = 0
    
    while i < message.count {
        
        for j in i+1..<message.count {
            if !dictionary.contains(w+message[j]) {
                c = message[j]
                break
            } else {
                w = w+message[j]
                
            }
        }
        
        for k in 0..<dictionary.count {
            if dictionary[k] == w {
                result.append(k+1)
                break
            }
        }
        dictionary.append(w+c)
        
        
        i += w.count
        w = c
        
    }
    //    print(dictionary)
    
    return result
}


