#pragma once
#include "Neuron.h"
#include <vector>

class Net
{
	typedef std::vector<Neuron> Layer;

private:
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor = 100.0;
	std::vector<Layer> m_layers;

public:
	Net(const std::vector<unsigned>& topology);
	void feedForward(const std::vector<double>& inputVals);
	void backProp(const std::vector<double>& targetVals);
	void getResults(std::vector<double>& resultVals) const;
	double getRecentAverageError(void) const { return m_recentAverageError; }
	double getRmsDeviation(void) const { return m_error;  }
};