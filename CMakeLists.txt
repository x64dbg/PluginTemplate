# At least 3.5 is required for CMAKE_MSVC_RUNTIME_LIBRARY
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# Set up a more familiar Visual Studio configuration
# Override these options with -DCMAKE_OPTION=Value
#
# See: https://cmake.org/cmake/help/latest/command/set.html#set-cache-entry
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG:FULL /INCREMENTAL:NO" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "/DEBUG:FULL /INCREMENTAL:NO" CACHE STRING "")
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "")

# Plugin project
project(PluginTemplate)

# Enable solution folder support
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# https://github.com/TheLartians/CPM.cmake/releases
include(CPM.cmake)

# Add x64dbg plugin SDK dependency
CPMAddPackage(
	NAME x64dbg
	GITHUB_REPOSITORY x64dbg/sdk
	GIT_TAG x64dbg_9f9b1ba1c03ffb9dc921b3e1f8615412c65723f5
)

#add_subdirectory(../x64dbg_sdk ${CMAKE_CURRENT_BINARY_DIR}/x64dbg)

# Create a plugin
configure_file(pluginconfig.h.in include/pluginconfig.h ESCAPE_QUOTES)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
)
x64dbg_plugin(${PROJECT_NAME}
	plugin.cpp
	plugin.h
	pluginmain.cpp
	pluginmain.h
	${CMAKE_CURRENT_BINARY_DIR}/include/pluginconfig.h
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/include)

# Set the plugin as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})