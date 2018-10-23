#include "dllist.h"
#include "catch.hpp"

TEST_CASE("Initialization", "[init]"){
    Dllist<int> *list = new Dllist<int>();
    REQUIRE(list->length() == 0);
    REQUIRE(list->front() == NULL);
    REQUIRE(list->back() == NULL);
}

TEST_CASE("Insertions", "[insert]"){
    Dllist<int> *list = new Dllist<int>();

    SECTION("push_back simple"){
        list->push_back(0);
        REQUIRE(list->length() == 1);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() == list->back());
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 0);

        list->push_back(1);
        REQUIRE(list->length() == 2);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() != list->back());
        REQUIRE(list->front()->next() == list->back());
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 1);

        list->push_back(2);
        REQUIRE(list->length() == 3);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() != list->back());
        REQUIRE(list->front()->next() != list->back());
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 2);
    }

    SECTION("push_front simple"){
        list->push_front(0);
        REQUIRE(list->length() == 1);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() == list->back());
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 0);

        list->push_front(1);
        REQUIRE(list->length() == 2);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() != list->back());
        REQUIRE(list->front()->next() == list->back());
        REQUIRE(list->front()->data() == 1);
        REQUIRE(list->back()->data() == 0);

        list->push_front(2);
        REQUIRE(list->length() == 3);
        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() != list->back());
        REQUIRE(list->front()->next() != list->back());
        REQUIRE(list->front()->data() == 2);
        REQUIRE(list->back()->data() == 0);
    }

    SECTION("insert simple"){
        DllNode<int> *test_ptr;

        test_ptr = list->insert(list->front(), 0);
        REQUIRE(test_ptr == NULL);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
        REQUIRE(list->length() == 0);

        list->push_front(0);
        test_ptr = list->insert(list->front(), 1);
        REQUIRE(test_ptr == list->back());
        REQUIRE(list->length() == 2);
        REQUIRE(list->front() != list->back());
        REQUIRE(list->front()->next() == list->back());

        test_ptr = list->insert(list->front(), 100);
        REQUIRE(test_ptr == list->front()->next());
        REQUIRE(test_ptr->data() == 100);
        REQUIRE(list->length() == 3);

        test_ptr = list->insert(list->back(), 666);
        REQUIRE(test_ptr == list->back());
        REQUIRE(test_ptr->data() == 666);
        REQUIRE(list->length() == 4);
    }
}

TEST_CASE("Deletions","[deletion]"){
    Dllist<int> *list = new Dllist<int>();
    DllNode<int> *remove_ptr;
    list->push_back(0);

    SECTION("clear simple"){
        REQUIRE(list->length() == 1);
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 0);
        REQUIRE(list->front() == list->back());

        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);

        list->push_back(0);
        list->push_back(1);
        list->push_back(2);
        list->push_back(3);
        list->push_back(4);
        list->push_back(5);
        list->push_back(6);
        REQUIRE(list->length() == 7);
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 6);

        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
    }

    SECTION("remove length = 1"){
        REQUIRE(list->length() == 1);
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 0);
        REQUIRE(list->front() == list->back());

                
        remove_ptr = list->front();
        list->remove(remove_ptr);

        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
        REQUIRE(list->length() == 0);


        list->push_front(1);
        list->push_front(0);

    }

    SECTION("remove length = 2"){
        list->push_front(0);
        REQUIRE(list->length() == 2);
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 0);
        REQUIRE(list->front() != list->back());
        
        remove_ptr = list->back();
        list->remove(remove_ptr);

        REQUIRE(list->front() != NULL);
        REQUIRE(list->back() != NULL);
        REQUIRE(list->front() == list->back());
        REQUIRE(list->length() == 1);
    }

    SECTION("remove length > 2"){
        list->push_back(1);
        list->push_back(2);
        REQUIRE(list->length() == 3);
        REQUIRE(list->front()->data() == 0);
        REQUIRE(list->back()->data() == 2);
        REQUIRE(list->front() != list->back());


        
    }
}

TEST_CASE("Comparisons","[equals]"){
    Dllist<int> *left = new Dllist<int>();
    Dllist<int> *right = new Dllist<int>();

    SECTION("Empty comparison"){
        REQUIRE(left->equals(right) == true);
        REQUIRE(right->equals(left) == true);
    }

    for(int i = 0; i < 10; i++){
        left->push_back(i);
    }

    SECTION("Empty and Non-Empty"){
        REQUIRE(left->equals(right) == false);
        REQUIRE(right->equals(left) == false);
    }


    for(int i = 0; i < 10; i++){
        right->push_back(i);
    }
    SECTION("Non empty equal comparison"){
        REQUIRE(left->equals(right) == true);
        REQUIRE(right->equals(left) == true);
    }

    SECTION("Non empty INequal comparison"){
        left->pop_front();
        REQUIRE(left->equals(right) == false);
        REQUIRE(right->equals(left) == false);
    }
}

TEST_CASE("Empty","[empty]"){
    Dllist<int> *list = new Dllist<int>();
    REQUIRE(list->empty() == true);
    list->push_back(0);
    REQUIRE(list->empty() == false);
}

TEST_CASE("Clear","[clear]"){
    Dllist<int> *list = new Dllist<int>();
    SECTION("clear on empty list"){
        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
    }

    list->push_back(0);
    SECTION("clear on single element"){
        REQUIRE(list->length() == 1);
        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
    }

    list->push_back(1);
    SECTION("clear on two element"){
        REQUIRE(list->length() == 2);
        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
    }

    for (int i = 2; i < 40; ++i){
        list->push_back(i);
    }

    SECTION("clear on many element"){
        REQUIRE(list->length() == 40);
        list->clear();
        REQUIRE(list->length() == 0);
        REQUIRE(list->front() == NULL);
        REQUIRE(list->back() == NULL);
    }
}

TEST_CASE("Find","[find]"){
    Dllist<int> *list = new Dllist<int>();
    SECTION("Empty"){
        REQUIRE(list->find(0) == NULL);
    }

    list->push_back(0);

    SECTION("Singleton"){
        REQUIRE(list->find(0) == list->front());
        REQUIRE(list->find(1) == NULL);
    }

    list->push_back(1);

    SECTION("2-element"){
        REQUIRE(list->find(0) == list->front());
        REQUIRE(list->find(1) == list->back());
        REQUIRE(list->find(2) == NULL);
    }

    list->push_back(2);

    SECTION("3-element"){
        REQUIRE(list->find(0) == list->front());
        REQUIRE(list->find(1) == list->front()->next());
        REQUIRE(list->find(2) == list->back());
        REQUIRE(list->find(4) == NULL);
    }

    DllNode<int> *pointer_arr[50];
    pointer_arr[0] = list->front();
    pointer_arr[1] = list->front()->next();
    pointer_arr[2] = list->back();

    for (int i = 3; i < 49; ++i){
        list->push_back(i);
        pointer_arr[i] = list->back();
    }

    SECTION("Many elements"){
        for (int i = 0; i < 49; ++i)
        {
            REQUIRE(list->find(i) == pointer_arr[i]);
        }
    }
}


// int main(int argc, char const *argv[])
// {
//     Dllist<int> ints();

//     return 0;
// }