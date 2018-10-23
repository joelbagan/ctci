#include "linkedlist.h"

using namespace std;

template <class T> 
Dllist<T>::Dllist(){
    this->m_length = 0;
    this->m_head = NULL;
    this->m_tail = NULL;
}

template <class T> 
Dllist<T>::~Dllist(){
    while(this->m_head != NULL){
        this->pop_front();
    }
}

//access
template <class T> 
DllNode<T> *Dllist<T>::front(){
    return this->m_head;
}

template <class T> 
DllNode<T> *Dllist<T>::back(){
    return this->m_tail;
}

template <class T> 
DllNode<T> *Dllist<T>::at(size_t index){
    DllNode<T> *cursor = this->m_head;
    for(size_t i = 1; (i < index) && (cursor != NULL); ++i){
        cursor = cursor->next();
    }
    return cursor;
}

template <class T>
DllNode<T> *Dllist<T>::find(const T& target){
    DllNode<T> *cursor;
    for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
        if(cursor->data() == target){
            return cursor;
        }
    }
    return NULL;
}

template <class T> 
size_t Dllist<T>::length(){
    const DllNode<T> *cursor;
    size_t retval = 0;
    for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
        ++retval;
    }
    return retval;
}

//Modifiers
template <class T> 
void Dllist<T>::push_back(const T& item){
    this->m_tail = new DllNode<T>(item, this->m_tail, NULL);
}

template <class T> 
void Dllist<T>::push_front(const T& item){
    this->m_head = new DllNode<T>(item, NULL, this->m_head);
}


template <class T> 
void Dllist<T>::pop_front(){
    if(this->m_head == NULL) return;

    DllNode<T> *remove_ptr = this->m_head;
    this->m_head = remove_ptr->next();
    if(this->m_head != NULL){
        this->m_head->set_prev(NULL);
    }
    delete remove_ptr;
}

template <class T> 
void Dllist<T>::pop_back(){
    if(this->m_tail == NULL) return;

    DllNode<T> *remove_ptr = this->m_tail;
    this->m_tail = remove_ptr->prev();
    if(this->m_tail != NULL){
        this->m_tail->set_next(NULL);
    }
    delete remove_ptr;
}

template <class T> 
void Dllist<T>::remove(DllNode<T> *remove_ptr){
    if(remove_ptr == NULL) return;
    if(remove_ptr == this->m_head) return this->pop_front();
    if(remove_ptr == this->m_tail) return this->pop_back();

    remove_ptr->next()->set_prev(remove_ptr->prev());
    remove_ptr->prev()->set_next(remove_ptr->next());
    delete remove_ptr;
}

template <class T> 
DllNode<T> * Dllist<T>::insert(DllNode<T> *previous_ptr, const T& item){
    if(previous_ptr == NULL){
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

template <class T> 
void Dllist<T>::clear(){
    while(this->m_head != NULL){
        this->pop_front();
    }
    this->m_tail = NULL;
}


//const access
template <class T>
const DllNode<T> *Dllist<T>::front() const{
    return (const DllNode<T> *) this->m_head;
}

template <class T>
const DllNode<T> *Dllist<T>::back() const{
    return (const DllNode<T> *) this->m_tail;
}

template <class T>
const DllNode<T> *Dllist<T>::at(size_t index) const{
    const DllNode<T> *cursor = this->m_head;
    for(size_t i = 1; (i < index) && (cursor != NULL); ++i){
        cursor = cursor->next();
    }
    return cursor;
}

template <class T>
const DllNode<T> *Dllist<T>::find(const T& target) const{
    const DllNode<T> *cursor;
    for(cursor = this->m_head; cursor != NULL; cursor = cursor->next()){
        if(cursor->data() == target){
            return cursor;
        }
    }
    return NULL;
}