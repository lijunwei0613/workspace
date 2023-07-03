//
// Created by a3412 on 2022/4/5.
//
#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    ~Test() {
        cout << "析构\n";
    }
};




int main() {
    std::unique_ptr<int> up1(new int(11));  //创建智能指针对象；
//    std::cout << *up1 << std::endl;

    {
        unique_ptr<Test> up2(new Test);  //无需释放，自动释放
        cout << "指针内存自动释放" << endl;
        //手动释放；
//        up2 = nullptr;
//        up2 = NULL;
        up2.reset();
        cout << "指针内存手动释放" << endl;


    }
}

