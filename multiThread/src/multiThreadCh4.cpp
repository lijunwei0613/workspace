//
// Created by a3412 on 2022/4/2.
//

#include <map>
#include <string>
#include <thread>
#include <list>
#include <mutex>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

void myprint(int inum) {
    cout << "线程开始，线程编号" << endl;

    cout << "线程结束，线程编号" << endl;
}

class A {
public:
    //把收到的消息入到一个队列的线程
    void inMsgRecvQueue() {
        for (int i = 0; i < 10000; ++i) {
            cout << "inMSg成员函数调用，插入一个元素" << i << endl;
            my_mutex.lock();  //程序执行至此线程锁1  线程锁执行取决于系统的随机分配，假设先执行线程锁1，线程锁2卡住，先执行线程锁1中的写操作，待线程锁1中的操作执行完之后，再执行线程锁2中的读操作，反之线程锁2中执行读操作时，线程1中的读卡住，待2中执行完再执行1.
            msgRecvQueue.push_back(i);  //将i插入到消息队列中；
            my_mutex.unlock();
        }
    }

//方便操作共享数据，整理成单独函数，方便加锁和解锁。
    bool outMslLULProc(int &command) {

        my_mutex.lock();//程序执行至此线程锁2
        if (!msgRecvQueue.empty()) {
            //消息不为空
            command = msgRecvQueue.front();  //返回第一个元素，但不检查元素是否存在
            msgRecvQueue.pop_front();//移除第一个元素但是不返回；
            my_mutex.unlock();
            return true;
        }

        my_mutex.unlock();
        return false;
    }

    //一个线程将数据从容器（消息队列）中取出；
    void outRecvQueue() {

        int command = 0;
        for (int i = 0; i < 10000; ++i) {
            bool result = outMslLULProc(command);
            if (result == true) {
                cout << "outRecvQueue()执行, 取出一个元素" << command << endl;
                //数据操作部分
            } else {
                cout << "outRecvQueue()执行，目前容器中消息队列为空" << i << endl;
            }
        }
    }


private:
    std::list<int> msgRecvQueue;  //容器   共享数据，锁住
    std::mutex my_mutex;  //创建了一个互斥量的成员变量；
};


int main() {
    //多线程执行顺序是乱的，跟操作系统内部对线程的运行调度机制有关；
    //主线程等待所有子线程运行结束，最后主线程结束，比较稳定；
    //将thread对象放入到容器里管理，看上去像个thread对象数组，创建大量线程并对大量线程进行管理；

    //二：数据共享问题分析
    //（2.1）只读数据

    //三：共享数据的保护 vector 和list 区别，list可以频繁的按顺序插入和删除数据时效率高，vector容器随机的插入和删除数据效率高。
    //对于这种两个线程的程序，在线程1中执行了写的操作，线程2中执行了读的操作，但系统会不懂事切换上下文，线程1和2不定时执行，这就可能存在线程1还在写的过程中线程2就开始读了，造成程序执行异常。

    //互斥量用法
    //c++解决多线程保护共享数据引入“互斥量”  互斥量是个类对象，可理解为锁，多个线程用lock()成员函数来加锁。


    //互斥量用法 lock(), unlock();
    //操作步骤：先lock(), 操作共享数据， unlock();  成对使用；

    //std::lock_guard<std::mutex> sbguard(my_mutex, std::adopt_lock);   //adopt_lock标记作用；
    //std::adopt_lock：表示这个互斥量已经被lock了（必须要把互斥量提前lock，否则会报异常）
    //std::adopt_lock标记的效果是“假设调用方 线程已经拥有了互斥的所有权（已经loak()成功了）”；
    //通知lock_guard不需要在构造函数中lock这个互斥量了；
    //std::try_to_lock尝试用mutex的lock()去锁定mutex，如果没有锁定成功，会立即返回，不会阻塞在那；前提是不能自己先去lock。
    //std::defer_lock 前提是不能先自行lock（），然后作用是没有给mutex加锁：初始化了一个没有加锁的mutex;
    //unique_lock成员函数：lock()加锁和unlock()解锁。
    //unique_lock成员函数 try_lock(),尝试给互斥量加锁，如果拿不到锁返回false, 如果拿到锁，返回true,这个函数不阻塞；
    //unique_lock成员函数 release(), 返回它锁管理的mutex对象指针，释放所有权，即unique_lock和mutex不在关联；与mutex解除关联之后，要自己负责mutex的unlock;
    //锁住代码段越少执行效率越高；锁住的代码多少成为所得粒度，一般用粗细来描述；

    A myobja;
    std::thread myOutMsgObj(&A::outRecvQueue, &myobja);   //第二个参数是 引用，才能保证线程中是用的同一个对象；
    std::thread myInMsgObj(&A::inMsgRecvQueue, &myobja);

    myOutMsgObj.join();
    myInMsgObj.join();

    //一创建和等待多个线程
    vector<thread> mythreads;
//创建多个线程，线程入口函数统一使用myprint
    for (int i = 0; i < 10; i++) {
        mythreads.push_back(thread(myprint, i)); //创建10个线程，同时这10个线程已经开始执行
    }
    for (auto iter = mythreads.begin(); iter != mythreads.end(); ++iter) {
        iter->join();//等待10个线程都返回；
    }
    cout << "主线程执行" << endl;


    return 0;
}