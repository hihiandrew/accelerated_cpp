#include <numeric>
#include <vector>

using namespace std;

double average(const vector<double>& vec) {
	return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
}
