#ifndef LECTURE_H
#define LECTURE_H

#include <memory>

//Class Lecture
//Implements a lecture,with lecture ID, course ID and time watched
class Lecture
{
    private:
        int course_id;
        int lecture_id;
        int time;

    public:
        Lecture() = default;

        /**
         * Lecture c'tor:
         * Creates a new Lecture with given parameters
         */
        Lecture(const int course_id,const int lecture_id,const int time=0);


        /**
        * getters: returns the wanted field
        */
        int getCourseID() const;
        int getLectureID() const;
        int getTime() const;

        /**
        * operator< 
        * 
        * @param:
        *       other - reference for other lecture to compare to
        * 
        * return: by comparing time (highest), then comparing course ID (lowest), then comparing lecture ID (lowest)
        */  
        bool operator < (const Lecture& other) const;

};
        /**
        * operator> 
        * 
        * @param:
        *       other - reference for other lecture to compare to
        * 
        * return: by comparing time (lowest), then comparing course ID (highest), then comparing lecture ID (highest)
        */  
        bool operator > (const Lecture& lecture1, const Lecture& lecture2) ;

        /**
        * operator == 
        * 
        * @param:
        *       other - reference for other lecture to compare to
        * 
        * return: true only if time, course ID and lecture ID is identical
        */  
        bool operator == (const Lecture& lecture1, const Lecture& lecture2) ;

        /**
        * operator != 
        * 
        * @param:
        *       other - reference for other lecture to compare to
        * 
        * return: false only if time, course ID and lecture ID is identical
        */  
        bool operator != (const Lecture& lecture1, const Lecture& lecture2) ;
        



#endif //LECTURE_H