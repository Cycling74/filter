cmake_minimum_required(VERSION 3.0)

project(filter)

if (APPLE)
	if (${CMAKE_GENERATOR} MATCHES "Xcode")
		if (${XCODE_VERSION} VERSION_LESS 7)
			message(STATUS "Xcode 7 or higher is required. Please install from the Mac App Store.")
			return ()
		elseif(${XCODE_VERSION} VERSION_GREATER_EQUAL 12)
			set(C74_BUILD_FAT YES)
		endif ()
	endif ()

	if (NOT CMAKE_OSX_ARCHITECTURES)
		if(C74_BUILD_FAT)
			set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "macOS architecture" FORCE)
		else()
			set(CMAKE_OSX_ARCHITECTURES ${CMAKE_SYSTEM_PROCESSOR} CACHE STRING "macOS architecture" FORCE)
		endif()
		message("CMAKE_OSX_ARCHITECTURES set to ${CMAKE_OSX_ARCHITECTURES}")
	endif()
endif()

# Misc setup and subroutines
include(${CMAKE_CURRENT_SOURCE_DIR}/source/min-api/script/min-package.cmake)

# Add unit tests for the API
enable_testing()

# Generate a project for every folder in the "source/projects" folder
SUBDIRLIST(PROJECT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/source/projects)
foreach (project_dir ${PROJECT_DIRS})
	if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/source/projects/${project_dir}/CMakeLists.txt")
		message("Generating: ${project_dir}")
		add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/projects/${project_dir})
	endif ()
endforeach ()
