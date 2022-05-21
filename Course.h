#ifndef COURSE_H
#define COURSE_H

#include "DynamicArray.h"


/**
 * Class Course.
 * Every course had unique id number, and counter for how many lectures which hasn't wacthed yet.
 * Course holds lecture_times, array to represent watched time for every lecture.
 * Course holds node_ptrs_array, array of pointers to nodes of lectures in the correct list
 * (of zero time or more than zero time watched).
 */
class Course
{
private:
        int course_id;
        int num_of_lectures;
        DynamicArray lecture_times;

public:
        /**
         * c'tor for Course with given id. Used for implementation of other functions in CourserManager.
         */
        explicit Course(int course_id=-1);

        /**
         * return unique course_id number.
         */
        int getCourseID() const;

        /**
         * return unique num_of_lectures number.
         */
        int getNumOfLectures() const;

        int AddLecture();

        /**
         * return reference for "lecture_times" array.
         */
        DynamicArray& getLectureTimes();

        /**
        * operator< 
        * 
        * @param:
        *       other - reference for other Course to compare to.
        * 
        * return: by comparing course ID (lowest)
        */  
        bool operator < (const Course& other) const;
};
        /**
        * operator>
        * 
        * @param:
        *       other - reference for other Course to compare to.
        * 
        * return: by comparing course ID (highest)
        */  
        bool operator > (const Course& course1, const Course& course2);

        /**
        * operator == 
        * 
        * @param:
        *       other - reference for other Course to compare to.
        * 
        * return: true only if course ID is identical
        */  
        bool operator == (const Course& course1, const Course& course2);

        /**
        * operator != 
        * 
        * @param:
        *       other - reference for other Course to compare to.
        * 
        * return: false only if course ID is identical
        */  
        bool operator != (const Course& course1, const Course& course2);
        


#endif //COURSE_H