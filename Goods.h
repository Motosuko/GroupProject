
#pragma once//ʹͷ�ļ�ֻ����һ��,��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

//��Ʒ���
enum GoodsType
{
    Food = 1,//ʳƷ
    Cosmetic,//��ױƷ
    Commodity,//����Ʒ
    Drink//����
};


class Goods {
private:
    int id; // ��Ʒ���
    string name; // ��Ʒ����
    int size; // ��Ʒ��С��ռ�ÿռ䣩
    int row;
    int col;
    int amount;
    int customer_id; // �洢����Ʒ�Ŀͻ����
    int warehouse_id; // �洢����Ʒ�Ĳֿ���
    Date in_date; // ��Ʒ�������
    Date out_date; // ��Ʒ��������
public:
    // ���캯��

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

    int getId() { // ��ȡ��Ʒ���
        return id;
    } 
    string getName() { // ��ȡ��Ʒ����
        return name;
    }
    int getSize() {  // ��ȡ��Ʒ��С��ռ�ÿռ䣩
        return size;
    } 

    int getRow() {  // 
        return row;
    }
    int getCol() {  // 
        return col;
    }
    int getAmount() {  // ��ȡ��Ʒ��С��ռ�ÿռ䣩
        return amount;
    }
    int getCustomerId() {  // ��ȡ�洢����Ʒ�Ŀͻ����
        return customer_id;
    } 
    int getWarehouseId() {  //��ȡ�洢����Ʒ�Ĳֿ���
        return warehouse_id;
    }  
    Date getInDate() { // ��ȡ��Ʒ�������
        return in_date;
    } 
    // ��ȡ��Ʒ��������
    Date getOutDate() {
        return out_date;
    } // ��ȡ��Ʒ��������
    void setAmount(int amount) {
        this->amount = amount;
    }
};

