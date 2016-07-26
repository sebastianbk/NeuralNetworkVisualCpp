#include "stdafx.h"
#include "Functions.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace Functions
{
	vector<vector<double>> normalizeVals(vector<vector<double>>& values)
	{
		vector<vector<double>> values_t = transpose(values);

		for (unsigned i = 0; i < values_t.size(); i++)
		{
			vector<double>& v = values_t[i];
			auto result = minmax_element(v.begin(), v.end());
			auto minVal = v[result.first - v.begin()];
			auto maxVal = v[result.second - v.begin()];

			for (unsigned j = 0; j < values.size(); j++)
			{
				values_t[i][j] = (values_t[i][j] - minVal) / (maxVal - minVal);
			}
		}

		return transpose(values_t);
	}

	vector<vector<double>> transpose(const vector<vector<double>>& data)
	{
		vector<vector<double>> result(data[0].size(), vector<double>(data.size()));

		for (unsigned i = 0; i < data[0].size(); i++)
		{
			for (unsigned j = 0; j < data.size(); j++)
			{
				result[i][j] = data[j][i];
			}
		}

		return result;
	}

	void showVectorVals(const vector<double>& v)
	{
		for (unsigned i = 0; i < v.size(); i++)
		{
			if (i > 0)
				cout << "\t";

			cout << toStrMaxDecimals(v[i], 1);
		}
	}

	string toStrMaxDecimals(const double& value, const int& decimals)
	{
		ostringstream ss;
		ss << fixed << setprecision(decimals) << value;
		string s = ss.str();
		if (decimals > 0 && s[s.find_last_not_of('0')] == '.') {
			s.erase(s.size() - decimals + 1);
		}
		return s;
	}
}