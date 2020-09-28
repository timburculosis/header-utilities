#ifndef NJOY_UTILITY_IS_ITERATOR
#define NJOY_UTILITY_IS_ITERATOR

// system includes
#include <type_traits>

// other includes
#include "header-utilities/void_t.hpp"
#include "header-utilities/iterator_category.hpp"

namespace njoy {
namespace utility {

  /**
   *  @brief A metaprogram leveraging SFINAE to deduce whether a parameter
   *         type is an iterator
   */
  template< typename T, typename = void >
  struct is_iterator : std::false_type{};

  template< typename T >
  struct is_iterator< T, void_t< iterator_category<T> > > : std::true_type{};

} // utility namespace
} // njoy namespace

#endif
