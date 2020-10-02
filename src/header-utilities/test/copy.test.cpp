#include <vector>

#include "catch.hpp"
#include "header-utilities/copy.hpp"

using namespace njoy::utility;

TEST_CASE("copy function template"){
  std::vector<int> lvalue{0,1,2,3,4};
  auto copiedValue = copy(lvalue);
  REQUIRE( lvalue == copiedValue );
}
