#ifndef GUARD_ch8_4_h
#define GUARD_ch8_4_h

int ch8_4();

template <class BiIter>
void reverse(BiIter first, BiIter last) {
	while (first != last) {
		BiIter temp = first;
		*first = *last;
		*last = *temp;
		++first; --last;
	}
}

#endif
