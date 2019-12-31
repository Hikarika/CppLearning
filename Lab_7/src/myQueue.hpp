#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <iostream>
#include <exception>
#include <string>
#include <utility>

using std::ostream;
using std::cout;
using std::endl;
using std::exception;
using std::string;

namespace NEU
{
    class no_such_element_exception : public exception {
    public:
        const char * what() const noexcept override {
            return message.c_str();
        }

        explicit no_such_element_exception(string info): message(std::move(info)) {}

    private:
        string message;
    };

    template<typename T>
    class myQueue
    {
    public:
        ///////////CONSTRUCTORS///////////
        //default constructor
        myQueue();
        //deep copy from queue -> constructor
        myQueue(const myQueue& queue);
        //destructor
        ~myQueue();

        ///////////FUNCTIONS//////////////
        ///////////MEMBER/////////////////

        //push item to back of the queue
        bool push(T item);

        //pop item from front of the queue but not return
        bool pop(T& item);

        bool pop();

        //get item from front but not remove
        T peek() const ;

        //return true if queue is empty
        bool empty();

        //return queue's size
        int size() const ;

        //clear all element in queue
        void clear();

        ///////////OPERATORS//////////////
        ///////////MEMBER/////////////////
        
        myQueue<T> & operator= (const myQueue<T> & rhs);

        ///////////NONMEMBER//////////////
        friend ostream & operator<< (ostream& out, myQueue const & queue) { queue_node * temp = queue.head; while(temp) {out << temp->data << " ";temp = temp->next;} return out; }

    private:
        //////////NODE_CLASS/////////////
        struct queue_node {
            queue_node * prev = nullptr;
            T data;
            queue_node * next = nullptr;

            queue_node(queue_node* p_prev_node, const T& new_data, queue_node* p_next_node)
                : prev(p_prev_node), data(new_data), next(p_next_node) {}
        };
        queue_node * head;
        queue_node * tail;
        int count;
    };


    template<typename T>
    NEU::myQueue<T>::myQueue(): head(nullptr), tail(nullptr), count(0) {}

    template<typename T>
    NEU::myQueue<T>::myQueue(const myQueue<T>& queue) {
        if(queue.size() == 0) {
            cout << "queue is empty." << endl;
        }

        queue_node * data_ptr = queue.head;
        count = queue.count;
        int mark = 1;
        queue_node * prev = nullptr;
        while(mark <= count) {
            auto* new_node = new queue_node(prev, data_ptr->data, nullptr); // use new to allocate new space for queue_node.
            if(new_node->prev == nullptr) { // if queue is empty, head and tail is the new_node
                head = new_node;
                tail = new_node;
            } else {
                new_node->prev->next = new_node; // previous node link new_node
            }
            prev = new_node; // link new_node to previous node

            if(data_ptr->next == nullptr) // if reach the queue's tail then update current tail
                tail = new_node;

            data_ptr = data_ptr->next; // point to next node
            mark++; // update mark in order to prevent error
        }
    }

    template<typename T>
    NEU::myQueue<T>::~myQueue() { clear(); } // use clear as destructor

    template<typename T>
    bool NEU::myQueue<T>::push(const T item) {
        if(item == 0)
            return false;
        auto * new_node = new queue_node(tail, item, nullptr); // new a new_node and allocate a new space
        if(count == 0) { // in case of queue is empty
            head = new_node;
            tail = new_node;
        }
        tail->next = new_node; // update tail to new tail
        tail = new_node;
        count++; // update count -> size()
        return true;
    }

    template<typename T>
    bool NEU::myQueue<T>::pop() {
        queue_node * ori_head = head; // point to original head pointer for future use
        if(head == 0)
            return false;
        head = head->next; // update head pointer
        delete ori_head; // free space of original head
        count--; // decrease size()
        return true;
    }

    template<typename T>
    T NEU::myQueue<T>::peek() const {
        if(size() != 0) // if not empty
            return (head->data);
        else {
            throw no_such_element_exception("No Element in queue"); // throw a custom exception to main to handle
        }
    }

    template<typename T>
    void NEU::myQueue<T>::clear() {
        tail = nullptr; // initialize tail
        while (head) {
            queue_node * queue_ptr = head;
            head = head->next;
            delete queue_ptr; // delete the current pointing space
        }
        count = 0; // initialize size
    }

    template<typename T>
    int NEU::myQueue<T>::size() const {
        return count;
    }

    template<typename T>
    bool NEU::myQueue<T>::empty() {
        return count == 0;
    }

    template<typename T>
    NEU::myQueue<T> & NEU::myQueue<T>::operator= (const NEU::myQueue<T> & rhs) {
        this = myQueue(rhs);
        return (*this);
    }

    template<typename T>
    bool myQueue<T>::pop(T& item) {
        queue_node * ori_head = head;
        if(head == 0)
            return false;
        head = head->next;
        item = ori_head->data;
        delete ori_head;
        count--;
        return true;
    }
}
#endif