#pragma once

#define WD_WIDTH 1280
#define WD_HEIGHT 670
#define MAX_MENU 6
#define DIS_MENUX 20
#define DIS_MENUY 20
#define OBJ_PER_PAGE 20

char MenuChinh[MAX_MENU + 1][30] = { "Material", "Employee", "Bill", "Statistic", "Help", "Quit" };
char MenuMater[][30] = { "Add", "Remove", "Adjust", "Materials List" };
char MenuEmp[][30] = { "Add", "Remove", "Adjust", "Employees List" };
char MenuBill[][30] = { "Create Bill", "Check Bill" };
char MenuStat[][30] = { "Bills", "Top Materials" };
char MenuHelp[][30] = { "Guide", "About" };

char title[][50]={"Remove Material", "Adjust Info Material", "Remove Employee", "Adjust Info Employee",
"Add Material To Bill", "Search Bill"};

//thong so
int ViTriMucMenu[MAX_MENU + 1] = { 10 };//a[0]=10
int ViTriMucMenuPhu[5] = { 0, 42, 84, 126, 168 };
int KichThuocMenuPhu[MAX_MENU + 1] = { 200, 200, 180, 180, 120 };
int ViTriKhung[] = { 0, 200, 260, 320, 380, 440 };

// notify
char Success[][50] = { "Added Successfully!", "Remove Successfully!", "Adjust Successfully!", "Save Successfully!" };
char Fail[][50] = { "Empty Field!", "Not Found!", "Empty List!","Wrong Date!", "Already Exists!",
"Employee Not Found!", "Not Enough Material!","Current Quantity: ", "Full List!", "Value Must Not Equal 0!" };

//error
char sameMat[][50] = { "Error: The same  Material's ID already exists!", "Yes", "No","Would you like to ADJUST the existing object?" };
char sameEmp[][50] = { "Error: The same  Employees's ID already exists!", "Yes", "No","Would you like to ADJUST the existing object?" };
char lackAmount[][30] = { "Current Quantity" };

char khungMat[][30] = { "Material's Informations", "Add Material", "Exit", "ID", "Name", "Unit", "Quantity", "Confirm" };
char checkMat[][30] = { "Material's Informations", "Confirm", "Exit", "ID", "Name", "Unit", "Quantity" };
char danhSachMat[][30] = { "STT", "ID", "Name", "Unit", "Quantity" };
char choiceObject[][30] = { "ID", "Materials List", "Employee List", "Check", "Exit" };
int  sizeDanhSachMat[] = { 10, 50, 105, 50, 20 };

//Bill
char khungBill[][30] = { "Bill's Informations", "Material List", "Exit", "ID", "Date (dd/mm/yyyy)", "Biller's ID", "Type", "Biller" };
char khungListBill[][30] = { "Add Material", "Confirm", "Exit" };
char khungchooseBill[][30] = { "Remove", "Adjust", "Exit" };
char type[][30] = { "N", "X","/" };
char danhSachDetailBill[][30] = { "STT", "ID", "Price", "VAT(%)", "Quantity" };
char khungDetailBill[][30] = { "Material's Informations", "Add Material", "Exit", "ID", "Price (Dong)", "VAT (%)", "Quantity", };
char choiceBillList[][30] = { "ID", "Bill List", "Check", "Exit" };
int  sizeKhungDate[] = { 55, 110, 165, 220, 275 };
char cancle[][50] = {"Notice!", "Yes", "No", "Would you like to CANCLE the bill?"};

//Employees
char khungEmp[][30] = { "Employee's Informations", "Add Employee", "Exit", "ID", "First Name", "Last Name", "Sex" };
char Sex[][30] = { "Male", "Female" };
char khungAdjustEmp[][30] = { "Employee's Informations", "Save", "Exit", "ID", "First Name", "Last Name", "Sex" };
char checkEmp[][30] = { "Employee's Informations", "Confirm", "Exit", "ID", "First Name", "Last Name", "Sex" };
char danhSachEmp[][30] = { "STT", "ID", "Last Name", "First Name", "Sex", "Nam", "Nu" };
int  sizeDanhSachEmp[] = { 10, 50, 100, 50, 20 };

//Statistic
char khungNhapNgay[][30] = { "Statistics of bills in: ", "Check", "Exit", "From date:", "To date:" };
char ngayTopVT[][30] = { "Top 10 Materials in:", "Check", "Exit", "From date:", "To date:" };
char trangBill[][30] = { "STT", "ID", "Date", "Type", "Last Name", "First Name", "Value" };
char trangTop[][30] = { "Rank", "ID", "Name", "Revenue" };
int  sizeTrangBill[] = { 10, 100, 50, 20, 80, 40, 70 };
int  sizeTrangTop[] = { 10, 60, 100, 70 };

//end


