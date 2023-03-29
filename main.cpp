#include "include/content.h"
#include "include/color.h"
#include "include/function.h"
#include "include/mater.h"
#include "include/emp.h"

using namespace std;

//==Cac ham ve==
void KhoiTaoChuongTrinh();
void VeMenu();
void VeMenuPhu(int sttMenuChinh, char menu[][30]);
void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE);
void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu);
void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu);
void veMuc3Chon(int x, int y, char khungNoiDung[][30],int choose, bool reset, int &stt);
void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n);
void VeMucChonNgay(int x, int y, char noiDungMucChon[], int ViTri, int mauNen, int mauChu);
void veKhungYesNo(char khungNoiDung[][50], bool &choice, int n);
void notify(char khungNoiDung[]);
//==============

//======Cac ham Menu======
void Menu(struct listEmp &ListEmployees,NODER &tree);
void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc);
void ChonMenuPhu(int x, struct listEmp &ListEmployees, NODER &tree);
void Save(NODER &tree,struct listEmp &ListEmployees);
void Materials(NODER &tree);
void Employees(struct listEmp &ListEmployees);
void Bill(NODER &tree,struct listEmp &ListEmployees);
void Statistics(NODER &tree, struct listEmp &ListEmployees);
void Help();
void About();
void Guide();
//=========================

//==========KimSon=========
//Cau A, B, G, H

//==========Nghia========
//Cau C, D, E, F

int Count = 0;
// Cau A:
void VeKhungAddMat(NODER &tree, char khungNoiDung[][30], int H, int W,int Mcase,  Material &tmp);
void infoText(int x, int y, char noiDung[],char info[], int MauChu);
void hienThiInfoMat(NODER &tree, char khungNoiDung[][30], int H, int W, char keyword[]);
void inID_ListMatToRoA(NODER &tree, char khungNoiDung[][30],bool RoA);
void danhSachRoAMat(NODER &tree, int &CountM, int RoA); //1: Remove 2: Adjust 
void chonTuDanhSachMat(NODER &tree, NameMats *arrM, int CountM, int &stt, int &startPage, bool &selected);

//cau B:
void inTrangMat(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], NameMats *arr, int start, int sizeM);
void taoMangMat(NODER &tree, NameMats *arrM);
void inVatTu(Material VT, int posX, int posY);
void inDanhSachMat(NODER &tree, int size);

// cau G: 
void nhapNgay(Dates &dayBegin, Dates &dayEnd, char khungNoiDung[][30], bool &selected);
void thongKeBill(struct listEmp &ListEmployees);
void taoMangBillDate(struct listEmp &List, struct listBillDate *arr, struct Dates dayBegin, struct Dates dayEnd);
void inTrangBill(struct listEmp &list, struct listBillDate *arr, int start);
//cau H:
void topVatTu(NODER &tree, struct listEmp &ListEmployees);
void inTrangTopVT(struct listEmp &list, struct NameMats *arr, int Size, int start);
void sortTopMat(NameMats *arr, int left, int right);
void updateRevenue(NameMats *arr, listBillDate *arrBill);
void TinhGiaTriRevenue(NameMats *arr, char code[11], unsigned long long Rev);
void findMaxMat(NameMats *arrMat, int &C);
//=========================


// cau C:
// nhap
void addEmp(struct listEmp &ListEmployees);
void khungNhapEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *tmpE, bool &selected);
// chinh sua
void chinhSuaEmp(struct listEmp &ListEmployees);
void inID_LIST(char khungNoiDung[][30], struct listEmp &ListEmployees, bool &list, char *findID, bool &selected, int Re);
void khungAdjustInfoEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *tmpE, bool &selected);
void danhSachAdjustEmp(struct listEmp &ListEmployees);
void chonTuDanhSach(struct listEmp &ListEmployees, int &stt, int &startPage, bool &selected);
// xoa
void removeEmp(struct listEmp &ListEmployees);
void danhSachRemoveEmp(struct listEmp &ListEmployees);
void deleteInfoEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *Info);

// cau D:
//in
void inDanhSachEmp(struct listEmp &ListEmployees);
void inTrangEmp(struct listEmp &list, char khungNoiDung[][30], int sizeKhungNoiDung[], struct NamesInfoEmp arr[], int start);
void inNhanVien(struct Employee *NV, int posX, int posY);

//cau E:
void VeKhungAddBill(NODER &tree, listEmp &ListEmployees, char khungNoiDung[][30], int H, int W);
void danhSachDetail(NODER &tree, listEmp &ListEmployees, bool NoX, Bills &tmpB, char keyName[]);
void chonTuDsDetail(NODER &tree, listEmp &ListEmployees, int &stt, bool &selected, bool NoX, Bills &tmpB, char keyName[]);
void inTrangDetailList(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Bills &tmpB, int start);
void khungThemMatVaoBill(NODER &tree, listEmp &ListEmployees, char khungNoiDung[][30], bool NoX, Bills &tmpB, char keyName[]);
void hienThiInfoDetail(NODER &tree,listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, char keyword[], bool NoX, Bills &tmpB, char keyName[]); //1:N   0:X
void khungDetailduocChon(NODER &tree, listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, Bills &tmpB, int &ViTri, bool NoX, char keyName[]);
void danhSachSelectMat(NODER &tree,listEmp &ListEmployees, Bills &tmpB, bool NoX, char keyName[]);  
void inVatTuBill(Details VT, int posX, int posY);

//cau F:
void inInfoBill(NODER &tree,listEmp &ListEmployees,Employee *tmpE, char findID[]);
void TrangDetailBill(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Bills &tmpB, int start);
void veKhungSearchBill(NODER &tree, listEmp &ListEmployees,char khungNoiDung[][30], Bills &tmpB);
//=========================


//	Main
int main(){
	KhoiTaoChuongTrinh();
	NODER tree = NULL;
	loadFile(tree, CountM);
	struct listEmp ListEmployees;
	loadEmp(ListEmployees);
	Menu(ListEmployees, tree);
	return 0;
}


void Save(NODER &tree,struct listEmp &ListEmployees){
	saveEmp(ListEmployees);
	saveMat(tree, CountM);
	loadFile(tree, CountM);
	loadEmp(ListEmployees);
}

void VeMenu(){
	// Ve nen menu chinh
	setbkcolor(MAU_NEN);
	cleardevice();
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar(0, 0, WD_WIDTH+1000, 25);
	
	// Ve cac muc menu chinh
	setcolor(BLACK);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	for (int i = 0; i < MAX_MENU; i++){
		outtextxy(ViTriMucMenu[i], 2, MenuChinh[i]);
		ViTriMucMenu[i+1] = ViTriMucMenu[i] + textwidth(MenuChinh[i]) + DIS_MENUX;
	}
	
	// Gach duoi menu chinh
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(0, 25, WD_WIDTH+1000, 25);
}

void NoiBatMuc(int sttMenuChinh, int sttMenuPhu, char menu[][30], int HL_COLOR, int C_SIZE){
	setbkcolor(HL_COLOR);
	setfillstyle(SOLID_FILL, HL_COLOR);
	setcolor(BLACK);
	settextstyle(COMPLEX_FONT, 0, C_SIZE);
	
	// Highlight muc menu chinh
	if (sttMenuPhu == 0){
		bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 0, ViTriMucMenu[sttMenuChinh+1]-DIS_MENUX/2, 25);
		outtextxy(ViTriMucMenu[sttMenuChinh], 2, menu[sttMenuChinh]);
	}
	//Higlight muc menu phu
	else{
		bar(ViTriMucMenu[sttMenuChinh] - DIS_MENUX/2, 
		25 + ViTriMucMenuPhu[sttMenuPhu-1], 
		ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2 + KichThuocMenuPhu[sttMenuChinh], 
		25 + ViTriMucMenuPhu[sttMenuPhu]);
		
		outtextxy(ViTriMucMenu[sttMenuChinh], 25+ViTriMucMenuPhu[sttMenuPhu-1]+DIS_MENUY/2, menu[sttMenuPhu-1]);
	}
	
}

void VeMenuPhu(int sttMenuChinh, char menu[][30]){
	int MAX;	//so luong muc trong menu phu
	switch(sttMenuChinh){
		case 0: {
			MAX = 4;
			break;
		}
		case 1: {
			MAX = 4;
			break;
		}
		case 2: {
			MAX = 2;
			break;
		}
		case 3: {
			MAX = 2;
			break;
		}
		case 4: {
			MAX = 2;
			break;
		}
		
	}
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	setusercharsize(1, 2, 1, 2);
	setcolor(BLACK);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	
	// in nen menu phu
	bar(ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2, 
	25, 
	ViTriMucMenu[sttMenuChinh]-DIS_MENUX/2+KichThuocMenuPhu[sttMenuChinh], 
	25+ViTriMucMenuPhu[MAX]);
	
	// in cac muc menu phu
	for (int i = 0; i < MAX; i++){
		outtextxy(ViTriMucMenu[sttMenuChinh], 25+ViTriMucMenuPhu[i]+DIS_MENUY/2, menu[i]);
	}
}

void MenuPhu(int viTriMenuPhu, char menu[][30], int MAXMENU, int &chonMuc){
	chonMuc = 1;
	NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, USER_CHAR_SIZE);
	while(1){
		if(kbhit()){
			VeMenuPhu(viTriMenuPhu, menu);
			char key = getch();
			if (key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_UP: {
						chonMuc--;
						break;
					}
					case KEY_DOWN: {
						chonMuc++;
						break;
					}
//					default:{
//							VeMenu();
//							chonMuc = -1;
//							return;
//						}
				}
				if (chonMuc > MAXMENU)
					chonMuc = 1;
				if (chonMuc < 1)
					chonMuc = MAXMENU;
			}
			else
				if (key == '\r'){
					return VeMenu();
				}
				else
					if (key == 27){
						chonMuc = -1;
						VeMenu();
						return;
					}
			NoiBatMuc(viTriMenuPhu, chonMuc, menu, HL_MENU_PHU, USER_CHAR_SIZE);
		}
	}
}

void Materials(NODER &tree, int size){
	VeMenuPhu(0, MenuMater);
	int thaoTac;
	MenuPhu(0, MenuMater, 4, thaoTac);
	switch (thaoTac){
		case 1:{
				Material newM;
				return VeKhungAddMat(tree, khungMat, 450, 600, 1, newM);
			}
		case 2:{
				return inID_ListMatToRoA(tree, choiceObject, 1);
			}
		case 3:{
				return inID_ListMatToRoA(tree, choiceObject, 0);
			}
		case 4:{
				return inDanhSachMat(tree,size);
			}
	}
}

void Employees(struct listEmp &ListEmployees){
	VeMenuPhu(1, MenuEmp);
	int thaoTac;
	MenuPhu(1, MenuEmp, 4, thaoTac);
	switch (thaoTac){
		case 1:{
				return addEmp(ListEmployees);;
			}
		case 2:{
				return removeEmp(ListEmployees);
			}
		case 3:{
				return chinhSuaEmp(ListEmployees);
			}
		case 4:{
				return inDanhSachEmp(ListEmployees);
			}
	}
}

void Bill(NODER &tree, struct listEmp &ListEmployees){
	VeMenuPhu(2, MenuBill);
	int thaoTac;
	MenuPhu(2, MenuBill, 2, thaoTac);
	Bills tmpB;
	switch(thaoTac) {
		case 1:{
				return VeKhungAddBill(tree,ListEmployees, khungBill, 450, 600);	
			}
		case 2:{
				return veKhungSearchBill(tree, ListEmployees,choiceBillList,tmpB);
			}	
	}
}

void Statistics(NODER &tree, struct listEmp &ListEmployees){
	VeMenuPhu(3, MenuStat);
	int thaoTac;
	MenuPhu(3, MenuStat, 2, thaoTac);
	switch (thaoTac){
		case 1:{
				thongKeBill(ListEmployees);
				break;
			}
		case 2:{
				topVatTu(tree, ListEmployees);
				break;
			}
	}
}

void Help(){
	VeMenuPhu(4, MenuHelp);
	int thaoTac;
	MenuPhu(4, MenuHelp, 2, thaoTac);
	switch (thaoTac){
		case 1:{
				Guide();
				break;
			}
		case 2:{
				About();
				break;
			}
	}
}

void ChonMenuPhu(int sttMenuChinh, struct listEmp &ListEmployees, NODER &tree){
	switch(sttMenuChinh){
		case 0:	return Materials(tree, CountM);
		case 1: return Employees(ListEmployees);
		case 2:	return Bill(tree, ListEmployees);
		case 3:	return Statistics(tree, ListEmployees);
		case 4:	return Help();
		default: return;
	}
}

void KhoiTaoChuongTrinh(){
	initwindow(WD_WIDTH, WD_HEIGHT);
	setwindowtitle("Materials-Management");
	VeMenu();
}

void Menu(struct listEmp &ListEmployees, NODER &tree){
	VeMenu();
	int kt = 1;
	int chiMuc = 0;
	NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
	while(kt){
		if(kbhit()){
			VeMenu();//unhightlight
			char key = getch();
			if (key == 0){
				char cNext = getch();
				switch(cNext){
					case KEY_LEFT: {
						chiMuc--;
						break;
					}
					case KEY_RIGHT: {
						chiMuc++;
						break;
					}
					case KEY_F9: {
						Save(tree, ListEmployees);
						notify(Success[3]);
						delay(1000);
						VeMenu();
						break;
					}
				}
				if (chiMuc == MAX_MENU)
					chiMuc = 0;
				if (chiMuc < 0)
					chiMuc = MAX_MENU - 1;
			}
			else 
				if (key == '\r'){
					if(chiMuc==5){
						kt=0;
					}
					else{
						VeMenu();
						ChonMenuPhu(chiMuc, ListEmployees, tree);
					}
				}
			NoiBatMuc(chiMuc, 0, MenuChinh, HIGHTLIGHT, USER_CHAR_SIZE);
		}
	}
}

void About(){
	int U = WD_HEIGHT/2 - 95;
	int D =	WD_HEIGHT/2 + 95;
	int L =	WD_WIDTH/2 - 200;
	int R =	WD_WIDTH/2 + 200;
	setfillstyle(SOLID_FILL, 8);//ve mau~ to^ voi mau` to^
	bar(L, U, R, D);
	setbkcolor(8);
	setcolor(0);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	outtextxy(480, 255, "Mon hoc: Cau Truc Du Lieu & Giai Thuat");
	outtextxy(480, 285, "Giang vien: Luu Nguyen Ky Thu");
	outtextxy(480, 315, "Materials-Management");
	outtextxy(480, 345, "Authors:");
	outtextxy(480, 375, "Pham Hong Nghia - N19DCCN121");
	outtextxy(480, 405, "Vo Kim Son - N19DCCN162");
}
void Guide(){
	int U = WD_HEIGHT/2 - 95;
	int D =	WD_HEIGHT/2 + 95;
	int L =	WD_WIDTH/2 - 200;
	int R =	WD_WIDTH/2 + 200;
	setfillstyle(SOLID_FILL, 8);//ve mau~ to^ voi mau` to^
	bar(L, U, R, D);
	setbkcolor(8);
	setcolor(0);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	outtextxy(490, 265, "Move			: Press Arrow keys.");
	outtextxy(490, 295, "Select			: Press Enter.");
	outtextxy(490, 325, "Save			: Press F9.");
	outtextxy(490, 355, "Exit			: Press ESC.");
	outtextxy(490, 385, "Scroll Page	: Press PageUp, PageDown.");
}

void veKhung(int x, int y, char noiDung[], bool daChon, int mauNen, int mauChu){
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int dis = 175;
	
	if (daChon)
		setfillstyle(SOLID_FILL, LIGHTGREEN);
	else
		setfillstyle(SOLID_FILL, BLACK);
	// highligh vien ngoai neu da chon
	bar (x+dis-1, y-2-1, x+dis+W+1, y+2+textheight(noiDung)+1);
	
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (x+dis, y-2, x+dis+W, y+2+textheight(noiDung));
}

