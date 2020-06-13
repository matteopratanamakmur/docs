### アジェンダ
- pimpl イディオムとは
- private 変数 / 関数
- pimpl を利用して書き直す
- メリット
- まとめ

---

### 1. pimpl イディオムとは
C++ に置いて、private 変数 / 関数は、
本当の意味で private になっていない（変数名 / 関数名が外部から見える）

---

#### 例
Hello.hpp

```
#include <string>

class Hello {
  public:
    Hello();
    void greet();
  private:
    std::string m_secret_name;
};
```

---

#### 例
Hello.cpp

```
#include "Hello.hpp"
#include <iostream>

Hello::Hello() {
    this->m_secret_name = "秘密の名前";
}

void Hello::greet() {
    std::cout << "hello " << this->m_secret_name << std::endl;
}
```

---

#### 例
main.cpp

```
#include <iostream>
#include "Hello.hpp"

int main() {
    Hello hello;
    hello.greet();
    return 0;
}
```

---

#### 例
実行してみる

```
[matteo's PC] ~/Work/docs/c++/part1
% g++ main.cpp Hello.cpp
[matteo's PC] ~/Work/docs/c++/part1
% ./a.out
hello 秘密の名前
```

---

### 2. private 変数 / 関数
hpp / cpp ファイルを見てみると、
次のように hpp ファイル中に private 変数 / 関数が書かれており、
外部から見えている。

---

Hello.hpp
```
#include <string>

class Hello {
  public:
    Hello();
    void greet();
  private:
    std::string m_secret_name;
};
```

@[7-8](private 変数が見えている)

---

### 3. pimpl を利用して書き直す
hpp には「impl」だけが private として定義されている。

それ以外の private 変数 / 関数は cpp 側に定義されており、
hpp ファイルからは見えない。

---

#### 例
Hello2.hpp
```
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
```

@[1](string の include が cpp に移動)
@[7-9](private 変数は pimpl のみ)

---

#### 例
Hello2.cpp
```
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
```

@[15-16](private 変数が cpp に移動)
@[25-27](pimpl 経由で呼び出す)

---

#### 例
main2.cpp

```
#include <iostream>
#include "Hello2.hpp"

int main() {
    Hello2 hello2;
    hello2.greet();
    return 0;
}
```

---

#### 例
実行してみる

```
[matteo's PC] ~/Work/docs/c++/part1
% g++ main2.cpp Hello2.cpp
[matteo's PC] ~/Work/docs/c++/part1
% ./a.out
hello 秘密の名前
```

---

### 5. まとめ

1. pimpl を利用することで、private 変数 / 関数を完全に隠蔽できる
2. cpp ファイルに、ライブラリ依存を詰め込める