/** 
* @file main.cpp
* @brief Главный модуль программы для стеганографического преобрзования.
*/
#include "Steganography.h"

int main()
{
    setlocale(LC_ALL, "ru");
    
	try{
		int key = 2;
		
		Steganography encryption;
		
		string container = "";
		string messag = "";
		
		cout << "Если вы хотите скрыть сообщение, введите 1" << endl;
		cout << "Если вы хотите извлечь сообщение, введите 0" << endl;
		
		cin >> key;
			
		if (key == 1)
		{
			cout << "Введите файл-контейнер: " << endl;
			cin >> container;
			
			cout << "Введите файл-сообщение: " << endl;
			cin >> messag;
			encryption.concealment(container, messag);
			}
			
		else
		{
			cout << "Введите файл-контейнер: " << endl;
			cin >> container;
			encryption.extraction(container);
		}
	}
	catch (const error_proj & e) {
		std::cerr << e.what() << std::endl;
	}
	
    return 0;
}
