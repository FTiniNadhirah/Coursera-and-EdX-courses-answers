#include <iostream>
#include <vector>

using namespace std;

template <class T>
T sum(const vector<T> &data)
{
	T result = 0;

	for (int i=0; i<data.size(); i++)
	{
		result += data[i];
	}

	return result;
}

int main()
{
	vector<double> vec;
	vec.push_back(1);
	vec.push_back(5.5);

	cout << sum(vec) << endl;

	return 0;
}
