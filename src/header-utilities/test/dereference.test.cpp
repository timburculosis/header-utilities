#include "catch.hpp"
#include "header-utilities/dereference.hpp"

using namespace njoy::utility;

template< typename T >
struct echo;


TEST_CASE("dereference"){
  int i = 1;
  static_assert( std::is_same< int&, decltype( dereference(i) ) >::value, "" );
  REQUIRE( 1 == dereference(i) );

  const int ci = i;
  static_assert( std::is_same< const int&, decltype( dereference(ci) ) >::value,
                 "" );
  REQUIRE( 1 == dereference(ci) );

  int& ir = i;
  static_assert( std::is_same< int&, decltype( dereference(ir) ) >::value, "" );
  REQUIRE( 1 == dereference(ir) );

  const int& cir = ci;
  static_assert( std::is_same< const int&,
                               decltype( dereference(cir) ) >::value, "" );
  REQUIRE( 1 == dereference(cir) );

  int* ip = &i;
  static_assert( std::is_same< int&, decltype( dereference(ip) ) >::value, "" );
  REQUIRE( 1 == dereference(ip) );

  const int* cip = &ci;
  static_assert( std::is_same< const int&,
                               decltype( dereference(cip) ) >::value, "" );
  REQUIRE( 1 == dereference(cip) );
}
