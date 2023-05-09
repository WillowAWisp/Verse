
add_library(core
  ast.c
  mem.c
  token.c
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_LIST_DIR})
