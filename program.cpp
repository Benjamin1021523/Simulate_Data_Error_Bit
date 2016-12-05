#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>//有的compiler不用include
#include<iomanip>
#include<string>
using namespace std;
#define sectorSize 10	//資料塊大小
#define sectors 24		//資料塊數量
#define errorRate 16	//錯誤發生的機率為1/errorRate 

void Print(int o);

#include"COLOR.cpp"

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

	Print(4);
	cout << "Total error: " << total << endl;
	cout << "error rate = " << fixed << setprecision(2) << (double)total / sectors * sectorSize << "%" << endl;
}

void Print(int o){
	string out;
	out += "ω = ";
	out += (o + 48);
	cout << out << endl;
	int check = 0;
	int temp;
	SetColor(14*16);
	for(int i = 0;i < sectorSize + 2 + 2;++i)
		cout << " ";
	cout << endl;
	SetColor();
	for(int i = 0;i < sectors;++i){
		
		SetColor(14*16);
		cout << " ";
		SetColor();
		for(int j = 0;j < sectorSize + 2;++j)
			cout << "-";
		SetColor(14*16);
		cout << " ";
		SetColor();
		cout << endl;
		SetColor(14*16);
		cout << " ";
		SetColor();
		cout << "|";
		for(int j = 0;j < sectorSize;++j){
			if(data[i][j])
				SetColor(12*16);
			else
				SetColor(7*16);
			cout << " ";
			SetColor();
		}
		cout << "|";
		SetColor(14*16);
		cout << " ";
		SetColor();
		
		if(check == i){
			temp = 0;
			for(int j = check;j < i + o;++j){
				temp += count[j];
			}
			cout << "  This part has ";
			if(temp > o)
				SetColor(12);
			cout << temp;
			SetColor();
			cout << " errors.";
			check += o;
		}
		cout << endl;
		if((i + 1) % o == 0){
			SetColor(14*16);
			cout << " ";
			SetColor();
			for(int j = 0;j < sectorSize + 2;++j)
				cout << "-";
			SetColor(14*16);
			cout << " " << endl;
			for(int j = 0;j < sectorSize + 2 + 2;++j)
				cout << " ";
			cout << endl;
			SetColor();
		}
	}
	
	for(int i = 0;i < sectorSize + 2;++i)
		cout << "-";
	cout << endl;

}

