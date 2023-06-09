#include <iostream>
#include <string.h>
#include <time.h>
#include "function.h"

#define MAXL_DETAIL 20
#define MAXL_EMP 500
using namespace std;

//Nghia

struct Dates{
	int day;
	int month;
	int year;
	
	Dates(){
		day = 1;
		month = 1;
		year = 1;
	}
	bool isValid(){
		if(month<1 || month>12 || year<0 || day<0 || day>31){
			return false;
		}
		
		if (month==2 || month==4 || month==6 || month==9 || month == 11){
			if (day > 30)
				return false;
			if (month == 2){
				//chia du 100 == 0 la nam co 2 so 0 o cuoi
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
				//nam co 2 so 0 o cuoi chia du 400 == la nam nhuan, cac truong hop khac chia du 4 == 0 la nam nhu�n
					if (day > 29)
						return false;
				}
				else{
					if (day > 28)
						return false;
				}
			}
		}
		return true;
	}
	
	bool operator > (const struct Dates &other){
		if (this->year > other.year)
			return true;
		else
			if (this->year == other.year) {
				if(this->month > other.month)
					return true;
				else
					if (this->month == other.month){
						if (this->day > other.day)
							return true;
					}
		}	
		return false;
	}
	
	bool operator < (const struct Dates &other){
		if (this->year < other.year)
			return true;
		else 
			if (this->year == other.year) {
				if(this->month < other.month)
					return true;
				else 
					if (this->month == other.month){
						if (this->day < other.day)
							return true;
					}
			}		
		return false;
	}
	
	bool operator == (const struct Dates &other){
		if (this->year == other.year)
			if (this->month == other.month)
				if (this->day == other.day)
					return true;
		return false;
	}
};


// CT_HOADON
struct Details{
	char ID[11];
	unsigned int amount;
	unsigned int price;
	int VAT;
	
//	bool operator == (struct Details other){
//		return (strcmp(this->ID, other.ID) == 0);
//	}
};


//===============DanhsachCT_HOADON==========
struct listBillDeta{
	int n;
	struct Details nodeListDeta[20];
	
	listBillDeta(){
		n = 0;
	}
	
	bool isEmpty(){
		return (n == 0);
	}
	
	bool isFull(){
		return (n == MAXL_DETAIL);
	}
	//push_back
	void Insert(struct Details newNode)	{
		nodeListDeta[n++] = newNode;
	}
	
	void Detele(int pos){
		for (int j = pos+1; j < n; j++){
			nodeListDeta[j-1] = nodeListDeta[j];
		}
		n-=1;
	}
	//kiem tra vat tu da co
	bool cmp_ID(char keyID[]){
		for(int i = 0; i < n; i++){
			if(strcmp(nodeListDeta[i].ID, keyID) == 0){
				return 1;
			}
		}
		return 0;
	}
};


//=============HOADON======================
struct Bills{
	char Num[21];
	struct Dates date;
	char type;
	struct listBillDeta *details;
	Bills(){
		Num[0] = '\0';
		details = new listBillDeta;
	}
//	bool operator == (struct Bills other){
//		return(strcmp(this->Num, other.Num) == 0);
//	}
	long long value(){
		long long res = 0;
		for (int i = 0; i < details->n; i++){
			res += (1LL*details->nodeListDeta[i].amount*details->nodeListDeta[i].price)/100.0*((100+details->nodeListDeta[i].VAT));
		}
		return res;
	}
};

struct nodeListBill{
	struct Bills info;
	struct nodeListBill *next;
};
typedef struct nodeListBill* NODE_LB;

//============DANH-SACH-HOA-DON===============
struct ListBill{
	int Size;
	NODE_LB firstNode;
	
	ListBill(){
		Size = 0;
		firstNode = NULL;
	}
	
	void insertFirst(Bills &nodeN){
		NODE_LB p = new nodeListBill;
		p->info = nodeN;
		p->next = firstNode;
		firstNode = p;
		Size++;
	}
	
	void loadNODE_LB(NODE_LB p){
		p->next = firstNode;
		firstNode = p;
	}
	
	bool checkID(char ID[]){
		for (NODE_LB p = firstNode; p != NULL; p = p->next){
			if (strcmp(p->info.Num, ID) == 0)
				return false;
		}
		return true;
	}
	
	Bills findBill(char IDBill[20]){
		for (NODE_LB p = firstNode; p != NULL; p = p->next){
			if (strcmp(p->info.Num, IDBill) == 0)
				return p->info;
		}
	}
};



//=============NHANVIEN==================
struct Employee{
	char ID[11];
	char firstName[11];
	char lastName[21];
	bool sex; //1: male
	struct ListBill listBill;
	Employee(){
		ID[0] = '\0';
		firstName[0] = '\0';
		lastName[0] = '\0';
		sex = 1;
	}
	
