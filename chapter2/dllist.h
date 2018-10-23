/*
Implementation is kept in header file to allow for ease of compiling
with template class.


*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "dll_node.h"

using namespace std;

template <class T> 
class Dllist{
private:
    DllNode<T>* m_head;
    DllNode<T>* m_tail;
public:
    Dllist(){
        this->m_head = NULL;
        this->m_tail = NULL;
    }

    ~Dllist(){
        while(this->m_head != NULL){
            this->pop_front();
        }
    }

    //Capacity
    void clear(){
        while(this->m_head != NULL){
            this->pop_front();
        }
        this->m_tail = NULL;
    }

    bool empty(){
        return ((this->m_head == NULL && this->m_tail == NULL) ? true : false);
    }
    
    bool equals(Dllist<T>* other){
        DllNode<T> *my_cursor, *other_cursor;
        if(this->empty() && other->empty()) return true;
 
        my_cursor = this->front();
        other_cursor = other->front();

        while(my_cursor != NULL && other_cursor != NULL){
            if(my_cursor->data() != other_cursor->data()){
                return false;
            }
            my_cursor = my_cursor->next();
            other_cursor = other_cursor->next();
        }
        if(my_cursor != NULL || other_cursor != NULL){
            return false;
        }
        else{
            return true;
        }
    }

    //Access
    DllNode<T> *front(){
        return this->m_head;
    }

    DllNode<T> *back(){
        return this->m_tail;
    }

    DllNode<T> *at(size_t index){
        DllNode<T> *cursor = this->m_head;
        for(size_t i = 1; (i < index) && (cursor != NULL); ++i){
            cursor = cursor->next();
        }
        return cursor;
    }

    DllNode<T> *find(const T& target){
        DllNode<T> *cursor;
        for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
            if(cursor->data() == target){
                return cursor;
            }
        }
        return NULL;
    }

    size_t length(){
        const DllNode<T> *cursor;
        size_t retval = 0;
        for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
            ++retval;
        }
        return retval;
    }
    
    //Modifiers
    void push_back(const T& item){
        if(this->m_tail == NULL){
            this->m_tail = new DllNode<T>(item, NULL, NULL);
            this->m_head = this->m_tail;
        }
        else{
            this->m_tail->set_next(new DllNode<T>(item, this->m_tail, NULL));
            this->m_tail = this->m_tail->next();
        }
    }

    void push_front(const T& item){
        if(this->m_head == NULL){
            this->m_head = new DllNode<T>(item, NULL, this->m_head);
            this->m_tail = this->m_head;
        }
        else{
            this->m_head->set_prev(new DllNode<T>(item, NULL, this->m_head));
            this->m_head = this->m_head->prev();
        }
    }

    void pop_front(){
        if(this->m_head == NULL) return;

        DllNode<T> *remove_ptr = this->m_head;
        this->m_head = remove_ptr->next();
        if(this->m_head != NULL){
            this->m_head->set_prev(NULL);
        }
        else{
            this->m_tail = NULL;
        }
        delete remove_ptr;
    }

    void pop_back(){
        if(this->m_tail == NULL) return;

        DllNode<T> *remove_ptr = this->m_tail;
        this->m_tail = remove_ptr->prev();
        if(this->m_tail != NULL){
            this->m_tail->set_next(NULL);
        }
        else{
            this->m_head = NULL;
        }
        delete remove_ptr;
    }

    //TODO maybe check that the pointer is actually to a node in the list the function is called on
    void remove(DllNode<T> *remove_ptr){
        if(remove_ptr == NULL) return;
        if(remove_ptr == this->m_head) return this->pop_front();
        if(remove_ptr == this->m_tail) return this->pop_back();

        remove_ptr->next()->set_prev(remove_ptr->prev());
        remove_ptr->prev()->set_next(remove_ptr->next());
        delete remove_ptr;
    }

    DllNode<T> *insert(DllNode<T> *previous_ptr, const T& item){
        if(this->empty()){
            return NULL;
        }
        else if(previous_ptr == this->m_tail){
            this->push_back(item);
            return this->m_tail;
        }
        else {
            DllNode<T> *insert_ptr = new DllNode<T>(item, previous_ptr, previous_ptr->next());
            previous_ptr->set_next(insert_ptr);
            if(insert_ptr->next() != NULL){
                insert_ptr->next()->set_prev(insert_ptr);
            }
            return insert_ptr;
        }
    }
    
    //const access
    const DllNode<T> *front() const{
        return (const DllNode<T> *) this->m_head;
    }

    const DllNode<T> *back() const{
        return (const DllNode<T> *) this->m_tail;
    }

    const DllNode<T> *at(size_t index) const{
        const DllNode<T> *cursor = this->m_head;
        for(size_t i = 1; (i < index) && (cursor != NULL); ++i){
            cursor = cursor->next();
        }
        return cursor;
    }

    const DllNode<T> *find(const T& target) const{
        const DllNode<T> *cursor;
        for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
            if(cursor->data() == target){
                return cursor;
            }
        }
        return NULL;
    }
};

#endif