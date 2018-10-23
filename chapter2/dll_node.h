#ifndef DLL_NODE_H
#define DLL_NODE_H

#include <cstdlib>
#include <type_traits>

using namespace std;

template <class T>
class DllNode{
private:
    T m_data;    
    DllNode<T>* m_prev;
    DllNode<T>* m_next;
public:
    DllNode();
    DllNode(const T& item, DllNode<T>* ptrprev = NULL, DllNode<T>* ptrnext = NULL){
        this->m_data = item; this->m_prev = ptrprev; this->m_next = ptrnext;}
    ~DllNode(){
        //TODO handle pointer data
    }

    //Modifiers
    DllNode<T>* next(){return m_next;}
    DllNode<T>* prev(){return m_prev;}
    void set_data(const T& new_data){data = new_data;}
    void set_next(DllNode<T>* new_next){m_next = new_next;}
    void set_prev(DllNode<T>* new_prev){m_prev = new_prev;}
    
    T data() {return m_data;}

    //CONST members
    const DllNode<T> *next() const {return m_next;}
    const DllNode<T> *prev() const {return m_prev;}
};

#endif