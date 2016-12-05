#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>//有的compiler不用include
#include<iomanip>
using namespace std;

#define sectorSize 10
#define sectors 24

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
	int den = 10;
	int total = 0;
	for(int i = 0;i < sectors;i++){
		for(int j = 0;j < sectorSize;j++){
			if(rand() % den + 1 == 1){
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
	for(int j = 0;j < sectors;++j){
		cout << "------------" << endl;
		cout << "|";
		for(int i = 0;i < sectorSize;++i){
			if(data[j][i])
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
