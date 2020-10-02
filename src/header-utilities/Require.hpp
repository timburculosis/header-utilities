#ifndef NJOY_UTILITY_REQUIRE
#define NJOY_UTILITY_REQUIRE

// system includes

// other includes

namespace njoy {
namespace utility {

  template< bool TF,
            template< typename...> class Concept,
            typename... T
           >
  using Require = std::enable_if_t< Concept< T... >::value == TF, bool >;

} // utility namespace
} // njoy namespace

#endif
