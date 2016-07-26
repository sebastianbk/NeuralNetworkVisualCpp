#pragma once
#include <fstream>
#include <vector>

class TrainingData
{
public:
	TrainingData(const std::string& inputValesFilePath, const std::string& targetValesFilePath);
	virtual ~TrainingData();
	bool isEof(void) const { return m_trainingInputValuesFile.eof() || m_trainingTargetValuesFile.eof(); };
	unsigned retrieveInputVals(std::vector<double>& inputVals);
	unsigned retrieveTargetVals(std::vector<double>& targetOutputVals);

private:
	std::ifstream m_trainingInputValuesFile;
	std::ifstream m_trainingTargetValuesFile;
};