//
// Created by a3412 on 2022/5/1.
//

#include <iostream>
#include <list>

struct ListNode {
    int val;  //节点上存储的元素
    ListNode *next;  //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  //节点的构造函数
};