//
//  main.swift
//  피보나치 수
//
//  Created by 원현식 on 2020/08/09.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation


func solution(_ n:Int) -> Int {
    var fibonacci = [0, 1]
    
    for i in 2...n {
        fibonacci.append((fibonacci[i-2] + fibonacci[i-1]) % 1234567)
    }
    
    return fibonacci[n]
}

