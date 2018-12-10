#include "Order.hpp"
#include <iostream>
#define cnt 8		//количество счетов
#define SWAP(A, B) { Order o = A; A = B; B = o; } //меняем местами

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	Order orders[cnt];
	int checker;
	//меню
	while(true){
		cout << "\n1. Считать счета\n2. Вывести информацию\n";
		if(!(cin >> checker)){//если некорректный ввод, то пропускаем всё
		 continue;
		}  
		if(checker == 1){
			//считываем данные о поездах
			cout << "[№ плательщика] [№ получателя] [сумма]\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> orders[i];
				}	  //обрабатываем исключение
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//откатываем i назад для повторного ввода
				}
			}
			/*сортируем пузырьком по счёу плательщика*/
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
			cout << "Введите сумму: ";
			if(!(cin >> checker)){
				cout << "Сумма не валидна";
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
				cout << "Не найдено!";
			}
		}
	}

}
