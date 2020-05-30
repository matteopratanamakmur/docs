# part4. 文字列型（char* / char[]）の注意点

## アジェンダ
- C での文字列
- 終端文字に関する注意点
- まとめ

---

## 内容
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

### 例

```
const char* str = "test_\0data"
printf("%d", (int)strlen(str));
```

---

## まとめ
- C 言語の文字列に関しては、終端文字の有無に注意
- 途中に終端文字が存在した場合には、（文字列操作の際などに）バグが発生する可能性がある
  （単体試験等で、NULL 終端文字が含むケースを実施しておくのが望ましい）