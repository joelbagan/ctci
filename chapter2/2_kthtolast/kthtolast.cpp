// -------------------Libraries-------------------


// -------------------Testing framework-------------------
// Uncomment when compiling tests
// Comment out main method when compiling
// #include "catch.hpp"


// -------------------Chapter data structure-------------------
#include "../dllist.h"

using namespace std;

//-------------------Problem Description-------------------


// -------------------Methods-------------------
DllNode<int> *kthToLastDll(unsigned k, Dllist<int> *input){
    if(input->empty() || k == 0){
        return NULL;
    }

    DllNode<int> *cursor = input->back();
    while(cursor != NULL && --k > 0){
        cursor = cursor->prev();
    }
    return cursor;
}

DllNode<int> *kthToLastSll(unsigned k, Dllist<int> *input){
    if(k == 0){
        return NULL;
    }

    DllNode<int> *slow_cursor = input->front();
    DllNode<int> *fast_cursor = slow_cursor;
    for (int i = 1; i < k; ++i)
    {
        fast_cursor = fast_cursor->next();
        if(fast_cursor == NULL){
            return NULL;
        }
    }

    return slow_cursor;
}
// -------------------Tests-------------------
// TEST_CASE("Description","[tag1]"){
//     //Initialization applied to all SECTION's

//     SECTION("Description"){
//         REQUIRE(true);
//     }
// }

// -------------------Main-------------------
// Keep this main method when only compiling methods
// Uncomment when compiling tests and uncomment 
// catch include statement
int main(int argc, char const *argv[])
{
    return 0;
}