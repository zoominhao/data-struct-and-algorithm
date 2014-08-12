include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/strtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sorttest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/subsettest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


set(strtest_incs   algorithm/strtest.h			  			  	  		
			)			
set(strtest_srcs  algorithm/strtest.cpp			   		  
			)
			
set(sorttest_incs   algorithm/sorttest.h			  			  	  		
			)			
set(sorttest_srcs  algorithm/sorttest.cpp			   		  
			)
			
set(subsettest_incs   algorithm/subsettest.h			  			  	  		
			)			
set(subsettest_srcs  algorithm/subsettest.cpp			   		  
			)
			

set(incs    ${strtest_incs}
            ${sorttest_incs}
			${subsettest_incs}
			include/test.h
            )
set(srcs    ${strtest_srcs}
            ${sorttest_srcs}
            ${subsettest_srcs}
            src/main.cpp
            )



# Organize files
SOURCE_GROUP("StrTest\\include" FILES ${strtest_incs})
SOURCE_GROUP("StrTest\\src" FILES ${strtest_srcs} )
SOURCE_GROUP("SortTest\\include" FILES ${sorttest_incs})
SOURCE_GROUP("SortTest\\src" FILES ${sorttest_srcs})
SOURCE_GROUP("SubsetTest\\include" FILES ${subsettest_incs})
SOURCE_GROUP("SubsetTest\\src" FILES ${subsettest_srcs})


# Put the ui in the windows project file
IF (${CMAKE_BUILD_TOOL} MATCHES "msdev")
  SET (srcs ${srcs})
ENDIF (${CMAKE_BUILD_TOOL} MATCHES "msdev")
IF (${CMAKE_BUILD_TOOL} MATCHES "devenv")
  SET (srcs ${srcs})
ENDIF (${CMAKE_BUILD_TOOL} MATCHES "devenv")

set(exe_name Algorithm)
add_executable(${exe_name} ${srcs} ${incs} )
#target_link_libraries(${exe_name} 
#)

if(WIN32 AND MSVC)
  set_target_properties(${exe_name} PROPERTIES LINK_FLAGS_RELEASE /OPT:REF)
elseif(CMAKE_SYSTEMname STREQUAL "Darwin")
  if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set_target_properties(${exe_name} PROPERTIES LINK_FLAGS -Wl)
  endif()
elseif(__COMPILER_PATHSCALE)
  set_target_properties(${exe_name} PROPERTIES LINK_FLAGS -mp)
else()
  set_target_properties(${exe_name} PROPERTIES LINK_FLAGS -Wl,--as-needed)
endif()

set_target_properties(${exe_name} PROPERTIES DEBUG_POSTFIX _debug)
set_target_properties(${exe_name} PROPERTIES RELEASE_POSTFIX _release)
