#include <vector>

#include "catch.hpp"
#include "header-utilities/iterator.hpp"

using namespace njoy::utility;

TEST_CASE("iterator alias"){
  using type = std::vector<int>;
  using type_iterator = type::iterator;
  auto value = std::is_same< iterator< type >, type_iterator >::value;
  REQUIRE( value );
  value = std::is_same< iterator< const type >, type_iterator >::value;
  REQUIRE( value );
  value = std::is_same< iterator< type& >, type_iterator >::value;
  REQUIRE( value );
  value = std::is_same< iterator< const type& >, type_iterator >::value;
  REQUIRE( value );
}
