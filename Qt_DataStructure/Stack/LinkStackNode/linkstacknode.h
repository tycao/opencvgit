#pragma once

template<typename T>
class LinkStackNode
{
public:
    LinkStackNode(); // Ĭ�Ϲ��캯��
    LinkStackNode(T); // ����һ���β�����ΪT�Ĺ��캯��

    LinkStackNode<T>*& GetLink();   // �û��ӿں��������ض��������˽�����ݳ�Ա
    T& GetData();   // �ӿں��������ض��������˽�����ݳ�Ա
private:
    LinkStackNode<T>* link; // ���ݳ�Ա��ָ�룩
    T data; //
};
template<typename T>
LinkStackNode<T>::LinkStackNode() : link(nullptr) { } // Ĭ�Ϲ��캯��

template<typename T>
LinkStackNode<T>::LinkStackNode(T value) : data(value), link(nullptr) { } // ����һ���β�����ΪT�Ĺ��캯��

template<typename T>
LinkStackNode<T>*& LinkStackNode<T>::GetLink() { return this->link; }

template<typename T>
T& LinkStackNode<T>::GetData() { return this->data; }
