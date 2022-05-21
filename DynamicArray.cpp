#include "DynamicArray.h"

DynamicArray::DynamicArray(int inital): current_size(0), array(INITAL_SIZE,inital) {}

int& DynamicArray::operator[] (const int index)
{
    if(array[index]==-1)
    {
        current_size++;
        if(current_size==getSize())
        {
            ExtendArray();
        }
    }
    return array[index];
}

const int& DynamicArray::operator[] (const int index) const
{
    return array[index];
}

int DynamicArray::getSize() const
{
    return array.getSize();
}

void DynamicArray::ExtendArray()
{
    int new_size=getSize()*2;
    
    Array<int> new_array(new_size,-1);
    Array<int>::iterator new_it = new_array.begin();
    for(Array<int>::iterator it = array.begin(); it !=array.end(); it++, new_it++)
    {
        *new_it = *it;
    }
    array=new_array;
}