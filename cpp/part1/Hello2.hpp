#include <memory>

class Hello2 {
  public:
    Hello2();
    ~Hello2();
    void greet();
  private:
    class Impl;
    std::unique_ptr<Impl> pimpl;
};