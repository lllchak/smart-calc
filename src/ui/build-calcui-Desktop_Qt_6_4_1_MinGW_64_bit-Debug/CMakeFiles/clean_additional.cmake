# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\calcui_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\calcui_autogen.dir\\ParseCache.txt"
  "calcui_autogen"
  )
endif()
