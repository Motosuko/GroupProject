#pragma once
#include"Customer.h"
#include"Warehouse.h"
class WarehouseManager : public Customer {

private:
    vector<Warehouse> warehouse_list; // ����Ĳֿ��б�
public:
    // ���캯�������ø��๹�캯����
    WarehouseManager(int id, string name, string password) : Customer(id, name, password) {}
    // ��ȡ����Ĳֿ��б�
    vector<Warehouse> getWarehouseList() {
        return warehouse_list;
    }



};