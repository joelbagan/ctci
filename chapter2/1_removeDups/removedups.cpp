// -------------------Libraries-------------------
#include <unordered_set>

// -------------------Testing framework-------------------
// Uncomment when compiling tests
// Comment out main method when compiling
#include "catch.hpp"


// -------------------Chapter data structure-------------------
#include "../dllist.h"

using namespace std;

//-------------------Problem Description-------------------
// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?

// -------------------Methods-------------------
void removeDups(Dllist<int> *input){
    unordered_set<int> unique_items;
    DllNode<int> *cursor, *next_node;
    for(cursor = input->front(); cursor != NULL; cursor = next_node){
        int current_item = cursor->data();
        next_node = cursor->next();
        if(unique_items.count(current_item) == 0){
            unique_items.insert(current_item);
        }
        else{
            input->remove(cursor);
        }
    }
}

// -------------------Tests-------------------
TEST_CASE("Simple","[tag1]"){
    //input = [0, 0, 1, 1, 2, 2, 3, 3, 4, 4]
    Dllist<int> *input = new Dllist<int>();
    Dllist<int> *result_check = new Dllist<int>();
    for(int i = 0; i < 5; i++){
        input->push_back(i);
        input->push_back(i);
        result_check->push_back(i);
    }

    SECTION("Description"){
        removeDups(input);
        REQUIRE(input->equals(result_check));
    }

    delete input;
    delete result_check;
}

TEST_CASE("Intermediate","[tag1]"){
    Dllist<int> input = Dllist<int>();
    Dllist<int> result_check = Dllist<int>();
    //input = [0,1,2,3,4,4,3,2,1,0]
    for (int i = 0; i < 5; ++i)
    {
        input.push_back(i);
        result_check.push_back(i);
    }
    for(int i = 4; i >= 0; --i){
        input.push_back(i);
    }

    SECTION("Description"){
        removeDups(&input);
        REQUIRE(input.equals(&result_check));
    }
}

// -------------------Main-------------------
// Keep this main method when only compiling methods
// Uncomment when compiling tests and uncomment 
// catch include statement
// int main(int argc, char const *argv[])
// {
//     return 0;
// }