#include <vector>

#include "catch.hpp"
#include "header-utilities.hpp"

using namespace njoy::utility;

TEST_CASE("is_smart_ptr"){
  using shared_type = std::shared_ptr<int>;
  using unique_type = std::unique_ptr<int>;
  using not_type = int;
  REQUIRE( is_smart_ptr< shared_type >::value );
  REQUIRE( is_smart_ptr< const shared_type >::value );
  REQUIRE( is_smart_ptr< shared_type& >::value );
  REQUIRE( is_smart_ptr< const shared_type& >::value );

  REQUIRE( is_smart_ptr< unique_type >::value );
  REQUIRE( is_smart_ptr< const unique_type >::value );
  REQUIRE( is_smart_ptr< unique_type& >::value );
  REQUIRE( is_smart_ptr< const unique_type& >::value );

  REQUIRE( not is_smart_ptr< not_type >::value );
  REQUIRE( not is_smart_ptr< const not_type >::value );
  REQUIRE( not is_smart_ptr< not_type& >::value );
  REQUIRE( not is_smart_ptr< const not_type& >::value );
}
