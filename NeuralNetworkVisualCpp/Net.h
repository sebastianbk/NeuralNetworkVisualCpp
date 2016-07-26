#pragma once
#include "Neuron.h"
#include <vector>

typedef std::vector<Neuron> Layer;

class Net
{
private:
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
	std::vector<Layer> m_layers;

public:
	Net(const std::vector<unsigned>& topology);
	void feedForward(const std::vector<double>& inputVals);
	void backProp(const std::vector<double>& targetVals);
	void getResults(std::vector<double>& resultVals) const;
	double getRecentAverageError(void) const { return m_recentAverageError; }
};