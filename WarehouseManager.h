#pragma once
#include"Customer.h"
#include"Warehouse.h"
class WarehouseManager : public Customer {

private:
    vector<Warehouse> warehouse_list; // 管理的仓库列表
public:
    // 构造函数（调用父类构造函数）
    WarehouseManager(int id, string name, string password) : Customer(id, name, password) {}
    // 获取管理的仓库列表
    vector<Warehouse> getWarehouseList() {
        return warehouse_list;
    }



};