#include "myQueue.hpp"
#include <exception>
//#include <string>

using std::cout;
using std::endl;
//using std::string;
using namespace NEU;

//string bool_to_string(bool value) {
//    return value == 0 ? "false" : "true";
//}

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
            catch (no_such_element_exception& e) { cout << "check peek() -> SUCCESS" << endl; }
        }
        else
            cout << "check peek() -> FAIL" << endl;

        ///////////////POP CHECK/////////////////
        if(queue.pop() && ! empty_queue.pop())
            cout << "check pop() -> SUCCESS" << endl;
        else
            cout << "check pop() -> FAIL" << endl;

        ///////////////SIZE CHECK////////////////
        if(queue.size() == 4 && empty_queue.size() == 0)
            cout << "check size() -> SUCCESS, queue size is -> " << queue.size() << endl;
        else
            cout << "check size() -> FAIL, queue size is -> " << queue.size() << endl;

        ///////////////EMPTY CHECK///////////////
        if(!queue.empty() && empty_queue.empty())
            cout << "check empty() -> SUCCESS" << endl;
        else
            cout << "check empty() -> FAIL" << endl;

        ///////////////CLEAR CHECK///////////////
        queue.clear();
        bool mark = true;
        try { empty_queue.clear(); } catch (std::exception& e) { cout << "cannot clear empty queue."; mark = false; cout << e.what(); }
        if(mark && queue.empty())
            cout << "check clear() -> SUCCESS" << endl;
        else
            cout << "check clear() -> FAIL" << endl;

        ///////////////OPERATOR CHECK////////////
        cout << "check operator<< -> you should see 1 2 3 4 5 down here: " << endl;
        cout << new_queue << endl;

        bool mark2 = true;
        bool temp = true;
        while(temp){
            mark2 = (new_queue.peek() == copy_queue.peek());
            temp = (new_queue.pop() && copy_queue.pop());
            try {new_queue.peek(); copy_queue.peek();} catch (no_such_element_exception& e) {break;}
        }
        if(mark2)
            cout << "check operator= -> SUCCESS" << endl;
        else
            cout << "check operator= -> FAIL" << endl;
    } catch (std::exception& e) {
        cout << "exception detected: " << endl;
        cout << e.what() << endl;
        system("pause");
        getchar();

        return 1;
    }
    
    system("pause");
    getchar();
    return 0;
}