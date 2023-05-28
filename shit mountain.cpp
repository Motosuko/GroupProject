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
			string password; // ����
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
			string password; // ����
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
				if (!goods.empty()) { // �ж�vector�Ƿ�Ϊ��
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

//��¼��Ĳ˵�
void menuLogin() {
	cout << " ---------------------------Welcome to the warehouse management system------------------------" << endl;
	cout << " |                         1����ѯ����                                  |" << endl;
	cout << " |                         2����⹦��                                  |" << endl;
	cout << " |                         3�����⹦��                                  |" << endl;
	cout << " |                         4�������Ʒ����                              |" << endl;
	cout << " |                         5��ɾ����Ʒ����                              |" << endl;
	cout << " |                         6���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
}

//��ѯ���ܵĲ˵�
void menuQuery() {
	cout << " ---------------------------��ӭʹ�òֿ����ϵͳ------------------------" << endl;
	cout << " |                         1����ѯ�˺���Ϣ                              |" << endl;
	cout << " |                         2����ѯ�����Ϣ                              |" << endl;
	cout << " |                         3���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
}

//�ܲ˵�
void menuSub() {
	cout << " ---------------------------��ӭʹ�òֿ����ϵͳ------------------------" << endl;
	cout << " |                         1��ע��                                      |" << endl;
	cout << " |                         2����¼                                      |" << endl;
	cout << " |                         3���˳�                                      |" << endl;
	cout << " -----------------------------------------------------------------------" << endl;
	cout << " ���������ѡ��:";
};

//user��
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

//��ȡ�û�����Ϣ
void user::readUser(string number) {
	string IDStr, nameStr, pwdStr;
	istringstream is(number);
	is >> IDStr >> nameStr >> pwdStr;
	this->ID = IDStr;
	this->Name = nameStr;
	this->Password = pwdStr;
}
//��ǰ�û�nowUser
user nowUser;

//ע�Ṧ��
void user::Register()
{
	string pw1;
	string pw2;
	user person;
flag:
	cout << "����������ID:";
	cin >> person.ID;
	ifstream rfile;
	rfile.open("user.txt", ios::in);
	string temp;
	user u;
	while (getline(rfile, temp)) {
		u.readUser(temp);
		if (u.ID == person.ID) {
			cout << "��ID�Ѵ��ڣ�����������!" << endl;
			goto flag;
		}
	}
	cout << "�����������û���:";
	cin >> person.Name;
	cout << "��������������:";
flag0:
	cin >> pw1;
	cout << "���ٴ�ȷ����������:";
	cin >> pw2;
	if (pw1 != pw2)
	{
		cout << "ǰ�������������벻һ�£���������������!" << endl;
		goto flag0;
	}
	person.Password = pw1;
	writeUser(person.ID, person.Name, person.Password);
	cout << "\n" << endl;
	cout << "�û�[" << person.Name << "]ע��ɹ�!" << endl;
	system("pause");
};

//��¼����
void user::Enter()
{
flag1:
	cout << "���������ID:";
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
	cout << "��ID�����ڣ�����������!" << endl;
	goto flag1;

flag2:
	cout << "�������������:";
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
				cout << "�����������������!" << endl;
				system("pause");
				goto flag2;
			}
		}
	}
	nowUser = userPwd;
	cout << "\n" << endl;
	cout << "�û�[" << userPwd.Name << "]��¼�ɹ�!" << endl;
	system("pause");
	function();
};

//��ʾ��ǰ�û�����Ϣ
void user::queryUser() {
	cout << "����IDΪ:" << this->ID << endl;
	cout << "��������Ϊ:" << this->Password << endl;
	cout << "�����û���Ϊ:" << this->Name << endl;
	system("pause");
}

//��ע����û���Ϣд��user.txt
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


//good��
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

//vector��һ����װ�˶�̬��С�����˳������,���ڴ��������Ʒ����Ϣ
vector<good> goods;

//����Ʒ��Ϣд��good.txt
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

//��ȡ��Ʒ����Ϣ
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

//��ѯ����ʾ��Ӧ��Ʒ����Ϣ
void good::queryGood() {
	good findGood;
	string temp;
	string inNumber;
	ifstream rfile;
	rfile.open("good.txt", ios::in);
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
		rfile.close();
	}
	else
	{
		rfile.close();
		while (1)
		{

			ifstream rfile;
			rfile.open("good.txt", ios::in);
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					cout << "���Ļ�Ʒ���Ϊ:" << findGood.ID << endl;
					cout << "���Ļ�Ʒ����Ϊ:" << findGood.Name << endl;
					cout << "����ԭʼ���Ϊ:" << findGood.originalNum << endl;
					cout << "���Ľ�����ĿΪ:" << findGood.inNum << endl;
					cout << "���ĳ�����ĿΪ:" << findGood.outNum << endl;
					cout << "�������տ��Ϊ:" << findGood.finalNum << endl;
					rfile.close();
					goto flag3;
				}
			}
			cout << "������������������!" << endl;
		}
	flag3:
		system("pause");
	}
}

