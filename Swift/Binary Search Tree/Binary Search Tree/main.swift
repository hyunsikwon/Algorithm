//
//  main.swift
//  Binary Search Tree
//
//  Created by 원현식 on 2020/05/25.
//  Copyright © 2020 Hyunsik Won. All rights reserved.
//

import Foundation

class BinarySearchTree<T: Comparable> {
    var value: T
    var leftChild: BinarySearchTree?
    var rightChild: BinarySearchTree?
    
    init(value: T) {
        self.value = value
    }
    
    func insert(_ value: T) {
        if value < self.value {
            if self.leftChild != nil {
                self.leftChild?.insert(value)
            } else {
                self.leftChild = BinarySearchTree(value: value)
            }
        } else if value > self.value{
            if self.rightChild != nil {
                self.rightChild?.insert(value)
            } else {
                self.rightChild = BinarySearchTree(value: value)
            }
        }
    }
    
    // contains
    func contains(_ value: T) -> Bool {
        if self.value == value {
            return true
        }
        if value < self.value {
            guard let leftChild = self.leftChild else { return false }
            return leftChild.contains(value)
        } else {
            guard let rightChild = self.rightChild else { return false }
            return rightChild.contains(value)
        }
    }
    
    // print
    func printNode() {
        if self.leftChild != nil {
            leftChild?.printNode()
        }
        print(self.value, terminator: " ")
        if self.rightChild != nil {
            rightChild?.printNode()
        }
    }
    
    // remove
    func remove(_ value: T, parent: BinarySearchTree) {
        if value < self.value {
            guard let leftChild = self.leftChild else {return}
            leftChild.remove(value, parent: self)
        } else if value > self.value {
            guard let rightChild = self.rightChild else {return}
            rightChild.remove(value, parent: self)
        } else {
            // 자식이 두개 있을 경우
            if self.leftChild != nil && self.rightChild != nil {
                let tempValue = self.rightChild!.getLeftMostChild()
                self.value = tempValue
                self.rightChild?.remove(tempValue, parent: self)
                
            } else {
                // 자식이 없거나, 하나만 있을 경우
                let child = self.leftChild == nil ? self.rightChild : self.leftChild
                if self.value < parent.value {
                    parent.leftChild = child
                } else {
                    parent.rightChild = child
                }
                
            }
        }
    }
    
    func getLeftMostChild() -> T {
        guard let leftChild = self.leftChild else { return self.value }
        return leftChild.getLeftMostChild()
    }
    
}

let root = BinarySearchTree(value: 4)
let arr = [7, 2, 4, 9, 15, 13, 5, 1, 3, 8]

for i in arr {
    root.insert(i)
}

root.printNode()
root.remove(7, parent: root.self); print()
root.printNode()