void veMuc2Chon(int x, int y, char noiDung[], char noiDungMucChon[][30], bool chonTrai, int mauNen, int mauChu){
	setbkcolor(mauNen);	
	setcolor(BLACK);//setcolor(mauChu);
	outtextxy(x, y, noiDung);
	int H = textheight(noiDung);
	int W = 275;
	int rad = H/2-2;
	int dis1 = 180;
	int dis2 = 320;
	setcolor(mauChu);
	outtextxy(x+dis2+H, y, noiDungMucChon[1]);
	outtextxy(x+dis1+H, y, noiDungMucChon[0]);
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	
	if (chonTrai){
		setcolor(LIGHTGREEN);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(LIGHTGREEN);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}
	else{
		setcolor(LIGHTGREEN);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis1, y+H/2, rad);
		setfillstyle(SOLID_FILL, mauNen);
		setcolor(BLACK);
		circle(x+dis1, y+H/2, rad-2);
		floodfill(x+dis1, y+H/2, BLACK);
		
		setcolor(LIGHTGREEN);
		setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
		circle(x+dis2, y+H/2, rad);
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		setcolor(BLACK);
		circle(x+dis2, y+H/2, rad-2);
		floodfill(x+dis2, y+H/2, BLACK);
	}	
	setfillstyle(SOLID_FILL, TEXTBOX);
}


void VeMucChonNgay(int x, int y, char noiDungMucChon[], int ViTri, int mauNen, int mauChu){
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noiDungMucChon);
	int H = textheight(noiDungMucChon);
	int W = 55;
	int dis = 175;
	for(int i = 1; i <= 5; i++){
		setfillstyle(SOLID_FILL, BLACK);
		if(i % 2 != 0){	// ve cac khung nhap
			setcolor(BLACK);
			if(i == 1){
				if (ViTri == 1){
					setfillstyle(SOLID_FILL, LIGHTGREEN);
					setcolor(LIGHTGREEN);					
				}
				else
					setfillstyle(SOLID_FILL, BLACK);	
				//ve khung nhap ngay
				line((x+dis-1)-1, y-2-1, (x+dis-1)-1, y+textheight(noiDungMucChon)+2);
				bar ((x+dis-1), y-2-1, (x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon)+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1), y-2,(x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon)+1);
			}
			else{
				if(ViTri == 2){
					setfillstyle(SOLID_FILL, LIGHTGREEN);
					setcolor(LIGHTGREEN);
				}
				// ve khung nhap thang
				line((x+dis-1)+sizeKhungDate[1]-1, y-2-1, (x+dis-1)+sizeKhungDate[1]-1, y+textheight(noiDungMucChon)+2);
				bar ((x+dis-1)+sizeKhungDate[1], y-2-1, (x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon)+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1)+sizeKhungDate[1], y-2,(x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon)+1);
				line((x+dis+sizeKhungDate[2]), y-2-1, (x+dis+sizeKhungDate[2]), y+textheight(noiDungMucChon)+2);
				setfillstyle(SOLID_FILL, BLACK);
				setcolor(BLACK);
				if(ViTri == 3){
					setfillstyle(SOLID_FILL, LIGHTGREEN);
					setcolor(LIGHTGREEN);
				}
				// ve khung nhap nam
				line((x+dis-1)+sizeKhungDate[3]-1, y-2-1, (x+dis-1)+sizeKhungDate[3]-1, y+textheight(noiDungMucChon)+2);
				bar ((x+dis-1)+sizeKhungDate[3], y-2-1, (x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon)+2);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar ((x+dis-1)+sizeKhungDate[3], y-2,(x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon)+1);
				line((x+dis+sizeKhungDate[4]), y-2-1, (x+dis+sizeKhungDate[4]), y+textheight(noiDungMucChon)+2);
			}
		}
		else{	// ve dau ngan cach "/"
			setcolor(BLACK);
			outtextxy(x+dis+(sizeKhungDate[i-2] + sizeKhungDate[i-1]) /2 , y-2, type[2] );
		}
		line((x+dis+sizeKhungDate[i-1]), y-2-1, (x+dis+sizeKhungDate[i-1]), y+textheight(noiDungMucChon)+2);
	}
}

void veKhungNut(int H, int W, char khungNoiDung[][30], bool Left, bool reset, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[n]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[n]))/2 + textheight(khungNoiDung[n]);
	
	//ve khung duoi
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
		MAU_NUT_HL = NEN_KHUNG;
		
	setfillstyle(SOLID_FILL, MAU_NUT_HL);
	if (Left){
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
		setbkcolor(MAU_NUT_HL);
		setcolor(BLACK);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
	
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	else{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		setcolor(BLACK);
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[n]);
		
		setbkcolor(MAU_NUT_HL);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}	
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
}
void veMuc3Chon(int H, int W, char khungNoiDung[][30], int choose, bool reset, int &stt){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2 - 4;
	int R =	WD_WIDTH/2 + W/2 + 4;
	int midText1 = ((R-L)/3 - textwidth(khungNoiDung[0]))/2;
	int midText2 = ((R-L)/3 - textwidth(khungNoiDung[1]))/2;
	int midText3 = ((R-L)/3 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut + 10 - textheight(khungNoiDung[0]))/2 + textheight(khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D-kichThuocNut/4);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(L, D-kichThuocNut/4, R, D-kichThuocNut/4);							//top line
	line(L, D-kichThuocNut, L, D-kichThuocNut/4);							//left line
	line(R, D-kichThuocNut, R, D-kichThuocNut/4);							//right line
	line(L+(R-L)/3, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);			//line between add and confirm 
	line(L+2*(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);		// line between confirm and exit		
//	int choose = 1;
	int MAU_NUT_HL = HL_MENU_PHU;
	if (reset)
		MAU_NUT_HL = NEN_KHUNG;
	setfillstyle(SOLID_FILL, NEN_KHUNG);	
	if (choose == 1){
		bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
		bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
		
		setfillstyle(SOLID_FILL, MAU_NUT_HL);	
		bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
		setbkcolor(MAU_NUT_HL);
		
		setcolor(BLACK);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
	}
	else 
		if(choose == 2)	{
			bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
			bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
			
			setfillstyle(SOLID_FILL, MAU_NUT_HL);	
			bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
			setbkcolor(MAU_NUT_HL);
			
			setcolor(BLACK);
			outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
			
			setbkcolor(NEN_KHUNG);
			outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
			
			setbkcolor(NEN_KHUNG);
			outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
		}
		else
			if(choose == 3){
				bar (L, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);
				bar (L+(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);
				
				setfillstyle(SOLID_FILL, MAU_NUT_HL);	
				bar (L+2*(R-L)/3, D-kichThuocNut, R, D-kichThuocNut/4);
				setbkcolor(MAU_NUT_HL);
				
				setcolor(BLACK);
				outtextxy(L+2*(R-L)/3+midText3, D-midTextH, khungNoiDung[2]);
				
				setbkcolor(NEN_KHUNG);
				outtextxy(L+(R-L)/3+midText2, D-midTextH, khungNoiDung[1]);
				
				setbkcolor(NEN_KHUNG);
				outtextxy(L+midText1, D-midTextH, khungNoiDung[0]);
			}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(L, D-kichThuocNut/4, R, D-kichThuocNut/4);							//top line
	line(L, D-kichThuocNut, L, D-kichThuocNut/4);							//left line
	line(R, D-kichThuocNut, R, D-kichThuocNut/4);							//right line
	line(L+(R-L)/3, D-kichThuocNut, L+(R-L)/3, D-kichThuocNut/4);			//line between add and confirm 
	line(L+2*(R-L)/3, D-kichThuocNut, L+2*(R-L)/3, D-kichThuocNut/4);		// line between confirm and exit	
}
void veKhungYesNo(char khungNoiDung[][50], bool &choice, int n){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[n]))/2 + textheight(khungNoiDung[n]);
	setcolor(BLACK);
	outtextxy(L+25, ViTriKhung[3]-15, khungNoiDung[n]);
	outtextxy(L+25, ViTriKhung[4]-15, khungNoiDung[3]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
	if (choice){
		bar (L, D-kichThuocNut, WD_WIDTH/2, D);
	
		setbkcolor(HL_MENU_PHU);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	
		setbkcolor(NEN_KHUNG);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	else{
		bar (WD_WIDTH/2, D-kichThuocNut, R, D);
		
		setbkcolor(NEN_KHUNG);
		outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
		
		setbkcolor(HL_MENU_PHU);
		outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	}
	setcolor(BLACK);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
	
	while(1){
		if(kbhit()){
			char keyNoti = getch();
			char ckeyNoti;
			if(keyNoti==0){
				ckeyNoti = getch();
				if(ckeyNoti == KEY_LEFT || ckeyNoti == KEY_RIGHT){
					choice ^= 1;
					setcolor(BLACK);
					setfillstyle(SOLID_FILL, NEN_KHUNG);
					if (choice){
						bar (WD_WIDTH/2, D-kichThuocNut, R, D);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
						bar (L, D-kichThuocNut, WD_WIDTH/2, D);
						setbkcolor(HL_MENU_PHU);
						outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
						setbkcolor(NEN_KHUNG);
						outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
					}
					else{
						bar (L, D-kichThuocNut, WD_WIDTH/2, D);
						setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
						bar (WD_WIDTH/2, D-kichThuocNut, R, D);
						setbkcolor(NEN_KHUNG);
						outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
						setbkcolor(HL_MENU_PHU);
						outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
					}
					setcolor(BLACK);
					line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
					line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
				}
			}
			else
				if(keyNoti == '\r'){
					return;
				}
				else
					if(keyNoti == 27){
						choice = 0;
						return;
					}			
		}
	}
}

void notify(char khungNoiDung[]){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 100;
	int W = 250;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
	
	//in thong bao
	setcolor(BLACK);
	outtextxy(L+canLeGiua(khungNoiDung, W), U+(H-textheight(khungNoiDung))/2, khungNoiDung);
}

//=====================================Son===============================================//
void VeKhungAddMat(NODER &tree, char khungNoiDung[][30], int H, int W, int Mcase, Material &tmp){	// 1: choose addMat 0: choose adjust
	Material recovertmp;
	recovertmp = tmp;
	int cases = 1;
	if(Mcase == 0)
		cases = 7;
	NotiN:
	int pos = 1;	
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	setfillstyle(SOLID_FILL, mauNut);
	bar (L, D-kichThuocNut, R, D);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[cases]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[cases]))/2 + textheight(khungNoiDung[cases]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[cases]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	
	for (int i = 1; i <= SoLuongKhung; i++){
		if (i == 1){
			if(Mcase == 0){
				infoText(380, ViTriKhung[i], khungNoiDung[i+2], tmp.code, WHITE);
			}
			else
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);			
		}
		else{
			if(i == 4 && Mcase == 0){
				infoText(380, ViTriKhung[i], khungNoiDung[i+2], tmp.amount, WHITE);
			}
			else{
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
				if(Mcase == 0 && i == 2){
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);				
				}
			}
		}
	}
	if(Mcase == 1)
		InThongTin(560, ViTriKhung[1], tmp.code);
	InThongTin(560, ViTriKhung[2], tmp.name);
	InThongTin(560, ViTriKhung[3], tmp.type);
	if(Mcase==1)
		InThongTin(560, ViTriKhung[4], tmp.amount);
	//===== Chon vi tri ======//
	
	if(Mcase == 0)
		pos=2;
	
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						pos--;
						if(Mcase == 0 && pos == 1)
							pos=5;
						if(Mcase == 0 && pos == 4)
							pos=3;
						break;
						}
					case KEY_DOWN:{
						pos++;
						if(Mcase == 0 && pos == 4)
							pos=5;
						break;
					}
				}
				cpos:
				if (pos == 0)
					pos = 5;
				
				if (pos > 5){
					if(Mcase==0)
						pos = 2 ;
					else	
						pos = 1;
				}
				if(pos == 1 && Mcase == 0)
					pos = 5;
			}
			else
				if (key == '\r'){
					if(Mcase == 0){
						if(pos<=3)
							pos++;
						if(pos == 4)
							pos=5;
					}
					else
						if (pos <= 4)
							pos++;

				}
				else
					if (key == 27){
						if(Mcase == 0){
							tmp=recovertmp;
							VeMenu();
							return inID_ListMatToRoA(tree, choiceObject, 0);
						}
						VeMenu();
						return;
					}
			for (int i = 1; i <= SoLuongKhung; i++){
				if(i == 1 && Mcase == 0){
					infoText(380, ViTriKhung[i], khungNoiDung[i+2], tmp.code, WHITE);
				}
				else
					if(i == 4 && Mcase == 0){
						infoText(380, ViTriKhung[i], khungNoiDung[i+2], tmp.amount, WHITE);	
					}
					else
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
			}
			setbkcolor(NEN_TEXT);
			if(Mcase == 1)
				InThongTin(560, ViTriKhung[1], tmp.code);
			InThongTin(560, ViTriKhung[2], tmp.name);
			InThongTin(560, ViTriKhung[3], tmp.type);
			if(Mcase == 1)
				InThongTin(560, ViTriKhung[4], tmp.amount);
			veKhungNut(H, W, khungNoiDung, 1, 1, cases);
			//===di chuyen trong menu===//
			switch(pos){
				case 1:{
					if(Mcase == 0)
						break;
					veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
					Nhap(560,200,-1, key, tmp.code,10);
					break;
				}
				case 2:{
					veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, BLACK);
					Nhap(560,260,2, key, tmp.name, 25);
					break;
				}
				case 3:{
					veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, BLACK);
					Nhap(560,320,1, key, tmp.type, 10);
					break;
				}
				case 4:{
					if(Mcase == 0)
						break;
					veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, BLACK);
					Nhap(560,380,0, key, tmp.amount,8);						
					break;									
				}
				case 5:{
					bool buttonL = 1;
					veKhungNut(H, W, khungNoiDung, buttonL, 0, cases);						
					while(1){
						if(kbhit()){
							char key5 = getch();
							char c5Next;
							if (key5 == 0){
								c5Next = getch();
								switch(c5Next){
									case KEY_UP:{
										pos--;
										if(Mcase == 0 && pos == 4){
											pos=3;
										}
										veKhungNut(H, W, khungNoiDung, buttonL, 1, cases);
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										veKhungNut(H, W, khungNoiDung, buttonL, 1, cases);
										goto cpos;
									}
									case KEY_LEFT:{
										buttonL ^= 1;
										break;
									}
									case KEY_RIGHT:{
										buttonL ^= 1;
										break;
									}
								}
							}
							else															
								if (key5 == '\r'){
									//return;
									if (buttonL == 1){
										//===thong bao loi===//
										if(strlen(tmp.code) != 0 && strlen(tmp.name) != 0
										&& strlen(tmp.type) != 0 && strlen(tmp.amount) != 0){
											if(Mcase==1){
												NODER p=Search(tree, tmp.code);
												if(p==NULL){
													NotiY:
														++CountM;
														tree=Insert(tree, tmp.code, tmp);
														ThongBao(750, 90, Success[0], LIGHTGREEN, BLACK);
														Material newM;
														return VeKhungAddMat(tree, khungMat, 450, 600, 1, newM);
												}
						 						else{
													bool x = 1;
													veKhungYesNo(sameMat, x, 0);
													if(x){
														--CountM;
														tree=deleteNode(tree, tmp.code);
														goto NotiY;
													}
													else
														goto NotiN;
												}
											}
											else{
												char notyet[]="Info Has Not Been Adjusted!";
												if(strcmp(recovertmp.name, tmp.name) == 0 && strcmp(recovertmp.type, tmp.type) == 0){
													ThongBao(690, 150, notyet, LIGHTRED, BLACK);
													goto NotiN;
												}
												else{
													ThongBao(750, 90, Success[2], LIGHTGREEN, BLACK);
													VeMenu();
													return inID_ListMatToRoA(tree, choiceObject, 0);
												}
											}
										}
										else{
											ThongBao(830, 90, Fail[0], LIGHTRED, BLACK);//MAU_MENU
											goto NotiN;
										}
									}
									else{
										if(Mcase==0){
											//khoi phuc
											tmp=recovertmp;
											VeMenu();
											return inID_ListMatToRoA(tree, choiceObject, 0);
										}
										else{
											VeMenu();
											return;
										}									
									}
								}//	else if key5 == r
							if (key5 == 27){ // exit trong case 5, 2muc chon
								if(Mcase==0){
									//khoi phuc	neu khong adjust
									tmp=recovertmp;
									VeMenu();
									return inID_ListMatToRoA(tree, choiceObject, 0);
								}
								else{										
									VeMenu();
									return;																				
								}									
							}
							veKhungNut(H, W, khungNoiDung, buttonL, 0, cases);						
						}
					}
				}
			}
		}		
	}
}

