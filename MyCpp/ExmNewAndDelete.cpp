#include <iostream>
using namespace std;
int main (void) {
    double* pvalue = NULL; // 初始化为 null 的指针
    if ( !(pvalue = new double) ) { // 为变量请求内存，带检测，若无内存报错
        cout << "Error : out of memory !!!"<<endl;
        exit(1);
    }
    *pvalue = 29494.99; // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue; // 释放内存
    return 0;
}
