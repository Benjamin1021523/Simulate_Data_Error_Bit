#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>//¦³ªºcompiler¤£¥Îinclude
#include<iomanip>
using namespace std;

#define sectors 24		//ï¿½ï¿½Æ¶ï¿½Æ¶q 
#define errorRate 16	//ï¿½ï¿½ï¿½~ï¿½oï¿½Íªï¿½ï¿½ï¿½ï¿½vï¿½ï¿½1/errorRate 

void Print();

#include<windows.h>
void SetColor(int f=7){
    unsigned short ForeColor=f;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

bool data[sectors][sectorSize] = {};
int count[sectors] = {};

int main(){
	srand (time(NULL));
	int total = 0;
	for(int i = 0;i < sectors;i++){
		for(int j = 0;j < sectorSize;j++){
			if(!(rand() % errorRate)){
				data[i][j] = 1;
				++count[i];
			}
		}
		total += count[i];
	}

	Print();
	cout << "Total error: " << total << endl;
	cout << "error rate = " << fixed << setprecision(2) << (double)total / sectors * sectorSize << "%" << endl;
}

void Print(){
	for(int i = 0;i < sectors;++i){
		cout << "------------" << endl;
		cout << "|";
		for(int j = 0;j < sectorSize;++j){
			if(data[i][j])
				SetColor(12*16);
			else
				SetColor(7*16);
			cout << " ";
			SetColor();
		}
		cout << "|" << endl;
	}
	cout << "------------" << endl;
}
