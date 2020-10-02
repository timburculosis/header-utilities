#ifndef NJOY_UTILITY_DEREFERENCE
#define NJOY_UTILITY_DEREFERENCE

// system includes

// other includes
#include "header-utilities/void_t.hpp"

namespace njoy {
namespace utility {

  template< typename T, typename = void >
  constexpr bool is_dereferencable = false;

  template< typename T >
  constexpr bool is_dereferencable
                 < T, void_t< decltype( *( std::declval<T>() ) ) > > = true;

  template< typename T, std::enable_if_t< is_dereferencable<T>, bool > = true >
  decltype(auto) dereference( T&& t ){ return *t; }

  template< typename T,
            std::enable_if_t< not is_dereferencable<T>, bool > = true >
  decltype(auto) dereference( T&& t ){ return t; }

} // utility namespace
} // njoy namespace

#endif
