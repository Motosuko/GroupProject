#include <iostream>
#include <iomanip>
#include<string>
#include <vector>
#include"Customer.h"
#include"Warehouse.h"
#include"Goods.h"
#include"WarehouseManager.h"

class MainProcess {

private:
	//static MainProcess* instance; // 系统实例指针（静态成员变量）
	vector<Warehouse> warehouse_list; // 系统中的所有仓库列表（包括大仓库和小仓库）
	vector<Customer> customer_list; // 系统中的所有客户列表（包括普通客户和仓库管理员）
    vector<Customer> manager_list;
	Customer currentuser; // 当前登录的用户指针
public:
    // initialize some customers for testing purpose
    MainProcess() {
        manager_list.push_back(WarehouseManager(1, "Alice", "1234567890"));
        customer_list.push_back(Customer(2, "Bob", "88888888"));
        warehouse_list.push_back(Warehouse(1, true));
        Date intime = Date(2020, 1, 1);
        Date outtime = Date(2023, 1, 1);
        Goods newGood = Goods(3, "apple", 2, 5, 1, 0, 1, 2, intime, outtime);
        warehouse_list[0].getGrid()[0][1].addGoods(newGood);
        /*cout << warehouse_list[0].getGrid()[0][1].getGoods().empty() << endl;
        vector<Goods> g = warehouse_list[0].getGrid()[0][1].getGoods();
        cout << g[0].getAmount() << endl;*/
        //cout << warehouse_list[0].getGrid()[0][1].getGoods()[0].getAmount()<< endl;
        //warehouse_list[1].setContainer();
    }

