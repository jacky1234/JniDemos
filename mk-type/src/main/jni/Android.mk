
# LOCAL_PATH是得最先配置的，它用于在开发tree中查找源文件。此变量必须保留其值，因为系统在单一 GNU Make 执行环境（其中所有变量都是全局的）中解析所有构建控制文件.宏函数‘my-dir’, 由编译系统提供，用于返回当前路径（即包含Android.mk file文件的目录
LOCAL_PATH := $(call my-dir)

# include $(CLEAR_VARS) ： CLEAR_VARS 变量指向特殊 GNU Makefile ，可为您清除许多 LOCAL_XXX 变量，例如LOCAL_MODULE 、 LOCAL_SRC_FILES 和 LOCAL_STATIC_LIBRARIES 。 请注意，它不会清除 LOCAL_PATH
include $(CLEAR_VARS)

# LOCAL_MODULE ：存储您要构建的模块的名称,并指定想生成的 so 叫什么名字。当然生成产物的时候前面会自动拼接上 lib,后面会自动拼接上 .so 。
LOCAL_MODULE := hi_jni

# LOCAL_SRC_FILES :要编译的源文件，多个文件以空格分开即可。当导入 .a 或者 .so 文件的时候一个模块只能添加一个文件，后面将演示。
LOCAL_SRC_FILES := hi_jni.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)

# LOCAL_LDLIBS :这里是添加一个本地依赖库，比如可以添加一个 log 库，当然我没用到就注释了。
# LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)




# LOCAL_PATH := $(call my-dir)
# 	#第一组
# include $(CLEAR_VARS)
# LOCAL_MODULE := x264
# LOCAL_SRC_FILES := $(LOCAL_PATH)/x264/libx264.a
# LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/
# include $(PREBUILT_STATIC_LIBRARY)
# 	#第二组
# include $(CLEAR_VARS)
# LOCAL_MODULE := hi_jni
# LOCAL_SRC_FILES := hi_jni.cpp
# LOCAL_C_INCLUDES += $(LOCAL_PATH)
# LOCAL_STATIC_LIBRARIES := x264
# include $(BUILD_SHARED_LIBRARY
