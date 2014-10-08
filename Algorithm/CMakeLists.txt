include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


set(strtest_incs   algorithm/strtest.h	
                   algorithm/myString.h		  			  	  		
			)			
set(strtest_srcs  algorithm/strtest.cpp	
                  algorithm/myString.cpp		   		  
			)
			
set(sorttest_incs   algorithm/sorttest.h			  			  	  		
			)			
set(sorttest_srcs  algorithm/sorttest.cpp			   		  
			)
			
set(subsettest_incs   algorithm/subsettest.h			  			  	  		
			)			
set(subsettest_srcs  algorithm/subsettest.cpp			   		  
			)

set(simpletest_incs   algorithm/simpletest.h			  			  	  		
			)			
set(simpletest_srcs  algorithm/simpletest.cpp			   		  
			)			

set(binarytest_incs   algorithm/binarytest.h			  			  	  		
			)			
set(binarytest_srcs  algorithm/binarytest.cpp			   		  
			)		
set(treetest_incs   algorithm/treetest.h			  			  	  		
			)			
set(treetest_srcs  algorithm/treetest.cpp			   		  
			)	
set(linklisttest_incs 	algorithm/linklisttest.h		  			  	  		
			)			
set(linklisttest_srcs  algorithm/linklisttest.cpp			   		  
			)	
set(structtest_incs algorithm/Hash.h
                    algorithm/LinkedHash.h
					algorithm/minStack.h
					algorithm/CircledQueue.h
					algorithm/QueueWithStack.h
					algorithm/StackWithQueue.h
					algorithm/TrieTree.h
					algorithm/RedBlackTree.h
					algorithm/structtest.h
					)				
set(structtest_srcs algorithm/Hash.cpp
                    algorithm/LinkedHash.cpp
					algorithm/minStack.cpp
					algorithm/CircledQueue.cpp
					algorithm/QueueWithStack.cpp
					algorithm/StackWithQueue.cpp
					algorithm/TrieTree.cpp
					algorithm/RedBlackTree.cpp
					algorithm/structtest.cpp
					)
set(graphtest_incs algorithm/graph.h
    )	
set(graphtest_srcs algorithm/graph.cpp
    )	
set(bigInteger_incs algorithm/bigInteger.h
    )	
set(bigInteger_srcs algorithm/bigInteger.cpp
    )	
set(dptest_incs algorithm/dptest.h
    )	
set(dptest_srcs algorithm/dptest.cpp
    )	
	

set(incs    ${strtest_incs}
            ${sorttest_incs}
			${subsettest_incs}
			${simpletest_incs}
			${binarytest_incs}
			${treetest_incs}
			${linklisttest_incs}
			${structtest_incs}
			${graphtest_incs}
			${bigInteger_incs}
			${dptest_incs}
			include/test.h
            )
set(srcs    ${strtest_srcs}
            ${sorttest_srcs}
            ${subsettest_srcs}
			${simpletest_srcs}
			${binarytest_srcs}
			${treetest_srcs}
			${linklisttest_srcs}
			${structtest_srcs}
			${graphtest_srcs}
			${bigInteger_srcs}
			${dptest_srcs}
            src/main.cpp
            )



# Organize files
SOURCE_GROUP("StrTest\\include" FILES ${strtest_incs})
SOURCE_GROUP("StrTest\\src" FILES ${strtest_srcs} )
SOURCE_GROUP("SortTest\\include" FILES ${sorttest_incs})
SOURCE_GROUP("SortTest\\src" FILES ${sorttest_srcs})
SOURCE_GROUP("SubsetTest\\include" FILES ${subsettest_incs})
SOURCE_GROUP("SubsetTest\\src" FILES ${subsettest_srcs})
SOURCE_GROUP("SimpleTest\\include" FILES ${simpletest_incs})
SOURCE_GROUP("SimpleTest\\src" FILES ${simpletest_srcs})
SOURCE_GROUP("BinaryTest\\include" FILES ${binarytest_incs})
SOURCE_GROUP("BinaryTest\\src" FILES ${binarytest_srcs})
SOURCE_GROUP("TreeTest\\include" FILES ${treetest_incs})
SOURCE_GROUP("TreeTest\\src" FILES ${treetest_srcs})
SOURCE_GROUP("LinkListTest\\include" FILES ${linklisttest_incs})
SOURCE_GROUP("LinkListTest\\src" FILES ${linklisttest_srcs})
SOURCE_GROUP("StructTest\\include" FILES ${structtest_incs})
SOURCE_GROUP("StructTest\\src" FILES ${structtest_srcs})
SOURCE_GROUP("GraphTest\\include" FILES ${graphtest_incs})
SOURCE_GROUP("GraphTest\\src" FILES ${graphtest_srcs})
SOURCE_GROUP("BigTest\\include" FILES ${bigInteger_incs})
SOURCE_GROUP("BigTest\\src" FILES ${bigInteger_srcs})
SOURCE_GROUP("DPTest\\include" FILES ${dptest_incs})
SOURCE_GROUP("DPTest\\src" FILES ${dptest_srcs})



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
