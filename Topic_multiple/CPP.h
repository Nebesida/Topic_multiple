#pragma once
#include "ITopic.h"

class CPP : virtual public ITopic
{
public:
	CPP(std::string courseName, std::string topicName, int tasksCount, int lectsCount, int standart);
	CPP(int standart);
	CPP();

	~CPP();

	void setStandart(int standart);
	int getStandart();

	CPP operator++();
	CPP operator--();

	bool operator< (CPP other);
	bool operator> (CPP other);

	friend std::ostream& operator<< (std::ostream& output, CPP c);

	void readFromConsole();
	void display();
	void writeToFile();

private:
	int _standart;
};

