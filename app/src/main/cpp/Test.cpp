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
    c_c='a';
    m_b = 2;
}

class Son : public Parent {
public:
    int m_c;
};

void Test::test() {
    Son temp;
    LOG("data d %d", temp.m_b);
    LOG("data d %d", *(&temp.m_b - sizeof(temp.m_b)));
    LOG("data p %p", &temp.m_b);
    LOG("data p %p", (&temp.m_a));
    LOG("data p %p", (&temp.m_b - sizeof(temp.m_b)));
    LOG("data p %d %d %d %d %d %d", sizeof(temp.m_b), sizeof(1), sizeof(int), sizeof(long),
         sizeof(char), sizeof(bool));
    LOG("data p %p", (&temp.m_b - 1));
    *(&temp.m_b - sizeof(int)) = 666;//修改私有成员

    LOG("data c_c %p", &temp.c_c);
    *(&temp.m_a-1)='a';
    LOG("data c_c %c", temp.c_c);

    LOG("data p %d", temp.m_a);

    int *data = static_cast<int *>(malloc(sizeof(int) * 4));
    *(int *) (data + sizeof(int) * 0) = 1;
    *(int *) (data + sizeof(int) * 1) = 2;
    *(int *) (data + sizeof(int) * 2) = 3;
    *(int *) (data + sizeof(int) * 3) = 4;
    LOG("------------- %d\t%d\n", *(int *) data, *(int *) (data + sizeof(int) * 3));
}