STL�е�set
=========
�ڱ�׼ģ���STL��set������ʵ�ּ��ϵĹ��ܡ�set����vector���кܶ������֮������set�в��ܴ洢�ظ���Ԫ�أ�����set��vector֮�������
���⣬set�е�Ԫ�����������еģ���һ����map��ͬ��
---------
* set������ :
	* set_intersection��ȡ���Ͻ�������
	* set_union��ȡ���ϲ�������
	* set_difference��ȡ���ϲ����
	* set_symmetric_difference��ȡ���϶ԳƲ��
	* �Ⱥ���
#### set_intersection��ȡ���Ͻ����� ���÷���
```cpp
	ostream_iterator<int> out(cout , " ");
	// �󼯺�MySet1��MySet2�Ľ���
	cout << "\nMySet1��MySet2�Ľ�����";
	set_intersection( MySet1.begin(), MySet1.end(),
					  MySet2.begin(), MySet2.end(),
					  out );
```

#### set_union��ȡ���ϲ�����  ���÷���
```cpp

	// �󼯺�MySet1��MySet2�Ĳ���
	cout << "\nMySet1��MySet2�Ĳ�����";
	set_union(MySet1.begin(), MySet1.end(),
			  MySet2.begin(), MySet2.end(),
			  out);
```

#### set_difference��ȡ���ϲ��  ���÷���
```cpp
	ostream_iterator<int> out(cout , " ");
	// �󼯺�MySet1��MySet2�Ĳ
	cout << "\nMySet1��MySet2�Ĳ��";
	set_difference(MySet1.begin(), MySet1.end(),
				   MySet2.begin(), MySet2.end(),
				   out);

	cout << "\nMySet2��MySet1�Ĳ��";
	set_difference(MySet2.begin(), MySet2.end(),
				   MySet1.begin(), MySet1.end(),
				   out);
```

#### set_symmetric_difference��ȡ���϶ԳƲ��  ���÷���
```cpp
	ostream_iterator<int> out(cout , " ");
	// �󼯺�MySet1��MySet2�ĶԳƲ�
	set_symmetric_difference(MySet1.begin(), MySet1.end(),
				 MySet2.begin(), MySet2.end(),
				 inserter(MySet3, MySet3.begin())	// inserter : ������ͷ�ļ� <iterator> ��
					 ); 
	// ����MySet3
	std::for_each(MySet3.begin(), MySet3.end(), [&](int i){ cout << i << " "; });
```
#### �������л����ͼ��
![stdSet](https://github.com/tycao/opencvgit/blob/master/Qt_DataStructure/Set/stdSet/src/stdSet.png "stdSet")


