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
        friend ostream & operator<< (ostream& out, myQueue const & queue) {
            queue_node * temp = queue.head;
            while(temp) {
                out << temp->data << " ";
                temp = temp->next;
            }
            return out;
        }

    private:
        //////////NODE_CLASS/////////////
        struct queue_node {
            T data;
            queue_node * next;
            queue_node * prev;

            queue_node(queue_node* p_prev_node, const T& new_data, queue_node* p_next_node)
                : data(new_data), next(p_next_node), prev(p_prev_node) {}
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
            auto* new_node = new queue_node(prev, data_ptr->data, nullptr);
            if(new_node->prev == nullptr) {
                head = new_node;
                tail = new_node;
            } else {
                new_node->prev->next = new_node;
            }
            prev = new_node;

            if(data_ptr->next == nullptr)
                tail = new_node;

            data_ptr = data_ptr->next;
            mark++;
        }
    }

    template<typename T>
    NEU::myQueue<T>::~myQueue() { clear(); }

    template<typename T>
    bool NEU::myQueue<T>::push(const T item) {
        if(item == 0)
            return false;
        auto * new_node = new queue_node(tail, item, nullptr);
        if(count == 0) {
            head = new_node;
            tail = new_node;
        }
        tail->next = new_node;
        tail = new_node;
        count++;
        return true;
    }

    template<typename T>
    bool NEU::myQueue<T>::pop() {
        queue_node * ori_head = head;
        if(head == 0)
            return false;
        head = head->next;
        delete ori_head;
        count--;
        return true;
    }

    template<typename T>
    T NEU::myQueue<T>::peek() const {
        if(size() != 0)
            return (head->data);
        else {
            throw no_such_element_exception("No Element in queue");
        }
    }

    template<typename T>
    void NEU::myQueue<T>::clear() {
        tail = nullptr;
        while (head) {
            queue_node * head_of_queue = head;
            head = head->next;
            delete head_of_queue;
        }
        count = 0;
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
        myQueue<T> new_queue(rhs);
        return (*this);
    }
}
#endif