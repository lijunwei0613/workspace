//
// Created by a3412 on 2022/5/1.
//
/*
 * 给定一个整数数组nums和一个整数目标值target, 请你在该数组中找出和为目标值target的那两个整数，并返回他们的数组下标。
 */
#include <iostream>
//#include <algorithm>
#include <vector>
#include <unordered_map>
/*
 * 两数之和之查找表法
 * 在遍历的同时记录一些信息，以省去一层循环，这是“以空间换时间”的想法；
 * 需要记录已经遍历过的数指和它所对应的下标，可以借助查找表实现
 * 常用查找表实现：
 * 哈希表
 * 平衡二叉搜索树
 *
 */

using namespace std;
//map中所有元素都会根据元素的键值自动排序；map中不允许有重复的键值，multimap中允许容器中有重复的键值；底层实现都是二叉树；
//unordered_map中 key是无序的，且key值是不可重复的；


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            //定义一个迭代器，查找数组中目标值-数组元素值，若map中没有元素与之对应则将当前遍历到的该数组元素值（key）以及对应的下标(value)插入哈希表中
            //直至遍历数组元素，目标值-当前数组元素值的差值出现在哈希表中，则当前遍历到的数组元素值和差值就是要查找到的两个元素值和遍历时对应的下标值；

            //ps：要理解在遍历数组的过程中，在没找到对应值之前将数组元素和下标插入哈希表中，在继续遍历下面的元素中，在哈希表找到匹配的对组，返回迭代器，访问second（value），以及遍历到当前数组元素的下标i;
            auto iter = map.find(target - nums[i]);  //查找key为（target - nums[i]）的对组；
            /*
             *    迭代器是一种检查容器内元素并遍历元素的数据类型，标准库中每一种标准容器（如vector）定义了一种迭代器类型
             *    *iter                //对iter进行解引用，返回迭代器iter指向的元素的引用
             *    iter->men            //对iter进行解引用，获取指定元素中名为men的成员。等效于(*iter).men
             */
            if (iter != map.end()) {  //表示找到对应的元素值 通过 !=map.end()来判断找到了，可理解为遍历过程中找到
                cout << "find it!" << endl;
                //find()算法找到了，返回该位置元素的迭代器。
                cout << iter->second << " " << i << endl; //打印iter->second是获取找到的返回迭代器中的value值-下标值。
                return {iter->second, i};
            }
            else{  //从头找到尾部，没找到，返回一个end()迭代器，就是容器结束的位置。
                cout << "can't find it! iter = map.end()" << endl;
            }
            //在哈希表中查询到target-x的目标值之前, 将x及对应的下标值插入哈希表中，即可保证不会让x和自己匹配；
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main(){
    vector<int> num = {2,15,11,7};
    int val = 9;
    Solution p1;
    p1.twoSum(num, val);

}