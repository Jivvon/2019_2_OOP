#include "student.h"

student::student()
{
    // TODO: Fill it
    // this의 name의 default값을 nullptr으로 설정
    // this의 student_id의 default값을 -1 으로 설정
    this->student_id = -1;
    this->name = nullptr;
}

student::student(char *name)
{
    // TODO: Fill it
    // this의 name을 name값으로 설정
    // this의 student_id의 default값을 -1 으로 설정
    this->name = name;
    this->student_id = -1;
}

student::student(int student_id)
{
    // TODO: Fill it
    // this의 name의 default값을 nullptr으로 설정
    // this의 student_id를 student_id 값으로 설정
    this->name = nullptr;
    this->student_id = student_id;
}

student::student(char *name, int student_id)
{
    // TODO: Fill it
    // this의 name을 name 값으로 설정
    // this의 student_id를 student_id 값으로 설정
    this->name = name;
    this->student_id = student_id;
}

int student::get_student_id()
{
    // TODO: Fill it
    // student_id 의 값을 반환하게 구현
    return this->student_id;
}

int student::get_id()
{
    // TODO: Fill it
    // 1을 리턴하도록 구현
    return 1;
}
