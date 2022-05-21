#include "CoursesManager.h"

    StatusType CoursesManager::AddCourse(const int courseID)
    {
        try{
            if (courseID <= 0)
            {
                return INVALID_INPUT;
            }
            Course new_course(courseID);
            Course* course_ptr = courses_hash.Find(new_course);
            if(course_ptr!=NULL)
                return FAILURE;
            courses_hash.Add(new_course);
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
    }

    StatusType CoursesManager::RemoveCourse(const int courseID)
    {
        try{
            if (courseID <= 0)
            {
                return INVALID_INPUT;
            }
            Course new_course(courseID);
            Course* course_ptr = courses_hash.Find(new_course);
            if(course_ptr==NULL)
                return FAILURE;
            DynamicArray& lecture_array=course_ptr->getLectureTimes();
            int num_of_lectures=course_ptr->getNumOfLectures();
            for(int i=0;i<num_of_lectures;i++)
            {
                if(lecture_array[i]>0)
                {
                    Lecture lecture_to_remove(courseID,i,lecture_array[i]);
                    lectures_tree.remove(lecture_to_remove);
                }
            }
            courses_hash.Remove(new_course);
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
    }
        
    StatusType CoursesManager::AddClass(const int courseID, int* const classID)
    {
        try
        {
            if (courseID <= 0)
            {
                return INVALID_INPUT;
            }
            Course new_course(courseID);
            Course* course_ptr = courses_hash.Find(new_course);
            if(course_ptr==NULL)
                return FAILURE;
            *(classID)=course_ptr->AddLecture();
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
    }

    StatusType CoursesManager::WatchClass(const int courseID,const int classID,const int time)
    {
        try{
            if (time<=0 || classID<0 || courseID<=0)
            {
                return INVALID_INPUT;
            }
            Course new_course(courseID);
            Course* course_ptr = courses_hash.Find(new_course);
            if(course_ptr==NULL)
                return FAILURE;
            if (classID >= course_ptr->getNumOfLectures())
            {
                return INVALID_INPUT;
            }
            DynamicArray& lecture_array=course_ptr->getLectureTimes();
            if(lecture_array[classID]>0)
            {
                Lecture lecture_to_remove(courseID,classID,lecture_array[classID]);
                lectures_tree.remove(lecture_to_remove);
            }
            lecture_array[classID] += time;
            Lecture new_lecture(courseID,classID,lecture_array[classID]);
            lectures_tree.insert(new_lecture);
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }  
    }

    StatusType CoursesManager::TimeViewed(const int courseID, const int classID, int * timeViewed)
    {
        try{
            if ( classID<0 || courseID<=0)
            {
                return INVALID_INPUT;
            }
            Course new_course(courseID);
            Course* course_ptr = courses_hash.Find(new_course);
            if(course_ptr==NULL)
                return FAILURE;
            if (classID >= course_ptr->getNumOfLectures())
            {
                return INVALID_INPUT;
            }
            *(timeViewed)=(course_ptr->getLectureTimes())[classID];
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
    }

    StatusType CoursesManager::GetIthWatchedClass(const int i, int* courseID, int* classID) const
    {
        try{
            if (i <= 0)
            {
                return INVALID_INPUT;
            }
            const Lecture* lecture_ptr =lectures_tree.Select(i);
            if (!lecture_ptr)
            {
                return FAILURE;
            }
            *(courseID)=lecture_ptr->getCourseID();
            *(classID)=lecture_ptr->getLectureID();
            return SUCCESS;
        }
        catch(std::bad_alloc& e)
        {
            return ALLOCATION_ERROR;
        }
    }