	bool operator > (const struct Employee &other){
		char thisFN[11] = "";
		char thisLN[21] = "";
		char otherFN[11] = "";
		char otherLN[21] = "";
	
		//chuyen ten -> xoa dau cach + viet thuong
		strcpy(thisFN, this->firstName);
		delBlank(thisFN);
		for (int i = 0; i < strlen(thisFN); i++)
			thisFN[i] = tolower(thisFN[i]);
			
		strcpy(thisLN, this->lastName);
		delBlank(thisLN);
		for (int i = 0; i < strlen(thisLN); i++)
			thisLN[i] = tolower(thisLN[i]);
			
		strcpy(otherFN, other.firstName);
		delBlank(otherFN);
		for (int i = 0; i < strlen(otherFN); i++)
			otherFN[i] = tolower(otherFN[i]);
			
		strcpy(otherLN, other.lastName);
		delBlank(otherLN);
		for (int i = 0; i < strlen(otherLN); i++)
			otherLN[i] = tolower(otherLN[i]);
		
		if (strcmp(thisFN, otherFN) > 0){
			return true;
		}
		else
			if (strcmp(thisFN, otherFN) == 0){
				if (strcmp(thisLN, otherLN) > 0){
					return true;
				}
				else
					return false;
			}
			else 
				return false;
	}
	
	bool operator < (const struct Employee &other){
		char thisFN[11] = "";
		char thisLN[21] = "";
		char otherFN[11] = "";
		char otherLN[21] = "";
	
		//chuyen ten -> xoa dau cach + viet thuong
		strcpy(thisFN, this->firstName);
		delBlank(thisFN);
		for (int i = 0; i < strlen(thisFN); i++)
			thisFN[i] = tolower(thisFN[i]);
			
		strcpy(thisLN, this->lastName);
		delBlank(thisLN);
		for (int i = 0; i < strlen(thisLN); i++)
			thisLN[i] = tolower(thisLN[i]);
			
		strcpy(otherFN, other.firstName);
		delBlank(otherFN);
		for (int i = 0; i < strlen(otherFN); i++)
			otherFN[i] = tolower(otherFN[i]);
			
		strcpy(otherLN, other.lastName);
		delBlank(otherLN);
		for (int i = 0; i < strlen(otherLN); i++)
			otherLN[i] = tolower(otherLN[i]);
		
		if (strcmp(thisFN, otherFN) < 0){
			return true;
		}
		else 
			if (strcmp(thisFN, otherFN) == 0){
				if (strcmp(thisLN, otherLN) < 0){
					return true;
				}
				else
					return false;
			}
			else 
				return false;
	}	
};

//========DANH-SACH-NHAN-VIEN===========================
struct listEmp{
	int n;
	struct Employee *nodeListEmp[MAXL_EMP];
	
	listEmp(){
		n = 0;
	}
	
	bool isFull(){
		return (n == MAXL_EMP);
	}
	//push_back
	void Insert(struct Employee *newNode){
		nodeListEmp[n++] = newNode;
	}
	
	void Detele(int pos){
		delete nodeListEmp[pos];
		for (int j = pos+1; j < n; j++){
			nodeListEmp[j-1] = nodeListEmp[j];
		}
		n--;
	}
	
	void DeteleID(char tmpID[11]){
		for (int i = 0; i < n; i++){
			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0){
				this->Detele(i);
				break;
			}
		}
	}
	
	int Search_info(struct Employee *info){
		for (int i = 0; i < n; i++){
			if (strcmp(nodeListEmp[i]->ID, info->ID) == 0){
				return i;
			}
		}
		return -1;
	}
	
	//check ID nhan vien, tra ve NULL neu k trung
	struct Employee* Search_ID(char tmpID[11]){
		for (int i = 0; i < n; i++){
			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0){
				return nodeListEmp[i];
			}
		}
		return NULL;
	}
	
	//return false neu co ID trung
	bool checkIDBill(char idBill[20]){
		for (int numE = 0; numE < n; numE++){
			if (nodeListEmp[numE]->listBill.checkID(idBill) == false) // co ID trung
				return false;
		}
		return true;
	}
	
	// check ID bill
	Employee *FindEmp(char IDBill[20]){
		for (int numE = 0; numE < n; numE++){
			if (nodeListEmp[numE]->listBill.checkID(IDBill) == false) // co ID trung
				return nodeListEmp[numE];
		}
		return NULL;
	}
	
	void addBill(char idEmp[11], Bills &newBill){
		struct Employee* p = Search_ID(idEmp);
		p->listBill.insertFirst(newBill);
	}
	
};

