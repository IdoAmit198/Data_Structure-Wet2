#include "library2.h"
#include "CoursesManager.h"

void *Init()
{
    try{
        CoursesManager *DS = new CoursesManager ();
        return ( void *)DS;
    }
    catch(...)
    {
        return NULL;
    }
}

StatusType AddCourse (void *DS, int courseID)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)-> AddCourse(courseID);
}

StatusType RemoveCourse(void *DS, int courseID)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)-> RemoveCourse(courseID);
}

StatusType AddClass(void* DS, int courseID, int* classID)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager*)DS)->AddClass(courseID, classID);
}
StatusType WatchClass(void *DS, int courseID, int classID, int time)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)-> WatchClass (courseID, classID,time);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
        return ((CoursesManager *)DS)-> TimeViewed (courseID, classID,timeViewed);
}

StatusType GetIthWatchedClass(void* DS, int i, int* courseID, int* classID)
{
    if(DS==NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)-> GetIthWatchedClass (i, courseID,classID);
}

void Quit(void** DS)
{
    if (DS ==NULL || *DS ==NULL)
    {
        return;
    }
    delete (CoursesManager *)(*(DS));
    *DS=NULL;
}

