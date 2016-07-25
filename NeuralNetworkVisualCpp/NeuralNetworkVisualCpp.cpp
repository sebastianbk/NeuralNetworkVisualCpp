#include "stdafx.h"
#include "Net.h"
#include "Neuron.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net neuralNet(topology);

	std::vector<double> inputVals;
	neuralNet.feedForward(inputVals);

	std::vector<double> targetVals;
	neuralNet.backProp(targetVals);

	std::vector<double> resultVals;
	neuralNet.getResults(resultVals);

    return 0;
}

