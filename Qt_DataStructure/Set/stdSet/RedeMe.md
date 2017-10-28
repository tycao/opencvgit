STL中的set
=========
在标准模版库STL中set类用以实现集合的功能。set类与vector类有很多的相似之处。但set中不能存储重复的元素，这是set与vector之间的区别。
此外，set中的元素是有序排列的，这一点与map相同。
---------
* set里面有 :
	* set_intersection（取集合交集）、
	* set_union（取集合并集）、
	* set_difference（取集合差集）、
	* set_symmetric_difference（取集合对称差集）
	* 等函数
#### set_intersection（取集合交集） 的用法：
```cpp
	ostream_iterator<int> out(cout , " ");
	// 求集合MySet1与MySet2的交集
	cout << "\nMySet1与MySet2的交集：";
	set_intersection( MySet1.begin(), MySet1.end(),
					  MySet2.begin(), MySet2.end(),
					  out );
```

#### set_union（取集合并集）  的用法：
```cpp

	// 求集合MySet1和MySet2的并集
	cout << "\nMySet1和MySet2的并集：";
	set_union(MySet1.begin(), MySet1.end(),
			  MySet2.begin(), MySet2.end(),
			  out);
```

#### set_difference（取集合差集）  的用法：
```cpp
	ostream_iterator<int> out(cout , " ");
	// 求集合MySet1和MySet2的差集
	cout << "\nMySet1和MySet2的差集：";
	set_difference(MySet1.begin(), MySet1.end(),
				   MySet2.begin(), MySet2.end(),
				   out);

	cout << "\nMySet2和MySet1的差集：";
	set_difference(MySet2.begin(), MySet2.end(),
				   MySet1.begin(), MySet1.end(),
				   out);
```

#### set_symmetric_difference（取集合对称差集）  的用法：
```cpp
	ostream_iterator<int> out(cout , " ");
	// 求集合MySet1和MySet2的对称差
	set_symmetric_difference(MySet1.begin(), MySet1.end(),
				 MySet2.begin(), MySet2.end(),
				 inserter(MySet3, MySet3.begin())	// inserter : 定义在头文件 <iterator> 内
					 ); 
	// 遍历MySet3
	std::for_each(MySet3.begin(), MySet3.end(), [&](int i){ cout << i << " "; });
```
#### 程序运行画面截图：
![stdSet](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Set/stdSet/src/stdSet.png "stdSet")


