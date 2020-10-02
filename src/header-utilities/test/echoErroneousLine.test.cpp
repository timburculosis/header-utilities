#include <sstream>

#include "catch.hpp"
#include "header-utilities/echoErroneousLine.hpp"

std::stringstream ss;

using namespace njoy::utility;

SCENARIO("echoErroneousLine"){
  njoy::Log::add_sink(ss);
  std::string buffer("the error is here -> \n pretty cool huh?");
  auto begin = buffer.begin();
  auto it = std::next( begin, 20 );
  auto end = buffer.end();
  auto lineNumber = 10l;

  echoErroneousLine( begin, it, end, lineNumber );

  std::string referenceMessage =
    "[info] Error while parsing line 10\n"
    "\n"
    "the error is here -> \n"
    "~~~~~~~~~~~~~~~~~~~~^\n"
    "\n";

  REQUIRE( referenceMessage == ss.str() );
}
