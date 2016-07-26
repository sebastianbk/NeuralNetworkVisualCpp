#include "stdafx.h"
#include "Functions.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Functions
{
	void normalizeVals(vector<double>& values)
	{
		auto minVal = min_element(begin(values), end(values));
		auto maxVal = max_element(begin(values), end(values));

		for (unsigned i = 0; i < values.size(); i++)
		{
			values[i] = (values[i] - *minVal) / (*maxVal - *minVal);
		}
	}

	void showVectorVals(const vector<double>& v)
	{
		for (unsigned i = 0; i < v.size(); i++)
		{
			if (i > 0)
				cout << " ";

			cout << v[i];
		}
	}
}