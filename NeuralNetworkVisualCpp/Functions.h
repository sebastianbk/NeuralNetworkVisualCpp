#pragma once
#include <functional>
#include <vector>

using namespace std;

typedef double(*funcptr)(double&);

namespace Functions
{
	vector<vector<double>> normalizeVals(vector<vector<double>>& values);
	void showVectorVals(const vector<double>& v);
	string toStrMaxDecimals(const double& value, const int& decimals);
	vector<vector<double>> transpose(const vector<vector<double>>& values);

	static double hyperbolicTangentFunction(double& value) { return tanh(value); };
	static double hyperbolicTangentFunctionDerivative(double& value) { return 1.0 - value * value; };
	static double sigmoidFunction(double& value) { return 1.0 / (1.0 + exp(-1.0 * value)); };
	static double sigmoidFunctionDerivative(double& value) { return exp(value) / ((1 + exp(value)) * (1 + exp(value))); };

	static funcptr activationFunction = &hyperbolicTangentFunction;
	static funcptr activationFunctionDerivative = &hyperbolicTangentFunctionDerivative;
}