void infoText(int x, int y, char noiDung[],char info[],int MauChu){
	setbkcolor(NEN_KHUNG);
	setcolor(BLACK);
	outtextxy(x, y, noiDung);
	int dis = 175;
	setcolor(MauChu);
	outtextxy(x+dis-1, y, info);
}

void hienThiInfoMat(NODER &tree, char khungNoiDung[][30], int H, int W, char keyword[]){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
		
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	setfillstyle(SOLID_FILL, mauNut);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	
	//info
	NODER tmp;
	tmp = Search(tree,keyword);
	infoText(380, ViTriKhung[1], khungNoiDung[1+2],tmp->info.code,WHITE);
	infoText(380, ViTriKhung[2], khungNoiDung[2+2],tmp->info.name,WHITE);
	infoText(380, ViTriKhung[3], khungNoiDung[3+2],tmp->info.type,WHITE);
	infoText(380, ViTriKhung[4], khungNoiDung[4+2],tmp->info.amount,WHITE);
	
	bool button = 1;
	veKhungNut(H, W, khungNoiDung, button, 0,1);
	while(1){
		if(kbhit()){
			char key = getch();
			char ckey; 
			if(key == 0){
				ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						button ^= 1;
						break;
					}
					case KEY_RIGHT:{
						button ^= 1;
						break;
					}
				}
			}
			if(key == '\r'){
				if(button == 1){
				 	ThongBao(750, 90, Success[1], LIGHTGREEN, BLACK);
				 	--CountM;
				 	tree = deleteNode(tree,tmp->key);
				 	VeMenu();
				 	return inID_ListMatToRoA(tree, choiceObject, 1);
				}
				else{
					VeMenu();
					return inID_ListMatToRoA(tree, choiceObject,1);
				}
			}
			if(key==27){
			 	VeMenu();
				return inID_ListMatToRoA(tree, choiceObject, 1);
			}
			veKhungNut(H, W, khungNoiDung, button, 0,1);
		}
	}	
}

void inID_ListMatToRoA(NODER &tree, char khungNoiDung[][30], bool RoA){	// RoA = 1  remove, RoA = 0 adjust
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);							//top line
	
	int n;
	if(RoA == 1)
		n=0;
	else
		n=1;
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(570, 240, title[n]);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	// ve khung chon id
	rectangle(L+14, ViTriKhung[3]-11,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));

	// ve khung chon materials list 
	rectangle(WD_WIDTH/2-1, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	// 2 nut check and exit
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	char findID[11];
	findID[0] = '\0';
	while(1){
		InThongTin(L+30+2*textwidth(khungNoiDung[0]), ViTriKhung[3], findID);
		if(kbhit()){
			char keyR = getch();
				char ckeyR;
				if(keyR==0){
					ckeyR = getch();
					switch(ckeyR){
						case KEY_LEFT:{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_RIGHT:{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_UP:{
							if(posR == 0 || posR == 1){
								posR = 2;
								break;
							}
							else
								if(posR == 2 || posR == 3){
								 	posR =0;
								 	choiceN = 1;
								 	break;
								 }		
						}
						case KEY_DOWN:{
							if(posR == 0 || posR == 1){
								posR = 2;
								break;
							}
							else
								if(posR == 2 || posR == 3){
								 	posR =0;
								 	choiceN = 1;
								 	break;
								}	
						}	
					}
				}
				if(keyR == '\r'){
					if(posR == 0 || posR == 1){
						posR = 2;
					}
					else{
						if(choiceN){
							if(choice == 1){
								if(strlen(findID) != 0){
									if(Search(tree,findID)==NULL){
										//loi ko ton tai
										ThongBao(760, 210, Fail[1], LIGHTRED, BLACK);
									}
									else{	
										if(RoA == 1)
											return hienThiInfoMat(tree, checkMat, 450, 600, findID); // den khung check info 1 Mats
										
										else{
											NODER findM = Search(tree, findID);
											VeMenu();	
											return VeKhungAddMat(tree, khungMat, 450, 600, 0, findM->info);
										}
									}
								}
								else{
									ThongBao(760, 210, Fail[0], LIGHTRED, BLACK);
									posR = 0;
								}
							}
							else{
								return danhSachRoAMat(tree, CountM, RoA); //den khung danh sach
							}	
						}
						else{
							VeMenu();
							return;
						}
					}
				}
				if(keyR == 27){
					VeMenu();
					return;
				}
		// hien thi
		if(posR==0 || posR == 1){
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice){
				// ID
				setbkcolor(NEN_KHUNG);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
			}
			else{
				// material list
				setbkcolor(NEN_KHUNG);
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
			}
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			bar (L, D-kichThuocNut, WD_WIDTH/2, D);
			bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
			setbkcolor(NEN_KHUNG);
			line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
			line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			setcolor(BLACK);
			outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
			outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
		}
		else
			if(posR==2 || posR==3){
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN){	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			 }		
		}
	} // while
}

void danhSachRoAMat(NODER &tree, int &CountM, int RoA){	 //1: Remove 0: Adjust
	
	if(CountM == 0){
		ThongBao(760, 210, Fail[2], LIGHTRED, BLACK);
		VeMenu();
		return inID_ListMatToRoA(tree, choiceObject, RoA);
	}
	else{
		if(RoA == 1){
			char xoa[][80]={"Enter To Delete"};
			setcolor(CYAN);
			outtextxy(350, 635, xoa[0]);
		}
		//tao mang 1 chieu
		NameMats *arrM = new NameMats[CountM];
		Count = 0;
		taoMangMat(tree, arrM);
		Qsort(arrM,0,CountM-1);
		int removePos = 0;
		int page = 1;
		bool select;
		while(1){
			chonTuDanhSachMat(tree, arrM, CountM, removePos, page, select);
			if(select){
				if(RoA == 1){
					tree = deleteNode(tree, arrM[removePos].code);
					for (int i = removePos; i < CountM; arrM[i] = arrM[++i]);
					--CountM;				
				}
				else if(RoA == 0){
					NODER findM = Search(tree, arrM[removePos].code);
					return VeKhungAddMat(tree, khungMat, 450, 600, 0, findM->info);
				}
			}
			else{
				VeMenu();
				return inID_ListMatToRoA(tree, choiceObject, RoA);
			}
		}
		VeMenu();
	}
}

void chonTuDanhSachMat(NODER &tree, NameMats *arrM, int size, int &stt, int &startPage, bool &selected){	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(size*1.0/OBJ_PER_PAGE);
	if (limitPage == 0 || size == 0){
		VeMenu();
		notify(Fail[2]);
	}
	else{
		// tinh thong so
		int kichThuocSTT = 30;
		int h = textheight(danhSachMat[0]) + 5*2;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		int W = 0;
		for (int i = 0; i < 5; i++){
			W += textwidth(danhSachMat[i]) + sizeDanhSachMat[i]*2;
		}
		int U = WD_HEIGHT/2 - H/2;
		int L =	WD_WIDTH/2 - W/2;
		
		int x = L, y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
		int yOld = y;
				
		inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE, size);
		showPage(830, 635, startPage, limitPage);
		
		setcolor(LIGHTGREEN);
		rectangle(x, y, x+W, y+h);
		while(1){
			if(kbhit()){
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGUP:{
							startPage--;
							if (startPage < 1)
								startPage = limitPage;
							inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE, size);
							showPage(830, 635, startPage, limitPage);
							stt = (startPage-1)*OBJ_PER_PAGE;
							break;
						}
						case KEY_PGDN:{
							startPage++;
							if (startPage > limitPage)
								startPage = 1;
							inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE, size);
							showPage(830, 635, startPage, limitPage);
							stt = (startPage-1)*OBJ_PER_PAGE;
							break;
						}
						case KEY_UP:{
							stt--;
							break;
						}
						case KEY_DOWN:{
							stt++;
							break;
						}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), size-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > size-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U+kichThuocSTT+(stt%OBJ_PER_PAGE)*h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(LIGHTGREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else
					if (key == 27) {
						VeMenu();
						return;
					}
					else
						if (key == '\r'){
							selected = true;
							return;
						}
			}
		}
	}
}

//==Material List==
void inTrangMat(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], NameMats *arr, int start, int sizeM){
	NameMats *arrM = new NameMats[CountM];
	Count = 0;
	taoMangMat(tree, arrM);
	Qsort(arrM,0,CountM - 1);
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = sizeM;
	NODER p; 

	for (int i = start; i < min(start + OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i + 1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		p = Search(tree, arr[i].code);		
		if(p != NULL){
			inVatTu(p->info, disW, dis);
		}
		//outtextxy(disW, dis, arr[i].name);
		dis += h+5;
	}
}

void inVatTu(Material VT, int posX, int posY){
	// in ID
	outtextxy(posX + canLeGiua(VT.code, textwidth(danhSachMat[1])+sizeDanhSachMat[1]*2), posY, VT.code);
	posX += textwidth(danhSachMat[1]) + sizeDanhSachMat[1]*2;
	
	// in Name
	outtextxy(posX + 10, posY, VT.name);
	posX += textwidth(danhSachMat[2]) + sizeDanhSachMat[2]*2;
	
	// in type
	outtextxy(posX + canLeGiua(VT.type , textwidth(danhSachMat[3])+sizeDanhSachMat[3]*2), posY, VT.type);
	posX += textwidth(danhSachMat[3]) + sizeDanhSachMat[3]*2;
	
	// in Amount
	outtextxy(posX + canLeGiua(VT.amount , textwidth(danhSachMat[4])+sizeDanhSachMat[4]*2), posY, VT.amount);		
	posX += textwidth(danhSachMat[4]) + sizeDanhSachMat[4]*2;
}

void taoMangMat(NODER &tree, NameMats *arrM){
	if(tree != NULL){
		taoMangMat(tree->left,arrM);
		get_chuoi(arrM[Count].name, tree->info.name);
//		strcpy(arrM[Count].name, tree->info.name);
		strcpy(arrM[Count++].code, tree->info.code);
		taoMangMat(tree->right,arrM);
	}
	else
		return;
}

void inDanhSachMat(NODER &tree, int size){
	NameMats *arrM = new NameMats[size];
	Count = 0;
	taoMangMat(tree,arrM);
	Qsort(arrM,0,size-1);
	//in danh sach
	// chuyen trang 
	int startPage = 1;
	int limitPage = ceil(size*1.0/OBJ_PER_PAGE);
	if (limitPage == 0){
		VeMenu();
		notify(Fail[2]);
	}
	else{
		inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, 0, size);
		showPage(830, 635, startPage, limitPage);
		while(1){
			if(kbhit()){
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGUP:{
							startPage--;
							if (startPage < 1)
								startPage = limitPage;
							inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE,size);	
							showPage(830, 635, startPage, limitPage);
							break;	
						}	
						case KEY_PGDN:{
							startPage++;
							if (startPage > limitPage)
								startPage = 1;
							inTrangMat(tree, danhSachMat, sizeDanhSachMat, arrM, (startPage-1)*OBJ_PER_PAGE,size);
							showPage(830, 635, startPage, limitPage);
							break;
						}
					}
				}
				else
					if(key == 27){
						VeMenu();
						return;
					}
			}
		}
	}
	delete arrM;
}
//end material

//==BILL==
void VeKhungAddBill(NODER &tree, listEmp &ListEmployees, char khungNoiDung[][30], int H, int W){
	Bills tmpB;
	//tmpB.details;
	int index = 0;
	char keyName[11];//ma nv
	keyName[0] = '\0';
	struct FDate{
		char days[3];
		char months[3];
		char years[5];
		FDate(){
			days[0]='\0';
			months[0]='\0';
			years[0]='\0';
		}
	};
	FDate *date = new FDate;
	int soLuongKhung = 4;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
		
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 1)
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
			else{
				if(i==2) // date
					VeMucChonNgay(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
				else
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
			}
		}
		else
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], type, 1, NEN_KHUNG, BLACK);
	}
	int pos = 1;
	int fst = 1;
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						pos--;
						break;
					}
					case KEY_DOWN:{
						pos++;
						break;
					}
				}
				cpos:
				if (pos == 0)
					pos = 5;
				if (pos > 5)
					pos = 1;
			}
			else
				if (key == '\r'){
					if (pos <= 4)
						pos++;
				}
				else
					if (key == 27){
						VeMenu();
						return;
					}
									
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 4; i++){
				if (i != 4){
					if (i == 1)
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
					if(i == 2)
						VeMucChonNgay(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
					else
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);					
				}
				else
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], type, fst, NEN_KHUNG, BLACK);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], tmpB.Num);
			InThongTin(560+40-textwidth(date->days), ViTriKhung[2], date->days);	
			InThongTin(560+150-textwidth(date->months), ViTriKhung[2], date->months);	
			InThongTin(560+260-textwidth(date->years), ViTriKhung[2], date->years);	
			InThongTin(560, ViTriKhung[3], keyName);
			switch(pos){
				case 1:{
					veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
					Nhap(560, 200, -1, key, tmpB.Num, 20);
					break;
				}
				case 2:{
					int ViTri = 1 ;
					cViTri:
					VeMucChonNgay(380, ViTriKhung[2], khungNoiDung[4], ViTri, NEN_KHUNG, BLACK);
					InThongTin(560+40-textwidth(date->days), ViTriKhung[2], date->days);	
					InThongTin(560+150-textwidth(date->months), ViTriKhung[2], date->months);	
					InThongTin(560+260-textwidth(date->years), ViTriKhung[2], date->years);	
					while(1){
						if (kbhit()){
							char key2 = getch();
							if (key2 == 0){
								char c2Next = getch();
								switch(c2Next){
									case KEY_LEFT:{
										ViTri--;
										break;
									}
									case KEY_RIGHT:{
										ViTri++;
										break;
									}
									case KEY_UP:{
										pos--;
										goto cpos;
										break;
									}
									case KEY_DOWN:{
										pos++;
										goto cpos;
										break;
									}
								}
							}
							else
								if (key2 == '\r'){
									if(ViTri==3){
										pos++;
										goto cpos;
									}
									ViTri++;
									goto cViTri;
								}
								else
									if (key2 == 27){
										VeMenu();
										return;
									}
							if (ViTri == 0)
								ViTri = 3;
							if (ViTri > 3)
								ViTri = 1;	
							if(ViTri==1){
								Nhap(560+40-textwidth(date->days), ViTriKhung[2], 0, key2, date->days,2);
							}
							else
								if(ViTri==2){
									Nhap(560+150-textwidth(date->months), ViTriKhung[2], 0, key2, date->months,2);									
								}							
								else
									if(ViTri==3){
										Nhap(560+260-textwidth(date->years), ViTriKhung[2], 0, key2, date->years,4);
									}							
							VeMucChonNgay(380, ViTriKhung[2], khungNoiDung[4], ViTri, NEN_KHUNG, BLACK);
							InThongTin(560+40-textwidth(date->days), ViTriKhung[2], date->days);	
							InThongTin(560+150-textwidth(date->months), ViTriKhung[2], date->months);	
							InThongTin(560+260-textwidth(date->years), ViTriKhung[2], date->years);
						}
					}
				break;
				}
				case 3:{
					veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, BLACK);
					Nhap(560, 320, -1, key, keyName, 10);
					break;
				}
				case 4:{
					veMuc2Chon(380, 380, khungNoiDung[6], type, fst, NEN_KHUNG, LIGHTGREEN);
					while(1){
						if (kbhit()){
							char key4 = getch();
							if (key4 == 0){
								char c4Next = getch();
								switch(c4Next){
									case KEY_LEFT:{
										fst++;
										break;
									}
									case KEY_RIGHT:{
										fst--;
										break;
									}
									case KEY_UP:{
										pos--;
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										goto cpos;
									}
								}
							}
							else
								if (key4 == '\r'){
									pos++;
									goto cpos;
									break;
								}
								else
									if (key4 == 27){
										VeMenu();
										return;
									}
							if (fst == -1)
								fst = 1;
							if (fst > 1)
								fst = 0;								
							veMuc2Chon(380, 380, khungNoiDung[6], type, fst, NEN_KHUNG, LIGHTGREEN);
						}
					}
				}	
				case 5:{
					bool buttonL = 1;
					veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
					while(1){
						if(kbhit()){
							char key5 = getch();
							char c5Next;
							if (key5 == 0){
								c5Next = getch();
								switch(c5Next){
									case KEY_UP:{
										pos--;
										veKhungNut(H, W, khungNoiDung, buttonL, 1, 1);
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										veKhungNut(H, W, khungNoiDung, buttonL, 1, 1);
										goto cpos;
									}
									case KEY_LEFT:{
										buttonL ^= 1;
										break;
									}
									case KEY_RIGHT:{
										buttonL ^= 1;
										break;
									}
								}
							}
							else
								if (key5 == '\r'){
									//return;
									if (buttonL == 1){
										// den material list
										if(strlen(tmpB.Num) != 0 && strlen(keyName) != 0 && strlen(date->days) != 0
										&& strlen(date->months) != 0 && strlen(date->years) != 0){
											
											if(ListEmployees.Search_ID(keyName) != NULL){
												
												if(ListEmployees.checkIDBill(tmpB.Num)){
													tmpB.type = fst == 1 ? 'N' : 'X';
													tmpB.date.day = ChangeCharToNum(date->days);
													tmpB.date.month = ChangeCharToNum(date->months);
													tmpB.date.year = ChangeCharToNum(date->years);
													VeMenu();
													danhSachDetail(tree, ListEmployees, fst, tmpB, keyName);
													return;
												}
												else{
													ThongBao(730, 90, Fail[4], LIGHTRED, BLACK);
													pos = 1;
													veKhungNut(H, W, khungNoiDung, buttonL, 1, 1);
													goto cpos;
												}												
											}
											else{
												ThongBao(740, 90, Fail[5], LIGHTRED, BLACK);
												veKhungNut(H, W, khungNoiDung, buttonL, 1, 1);
												pos = 1;
												goto cpos;
											}
										}
										else{
											ThongBao(760, 90, Fail[0], LIGHTRED, BLACK);
											veKhungNut(H, W, khungNoiDung, buttonL, 1, 1);
											pos = 1;
											goto cpos;
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else
									if (key5 == 27){
										VeMenu();
										return;
									}
							veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
						}
					}
				}
			}
			// kiem tra date
			if(strlen(date->days) != 0 && strlen(date->months) != 0 && strlen(date->years) != 0){
				tmpB.date.day = ChangeCharToNum(date->days);
				tmpB.date.month = ChangeCharToNum(date->months);
				tmpB.date.year = ChangeCharToNum(date->years);
				if(!tmpB.date.isValid()){
					ThongBao(800, 90, Fail[3], LIGHTRED, BLACK);
					pos = 2;
					goto cpos;
				}
			}
		}
	} // while 
}
	
