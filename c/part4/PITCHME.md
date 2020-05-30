### アジェンダ
- C での文字列
- 終端文字に関する注意点
- バグが発生する例
- まとめ

---

### 1. C での文字列
C 言語で、文字列を表現する場合には、

- char*
- char[]
- const char*

などを利用する。

---

### 2. 終端文字に関する注意点
C 言語における文字列操作は、NULL 終端文字（'\0'）で終わっている文字列を前提としている。

=> 途中に NULL 終端文字が存在する場合に、ここを文字列の最後としてしまうことがある。

---

#### 例
```
#include <stdio.h>
#include <string.h>

int main() {
    const char* str = "test_\0data";
    printf("%d\n", (int)strlen(str));
    return 0;
}
```

この場合には、実行結果は、5 になる  
（NULL 終端文字までの文字列）

```
[vagrant@localhost ~]$ gcc main.c
[vagrant@localhost ~]$ ./a.out
5
```

---

### 3. バグが発生する例

```
#include <stdio.h>
#include <string.h>

int main() {
    char src[11] = "test_\0data";
    char dst[11] = "xxxxxxxxxx";
    size_t src_len = strlen(src);
    printf("%d\n", (int)src_len);
    for (int i=0; i<(int)src_len; i++) {
         dst[i] = src[i];
    }

    for (int i=0; i<11; i++) {
         printf("[%d][src][%c][dst][%c]\n", i, src[i], dst[i]);
    }
    return 0;
}
```

@[7](strlen を用いると途中で切れる)

---

#### 実行結果

これを実行すると、次のようになる  
（途中までしかコピーできていない）

```
[vagrant@localhost ~]$ g++ main_2.c
[vagrant@localhost ~]$ ./a.out
5
[0][src][t][dst][t]
[1][src][e][dst][e]
[2][src][s][dst][s]
[3][src][t][dst][t]
[4][src][_][dst][_]
[5][src][][dst][x]
[6][src][d][dst][x]
[7][src][a][dst][x]
[8][src][t][dst][x]
[9][src][a][dst][x]
[10][src][][dst][]
```

---

#### 対策
```
#include <stdio.h>
#include <string.h>

int main() {
    char src[11] = "test_\0data";
    char dst[11] = "xxxxxxxxxx";
    memcpy(dst, src, 11);
    for (int i=0; i<11; i++) {
         printf("[%d][src][%c][dst][%c]\n", i, src[i], dst[i]);
    }
    return 0;
}
```

memcpy によって、サイズを指定してコピー

#### 実行結果

この場合には、実行結果は以下の通り  
（NULL 以降もコピーできている）

```
[vagrant@localhost ~]$ ./a.out
[0][src][t][dst][t]
[1][src][e][dst][e]
[2][src][s][dst][s]
[3][src][t][dst][t]
[4][src][_][dst][_]
[5][src][][dst][]
[6][src][d][dst][d]
[7][src][a][dst][a]
[8][src][t][dst][t]
[9][src][a][dst][a]
[10][src][][dst][]
```

### まとめ
- C 言語の文字列に関しては、終端文字の有無に注意
- 途中に終端文字が存在した場合には、文字列が途中で切れる可能性がある  
  （単体試験等で、NULL 終端文字が含むケースを実施しておくのが望ましい）