#include <memory>
#include "../include/iterator.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace ft
{
  template <typename T>
  class vector {
    T* data;
    int capacity;
    int length;

  public:
    /* 1. empty container constructor (default constructor) */
    vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}
    /* 2. fill constructor */
    vector(int n, int m) : data(new T[n]), capacity(n), length(n)
    {
      for (int i = 0; i < n; i++)
        data[i] = m;
    }
    /* 3. range constructor */
    const_iterator begin() const
		{
			return (const_iterator(&_container[0]));
		}

		iterator begin()
		{
			return (iterator(&_container[0]));
		}

		const_iterator end() const
		{
			return (const_iterator(&_container[_size]));
		}

		iterator end()
		{
			return (iterator(&_container[_size]));
		}
    
    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
      if (capacity <= length) {
        T* temp = new T[capacity * 2];
        for (int i = 0; i < length; i++) {
          temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
      }
      data[length] = s;
      length++;
    }

    // 임의의 위치의 원소에 접근한다.
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
      for (int i = x + 1; i < length; i++)
        data[i - 1] = data[i];
      length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~vector() {
      if (data) {
        delete[] data;
      }
    }
  };
}

int main() {
  /* 2. fill constructor */
  std::vector<int> basic_vec(4, 100);
  std::cout << basic_vec.size() << std::endl;
  // std::cout << basic_vec.capacity() << std::endl;
  std::cout << "첫번째 원소 : " << basic_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << basic_vec[1] << std::endl;
  std::cout << "세번째 원소 : " << basic_vec[1] << std::endl;
  std::cout << "네번째 원소 : " << basic_vec[1] << std::endl;

  ft::vector<int> basic_ft_vec(4, 100);
  std::cout << basic_ft_vec.size() << std::endl;
  std::cout << "첫번째 원소 : " << basic_ft_vec[0] << std::endl;
  std::cout << "두번째 원소 : " << basic_ft_vec[1] << std::endl;
  std::cout << "세번째 원소 : " << basic_ft_vec[2] << std::endl;
  std::cout << "네번째 원소 : " << basic_ft_vec[3] << std::endl;
  

  // // int 를 보관하는 벡터를 만든다.
  // ft::vector<int> int_vec;
  // int_vec.push_back(3);
  // int_vec.push_back(2);

  // std::cout << "-------- int vector ----------" << std::endl;
  // std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
  // std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

  // ft::vector<std::string> str_vec;
  // str_vec.push_back("hello");
  // str_vec.push_back("world");
  // std::cout << "-------- std::string vector -------" << std::endl;
  // std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
  // std::cout << "두번째 원소 : " << str_vec[1] << std::endl;
}

// /* 1. empty container constructor (default constructor) */
//   std::vector<int> basic_vec;
//   std::cout << basic_vec.size() << std::endl;

//   ft::vector<int> basic_ft_vec;
//   std::cout << basic_ft_vec.size() << std::endl;