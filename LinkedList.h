#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

/**
 * Generic Node for LinkedList with data of type T.
 * Each Node hold pointer to next node in list, pointer to previous node and pointer to head of list.
 */
template <class T>
class LinkedListNode
{
    public:
    T data;
    std::shared_ptr<LinkedListNode<T> > next;
    std::shared_ptr<LinkedListNode<T> > previous;
    std::shared_ptr<LinkedListNode<T> > ptr_to_head;

    /**
     * default c'tor for LinkedListNode.
     * Passing null for each pointer and default value in data of type T.
     */
    LinkedListNode() = default;

    /**
     * c'tor for LinkedListNode.
     * passing null for pointers and initialize data with required information of type T.
     */
    LinkedListNode(const T data) : data(data), next(nullptr), previous(nullptr){}
};

/**
 * Generic LinkedList class.
 * Each list holds pointer to head and tail, while each of them is generic LinkedListNode. 
 */
template <class T>
class LinkedList
{
    private:
        std::shared_ptr<LinkedListNode<T> > head;
        std::shared_ptr<LinkedListNode<T> > tail;

    public:

        /**
         * c'tor for LinkedListNode.
         * The c'tor allocate pointers for head and tail, and points them to each other,
         * since the list is empty at start.
         */
        LinkedList():head(new LinkedListNode<T>()) , tail(new LinkedListNode<T>())
        {
            head->next = tail;
            tail->previous = head;
        }
        
        /**
         * copy c'tor for LinkedListNode.
         * 
         * @param:
         *      other - Reference for another list, from whom to initialize new list members.
         */
        LinkedList(const LinkedList<T>& other): head(new LinkedListNode<T>()),
                                                tail(new LinkedListNode<T>())
        {
            head->next = tail;
            tail->previous = head;
            std::shared_ptr<LinkedListNode<T> > ptr_other= (other.head)->next;
            while(ptr_other != other.tail)
            {
                this->insert(ptr_other->data);
                ptr_other = ptr_other->next;
            }
        }

        /**
         * copy c'tor for LinkedListNode.
         * 
         * @param:
         *      other - Reference for another list, from whom to copy to new list members.
         */
        LinkedList<T>& operator= (const LinkedList& other)
        {
            if (this == &other)
            {
                return *this;
            }
            std::shared_ptr<LinkedListNode<T> > current = head->next;
            while(current != tail)
            {
                (current->previous)->next=nullptr;
                current->previous=nullptr;
                current->ptr_to_head=nullptr;
                current=current->next;
            }
            head->next = tail;
            tail->previous = head;
            std::shared_ptr<LinkedListNode<T> > ptr_other= (other.head)->next;
            while(ptr_other != other.tail)
            {
                this->insert(ptr_other->data);
                ptr_other = ptr_other->next;
            }
            return *this;
        }

        /**
         * d'tor for LinkedListNode.
         * deallocate every member in list by traverse over them
         * by pointing the shared_ptr: next, previous, ptr_to_head - to null.
         */
        ~LinkedList()
        {
            std::shared_ptr<LinkedListNode<T> > current=head->next;
            while((current!=nullptr) && (current.get() != nullptr))
            {
                (current->previous)->next=nullptr;
                current->previous=nullptr;
                current->ptr_to_head=nullptr;
                current=current->next;
            }
        }

        /**
         * insert function in LinkedListNode. insert new member in end of list.
         * 
         * @param:
         *      data - required data to fill in new member allocated in end of list.
         * 
         * return: pointer to the inserted new Node in the list.
         */
        std::shared_ptr<LinkedListNode<T>> insert(const T& data)
        {
            return insertAfterNode(tail->previous,data);
        }
        
        /**
         * insertAtStart function to insert member at begining of the list.
         * 
         * @param:
         *      data - required data to fill in new member in begining of list.
         * 
         * return: pointer to the inserted new Node.
         */
        std::shared_ptr<LinkedListNode<T> > insertAtStart(const T& data)
        {
            return insertAfterNode(head,data);
        }

