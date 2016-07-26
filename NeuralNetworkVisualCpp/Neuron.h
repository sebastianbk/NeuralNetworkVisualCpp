#pragma once
#include "Connection.h"
#include <cstdlib>
#include <vector>

class Neuron
{
	typedef std::vector<Neuron> Layer;

private:
	unsigned m_myIndex;
	double m_outputVal;
	double m_gradient;
	std::vector<Connection> m_outputWeights;
	static double randomWeight(void) { return rand() / double(RAND_MAX); }

public:
	Neuron(unsigned numOutputs, unsigned myIndex);
	void feedForward(const Layer& prevLayer);
	double getOutputVal() const { return m_outputVal; };
	void setOutputVal(double outputVal);
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const Layer& nextLayer);
	void updateInputWeights(Layer& prevLayer);
	double sumDOW(const Layer& nextLayer) const;
};