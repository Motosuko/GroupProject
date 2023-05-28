
#pragma once//使头文件只编译一次,防止头文件重复包含
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

//商品类别
enum GoodsType
{
    Food = 1,//食品
    Cosmetic,//化妆品
    Commodity,//日用品
    Drink//饮料
};


class Goods {
private:
    int id; // 商品编号
    string name; // 商品名称
    int size; // 商品大小（占用空间）
    int row;
    int col;
    int amount;
    int customer_id; // 存储该商品的客户编号
    int warehouse_id; // 存储该商品的仓库编号
    Date in_date; // 商品入库日期
    Date out_date; // 商品出库日期
public:
    // 构造函数

    Goods(int id, string name, int size, int amount, int warehouse_id, int row, int col, int customer_id, Date in_date, Date out_date) {
        this->id = id;
        this->name = name;
        this->size = size;
        this->amount = amount;
        this->warehouse_id = warehouse_id;
        this->row = row;
        this->col = col;
        this->customer_id = customer_id;
        this->in_date = in_date;
        this->out_date = out_date;
    } 

    int getId() { // 获取商品编号
        return id;
    } 
    string getName() { // 获取商品名称
        return name;
    }
    int getSize() {  // 获取商品大小（占用空间）
        return size;
    } 

    int getRow() {  // 
        return row;
    }
    int getCol() {  // 
        return col;
    }
    int getAmount() {  // 获取商品大小（占用空间）
        return amount;
    }
    int getCustomerId() {  // 获取存储该商品的客户编号
        return customer_id;
    } 
    int getWarehouseId() {  //获取存储该商品的仓库编号
        return warehouse_id;
    }  
    Date getInDate() { // 获取商品入库日期
        return in_date;
    } 
    // 获取商品出库日期
    Date getOutDate() {
        return out_date;
    } // 获取商品出库日期
    void setAmount(int amount) {
        this->amount = amount;
    }
};

