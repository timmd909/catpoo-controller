include_directories(
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/lib/tclap/include/"
)

add_executable (catpoo_controller
  main.cpp
  I2C.cpp
  I2C.h
  Options.cpp
  Options.h
)

target_link_libraries(catpoo_controller
  stdc++
)
