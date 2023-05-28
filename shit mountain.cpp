#include <iostream>
#include<string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <sstream>
#include"Customer.h"
#include"Warehouse.h"
#include"Goods.h"
#include"WarehouseManager.h"

using namespace std;

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
		//customerMenu();
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
		cout << "Please input warehouseId you want to query";
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
		cout << "Please input warehouseId, row, col where you want to store your goods";
		cin >> warehouseId >> row >> col;
		addGoods(warehouseId, row, col);
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
		cout << "Please enter the goods in year, month, date:" << endl;
		cin >> y1 >> m1 >> d1;
		Date intime = Date(y1, m1, d1);
		cout << "Please enter the goods out year, month, date:" << endl;
		cin >> y2 >> m2 >> d2;
		Date outtime = Date(y2, m2, d2);
		// Check if the current container has enough space for the new goods
		if (currentContainer.getGoods().size() + quantity <= currentContainer.getCapacity()) {
			// Create a new good object with the input information
			Goods newGood = Goods(id, name, size, quantity, warehouseId, row, col, currentuser.getId(), intime, outtime);
			// Add the new good to the current container
			currentContainer.getGoods().push_back(newGood);
			// Update the grid with the updated container
			warehouse_list[index].getGrid()[row][col] = currentContainer;
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
	// Check if the warehouse exists
	if (index != -1) {
		cout << setw(15) << "Container row" << setw(15) << "Container col" << setw(15) << "Customer id" << endl;
		// Loop through the grid of containers
		for (int i = 0; i < warehouse.getRows(); i++) {
			for (int j = 0; j < warehouse.getCols(); j++) {
				// Get the current container at the grid position
				//Container currentContainer = warehouse.getGrid()[i][j];
				vector<Goods> goods = warehouse.getGrid()[i][j].getGoods(); // get the goods vector from the currentContainer object
				// Print the container id and the number of goods in it
				if (!goods.empty()) { // 判断vector是否为空
					for (int i = 0; i < goods.size(); i++) { // loop through the goods vector
						cout << setw(15) << i << setw(15) << j << setw(15) << goods[i].getCustomerId() << endl;
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
void function();
void writeUser(string ID, string name, string pwd);
void writeGood(string ID, string name, int originalNum, int outNum, int inNum, int finalNum);
void query();

//登录后的菜单
void menuLogin() {
	cout << " ---------------------------Welcome to the warehouse management system------------------------" << endl;
	cout << " |                         1、查询功能                                  |" << endl;
	cout << " |                         2、入库功能                                  |" << endl;
	cout << " |                         3、出库功能                                  |" << endl;
	cout << " |                         4、添加商品功能                              |" << endl;
	cout << " |                         5、删除商品功能                              |" << endl;
	cout << " |                         6、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
}

//查询功能的菜单
void menuQuery() {
	cout << " ---------------------------欢迎使用仓库管理系统------------------------" << endl;
	cout << " |                         1、查询账号信息                              |" << endl;
	cout << " |                         2、查询库存信息                              |" << endl;
	cout << " |                         3、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
}

//总菜单
void menuSub() {
	cout << " ---------------------------欢迎使用仓库管理系统------------------------" << endl;
	cout << " |                         1、注册                                      |" << endl;
	cout << " |                         2、登录                                      |" << endl;
	cout << " |                         3、退出                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " 请输入你的选择:";
};

//user类
class user {
private:
	string ID;
	string Name;
	string Password;
public:
	user() {};
	void Register();
	void Enter();
	void queryUser();
	void readUser(string number);
};

//读取用户的信息
void user::readUser(string number) {
	string IDStr, nameStr, pwdStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> pwdStr;
	this->ID = IDStr;
	this->Name = nameStr;
	this->Password = pwdStr;
}
//当前用户nowUser
user nowUser;

//注册功能
void user::Register()
{
	string pw1;
	string pw2;
	user person;
flag:
	cout << "请设置您的ID:";
	cin >> person.ID;
	ifstream rfile;
	rfile.open("user.txt", ios::in);
	string temp;
	user u;
	while (getline(rfile, temp)) {
		u.readUser(temp);
		if (u.ID == person.ID) {
			cout << "该ID已存在，请重新设置!" << endl;
			goto flag;
		}
	}
	cout << "请设置您的用户名:";
	cin >> person.Name;
	cout << "请设置您的密码:";
flag0:
	cin >> pw1;
	cout << "请再次确认您的密码:";
	cin >> pw2;
	if (pw1 != pw2)
	{
		cout << "前后两次输入密码不一致，请重新设置密码!" << endl;
		goto flag0;
	}
	person.Password = pw1;
	writeUser(person.ID, person.Name, person.Password);
	cout << "\n" << endl;
	cout << "用户[" << person.Name << "]注册成功!" << endl;
	system("pause");
};

//登录功能
void user::Enter()
{
flag1:
	cout << "请输入你的ID:";
	string id;
	string pwd;
	cin >> id;
	ifstream rfileId;
	rfileId.open("user.txt", ios::in);
	string tempId;
	user userId;
	while (getline(rfileId, tempId)) {
		userId.readUser(tempId);
		if (userId.ID == id) {
			goto flag2;
		}
	}
	cout << "该ID不存在，请重新输入!" << endl;
	goto flag1;

flag2:
	cout << "请输入你的密码:";
	cin >> pwd;
	ifstream rfilePwd;
	rfilePwd.open("user.txt", ios::in);
	string tempPwd;
	user userPwd;
	while (getline(rfilePwd, tempPwd)) {
		userPwd.readUser(tempPwd);
		if (userPwd.ID == id)
		{
			if (userPwd.Password == pwd)
			{
				break;
			}
			else
			{
				cout << "密码错误，请重新输入!" << endl;
				system("pause");
				goto flag2;
			}
		}
	}
	nowUser = userPwd;
	cout << "\n" << endl;
	cout << "用户[" << userPwd.Name << "]登录成功!" << endl;
	system("pause");
	function();
};

//显示当前用户的信息
void user::queryUser() {
	cout << "您的ID为:" << this->ID << endl;
	cout << "您的密码为:" << this->Password << endl;
	cout << "您的用户名为:" << this->Name << endl;
	system("pause");
}

//将注册的用户信息写入user.txt
void writeUser(string ID, string name, string pwd) {
	fstream wfile;
	int IDLen = ID.size();
	int nameLen = name.size();
	int pwdLen = pwd.size();

	char* IDnumber = new char[IDLen];
	char* username = new char[nameLen];
	char* password = new char[pwdLen];

	strcpy(IDnumber, ID.c_str());
	strcpy(username, name.c_str());
	strcpy(password, pwd.c_str());

	wfile.open("user.txt", ios::out | ios::app);
	wfile.write(IDnumber, IDLen);
	wfile.write(" ", strlen(" "));
	wfile.write(username, nameLen);
	wfile.write(" ", strlen(" "));
	wfile.write(password, pwdLen);
	wfile.write("\n", strlen("\n"));
	wfile.close();
}


//good类
class good {
private:
	string ID;
	string Name;
	int originalNum;
	int outNum;
	int inNum;
	int finalNum;
public:
	good() {};
	void queryGood();
	void library();
	void readGood(string number);
	void outbound();
	void deleteGood();
};

//vector是一个封装了动态大小数组的顺序容器,用于存放所有商品的信息
vector<good> goods;

//将商品信息写入good.txt
void writeGood(string ID, string name, int originalNum, int outNum, int inNum, int finalNum) {
	char originalNumCh[10];
	_itoa(originalNum, originalNumCh, 10);
	string originalNumStr(originalNumCh, originalNumCh + strlen(originalNumCh));

	char outNumCh[10];
	_itoa(outNum, outNumCh, 10);
	string outNumStr(outNumCh, outNumCh + strlen(outNumCh));

	char inNumCh[10];
	_itoa(inNum, inNumCh, 10);
	string inNumStr(inNumCh, inNumCh + strlen(inNumCh));

	char finalNumCh[10];
	_itoa(finalNum, finalNumCh, 10);
	string finalNumStr(finalNumCh, finalNumCh + strlen(finalNumCh));

	int IDLen = ID.size();
	int nameLen = name.size();
	int originalNumStrLen = originalNumStr.size();
	int outNumStrLen = outNumStr.size();
	int inNumLen = inNumStr.size();
	int finalNumLen = finalNumStr.size();

	char* IDnumber = new char[IDLen];
	char* username = new char[nameLen];
	char* originalNumArr = new char[originalNumStrLen];
	char* outNumArr = new char[outNumStrLen];
	char* inNumArr = new char[inNumLen];
	char* finalNumArr = new char[finalNumLen];

	strcpy(IDnumber, ID.c_str());
	strcpy(username, name.c_str());
	strcpy(originalNumArr, originalNumStr.c_str());
	strcpy(outNumArr, outNumStr.c_str());
	strcpy(inNumArr, inNumStr.c_str());
	strcpy(finalNumArr, finalNumStr.c_str());

	fstream wfile;
	wfile.open("good.txt", ios::out | ios::app);
	wfile.write(IDnumber, IDLen);
	wfile.write(" ", strlen(" "));
	wfile.write(username, nameLen);
	wfile.write(" ", strlen(" "));
	wfile.write(originalNumArr, originalNumStrLen);
	wfile.write(" ", strlen(" "));
	wfile.write(outNumArr, outNumStrLen);
	wfile.write(" ", strlen(" "));
	wfile.write(inNumArr, inNumLen);
	wfile.write(" ", strlen(" "));
	wfile.write(finalNumArr, finalNumLen);
	wfile.write("\n", strlen("\n"));
	wfile.close();
}

//读取商品的信息
void good::readGood(string number) {
	string IDStr, nameStr, originalNumStr, outNumStr, inNumStr, finalNumStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> originalNumStr >> outNumStr >> inNumStr >> finalNumStr;
	stringstream ssOriginalNum;
	ssOriginalNum << originalNumStr;
	int originalNum;
	ssOriginalNum >> originalNum;
	stringstream ssOutNum;
	ssOutNum << outNumStr;
	int outNum;
	ssOutNum >> outNum;
	stringstream ssInNum;
	ssInNum << inNumStr;
	int inNum;
	ssInNum >> inNum;
	stringstream ssFinalNum;
	ssFinalNum << finalNumStr;
	int finalNum;
	ssFinalNum >> finalNum;
	this->ID = IDStr;
	this->Name = nameStr;
	this->originalNum = originalNum;
	this->outNum = outNum;
	this->inNum = inNum;
	this->finalNum = finalNum;
}

//查询并显示对应商品的信息
void good::queryGood() {
	good findGood;
	string temp;
	string inNumber;
	ifstream rfile;
	rfile.open("good.txt", ios::in);
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
		rfile.close();
	}
	else
	{
		rfile.close();
		while (1)
		{

			ifstream rfile;
			rfile.open("good.txt", ios::in);
			cout << "请输入查询商品的货品编号:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					cout << "您的货品编号为:" << findGood.ID << endl;
					cout << "您的货品名称为:" << findGood.Name << endl;
					cout << "您的原始库存为:" << findGood.originalNum << endl;
					cout << "您的进货数目为:" << findGood.inNum << endl;
					cout << "您的出货数目为:" << findGood.outNum << endl;
					cout << "您的最终库存为:" << findGood.finalNum << endl;
					rfile.close();
					goto flag3;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
		}
	flag3:
		system("pause");
	}
}

//查询功能
void query()
{
	char choice;
	good queryGood;
	while (1)
	{
		system("cls");
		menuQuery();
		cin >> choice;
		switch (choice)
		{
		case '1':
			nowUser.queryUser();
			break;
		case '2':
			queryGood.queryGood();
			break;
		case '3':
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

//入库功能
void good::library() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag4;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
		}
	flag4:
		cout << "请输入入库的数目:";
		int libraryNumber;
		cin >> libraryNumber;
		int inNumTemp = findGood.inNum;
		int finalNumTemp = findGood.finalNum;
		findGood.inNum += libraryNumber;
		findGood.finalNum += libraryNumber;

		if (findGood.inNum < 0 || findGood.finalNum < 0 || libraryNumber < 0) {
			cout << "输入的数目错误，请重新输入!" << endl;
			findGood.inNum = inNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag4;
		}

		//将文件的数据全部取出，修改对应的那行数据，再写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID == inNumber)
			{
				goods.push_back(findGood);
			}
			else
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
	}
	cout << "\n" << endl;
	cout << "入库成功!" << endl;
	cout << "提示:当前入库的数目为:" << findGood.inNum << "，当前库存的数目为:" << findGood.finalNum << endl;
	system("pause");
}

//出库功能
void good::outbound() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag5;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
		}
	flag5:
		cout << "请输入出库的数目:";
		int outboundNumber;
		cin >> outboundNumber;
		int outNumTemp = findGood.outNum;
		int finalNumTemp = findGood.finalNum;
		findGood.outNum += outboundNumber;
		findGood.finalNum -= outboundNumber;
		if (findGood.outNum < 0 || findGood.finalNum < 0 || outboundNumber < 0) {
			cout << "输入的数目错误，请重新输入!" << endl;
			findGood.outNum = outNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag5;
		}

		//将文件的数据全部取出，修改对应的那行数据，清空文件数据，再重新写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID == inNumber)
			{
				goods.push_back(findGood);
			}
			else
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
	}
	cout << "\n" << endl;
	cout << "出库成功!" << endl;
	cout << "提示:当前出库的数目为:" << findGood.outNum << "，当前库存的数目为:" << findGood.finalNum << endl;
	system("pause");
}

//添加商品功能
void addGood() {
	string addID;
	string addName;
	int addOriginalNum;
	int addOutNum;
	int addInNum;
	int addFinalNum;
	cout << "请输入商品ID:";
	cin >> addID;
	cout << "请输入商品名称:";
	cin >> addName;
	cout << "请输入商品原始库存:";
	cin >> addOriginalNum;
	cout << "请输入商品出库数目:";
	cin >> addOutNum;
	cout << "请输入商品入库数目:";
	cin >> addInNum;
	cout << "请输入商品最终数目:";
	cin >> addFinalNum;
	writeGood(addID, addName, addOriginalNum, addOutNum, addInNum, addFinalNum);
	cout << "\n" << endl;
	cout << "商品[" << addName << "]添加成功!" << endl;
	system("pause");
}

//删除商品功能
void good::deleteGood() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "提示:找不到 good.txt 文件!" << endl;
		cout << "提示:请添加 good.txt 文件!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "请输入查询商品的货品编号:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag6;
				}
			}
			cout << "输入有误，请重新输入!" << endl;
		}
	flag6:
		//将文件的数据全部取出，删除对应的那行数据，清空文件数据，再重新写入文件
		rfile.seekg(0);
		good tempGood;
		string tempStr;
		while (getline(rfile, tempStr))
		{
			tempGood.readGood(tempStr);
			if (tempGood.ID != inNumber)
			{
				goods.push_back(tempGood);
			}
		}
		ofstream f("good.txt", ios::trunc);
		f.close();
		for (int i = 0; i < goods.size(); i++)
		{
			writeGood(goods.at(i).ID, goods.at(i).Name, goods.at(i).originalNum, goods.at(i).outNum, goods.at(i).inNum, goods.at(i).finalNum);
		}
		goods.clear();
	}
	cout << "\n" << endl;
	cout << "商品删除成功!" << endl;
	system("pause");
}

//总功能
void function() {
	char choice;
	good d;
	while (1)
	{
		system("cls");
		menuLogin();
		cin >> choice;
		switch (choice)
		{
		case '1':
			//查询功能
			query();
			break;
		case '2':
			//入库功能
			d.library();
			break;
		case '3':
			//出库功能
			d.outbound();
			break;
		case '4':
			//添加商品功能
			addGood();
			break;
		case '5':
			//删除商品功能
			d.deleteGood();
			break;
		case '6':
			//退出
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

//主函数
void main()
{
	//设置控制台窗口和字体的颜色
	system("color 70");
	char choice;
	user u;
	while (1)
	{
		system("cls");
		menuSub();
		cin >> choice;
		switch (choice)
		{
		case '1':
			//注册功能
			u.Register();
			break;
		case '2':
			//登录功能
			u.Enter();
			break;
		case '3':
			//退出
			return;
			break;
		default:
			cout << "提示:请输入有误，重新输入!" << endl;
			system("pause");
		}
	}
}

