//
// Created by a3412 on 2022/4/5.
//
#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    ~Test() {
        cout << "����\n";
    }
};




int main() {
    std::unique_ptr<int> up1(new int(11));  //��������ָ�����
//    std::cout << *up1 << std::endl;

    {
        unique_ptr<Test> up2(new Test);  //�����ͷţ��Զ��ͷ�
        cout << "ָ���ڴ��Զ��ͷ�" << endl;
        //�ֶ��ͷţ�
//        up2 = nullptr;
//        up2 = NULL;
        up2.reset();
        cout << "ָ���ڴ��ֶ��ͷ�" << endl;


    }
}

