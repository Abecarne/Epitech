

cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
if (NOT boost_FOUND) # If there's none, fetch and build boost
  include(FetchContent)
  FetchContent_Declare(
    boost
      URL https://boostorg.jfrog.io/artifactory/main/release/1.75.0/source/boost_1_75_0.tar.gz
  )
  FetchContent_GetProperties(boost)
  if (NOT boost_POPULATED) # Have we downloaded boost yet?/src/entities/powerUp
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(boost)
  endif()
endif()