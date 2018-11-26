#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string line;//�����
	stringstream ss;	//��������� �����
	int max = -1; //������������ ��������
	int cnt = 1;//������� 1 ��� ��� ����� ���� ������
	while(getline(in,line, '.')){//��������� �� �����������
		cnt = 1;
		for(unsigned i = 0; i < line.size(); ++i){//������� ����� ����������
			//���� ��� ���� ����������
			if(!((line[i] >= '0' && line[i] <= '9') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))){
				 ++cnt;
			}
		}
		if(cnt > max){ //���� ������ �������������
			max = cnt;
			ss.clear();//������� ����� ������
		    ss.str(std::string());
			ss << line << ".\n";	//������� � �����
		}
		else if(cnt == max){
			 ss << line << ".\n";	//������� � �����
		}
	}
	cout << ss.str();// ������� �����������
	in.close();//��������� ����										   
	system("pause>>void");
}