	// function to output the main operation menu
    void outputMainOperationMenu() {
        cout << "----------------Welcome to the warehouse management system-------------" << endl;
        cout << "|               1: warehousemanager                                   |" << endl;
        cout << "|               2: customer                                           |" << endl;
        cout << "|               3: quit the program                                   |" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "Please input a number to set your role: ";
        int role;
        cin >> role;
        switch (role) {
        case 1:
            managerMenu();
            break;
        case 2:
            customerMenu();
            break;
        case 3:
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    // function to output the manager operation menu for the manager to choose from
    void managerMenu() {
        cout << "please input your manager Id: ";
        while (true) {
            string input;
            cin >> input;
            if (input == "quit") {
                outputMainOperationMenu(); // return to main menu
                break;
            }

            else {
                string password; // 密码
                cout << "please input your password: ";
                cin >> password;
                int id = stoi(input); // convert the input to an integer
                bool found = false; // flag to indicate if the customer id is found
                for (Customer manager : manager_list) {
                    if (manager.getId() == id && manager.getPassword() == password) {
                        found = true; // set the flag to true
                        break;
                    }
                }
                if (found) { // if the customer id is found
                    outputManagerOperationMenu();
                    break;
                }
                else { // if the customer id is not found
                    cout << "Incorrect id or password. Please input a new customer Id or input \"quit\" to move to parent menu: ";
                }
            }
        }
    }

    // function to output the manager operation menu
    void outputManagerOperationMenu() {
        cout << "-----------------------------------------------------------------------" << endl;
        cout << " | 1: query warehouse                                                 |" << endl;
        cout << " | 2: query products                                                  |" << endl;
        cout << " | 3: add customers                                                   |" << endl;
        cout << " | 4: query customers                                                 |" << endl;
        cout << " | 5: move to parent menu                                             |" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << " Please input a number to run the program: ";
        int program;
        cin >> program;
        switch (program) {
        case 5:
            outputMainOperationMenu();
            break;
        case 1:
            int warehouseId;
            cout << "Please input warehouseId you want to query: ";
            cin >> warehouseId;
            printLayout(warehouseId);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    // function to output the customer operation menu for customers to choose from
    void customerMenu() {
        cout << "please input your customer Id: ";
        while (true) {
            string input;
            cin >> input;
            if (input == "quit") {
                outputMainOperationMenu(); // return to main menu
                break;
            }

            else {
                string password; // 密码
                cout << "please input your password: ";
                cin >> password;
                int id = stoi(input); // convert the input to an integer
                bool found = false; // flag to indicate if the customer id is found
                for (Customer customer : customer_list) {
                    if (customer.getId() == id && customer.getPassword() == password) {
                        found = true; // set the flag to true
                        currentuser = customer;
                        break;
                    }
                }
                if (found) { // if the customer id is found
                    outputCustomerOperationMenu();
                    break;
                }
                else { // if the customer id is not found
                    cout << "Incorrect id or password. Please input a new customer Id or input \"quit\" to move to parent menu: ";
                }
            }
        }
    }
    // function to output the customer operation menu
    void outputCustomerOperationMenu() {
        cout << "-----------------------------------------------------------------------" << endl;
        cout << " | 1: add goods                                                       |" << endl;
        cout << " | 2: remove goods                                                  |" << endl;
        cout << " | 3: add goods                                                  |" << endl;
        cout << " | 4: query customers                                                 |" << endl;
        cout << " | 5: move to parent menu                                             |" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << " Please input a number to run the program: ";
        int program;
        cin >> program;
        switch (program) {
        case 5:
            outputMainOperationMenu();
            break;
        case 1:
            int warehouseId, row, col;
            cout << "Please input warehouseId, row, col where you want to store your goods: ";
            cin >> warehouseId >> row >> col;
            addGoods(warehouseId, row, col);
            outputCustomerOperationMenu();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    // A function to add goods to the specified container in the specified warehouse if there is space available
    void addGoods(int warehouseId, int row, int col) {
        int index = 0;
        for (int i = 0; i < warehouse_list.size(); i++) { // Loop through the vector of warehouses
            if (warehouse_list[i].getId() == warehouseId) {
                index = i;
            }
        }
        // Check if the row and col are valid indices
        if (row >= 0 && row < warehouse_list[index].getRows() && col >= 0 && col < warehouse_list[index].getCols()) {
            // Get the current container at the grid position
            Container currentContainer = warehouse_list[index].getGrid()[row][col];
            // Prompt the customer to input the goods information
            cout << "Please enter the goods id, name, size and quantity:" << endl;
            int id, size, quantity;
            string name;
            cin >> id >> name >> size >> quantity;
            int y1, m1, d1, y2, m2, d2;
            cout << "Please enter the goods in year, month, date: " << endl;
            cin >> y1 >> m1 >> d1;
            Date intime = Date(y1, m1, d1);
            cout << "Please enter the goods out year, month, date: " << endl;
            cin >> y2 >> m2 >> d2;
            Date outtime = Date(y2, m2, d2);
            // Check if the current container has enough space for the new goods
            if (currentContainer.getGoods().size() + quantity <= currentContainer.getCapacity()) {
                // Create a new good object with the input information
                Goods newGood = Goods(id, name, size, quantity, warehouseId, row, col, currentuser.getId(), intime, outtime);
                // Add the new good to the current container
                warehouse_list[index].getGrid()[row][col].addGoods(newGood);
                // Update the grid with the updated container
                //warehouse_list[index].setContainer(currentContainer, row, col);
                // Output successful information
                cout << "Successfully added " << quantity << " units of " << name << " to container at row " << row << " and column " << col << endl;
            }
            else {
                // Output a reminder that there is not enough space
                cout << "The container at row " << row << " and column " << col << " does not have enough space for the new goods" << endl;
            }
        }
        else {
            // Output a reminder that the row and col are invalid
            cout << "The row and column are invalid" << endl;
        }
    }

    // A function to remove goods from the specified container in the specified warehouse
    void removeGoods(int warehouseId, int row, int col) {
        int index = 0;

        for (int i = 0; i < warehouse_list.size(); i++) { // Loop through the vector of warehouses
            if (warehouse_list[i].getId() == warehouseId) {
                index = i;
            }
        }
        // Check if the row and col are valid indices
        if (row >= 0 && row < warehouse_list[index].getRows() && col >= 0 && col < warehouse_list[index].getCols()) {
            // Get the current container at the grid position
            Container currentContainer = warehouse_list[index].getGrid()[row][col];
            // Prompt the customer to input the goods id and quantity to remove
            cout << "Please enter the goods id and quantity to remove:" << endl;
            int id, quantity;
            cin >> id >> quantity;
            // Check if the current container has the goods with the given id
            bool found = false;
            for (int k = 0; k < currentContainer.getGoods().size(); k++) {
                // Get the current good at the vector position
                Goods currentGood = currentContainer.getGoods()[k];
                // If the id matches, remove the quantity from the good
                if (currentGood.getId() == id) {
                    found = true;
                    // Check if the quantity to remove is valid
                    if (quantity > 0 && quantity <= currentGood.getAmount()) {
                        // Subtract the quantity from the good
                        currentGood.setAmount(currentGood.getAmount() - quantity);
                        // Update the vector with the updated good
                        currentContainer.getGoods()[k] = currentGood;
                        // Update the grid with the updated container
                        warehouse_list[index].getGrid()[row][col] = currentContainer;
                        // Output successful information
                        cout << "Successfully removed " << quantity << " units of " << currentGood.getName() << " from container at row " << row << " and column " << col << endl;
                    }
                    else {
                        // Output a reminder that the quantity to remove is invalid
                        cout << "The quantity to remove is invalid" << endl;
                    }
                    break;
                }
            }
            if (!found) {
                // Output a reminder that there is no goods with the given id
                cout << "There is no goods with id " << id << " in the container at row " << row << " and column " << col << endl;
            }
        }
        else {
            // Output a reminder that the row and col are invalid
            cout << "The row and column are invalid" << endl;
        }
    }

    // A function to print the layout of the warehouse
    void printLayout(int warehouseId) {
        int index = -1;
        for (int i = 0; i < warehouse_list.size(); i++) { // Loop through the vector of warehouses
            if (warehouse_list[i].getId() == warehouseId) {
                index = i;
            }
        }
        // Find the warehouse with the given id
        Warehouse warehouse = warehouse_list[index];

        
        //Check if the warehouse exists
        if (index != -1) {
            cout << setw(15) << "Container row" << setw(15) << "Container col" << setw(15) << "Customer id" << setw(15) << "Good name" << endl;
            // Loop through the grid of containers
            for (int i = 0; i < warehouse.getRows(); i++) {
                for (int j = 0; j < warehouse.getCols(); j++) {
                    // Get the current container at the grid position
                    //Container currentContainer = warehouse.getGrid()[i][j];
                    vector<Goods> goods = warehouse.getGrid()[i][j].getGoods(); // get the goods vector from the currentContainer object
                    // Print the container id and the number of goods in it
                    if (!goods.empty()) { // 判断vector是否为空
                        for (int k = 0; k < goods.size(); k++) { // loop through the goods vector
                            cout << setw(15) << i << setw(15) << j << setw(15) << goods[k].getCustomerId() << setw(15) << goods[k].getName() << endl;
                        }
                    }

                }
            }
        }
        else {
            // Output a reminder that there is no warehouse with the given id
            cout << "There is no warehouse with id " << warehouseId << endl;
        }
    }
	
};


void main() {
    MainProcess m;
    m.outputMainOperationMenu();
}

