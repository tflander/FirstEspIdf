# This file is long and looks intimidating.  After you
# read the comments, strip all of them out and you will
# see that the file isn't quite so large or scary.
#######################################################

# CMake file for the unit tests 

# Windows (and maybe OSX) need this definition
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	add_definitions(-D__time_t_defined)
endif()

# Setting up include paths to get esp-idf header files
# include_directories(SYSTEM $ENV{IDF_PATH}/components/freertos/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/newlib/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/soc/esp32/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/esp32/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/esp_common/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/driver/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/soc/esp32/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/soc/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/heap/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/xtensa/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/xtensa/esp32/include)
# include_directories(SYSTEM $ENV{IDF_PATH}/components/esp_rom/include)
include_directories(${PROJECT_SOURCE_DIR}/build/config)


# FILE GLOBing: a unix concept where all files matching a wildcard
# pattern are collected as a group.

# A list of all of the files matching *.c in this directory
# will be assigned to the variable TEST_SRC
FILE(GLOB TEST_SRC *.c)

# A list of all of the files matching *.c in the MOCK_DIR directory
# will be assigned to the variable TEST_SRC (defined one level up)
FILE(GLOB MOCK_SRC ${MOCK_DIR}/*.c)

# A list of all src files in the System Under Test
FILE(GLOB SUT_SRC ../main/*.c)

# These make the mock directory and the unity directory 
# available as a source for header files, so if you have
# a file unity_fixture.h in the unity directory, you can 
# write  '#include <unity_fixture.h>' in a file and the
# compiler will know how to find it.
# This works the same for files under the mock directory.

include_directories(SYSTEM ${MOCK_DIR})
include_directories(SYSTEM ${UNITY_DIR})

# Tells cmake that we want to create an executable named 
# phonebooth-esp-idf-test (defined one level up).
add_executable(${PROJECT_TEST} ${TEST_SRC} ${SUT_SRC} ${MOCK_SRC})
add_custom_target(tdd ./${PROJECT_TEST}
	DEPENDS ${PROJECT_TEST}
	)

# This says the that executable phonebooth-esp-idf-test will be
# linked with the unity library.
target_link_libraries(${PROJECT_TEST} ${LIB_UNITY})
