#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities/is_container.hpp"

using namespace njoy::utility;

TEST_CASE("is_container"){
  using type = std::vector<int>;
  using type_iterator = type::iterator;

  REQUIRE( not is_container< type_iterator >::value );
  REQUIRE( not is_container< type_iterator& >::value );
  REQUIRE( not is_container< const type_iterator >::value );
  REQUIRE( not is_container< const type_iterator& >::value );

  REQUIRE( is_container< type >::value );
  REQUIRE( is_container< type& >::value );
  REQUIRE( is_container< const type >::value );
  REQUIRE( is_container< const type& >::value );
}
