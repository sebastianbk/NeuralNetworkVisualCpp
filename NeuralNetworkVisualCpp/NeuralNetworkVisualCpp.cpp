#include "stdafx.h"
#include "Constants.h"
#include "Functions.h"
#include "Net.h"
#include "Neuron.h"
#include "TrainingData.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	cout << " _   _ _   ___      _______           " << endl;
	cout << "| \\ | | \\ | \\ \\    / / ____|_     _   " << endl;
	cout << "|  \\| |  \\| |\\ \\  / / |   _| |_ _| |_ " << endl;
	cout << "| . ` | . ` | \\ \\/ /| |  |_   _|_   _|" << endl;
	cout << "| |\\  | |\\  |  \\  / | |____|_|   |_|  " << endl;
	cout << "|_| \\_|_| \\_|   \\/   \\_____|          " << endl;
	cout << "" << endl;
	cout << "by Sebastian Brandes (https://github.com/sebastianbk)" << endl << endl;

	if (argc < 6)
	{
		cout << "NNVC++ requires minium 5 command-line arguments:" << endl;
		cout << "  pathToInputValuesFile" << endl;
		cout << "  pathToTargetValuesFile" << endl;
		cout << "  numInputNeurons" << endl;
		cout << "  numHiddenNeurons (in case of a one-layer network)" << endl;
		cout << "  numOutputNeurons";

		return 1;
	}

	string inputValuesFile = argv[1];
	string targetValuesFile = argv[2];
	TrainingData trainingData(inputValuesFile, targetValuesFile);

	vector<unsigned> topology;
	cout << "Topology:";
	for (int i = 3; i < argc; i++)
	{
		istringstream ss(argv[i]);
		unsigned x;
		if (ss >> x)
		{
			topology.push_back(x);
			cout << " " << x;
		}
	}
	cout << endl;
	Net neuralNet(topology);

	vector<double> inputVals, targetVals, resultVals;
	int trainingPass = 0;

	while (!trainingData.isEof())
	{
		++trainingPass;
		cout << endl << "Pass #" << trainingPass << endl;

		auto numInputVals = trainingData.retrieveInputVals(inputVals);
		auto numTargetVals = trainingData.retrieveTargetVals(targetVals);
		if (numInputVals != topology[0] || numTargetVals != topology.back())
			continue;

		neuralNet.feedForward(inputVals);
		cout << "Inputs: ";
		Functions::showVectorVals(inputVals);
		cout << endl;

		neuralNet.getResults(resultVals);
		cout << "Outputs: ";
		Functions::showVectorVals(resultVals);
		cout << endl;

		cout << "Targets: ";
		Functions::showVectorVals(targetVals);
		cout << endl;

		assert(targetVals.size() == topology.back());

		neuralNet.backProp(targetVals);

		cout << "Net recent average error: "
			<< neuralNet.getRecentAverageError() << endl;
	}

	cout << endl << "Done!" << endl;

    return 0;
}