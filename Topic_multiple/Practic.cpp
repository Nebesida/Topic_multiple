#include "Practic.h"

Practic::Practic(std::string courseName, std::string topicName, int tasksCount, std::string frameworkName, int standart, std::string usingIDE) :
	ITopic(courseName, topicName, tasksCount), Java(frameworkName), CPP(standart), _usingIDE(usingIDE) {}
Practic::Practic() : Practic("undefined", "undefined", 0, "undefined", 0, "undefined") {}
Practic::~Practic() {}

void Practic::setUsingIDE(std::string usingIDE) { this->_usingIDE = correctAlpha(usingIDE); }
std::string Practic::getUsingIDE() { return _usingIDE; }

Practic Practic::operator++()
{
	setTasksCount(getTasksCount() + 1);
	return *this;
}

Practic Practic::operator--()
{
	setlocale(LC_ALL, "");
	if (getTasksCount() > 0)
	{
		setTasksCount(getTasksCount() - 1);
		return *this;
	}
	else
	{
		std::cout << "���������� ������� ���� ������ 0!" << std::endl;
		return *this;
	}
}

bool Practic::operator< (Practic other)
{
	return this->getTasksCount() < other.getTasksCount();
}

bool Practic::operator> (Practic other)
{
	return this->getTasksCount() > other.getTasksCount();
}

std::ostream& operator<<(std::ostream& output, Practic p)
{
	setlocale(LC_ALL, "");
	output << "�������� �����: " << p.getCourseName() << std::endl
		<< "�������� ����: " << p.getTopicName() << std::endl
		<< "���������� ����� � ����: " << p.getTasksCount() << std::endl
		<< "������������ ���������: " << p.getFrameworkName() << std::endl
		<< "������������ ������: " << p.getStandart() << std::endl
		<< "������������ IDE: " << p._usingIDE << std::endl
		<< "_____________________________________________" << std::endl;
	return output;
}

void Practic::readFromConsole()
{
	ITopic::readFromConsole();
	std::cout << "������� ������������ ���������: "; 
	std::string frameworkName; std::cin >> frameworkName; setFrameworkName(frameworkName);
	std::cout << "������� ������������ ������: ";
	int standart; std::cin >> standart; setStandart(standart);
	std::cout << "������� ������������ IDE: "; std::cin >> _usingIDE;
}
void Practic::display()
{
	ITopic::display();
	std::cout << "������������ ���������: " << getFrameworkName() << std::endl
		<< "������������ ������: " << getStandart() << std::endl
		<< "������������ IDE: " << _usingIDE << std::endl;
}
void Practic::writeToFile()
{
	std::ofstream out;
	out.open("Topic.txt", std::ios::app);
	if (out.is_open())
	{
		out << "�������� �����: " << getCourseName() << std::endl
			<< "�������� ����: " << getTopicName() << std::endl
			<< "���������� ����� � ����: " << getTasksCount() << std::endl
			<< "������������ ���������: " << getFrameworkName() << std::endl
			<< "������������ ������: " << getStandart() << std::endl
			<< "������������ IDE: " << _usingIDE << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}
