#include "Course.h"

    Course::Course(int course_id): course_id(course_id),num_of_lectures(0), lecture_times(){}

    int Course::getCourseID() const
    {
        return course_id;
    }

    int Course::getNumOfLectures() const
    {
        return num_of_lectures;
    }

    int Course::AddLecture()
    {
        lecture_times[num_of_lectures]=0;
        num_of_lectures++;
        return num_of_lectures-1;
    }

    DynamicArray& Course::getLectureTimes() 
    {
        return lecture_times;
    }
    
    bool Course::operator < (const Course& other) const
    {
        return course_id<other.course_id;
    }

    bool operator > (const Course& course1, const Course& course2)
    {
        return course2<course1;
    }
    
    bool operator == (const Course& course1, const Course& course2)
    {
        return !(course1>course2) && !(course1<course2);
    }

    bool operator != (const Course& course1, const Course& course2)
    {
        return !(course1==course2);
    }