#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "decisions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test get_letter_grade_using_if ")
{
	REQUIRE("A" == get_letter_grade_using_if(95));
	REQUIRE("B" == get_letter_grade_using_if(85));
	REQUIRE("C" == get_letter_grade_using_if(75));
	REQUIRE("D" == get_letter_grade_using_if(65));
	REQUIRE("F" == get_letter_grade_using_if(50));
}

TEST_CASE("Test get_letter_grade_using_switch ")
{
	REQUIRE("A" == get_letter_grade_using_switch(95));
	REQUIRE("B" == get_letter_grade_using_switch(85));
	REQUIRE("C" == get_letter_grade_using_switch(75));
	REQUIRE("D" == get_letter_grade_using_switch(65));
	REQUIRE("F" == get_letter_grade_using_switch(50));
}