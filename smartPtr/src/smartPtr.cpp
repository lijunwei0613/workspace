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
//    std::unique_ptr<int> up1(new int(11));  //创建智能指针对象；
//    std::cout << *up1 << std::endl;

//    {
//        unique_ptr<Test> up2(new Test);  //无需释放，自动释放
//        cout << "指针内存自动释放" << endl;
        //手动释放；
//        up2 = nullptr;
//        up2 = NULL;
//        up2.reset();
//        cout << "指针内存手动释放" << endl;
//    }

    //上行的转换（派生类到基类的转换）
//    shared_ptr<CDerive> spDeriveUp;
//    shared_ptr<CBase> spBaseUp;
    shared_ptr<CDerive> spDeriveUp = make_shared<CDerive>();
    shared_ptr<CBase> spBaseUp = dynamic_pointer_cast<CBase>(spDeriveUp);
    spBaseUp->myBase();

    //下行的转换（基类到派生类的转换)
//    shared_ptr<CDerive> spDeriveDown;
//    shared_ptr<CBase> spBaseDown;
    shared_ptr<CBase> spBaseDown = make_shared<CBase>();
    shared_ptr<CDerive> spDeriveDown = dynamic_pointer_cast<CDerive>(spBaseDown);
    if (spDeriveDown == nullptr)	//由于会进行类型的检查，这边是返回nullptr
        cout << "spDeriveDown is null" << endl;


//    shared_ptr<CDerive> spDeriveDown;
//    shared_ptr<CBase> spBaseDown;
//    shared_ptr<CBase> spBaseDown = make_shared<CDerive>();
//    shared_ptr<CDerive> spDeriveDown = dynamic_pointer_cast<CDerive>(spBaseDown);
//    if (spDeriveDown == nullptr)	//由于会进行类型的检查，这边是返回NULL
//        cout << "spDeriveDown is null" << endl;
//    spDeriveDown->myDerive();


    return 0;
}

