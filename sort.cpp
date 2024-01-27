#include "sort.h"
int_sorted sorte(const int* begin, const int* end) {
  if (begin == end) {
    return int_sorted(nullptr, 0);
  }
  if (begin == end - 1) {
    return int_sorted(begin, 1);
  }
  ptrdiff_t half = (end - begin) / 2;
  const int* mid = begin + half;
  //recursively calls sorte method with left half of input array.
  //recursively creates two new int_sorted objects, which stores sorted copies of left and right halves of input array

  return sorte(begin, mid).merge(sorte(mid, end));
}
int_sorted::int_sorted(const int *source, size_t size)
    : buffer(source, size)
{//template< class RandomIt >
//void sort( RandomIt first, RandomIt last );
//ascending order, 
if (size>1)
{
	buffer= sorte(source, source+size).buffer;	

}

}

size_t int_sorted::size () const 
{
    return buffer.size();
}


void int_sorted::insert(int value)
{
	*this= merge(int_sorted(&value, 1));
}


const int * int_sorted::begin() const 
{
    return buffer.begin();
}
const int * int_sorted::end() const 
{
    return buffer.end();
}


int_sorted int_sorted::merge(const int_sorted & merge_with) const
{
    int_buffer mergedBuffer(buffer.size() + merge_with.size());
	const int* aIter = buffer.begin();
	const int* bIter = merge_with.begin();
	const int* aEnd = buffer.end();
	const int* bEnd = merge_with.end();
	int* mergedIter = mergedBuffer.begin();

	while(aIter != aEnd && bIter != bEnd)
	{
		if(*aIter < *bIter)
		{
			*mergedIter = *aIter;
			++mergedIter, ++aIter;
		}
		else
		{
			*mergedIter = *bIter;
			++mergedIter, ++bIter;
		}
	}

	while(aIter != aEnd)
	{
		*mergedIter = *aIter;
		++mergedIter, ++aIter;
	}

	while(bIter != bEnd)
	{
		*mergedIter = *bIter;
		++mergedIter, ++bIter;
	}

	int_sorted sorted(nullptr, 0);
	sorted.buffer = std::move(mergedBuffer);

	return sorted;
}

