#include <iostream>
#include <cstring>
using namespace std;

//类与结构体在C++中只有两点区别，除此这外无任何区别。
// (1) class中默认的成员访问权限是private的，而struct中则是public的。
// (2) 从class继承默认是private继承，而从struct继承默认是public继承。

void printBook( struct Books book );

// 声明一个结构体类型 Books 
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}Shu;//设置Books这个结构体的别名。即Books、Shu两个名字都是这个结构体

int main(void)
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Shu Book2;        // 定义结构体类型 Shu 的变量 Book2
    // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "Runoob"); 
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;
   // Book2 详述
   strcpy( Book2.title, "CSS 教程");
   strcpy( Book2.author, "Runoob");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;
   // 输出 Book1 信息
   printBook( Book1 );
   // 输出 Book2 信息
   printBook( Book2 );
   return 0;
}
void printBook( struct Books book )
{
   cout << "书标题 : " << book.title <<endl;
   cout << "书作者 : " << book.author <<endl;
   cout << "书类目 : " << book.subject <<endl;
   cout << "书 ID : " << book.book_id <<endl;
}
