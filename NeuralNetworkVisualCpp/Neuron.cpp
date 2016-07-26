#include "stdafx.h"
#include "Constants.h"
#include "Functions.h"
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

void Neuron::feedForward(const Layer& prevLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = (*Functions::activationFunction)(sum);
}

void Neuron::setOutputVal(double outputVal)
{
	m_outputVal = outputVal;
}

void Neuron::calcHiddenGradients(const Layer& nextLayer)
{
	double dow = sumDOW(nextLayer);
	m_gradient = dow * (*Functions::activationFunctionDerivative)(m_outputVal);
}

void Neuron::calcOutputGradients(double targetVal)
{
	double delta = targetVal - m_outputVal;
	m_gradient = delta * (*Functions::activationFunctionDerivative)(m_outputVal);
}

void Neuron::updateInputWeights(Layer& prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); n++)
	{
		Neuron& neuron = prevLayer[n];

		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight = Constants::eta * neuron.getOutputVal() * m_gradient + Constants::alpha * oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}

double Neuron::sumDOW(const Layer& nextLayer) const
{
	double sum = 0.0;

	for (unsigned n = 0; n < nextLayer.size() - 1; n++)
	{
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}
