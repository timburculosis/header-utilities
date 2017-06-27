/**
 * @brief
 * Dumps a line of text to screen, followed by cursor indicating the source of 
 * the error */
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
