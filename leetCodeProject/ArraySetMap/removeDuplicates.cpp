//
// Created by a3412 on 2022/4/24.
//

#include <iostream>
#include <vector>

using namespace std;
/*
 * 要求是对给定的有序数组nums删除重复元素，在删除重复元素之后，每个元素只出现一次，并返回新的长度，需通过原地修改数组的方法；
 * 通过双指针：如果数组nums长度为0，即数组不包含任何元素，返回0；
 * 当数组长度大于0时，数组中至少包含一个元素，在删除重复元素之后也至少剩下一个元素，因此nums[0]保持原状，从下标1开始删除重复元素；
 * 定义左指针和右指针，右指针遍历数组到达下标位置，左指针下一个不同元素要填入的下标位置；
 * 右指针遍历1到n-1的每个位置，对于每个位置元素，满足nums[right] != nums[right-1],说明nums[right] 的值和之前都不相同，将nums[right]复
 * 制到nums[left], 然后left++ 即指向下一个位置, 遍历结束之后，从 \textit{nums}[0]nums[0] 到 \textit{nums}[\textit{slow}-1]nums[slow?1] 的每个元素都不相同且包含原数组中的每个不同的元素，
 * 因此新的长度即为 left，返回 left 即可
 */
class Solution {
public:
    // for(vector<int>::iterator it=vec.begin(); it!=vec.end(); it++)
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
