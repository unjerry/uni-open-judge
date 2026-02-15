cmake_minimum_required(VERSION 3.12)
project(luogu)

# static link command
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(P15289 "P15289.cpp")
add_executable(P15289-generator "P15289-generator.cpp")
message("START")
file(GLOB LUOGU_IN_FILES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.in")
message(${LUOGU_IN_FILES})

foreach(f ${LUOGU_IN_FILES})
  add_custom_command(TARGET P15289 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${f}"
    "$<TARGET_FILE_DIR:P15289>/"
    VERBATIM
  )
endforeach()

message("CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}")
message("Found .in files count=${LUOGU_IN_FILES}")

foreach(f IN LISTS LUOGU_IN_FILES)
  message("  - ${f}")
endforeach()

message("END")
