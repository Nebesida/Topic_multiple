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
		std::cout << "Количество лекций темы меньше 0!" << std::endl;
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
	output << "Название курса: " << j.getCourseName() << std::endl
		<< "Название темы: " << j.getTopicName() << std::endl
		<< "Количество задач в теме: " << j.getTasksCount() << std::endl
		<< "Количество лекций в теме: " << j.getLectsCount() << std::endl
		<< "Используемый фреймворк: " << j._frameworkName << std::endl
		<< "_____________________________________________" << std::endl;
	return output;
}

void Java::readFromConsole()
{
	ITopic::readFromConsole();
	std::cout << "Введите количество лекций в теме: "; 
	int lectsCount; std::cin >> lectsCount; setLectsCount(lectsCount);
	std::cout << "Введите используемый фреймворк: "; std::cin >> _frameworkName;
}
void Java::display()
{
	ITopic::display();
	std::cout << "Количество лекций в теме: " << getLectsCount() << std::endl
		 << "Используемый фреймворк: " << _frameworkName << std::endl;
}
void Java::writeToFile()
{
	std::ofstream out;
	out.open("Topic.txt", std::ios::app);
	if (out.is_open())
	{
		out << "Название курса: " << getCourseName() << std::endl
			<< "Название темы: " << getTopicName() << std::endl
			<< "Количество задач в теме: " << getTasksCount() << std::endl
			<< "Количество лекций в теме: " << getLectsCount() << std::endl
			<< "Используемый фреймворк: " << _frameworkName << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}