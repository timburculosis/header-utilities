#define CATCH_CONFIG_MAIN

#include <vector>
#include <list>

#include "catch.hpp"
#include "header-utilities/is_range.hpp"

using namespace njoy::utility;

SCENARIO( "is_range" ){

  REQUIRE( is_range< std::vector< int    > >::value );
  REQUIRE( is_range< std::vector< double > >{} );
  REQUIRE( is_range< std::list<   int    > >{} );
  REQUIRE( is_range< std::list<   double > >{} );
  REQUIRE( is_range< double[ 3 ] >{} );

  REQUIRE( not is_range< double >{} );
  REQUIRE( not is_range< int >{} );
} // SCENARIO
