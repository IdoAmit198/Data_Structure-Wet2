#include "HashTable.h"
#include <iostream>

HashTable::HashTable(): current_size(0), array(INITAL_SIZE) {}

Course* HashTable::Find (const Course& course) 
{
    LinkedList<Course>& coursesList=array[(course.getCourseID())%(array.getSize())];
    for(LinkedList<Course>::iterator it=coursesList.begin(); it!=coursesList.end(); it++)
    {
        if((*it)==course)
        {
            return &(*it);
        }
    }
    return NULL;
}

void HashTable::Add (const Course& course) 
{
    if (!Find(course))
    {
        current_size++;
        if(current_size==getSize())
        {
            RefactorSizeArray(2);
        }
        array[(course.getCourseID())%getSize()].insert(course);
    }
}

void HashTable::Remove (const Course& course)
{
    if (Find(course))
    {
        array[course.getCourseID()%getSize()].removeByData(course);
        current_size--;
        if(4*current_size<=getSize() && getSize()>4)
        {
            RefactorSizeArray(0.5);
        }
    }
}

int HashTable::getSize() const
{
    return array.getSize();
}

void HashTable::RefactorSizeArray(const double factor)
{
    int new_size=getSize()*factor;
    Array<LinkedList<Course>> new_array(new_size);
    for(Array<LinkedList<Course>>::iterator it = array.begin();it!=array.end();it++)
    {
        for(LinkedList<Course>::iterator list_it=(*it).begin(); list_it!=(*it).end();list_it++)
        {
            new_array[(*list_it).getCourseID()%new_size].insert(*list_it);
        }
    }
    array=new_array;
}