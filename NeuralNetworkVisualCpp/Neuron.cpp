#include "stdafx.h"
#include "Neuron.h"
#include <cmath>

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
	m_myIndex = myIndex;

	for (unsigned c = 0; c < numOutputs; c++)
	{
		m_outputWeights.push_back(Connection());

		m_outputWeights.back().weight = Neuron::randomWeight();
	}
}

Neuron::~Neuron()
{
}

double Neuron::eta = 0.15; // overall learning rate
double Neuron::alpha = 0.5; // momentum

double Neuron::transferFunction(double x)
{
	return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
	return 1 - x * x;
}

void Neuron::feedForward(const Layer& prevLayer)
{
	double sum = 0;

	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = transferFunction(sum);
}

void Neuron::setOutputVal(double outputVal)
{
	m_outputVal = outputVal;
}

void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - m_outputVal;
	m_gradient = delta * transferFunctionDerivative(m_outputVal);
}

void Neuron::calcHiddenGradients(const Layer& nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * transferFunctionDerivative(m_outputVal);
}

void Neuron::updateInputWeights(Layer & prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		Neuron& neuron = prevLayer[n];

		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight = eta * neuron.getOutputVal() * m_gradient + alpha * oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}

double Neuron::sumDOW(const Layer & nextLayer) const
{
	double sum = 0;

	for (unsigned n = 0; n < nextLayer.size() - 1; n++)
	{
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}
