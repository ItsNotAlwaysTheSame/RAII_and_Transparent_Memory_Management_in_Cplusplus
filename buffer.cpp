#include "buffer.h"
#include <iostream>
int_buffer::int_buffer(size_t size)
    : m_beg(new int[size]), m_end(m_beg + size)
{//constructor, creates an array of integers of a specified size and initializes
//the member variables of the "int_buffer" class to point to the beginning and end of array
}



int_buffer::int_buffer(const int* source, size_t size) //copy elements from input array to internal array
    : int_buffer(size)
{//template< class InputIt, class OutputIt >
//OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
    std::copy(source, source + size, m_beg); //copy elements of source range [source, source+size] to internal array m_beg which stands for [m_beg, m_beg+size]
}

int_buffer::int_buffer(const int_buffer& rhs) //input: const reference to int_buffer object
    : int_buffer(rhs.begin(), rhs.size())
{
}


int_buffer::int_buffer(int_buffer&& rhs) 
    : m_beg(rhs.m_beg), m_end(rhs.m_end) 
{//moves internal array of input object to new object, transferring ownership of array
    rhs.m_beg = rhs.m_end = nullptr;
    //prevent memory leak, after the moving process "rhs" shouldn't be used as it doesn't have any valid resources
}

int_buffer& int_buffer::operator =(const int_buffer& rhs) //usng copy-and-swap idiom
{ //copy values from input objet's array to new array with same size 
    int_buffer tmp(rhs); //create temporary int_buffer
    std::swap(m_beg, tmp.m_beg);
    std::swap(m_end, tmp.m_end);
    return *this; //reference to the current object
}

int_buffer& int_buffer::operator =(int_buffer&& rhs)
{//only moves the ownership from rhs to the current object (*this)
    std::swap(m_beg, rhs.m_beg);
    std::swap(m_end, rhs.m_end);
    return *this;
}

int& int_buffer::operator [](size_t index)
{
    return m_beg[index];//Since the function is non-const, it can be used to modify the values of the int_buffer object.
}

const int& int_buffer::operator [](size_t index) const
{
    return m_beg[index];
}

size_t int_buffer::size() const
{
    return m_end - m_beg;
}
int_buffer::~ int_buffer () 
{
    if (m_beg!= nullptr)
    {
        delete[] m_beg;
    }
    
}

int * int_buffer::begin () 
{
    return m_beg;
}
int * int_buffer::end () 
{
    return m_end;
}
const int * int_buffer::begin () const 
{
    return m_beg;
}
const int * int_buffer::end () const 
{
    return m_end;
}
