#ifndef NJOY_UTILITY_VALUE_T
#define NJOY_UTILITY_VALUE_T

// system includes

// other includes
#include "header-utilities/is_range.hpp"
#include "header-utilities/Require.hpp"

namespace njoy {
namespace utility {

  template< typename R,
            Require< true, is_range, std::decay_t< R > > = true >
  struct value {
    using type = std::decay_t< decltype( *( std::declval< R >().begin() ) ) >;
  };

  template< typename R >
  using value_t = typename value< R >::type;

} // utility namespace
} // njoy namespace

#endif
