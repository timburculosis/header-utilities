#include "catch.hpp"

#include "header-utilities/slurpFileToMemory.hpp"

extern int testNumber;

using namespace njoy::utility;

SCENARIO("slurpFileToMemory"){
  GIVEN("a path to a file with known contents"){
    std::string path = "./reference_file.txt";
    std::string contents =
      "Yesterday, all my troubles seemed so far away\n"
      "Now it looks as though they’re here to stay\n"
      "Oh, I believe in yesterday\n";
    WHEN("the file at the specified path is slurped to memory"){
      auto trial = slurpFileToMemory( path );
      THEN("the returned string will match the known contents"){
        REQUIRE( contents == trial );
      }
    }
  }
  GIVEN("a path to a non-existent file"){
    THEN("the slurpFileToMemory function will throw"){
      std::string path = "foobarbaz.xyz";
      REQUIRE_THROWS( slurpFileToMemory( path ) );
    }
  }
}
