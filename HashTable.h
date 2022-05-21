#ifndef Hash_Table_H
#define Hash_Table_H

#include "Array.h"
#include "LinkedList.h"
#include "Course.h"

class HashTable
{
    private:
        const int INITAL_SIZE=4;
        int current_size;
        Array<LinkedList<Course>> array;

        void RefactorSizeArray(const double factor);
        /**
         * return size of Hash Table.
         */
        int getSize() const;
        
    public:
        /**
         * Default c'tor for Hash Table object.
         */
        HashTable();
        
        /**
         * copy c'tor for Hash Table object.
         * 
         * @param:
         *      other - Reference for another Hash Table object, from whom to initialize new Hash Table fields.
         */
        HashTable(const HashTable& other)=default;

        /**
         * d'tor for Hash Table. deallocate data of Hash Table.
         */
        ~HashTable()=default;
        
        /**
         * At for Hash Table
         * 
         * @paaram:
         *      course_id - required course id to access in the Hash Table.
         * 
         * return: course object with given ID in Hash Table.
         */

        Course* Find(const Course& course);

        void Add (const Course& course);

        void Remove (const Course& course);
    
};


#endif //Dynamic_Array_H