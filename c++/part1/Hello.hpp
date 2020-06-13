#include <string>

class Hello {
  public:
    Hello();
    void greet();
  private:
    std::string m_secret_name;
};