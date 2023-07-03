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

class CBase {
public:
    CBase() {}

    virtual ~CBase() {}

    void myBase() {
        cout << "CBase::myBase" << endl;
    }
};

class CDerive : public CBase {
public:
    CDerive() {}

    ~CDerive() {}

    void myDerive() {
        cout << "CDerive::myDerive" << endl;
    }
};


int main() {
//    std::unique_ptr<int> up1(new int(11));  //��������ָ�����
//    std::cout << *up1 << std::endl;

//    {
//        unique_ptr<Test> up2(new Test);  //�����ͷţ��Զ��ͷ�
//        cout << "ָ���ڴ��Զ��ͷ�" << endl;
        //�ֶ��ͷţ�
//        up2 = nullptr;
//        up2 = NULL;
//        up2.reset();
//        cout << "ָ���ڴ��ֶ��ͷ�" << endl;
//    }

    //���е�ת���������ൽ�����ת����
//    shared_ptr<CDerive> spDeriveUp;
//    shared_ptr<CBase> spBaseUp;
    shared_ptr<CDerive> spDeriveUp = make_shared<CDerive>();
    shared_ptr<CBase> spBaseUp = dynamic_pointer_cast<CBase>(spDeriveUp);
    spBaseUp->myBase();

    //���е�ת�������ൽ�������ת��)
//    shared_ptr<CDerive> spDeriveDown;
//    shared_ptr<CBase> spBaseDown;
    shared_ptr<CBase> spBaseDown = make_shared<CBase>();
    shared_ptr<CDerive> spDeriveDown = dynamic_pointer_cast<CDerive>(spBaseDown);
    if (spDeriveDown == nullptr)	//���ڻ�������͵ļ�飬����Ƿ���nullptr
        cout << "spDeriveDown is null" << endl;


//    shared_ptr<CDerive> spDeriveDown;
//    shared_ptr<CBase> spBaseDown;
//    shared_ptr<CBase> spBaseDown = make_shared<CDerive>();
//    shared_ptr<CDerive> spDeriveDown = dynamic_pointer_cast<CDerive>(spBaseDown);
//    if (spDeriveDown == nullptr)	//���ڻ�������͵ļ�飬����Ƿ���NULL
//        cout << "spDeriveDown is null" << endl;
//    spDeriveDown->myDerive();


    return 0;
}

