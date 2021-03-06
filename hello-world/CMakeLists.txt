cmake_minimum_required(VERSION 3.12)

project(hello_world)
set(CMAKE_CXX_STANDARD 17)

set(MCU_SPEED "4000000UL")

###################################################################################
## some cmake cross-compile necessities
###################################################################################
#if(DEFINED ENV{AVR_FIND_ROOT_PATH})
#    set(CMAKE_FIND_ROOT_PATH $ENV{AVR_FIND_ROOT_PATH})
#else(DEFINED ENV{AVR_FIND_ROOT_PATH})
#    if(EXISTS "/opt/local/avr")
#        set(CMAKE_FIND_ROOT_PATH "/opt/local/avr")
#    elseif(EXISTS "/usr/avr")
#        set(CMAKE_FIND_ROOT_PATH "/usr/avr")
#    elseif(EXISTS "/usr/lib/avr")
#        set(CMAKE_FIND_ROOT_PATH "/usr/lib/avr")
#    elseif(EXISTS "/usr/local/CrossPack-AVR")
#        set(CMAKE_FIND_ROOT_PATH "/usr/local/CrossPack-AVR")
#    else(EXISTS "/opt/local/avr")
#        message(FATAL_ERROR "Please set AVR_FIND_ROOT_PATH in your environment.")
#    endif(EXISTS "/opt/local/avr")
#endif(DEFINED ENV{AVR_FIND_ROOT_PATH})
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
## not added automatically, since CMAKE_SYSTEM_NAME is "generic"
#set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/include")
#set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/lib")
#
###################################################################################
## status messages for generating
###################################################################################
#message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
#message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
#message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")
#
###################################################################################
## set compiler options for build types
###################################################################################
#if(CMAKE_BUILD_TYPE MATCHES Release)
#    set(CMAKE_C_FLAGS_RELEASE "-Os")
#    set(CMAKE_CXX_FLAGS_RELEASE "-Os")
#endif(CMAKE_BUILD_TYPE MATCHES Release)
#
#if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
#    set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
#    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
#endif(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
#
#if(CMAKE_BUILD_TYPE MATCHES Debug)
#    set(CMAKE_C_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
#    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
#endif(CMAKE_BUILD_TYPE MATCHES Debug)

##################################################################################
# compiler options for all build types
##################################################################################
add_definitions("-DF_CPU=${MCU_SPEED}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
# http://gcc.gnu.org/onlinedocs/gcc-4.8.2/gcc/Alternate-Keywords.html#Alternate-Keywords
# [...]-pedantic and other options cause warnings for many GNU C extensions. You can prevent such warnings within
# one expression by writing __extension__ before the expression. __extension__ has no effect aside from this.[...]
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
#  add_definitions("-funsigned-char")
#  add_definitions("-funsigned-bitfields")
#  add_definitions("-ffunction-sections")

add_definitions('-D__AVR_ATmega328P__')
add_definitions('-D__OPTIMIZE__')
add_definitions('-D__DELAY_BACKWARD_COMPATIBLE__')

add_executable(hello_world main.cpp)

