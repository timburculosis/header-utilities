#ifndef NJOY_UTILITY_SLURPFILETOMEMORY
#define NJOY_UTILITY_SLURPFILETOMEMORY

// system includes
#include <string>
#include <fstream>

// other includes
#include "Log.hpp"

namespace njoy {
namespace utility {

  /**
   *  @brief Copies the contents of a file to a string
   */
  inline std::string
  slurpFileToMemory( const std::string& path ){
    std::string sink;
    std::ifstream input( path, std::ios::in | std::ios::binary | std::ios::ate );
    if ( not input ){
      Log::error( "File could not opened for reading" );
      Log::info( "Specified file path: {}", path );
      Log::info( "Error while slurping file to memory" );
      throw std::runtime_error("input file could not be opened");
    }
    const auto file_size = input.tellg();
    input.seekg( 0, std::ios::beg );
    sink.resize( file_size / sizeof(char) );
    input.read( &( sink[ 0 ] ), file_size );
    return sink;
  }

} // utility namespace
} // njoy namespace

#endif