        /**
         * insertAfterNode function to insert member after giving Node of the list (as his next).
         * 
         * @param:
         *      prev_node - the Node we want to insert our new node rifht after.
         *      data - required data to fill in new member in begining of list.
         * 
         * return: pointer to the inserted new Node.
         */
        std::shared_ptr<LinkedListNode<T> > insertAfterNode(std::shared_ptr<LinkedListNode<T> > prev_node,
                                                            const T& data)
        {
            std::shared_ptr<LinkedListNode<T> > new_node(new LinkedListNode<T>(data));
            new_node->next = prev_node->next;
            new_node->previous = prev_node;
            prev_node->next = new_node;
            new_node->next->previous = new_node;
            new_node->ptr_to_head=head;
            return new_node;
        }

        /**
         * remove function to remove Node from list.
         * 
         * @param:
         *      node - reference for a Node in list, whom we want to remove.
         * 
         * return: pointer to the node previous to removed node.
         */
        std::shared_ptr<LinkedListNode<T> > remove(LinkedListNode<T>& node)
        {
            if (node.ptr_to_head==head)
            {
                std::shared_ptr<LinkedListNode<T> > prev = node.previous;
                (node.previous)->next = node.next;
                (node.next)->previous = node.previous;
                node.ptr_to_head=nullptr;
                return prev;
            }
            return nullptr;
        }
        
        /**
         * removeByData function to remove Node from list.
         * 
         * @param:
         *      node - reference for a Node in list, whom we want to remove.
         * 
         * return: pointer to the node previous to removed node.
         */
        void removeByData(const T& data)
        {
            std::shared_ptr<LinkedListNode<T> > curr_node=head->next;
            while(curr_node!=tail)
            {
                if(curr_node->data==data)
                {
                    remove(*curr_node);
                    return;
                }
                curr_node=curr_node->next;
            }
            return;
        }

        /**
        * iterator for LinkedList object.
        */
        class iterator
            {
                private:
                    const LinkedList<T>* list;
                    LinkedListNode<T>* ptr;

                    /**
                    * iterator c'tor
                    * 
                    * @param:
                    *       list - pointer to a LinkedList object.
                    *       ptr - pointer to the node in the list.
                    * 
                    * return: an iterator for the given Node in list ot type T.
                    */
                    iterator(const LinkedList<T>* list, LinkedListNode<T>* ptr) :list(list) ,ptr(ptr){}
                    friend class LinkedList;
                    
                public:                   
                    /**
                    * operator== (iterator)
                    * 
                    * @param:
                    *       it - reference for an iterator object for LinkedList.
                    * 
                    * return: true/false if the this, it iterator are equal 
                    *         (pointing on the same Node in the same LinkedList)
                    */
                    bool operator==(const iterator& it) const
                    {
                        return ptr == (it.ptr);
                    }

                    /**
                    * operator!= (iterator)
                    * 
                    * @param:
                    *       it - reference for an iterator object for LinkedList.
                    * 
                    * return: true/false if the this, it iterator aren't equal 
                    *         (pointing on the same Node in the same LinkedList)
                    */ 
                    bool operator!=(const iterator& it) const
                    {
                        return !(*this == it);
                    }

                    /**
                    * operator* (iterator)
                    * 
                    * return: return a refrence to the value the iterator points at.
                    */
                    T& operator*()
                    {
                        return ptr->data;
                    }

                    /**
                    * operator++ (iterator)
                    * 
                    * return: promote and return the new value the iterator points at.
                    */
                    iterator& operator++() 
                    {
                        ptr=(ptr->next).get();
                        return *this;
                    }

                    /**
                    * operator++ (iterator)
                    * 
                    * return: return the value the iterator points at and promomte it to the next Node.
                    */
                    iterator operator++(int)
                    {
                        iterator result=*this;
                        ++*this;
                        return result;
                    }

                    /**
                     * default copy c'tor for iterator of LinkedList object.
                     */
                    iterator(const iterator&) = default;

                    /**
                     * operator= for iterator of LinkedList object.
                     */
                    iterator& operator=(const iterator&) = default;               
            };
            /**
             * method to create and return an iterator points to the first Node in LinkedList.
             */
            iterator begin()
            {
                return iterator(this, ((this->head)->next).get());
            }

            /**
             * method to create and return an iterator points to the tail of LinkedList.
             */
            iterator end()
            {
                return iterator(this, (this->tail).get());
            }
};

#endif //LINKEDLIST_H