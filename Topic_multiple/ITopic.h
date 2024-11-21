#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "anyTopic.h"

using namespace anyTopic;

class ITopic
{
public:
	ITopic(std::string courseName, std::string topicName, int tasksCount, int lectsCount);
	ITopic(std::string courseName, std::string topicName, int tasksCount);
	ITopic();

	virtual ~ITopic();

	void setCourseName(std::string courseName);
	std::string getCourseName();
	void setTopicName(std::string topicName);
	std::string getTopicName();
	void setLectsCount(int lectsCount);
	int getLectsCount();
	void setTasksCount(int tasksCount);
	int getTasksCount();

	virtual void readFromConsole() = 0;
	virtual void display();
	virtual void writeToFile();

private:
	std::string _courseName;
	std::string _topicName;
	int _tasksCount;
	int _lectsCount;
};