#ifndef NJOY_UTILITY_ECHOERRONEOUSLINE
#define NJOY_UTILITY_ECHOERRONEOUSLINE

// system includes
#include <algorithm>
#include <iterator>
#include <string>

// other includes
#include "Log"

namespace njoy {
namespace utility {

  /**
   * @brief Dumps a line of text to screen, followed by cursor indicating the
	 *        source of the error
	 */
	template< typename Iterator >
	void echoErroneousLine( Iterator lineBegin, Iterator positionIterator,
			                   	const Iterator& end, long lineNumber ){
	  const auto lineEnd = std::find( positionIterator, end, '\n');
	  const auto position = std::distance( lineBegin, positionIterator );
	  Log::info( "Error while parsing line {}\n\n{}\n{}{}\n",
		           lineNumber,
		           std::string( lineBegin, lineEnd ),
		           std::string( position, '~' ), '^' );
	}

} // utility namespace
} // njoy namespace

#endif
