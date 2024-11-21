#pragma once
#include "ITopic.h"
class Java : virtual public ITopic
{
public:
	Java(std::string courseName, std::string topicName, int tasksCount, int lectsCount, std::string frameworkName);
	Java(std::string frameworkName);
	Java();

	~Java();

	void setFrameworkName(std::string frameworkName);
	std::string getFrameworkName();

	Java operator++();
	Java operator--();

	bool operator< (Java other);
	bool operator> (Java other);

	friend std::ostream& operator<< (std::ostream& output, Java j);

	void readFromConsole();
	void display();
	void writeToFile();

private:
	std::string _frameworkName;
};