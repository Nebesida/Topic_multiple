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
		std::cout << "���������� ������ ���� ������ 0!" << std::endl;
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
	output << "�������� �����: " << c.getCourseName() << std::endl
		<< "�������� ����: " << c.getTopicName() << std::endl
		<< "���������� ����� � ����: " << c.getTasksCount() << std::endl
		<< "���������� ������ � ����: " << c.getLectsCount() << std::endl
		<< "������������ ��������: " << c._standart << std::endl
		<< "_____________________________________________" << std::endl;
	return output;
}

void CPP::readFromConsole()
{
	ITopic::readFromConsole();
	std::cout << "������� ���������� ������ � ����: ";
	int lectsCount; std::cin >> lectsCount; setLectsCount(lectsCount);
	std::cout << "������� ������������ ������: "; std::cin >> _standart;
}
void CPP::display()
{
	ITopic::display();
	std::cout << "���������� ������ � ����: " << getLectsCount() << std::endl
		<< "������������ ��������: " << _standart << std::endl;
}
void CPP::writeToFile()
{
	std::ofstream out;
	out.open("Topic.txt", std::ios::app);
	if (out.is_open())
	{
		out << "�������� �����: " << getCourseName() << std::endl
			<< "�������� ����: " << getTopicName() << std::endl
			<< "���������� ����� � ����: " << getTasksCount() << std::endl
			<< "���������� ������ � ����: " << getLectsCount() << std::endl
			<< "������������ ��������: " << _standart << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}