void khungThemMatVaoBill(NODER &tree,listEmp &ListEmployees, char khungNoiDung[][30],bool NoX, Bills &tmpB, char keyName[]){	// NoX = 1  nhap, NoX = 0 xuat
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(560, 240, title[4]);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	// ve khung chon id
	rectangle(L+14, ViTriKhung[3]-11,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setcolor(BLACK);
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));

	// ve khung chon materials list 
	rectangle(WD_WIDTH/2-1, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setcolor(BLACK);
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	// 2 nut check and exit
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	//make ur choice
	
	char findID[11];
	findID[0] = '\0';
	while(1){
		InThongTin(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],findID);
		if(kbhit()){
			char keyR = getch();
				char ckeyR;
				if(keyR==0){
					ckeyR = getch();
					switch(ckeyR){
						case KEY_LEFT:{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_RIGHT:{
							if(posR==1 || posR==0)
								choice ^= 1; // 1: trai 0: phai
							if(posR==2 || posR==3)
								choiceN ^= 1;	
							break;
						}
						case KEY_UP:{
							if(posR == 0 || posR == 1){
								posR = 2;
								break;
							}
							else
								if(posR == 2 || posR == 3){
								 	posR =0;
								 	choiceN = 1;
								 	break;
								}		
						}
						case KEY_DOWN:{
							if(posR == 0 || posR == 1){
								posR = 2;
								break;
							}
							else
								if(posR == 2 || posR == 3){
								 	posR =0;
								 	choiceN = 1;
								 	break;
								}	
						}	
					}
				}
				if(keyR == '\r'){
					if(posR == 0 || posR == 1){
						posR = 2;
					}
					else{
						if(choiceN){
							if(choice == 1){
								if(strlen(findID) != 0){
									if(Search(tree, findID) == NULL){
										//loi ko ton tai
										ThongBao(740, 210, Fail[1], LIGHTRED, BLACK);
									}
									else{
										if(!tmpB.details->isFull()){
											NODER tmp = Search(tree,findID);
											// den khung add detail
											return hienThiInfoDetail(tree,ListEmployees, khungDetailBill, 450, 600, findID, NoX, tmpB, keyName);
										}
										else{
											ThongBao(720, 210, Fail[8], LIGHTRED, BLACK);
											VeMenu();
											return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
										}	
									}
								}
								else{
									ThongBao(720, 210, Fail[0], LIGHTRED, BLACK);
									posR = 0;
								}
							}
							else{
								if(!tmpB.details->isFull()){
									return danhSachSelectMat(tree,ListEmployees, tmpB, NoX, keyName); //den khung danh sach
								}
								else{
									ThongBao(720, 210, Fail[8], LIGHTRED, BLACK);
									VeMenu();
									return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
								}
							}	
						}
						else{
							VeMenu();
							return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
						}
					}
				}
				if(keyR == 27){
					VeMenu();
					return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
				}
		// hien thi
		if(posR==0 || posR == 1){
			setcolor(WHITE);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice){
				// ID
				setbkcolor(NEN_KHUNG);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR,findID,10);
			}
			else{
				// material list
				setbkcolor(NEN_KHUNG);
				bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);
				bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[1]);
			}
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			bar (L, D-kichThuocNut, WD_WIDTH/2, D);
			bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
			setbkcolor(NEN_KHUNG);
			line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
			line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			setcolor(BLACK);
			outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
			outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
		}
		else
			if(posR==2 || posR==3){
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN){	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	} // while
}

void hienThiInfoDetail(NODER &tree,listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, char keyword[], bool NoX, Bills &tmpB, char keyName[]){
	//1 N  0 X
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	setfillstyle(SOLID_FILL, mauNut);
	bar (L, D-kichThuocNut, R, D);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//==info==
	NODER MatInf;
	MatInf = Search(tree,keyword);
	Details tmp;
	strcpy(tmp.ID, keyword);
	struct InfoDetail{
		char tmpPrice[11];
		char tmpVAT[3];
		char tmpAmount[9];
		InfoDetail(){
			tmpPrice[0] = '\0';
			tmpVAT[0] = '\0';
			tmpAmount[0] = '\0';
		}
	};
	InfoDetail tempM;
	//===
	infoText(380, ViTriKhung[1], khungNoiDung[1+2], tmp.ID, WHITE);
	InThongTin(560,ViTriKhung[2],tempM.tmpPrice);
	InThongTin(560,ViTriKhung[3],tempM.tmpVAT);
	InThongTin(560,ViTriKhung[4],tempM.tmpAmount);
	// ve khung amount
	bool button = 1;
	int pos = 0;
	for(int i = 2;i<=4;i++){
		if(i==2){
			veKhung(380,ViTriKhung[i],khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
		}
		else{
			veKhung(380,ViTriKhung[i],khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
		}
	}
	veKhungNut(H, W, khungNoiDung, button, 1, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			char ckey; 
			if(key == 0){
				ckey = getch();
				switch(ckey){
					case KEY_UP:{
						pos--;
						break;	
					}
					case KEY_DOWN:{
						pos++;
						break;
					}	
					case KEY_LEFT:{
						if(pos==3)
							button ^= 1;
						break;
					}
					case KEY_RIGHT:{
						if(pos==3)
							button ^= 1;
						break;
					}
				}
			}
			cpos:
			if(pos == -1){
				button = 1;
				pos = 3;
			}
			else
				if(pos > 3)
					pos = 0;
			if(key == '\r'){
			 	if(pos<=2){
			 		pos++;
				}
				else
					if(pos == 3){
					 	if(button == 1){
					 		if(strlen(tempM.tmpAmount) != 0 && strlen(tempM.tmpVAT) != 0  && strlen(tempM.tmpPrice) != 0 ){
					 			
					 			if(ChangeCharToNum(tempM.tmpPrice) == 0 || ChangeCharToNum(tempM.tmpAmount) == 0){
					 				ThongBao(690, 90, Fail[9], LIGHTRED, BLACK);
					 				pos = 1;
					 				goto cpos;
								}
					 			if( NoX == 0 ){
									if(ChangeCharToNum(tempM.tmpAmount) > ChangeCharToNum(MatInf->info.amount)){
						 				ThongBao(715, 90, Fail[6], LIGHTRED, BLACK);
										infoText(380, 450, lackAmount[0], MatInf->info.amount, WHITE);
										pos = 1;
										goto cpos;						
									}
								}
				 				ThongBao(720, 90, Success[0], LIGHTGREEN, BLACK);
								tmp.VAT = ChangeCharToNum(tempM.tmpVAT);
								tmp.amount = ChangeCharToNum(tempM.tmpAmount);
								tmp.price = ChangeCharToNum(tempM.tmpPrice);
								tmpB.details->Insert(tmp);
								VeMenu();
								return khungThemMatVaoBill(tree, ListEmployees, choiceObject,NoX, tmpB, keyName);
							}
							else{
								ThongBao(790, 90, Fail[0], LIGHTRED, BLACK);
							}
						}
						else{
							VeMenu();
							return khungThemMatVaoBill(tree,ListEmployees, choiceObject, 1, tmpB, keyName);
						}
					}
				//end else
			}
			if(key == 27){
			 	VeMenu();
				return khungThemMatVaoBill(tree,ListEmployees, choiceObject, 1, tmpB, keyName);
			}
			for(int i = 2;i<=4;i++){	
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
			}
			veKhungNut(H, W, khungNoiDung, button, 1, 1);
			switch(pos){
				case 0:{	
					veKhung(380,ViTriKhung[2],khungNoiDung[4],1,NEN_KHUNG, BLACK);
					Nhap(560,ViTriKhung[2],0,key,tempM.tmpPrice, 10);
					break;
				}
				case 1:{
					veKhung(380,ViTriKhung[3],khungNoiDung[5],1,NEN_KHUNG,BLACK);
					Nhap(560,ViTriKhung[3],0,key,tempM.tmpVAT,2);
					break;						
				}
				case 2:	{
					veKhung(380,ViTriKhung[4],khungNoiDung[6],1,NEN_KHUNG,BLACK);
					Nhap(560,ViTriKhung[4],0,key,tempM.tmpAmount,8);
					break;												
				}
				case 3:{
					veKhungNut(H, W, khungNoiDung, button, 0,1);
					break;				
				}		
			}
			InThongTin(560,ViTriKhung[2],tempM.tmpPrice);
			InThongTin(560,ViTriKhung[3],tempM.tmpVAT);
			InThongTin(560,ViTriKhung[4],tempM.tmpAmount);
		}
	}// end while
}
	
void danhSachSelectMat(NODER &tree,listEmp &ListEmployees,Bills &tmpB, bool NoX, char keyName[]){
	//tao mang 1 chieu
	NameMats *arrM = new NameMats[CountM];
	int size = CountM;
	Count = 0;
	taoMangMat(tree, arrM);
	Qsort(arrM, 0, size - 1);
	int removePos = 0;
	int startpage = 1;
	bool select = 0;
	while(1){
		loop:
		chonTuDanhSachMat(tree, arrM, size, removePos, startpage, select);
		if(select == 1 && !tmpB.details->isFull()){
			//them vao listBill
			NODER p;
			p = Search(tree, arrM[removePos].code);
			for(int i = 0 ; i < tmpB.details->n ; i++){
				if(tmpB.details->cmp_ID(p->info.code)){
					ThongBao(1000, 40, Fail[4], LIGHTRED, BLACK);
					goto loop;
				}
			}
			VeMenu();
			return hienThiInfoDetail(tree,ListEmployees, khungDetailBill, 450, 600, p->info.code, NoX, tmpB, keyName);	
		}
		else{
			VeMenu();
			return khungThemMatVaoBill(tree,ListEmployees, choiceObject, NoX, tmpB, keyName);
		}
	}
}


void danhSachDetail(NODER &tree, listEmp &ListEmployees, bool NoX, Bills &tmpB, char keyName[]){	// 1: N     0: X
	int removePos = 0;
	bool select = 0;
	while(1){
		chonTuDsDetail(tree, ListEmployees, removePos, select, NoX, tmpB, keyName);
		if(select){
			if(!tmpB.details->isEmpty())
				return khungDetailduocChon(tree, ListEmployees, khungDetailBill, 450, 600, tmpB, removePos, NoX, keyName);			
		}
		else
			break;
		
	}
	VeMenu();
}

void chonTuDsDetail(NODER &tree, listEmp &ListEmployees, int &stt, bool &selected, bool NoX, Bills &tmpB, char keyName[]){	
	//in danh sach
	//int startPage = 1;
	N:
	selected = false; 
	// tinh thong so
	int kichThuocSTT = 30;
	int h = textheight(danhSachMat[0]) + 5*2;
	int H = (h)*20 + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++){
		W += textwidth(danhSachMat[i]) + sizeDanhSachMat[i]*2;
	}
	int U = WD_HEIGHT/2 - H/2 - 10;
	int L =	WD_WIDTH/2 - W/2;
	
	int x = L, y = U+kichThuocSTT+(stt%20)*h;
	int yOld = y;
	inTrangDetailList(tree, danhSachDetailBill, sizeDanhSachMat, tmpB, 0);
			
	int choose = 1;
	stt = 20;
	veMuc3Chon(650, 680 ,khungListBill, choose, 0, stt);
	while(1){
		if(kbhit()){
			char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_UP:{
							stt--;
							break;
						}
						case KEY_DOWN:{
							stt++;
							break;
						}
						case KEY_LEFT:{
							if(stt == 20){
								choose--;
							}
						break;
						}
						case KEY_RIGHT:{
							if(stt == 20){
								choose++;
							}
							break;
						}				
					}
					if (stt == -1)
						stt = 20;
					else
						if (stt > 20)
							stt = 0;
					if(choose == 0){
						choose = 3;
					}
					else
						if(choose > 3)
							choose = 1;
					if(stt >= 0 && stt <= 19){
						y = U+kichThuocSTT+(stt%20)*h;
						// to den hinh chu nhat cu
						setcolor(BLACK);
						rectangle(x+3 - 17 - 1, yOld, x+W-3 + 17, yOld+h);
						// ve hinh chu nhat moi
						setcolor(LIGHTGREEN);
						rectangle(x+3 - 17 - 1, y, x+W-3 + 17, y+h);
						yOld = y;
					}
					if(stt == 20){	
						setcolor(BLACK);
						rectangle(x - 14 - 1, yOld, x+W + 14, yOld+h);
						veMuc3Chon(650,680,khungListBill,choose, 0, stt);
					}
					else{
						choose = 1;
						veMuc3Chon(650,680,khungListBill,choose, 1, stt);
					}
				}
				else
					if (key == 27){ //exit
						bool x=1;
						veKhungYesNo(cancle, x, 0);
						if(x){
							VeMenu();
							return VeKhungAddBill(tree, ListEmployees, khungBill, 450, 600);
						}
						else
							goto N;
					}
					else
						if (key == '\r'){
							if(stt >= 0 && stt <= 19 && stt < tmpB.details->n) {	//chon tung phan tu
								selected = true;
								VeMenu();
								return;
							}
							if(stt == 20){
								if(choose == 1){
									if(!tmpB.details->isFull()){
										//add material
										VeMenu();
										return khungThemMatVaoBill(tree,ListEmployees,choiceObject, NoX, tmpB, keyName);
										// NoX = 1  nhap, RoA = 0 xuat
									}
									else{
										ThongBao(1000, 35, Fail[8], LIGHTRED, BLACK);
										goto N;
									}
								}
								else
									if(choose == 2){
										//confirm
										// neu list rong thi bao loi
										if(tmpB.details->isEmpty()){
											ThongBao(1000, 35, Fail[2], LIGHTRED, BLACK);
										}
										else{
		//									// save Bill
											// adjust quantity
											for(int i = 0 ;i<tmpB.details->n;i++){
												NODER tmpM;
												tmpM = Search(tree,tmpB.details->nodeListDeta[i].ID);
												long tmpNum = 0;
												if(NoX == 1){
													tmpNum = ChangeCharToNum(tmpM->info.amount) + tmpB.details->nodeListDeta[i].amount;
												}
												else{
													tmpNum = ChangeCharToNum(tmpM->info.amount) - tmpB.details->nodeListDeta[i].amount;
													
												}
												strcpy(tmpM->info.amount,  toChars(tmpNum));
											}
											ListEmployees.addBill(keyName, tmpB);
											VeMenu();
											return;
										}
									}
									else
										if(choose == 3){
											VeMenu();
											return VeKhungAddBill(tree, ListEmployees, khungBill, 450, 600);
										}
							}
						}
		}	//kbhit
	}	//while
}

