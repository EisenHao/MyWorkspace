#include <iostream>
using namespace std;
// 第一个命名空间
namespace first_space {
    void func(void) {
        cout << "Inside first_space" << endl;
    }
    // 第二个命名空间
    namespace second_space {
        void func(void) {
            cout << "Inside second_space" << endl;
        }
    }
}
using namespace first_space::second_space;
int main (void) {
    func();// 调用第二个命名空间中的函数
    return 0;
}
