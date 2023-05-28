#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Goods.h"
class Customer {
private:
    int id; // 客户编号
    string name; // 客户名称
    string password; // 客户密码（用于登录）
    vector<Goods> goods_list; // 客户存储的商品列表
public:
    // 构造函数
    Customer(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    } 
    Customer(){}

    int getId(){  // 获取客户编号
    return id;
}
    string getName(){ // 获取客户名称
        return name;
    }
    string getPassword() { // 获取客户密码（用于登录）
        return password;
    } 
    vector<Goods> getGoodsList() { // 获取客户存储的商品列表
        return goods_list;
    }
};
