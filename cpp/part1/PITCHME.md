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

### 2. private 変数 / 関数
hpp / cpp ファイルを見てみると、
次のように hpp ファイル中に private 変数 / 関数が書かれており、
外部から見えている。

---

### 3. pimpl を利用して書き直す
hpp 中には、「impl」だけが private として定義されている。

それ以外の private 変数 / 関数は cpp 側に定義されており、
hpp ファイルからは見えなくなっている。

---

### 4. メリット

例えば次の点に、メリットがある。

1. private 変数 / 関数を外部から完全に隠蔽できる
2. cpp ファイルに、ライブラリ依存を詰め込める

---

### 5. まとめ

1. pimpl を利用することで、private 変数 / 関数を完全に隠蔽できる
2. cpp ファイルに、ライブラリ依存を詰め込める

--