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
		cout << "NNVC++ requires a minimum 6 command-line arguments:" << endl;
		cout << "  pathToInputValuesFile" << endl;
		cout << "  pathToTargetValuesFile" << endl;
		cout << "  activationFunction (sig or tanh)" << endl;
		cout << "  numInputNeurons" << endl;
		cout << "  numHiddenNeurons (in case of a one-layer network)" << endl;
		cout << "  numOutputNeurons";

		return 1;
	}

	string inputValuesFile = argv[1];
	string targetValuesFile = argv[2];
	TrainingData* trainingData = new TrainingData(inputValuesFile, targetValuesFile);

	if (argv[3] == "sig")
	{
		Functions::activationFunction = &Functions::sigmoidFunction;
		Functions::activationFunctionDerivative = &Functions::sigmoidFunctionDerivative;
	}

	vector<unsigned> topology;
	cout << "Topology:";
	for (int i = 4; i < argc; i++)
	{
		istringstream ss(argv[i]);
		unsigned x;
		if (ss >> x)
		{
			topology.push_back(x);
			cout << " " << x;
		}
	}
	cout << endl << endl;
	Net neuralNet(topology);

	vector<vector<double>> input, target;
	vector<vector<double>> input_n, target_n;

	while (!(*trainingData).isEof())
	{
		vector<double> inputVals, targetVals;

		auto numInputVals = (*trainingData).retrieveInputVals(inputVals);
		auto numTargetVals = (*trainingData).retrieveTargetVals(targetVals);

		if (numInputVals != topology[0] || numTargetVals != topology.back())
			continue;

		input.push_back(inputVals);
		target.push_back(targetVals);
	}

	delete trainingData;

	input_n = Functions::normalizeVals(input);
	target_n = Functions::normalizeVals(target);

	if (input.size() == target.size())
	{
		for (unsigned i = 0; i < input.size(); i++)
		{
			cout << endl << "Pass " << i << endl;

			vector<double>& inputVals = input[i];
			vector<double>& targetVals = target[i];
			vector<double>& inputVals_n = input_n[i];
			vector<double>& targetVals_n = target_n[i];
			vector<double> resultVals;

			neuralNet.feedForward(inputVals_n);
			neuralNet.getResults(resultVals);

			cout << "in=\t";
			Functions::showVectorVals(inputVals);
			cout << endl;

			cout << "in_n=\t";
			Functions::showVectorVals(inputVals_n);
			cout << endl;

			cout << "out=\t";
			Functions::showVectorVals(resultVals);
			cout << endl;

			cout << "tar=\t";
			Functions::showVectorVals(targetVals);
			cout << endl;

			cout << "tar_n=\t";
			Functions::showVectorVals(targetVals_n);
			cout << endl;

			assert(targetVals.size() == topology.back());

			neuralNet.backProp(targetVals_n);

			cout << "RMS deviation: " << neuralNet.getRmsDeviation() << endl;
			cout << "Net recent average error: " << neuralNet.getRecentAverageError() << endl;
		}

		cout << endl << "Done!" << endl;
	}
	else
	{
		cout << "Input file and target output file aren't of the same size." << endl;
	}

    return 0;
}