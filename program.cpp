#include<iostream>
#include<ctime> 
#include<vector>
#include<cstdlib>//有的compiler不用include
using namespace std;
#define sectorSize 10
#define sectors 24
void omega(int range);

bool data[sectors][sectorSize] = {};
int count[sectors] = {};

int main(){
	srand (time(NULL));
	int den = 10;
	int a;
	for(int i = 0;i < sectors;i++){
		for(int j = 0;j < sectorSize;j++){
			if(rand() % den + 1 == 1){
				data[i][j] = 1;
				++count[i];
			}
		}
	}

	omega(1);
	omega(2);
	omega(3);
	omega(4);
}

void omega(int range){
	vector<int> result;
	int temp = 0;
	for(int i = 0;i < sectors;i++){
		temp += count[i];
		if((i + 1) % range == 0 || i + 1 == 24){
			result.push_back(temp);
			temp = 0;
		}
	}
	cout << endl;
	for(int i = 0;i < result.size();i++)
		cout << result[i] << " ";
	cout << endl;
}
