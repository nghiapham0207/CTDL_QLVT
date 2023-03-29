#include "function.h"
#define DELAY_NOTI 2000

bool CheckLetter(char s){
	if((s>= 65 && s<= 90) || (s>= 97 && s<= 122 ) || (s==32)){
		return 1;
	}
	return 0;	 
}

bool CheckNum(char s){
		if(s >= 48 && s <= 57){
			return 1;
		}
	return 0;	 
}

unsigned long long ChangeCharToNum (char s[]){
	unsigned long long n = 0;
	for(int i = 0; i<strlen(s);i++){
		n *= 10;
		n += (s[i]-48);
	}
	return n;
}

char* toChars(unsigned long long num){
	char* a = new char[100];
	if (num == 0){
		a[1] = '\0';
		a[0] = '0';
	}
	else{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0){
			a[l--] = num%10+48; //to char
			num/=10;
		}
	}
	return a;
}
void AddChuoi(char c, char s[]){
	strncat(s, &c,1);
}

void get_chuoi(char *des, char *s ){
	int it = 0;
	for(int i=0; i<strlen(s); i++){
		if(s[i] != ' '){
			des[it] = toupper(s[i]);
			it++;
		}
	}
	des[it] ='\0';
}

void delBlank(char *s){
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == ' '){
			s[i] = s[i+1];
			for(int j = i+1;j<strlen(s)-1;j++){
				s[j] = s[j+1];
			}
			s[strlen(s)-1] = '\0';
		}
	}
}

int KiemtraNhapLieu(char c, char s[]){
	if(strlen(s) == 0 && c == ' ') // block space
		return 0;
	else	
		if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') // block double space 
			return 0;	
		else	
			if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' '))// upper Letter
				return -1;
	return 1;	 
}

bool GioiHanKyTu(char s[], int n){
	if(strlen(s)<n)
		return 1;
	return 0;	
}

void Nhap(int x, int y, int check, char c, char s[], int n){

	if(c == 8 && strlen(s) != 0){ //c==8 backspace
		s[strlen(s)-1] = '\0';
	}	
	if(check == 1){	// chi co ky tu in hoa chu cai dau moi tu
		if(CheckLetter(c) && GioiHanKyTu(s,n)){
			if(KiemtraNhapLieu(c,s) == 1){
				c = tolower(c);
				AddChuoi(c,s);
			}
			else
				if(KiemtraNhapLieu(c,s)==-1){
					c = toupper(c);
					AddChuoi(c,s);
				}		
		}
		
	}
	else
		if(check==0) {	// chi nhan ky tu so
			if(CheckNum(c) && GioiHanKyTu(s,n)){
				if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1){
					AddChuoi(c,s);
				}
			}
		}
		else
			if(check == -1) {	// in hoa, khong co dau cach, cho phep ca so va ky tu chu cai
				if((CheckNum(c) || CheckLetter(c)) && GioiHanKyTu(s,n) && c != ' '){
					
					if(KiemtraNhapLieu(c,s) == 1|| KiemtraNhapLieu(c,s) == -1){
						c = toupper(c);
						AddChuoi(c,s);
					}
				}
			}
			else
				if(check == 2){	// ky tu dau tien in hoa con lai in thuong, co ca so va ky tu chu cai
					if((CheckNum(c) || CheckLetter(c)) && GioiHanKyTu(s,n)){
						
						if(KiemtraNhapLieu(c,s) == 1){
							c = tolower(c);
							AddChuoi(c,s);
						}
						else
							if(KiemtraNhapLieu(c,s) == -1){
								c = toupper(c);
								AddChuoi(c,s);
							}
					}
				}
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x,y,s);
}

int canLeGiua(char *S, int dis){
	return (dis-textwidth(S))/2;
}

//Ham do hoa

void InThongTin(int x, int y, const char *s){
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x, y, s);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen){	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(DELAY_NOTI);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));	
}

void showPage(int x, int y, int page, int limit){
	//Page: page / limit
	setcolor(MAU_TEXT_KHUNG);
	setbkcolor(MAU_NEN);
	outtextxy(x, y, "Page: ");
	x += textwidth("Page: ");
	
	outtextxy(x, y, toChars(page));
	x += textwidth(toChars(page));
	
	outtextxy(x, y, " / ");
	x += textwidth(" / ");	
	
	outtextxy(x, y, toChars(limit));
}

char* charDate(int day, int month, int year){
	char *res = new char[100];
	res[0] = '\0';
	
	if (day < 10)
		strcat(res, "0");
	strcat(res, toChars(day));
	strcat(res, "/");
	
	if (month < 10)
		strcat(res, "0");
	strcat(res, toChars(month));
	strcat(res, "/");
	
	if (year < 10)
		strcat(res, "0");
	if (year < 100)
		strcat(res, "0");
	if (year < 1000)
		strcat(res, "0");
	strcat(res, toChars(year));
	
	return res;
}
void hienThiTime(int x, int y, char *date1, char *date2,char khungND[][30]){
	setcolor(CYAN);
	setbkcolor(BLACK);
	outtextxy(x, y, khungND[3]);
	x = x + textwidth(khungND[3]) + 10;
	outtextxy(x, y, date1);
	x = x + textwidth(date1) + 10;
	outtextxy(x, y, khungND[4]);
	x = x + textwidth(khungND[4]) + 10;
	outtextxy(x, y, date2);
}

