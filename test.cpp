#include <iostream>
using namespace std;
class Student
{
private:
char * name;
int age;
public:
Student(char * name, int age) : age(age)
{
this->name = new char[10];
strcpy(this->name, name);
}
void ShowInfo() {
cout << "이름: " << name << endl;
cout << "나이: " << age << endl;
}
Student& operator=(Student& ref)
{
delete []name;
name = new char[10];
strcpy(name, ref.name);
age = ref.age;
return *this;
}
~Student()
{
delete []name;
cout << "~Student 소멸자 호출!" << endl;
}
};
int main()
{
Student st1("김철수", 14);
Student st2("홍길동", 15);
st2 = st1;
st1.ShowInfo();
st2.ShowInfo();
return 0;
}

// 출처: https://blog.hexabrain.net/177 [끝나지 않는 프로그래밍 일기]