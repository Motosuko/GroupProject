#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Goods.h"
class Customer {
private:
    int id; // �ͻ����
    string name; // �ͻ�����
    string password; // �ͻ����루���ڵ�¼��
    vector<Goods> goods_list; // �ͻ��洢����Ʒ�б�
public:
    // ���캯��
    Customer(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    } 
    Customer(){}

    int getId(){  // ��ȡ�ͻ����
    return id;
}
    string getName(){ // ��ȡ�ͻ�����
        return name;
    }
    string getPassword() { // ��ȡ�ͻ����루���ڵ�¼��
        return password;
    } 
    vector<Goods> getGoodsList() { // ��ȡ�ͻ��洢����Ʒ�б�
        return goods_list;
    }
};
