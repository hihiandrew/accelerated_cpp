#include <stdexcept>
#include "loaders.h"

int nrand(RuleCollection::size_type size) {
	if (size <= 0 || size > RAND_MAX) {
		throw std::domain_error("size out of bounds");
	}

	int bucket_size = RAND_MAX / size;
	int idx;

	// to avoid seeded rand()
	static unsigned seed;
	seed += 256 * size;
	srand(seed);

	do idx = rand() / bucket_size;
	while (idx >= size); //if idx is out of range / >size, recalculate

	return idx;
}