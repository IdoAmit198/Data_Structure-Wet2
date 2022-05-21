#ifndef COURSESMANAGER_H
#define COURSESMANAGER_H

#include "AVL.h"
#include "LinkedList.h"
#include "HashTable.h"
#include "DynamicArray.h"
#include "Course.h"
#include "Lecture.h"
#include "library2.h"
/**
 * Class CoursesManager is the data structure we hold.
 * CoursesManager contains: 
 *                          lectures_tree, which hold CourseWithoutTime in its nodes.
 */
class CoursesManager
{
    private:
        AvlTree<Lecture> lectures_tree;
        HashTable courses_hash;
    
    public:
        /**
         * default c'tor for CoursesManager.
         * 
         * Complexity: O(1)
         */
        CoursesManager() = default;

        StatusType AddCourse(const int courseID);   
        StatusType RemoveCourse(const int courseID);
        StatusType AddClass(const int courseID, int* const classID);
        StatusType WatchClass(const int courseID,const int classID,const int time);
        StatusType TimeViewed(const int courseID,const int classID, int * timeViewed);
        StatusType GetIthWatchedClass(const int i, int* courseID, int* classID) const;
};

#endif //COURSESMANAGER_H