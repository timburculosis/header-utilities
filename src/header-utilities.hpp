#ifndef NJOY_HEADER_UTILITIES
#define NJOY_HEADER_UTILITIES

#include <fstream>
#include <iterator>
#include <memory>
#include <type_traits>

#include "Log.hpp"

namespace njoy{
namespace utility{

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

/** @brief An alias to a parameter type's nested element_type alias */
template< typename T >
using element_type = typename std::decay_t<T>::element_type;

/**
 * @brief
 * An alias to a parameter type's nested iterator_category alias
 * (with special treament for pointers)
 */
template< typename T >
using iterator_category =
  typename std::iterator_traits< std::decay_t<T> >::iterator_category;

/** @brief An alias to a parameter type's nested iterator alias */
template< typename T >
using iterator = typename std::decay_t<T>::iterator;

#include "header-utilities/is_shared_ptr.hpp"
#include "header-utilities/is_unique_ptr.hpp"
#include "header-utilities/is_iterator.hpp"
#include "header-utilities/is_container.hpp"
#include "header-utilities/is_range.hpp"
#include "header-utilities/Require.hpp"
#include "header-utilities/value_t.hpp"
#include "header-utilities/exponentialSearch.hpp"
#include "header-utilities/src/dereference.hpp"

}
}

#endif

#include "header-utilities/copy.hpp"
#include "header-utilities/echoErroneousLine.hpp"
#include "header-utilities/slurpFileToMemory.hpp"
