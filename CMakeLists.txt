# CMakeList.txt: proyecto de CMake para plataform-sdl, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.22)

# Habilite Recarga activa para los compiladores de MSVC si se admiten.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("plataform-sdl")


if (WIN32)
    set(SDL2_DIR "vcpkg_installed/x64-windows/share/sdl2" CACHE PATH "Rute to SDL2" FORCE)
endif()

find_package(SDL2 CONFIG REQUIRED)


# Agregue un origen al ejecutable de este proyecto.
add_executable (plataform-sdl  "tools/Logger.cpp" "window/Window.cpp" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET plataform-sdl PROPERTY CXX_STANDARD 20)
endif()


target_compile_features(plataform-sdl PRIVATE cxx_std_20)
target_link_libraries(plataform-sdl PRIVATE SDL2::SDL2)
target_link_libraries(plataform-sdl PRIVATE SDL2::SDL2main)

if (WIN32)
    add_custom_command(
        TARGET plataform-sdl POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:plataform-sdl>"
        VERBATIM
    )
endif()
# TODO: Agregue pruebas y destinos de instalación si es necesario.
