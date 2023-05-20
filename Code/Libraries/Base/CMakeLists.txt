set(SOURCES
  Object/object.c
  Memory/memnew.c
  )

build(Base shlib)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")

  add_compile_definitions(BASE_MEM_TRACE)

endif()
