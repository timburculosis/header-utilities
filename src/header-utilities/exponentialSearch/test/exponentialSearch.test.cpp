#include <random>

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "header-utilities/exponentialSearch.hpp"

using namespace njoy::utility;

SCENARIO("Exponential Search implementation"){
  GIVEN("a random list"){
    std::minstd_rand0 generator( 3091988 );
    std::uniform_int_distribution<int> distribution(0,1000);
    std::vector< int > instance;
    instance.reserve(100);
    int j = 100;
    while( --j ){ instance.push_back( distribution( generator ) ); }
    auto value = instance.front();
    std::sort( instance.begin(), instance.end() );

    THEN("the search implementation will match std::lower_bound"){
      REQUIRE( std::lower_bound( instance.begin(), instance.end(), value )
	       == exponentialSearch( instance.begin(), instance.end(), value ) );
    }

    THEN("the search implementation return end when a match is not found"){
      REQUIRE( instance.end()
	       == exponentialSearch( instance.begin(), instance.end(), 1001 ) );
    }
  }
}
