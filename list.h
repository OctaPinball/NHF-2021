#ifndef LIST_H
#define LIST_H

//#include "node.h"
#include "defs.h"

template <typename T>
class list : public persistence
{
protected:

private:
    node<T>* first;
    node<T>* last;
    //bool isEmpty();
    bool dataExist(T);


public:
    list();
    ~list();
    //list (list& x);
    void insertNode(const T&);
    void deleteNode(T);
    bool isEmpty();
    void print(std::ostream& os);
    void printInverse(std::ostream& os);
    void insertAtFirst(const T&);
    void insertAtLast(const T&);
    int size();
    virtual int decode8(std::istream&);
    virtual void encode8(std::ostream&, int);
    virtual std::ostream& write(std::ostream&);
    virtual std::istream& read(std::istream&);
    virtual void writetofile(const char* filename);
    virtual void readfromfile(const char* filename);
    class iterator
    {

    public:
        node<T> * ptr;

        iterator(node<T> * ptr = NULL)
            : ptr(ptr)
        {
        }

        iterator operator++(int)
        {
            if(ptr->next == NULL)
                throw std::out_of_range("Iterator kifutott a listabol!");
            iterator copy = *this; // !
            ptr = ptr->next;
            return copy;
        }

        iterator operator--(int)
        {
            if(ptr->prev == NULL)
                throw std::out_of_range("Iterator kifutott a listabol!");
            iterator copy = *this; // !
            ptr = ptr->prev;
            return copy;
        }

        T& operator*() const
        {
            return ptr->data;
        }

        bool operator==(iterator a) const
        {
            return ptr == a.ptr;
        }
        bool operator!=(iterator a) const
        {
            return ptr != a.ptr;
        }
        bool operator<(iterator a) const
        {
            return ptr < a.ptr;
        }
        bool operator>(iterator a) const
        {
            return ptr > a.ptr;
        }

    };

    iterator begin()
    {
        return iterator(first);
    }

    iterator end()
    {
        return iterator(last);
    }

    iterator firstData()
    {
        return iterator(first->next);
    }

    iterator lastData()
    {
        return iterator(last->prev);
    }

};

#endif // LIST_H
