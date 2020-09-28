#include "catch.hpp"
#include "header-utilities/element_type.hpp"

#include <memory>

using namespace njoy::utility;

TEST_CASE("element_type alias"){
  using type = std::shared_ptr<int>;
  auto value = std::is_same< element_type< type >, int >::value;
  REQUIRE( value );
  value = std::is_same< element_type< const type >, int >::value;
  REQUIRE( value );
  value = std::is_same< element_type< type& >, int >::value;
  REQUIRE( value );
  value = std::is_same< element_type< const type& >, int >::value;
  REQUIRE( value );
}
