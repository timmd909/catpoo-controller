include_directories( "${PROJECT_BINARY_DIR}" )

add_executable (catpoo_controller
  main.cpp
  I2C.cpp
  I2C.h
)

target_link_libraries(catpoo_controller
  stdc++
  boost_program_options
)
