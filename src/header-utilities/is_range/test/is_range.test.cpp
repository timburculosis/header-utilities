#define CATCH_CONFIG_MAIN

#include <vector>
#include <list>

#include "catch.hpp"
#include "header-utilities.hpp"

using namespace njoy::utility;

SCENARIO( "is_range" ){

  REQUIRE( isRange< std::vector< int    > >{} );
  REQUIRE( isRange< std::vector< double > >{} );
  REQUIRE( isRange< std::list<   int    > >{} );
  REQUIRE( isRange< std::list<   double > >{} );

  double a[3] = {};
  REQUIRE( isRange< decltype( a ) >{} ); // This should be true

  REQUIRE( not isRange< double >{} );
  REQUIRE( not isRange< int >{} );
} // SCENARIO
