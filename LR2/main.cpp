#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string line;//слово
	stringstream ss;	//строковый поток
	int max = -1; //максимальное значение
	int cnt = 1;//счётчик 1 так как точка есть всегда
	while(getline(in,line, '.')){//считываем по предложению
		cnt = 1;
		for(unsigned i = 0; i < line.size(); ++i){//считаем знаки препинания
			//если это знак препинания
			if(!((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))){
				 ++cnt;
			}
		}
		if(cnt > max){ //если больше максимального
			max = cnt;
			ss.clear();//очищаем поток вывода
		    ss.str(std::string());
			ss << line << ".\n";	//выводим в поток
		}
		else if(cnt == max){
			 ss << line << ".\n";	//выводим в поток
		}
	}
	cout << ss.str();// выводим предложение
	in.close();//закрываем файл										   
	system("pause>>void");
}