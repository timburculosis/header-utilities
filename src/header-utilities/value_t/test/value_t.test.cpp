#define CATCH_CONFIG_MAIN

#include <type_traits>
#include <vector>

#include "catch.hpp"
#include "header-utilities/value_t.hpp"

using namespace njoy::utility;

TEST_CASE( "value_t" ){

  auto b2 = std::is_same< double, value_t< std::vector< double > > >::value;
  auto b3 = std::is_same< int, value_t< std::vector< double > > >::value;
  CHECK( b2 );
  CHECK( not b3 );
}
