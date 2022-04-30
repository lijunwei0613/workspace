//
// Created by a3412 on 2022/4/23.
//

#include <iostream>
#include <vector>


// 删除数组中等于val的元素，因此输出数组的长度一定小于等用途输出数组的长度->把输出数组直接写在输入数组上。
// 使用双指针：右指针right指向当前要处理的元素，左指针left指向下一个将要赋值的位置。
/*
    *如果右指针指向的元素不等于val, 它一定是输出数组的一个元素，就将右指针指向的元素复制到左指针位置，然后将左右指针同时右移；
    *如果右指针指向的元素等于val, 它不能在输出数组里，此时左指针不动，右指针右移一位；
 */
// 区间[0, left)中的元素都不等于val,当左右指针遍历完输入数组以后，left的值就是输出数组的长度；最坏情况是（输入数组中没有元素等于val）, 左右指针各遍历了数组一次；

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


/*
 * 如果左指针left指向的元素等于val, 此时将右指针right指向的元素复制到左指针left位置，然后右指针right左移一位。如果赋值过来的元素恰好也等于val,
 * 可以继续将右指针right指向的元素的值赋值过来（左指针left指向的等于val的元素的位置继续被覆盖），直到左指针指向的元素值不等于val为止；
 * 当左右指针重合的时候，左右指针遍历数组中所有的元素；
 * 避免了需要保留的元素的重复赋值操作；
*/
class Slution01 {
public:
    int removeElement01(std::vector<int> &nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                //如果左指针left指向的元素等于val, 将右指针right指向的元素复制到左指针left位置，然后右指针左移动一位；
                nums[left] = nums[right - 1]; //数组元素的个数等于数组长度-1；
                right--;
            } else {
                left++;
            }
        }
        return left;
    }

};

//

int main() {
//模拟qiaohong关于右值引用中的数组传入方法，vector赋值；
    Solution p1;
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);

    int a[] = {3, 2, 2,3};
    std::vector<int> vect(a, a + sizeof(a) / sizeof (int));
    Solution p2;
    std::cout << "p2：" << p2.removeElement(vect, 3) << std::endl;



    int len = vec.size();
    std::cout << "移除前vec的长度：" << len << std::endl;

    p1.removeElement(vec, 3);

    for (int i: vec) {
        std::cout << "vec[i]: " << i << std::endl;
    }
    std::cout << "移除后vec的长度：" << vec.size() << std::endl;

    return 0;
}