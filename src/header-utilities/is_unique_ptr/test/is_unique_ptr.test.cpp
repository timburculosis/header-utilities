#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities/is_unique_ptr.hpp"

using namespace njoy::utility;

TEST_CASE("is_unique_ptr"){
  using type = std::unique_ptr<int>;
  using notType = int;
  REQUIRE( is_unique_ptr< type >::value );
  REQUIRE( is_unique_ptr< const type >::value );
  REQUIRE( is_unique_ptr< type& >::value );
  REQUIRE( is_unique_ptr< const type& >::value );

  REQUIRE( not is_unique_ptr< notType >::value );
  REQUIRE( not is_unique_ptr< const notType >::value );
  REQUIRE( not is_unique_ptr< notType& >::value );
  REQUIRE( not is_unique_ptr< const notType& >::value );
}
