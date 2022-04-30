//
// Created by a3412 on 2022/4/4.
//

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>

using namespace std;

class MyCAS  //创建一个单例类  不能通过类名来床架对象；
{
private:    //构造函数私有化
    MyCAS() {

    }

private:
    static MyCAS *m_instance;   //静态成员变量；只想MyCAS这个类对象的指针；

public:
    static MyCAS *GetInstance() {  //定义一个静态成员函数
        if (m_instance == nullptr) {
            m_instance = new MyCAS();  //创建一个对象
            static CGarhuishou cl;  //生命周期一直到程序结束，当程序退出，这个静态变量一定调用对象的析构函数；重点是静态变量的声明周期；
        }
        return m_instance;
    }

    class CGarhuishou //类中套类-技巧用法，用来释放对象；用来回收
    {
    public:
        ~CGarhuishou() {  //类的析构函数中
            if (MyCAS::m_instance) {  //如果new过成立则执行delete;
                delete MyCAS::m_instance;
                MyCAS::m_instance = nullptr;
            }

        }
    };


    void func() {
        cout << "测试" << endl;
    }

};

//静态变量初始化
MyCAS *MyCAS::m_instance = nullptr;


//线程入口函数
void mythread() {
    cout << "我的线程开始执行了" << endl;
    MyCAS *p_a = MyCAS::GetInstance();  //两条通路或者两个线程同时执行这个一函数；存在问题：在调用GetInstance()，存在两个线程同时开始开始执行线程函数，如其中一个线程执行将要GetInstance()，上下文切换到线程2执行
    cout << "我的线程执行结束了" << endl;

}


int main() {
    //一：设计模式: 代码写法，程序灵活，维护方便，接管阅读麻烦；
    //构造函数私有化
    //单例:项目中，有某个或者某写特殊的类，属于该类的对象，只能创建一个；
    //单例设计模式共享数据问题分析、解决；
    //main中，在主线程中，创建其他子线程之前，就把单例类调用GetInstance（）把该初始化的数据进行初始化；
    //需要自己创建线程（不是主线程）中来创建MyCAS这个单例类的对象，最少两个；
    //可能面临GetInstanche()要互斥；

//    MyCAS *p_a = MyCAS::GetInstance();   //创建一个对象，返回该类（MyCAS）对象的指针；
//    p_a->func();//调用类内的普通成员函数；接口函数把配置文件中的数据进行装载，类中的数据就变成只读的数据，后面操作就可以对数据进行处理；
//    MyCAS::GetInstance()->func();  //也可以通过这种方式来调用类内的普通成员函数；装载数据，

    std::thread myobj1(mythread);
    std::thread myobj2(mythread);
    myobj1.join();
    myobj2.join();


    return 0;
}
