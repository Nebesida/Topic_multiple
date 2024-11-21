#pragma once
#include "CPP.h"
#include "Java.h"
#include "ITopic.h"

class Practic : public CPP, Java
{
public:
	Practic(std::string courseName, std::string topicName, int tasksCount, 
		std::string frameworkName, int standart, std::string usingIDE);
	Practic();

	~Practic();

	void setUsingIDE(std::string usingIDE);
	std::string getUsingIDE();

	Practic operator++();
	Practic operator--();

	bool operator< (Practic other);
	bool operator> (Practic other);

	friend std::ostream& operator<< (std::ostream& output, Practic t);

	void readFromConsole();
	void display();
	void writeToFile();

private:
	std::string _usingIDE;
};