cmake_minimum_required(VERSION 3.0)

set(C74_MIN_API_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../min-api)
include(${C74_MIN_API_DIR}/script/min-pretarget.cmake)


#############################################################
# MAX EXTERNAL
#############################################################


include_directories(
	"${C74_INCLUDES}"
	"${CMAKE_CURRENT_SOURCE_DIR}/../../dsp-filters/shared/DSPFilters/include"
)


file(GLOB DSP_FILTERS
	"${CMAKE_CURRENT_SOURCE_DIR}/../../dsp-filters/shared/DSPFilters/include/DSPFilters/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../dsp-filters/shared/DSPFilters/source/*.cpp"
)


set( SOURCE_FILES
	${PROJECT_NAME}.cpp
	${DSP_FILTERS}
)


add_library(
	${PROJECT_NAME}
	MODULE
	${SOURCE_FILES}
)


include(${C74_MIN_API_DIR}/script/min-posttarget.cmake)


#############################################################
# UNIT TEST
#############################################################

include(${C74_MIN_API_DIR}/test/min-object-unittest.cmake)
