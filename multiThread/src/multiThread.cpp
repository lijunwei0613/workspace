//
// Created by a3412 on 2022/3/31.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <thread>


using namespace std;
void myprint(const int &i, const string &pmybuf){ //const?
//void myprint(const int &i, char *pmybuf){
    cout << i << endl;  //i不是main()中的mvar的引用，实际是值传递，thread构造对象时将值复制到i中，相当于值传递，形参不会修饰实参。即使主线程detach子线程，子线程中用i值也是安全的
//此处用的不是主线程中的mvar的值而是复制过去的值。所以当使用detach()分离主子线程时，当主线程执行完，内存被系统回收，却不影响子线程的使用。
    cout << pmybuf.c_str() << endl;  //在使用detach()分离主子线程时会出现异常，原因是，地址传递形参修饰实参，在主线程执行完之后，内存被系统回收，子线程中指针指向的内存空间不存在。

}

int main()
{
    //一传递临时对象作为线程参数

    //值传递 形参不会修饰实参
    //地址传递 形参修饰实参
    //引用传递 形参修饰实参

    //若传递int这种简单类型参数，建议都是值传递，不要用引用
    //如果传递类对象，避免隐式类型转换；全部都在创建线程这一行就构建出临时对象，然后在函数参数中用引用来接。

    //线程id可以用c++标准库里的函数来获取。std::this_thread::get_id()来获取；


    //传递类对象、智能指针作为线程函数
    //std::ref函数


    int mvar =1;
    int &mvary = mvar;
    char mybuf[] = "this is a test!";  //字符数组->转成字符串，临时变量，内存地址不一致

//    thread mytoboj(myprint, mvar, mybuf); //什么时候mybuf转成string？是在mybuf都被系统回收了（主线程执行完了），系统采用mybuf去转string，程序处在异常的边缘处。
                                            //此处存在隐式转换。

thread mytoboj(myprint, mvar, string(mybuf));  //保险起见，直接将mybuf转换成string对象。 在创建线程的同时构造临时对象的方法传递参数是可行的；
    //此处是在主线程执行完之前通过string（）类构造一个临时对象。
    //只要用临时构造的A类对象作为参数传递给线程，那么就一定能够在主线程执行完毕之前把线程函数的第二个参数构建出来，从而即使主子线程分离也能安全运行。
    mytoboj.join();
//    mytoboj.detach();  //子线程和主线程分别执行 这时子线程函数的形参列表不建议使用引用，不能使用指针


//线程函数传入类的成员函数
//A myobj(10);  //生成一个类对象
//std::thread mytobj(&A::thread_work, myobj, 15)  //线程对象的构造函数中传入类成员函数，类对象和成员函数参数，这种情况用join和detach()都可，因为会调用拷贝构造函数重新复制一个对象
//std::thread mytobj(&A::thread_work, std::ref(myobj), 15)  //线程对象的构造函数中传入类成员函数，类对象和成员函数参数, 这种情况就不能用detach()，因为此处不再调用拷贝构造函数，传递到子线程函数中的对象不是重新复制过去的，一旦主线线程执行完，将会把内存回收，子线程在用该对象内存空间将会产生异常。


    cout << "I love China!" << endl;


    return 0;
}