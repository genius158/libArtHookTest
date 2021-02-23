#include <elf.h>
//
// Created by yan xianwei on 2020/11/9.
//

#include <jni.h>
#include <string>
#include "log.h"
#include "Test.h"
#include "log.h"



class Parent {
private:
public:
    int m_a;
    char c_c;
    int m_b;

    Parent();
};

Parent::Parent() {
    m_a = 1;
    c_c = 'a';
    m_b = 2;
}

class Son : public Parent {
public:
    int m_c;
};


#if(CallM1)
double cal_m1(int lines) {
      LOG("cal_m1 111111");
  return 0.05 * lines;
}
#else
double cal_m1(int lines) {
    LOG("cal_m1 222222");
    return 0.05 * lines;
}

#endif

double cal_m2(int lines) {
    return 0.5 * lines;
}

void estimate(int line_num, double (*pf)(int lines)) {
    double result = (*pf)(line_num);
    LOG("result estimate %f", result);

}


template<typename T>
void Swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

void Test::test() {
//    Son temp;
//    LOG("data d %d", temp.m_b);
//    LOG("data d %d", *(&temp.m_b - sizeof(temp.m_b)));
//    LOG("data p %p", &temp.m_b);
//    LOG("data p %p", (&temp.m_a));
//    LOG("data p %p", (&temp.m_b - sizeof(temp.m_b)));
//    LOG("data p %d %d %d %d %d %d", sizeof(temp.m_b), sizeof(1), sizeof(int), sizeof(long),
//        sizeof(char), sizeof(bool));
//    LOG("data p %p", (&temp.m_b - 1));
//    *(&temp.m_b - sizeof(int)) = 666;//修改私有成员
//
//    LOG("data c_c %p", &temp.c_c);
//    *(&temp.m_a - 1) = 'a';
//    LOG("data c_c %c", temp.c_c);
//
//    LOG("data p %d", temp.m_a);
//
//    int *data = static_cast<int *>(malloc(sizeof(int) * 4));
//    *(int *) (data + sizeof(int) * 0) = 1;
//    *(int *) (data + sizeof(int) * 1) = 2;
//    *(int *) (data + sizeof(int) * 2) = 3;
//    *(int *) (data + sizeof(int) * 3) = 4;
//    LOG("------------- %d\t%d\n", *(int *) data, *(int *) (data + sizeof(int) * 3));

    //////////////////////////////////////////////////////////////////////////////
    int a = 12;
    int b;
    int *p;
    int **ptr;
    p = &a; //&a 的结果是一个指针，类型是int*，指向的类型是
//int，指向的地址是a 的地址。
    *p = 24; //*p 的结果，在这里它的类型是int，它所占用的地址是
//p 所指向的地址，显然，*p 就是变量a。
    ptr = &p; //&p 的结果是个指针，该指针的类型是p 的类型加个*，
//在这里是int **。该指针所指向的类型是p 的类型，这
//里是int*。该指针所指向的地址就是指针p 自己的地址。
    *ptr = &b; //*ptr 是个指针，&b 的结果也是个指针，且这两个指针
//的类型和所指向的类型是一样的，所以用&b 来给*ptr 赋
//值就是毫无问题的了。
    **ptr = 34; //*ptr 的结果是ptr 所指向的东西，在这里是一个指针，
//对这个指针再做一次*运算，结果是一个int 类型的变量。

    estimate(23, cal_m1);

//    double cal_m2(int lines) {

    double (*fp)(int lines) = cal_m2;

    double result = (*fp)(20);

    LOG("result  %f", result);


    int swapA = 1;
    int swapB = 2;
    LOG("Swap before  %d   %d", swapA, swapB);
    Swap(&swapA, &swapB);

    LOG("Swap after  %d   %d", swapA, swapB);


    int i;
    float f = 166.71;
    // 关联性的数据转换 包括 继承
    i = static_cast<int>(f);
    LOG("static_cast  %d ", i);

    auto tf = static_cast<float>(i);
    LOG("static_cast  %f ", tf);

    int *i2;
    char *f2 = "sdf";
    // 可处理非关联性的转换
    i2 = reinterpret_cast<int *>(f2);
    LOG("reinterpret_cast  %d ", *i2);
    char *f3 = reinterpret_cast<char *>(i2);
    LOG("reinterpret_cast  %s ", f3);

}