void inTrangDetailList(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Bills &tmpB, int start){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++)
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2 - 10;
	int D =	WD_HEIGHT/2 + H/2 - 10;
	int L =	WD_WIDTH/2 - W/2 - 1;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = 20;
	for (int i = start; i < 20; i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		if(i < tmpB.details->n)
			inVatTuBill(tmpB.details->nodeListDeta[i], disW, dis);
			
		dis += h+5;
	}
}

void inVatTuBill(Details VT, int posX, int posY){
	// in ID
	outtextxy(posX + canLeGiua(VT.ID, textwidth(danhSachDetailBill[1])+sizeDanhSachMat[1]*2), posY, VT.ID);
	posX += textwidth(danhSachDetailBill[1]) + sizeDanhSachMat[1]*2;
	
	// in Rate
	outtextxy(posX + 10, posY, toChars(VT.price));
	posX += textwidth(danhSachDetailBill[2]) + sizeDanhSachMat[2]*2;
	
	// in VAT
	outtextxy(posX + canLeGiua(toChars(VT.VAT) , textwidth(danhSachDetailBill[3])+sizeDanhSachMat[3]*2), posY, toChars(VT.VAT));
	posX += textwidth(danhSachDetailBill[3]) + sizeDanhSachMat[3]*2;
	
	// in Quantity
	outtextxy(posX + canLeGiua(toChars(VT.amount) , textwidth(danhSachDetailBill[4])+sizeDanhSachMat[4]*2), posY, toChars(VT.amount));		
	posX += textwidth(danhSachDetailBill[4]) + sizeDanhSachMat[4]*2;
}

void khungDetailduocChon(NODER &tree, listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, Bills &tmpB, int &ViTri, bool NoX, char keyName[]){
	NODER p;
	int cases = 1;
	NotiN:
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
		
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D-10);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	
	for (int i = 2; i <= SoLuongKhung; i++){
		if (i == 2)
			veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
		else
			veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
	}
	
	//===== Chon vi tri ======//
	int pos = 1;
	veMuc3Chon(H, W - 7, khungchooseBill, 1, 1, pos);
	struct DetailVT{
		char ID[11];
		char amount[9];
		char VAT[3];
		char price[11];
		DetailVT(){
			ID[0] = '\0';
			amount[0] = '\0';
			VAT[0] = '\0';
			price[0] = '\0';
		}
	};
	DetailVT tmpVT;
	// in thong tin
	strcpy(tmpVT.ID, tmpB.details->nodeListDeta[ViTri].ID);
	strcpy(tmpVT.amount, toChars(tmpB.details->nodeListDeta[ViTri].amount));
	strcpy(tmpVT.VAT, toChars(tmpB.details->nodeListDeta[ViTri].VAT));
	strcpy(tmpVT.price, toChars(tmpB.details->nodeListDeta[ViTri].price));
	infoText(380, ViTriKhung[1], khungNoiDung[1+2],tmpVT.ID, WHITE);
	//InThongTin(560, ViTriKhung[1], tmpVT.ID);
	InThongTin(560, ViTriKhung[2], tmpVT.price);
	InThongTin(560, ViTriKhung[3], tmpVT.VAT);
	InThongTin(560, ViTriKhung[4], tmpVT.amount);
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						pos--;
						if(pos == 1)
							pos = 5;
						break;
					}
					case KEY_DOWN:{
						pos++;
						break;
					}
				}
				cpos:
				if (pos == 0)
					pos = 5;
				if (pos > 5)
					pos = 2;
			}
			else
				if (key == '\r'){
					if (pos <= 4)
						pos++;
				}
				else
					if (key == 27){
						VeMenu();
						return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
					}
			
			
			for (int i = 2; i <= SoLuongKhung; i++)			
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
			
			setbkcolor(NEN_TEXT);
//			InThongTin(560, ViTriKhung[1], tmpVT.ID );
			InThongTin(560, ViTriKhung[2], tmpVT.price);
			InThongTin(560, ViTriKhung[3], tmpVT.VAT);
			InThongTin(560, ViTriKhung[4], tmpVT.amount);
			veMuc3Chon(H, W - 7, khungchooseBill, 1, 1,pos);
			
			//===di chuyen trong menu===//
			switch(pos){
//				case 1:{
//					veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
//					Nhap(560,200,-1, key, tmpVT.ID,10);
//					break;
//				}
				case 2:{
					veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, BLACK);
					Nhap(560,260,0, key, tmpVT.price, 10);
					break;
				}
				case 3:{
					veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, BLACK);
					Nhap(560,320,0, key, tmpVT.VAT,2);
					break;
				}
				case 4:{
					veKhung(380, 380, khungNoiDung[6], 1, NEN_KHUNG, BLACK);
					Nhap(560,380,0, key, tmpVT.amount,8);					
					break;
				}
				case 5:{
					int buttonL = 1;
					veMuc3Chon(H, W - 7, khungchooseBill, buttonL, 0, pos);		
					while(1){
						if(kbhit()){
							char key5 = getch();
							char c5Next;
							if (key5 == 0){
								c5Next = getch();
								switch(c5Next){
									case KEY_UP:{
										pos--;
										veMuc3Chon(H, W - 7,khungchooseBill, buttonL, 1,pos);
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										veMuc3Chon(H, W - 7, khungchooseBill, buttonL, 1,pos);
										goto cpos;
									}
									case KEY_LEFT:{
										buttonL--;
										break;
									}
									case KEY_RIGHT:{
										buttonL++;
										break;
									}
								}
							}
							if(buttonL==0){
								buttonL = 3;
							}
							else
								if(buttonL >3){
									buttonL = 1;
								}
							if (key5 == '\r'){
								//return;
								if (buttonL == 1||buttonL == 2){
									//===thong bao loi===//
									if(strlen(tmpVT.ID) != 0 && strlen(tmpVT.amount) != 0 && strlen(tmpVT.VAT) != 0
									&& strlen(tmpVT.price) != 0){
										if(buttonL==1){
											//remove
											ThongBao(730, 90, Success[1], LIGHTGREEN, BLACK);
											tmpB.details->Detele(ViTri);
											VeMenu();
											return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
										}
										if(buttonL==2){
											//adjust
											p = Search(tree, tmpVT.ID);
											if(p != NULL){		//adjust bi loi so luong hoa don xuat
												if(ChangeCharToNum(tmpVT.price) == 0 || ChangeCharToNum(tmpVT.amount) == 0){
				 									ThongBao(730, 90, Fail[9], LIGHTRED, BLACK);
				 									goto NotiN;
												}
												if(NoX == 0){
													if(ChangeCharToNum(p->info.amount) < ChangeCharToNum(tmpVT.amount)){
														ThongBao(730, 90, Success[0], LIGHTGREEN, BLACK);
														strcpy(tmpB.details->nodeListDeta[ViTri].ID,tmpVT.ID);
														tmpB.details->nodeListDeta[ViTri].amount = ChangeCharToNum(tmpVT.amount);
														tmpB.details->nodeListDeta[ViTri].VAT = ChangeCharToNum(tmpVT.VAT);
														tmpB.details->nodeListDeta[ViTri].price = ChangeCharToNum(tmpVT.price);
														VeMenu();
														return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
													}
													else{
														ThongBao(730, 90, Fail[6], LIGHTRED, BLACK);
														infoText(380, 450, lackAmount[0], p->info.amount, WHITE);	
													}
												}
												else{
													ThongBao(730, 90, Success[0], LIGHTGREEN, BLACK);
													strcpy(tmpB.details->nodeListDeta[ViTri].ID,tmpVT.ID);
													tmpB.details->nodeListDeta[ViTri].amount = ChangeCharToNum(tmpVT.amount);
													tmpB.details->nodeListDeta[ViTri].VAT = ChangeCharToNum(tmpVT.VAT);
													tmpB.details->nodeListDeta[ViTri].price = ChangeCharToNum(tmpVT.price);
													VeMenu();
													return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
												}
											}
//											else{	
//												ThongBao(800, 90, Fail[1], LIGHTRED, BLACK);
//											}											
										}
									}
									else{
										ThongBao(760, 90, Fail[0], LIGHTRED, BLACK);
										goto NotiN;
									}
								}
								else
									if(buttonL == 3){
										//tro lai khung chon bill
										VeMenu();
										return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
									}
							}
							else
								if (key5 == 27){
									VeMenu();
									return danhSachDetail(tree, ListEmployees, NoX, tmpB, keyName);
								}
							veMuc3Chon(H, W - 7, khungchooseBill, buttonL, 0,pos);
						}//kbhit
					}//while
				}//case 5
			}
//			InThongTin(560, ViTriKhung[1], tmpVT.ID );
			InThongTin(560, ViTriKhung[2], tmpVT.price);
			InThongTin(560, ViTriKhung[3], tmpVT.VAT);
			InThongTin(560, ViTriKhung[4], tmpVT.amount);
		}
	}
}

void inInfoBill(NODER &tree,listEmp &ListEmployees,Employee *tmpE, char findID[]){
	// in info bill
	int soLuongKhung = 4;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	int H = 450;
	int W = 600;
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2-70;
	int D =	WD_HEIGHT/2 + H/2-70;
	int L =	WD_WIDTH/2 - W/2-300;//int L =	WD_WIDTH/2 - W/2-290;
	int R =	WD_WIDTH/2 + W/2-400;//int R =	WD_WIDTH/2 + W/2-370;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(U-30 + 200, U+5, khungBill[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	setbkcolor(NEN_KHUNG);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	bar (L, D-kichThuocNut, R, D);
	setbkcolor(HL_MENU_PHU);
	setcolor(BLACK);
	outtextxy((L+R)/2 - textwidth(khungBill[2])/2, D - kichThuocNut + textheight(khungBill[2])/2, khungBill[2]);
	Bills tmpB;
	tmpB = tmpE->listBill.findBill(findID);
	infoText(U+30, ViTriKhung[1]-70, khungBill[3],tmpB.Num,WHITE);
	// info date

	infoText(U+30, ViTriKhung[2]-70, khungBill[4],charDate(tmpB.date.day,tmpB.date.month,tmpB.date.year),WHITE);
	//===
	infoText(U+30, ViTriKhung[3]-70, khungBill[7],tmpE->lastName,WHITE);
//	outtextxy(260+ textwidth(tmpE->lastName)+textwidth(" "), ViTriKhung[3]-70, tmpE->firstName);
	outtextxy(260+ textwidth(tmpE->lastName) + 5, ViTriKhung[3]-70, tmpE->firstName);
	char type;
	type=tmpB.type;
	setcolor(BLACK);
	outtextxy(U+30, ViTriKhung[4]-70, khungBill[6]);
	setcolor(WHITE);
	outtextxy(U+30 + 175 -1, ViTriKhung[4]-70, &type);
//	infoText(U+30, ViTriKhung[4]-70, khungBill[6],&(tmpB.type),WHITE);
	
	//==in danh sach Material==
	int startPage = 1;
	int limitPage = 1;
	if (limitPage == 0){
		VeMenu();
		notify(Fail[2]);
		return;
	}
	else{
		TrangDetailBill(tree, danhSachDetailBill, sizeDanhSachMat, tmpB, 0);
	}
	while(1){
		char key = getch();
		if(key == '\r' || key == 27){
			VeMenu();
			struct Bills tmpB;
			return veKhungSearchBill(tree, ListEmployees, choiceBillList, tmpB);	
		}		
	}
}

void TrangDetailBill(NODER &tree, char khungNoiDung[][30], int sizeKhungNoiDung[], Bills &tmpB, int start){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++)
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2+255;
	int R =	WD_WIDTH/2 + W/2+255;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = 20;
	for (int i = start; i < 20; i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		if(i < tmpB.details->n){
			inVatTuBill(tmpB.details->nodeListDeta[i], disW, dis);
		}
		dis += h+5;
	}
}

