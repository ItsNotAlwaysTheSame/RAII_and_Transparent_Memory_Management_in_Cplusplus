//#include "buffer.h"
#include "sort.h"
#include <iostream>
#include <random>
#include <chrono>

void f(int_buffer buf) {  
  // write values to buffer using non-const begin() and end()
  for (int* i = buf.begin(); i != buf.end(); ++i) {
    *i = i - buf.begin() + 1;
  }
  
  // print buffer contents using const begin() and end()
  //for (const int* i = buf.begin(); i != buf.end(); ++i) {
    //std::cout << *i << " ";
  //}
  //std::cout << std::endl;

  
}
void print(const int_sorted& so)
{
	for(const int* it = so.begin(); it != so.end(); it++)
	{
		std::cout << *it << ", ";
	}

	std::cout << '\n';
}



 
void selection_sort(int* begin, int* end) {
	//comparison-based algorithm that repeatedly finds the minimum
	// element in the unsorted part of the array and swaps it with the first element of the unsorted part.
  for (int* i = begin; i != end; ++i) {
    int* min = i;
    for (int* j = i + 1; j != end; ++j) {
      if (*j < *min) {
        min = j;
      }
    }
    std::swap(*i, *min);
  }
}


int main()
{

	f(int_buffer(10));
	

	int_buffer buff(10);


	std::mt19937 mt((std::random_device()()));
	std::uniform_int_distribution<int> dist(1, 100);

	for(int* it = buff.begin(); it != buff.end(); it++)
	{
		*it = dist(mt);
	}
	f(buff);
	//int_sorted
	puts("int_sorted:" );
	int_sorted sorted(buff.begin(), buff.size());
	int_sorted secondSorted = sorted;
	print(sorted);
	for(int i = 0; i < 10; i++)
	{
		sorted.insert(i);
	}
	// BigBuffer alokerar minne
    int_buffer bigBuffer(10000);
	int_sorted sortedel(bigBuffer.begin(), bigBuffer.size());
	for(auto pos = 0; pos < bigBuffer.size(); ++pos)
	{
		sortedel.insert(rand()%10);// rand() ;
	}
	auto stdBuffer = bigBuffer;

		puts("_______________________________________________________________________________________________");

	//first method called divide-and-conquer algorithm. has time complexity of O(n log n) in worst case,
	//requires additional memory to store the intermidiate sorted arrays
	auto beginMerge = std::chrono::high_resolution_clock::now();
	int_sorted srt= sorte(bigBuffer.begin(), bigBuffer.end()); 
	auto endMerge = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffMerge = endMerge - beginMerge;

	std::cout << "Merge took: " << diffMerge.count() << " s\n";

	//introsort algorithm by C++ standard library. 
	//hyprid algorithm that combines quicksort, heap sort, and inserion sort.
	//time complexity of O(n log n). requires additional memory to store stack of recursive calls.
		puts("_______________________________________________________________________________________________");

	auto beginStd = std::chrono::high_resolution_clock::now();
	std::sort(stdBuffer.begin(), stdBuffer.end()); //The sort() function uses a 3 fold 
	//hybrid sorting technique named Introsort. It is a combination of Quick Sort, Heap Sort, and Insertion Sort.
	// in ascending order
	auto endStd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffStd = endStd - beginStd;

	std::cout << "Standard took: " << diffStd.count() << " s\n";
	puts("_______________________________________________________________________________________________");

	//has time compexity of O(n^2) in worst case, no additional memory required, it only swaps
	auto beginSelect = std::chrono::high_resolution_clock::now();
	selection_sort(bigBuffer.begin(), bigBuffer.end());
	auto endSelect = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diffSelect = endSelect - beginSelect;

	std::cout << "Selection took: " << diffSelect.count() << " s\n";
    return 0;

 
  

}