#include "CPP.h"

CPP::CPP(std::string courseName, std::string topicName, int tasksCount, int lectsCount, int standart) :
	ITopic(courseName, topicName, tasksCount, lectsCount), _standart(correctCount(standart)) {}
CPP::CPP(int standart) : _standart(correctCount(standart)) {}
CPP::CPP() : CPP("undefined", "undefined", 0, 0, 0) {}

CPP::~CPP() {}

void CPP::setStandart(int standart)
{
	this->_standart = correctCount(standart);
}

int CPP::getStandart()
{
	return _standart;
}

CPP CPP::operator++()
{
	setLectsCount(getLectsCount() + 1);
	return *this;
}

CPP CPP::operator--()
{
	setlocale(LC_ALL, "");
	if (getLectsCount() > 0)
	{
		setLectsCount(getLectsCount() - 1);
		return *this;
	}
	else
	{
		std::cout << "Количество лекций темы меньше 0!" << std::endl;
		return *this;
	}
}

bool CPP::operator< (CPP other)
{
	return this->getLectsCount() < other.getLectsCount();
}

bool CPP::operator> (CPP other)
{
	return this->getLectsCount() > other.getLectsCount();
}

std::ostream& operator<<(std::ostream& output, CPP c)
{
	setlocale(LC_ALL, "");
	output << "Название курса: " << c.getCourseName() << std::endl
		<< "Название темы: " << c.getTopicName() << std::endl
		<< "Количество задач в теме: " << c.getTasksCount() << std::endl
		<< "Количество лекций в теме: " << c.getLectsCount() << std::endl
		<< "Используемый стандарт: " << c._standart << std::endl
		<< "_____________________________________________" << std::endl;
	return output;
}

void CPP::readFromConsole()
{
	ITopic::readFromConsole();
	std::cout << "Введите количество лекций в теме: ";
	int lectsCount; std::cin >> lectsCount; setLectsCount(lectsCount);
	std::cout << "Введите используемую версию: "; std::cin >> _standart;
}
void CPP::display()
{
	ITopic::display();
	std::cout << "Количество лекций в теме: " << getLectsCount() << std::endl
		<< "Используемый стандарт: " << _standart << std::endl;
}
void CPP::writeToFile()
{
	std::ofstream out;
	out.open("Topic.txt", std::ios::app);
	if (out.is_open())
	{
		out << "Название курса: " << getCourseName() << std::endl
			<< "Название темы: " << getTopicName() << std::endl
			<< "Количество задач в теме: " << getTasksCount() << std::endl
			<< "Количество лекций в теме: " << getLectsCount() << std::endl
			<< "Используемый стандарт: " << _standart << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}