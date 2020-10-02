#ifndef NJOY_UTILITY_IS_CONTAINER
#define NJOY_UTILITY_IS_CONTAINER

// system includes
#include <type_traits>

// other includes
#include "header-utilities/iterator.hpp"
#include "header-utilities/void_t.hpp"

namespace njoy {
namespace utility {

  /**
   *  @brief  A metaprogram leveraging SFINAE to deduce whether a parameter
   *          type is a container
   */
  template< typename T, typename = void >
  struct is_container : std::false_type{};

  template< typename T >
  struct is_container< T, void_t< iterator<T> > > : std::true_type{};

} // utility namespace
} // njoy namespace

#endif
