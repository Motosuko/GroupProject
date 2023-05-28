#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Goods.h"

class Container {
private:
    //int id; // a unique identifier for the container
    int capacity; // the maximum number of goods that can be stored in the container
    vector<Goods> goods; // a vector of goods that are stored in the container
public:
    // Constructor
    Container(int capacity) {
        //this->id = id;
        this->capacity = capacity;
        this->goods.clear(); // no goods stored initially
        //goods = vector<Goods>();
    }
    Container(){}
    // Getters and setters
    //int getId() {
    //    return id;
    //}

    int getCapacity() {
        return capacity;
    }

    vector<Goods> getGoods() {
        return goods;
    }

    //void setId(int id) {
    //    this->id = id;
    //}

    void setCapacity(int capacity) {
        this->capacity = capacity;
    }

    void setGoods(vector<Goods> goods) {
        this->goods = goods;
    }
    void addGoods(Goods good) {
        goods.push_back(good);
    }
};

class Warehouse {
private:
    int id; // a unique identifier for the warehouse
    bool large; // whether the warehouse is large or small
    int rows; // the number of rows in the warehouse
    int cols; // the number of columns in the warehouse
    vector<vector<Container>> grid; // a two-dimensional vector to store the containers in the warehouse
public:
    // Constructor
    Warehouse(int id, bool large) {
        this->id = id;
        this->large = large;
        if (large) {
            rows = 5;
            cols = 2;
        }
        else {
            rows = 4;
            cols = 2;
        }
        grid = vector<vector<Container>>(rows, vector<Container>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = Container(100);
            }
        }
    }

    // Getters and setters
    int getId() {
        return id;
    }

    bool isLarge() {
        return large;
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    vector<vector<Container>> getGrid() {
        return grid;
    }

    void setId(int id) {
        this->id = id;
    }

    void setLarge(bool large) {
        this->large = large;
    }

    void setRows(int rows) {
        this->rows = rows;
    }

    void setCols(int cols) {
        this->cols = cols;
    }
    void setContainer(Container c,int row, int col) {
        this->grid[row][col] = c;
    }
    void setGrid(vector<vector<Container>> grid) {
        this->grid = grid;
    }

    // A function to calculate the total capacity of a warehouse composed of containers
    int getTotalCapacity(Warehouse warehouse) {
        int totalCapacity = 0;
        // Loop through the grid of containers
        for (int i = 0; i < warehouse.getRows(); i++) {
            for (int j = 0; j < warehouse.getCols(); j++) {
                // Add the capacity of each container to the total capacity
                totalCapacity += warehouse.getGrid()[i][j].getCapacity();
            }
        }
        return totalCapacity;
    }
};