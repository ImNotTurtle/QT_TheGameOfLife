# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TheGameOfLife_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TheGameOfLife_autogen.dir\\ParseCache.txt"
  "TheGameOfLife_autogen"
  )
endif()
