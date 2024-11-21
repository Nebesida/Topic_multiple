#include <iostream>
#include <fstream>
#include "Practic.h"

int main()
{
	CPP* sep = new CPP;
	Java* oct = new Java;
	CPP* nov = new CPP;
	Java* dec = new Java;
	Practic* march = new Practic;

	ITopic** arr = new ITopic * [5] {sep, oct, nov, dec, march};

	bool start = true;
	do
	{
		setlocale(LC_ALL, "");
		std::cout
			<< "Выберите тему курса: " << std::endl
			<< "1 = сентябрь" << std::endl << "2 = октябрь" << std::endl
			<< "3 = ноябрь" << std::endl << "4 = декабрь" << std::endl
			<< "5 = март" << std::endl << "0 = выход из программы" << std::endl;
		displaySeparator();

		char choice;
		std::cin >> choice;
		switch (choice)
		{
		case '1':
			arr[0]->readFromConsole();
			break;
		case '2':
			arr[1]->readFromConsole();
			break;
		case '3':
			arr[2]->readFromConsole();
			break;
		case '4':
			arr[3]->readFromConsole();
			break;
		case '5':
			arr[4]->readFromConsole();
			break;
		case '0':
			for (int i = 0; i < 5; ++i)
			{
				arr[i]->display();
				displaySeparator();
			}
			start = false;
			break;
		default:
			break;
		}
	} while (start);

	std::ofstream out("Topic.txt", std::ios::out | std::ios::trunc);
	out.close();

	for (int i = 0; i < 5; ++i)
	{
		arr[i]->writeToFile();
		std::cout << "Тема \"" << arr[i]->getTopicName() << "\" успешно записана в файл." << std::endl;
	}

	delete sep;
	delete oct;
	delete nov;
	delete dec;
	delete march;
	delete[] arr;

	return 0;
}