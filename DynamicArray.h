#ifndef Dynamic_Array_H
#define Dynamic_Array_H

#include "Array.h"

class DynamicArray
{
    private:
        const int INITAL_SIZE=4;
        int current_size;
        Array<int> array;

        void ExtendArray();
        /**
         * return size of Dynamic Array.
         */
        int getSize() const;
        
    public:
        /**
         * Default c'tor for Dynamic Array object.
         */
        //DynamicArray()=default;

        /**
         * c'tor.
         * 
         * @param:
         *      initial data - Required field to fill in each member of Dynamic Array upon creating.
         *                     Default parameter is the default c'tor of the type T.
         */
        DynamicArray(int inital=-1);
        
        /**
         * copy c'tor for Dynamic Array object.
         * 
         * @param:
         *      other - Reference for another Dynamic Array object, from whom to initialize new Dynamic Array fields.
         */
        DynamicArray(const DynamicArray& other)=default;

        /**
         * d'tor for Dynamic Array. deallocate data of Dynamic Array.
         */
        ~DynamicArray()=default;
        
        /**
         * operator[] for Dynamic Array. For example: arr[index] = value.
         * 
         * @param:
         *      index - required index to access in the Dynamic Array.
         * 
         * return: T object filled in the required index in Dynamic Array.
         */
        int& operator[] (const int index);

        /**
         * const operator[] for Dynamic Array. For example: value = arr[index].
         * in use only for reading data and not to write data in array.
         * 
         * @param:
         *      index - required index to read from in the Dynamic Array.
         * 
         * return: T object filled in the required index in Dynamic Array.
         */
        const int& operator[] (const int index) const;
};


#endif //Dynamic_Array_H