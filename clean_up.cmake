
set(CMAKE_GENERATED_FILES 
        ${CMAKE_INSTALL_PREFIX}
        ${CMAKE_BINARY_DIR}
)

foreach(file ${CMAKE_GENERATED_FILES})

  if (EXISTS ${file})
     file(REMOVE_RECURSE ${file})
  endif()

endforeach(file)