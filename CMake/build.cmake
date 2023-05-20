function(_template_cmake function name additional_args sources)

  cmake_language(CALL ${function} ${name} ${additional_args} ${SOURCES})

endfunction()

function(_app app_name)

  _template_cmake(add_executable "" ${app_name} ${SOURCES})
  target_include_directories(${app_name} PUBLIC .)

endfunction()

function(_stlib stlib_name)

  _template_cmake(add_library ${stlib_name} "STATIC" ${SOURCES})
  target_include_directories(${stlib_name} PUBLIC .)

endfunction()

function(_shlib shlib_name)

  _template_cmake(add_library ${shlib_name} "SHARED" ${SOURCES})
  target_include_directories(${shlib_name} PUBLIC .)

endfunction()

function(build target_name _target_build_type)

  if(NOT _target_build_type)

    message(FATAL_ERROR "Unknown target type.")

  endif()

  cmake_language(CALL _${_target_build_type} ${target_name})

  message(STATUS "| Component added to build: ${target_name}")

endfunction()
