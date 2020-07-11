#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

double median(vector<double> vec) {
	if (vec.size() == 0) {
		throw domain_error("empty vector supplied to median()");
	}
	sort(vec.begin(), vec.end());
	vector<double>::size_type mid = vec.size() / 2;
	return vec.size() % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}