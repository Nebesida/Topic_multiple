#include "ITopic.h"

ITopic::ITopic(std::string courseName, std::string topicName, int tasksCount, int lectsCount) :
	_courseName(correctAlpha(courseName)), _topicName(correctAlpha(topicName)),
	_tasksCount(correctCount(tasksCount)), _lectsCount(correctCount(lectsCount)) {}
ITopic::ITopic(std::string courseName, std::string topicName, int tasksCount) :
	_courseName(correctAlpha(courseName)), _topicName(correctAlpha(topicName)),
	_tasksCount(correctCount(tasksCount)) {}
ITopic::ITopic() : ITopic("undefined", "undefined", 0, 0) {}

ITopic::~ITopic() {}

void ITopic::setCourseName(std::string courseName) { this->_courseName = correctAlpha(courseName); }
std::string ITopic::getCourseName() { return _courseName; }
void ITopic::setTopicName(std::string topicName) { this->_topicName = correctAlpha(topicName); }
std::string ITopic::getTopicName() { return _topicName; }
void ITopic::setLectsCount(int lectsCount) { this->_lectsCount = correctCount(lectsCount); }
int ITopic::getLectsCount() { return _lectsCount; }
void ITopic::setTasksCount(int tasksCount) { this->_tasksCount = correctCount(tasksCount); }
int ITopic::getTasksCount() { return _tasksCount; }

void ITopic::readFromConsole()
{
	setlocale(LC_ALL, "");
	std::cout << "Введите название курса: "; std::cin >> _courseName;
	std::cout << "Введите название темы: "; std::cin >> _topicName;
	std::cout << "Введите количество задач в теме: "; std::cin >> _tasksCount;
}
void ITopic::display()
{
	setlocale(LC_ALL, "");
	std::cout << "Название курса: " << _courseName << std::endl
		<< "Название темы: " << _topicName << std::endl
		<< "Количество задач в теме: " << _tasksCount << std::endl;
}
void ITopic::writeToFile() {}