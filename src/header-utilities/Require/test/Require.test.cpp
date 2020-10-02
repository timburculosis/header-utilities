#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities/Require.hpp"

using namespace njoy::utility;

template< typename T, Require< true, std::is_integral, T > = true >
bool integrality( const T& ){ return true; }

template< typename T, Require< false, std::is_integral, T > = true >
bool integrality( const T& ){ return false; }

template< typename T, Require< true, std::is_object, T > = true >
bool objected( const T& ){ return true; }

template< typename T, Require< false, std::is_object, T > = true >
bool objected( const T& ){ return false; }

SCENARIO( "Require" ){
  GIVEN( "several container types" ){

    CHECK( integrality( 1 ) );
    CHECK( not integrality( std::vector< int >{} ) );
    CHECK( not integrality( 1.0 ) );

    CHECK( objected( std::vector< int >{} ) );
    CHECK( objected( 1 ) );
    CHECK( objected( 1.0 ) );

  } // GIVEN
} // SCENARIO
