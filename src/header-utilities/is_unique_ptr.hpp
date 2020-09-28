#ifndef NJOY_UTILITY_IS_UNIQUE_PTR
#define NJOY_UTILITY_IS_UNIQUE_PTR

// system includes
#include <memory>
#include <type_traits>

// other includes
#include "header-utilities/element_type.hpp"
#include "header-utilities/void_t.hpp"

namespace njoy {
namespace utility {

  /**
   *  @brief A metaprogram leveraging SFINAE to deduce whether a parameter type
   *         is an instantiation of the std::unique_ptr template
   */
  template< typename T, typename = void >
  struct is_unique_ptr : std::false_type{};

  template< typename T >
  struct is_unique_ptr< T, void_t< element_type<T> > > :
    std::integral_constant< bool, std::is_same
                                  < std::decay_t<T>,
                                    std::unique_ptr
                                    < element_type<T> > >::value >{};

} // utility namespace
} // njoy namespace

#endif
