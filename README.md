##NDk
### Link
- Android NDK 官网的[使用现有库](https://developer.android.com/ndk/guides/libs.html)的文档中还是使用  ndk-build + Android.mk + Application.mk 组合的说明文档。（其实官方文档中大部分都是的，并没有使用 CMake）
- 很实用的介绍[Android 官网，向您的项目中添加c和c++代码](https://developer.android.com/studio/projects/add-native-code.html?hl=zh-cn)
- [在 Android Studio 2.2 中愉快地使用 C/C++](http://wl9739.github.io/2016/09/21/%E5%9C%A8-Android-Studio-2-2-%E4%B8%AD%E6%84%89%E5%BF%AB%E5%9C%B0%E4%BD%BF%E7%94%A8-C-C-md/)
- [《Android-开发艺术探索》-14-JNI和NDK编程](http://szysky.com/2016/08/26/%E3%80%8AAndroid-%E5%BC%80%E5%8F%91%E8%89%BA%E6%9C%AF%E6%8E%A2%E7%B4%A2%E3%80%8B-14-JNI%E5%92%8CNDK%E7%BC%96%E7%A8%8B/)

下载 NDK 和构建工具
1. The Android Native Development Kit (NDK): 让你能在 Android 上面使用 C 和 C++ 代码的工具集。
2. CMake: 外部构建工具。如果你准备只使用 ndk-build 的话，可以不使用它。
3. LLDB: Android Studio 上面调试本地代码的工具。

#### CMake方式
- [CMake编译](http://www.jianshu.com/p/6332418b12b1)
- [Android 官网对cmake的描述](https://developer.android.com/ndk/guides/cmake.html)

例子位于module：cmake-type



#### 常见的问题
**1. extern "C"的作用**

extern "C"的主要作用就是为了能够正确实现C++代码调用其他C语言代码。加上extern "C"后，会指示编译器这部分代码按C语言的进行编译，而不是C++的