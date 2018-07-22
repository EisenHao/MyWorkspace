/*
signal() 函数
C++ 信号处理库提供了 signal 函数，用来捕获突发事件。以下是 signal() 函数的语法：
void (*signal (int sig, void (*func)(int)))(int); 
这个函数接收两个参数：第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。
让我们编写一个简单的 C++ 程序，使用 signal() 函数捕获 SIGINT 信号。不管您想在程序中捕获什么信号，您都必须使用 signal 函数来注册信号，并将其与信号处理程序相关联。看看下面的实例：
*/
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;
void signalHandler( int signum ) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
    exit(signum);
}
int main (void) {
    cout << endl << "按 Ctrl+C 来中断程序，您会看到程序捕获信号，程序打印如下内容并退出：" << endl;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);
    while(1) {
        cout << "Going to sleep...." << endl;
        sleep(1);
    }
    return 0;
}
/*
按 Ctrl+C 来中断程序，您会看到程序捕获信号，程序打印如下内容并退出：
*/
