#ifndef NJOY_UTILITY_VOID_T
#define NJOY_UTILITY_VOID_T

// system includes

// other includes

namespace njoy {
namespace utility {

  /**
   * @brief
   * A alias template used for as a template type parameter to enable SFINAE
   *
   * @details
   * The void_t template is useful for implementing the so-called detection
   * idiom to provide rudimentary compile-time reflection in C++. See the
   * is_iterator template later in this library for a simple executable example,
   * of the use of this template in pratice.
   */
  template< class... >
  using void_t = void;

} // utility namespace
} // njoy namespace

#endif
