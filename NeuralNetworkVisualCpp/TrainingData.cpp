#include "stdafx.h"
#include "TrainingData.h"
#include <fstream>
#include <sstream>

using namespace std;

TrainingData::TrainingData(const string & inputValesFilePath, const std::string& targetValesFilePath)
{
	m_trainingInputValuesFile.open(inputValesFilePath.c_str());
	m_trainingTargetValuesFile.open(targetValesFilePath.c_str());
}

TrainingData::~TrainingData()
{
	m_trainingInputValuesFile.close();
	m_trainingTargetValuesFile.close();
}

unsigned TrainingData::retrieveInputVals(vector<double>& inputVals)
{
	inputVals.clear();

	string line;
	getline(m_trainingInputValuesFile, line);
	stringstream ss(line);

	double value;
	while (ss >> value)
	{
		inputVals.push_back(value);
	}

	return inputVals.size();
}

unsigned TrainingData::retrieveTargetVals(vector<double>& targetOutputVals)
{
	targetOutputVals.clear();

	string line;
	getline(m_trainingTargetValuesFile, line);
	stringstream ss(line);

	double value;
	while (ss >> value)
	{
		targetOutputVals.push_back(value);
	}

	return targetOutputVals.size();
}
