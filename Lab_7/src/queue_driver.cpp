#include "myQueue.hpp"
#include <exception>
//#include <string>

using std::cout;
using std::endl;
using std::string;
using namespace NEU;

string bool_to_string(bool value) {
    return value == 0 ? "false" : "true";
}

int count = 0;
#define MAX_SUCCESS 8

int main(int argc, char ** args) {

    try {
        myQueue<int> queue;
        myQueue<int> empty_queue;

        ///////////////STORE VALUE///////////////
        try {
            queue.push(1);
            queue.push(2);
            queue.push(3);
            queue.push(4);
            queue.push(5);
            cout << "check push() -> SUCCESS" << endl;
            count++;
        } catch (std::exception& e) {
            cout << "check push() -> FAIL" << endl;
            e.what();
        }


        ///////////////COPY QUEUE////////////////
        myQueue<int> new_queue(queue);
        myQueue<int> copy_queue = new_queue;

        ///////////////FUNCTION CHECK////////////

        ///////////////PEEK CHECK////////////////
        if(queue.peek() == 1) {
            try { empty_queue.peek(); }
            catch (no_such_element_exception& e) { cout << "check peek() -> SUCCESS" << endl; count++;}
        }
        else
            cout << "check peek() -> FAIL" << endl;

        ///////////////POP CHECK/////////////////
        if(queue.pop() && ! empty_queue.pop()) {
            cout << "check pop(no parameter) -> SUCCESS" << endl;
            count++;
        }
        else
            cout << "check pop(no parameter) -> FAIL" << endl;

        int ret1;
//        cout << "glance of ret1 is -> " << queue.peek() << endl;
        queue.pop(ret1);
        if(ret1 == 2) {
            cout << "check pop(T& item) -> SUCCESS" << endl; count++;
        }
        else
            cout << "check pop(T& item) -> FAIL, ret1 is -> " << ret1 << endl;

        ///////////////SIZE CHECK////////////////
        if(queue.size() == 3 && empty_queue.size() == 0) {
            cout << "check size() -> SUCCESS, queue size is -> " << queue.size() << endl;
            count++;
        }
        else
            cout << "check size() -> FAIL, queue size is -> " << queue.size() << endl;

        ///////////////EMPTY CHECK///////////////
        if(!queue.empty() && empty_queue.empty()) {
            cout << "check empty() -> SUCCESS" << endl;
            count++;
        }
        else
            cout << "check empty() -> FAIL" << endl;

        ///////////////CLEAR CHECK///////////////
        queue.clear();
        bool mark = true;
        try { empty_queue.clear(); } catch (std::exception& e) { cout << "cannot clear empty queue."; mark = false; cout << e.what(); }
        if(mark && queue.empty()) {
            cout << "check clear() -> SUCCESS" << endl;
            count++;
        }
        else
            cout << "check clear() -> FAIL" << endl;

        ///////////////OPERATOR CHECK////////////
        cout << "check operator<< -> you should see 1 2 3 4 5 down here: " << endl;
        cout << new_queue << endl;

        bool mark2 = true;
        bool temp = true;

        myQueue<int>* ptr1 = &new_queue;
        myQueue<int>* ptr2 = &copy_queue;
        cout << "Is the queue using = to copy the same as original one? -> " << bool_to_string((ptr1 == ptr2)) << endl;

        while(temp) {
            mark2 = (new_queue.peek() == copy_queue.peek());
            temp = (new_queue.pop() && copy_queue.pop());
            try {new_queue.peek(); copy_queue.peek();} catch (no_such_element_exception& e) {break;}
        }
        if(mark2) {
            cout << "check operator= -> SUCCESS" << endl;
            count++;
        }
        else
            cout << "check operator= -> FAIL" << endl;
    } catch (std::exception& e) {
        cout << "exception detected: " << endl;
        cout << e.what() << endl;
        system("pause");
        getchar();

        return 1;
    }

    cout << "SUCCESS -> " << count << "/" << MAX_SUCCESS << endl;

    system("pause");
    return 0;
}