#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities.hpp"

using namespace njoy::utility;

SCENARIO( "Require" ){
  GIVEN( "several container types" ){
    double dRange[3];

  auto rVec = Require< true, isRange, std::vector< int > > {};
  auto rArr = Require< false, isRange, decltype( dRange ) > {};
  auto d = Require< false, isRange, double > {};
  CHECK( rVec );
  CHECK( rArr );
  CHECK( not d );

  auto cVec = Require< true, is_container, std::vector< int > > {};
  CHECK( cVec );
  } // GIVEN
} // SCENARIO