void veKhungSearchBill(NODER &tree, listEmp &ListEmployees,char khungNoiDung[][30], Bills &tmpB){
	bool choice = 1;
	bool choiceN = 1; 
	int posR = 0;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
//	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
//	setcolor(MAU_TEXT_KHUNG);
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(580, 240, title[5]);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	// ve khung chon id
	rectangle(L+14+105-30, ViTriKhung[3]-11,WD_WIDTH/2+105+30, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15+105-30, ViTriKhung[3]-10,WD_WIDTH/2+105+30, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setcolor(BLACK);
	outtextxy(L+25+105-30, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	
	// 2 nut check and exit
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[2]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[3]);
	//make ur choice
	
	char findID[21];
	findID[0] = '\0';
	while(1){
		InThongTin(L+30+2*textwidth(khungNoiDung[0])+105 -30,ViTriKhung[3],findID);
		if(kbhit()){
			char keyR = getch();
			char ckeyR;
			if(keyR==0){
				ckeyR = getch();
				switch(ckeyR){
					case KEY_LEFT:{
						if(posR==2 || posR==3){
							choiceN ^= 1;	
						}
						break;
					}
					case KEY_RIGHT:{
						if(posR==2 || posR==3){
							choiceN ^= 1;	
						}
							break;
					}
					case KEY_UP:{
						if(posR == 0){
							choice = 0;
							posR = 2;
							break;
						}
						if(posR == 2 || posR == 3){
							posR =0;
							choice = 1;
 							choiceN = 1;
							break;
						}		
					}
					case KEY_DOWN:{
						if(posR==0){
							posR = 2;
							choice = 0;
							break;
						}
						if(posR == 2 || posR == 3){
						 	posR = 0;
						 	choice = 1;
						 	choiceN = 1;
						 	break;
						}	
					}	
				}
			}
			if(keyR == '\r'){
				if(posR == 0){
					posR = 2;
				}
				else{
					if(choiceN){
						if(strlen(findID) != 0){
							if(ListEmployees.FindEmp(findID) == NULL){
								//loi ko ton tai
								ThongBao(740, 210, Fail[1], LIGHTRED, BLACK);
//								posR=0;
							}
							else{
								VeMenu();	
								Employee *tmpE;
								tmpE = ListEmployees.FindEmp(findID);
								return inInfoBill(tree,ListEmployees, tmpE, findID);
							}
						}
						else{
							ThongBao(760, 210, Fail[0], LIGHTRED, BLACK);
//							posR = 0;
						}
					}
					else{
						VeMenu();
						return ;
					}
				}
			}
			if(keyR == 27){
				VeMenu();
				return;
			}
		// hien thi
		if(posR==0){
			setcolor(BLACK);
			setbkcolor(NEN_KHUNG);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			if(choice){
				// ID
				setbkcolor(HL_MENU_PHU);
				setfillstyle(SOLID_FILL, HL_MENU_PHU);									//do mau nen cho nut
				bar (L+15+105- 30, ViTriKhung[3]-10,WD_WIDTH/2 +105 +30, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				outtextxy(L+25+105 -30, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				Nhap(L+30+2*textwidth(khungNoiDung[0])+105 - 30,ViTriKhung[3],-1,keyR,findID,20);
	 		} 		
			else{
				bar (L+15+105-30, ViTriKhung[3]-10,WD_WIDTH/2+105 +30 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25+105 -30, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				bar (L+25+2*textwidth(khungNoiDung[0])+105 -30, ViTriKhung[3]-2, WD_WIDTH/2-15+105 +30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
			}
			setcolor(BLACK);
			setbkcolor(NEN_KHUNG);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			bar (L, D-kichThuocNut, WD_WIDTH/2, D);
			bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
			line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
			line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			setcolor(BLACK);
			outtextxy(L+midText1, D-midTextH, khungNoiDung[2]);
			outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[3]);
		}
		else
			if(posR==2 || posR==3){
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(choiceN){	
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					setcolor(BLACK);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[2]);
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[3]);
				}
				else{
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					setcolor(BLACK);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[3]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[2]);
				}
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				setbkcolor(NEN_KHUNG);
				//khung ngoai
				bar (L+15+105-30, ViTriKhung[3]-10,WD_WIDTH/2 +105+30, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
				outtextxy(L+25+105-30, ViTriKhung[3], khungNoiDung[0]);
				setfillstyle(SOLID_FILL, TEXTBOX);
				//khung trong
				bar (L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				rectangle(L+25+2*textwidth(khungNoiDung[0])+105-30, ViTriKhung[3]-2, WD_WIDTH/2-15+105+30, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	} // while	
}
// end bill

//employee
void khungNhapEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *tmpE, bool &selected){
	selected = false;
	int soLuongKhung = 4;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	//khung
	rectangle(L - 1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 1)
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
			else
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
		}
		else{
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, 1, NEN_KHUNG, BLACK);
		}
	}
	
	int pos = 1;
	int fst = tmpE->sex;			//SEX
	
	//in thong tin
	InThongTin(560, ViTriKhung[1], tmpE->ID);
	InThongTin(560, ViTriKhung[2], tmpE->firstName);
	InThongTin(560, ViTriKhung[3], tmpE->lastName);
	veMuc2Chon(380, 380, khungNoiDung[6], Sex, tmpE->sex, NEN_KHUNG, BLACK);
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						pos--;
						break;
					}
					case KEY_DOWN:{
						pos++;
						break;
					}
				}
				cpos:
				if (pos == 0)
					pos = 5;
				if (pos > 5)
					pos = 1;
			}
			else
				if (key == '\r'){
					if (pos <= 4)
						pos++;
				}
				else
					if (key == 27){
						//VeMenu();
						return;
					}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 4; i++){
				if (i != 4)
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
				else
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, fst, NEN_KHUNG, BLACK);
				setcolor(WHITE);
			}
			setbkcolor(NEN_TEXT);
			InThongTin(560, ViTriKhung[1], tmpE->ID);
			InThongTin(560, ViTriKhung[2], tmpE->firstName);
			InThongTin(560, ViTriKhung[3], tmpE->lastName);
			switch(pos){
				case 1:{
					veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
					Nhap(560, 200, -1, key, tmpE->ID, 10);
					break;
				}
				case 2:{
					veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, BLACK);
					Nhap(560, 260, 1, key, tmpE->firstName, 10);
					break;
				}
				case 3:{
					veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, BLACK);
					Nhap(560, 320, 1, key, tmpE->lastName, 20);
					break;
				}
				case 4:{
					veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, LIGHTGREEN);
					while(1){
						if (kbhit()){
							char key4 = getch();
							if (key4 == 0){
								char c4Next = getch();
								switch(c4Next){
									case KEY_LEFT:{
										fst++;
										break;
									}
									case KEY_RIGHT:{
										fst--;
										break;
									}
									case KEY_UP:{
										pos--;
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										goto cpos;
									}
								}
							}
							else
								if (key4 == '\r'){
									pos++;
									goto cpos;
									break;
								}
								else
									if (key4 == 27){
										return;
									}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, LIGHTGREEN);
								tmpE->sex = fst;
							}
						}
						break;
					}
				case 5:{
					bool buttonL = 1;
					veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
					while(1){
						if(kbhit()){
							char key5 = getch();
							char c5Next;
							if (key5 == 0){
								c5Next = getch();
								switch(c5Next){
									case KEY_UP:{
										pos--;
										veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
										goto cpos;
									}
									case KEY_LEFT:{
										buttonL ^= 1;
										break;
									}
									case KEY_RIGHT:{
										buttonL ^= 1;
										break;
									}
								}
							}
							else
								if (key5 == '\r'){
									//return;
									if (buttonL == 1){
										if(strlen(tmpE->ID) != 0 && strlen(tmpE->firstName) != 0 && strlen(tmpE->lastName) != 0)
										{
											selected = true;
											return;
										}
										else{
											ThongBao(760, 90, Fail[0], LIGHTRED, BLACK);
										}
									}
									else{
										VeMenu();
										return;
									}
								}
								else
									if (key5 == 27){
										VeMenu();
										return;
									}
							veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
						}
					}
				}
			}
		}
	}
}

void khungAdjustInfoEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *tmpE, bool &selected){
	struct Employee recovertmp;
	strcpy(recovertmp.firstName, tmpE->firstName);
	strcpy(recovertmp.lastName, tmpE->lastName);
	recovertmp.sex = tmpE->sex;
	NotiN:
	selected = false;
	int soLuongKhung = 4;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
		
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);				//top line
	
	//khung
	rectangle(L-1, U, R, D);
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);				//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);		//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	for (int i = 1; i <= soLuongKhung; i++){
		if (i != soLuongKhung){
			if (i == 1){
				veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				bar (550, ViTriKhung[i]-2-1, 835, ViTriKhung[i]+textheight(khungNoiDung[i+2])+5);
				setcolor(BLACK);
				setbkcolor(NEN_KHUNG);
				outtextxy(560, ViTriKhung[1], tmpE->ID);
			}
			else{
				if (i == 2)
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 1, NEN_KHUNG, BLACK);
				else
					veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
			}
		}
		else{
			veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, 1, NEN_KHUNG, BLACK);
		}
	}
	
	int pos = 2;
	int fst = tmpE->sex;			//SEX
	
	//in thong tin
	InThongTin(560, ViTriKhung[2], tmpE->firstName);
	InThongTin(560, ViTriKhung[3], tmpE->lastName);
	veMuc2Chon(380, 380, khungNoiDung[6], Sex, tmpE->sex, NEN_KHUNG, BLACK);
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						pos--;
						break;
					}
					case KEY_DOWN:{
						pos++;
						break;
					}
				}
				cpos:
				if (pos == 1)
					pos = 5;
				if (pos > 5)
					pos = 2;
			}
			else
				if (key == '\r'){
					if (pos <= 4)
						pos++;
				}
				else
					if (key == 27){
//						strcpy(tmpE->firstName, recovertmp.firstName);
//						strcpy(tmpE->lastName, recovertmp.lastName);
//						tmpE->sex=recovertmp.sex;
						VeMenu();
						return;
					}
			
			setbkcolor(NEN_TEXT);	
			for (int i = 1; i <= 4; i++){
				if (i != 4){
					if (i > 1){
						veKhung(380, ViTriKhung[i], khungNoiDung[i+2], 0, NEN_KHUNG, BLACK);
					}
				}
				else
					veMuc2Chon(380, ViTriKhung[i], khungNoiDung[i+2], Sex, fst, NEN_KHUNG, BLACK);
				setcolor(BLACK);
			}
			setbkcolor(NEN_TEXT);
			//InThongTin(560, ViTriKhung[1], tmpE->ID);
			InThongTin(560, ViTriKhung[2], tmpE->firstName);
			InThongTin(560, ViTriKhung[3], tmpE->lastName);
			switch(pos){
				case 1:{
//					veKhung(380, 200, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
//					Nhap(560, 200, -1, key, tmpE->ID, 10);
//					break;
				}
				case 2:{
					veKhung(380, 260, khungNoiDung[4], 1, NEN_KHUNG, BLACK);
					Nhap(560, 260, 1, key, tmpE->firstName, 10);
					break;
				}
				case 3:{
					veKhung(380, 320, khungNoiDung[5], 1, NEN_KHUNG, BLACK);
					Nhap(560, 320, 1, key, tmpE->lastName, 20);
					break;
				}
				case 4:{
					veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, LIGHTGREEN);
					while(1){
						if (kbhit()){
							char key4 = getch();
							if (key4 == 0){
								char c4Next = getch();
								switch(c4Next){
									case KEY_LEFT:{
										fst++;
										break;
									}
									case KEY_RIGHT:{
										fst--;
										break;
									}
									case KEY_UP:{
										pos--;
										goto cpos;
									}
									case KEY_DOWN:{
										pos++;
										goto cpos;
									}
								}
							}
							else
								if (key4 == '\r'){
									pos++;
									goto cpos;
									break;
								}
								else
									if (key4 == 27){
//										strcpy(tmpE->firstName, recovertmp.firstName);
//										strcpy(tmpE->lastName, recovertmp.lastName);
//										tmpE->sex=recovertmp.sex;
										return;
									}
								if (fst == -1)
									fst = 1;
								if (fst > 1)
									fst = 0;								
								veMuc2Chon(380, 380, khungNoiDung[6], Sex, fst, NEN_KHUNG, LIGHTGREEN);
								tmpE->sex = fst;
							}
						}
						break;
					}
				case 5:{
						bool buttonL = 1;
						veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
						while(1){
							if(kbhit()){
								char key5 = getch();
								char c5Next;
								if (key5 == 0){
									c5Next = getch();
									switch(c5Next){
										case KEY_UP:{
											pos--;
											veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
											goto cpos;
										}
										case KEY_DOWN:{
											pos++;
											veKhungNut(H, W, khungNoiDung, buttonL, 1,1);
											goto cpos;
										}
										case KEY_LEFT:{
											buttonL ^= 1;
											break;
										}
										case KEY_RIGHT:{
											buttonL ^= 1;
											break;
										}
									}
								}
								else
									if (key5 == '\r'){
										//return;
										if (buttonL == 1){
											if(strlen(tmpE->ID) != 0 && strlen(tmpE->firstName) != 0 && strlen(tmpE->lastName) != 0){
												char notyet[]="Info Has Not Been Adjusted!";
												if(strcmp(recovertmp.firstName, tmpE->firstName) == 0 && strcmp(recovertmp.lastName, tmpE->lastName) == 0
												 && recovertmp.sex == tmpE->sex){
													ThongBao(690, 150, notyet, LIGHTRED, BLACK);
													goto NotiN;
												}
												else{
													selected = true;
													ThongBao(740, 90, Success[2], LIGHTGREEN, BLACK);
													return;
												}												
											}
											else{
												ThongBao(760, 90, Fail[0], LIGHTRED, BLACK);
											}
										}
										else{
//											strcpy(tmpE->firstName, recovertmp.firstName);
//											strcpy(tmpE->lastName, recovertmp.lastName);
//											tmpE->sex=recovertmp.sex;
											VeMenu();
											return;
										}
									}
									else
										if (key5 == 27){
//											strcpy(tmpE->firstName, recovertmp.firstName);
//											strcpy(tmpE->lastName, recovertmp.lastName);
//											tmpE->sex=recovertmp.sex;
											VeMenu();
											return;
										}
								veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
							}
						}
					}
			}
		}
	}
}

void addEmp(struct listEmp &ListEmployees){
	bool entered = false;
	do{
		struct Employee *tmpE = new struct Employee;
		fixEmp:
		khungNhapEmp(ListEmployees, khungEmp, 450, 600, tmpE, entered);
		if (entered){
			if (ListEmployees.isFull()){
				ThongBao(760, 90, Fail[8], LIGHTRED, BLACK);
			}
			else{
				if (ListEmployees.Search_info(tmpE) == -1){
					ListEmployees.Insert(tmpE);
					ThongBao(760, 90, Success[0], LIGHTGREEN, BLACK);
				}
				else{
					bool chooseY = 1;
					veKhungYesNo(sameEmp, chooseY, 0);
					if(chooseY){
						
						struct Employee *tmpEmp = ListEmployees.Search_ID(tmpE->ID);
						struct Employee recovertmp;
						strcpy(recovertmp.ID, tmpEmp->ID);
						strcpy(recovertmp.firstName, tmpEmp->firstName);
						strcpy(recovertmp.lastName, tmpEmp->lastName);
						recovertmp.sex = tmpEmp->sex;
						
						khungAdjustInfoEmp(ListEmployees, khungAdjustEmp, 450, 600, ListEmployees.Search_ID(tmpE->ID), entered);

						if(entered == false){
							strcpy(tmpEmp->ID, recovertmp.ID);
							strcpy(tmpEmp->firstName, recovertmp.firstName);
							strcpy(tmpEmp->lastName, recovertmp.lastName);
							tmpEmp->sex=recovertmp.sex;
							entered = true;
						}
					}
					else{
						goto fixEmp;
					}
				}
			}	
		}
	} while(entered);
	VeMenu();
}

void inTrangEmp(struct listEmp &list, char khungNoiDung[][30], int sizeKhungNoiDung[], int start){
	int kichThuocSTT = 30;
	int h = textheight(khungNoiDung[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 5; i++){
		W += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i]*2;
	}
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 5; i++){
		dis += sizeKhungNoiDung[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, khungNoiDung[i]);
		dis += textwidth(khungNoiDung[i]) + sizeKhungNoiDung[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = list.n;
	for (int i = start; i < min(start + OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(khungNoiDung[0])+sizeKhungNoiDung[0]*2), dis, d);
		disW += textwidth(khungNoiDung[0]) + sizeKhungNoiDung[0]*2;
		
		inNhanVien(list.nodeListEmp[i], disW, dis);
		
		dis += h+5;
	}
	
	setbkcolor(MAU_NEN);
}

void inNhanVien(struct Employee *NV, int posX, int posY){
	// in ID
	outtextxy(posX + canLeGiua(NV->ID, textwidth(danhSachEmp[1])+sizeDanhSachEmp[1]*2), posY, NV->ID);
	posX += textwidth(danhSachEmp[1]) + sizeDanhSachEmp[1]*2;
	
	// in Last Name
	outtextxy(posX + 10, posY, NV->lastName);
	posX += textwidth(danhSachEmp[2]) + sizeDanhSachEmp[2]*2;
	
	// in First Name
	outtextxy(posX + 10, posY, NV->firstName);
	posX += textwidth(danhSachEmp[3]) + sizeDanhSachEmp[3]*2;
	
	// in Sex
	if (NV->sex) // is Male
		outtextxy(posX + canLeGiua(danhSachEmp[5] , textwidth(danhSachEmp[4])+sizeDanhSachEmp[4]*2), posY, danhSachEmp[5]);
	else
		outtextxy(posX + canLeGiua(danhSachEmp[6] , textwidth(danhSachEmp[4])+sizeDanhSachEmp[4]*2), posY, danhSachEmp[6]);
		
	posX += textwidth(danhSachEmp[4]) + sizeDanhSachEmp[4]*2;
}

void inDanhSachEmp(struct listEmp &ListEmployees){
	if(ListEmployees.n == 0){
		notify(Fail[2]);
		return;
	}
	sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);
	//in danh sach
	int startPage = 1;
	int limitPage = ceil(ListEmployees.n*1.0/OBJ_PER_PAGE);
	if (limitPage == 0){
		notify(Fail[2]);
	}
	else{
		inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage - 1)*OBJ_PER_PAGE);
		showPage(830, 635, startPage, limitPage);
		while(1){
			if(kbhit()){
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGUP:{
							startPage--;
							if (startPage < 1)
								startPage = limitPage;
							inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage - 1)*OBJ_PER_PAGE);
							showPage(830, 635, startPage, limitPage);
							break;
						}
						case KEY_PGDN:{
							startPage++;
							if (startPage > limitPage)
								startPage = 1;
							inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage - 1)*OBJ_PER_PAGE);
							showPage(830, 635, startPage, limitPage);
							break;
						}
					}
				}
				else
					if(key == 27){ //exit
						VeMenu();
						return;
					}
			}
		}
	}
}

