#include "CoursesManager.h"
#include <stdlib.h>
#include <iostream>
#include <cassert>

using namespace std;


int main()
{
    CoursesManager boom;

    /**
     * AddCourse tests
     */
    assert(boom.AddCourse(-2)==INVALID_INPUT);
    assert(boom.AddCourse(0)==INVALID_INPUT);
    assert(boom.AddCourse(133)==SUCCESS);
    assert(boom.AddCourse(133)==FAILURE);
    int* i = new int;

    /**
     * RemoveCourse tests
     */
    assert(boom.RemoveCourse(-3)==INVALID_INPUT);
    assert(boom.RemoveCourse(0)==INVALID_INPUT);
    assert(boom.RemoveCourse(13)==FAILURE);
    assert(boom.RemoveCourse(133)==SUCCESS);
    assert(boom.AddCourse(133)==SUCCESS);

    /**
     * AddClass tests
     */
    assert(boom.AddClass(-3,i)==INVALID_INPUT);
    assert(boom.AddClass(0,i)==INVALID_INPUT);
    assert(boom.AddClass(1253,i)==FAILURE);
    assert(boom.AddClass(133,i)==SUCCESS);

    /**
     * WatchClass tests
     */
    assert(boom.WatchClass(-4,2,2)==INVALID_INPUT);
    assert(boom.WatchClass(0,2,2)==INVALID_INPUT);
    assert(boom.WatchClass(2,-5,2)==INVALID_INPUT);
    assert(boom.WatchClass(5,2,0)==INVALID_INPUT);
    assert(boom.WatchClass(0,2,-3)==INVALID_INPUT);
    assert(boom.WatchClass(133,1,2)==INVALID_INPUT);
    assert(boom.WatchClass(133,150,2)==INVALID_INPUT);
    assert(boom.WatchClass(133,0,2)==SUCCESS);
    assert(boom.WatchClass(15,0,2)==FAILURE);
    assert(boom.WatchClass(133,1,2)==INVALID_INPUT);
    assert(boom.WatchClass(133,-2,2)==INVALID_INPUT);
    assert(boom.WatchClass(133,0,-5)==INVALID_INPUT);

    /**
     * TimeViewed tests
     */
    assert(boom.TimeViewed(-3,2,i)==INVALID_INPUT);
    assert(boom.TimeViewed(0,2,i)==INVALID_INPUT);
    assert(boom.TimeViewed(5,-2,i)==INVALID_INPUT);
    assert(boom.TimeViewed(133,-3,i)==INVALID_INPUT);
    assert(boom.TimeViewed(133,1,i)==INVALID_INPUT);
    assert(boom.TimeViewed(1324,0,i)==FAILURE);
    assert(boom.TimeViewed(133,0,i)==SUCCESS);
    assert(*i==2);
    /**
     * GetIthWatchedClass tests
     */
    int* course=new int;
    int* lecture=new int;
    assert(boom.GetIthWatchedClass(-3,course,lecture)==INVALID_INPUT);
    assert(boom.GetIthWatchedClass(0,course,lecture)==INVALID_INPUT);
    assert(boom.GetIthWatchedClass(3,course,lecture)==FAILURE);
    assert(boom.GetIthWatchedClass(1,course,lecture)==SUCCESS);
    assert(*course==133);
    assert(*lecture==0);
    /**free for my brothers*/
    delete i;
    delete course;
    delete lecture;
    assert(1==0);
    return 0;
}