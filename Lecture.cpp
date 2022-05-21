#include "Lecture.h"
    Lecture::Lecture(const int course_id, const int lecture_id,
                    const int time): course_id(course_id), lecture_id(lecture_id), time(time){}
                    
    int Lecture::getCourseID() const
    {
        return course_id;
    }
    int Lecture::getLectureID() const
    {
        return lecture_id;
    }
    int Lecture::getTime() const
    {
        return time;
    }
    bool Lecture::operator < (const Lecture& other) const
    {
        if(time==other.time)
        {
            if(course_id==other.course_id)
            {
                return lecture_id>other.lecture_id;
            }
            else
            {
                return course_id>other.course_id;
            }
        }
        else
        {
            return time<other.time;
        }
    }

    bool operator > (const Lecture& lecture1, const Lecture& lecture2) 
    {
        return lecture2<lecture1;
    }
    bool operator == (const Lecture& lecture1, const Lecture& lecture2) 
    {
        return !(lecture1>lecture2) && !(lecture1<lecture2);
    }
    bool operator != (const Lecture& lecture1, const Lecture& lecture2) 
    {
        return !(lecture1==lecture2);
    }