void chonTuDanhSach(struct listEmp &ListEmployees, int &stt, int &startPage, bool &selected){	
	//in danh sach
	//int startPage = 1;
	selected = false;
	int limitPage = ceil(ListEmployees.n*1.0/OBJ_PER_PAGE);
	if (limitPage == 0)
		notify(Fail[2]);
		
	else{
		// tinh thong so
		int kichThuocSTT = 30;
		int h = textheight(danhSachEmp[0]) + 5*2;
		int H = (h)*OBJ_PER_PAGE + kichThuocSTT;
		int W = 0;
		for (int i = 0; i < 5; i++)
			W += textwidth(danhSachEmp[i]) + sizeDanhSachEmp[i]*2;

		int U = WD_HEIGHT/2 - H/2;
		int L =	WD_WIDTH/2 - W/2;
		
		int x = L, y = U + kichThuocSTT+(stt % OBJ_PER_PAGE)*h;
		int yOld = y;
				
		inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage-1)*OBJ_PER_PAGE);
		showPage(830, 635, startPage, limitPage);
		
		setcolor(LIGHTGREEN);
		rectangle(x, y, x+W, y + h);
		while(1){
			if(kbhit()){
				char key = getch();
				if (key == 0){
					char nextK = getch();
					switch(nextK){
						case KEY_PGUP:{
							startPage--;
							if (startPage < 1)
								startPage = limitPage;
							inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage-1)*OBJ_PER_PAGE);
							showPage(830, 635, startPage, limitPage);
							stt = (startPage-1)*OBJ_PER_PAGE;
							break;
						}
						case KEY_PGDN:{
							startPage++;
							if (startPage > limitPage)
								startPage = 1;
							inTrangEmp(ListEmployees, danhSachEmp, sizeDanhSachEmp, (startPage-1)*OBJ_PER_PAGE);
							showPage(830, 635, startPage, limitPage);
							stt = (startPage-1)*OBJ_PER_PAGE;
							break;
						}
						case KEY_UP:{
							stt--;
							break;
						}
						case KEY_DOWN:{
							stt++;
							break;
						}
					}
					if (stt < (startPage-1)*OBJ_PER_PAGE)
						stt = min((startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1), ListEmployees.n-1);
					else if (stt > (startPage-1)*OBJ_PER_PAGE+(OBJ_PER_PAGE-1) || stt > ListEmployees.n-1)
						stt = (startPage-1)*OBJ_PER_PAGE;
						
					y = U + kichThuocSTT + (stt % OBJ_PER_PAGE) * h;
					// to den hinh chu nhat cu
					setcolor(BLACK);
					rectangle(x, yOld, x+W, yOld+h);
					// ve hinh chu nhat moi
					setcolor(LIGHTGREEN);
					rectangle(x, y, x+W, y+h);
					yOld = y;
				}
				else
					if (key == 27) {//exit
						//VeMenu();
						return;
					}
					else
						if (key == '\r'){
							selected = true;
							return;
						}
			}
		}
	}
}

void danhSachRemoveEmp(struct listEmp &ListEmployees){
	
	if(ListEmployees.n == 0)
	{
		ThongBao(760, 210, Fail[2], LIGHTRED, BLACK);
		VeMenu();
		return removeEmp(ListEmployees);
	}
	else{
		char xoa[][80]={"Enter To Delete"};
		setcolor(CYAN);
		outtextxy(350, 635, xoa[0]);
		
		sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);	
		int removePos = 0;
		int page = 1;
		bool select;
		while(1){
			chonTuDanhSach(ListEmployees, removePos, page, select);
			if(select){
				ListEmployees.Detele(removePos);
			}
			else{
				VeMenu();
				return removeEmp(ListEmployees);
			}
		}
		VeMenu();
	}
}

void removeEmp(struct listEmp &ListEmployees){
	bool entered = false;
	do{
		bool chooseList = false;
		char tmpID[11];
		int Re = 1;
		inID_LIST(choiceObject, ListEmployees, chooseList, tmpID, entered, Re);
		if (entered){
			if (chooseList){
				return danhSachRemoveEmp(ListEmployees);
			}
			else{
				struct Employee *tmp;
				tmp = ListEmployees.Search_ID(tmpID);
				if(tmp == NULL){
					//loi ko ton tai
					ThongBao(760, 210, Fail[1], LIGHTRED, BLACK);
				}
				else	
					deleteInfoEmp(ListEmployees, checkEmp, 450, 600, tmp);
				
			}
		}
	}while(entered);
}

void inID_LIST(char khungNoiDung[][30], struct listEmp &ListEmployees, bool &list, char *findID, bool &selected, int Re){
	selected = false;
	bool choice = 1;
	bool chooseL = 1; 
	int posR = 1;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	int H = 200;
	int W = 450;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	setcolor(BLACK);
	rectangle(L-1, U-1, R+1, D+1);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);			//top line
	int n=0;
	if(Re == 1){
		n=2;
		settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(570, 240, title[n]);
	}
	else{
		n=3;
		settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(550, 240, title[n]);
	}
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);				//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);		//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[3]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[4]))/2;
	int midText3 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[2]);
	setcolor(BLACK);	
	
	rectangle(L+14, ViTriKhung[3]-11, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+textheight(khungNoiDung[0]));
	// ve khung chon id
	setbkcolor(HL_MENU_PHU);
	setfillstyle(SOLID_FILL, HL_MENU_PHU);
	bar (L+15, ViTriKhung[3]-10, WD_WIDTH/2, ViTriKhung[3]+10+textheight(khungNoiDung[0]));
	setcolor(BLACK);
	outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
	setfillstyle(SOLID_FILL, TEXTBOX);
	bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
	
	// ve khung chon list
	setbkcolor(NEN_KHUNG);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
	setcolor(BLACK);
	outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);	
	setfillstyle(SOLID_FILL, HL_MENU_PHU);	
	
	// 2 nut check and exit
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
	
	//make ur choice	
	findID[0] = '\0';
	while(1){
		InThongTin(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3], findID);
		if(kbhit()){
			char keyR = getch();
			if(keyR==0){
				char ckeyR = getch();
				switch(ckeyR){
					case KEY_LEFT:{
						if(posR==1)//trên
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)//duoi
							chooseL ^= 1;	
						break;
					}
					case KEY_RIGHT:{
						if(posR==1)
							choice ^= 1; // 1: trai 0: phai
						if(posR==2)
							chooseL ^= 1;	
						break;
					}
					case KEY_UP:{
						if(posR == 1){
							posR = 2;
							chooseL = true;
							break;
						}
						else{
							posR = 1;
							break;
						}		
					}
					case KEY_DOWN:{
						if(posR == 1){
							posR = 2;
							chooseL = true;
							break;
						}
						else{
							posR = 1;
							break;
						}	
					}	
				}
			}
			if(keyR == '\r'){
				if(posR == 1){
					posR = 2;
					chooseL = 1;
				}
				else{
					if(chooseL){
						if(choice == 1){
							list = false;
							selected = true;
							return;
						}
						else{
							list = true;
							selected = true;
							return;
						}
					}
					else{
						VeMenu();
						return;
					}
				}
			}
			if(keyR == 27){
				VeMenu();
				return;
			}
			// hien thi
			if(posR == 1){	//ID/list
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);
				if(choice){
					// ID
					setbkcolor(NEN_KHUNG);
					bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setcolor(BLACK);
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
					
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setcolor(BLACK);
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
					Nhap(L+30+2*textwidth(khungNoiDung[0]),ViTriKhung[3],-1,keyR, findID, 10);
				}
				else{
					// list
					setbkcolor(NEN_KHUNG);
					bar (L+15, ViTriKhung[3]-10,WD_WIDTH/2 , ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setcolor(BLACK);
					outtextxy(L+25, ViTriKhung[3], khungNoiDung[0]);
					
					setfillstyle(SOLID_FILL, TEXTBOX);
					bar (L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
					rectangle(L+25+2*textwidth(khungNoiDung[0]), ViTriKhung[3]-2, WD_WIDTH/2-15, ViTriKhung[3]+2+ textheight(khungNoiDung[0]));
					setbkcolor(HL_MENU_PHU);
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					bar(WD_WIDTH/2, ViTriKhung[3]-10, WD_WIDTH/2 + (R-L)/2-15, ViTriKhung[3]+10+ textheight(khungNoiDung[0]));
					setcolor(BLACK);
					outtextxy(WD_WIDTH/2 +	midText3, ViTriKhung[3], khungNoiDung[2]);
				}
			//reset posR = 2	
			setcolor(BLACK);
			setfillstyle(SOLID_FILL, NEN_KHUNG);
			bar (L, D-kichThuocNut, WD_WIDTH/2, D);
			bar (WD_WIDTH/2, D-kichThuocNut, R, D);				
			setbkcolor(NEN_KHUNG);
			line(L, D-kichThuocNut, R, D-kichThuocNut);			//bottom line
			line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			setcolor(BLACK);
			outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
			outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
			}
			else{	//check/exit
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, NEN_KHUNG);	
				if(chooseL){	//check
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);//reset mau
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					//hightlight check
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);
					setbkcolor(HL_MENU_PHU);
					setcolor(BLACK);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);					
					setbkcolor(NEN_KHUNG);
					outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[4]);
				}
				else{	//exit
					bar (L, D-kichThuocNut, WD_WIDTH/2, D);//reset mau
					setfillstyle(SOLID_FILL, HL_MENU_PHU);
					//hightlight exit
					bar (WD_WIDTH/2, D-kichThuocNut, R, D);
					setbkcolor(HL_MENU_PHU);
					setcolor(BLACK);
					outtextxy(WD_WIDTH/2 + midText2, D-midTextH, khungNoiDung[4]);
					setbkcolor(NEN_KHUNG);
					outtextxy(L+midText1, D-midTextH, khungNoiDung[3]);
				}
				setcolor(BLACK);
				line(L, D-kichThuocNut, R, D-kichThuocNut);		//bottom line
				line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);
			}		
		}
	}
}

void deleteInfoEmp(struct listEmp &ListEmployees, char khungNoiDung[][30], int H, int W, struct Employee *Info){
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);					//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(540, 115, khungNoiDung[0]);
	
	//Ve cac khung ban dau===
	int SoLuongKhung = 4;
	int mauNut = NEN_KHUNG;
	setfillstyle(SOLID_FILL, mauNut);
	bar (L, D-kichThuocNut, R, D);
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);					//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);			//center line
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2+midText2, D-midTextH, khungNoiDung[2]);
	
	//info
	infoText(380, ViTriKhung[1], khungNoiDung[1+2], Info->ID,WHITE);
	infoText(380, ViTriKhung[2], khungNoiDung[2+2], Info->firstName,WHITE);
	infoText(380, ViTriKhung[3], khungNoiDung[3+2], Info->lastName,WHITE);
	veMuc2Chon(380, ViTriKhung[4], khungNoiDung[4+2], Sex, Info->sex, NEN_KHUNG, WHITE);
	bool buttonL = 1;
	veKhungNut(H, W, khungNoiDung, buttonL, 0, 1);
	while(1){
		if(kbhit()){
			char key = getch();
			if(key==0){
				char ckey = getch();
				switch(ckey){
					case KEY_LEFT:{
						buttonL ^= 1;
						break;
					}
					case KEY_RIGHT:{
						buttonL ^= 1;
						break;
					}
				}
			}
			else
				if(key == '\r'){
					if(buttonL){
						ListEmployees.DeteleID(Info->ID);
						ThongBao(760, 90, Success[1], LIGHTGREEN, BLACK);
					}
					VeMenu();
					return;
				}
				else
					if(key==27){
				 		VeMenu();
					 	return;
					}
			veKhungNut(H, W, khungNoiDung, buttonL, 0,1);
		}
	}
}

void danhSachAdjustEmp(struct listEmp &ListEmployees){
	if(ListEmployees.n == 0){
		ThongBao(760, 210, Fail[2], LIGHTRED, BLACK);
		VeMenu();
		return chinhSuaEmp(ListEmployees);
	}
	else{
		//tao mang 1 chieu
		sortEmp(ListEmployees.nodeListEmp, 0, ListEmployees.n-1);
		
		int choosePos = 0;
		int page = 1;
		bool select;
		while(1){
			chonTuDanhSach(ListEmployees, choosePos, page, select);
			if(select){
				struct Employee *tmpE;
				tmpE = ListEmployees.nodeListEmp[choosePos];
				
				struct Employee recoverE;
				strcpy(recoverE.ID, tmpE->ID);
				strcpy(recoverE.firstName, tmpE->firstName);
				strcpy(recoverE.lastName, tmpE->lastName);
				recoverE.sex = tmpE->sex;
				
				bool saved = false;
				khungAdjustInfoEmp(ListEmployees, khungAdjustEmp, 450, 600, tmpE, saved);
				if (saved == false){
					strcpy(tmpE->ID, recoverE.ID);
					strcpy(tmpE->firstName, recoverE.firstName);
					strcpy(tmpE->lastName, recoverE.lastName);
					tmpE->sex = recoverE.sex;
				}
			}
			else{
				VeMenu();
				return chinhSuaEmp(ListEmployees);
			}
		}
		VeMenu();
	}
}

void chinhSuaEmp(struct listEmp &ListEmployees){
	bool entered = false;
	do{
		bool chooseList = false;
		char tmpID[11];
		int Re=0;
		inID_LIST(choiceObject, ListEmployees, chooseList, tmpID, entered, Re);
		if (entered){
			if (chooseList)			
				return danhSachAdjustEmp(ListEmployees);
			
			else{
				struct Employee *tmpE;
				tmpE = ListEmployees.Search_ID(tmpID);
				if(tmpE == NULL){
					//loi ko ton tai
					ThongBao(740, 210, Fail[1], LIGHTRED, BLACK);
				}
				else{	
					// tao bien de khoi phuc
					struct Employee recoverE;
					strcpy(recoverE.ID, tmpE->ID);
					strcpy(recoverE.firstName, tmpE->firstName);
					strcpy(recoverE.lastName, tmpE->lastName);
					recoverE.sex = tmpE->sex;
					
					bool saved = false;
					khungAdjustInfoEmp(ListEmployees, khungAdjustEmp, 450, 600, tmpE, saved);
					if (!saved){
						strcpy(tmpE->ID, recoverE.ID);
						strcpy(tmpE->firstName, recoverE.firstName);
						strcpy(tmpE->lastName, recoverE.lastName);
						tmpE->sex = recoverE.sex;
					}					
				}
			}
			VeMenu();
		}
	}while(entered);
}
//end employee


void inTrangBill(struct listEmp &list, struct listBillDate *arr, int start){
	int kichThuocSTT = 30;
	int h = textheight(trangBill[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 7; i++)
		W += textwidth(trangBill[i]) + sizeTrangBill[i]*2;
	
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 7; i++){
		dis += sizeTrangBill[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, trangBill[i]);
		dis += textwidth(trangBill[i]) + sizeTrangBill[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	int Size = arr->Size;
	for (int i = start; i < min(start+OBJ_PER_PAGE, Size); i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(trangBill[0])+sizeTrangBill[0]*2), dis, d);
		disW += textwidth(trangBill[0]) + sizeTrangBill[0]*2;
		
		{
			setcolor(BLACK);
			//Bills* tmpB = new Bills;
			Bills* tmpB;
			tmpB = arr->index(i)->info;
			//outtextxy(disW+5, dis, tmpB->Num);
			outtextxy(disW+canLeGiua(tmpB->Num, textwidth(trangBill[1]) + sizeTrangBill[1]*2), dis, tmpB->Num);
			disW += textwidth(trangBill[1]) + sizeTrangBill[1]*2;
			
			char *date = charDate(tmpB->date.day, tmpB->date.month, tmpB->date.year);
			outtextxy(disW+canLeGiua(date, textwidth(trangBill[2]) + sizeTrangBill[2]*2), dis, date);
			disW += textwidth(trangBill[2]) + sizeTrangBill[2]*2;
			
			if (tmpB->type == 'N')
				outtextxy(disW+(sizeTrangBill[3]*2-1.0/2*textwidth("NHAP")), dis, "NHAP");
			else
				outtextxy(disW+(sizeTrangBill[3]*2-1.0/2*textwidth("XUAT")), dis, "XUAT");
			
			disW += textwidth(trangBill[3]) + sizeTrangBill[3]*2;
			
			//Employee* tmpE = new Employee;
			Employee* tmpE;
			tmpE = arr->index(i)->Emp;
			
			outtextxy(disW+5, dis, tmpE->lastName);
			disW += textwidth(trangBill[4]) + sizeTrangBill[4]*2;
						
			outtextxy(disW+5, dis, tmpE->firstName);
			disW += textwidth(trangBill[5]) + sizeTrangBill[5]*2;
			
			disW += textwidth(trangBill[6]) + sizeTrangBill[6]*2;
			outtextxy(disW-5-textwidth(toChars(tmpB->value())), dis, toChars(tmpB->value()));
			
		}
		dis += h+5;
	}	
	setbkcolor(MAU_NEN);
}