//��ѯ����
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
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

//��⹦��
void good::library() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag4;
				}
			}
			cout << "������������������!" << endl;
			system("pause");
		}
	flag4:
		cout << "������������Ŀ:";
		int libraryNumber;
		cin >> libraryNumber;
		int inNumTemp = findGood.inNum;
		int finalNumTemp = findGood.finalNum;
		findGood.inNum += libraryNumber;
		findGood.finalNum += libraryNumber;

		if (findGood.inNum < 0 || findGood.finalNum < 0 || libraryNumber < 0) {
			cout << "�������Ŀ��������������!" << endl;
			findGood.inNum = inNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag4;
		}

		//���ļ�������ȫ��ȡ�����޸Ķ�Ӧ���������ݣ���д���ļ�
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
	cout << "���ɹ�!" << endl;
	cout << "��ʾ:��ǰ������ĿΪ:" << findGood.inNum << "����ǰ������ĿΪ:" << findGood.finalNum << endl;
	system("pause");
}

//���⹦��
void good::outbound() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag5;
				}
			}
			cout << "������������������!" << endl;
		}
	flag5:
		cout << "������������Ŀ:";
		int outboundNumber;
		cin >> outboundNumber;
		int outNumTemp = findGood.outNum;
		int finalNumTemp = findGood.finalNum;
		findGood.outNum += outboundNumber;
		findGood.finalNum -= outboundNumber;
		if (findGood.outNum < 0 || findGood.finalNum < 0 || outboundNumber < 0) {
			cout << "�������Ŀ��������������!" << endl;
			findGood.outNum = outNumTemp;
			findGood.finalNum = finalNumTemp;
			goto flag5;
		}

		//���ļ�������ȫ��ȡ�����޸Ķ�Ӧ���������ݣ�����ļ����ݣ�������д���ļ�
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
	cout << "����ɹ�!" << endl;
	cout << "��ʾ:��ǰ�������ĿΪ:" << findGood.outNum << "����ǰ������ĿΪ:" << findGood.finalNum << endl;
	system("pause");
}

//�����Ʒ����
void addGood() {
	string addID;
	string addName;
	int addOriginalNum;
	int addOutNum;
	int addInNum;
	int addFinalNum;
	cout << "��������ƷID:";
	cin >> addID;
	cout << "��������Ʒ����:";
	cin >> addName;
	cout << "��������Ʒԭʼ���:";
	cin >> addOriginalNum;
	cout << "��������Ʒ������Ŀ:";
	cin >> addOutNum;
	cout << "��������Ʒ�����Ŀ:";
	cin >> addInNum;
	cout << "��������Ʒ������Ŀ:";
	cin >> addFinalNum;
	writeGood(addID, addName, addOriginalNum, addOutNum, addInNum, addFinalNum);
	cout << "\n" << endl;
	cout << "��Ʒ[" << addName << "]��ӳɹ�!" << endl;
	system("pause");
}

//ɾ����Ʒ����
void good::deleteGood() {
	ifstream rfile;
	good findGood;
	rfile.open("good.txt", ios::in);
	string temp;
	string inNumber;
	int num = rfile.tellg();
	if (num == -1)
	{
		cout << "��ʾ:�Ҳ��� good.txt �ļ�!" << endl;
		cout << "��ʾ:����� good.txt �ļ�!" << endl;
	}
	else
	{
		while (1)
		{
			cout << "�������ѯ��Ʒ�Ļ�Ʒ���:";
			cin >> inNumber;
			while (getline(rfile, temp))
			{
				findGood.readGood(temp);
				if (findGood.ID == inNumber)
				{
					goto flag6;
				}
			}
			cout << "������������������!" << endl;
		}
	flag6:
		//���ļ�������ȫ��ȡ����ɾ����Ӧ���������ݣ�����ļ����ݣ�������д���ļ�
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
	cout << "��Ʒɾ���ɹ�!" << endl;
	system("pause");
}

//�ܹ���
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
			//��ѯ����
			query();
			break;
		case '2':
			//��⹦��
			d.library();
			break;
		case '3':
			//���⹦��
			d.outbound();
			break;
		case '4':
			//�����Ʒ����
			addGood();
			break;
		case '5':
			//ɾ����Ʒ����
			d.deleteGood();
			break;
		case '6':
			//�˳�
			return;
			break;
		default:
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

//������
void main()
{
	//���ÿ���̨���ں��������ɫ
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
			//ע�Ṧ��
			u.Register();
			break;
		case '2':
			//��¼����
			u.Enter();
			break;
		case '3':
			//�˳�
			return;
			break;
		default:
			cout << "��ʾ:������������������!" << endl;
			system("pause");
		}
	}
}

