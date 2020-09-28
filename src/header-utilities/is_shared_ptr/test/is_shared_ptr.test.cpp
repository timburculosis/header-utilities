#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities/is_shared_ptr.hpp"

using namespace njoy::utility;

TEST_CASE("is_shared_ptr"){
  using type = std::shared_ptr<int>;
  using notType = int;
  REQUIRE( is_shared_ptr< type >::value );
  REQUIRE( is_shared_ptr< const type >::value );
  REQUIRE( is_shared_ptr< type& >::value );
  REQUIRE( is_shared_ptr< const type& >::value );

  REQUIRE( not is_shared_ptr< notType >::value );
  REQUIRE( not is_shared_ptr< const notType >::value );
  REQUIRE( not is_shared_ptr< notType& >::value );
  REQUIRE( not is_shared_ptr< const notType& >::value );
}
