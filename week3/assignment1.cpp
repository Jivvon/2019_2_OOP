#include <iostream>

int code()
{
    return 0;
}

// int data = 'A'; // 초기화 된 전역변수 data
int bss; // 초기화 되지 않은 전역변수 BSS
// char *data = "oop test"; // 문자열은 rodata, 포인터 변수는 data
// const char rodata = 'C'; // 상수. 읽기 전용 read-only data

int main()
{
    int stack = 1; // 지역변수 stack

    static int data = 1;
    int *heap = new int[1]; // 동적할당 heap

    std::cout << "code\t" << (void *)code << std::endl;
    std::cout << "Rodata\t" << (void *)"rodata" << std::endl;
    std::cout << "data\t" << &data << std::endl;
    std::cout << "BSS\t" << &bss << std::endl;
    std::cout << "HEAP\t" << heap << std::endl;
    std::cout << "Stack\t" << &stack << std::endl;
}