#include "Hello.hpp"
#include <iostream>

Hello::Hello() {
    this->m_secret_name = "秘密の名前";
}

void Hello::greet() {
    std::cout << "hello " << this->m_secret_name << std::endl;
}