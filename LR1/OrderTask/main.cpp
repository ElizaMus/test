#include "Order.hpp"
#include <iostream>
#define cnt 8		//���������� ������
#define SWAP(A, B) { Order o = A; A = B; B = o; } //������ �������

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	Order orders[cnt];
	int checker;
	//����
	while(true){
		cout << "\n1. ������� �����\n2. ������� ����������\n";
		if(!(cin >> checker)){//���� ������������ ����, �� ���������� ��
		 continue;
		}  
		if(checker == 1){
			//��������� ������ � �������
			cout << "[� �����������] [� ����������] [�����]\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> orders[i];
				}	  //������������ ����������
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//���������� i ����� ��� ���������� �����
				}
			}
			/*��������� ��������� �� ���� �����������*/
			int j, n = cnt;
			  do {
				int nn = 0;
				for (j = 1; j < n; ++j)
				  if (orders [j-1].NumberPayer() > orders[j].NumberPayer()) {
					SWAP( orders[j-1], orders[j] );
					nn = j;
				  }
				n = nn;
			  } while (n);
		}
		else if(checker == 2){
			cout << "������� �����: ";
			if(!(cin >> checker)){
				cout << "����� �� �������";
				continue;
			}
			int i = 0;
			for(; i < cnt; ++i){
				if(orders[i].Sum() == checker){
					cout << orders[i];
					break;
				}
			}
			if(i == cnt){
				cout << "�� �������!";
			}
		}
	}

}