void sortEmp(struct Employee *arr[], int left, int right){
	struct Employee *mid = arr[(left + right) / 2];
	int i = left, j = right;
	do{
		while(*arr[i] < *mid)
			i++;
		while(*arr[j] > *mid)
			j--;
		if(i <= j){
			if(i < j){
				Employee *tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		sortEmp(arr, left, j);
	if(right > i)
		sortEmp(arr, i, right);
}

//==========DANH-SACH-BILL-THEO-NGAY===============
// dung de thong ke va in top vat tu Cau G, H
struct billDateNode{
	
	struct Bills *info;
	struct Employee *Emp;
	struct billDateNode *next;
	
};

typedef struct billDateNode* NODE_BDate;

struct listBillDate{
	int Size;
	NODE_BDate firstNode;
	
	listBillDate(){
		Size = 0;
		firstNode = NULL;
	}
	
	void insert(struct Bills &bill, struct Employee *Emp){
		NODE_BDate newNode, before, after;
		newNode = new billDateNode;
		newNode->info = &bill;
		newNode->Emp = Emp;
		for (after = firstNode; 
			after != NULL && after->info->date < newNode->info->date;
			before = after, after = after->next);	//muc dich chen tang dan theo ngay
			
		if (after == firstNode){	//after->info->date > newNode->info->date;
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else{	//after->info->date < newNode->info->date;
			before->next = newNode;
			newNode->next = after;
		}
		Size++;
	}
	
	NODE_BDate index(int stt){
		NODE_BDate newNode = firstNode;
		for (int i = 0; i < stt; newNode = newNode->next, i++);
		return newNode;
	}
};
//end cau G, H

//=============SAVE-and-LOAD===================

void writeDetail(ofstream &file, Details node){
	file << node.ID << endl;
	file << node.amount << endl;
	file << node.price << endl;
	file << node.VAT << endl;
}

void writeBill(ofstream &file, NODE_LB node){
	file << node->info.Num << endl;
	file << node->info.date.day << " " << node->info.date.month << " " << node->info.date.year << endl;
	file << node->info.type << endl;
	file << node->info.details->n << endl;
}

void writeEmp(ofstream &file, struct Employee *node){
	file << node->ID << endl;
	file << node->firstName << endl;
	file << node->lastName << endl;
	file << node->sex << endl;
	file << node->listBill.Size << endl;
}

void saveEmp(struct listEmp &ListEmployees){
	ofstream numList;
	ofstream fileListEmp;
	ofstream fileListBill;
	ofstream fileListDetail;
	numList.open("data/numberlist.txt", ios::out);
	fileListEmp.open("data/listemployee.txt", ios::out);
	fileListBill.open("data/listbill.txt", ios::out);
	fileListDetail.open("data/listdetailbill.txt", ios::out);
	
	numList << ListEmployees.n << endl;
	for (int i = 0; i < ListEmployees.n; i++){
		writeEmp(fileListEmp, ListEmployees.nodeListEmp[i]);
		struct ListBill tmpLB = ListEmployees.nodeListEmp[i]->listBill;
		for (NODE_LB p = tmpLB.firstNode; p != NULL; p = p->next){
			writeBill(fileListBill, p);
			struct listBillDeta *tmpDT = new listBillDeta;
			tmpDT = p->info.details;
			for (int j = 0; j < tmpDT->n; j++){
				writeDetail(fileListDetail, tmpDT->nodeListDeta[j]);
			}
			delete(tmpDT);
		}
	}
	fileListEmp.close();
	fileListBill.close();
	fileListDetail.close();
}

void readDetail(ifstream &file, struct Details &node){
	file >> node.ID;
	file >> node.amount;
	file >> node.price;
	file >> node.VAT;
}

void readBill(ifstream &file, NODE_LB node){
	file >> node->info.Num;
	file >> node->info.date.day >> node->info.date.month >> node->info.date.year;
	file >> node->info.type;
	file >> node->info.details->n;
}

void readEmp(ifstream &file, struct Employee *node){
	file >> node->ID;
	file.ignore();
	file.getline(node->firstName, sizeof(node->firstName));
	file.getline(node->lastName, sizeof(node->lastName));
	file >> node->sex;
	file >> node->listBill.Size;
}

void loadEmp(struct listEmp &ListEmployees){
	ifstream numList;
	ifstream fileListEmp;
	ifstream fileListBill;
	ifstream fileListDetail;
	numList.open("data/numberlist.txt", ios::in);
	fileListEmp.open("data/listemployee.txt", ios::in);
	fileListBill.open("data/listbill.txt", ios::in);
	fileListDetail.open("data/listdetailbill.txt", ios::in);
	
	numList >> ListEmployees.n;
	for (int i = 0; i < ListEmployees.n; i++){
		ListEmployees.nodeListEmp[i] = new Employee;
		readEmp(fileListEmp, ListEmployees.nodeListEmp[i]);
		struct ListBill tmpLB = ListEmployees.nodeListEmp[i]->listBill;
		for (int j = 0; j < tmpLB.Size; j++){
			NODE_LB p = new nodeListBill;
			readBill(fileListBill, p);
			ListEmployees.nodeListEmp[i]->listBill.loadNODE_LB(p);			
			for (int noNode = 0; noNode < p->info.details->n; noNode++){
				readDetail(fileListDetail, p->info.details->nodeListDeta[noNode]);	
			}
		}
	}
	fileListEmp.close();
	fileListBill.close();
	fileListDetail.close();
}

