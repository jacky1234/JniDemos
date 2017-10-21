##NDk
### Link
- Android NDK 官网的[使用现有库](https://developer.android.com/ndk/guides/libs.html)的文档中还是使用  ndk-build + Android.mk + Application.mk 组合的说明文档。（其实官方文档中大部分都是的，并没有使用 CMake）
- 很实用的介绍[Android 官网，向您的项目中添加c和c++代码](https://developer.android.com/studio/projects/add-native-code.html?hl=zh-cn)
- [在 Android Studio 2.2 中愉快地使用 C/C++](http://wl9739.github.io/2016/09/21/%E5%9C%A8-Android-Studio-2-2-%E4%B8%AD%E6%84%89%E5%BF%AB%E5%9C%B0%E4%BD%BF%E7%94%A8-C-C-md/)
- [<Android-开发艺术探索>-14-JNI和NDK编程](http://szysky.com/2016/08/26/%E3%80%8AAndroid-%E5%BC%80%E5%8F%91%E8%89%BA%E6%9C%AF%E6%8E%A2%E7%B4%A2%E3%80%8B-14-JNI%E5%92%8CNDK%E7%BC%96%E7%A8%8B/)
- [Android下玩JNI的新老三种姿势](http://blog.csdn.net/mabeijianxi/article/details/68525164)

下载 NDK 和构建工具
1. The Android Native Development Kit (NDK): 让你能在 Android 上面使用 C 和 C++ 代码的工具集。
2. CMake: 外部构建工具。如果你准备只使用 ndk-build 的话，可以不使用它。
3. LLDB: Android Studio 上面调试本地代码的工具。

### 三种方式
#### a. 手动MK方式
例子位于module：mk-type:

这种编译其实是用make工具来玩的，在 linux 徒手写并编译过c的应该很清楚，通过编写makefile，然后再用make编译已经比不停的用gcc命令逐个编译要爽很多,但是 makefile 的编写还是有点蛋疼。程序员都是化繁为简善解人意的，通过 ndk 工具我们无需自己写 makefile 了，现在你只要安心撸自己关心的代码就行了。

编译中出现了错误： 
NDK_PROJECT_PATH=null ，查询资料说 NDK一定要r9+版本的。实际我用r10e版本也是可行的，可能高版本是无法通过的。
但是尴尬的是 CMake 提示需要 Please use NDK r12+.

#### b. 配置gradle来编译
这种方式比上一中又简化了很多，无需再自己编写 Android.mk 了，但原理都是一样的

#### c. CMake方式 (推荐方式)
- [CMake编译](http://www.jianshu.com/p/6332418b12b1)
- [Android 官网对cmake的描述](https://developer.android.com/ndk/guides/cmake.html)

例子位于module：cmake-type:
- 调用jni，通过反射调用java代码。

#### 常见的问题
**1. 遇到的坑**
测试手机为华为mate8，cpu abi类型为 arm64-v8a,armeabi-v7a
a种方式，为何在 Appliaciton.mk 非要 APP_ABI 加上arm64-v8a，才能跑起应用(否则报 unsatisfied link
 error)，但是其他方式都不需要，好奇怪。

**2. extern "C"的作用**

为何要使用extern"C",
原因很简单，在 C++ 中函数在编译的时候会拼接上参数，这也是 c++ 中函数重载的处理机制，比如一个 set(int a) 和一个 set(int a,int b) ，在编译的时候就变成了 set_int 与 set_int_int ，我们加上extern ”C“ 就表示大爷想按照C来编译，所以函数名字后面就不会拼接上参数类型了。