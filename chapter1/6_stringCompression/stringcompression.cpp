#include <string>
#include <cstring>
#include <vector>

#include "catch.hpp"

/*
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example. the string aabcccccaaa would become a2b1c5a3. If the 
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a-z);
*/

using namespace std;

int countDigits(int number){
    if(number < 10){
        return 1;
    }
    else{
        int digit_count = 0;
        while(number > 0){
            ++digit_count;
            number = number/10;
        }
        return  digit_count;
    }
}

//can be made faster with c_string
string makeCompString(vector<pair<char,int>> compression){
    string retval;
    for(int i = 0; i < compression.size(); i++){
        retval.push_back(compression[i].first);
        retval.append(to_string(compression[i].second));
    }
    return retval;
}

string compress(string input){
    const char *cstr_input = input.c_str();
    vector<pair<char,int>> compression;
    int curr_count = 0;
    char curr_char;
    int compressed_length = 0;
    for (int i = 0; i < strlen(cstr_input); ++i){
        if(i == 0){
            curr_char = cstr_input[0];
        }
        if(curr_char != cstr_input[i]){
            compression.push_back(make_pair(curr_char, curr_count));
            compressed_length += (1 + countDigits(curr_count));
            curr_count = 1;
            curr_char = cstr_input[i];
        }
        else{
            ++curr_count;
        }
    }
    //REPEATED CODE!!!!!!!!!!!!!!!!
    compression.push_back(make_pair(curr_char, curr_count));
    compressed_length += (1 + countDigits(curr_count));

    return (compressed_length < strlen(cstr_input) ? makeCompString(compression) : input);
}

// int main(){
//     printf("1 %d\n", countDigits(1));
//     printf("10 %d\n", countDigits(10));
//     printf("100 %d\n", countDigits(100));
//     printf("123 %d\n", countDigits(123));
//     printf("123457689 %d\n", countDigits(123456789));
//     printf("0 %d\n", countDigits(0));
//     printf("%s\n", compress("aabcccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccaaa").c_str());
//     printf("%s\n", compress("abcd").c_str());
// }

TEST_CASE("Small compressible","[compressible]"){
    REQUIRE(compress("aabbccddd").compare("a2b2c2d3") == 0);
    REQUIRE(compress("aabcccccaaa").compare("a2b1c5a3") == 0);
    REQUIRE(compress("pppqqqiiiaabc").compare("p3q3i3a2b1c1") == 0);
    REQUIRE(compress("aaabbccuueettiioo").compare("a3b2c2u2e2t2i2o2") == 0);
}

TEST_CASE("Long compressible","[compressible]"){
    REQUIRE(compress("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa").compare("a100") == 0);
    REQUIRE(compress("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb").compare("a100b100") == 0);
}
