#include <string>
#include <cstring>
#include <cstdlib>

#include "catch.hpp"

using namespace std;


bool checkReplace(string str1, string str2){
    int diff_count = 0;
    for(int i = 0; i < strlen(str1.c_str()); i++){
        if(str1[i] != str2[i]){
            ++diff_count;
            if(diff_count > 1){
                return false;
            }
        }
    }
    return (diff_count == 1 ? true : false);
}

//Assumes str1.length() > str2.length()
bool checkInsertRemove(string str1, string str2){
    

    for(int i = 0; i < strlen(str2.c_str()); i++){
        if(str1[i] != str2[i]){
            str1.erase(i,1);

            return (str1.compare(str2) == 0 ? true : false);
        }
    }
    //printf("Outside loop\n");
    return true;//????
}

bool oneAway(string str1, string str2){
    int diff = strlen(str1.c_str()) - strlen(str2.c_str());
    if(abs(diff) > 1){
        // printf("Diff greater than 1\n");
        // printf("str1 is %d\n", strlen(str1.c_str()));
        // printf("str2 is %d\n", strlen(str2.c_str()));
        // printf("abs is %d\n", abs(diff));
        return false;
    }
    if(strlen(str1.c_str()) == strlen(str2.c_str())){
        //count number of differences 1-> true else false
        return checkReplace(str1, str2);
    }
    else{
        //diff in length must be 1 
        return (strlen(str1.c_str()) > strlen(str2.c_str()) ? checkInsertRemove(str1, str2) : checkInsertRemove(str2, str1));
    }
}


TEST_CASE("Valid replacements return true", "[replacement]"){
    REQUIRE(oneAway("asdf","asdr") == true);
    REQUIRE(oneAway("asdr","asdf") == true);
    REQUIRE(oneAway("asdf","rsdf") == true);
    REQUIRE(oneAway("rsdf","asdf") == true);
    REQUIRE(oneAway("a"," ") == true);
    REQUIRE(oneAway("1234567890","1234507890") == true);
    REQUIRE(oneAway("onetwothree","onetwothrei") == true);
}

TEST_CASE("Mutliple replacements return false", "[replacement]"){
    REQUIRE(oneAway("asdf","asgr") == false);
    REQUIRE(oneAway("asgr","asdf") == false);
    REQUIRE(oneAway("asdf","radf") == false);
    REQUIRE(oneAway("radf","asdf") == false);
    REQUIRE(oneAway("1234567890","f234507890") == false);
    REQUIRE(oneAway("onetwothree","onitwothrei") == false);
}

TEST_CASE("Single insert or remove returns true", "[insert/remove]"){
    REQUIRE(oneAway("pale","ple") == true);
    REQUIRE(oneAway("pale","ale") == true);
    REQUIRE(oneAway("pale","pal") == true);
    REQUIRE(oneAway("a","") == true);
    REQUIRE(oneAway("","a") == true);
}

TEST_CASE("Mutliple insert or remove returns false", "[insert/remove]"){
    REQUIRE(oneAway("pale","pl") == false);
    REQUIRE(oneAway("pale","pe") == false);
    REQUIRE(oneAway("pale","al") == false);
    REQUIRE(oneAway("pale","le") == false);
    REQUIRE(oneAway("1234","1234567890") == false);
    REQUIRE(oneAway("aaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaabbaaaaaaaaaa") == false);
    REQUIRE(oneAway("1234","2345") == false);

}
/*int main(){
    oneAway("","a");
}*/