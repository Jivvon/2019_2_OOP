#include <iostream>

int main()
{
    char target[] = "Jeong Jiwon";
    long b[119];             // long 8 * 119 = 952
    int a = 17;              // int 4
    int i = 984;             // int 4
    int *c = new int[502];   // int형 포인터 8 (64bit)
    char *copy = "is no no"; // char형 포인터 8 (64bit)
    char name = 'a';         // char 1 -> int형 포인터로 형변환 8

    std::cout << "target : \t" << &target << std::endl;
    std::cout << "b[0] :   \t" << &b[0] << std::endl;
    std::cout << "b[119] : \t" << &b[119] << std::endl;
    std::cout << "a :       \t" << &a << std::endl;
    std::cout << "i :       \t" << &i << std::endl;
    std::cout << "c :       \t" << &c << std::endl;
    std::cout << "copy :    \t" << &copy << std::endl;
    std::cout << "name :    \t" << (int *)&name << std::endl;

    std::cout << "\ntest :    \t" << ((int *)&target - (int *)&name) * sizeof(int) << std::endl;

    std::cout << "\ntarget : \t" << sizeof(target) << std::endl;
    std::cout << "b :       \t" << sizeof(b) << std::endl;
    std::cout << "a :       \t" << sizeof(a) << std::endl;
    std::cout << "i :       \t" << sizeof(i) << std::endl;
    std::cout << "c :       \t" << sizeof(c) << std::endl;
    std::cout << "copy :    \t" << sizeof(copy) << std::endl;
    std::cout << "name :    \t" << sizeof((int *)name) << std::endl;

    std::cout << "&name + i - 4 : " << &name + i - 4 << std::endl;
    std::cout << "&name + i - 3 : " << &name + i - 3 << std::endl;
}