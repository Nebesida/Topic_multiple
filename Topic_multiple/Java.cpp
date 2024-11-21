#include "Java.h"

Java::Java(std::string courseName, std::string topicName, int tasksCount, int lectsCount, std::string frameworkName) :
	ITopic(courseName, topicName, tasksCount, lectsCount), _frameworkName(correctAlpha(frameworkName)) {}
Java::Java(std::string frameworkName) : _frameworkName(correctAlpha(frameworkName)) {}
Java::Java() : Java("undefined", "undefined", 0, 0, "undefined") {}

Java::~Java() {}

void Java::setFrameworkName(std::string frameworkName) {this->_frameworkName = correctAlpha(frameworkName);}
std::string Java::getFrameworkName(){return _frameworkName;}

Java Java::operator++()
{
	setLectsCount(getLectsCount() + 1);
	return *this;
}

Java Java::operator--()
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

bool Java::operator< (Java other)
{
	return this->getLectsCount() < other.getLectsCount();
}

bool Java::operator> (Java other)
{
	return this->getLectsCount() > other.getLectsCount();
}

std::ostream& operator<<(std::ostream& output, Java j)
{
	setlocale(LC_ALL, "");
	output << "�������� �����: " << j.getCourseName() << std::endl
		<< "�������� ����: " << j.getTopicName() << std::endl
		<< "���������� ����� � ����: " << j.getTasksCount() << std::endl
		<< "���������� ������ � ����: " << j.getLectsCount() << std::endl
		<< "������������ ���������: " << j._frameworkName << std::endl
		<< "_____________________________________________" << std::endl;
	return output;
}

void Java::readFromConsole()
{
	ITopic::readFromConsole();
	std::cout << "������� ���������� ������ � ����: "; 
	int lectsCount; std::cin >> lectsCount; setLectsCount(lectsCount);
	std::cout << "������� ������������ ���������: "; std::cin >> _frameworkName;
}
void Java::display()
{
	ITopic::display();
	std::cout << "���������� ������ � ����: " << getLectsCount() << std::endl
		 << "������������ ���������: " << _frameworkName << std::endl;
}
void Java::writeToFile()
{
	std::ofstream out;
	out.open("Topic.txt", std::ios::app);
	if (out.is_open())
	{
		out << "�������� �����: " << getCourseName() << std::endl
			<< "�������� ����: " << getTopicName() << std::endl
			<< "���������� ����� � ����: " << getTasksCount() << std::endl
			<< "���������� ������ � ����: " << getLectsCount() << std::endl
			<< "������������ ���������: " << _frameworkName << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}