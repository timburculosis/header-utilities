#ifndef NJOY_UTILITY_COPY
#define NJOY_UTILITY_COPY

// system includes

// other includes

namespace njoy {
namespace utility {

	/**
	 * @brief A generic function to call to a parameter types copy ctor
	 *
	 * @details
	 * This function is convenient in conjunction with the idiom of always accepting
	 * sink arguments by r-value reference (used throughout NJOY21 libraries). When
	 * passing an l-value to such a function, the user can opt to either explicitly
	 * move (using std::move) or explicitly copy (using utility::copy) the l-value.
	 */
	template< typename T >
	T copy( const T& t ) { return t; }

} // utility namespace
} // njoy namespace

#endif
