# include について

## アジェンダ
- 導入
- /usr/include/ にある math.h を呼び出す
- hello_world.h を /usr/include に作って、呼び出す
- hello_world.h を /tmp に移動して、呼び出す

## 内容
### 導入
みなさまこんにちは、matteo と言います。

業務で利用する中で、昔学んだ内容に関してようやく意味がわかってきました（まだまだですが）。  
少しでもみなさまのお役に立てたら良いなと思い、動画をとることとしました。

動画をとることにまだまだ慣れていませんので、至らぬ点もあるかと思いますが、  
少しずつ改善して行けたらと思っています。

よろしくお願いいたします。

### 1. /usr/include/ にある math.h を呼び出す
linux においては、```/usr/include/``` に存在する header ファイルを、  
``` 
#include <(header ファイル名)> 
```
という形で呼び出すことができます。

### 2. hello_world.h を /usr/include に作って、呼び出す
自作の header ファイルを、```/usr/include``` におくことで、  
```
#include <(header ファイル名)>
```
という形で呼び出すことができるようになります。

### 3. hello_world.h を /tmp に移動して、呼び出す
```/usr/include``` におくと、デフォルトでは header ファイルの置き場としては認識されず、
build できないですが、```-I``` オプションにより場所を指定することで build できるようになります。
```
gcc -I<header ファイルの置き場所>
```

## まとめ
- ```/usr/include``` にある header ファイルを「#include」で利用できる
- ```/usr/include``` 以外にある header ファイルも「-I」により場所を教えれば利用できる