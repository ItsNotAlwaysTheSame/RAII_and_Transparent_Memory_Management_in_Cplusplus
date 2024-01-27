
#ifndef SORT_H
#define SORT_H
#include <algorithm>
#include "buffer.h"

#include <cstddef>
class int_sorted {
public :
int_sorted ( const int * source , size_t size ) ;
size_t size () const ;
void insert ( int value ) ;
const int *begin() const ;
const int *end() const ;
int_sorted merge ( const int_sorted &merge_with ) const ;
void selection_sort();
private:
int_buffer buffer;
};
int_sorted sorte(const int* begin, const int* end);
#endif 