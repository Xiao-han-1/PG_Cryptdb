project(autoexport)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${autoexport_BINARY_DIR}/bin)
add_subdirectory(sub)
add_library(objlib OBJECT objlib.c)
set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)
add_library(autoexport SHARED hello.cxx world.cxx foo.c $<TARGET_OBJECTS:objlib>)
add_library(autoexport3 SHARED cppCLI.cxx)
if(MSVC AND NOT MSVC_VERSION VERSION_LESS 1600
  AND NOT CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
  set_property(TARGET autoexport3 PROPERTY COMMON_LANGUAGE_RUNTIME "")
endif()

add_executable(say say.cxx)
if(MSVC)
  set_target_properties(say PROPERTIES ENABLE_EXPORTS ON)
  add_library(autoexport_for_exec SHARED hello2.c)
  target_link_libraries(autoexport_for_exec say)
  if(NOT MSVC_VERSION VERSION_LESS 1600 AND
    NOT CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
    enable_language(ASM_MASM)
    target_sources(autoexport PRIVATE nop.asm)
    set_property(SOURCE nop.asm PROPERTY COMPILE_FLAGS /safeseh)
    target_compile_definitions(say PRIVATE HAS_JUSTNOP)
  endif()
endif()
target_link_libraries(say autoexport autoexport2 autoexport3)
