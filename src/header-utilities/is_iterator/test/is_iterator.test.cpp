#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"
#include "header-utilities/is_iterator.hpp"

using namespace njoy::utility;

TEST_CASE("is_iterator"){
  using type = std::vector<int>;
  using type_iterator = type::iterator;

  REQUIRE( is_iterator< type_iterator >::value );
  REQUIRE( is_iterator< type_iterator& >::value );
  REQUIRE( is_iterator< const type_iterator >::value );
  REQUIRE( is_iterator< const type_iterator& >::value );

  REQUIRE( not is_iterator< type >::value );
  REQUIRE( not is_iterator< type& >::value );
  REQUIRE( not is_iterator< const type >::value );
  REQUIRE( not is_iterator< const type& >::value );
}
