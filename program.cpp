#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>//有的compiler不用include
#include<iomanip>
#include<string>
using namespace std; 

void Print(int o);

#include"COLOR.cpp"
#include"DEFINE.h"

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
	string edge, edgeB;
	for(int i = 0;i < sectorSize;++i){
		edge += "-";
		edgeB += "=";
	}
	for(int i = 0;i < sectors;++i){
		SetColor(colorOfEdge*16);
		cout << "=";
		if(i % o == 0){
			//SetColor(colorOfEdge*16);
			cout << edgeB;
		}
		else{
			SetColor();
			cout << edge;
		}
		SetColor(colorOfEdge*16);
		cout << "=" << endl;
		cout << "|";
		for(int j = 0;j < sectorSize;++j){
			if(data[i][j])
				SetColor(errorColor*16);
			else
				SetColor(normalColor*16);
			cout << " ";
			SetColor();
		}
		SetColor(colorOfEdge*16);
		cout << "|";
		SetColor();
				
		if(check == i){
			temp = 0;
			for(int j = check;j < i + o;++j){
				temp += count[j];
			}
			cout << "  This part has ";
			if(temp > o)
				SetColor(errorColor);
			cout << temp;
			SetColor();
			cout << " errors.";
			check += o;
		}
		cout << endl;
	}
	SetColor(colorOfEdge*16);
	cout << "=" << edgeB << "=" << endl;
	SetColor();
	
	cout << edge << endl;

}

