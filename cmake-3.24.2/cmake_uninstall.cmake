if(NOT EXISTS "/root/pakages/copy/cryptdb/cmake-3.24.2/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/root/pakages/copy/cryptdb/cmake-3.24.2/install_manifest.txt\"")
endif()

file(READ "/root/pakages/copy/cryptdb/cmake-3.24.2/install_manifest.txt" files)
string(REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if(EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/root/pakages/copy/cryptdb/cmake-3.24.2/Bootstrap.cmk/cmake" ARGS "-E rm -f \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if("${rm_retval}" STREQUAL 0)
    else()
      message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()
