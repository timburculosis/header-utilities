#ifndef NJOY_UTILITY_IS_RANGE
#define NJOY_UTILITY_IS_RANGE

// system includes
#include <iterator>
#include <type_traits>

// other includes
#include "header-utilities/void_t.hpp"

namespace njoy {
namespace utility {

  template< typename R, typename=void >
  struct is_range : std::false_type { };

  template< typename R >
  struct is_range< R,
    void_t<
      decltype( std::begin( std::declval< R& >() ) ),
      decltype( std::end  ( std::declval< R& >() ) )
               >  > : std::true_type {
  };

} // utility namespace
} // njoy namespace

#endif
