#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "loops.h"
#include "sequence.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test function get_gc_content")
{
	REQUIRE(get_gc_content("AGCTATAG")==0.375); 
	REQUIRE(get_gc_content("CGCTATAG")==0.50); 

}

TEST_CASE("Test function get_dna_complement")
{
	REQUIRE(get_dna_complement("AAAACCCGGT")=="ACCGGGTTTT"); 
	REQUIRE(get_dna_complement("CCCGGAAAAT")=="ATTTTCCGGG"); 

}

TEST_CASE("Test reverse_string")
{
	REQUIRE(reverse_string("AGCTATAG")=="GATATCGA"); 
	REQUIRE(reverse_string("CGCTATAG")=="GATATCGC");

}

// Helping to test code from the discussion board for this HW 
// TEST_CASE("Test the sample function")
// {
// 	REQUIRE(test_reverse("AGCTATAG")=="GATATCGA"); 

// }