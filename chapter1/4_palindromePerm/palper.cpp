#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>

#include "catch.hpp"

/*
Given a string, write a function to check if it is a permutation of a 
palindrome. a palindrome is a work or phrase that is the same forwards 
and backwards. A permutation is a rearrangemen tof letters. 
The palindrome does not need to be limited to just dictionary words.
*/

//Palindrome: AT MOST one char with odd frequency
//Permutation: order of characters is now irrelevant

bool palper(std::string input){
	char * cstr = new char[input.length() + 1];
	std::strcpy(cstr, input.c_str());
	std::vector<char> unique_chars;
	std::unordered_map<char, int> freq;

	for(int i = 0; i < input.length(); i++){
		if(cstr[i] == ' '){
			continue;
		}
		if(freq.count(cstr[i]) == 0){
			unique_chars.push_back(cstr[i]);
			freq.insert(std::make_pair(cstr[i], 1));
		}
		else{
			int old_count = freq.at(cstr[i]);
			freq.erase(cstr[i]);
			freq.insert(std::make_pair(cstr[i], old_count + 1));
		}
	}

	int odd_count = 0;
	for(int i = 0; i < unique_chars.size(); i++){
		if(freq.at(unique_chars[i]) % 2 != 0){
			++odd_count;
		}
		if(odd_count > 1){
			return false;
		}
	}
	return true;
}

TEST_CASE( "Valid input returns true", "[valid]" ) {
    REQUIRE( palper("tact coa") == true );
    REQUIRE( palper("tt") == true );
    REQUIRE( palper("123321") == true );
    REQUIRE( palper("123123") == true );
    REQUIRE( palper("`") == true );
    REQUIRE( palper("a but tuba") == true );
    REQUIRE( palper("a lad named e mandala") == true );
    REQUIRE( palper("alula") == true );
    REQUIRE( palper("naa") == true );
    REQUIRE( palper("wearedrawnnotonwardtonewera") == true );
    REQUIRE( palper("avid diva") == true );
    REQUIRE( palper("a slut nixes sex in tulsa") == true ); 
}

TEST_CASE( "Invalid input returns false", "[invalid]" ) {
    REQUIRE( palper("tact coas") == false );
    REQUIRE( palper("tttsss") == false );
    REQUIRE( palper("12332178") == false );
    REQUIRE( palper("123123-[") == false );
    REQUIRE( palper("`-[") == false );
    REQUIRE( palper("alulaa") == false );
    REQUIRE( palper("naat") == false );
    REQUIRE( palper("wearedrawnnotonwardtonewera-[") == false );
    REQUIRE( palper("avid divasd") == false );
    REQUIRE( palper("a slut nixes sexx in tulsaa") == false ); 
}