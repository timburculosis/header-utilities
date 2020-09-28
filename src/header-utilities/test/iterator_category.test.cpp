#include <vector>

#include "catch.hpp"
#include "header-utilities/iterator_category.hpp"

using namespace njoy::utility;

TEST_CASE("iterator_category alias"){
  using type = std::vector<int>::iterator;
  using category = std::random_access_iterator_tag;
  auto value = std::is_same< iterator_category< type >, category >::value;
  REQUIRE( value );
  value = std::is_same< iterator_category< const type >, category >::value;
  REQUIRE( value );
  value = std::is_same< iterator_category< type& >, category >::value;
  REQUIRE( value );
  value = std::is_same< iterator_category< const type& >, category >::value;
  REQUIRE( value );
}
