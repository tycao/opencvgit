使用boost::asio实现简易线程池
===========
*boost::asio 作为异步输入输出库，所有的对象都提供了异步调用的函数。* 

### 首先，遇到一个大坑：Qt creator 编译错误 ：cannot find file .pro qt
#### 其实问题的解决办法很简单：就是Qt不支持中文的路径，把源码的路径全部改成英文即可解决问题。首先问题发生在我运行网上的例子程序时，重新构建编译也是出错，提示：
	Cannot find file: F:\Pro\Qt\QT5开发及实例\本书源程序\CH1\CH101\Dialog\Dialog.pro.
	21:55:03: 进程"D:\Qt\Qt5.5.0\5.5\msvc2013_64\bin\qmake.exe"退出，退出代码 2 。
	Error while building/deploying project Dialog (kit: Desktop Qt 5.5.0 MSVC2013 64bit)
	When executing step "qmake"

## QT Creator对大于带有两个空格的目录和中文命名的目录不支持！！
## 究其原因 应该是qmake对带有空格的目录和中文命名的目录不支持！！

### 为了查找这个原因，我重新编译了boost源码。问题还是出现。然后我就百度寻找问题答案，[在这里找到了答案](http://blog.csdn.net/hyqsong/article/details/47072467)<br />

# 接下来，继续讲解利用boost::asio来进行网络编程
