#include "Hello2.hpp"
#include <iostream>
#include <string>

class Hello2::Impl
{
  public:
    Impl() : m_secret_name("秘密の名前") {}
    ~Impl() {}

    void greet() {
      std::cout << "hello " << this->m_secret_name << std::endl;
    }

  private:
    std::string m_secret_name;
};

Hello2::Hello2() : pimpl(new Hello2::Impl()) {
}

Hello2::~Hello2() {
}

void Hello2::greet() {
  this->pimpl->greet();
}