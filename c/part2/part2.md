# part2. so ファイルについて

## アジェンダ
- so ファイルとは
- so ファイルを作ってみる
- so ファイルを呼び出す
- ldd コマンドでライブラリ依存を確認

## 内容
### 1. so ファイルとは
ライブラリには、
- 静的ライブラリ
- 共通ライブラリ

の二種類存在するが、so ファイルは共通ライブラリのこと

```
[vagrant@centos8 ~]$ find /usr/lib64/ -name *.so.* | tail
/usr/lib64/libuv.so.1
/usr/lib64/libuv.so.1.0.0
/usr/lib64/libisl.so.13
/usr/lib64/libisl.so.13.1.0
/usr/lib64/libisl.so.15
/usr/lib64/libisl.so.15.1.1
/usr/lib64/libgpm.so.2
/usr/lib64/libgpm.so.2.1.0
/usr/lib64/libhavege.so.1
/usr/lib64/libhavege.so.1.1.0
```

共通ライブラリ化しておくことで、色々な（複数の）ファイルから呼び出すことができるようになる

### 2. so ファイルを作ってみる
```
gcc -shared ...
```
という形で、build 時に「-shared」をつけることで作成できる

※ so ファイル名は「lib」を先頭につける必要がある

### 3. so ファイルを呼び出す
```
gcc -L<so ファイルの置き場所> ... -l<ライブラリ名> 
```
という形で、build 時に「-l / -L」で「so ファイルの名前 / 場所」を指定することで呼び出せる

- ライブラリ名は、so ファイルから「lib / 拡張子」を除いた部分
- -l オプションは、コンパイルするファイルの後ろにおく１

### 4. ldd コマンドでライブラリ依存を確認
ldd コマンドを利用することで、ライブラリの依存関係を確認することができる

## まとめ
- so ファイルとは、共通ライブラリのこと
- 作成時には ``` -shared ``` をつけて build を行う
- 「-l / -L」により、so ファイルを呼び出せる（利用できる）