void taoMangBillDate(struct listEmp &List, struct listBillDate *arr, struct Dates dayBegin, struct Dates dayEnd){
	for (int i = 0; i < List.n; i++){
		NODE_LB p;
		for (p = List.nodeListEmp[i]->listBill.firstNode; p != NULL; p = p->next){
			struct Dates curDate = p->info.date;
			if ((curDate < dayEnd || curDate == dayEnd) && (curDate > dayBegin || curDate == dayBegin))
				arr->insert(p->info, List.nodeListEmp[i]);
		}
	}
}

void thongKeBill(struct listEmp &ListEmployees){
	struct listBillDate *arrBill = new listBillDate;
	Dates dayBegin, dayEnd;
	bool selected = false;
	
	nhapNgay(dayBegin, dayEnd, khungNhapNgay, selected);
	
	if (selected){
		taoMangBillDate(ListEmployees, arrBill, dayBegin, dayEnd);
	
		//in danh sach
		int startPage = 1;
		int limitPage = ceil(arrBill->Size*1.0/OBJ_PER_PAGE);
	
		if (limitPage == 0){
			notify(Fail[2]);
		}
		else{
			//in ngay nhap
			char *date1 = charDate(dayBegin.day, dayBegin.month, dayBegin.year);			
			char *date2 = charDate(dayEnd.day, dayEnd.month, dayEnd.year);
			hienThiTime(130, 635, date1, date2, khungNhapNgay);
			inTrangBill(ListEmployees, arrBill, 0);
			showPage(1050, 635, startPage, limitPage);
			while(1){
				if(kbhit()){
					char key = getch();
					if (key == 0){
						char nextK = getch();
						switch(nextK){
							case KEY_PGUP:{
								startPage--;
								if (startPage < 1)
									startPage = limitPage;
								inTrangBill(ListEmployees, arrBill, (startPage-1)*OBJ_PER_PAGE);
								showPage(1050, 635, startPage, limitPage);
								break;
							}
							case KEY_PGDN:{
								startPage++;
								if (startPage > limitPage)
									startPage = 1;
								inTrangBill(ListEmployees, arrBill, (startPage-1)*OBJ_PER_PAGE);
								showPage(1050, 635, startPage, limitPage);
								break;
							}
						}
					}
					else
						if(key == 27) {	//exit
							delete arrBill;
							VeMenu();
							return thongKeBill(ListEmployees);
						}
				}
			}
		}
	}	
}

void nhapNgay(Dates &dayBegin, Dates &dayEnd, char khungNoiDung[][30], bool &selected){

	int H = 200;
	int W = 500;
	
	int soLuongKhung = 2;
	int kichThuocSTT = 30;
	int kichThuocNut = 40;
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
		
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
			
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								//top line
	
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(L+5, U+(kichThuocSTT-textheight(khungNoiDung[0]))/2, khungNoiDung[0]);
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, D-kichThuocNut, R, D);
	
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);
	line(L, D-kichThuocNut, R, D-kichThuocNut);								//bottom line
	line(WD_WIDTH/2, D-kichThuocNut, WD_WIDTH/2, D);						//center line
	
	setbkcolor(NEN_KHUNG);
	int midText1 = ((R-L)/2 - textwidth(khungNoiDung[1]))/2;
	int midText2 = ((R-L)/2 - textwidth(khungNoiDung[2]))/2;
	int midTextH = (kichThuocNut - textheight(khungNoiDung[1]))/2 + textheight(khungNoiDung[1]);
	setcolor(BLACK);
	outtextxy(L+midText1, D-midTextH, khungNoiDung[1]);
	outtextxy(WD_WIDTH/2 + midText2, D-midTextH, khungNoiDung[2]);
	//ve khung nhap lieu
	VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], 1, NEN_KHUNG, BLACK);
	VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
	
	struct FDate{
		char days[5];
		char months[5];
		char years[5];
		FDate(){
			days[0]='\0';
			months[0]='\0';
			years[0]='\0';
		}
	}; 
	FDate date1, date2;
	int pos = 1;
	while(1){
		if(kbhit()){
			char key = getch();
			char cNext;
			resetKey:
			if (key == 0){
				cNext = getch();
				switch(cNext){
					case KEY_UP:{
						if (pos >= 1 && pos <= 3){
							pos = 7;
							VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], 0, NEN_KHUNG, BLACK);
						}
						else
							if (pos >= 4 && pos <= 6)
								pos -= 3;
							else
								pos = 4;
						break;
					}
					case KEY_DOWN:{
						if (pos >= 1 && pos <= 3)
							pos += 3;
						else
							if (pos >= 4 && pos <= 6){
								pos = 7;
								VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
							}
							else
								pos = 1;
						break;
					}
					case KEY_LEFT:{
						pos--;
						if (pos == 0)
							pos = 8;
						break;
					}
					case KEY_RIGHT:{
						pos++;
						if (pos == 9)
							pos = 1;
						break;
					}
				}
				if (pos >= 1 && pos <= 6){
					veKhungNut(H, W, khungNoiDung, (pos == 7), 1, 1);
					if (pos <= 3){
						VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
						VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], pos, NEN_KHUNG, BLACK);
					}
					else
						if (pos <= 6){
							VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], 0, NEN_KHUNG, BLACK);
							VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], pos-3, NEN_KHUNG, BLACK);
						}
				}
				else{
					VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
					VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], 0, NEN_KHUNG, BLACK);
					veKhungNut(H, W, khungNoiDung, (pos == 7), 0, 1);
				}
			}
			else
				if (key == '\r'){
					if (pos == 7){
						if (strlen(date1.days) == 0 || strlen(date1.months) == 0 || strlen(date1.years) == 0 ||
						strlen(date2.days) == 0 || strlen(date2.months) == 0 || strlen(date2.years) == 0){
							ThongBao(R-5-textwidth(Fail[0]), U+(kichThuocSTT-textheight(Fail[0]))/2 - 30, Fail[0], LIGHTRED, BLACK);
						}
						else{
							dayBegin.day = ChangeCharToNum(date1.days);
							dayBegin.month = ChangeCharToNum(date1.months);
							dayBegin.year = ChangeCharToNum(date1.years);
							
							dayEnd.day = ChangeCharToNum(date2.days);
							dayEnd.month = ChangeCharToNum(date2.months);
							dayEnd.year = ChangeCharToNum(date2.years);
							
							if (dayBegin > dayEnd || !dayBegin.isValid() || !dayEnd.isValid()){													
									ThongBao(R-5-textwidth(Fail[3]), U+(kichThuocSTT-textheight(Fail[3]))/2 - 30, Fail[3], LIGHTRED, BLACK);
							}
							else{
								selected = true;
								VeMenu();
								return;
							}
						}						
					}
					else
						if (pos == 8){
							selected = false;
							VeMenu();
							return;
						}
						else{
							pos++;
							if (pos == 7){
								VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
								veKhungNut(H, W, khungNoiDung, (pos == 7), 0, 1);
							}
						}
				}
				else
					if (key == 27){
						selected = false;
						VeMenu();
						return;
					}
			switch(pos){
				case 1:{
					Nhap(560+40-textwidth(date1.days) + 30, ViTriKhung[3]-30, 0, key, date1.days, 2);
					break;
				}
				case 2:{
					Nhap(560+150-textwidth(date1.months) + 30, ViTriKhung[3]-30, 0, key, date1.months, 2);
					break;
				}
				case 3:{
					Nhap(560+260-textwidth(date1.years) + 30, ViTriKhung[3]-30, 0, key, date1.years, 4);
					break;
				}
				case 4:{
					Nhap(560+40-textwidth(date2.days) + 30, ViTriKhung[4]-30, 0, key, date2.days, 2);
					break;
				}
				case 5:{
					Nhap(560+150-textwidth(date2.months) + 30, ViTriKhung[4]-30, 0, key, date2.months, 2);
					break; 
				}
				case 6:{
					Nhap(560+260-textwidth(date2.years) + 30, ViTriKhung[4]-30, 0, key, date2.years, 4);
					break;
				}
			}
			if (pos <= 3){
				VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], 0, NEN_KHUNG, BLACK);
				VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], pos, NEN_KHUNG, BLACK);
			}
			else
				if (pos <= 6){
					VeMucChonNgay(410, ViTriKhung[3]-30, khungNoiDung[3], 0, NEN_KHUNG, BLACK);
					VeMucChonNgay(410, ViTriKhung[4]-30, khungNoiDung[4], pos-3, NEN_KHUNG, BLACK);
				}
			setbkcolor(NEN_TEXT);
			InThongTin(560+40-textwidth(date1.days) + 30, ViTriKhung[3]-30, date1.days);	
			InThongTin(560+150-textwidth(date1.months) + 30, ViTriKhung[3]-30, date1.months);	
			InThongTin(560+260-textwidth(date1.years) + 30, ViTriKhung[3]-30, date1.years);	
			
			InThongTin(560+40-textwidth(date2.days) + 30, ViTriKhung[4]-30, date2.days);	
			InThongTin(560+150-textwidth(date2.months) + 30, ViTriKhung[4]-30, date2.months);	
			InThongTin(560+260-textwidth(date2.years) + 30, ViTriKhung[4]-30, date2.years);		
		}//kbhit
	}
}

void sortTopMat(NameMats *arr, int left, int right){
	NameMats mid = arr[(left + right) / 2];
	int i = left, j = right;
	do{
		while(arr[i] > mid)
			i++;
		while(arr[j] < mid)
			j--;
		if(i <= j){
			if(i < j){
				NameMats tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		sortTopMat(arr, left, j);
	if(right > i)
		sortTopMat(arr, i, right);
}

void TinhGiaTriRevenue(NameMats *arr, char code[11], unsigned long long Rev){
	for (int i = 0; i < CountM; i++){
		if (strcmp(arr[i].code, code) == 0){
			arr[i].revenue += Rev;
			return;
		}
	}
}

void updateRevenue(NameMats *arr, listBillDate *arrBill){
	for (NODE_BDate node = arrBill->firstNode; node != NULL; node = node->next){
		if (node->info->type == 'X'){
			listBillDeta *tmpDT = node->info->details;
			for (int i = 0; i < tmpDT->n; i++){
				int amountMat	= tmpDT->nodeListDeta[i].amount;
				int priceMat	= tmpDT->nodeListDeta[i].price;
				int VAT			= tmpDT->nodeListDeta[i].VAT;
				TinhGiaTriRevenue(arr, tmpDT->nodeListDeta[i].ID, (1LL*amountMat*priceMat)*((VAT+100)/100.0));
			}
		}
	}
}

void findMaxMat(NameMats *arrMat, int &C){
	int valueOld = 0;
	for (C = 0; C < CountM; C++) {
		if (valueOld != arrMat[C].revenue)
			valueOld = arrMat[C].revenue;
			
		if (arrMat[C].revenue == 0 || C == 10)
			break;
	}
}

void topVatTu(NODER &tree, struct listEmp &ListEmployees){
	struct listBillDate *arrBill = new listBillDate;
	Dates dayBegin, dayEnd;
	bool selected = false;

	nhapNgay(dayBegin, dayEnd, ngayTopVT, selected);
	
	if (selected){
		taoMangBillDate(ListEmployees, arrBill, dayBegin, dayEnd);
		NameMats *arrMat = new NameMats[CountM];
		Count = 0;
		taoMangMat(tree, arrMat);
		updateRevenue(arrMat, arrBill);
		sortTopMat(arrMat, 0, CountM - 1);
		//check
		int countMatRank = 0;
		findMaxMat(arrMat, countMatRank);
		//in danh sach
		int startPage = 1;
		int limitPage = ceil(countMatRank*1.0/OBJ_PER_PAGE);
	
		if (limitPage == 0){
			notify(Fail[2]);
		}
		else{
			//in ngay nhap
			char *date1 = charDate(dayBegin.day, dayBegin.month, dayBegin.year);			
			char *date2 = charDate(dayEnd.day, dayEnd.month, dayEnd.year);
			hienThiTime(350, 635, date1, date2, khungNhapNgay);
			
			inTrangTopVT(ListEmployees, arrMat, countMatRank, 0);
			showPage(820, 635, startPage, limitPage);
			while(1){
				if(kbhit()){
					char key = getch();
					if(key == 27){	 //exit		
						delete arrMat;
						delete arrBill;
						VeMenu();
						return topVatTu(tree, ListEmployees);
					}
				}
			}
		}	
	}		
}

void inTrangTopVT(struct listEmp &list, struct NameMats *arr, int Size, int start){
	int kichThuocSTT = 30;
	int h = textheight(trangTop[0]);
	int H = (h+5*2)*OBJ_PER_PAGE + kichThuocSTT;
	int W = 0;
	for (int i = 0; i < 4; i++){
		W += textwidth(trangTop[i]) + sizeTrangTop[i]*2;
	}
	
	setusercharsize(1, 2, 1, 2);
	//tinh kich thuoc khung
	int U = WD_HEIGHT/2 - H/2;
	int D =	WD_HEIGHT/2 + H/2;
	int L =	WD_WIDTH/2 - W/2;
	int R =	WD_WIDTH/2 + W/2;
	
	//in nen phan noi dung
	setfillstyle(SOLID_FILL, NEN_KHUNG);
	bar (L, U, R, D);
	
	//in nen phan danh sach
	setbkcolor(MAU_MENU);
	setfillstyle(SOLID_FILL, MAU_MENU);
	bar (L, U, R, U+kichThuocSTT);
	
	//in duong ke phan menu + vien
	setcolor(BLACK);
	setlinestyle(SOLID_LINE, EMPTY_FILL, NORM_WIDTH);		
	line(L, U+kichThuocSTT, R, U+kichThuocSTT);								
	rectangle(L-1, U-1, R+1, D+1);
	
	//in phan noi dung + gach doc
	settextstyle(COMPLEX_FONT, 0, USER_CHAR_SIZE);
	int dis = L;
	for (int i = 0; i < 4; i++){
		dis += sizeTrangTop[i];
		setcolor(MAU_TEXT_KHUNG);
		outtextxy(dis, U+(kichThuocSTT-h)/2, trangTop[i]);
		dis += textwidth(trangTop[i]) + sizeTrangTop[i];
		setcolor(BLACK);
		line(dis, U, dis, D);
	}
	//in gach ngang
	dis = U + kichThuocSTT;
	for (int i = 0; i < 20; i++){
		dis += h+5*2;
		line(L, dis, R, dis);
	}
	
	// in thong tin
	setcolor(BLACK);
	setbkcolor(NEN_KHUNG);
	dis = U + kichThuocSTT;
	for (int i = start; i < Size; i++){
		dis += 5;	
		// in STT
		int disW = L;
		char *d = toChars(i+1);
		outtextxy(disW + canLeGiua(d, textwidth(trangTop[0])+sizeTrangTop[0]*2), dis, d);
		disW += textwidth(trangTop[0]) + sizeTrangTop[0]*2;
		
		{
			setcolor(BLACK);
			outtextxy(disW+canLeGiua(arr[i].code, textwidth(trangTop[1]) + sizeTrangTop[1]*2), dis, arr[i].code);
			disW += textwidth(trangTop[1]) + sizeTrangTop[1]*2;
			
			outtextxy(disW+canLeGiua(arr[i].name, textwidth(trangTop[2]) + sizeTrangTop[2]*2), dis, arr[i].name);
			disW += textwidth(trangTop[2]) + sizeTrangTop[2]*2;
			
			outtextxy(disW+(textwidth(trangTop[3]) + sizeTrangTop[3]*2-5) - textwidth(toChars(arr[i].revenue)), dis, toChars(arr[i].revenue));
		}
		
		dis += h+5;
	}	
	setbkcolor(MAU_NEN);
}
//========end==========
