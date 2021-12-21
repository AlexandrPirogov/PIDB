project(myGreatProject)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

include_directories(${CMAKE_SOURCE_DIR}/../../FileHandlerPI/)
link_directories(${CMAKE_SOURCE_DIR}/../../FileHandlerPI/)

include_directories(${CMAKE_SOURCE_DIR}/../../ExecMachine/)
link_directories(${CMAKE_SOURCE_DIR}/../../ExecMachine/)

include_directories(${CMAKE_SOURCE_DIR}/../../CompilerPI/)
link_directories(${CMAKE_SOURCE_DIR}/../../CompilerPI/)

include_directories(${CMAKE_SOURCE_DIR}/../../Schemes/)
link_directories(${CMAKE_SOURCE_DIR}/../../Schemes/)

add_executable(${PROJECT_NAME}
    ${SRC_LIST}
    ${CMAKE_SOURCE_DIR}/../../FileHandlerPI/FileHandler.h
    ${CMAKE_SOURCE_DIR}/../../FileHandlerPI/FileHandler.cpp
    ${CMAKE_SOURCE_DIR}/../../ExecMachine/ExecuteMachine.h
    ${CMAKE_SOURCE_DIR}/../../ExecMachine/ExecuteMachine.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Parser.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Parser.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/SyntaxParser.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/SyntaxParser.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Node.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Node.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Tree.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Tree.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/SelectTree.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/SelectTree.cpp
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Compiler.h
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/Compiler.cpp
    ${CMAKE_SOURCE_DIR}/../../Schemes/Scheme.h
    ${CMAKE_SOURCE_DIR}/../../Schemes/Scheme.cpp
    ${CMAKE_SOURCE_DIR}/../../Schemes/crudStatuses.h
    ${CMAKE_SOURCE_DIR}/../../Schemes/crudTable.h
    ${CMAKE_SOURCE_DIR}/../../Schemes/crudTable.cpp
    ${CMAKE_SOURCE_DIR}/../../Schemes/Row.h
    ${CMAKE_SOURCE_DIR}/../../Schemes/Row.cpp
    ${CMAKE_SOURCE_DIR}/../../Schemes/Table.h
    ${CMAKE_SOURCE_DIR}/../../Schemes/Table.cpp
)
    
target_link_libraries(${PROJECT_NAME}
    ${wxWidgets_LIBRARIES}
    ${CMAKE_SOURCE_DIR}/../../FileHandlerPI/
    ${CMAKE_SOURCE_DIR}/../../ExecMachine/  
    ${CMAKE_SOURCE_DIR}/../../CompilersPI/
    ${CMAKE_SOURCE_DIR}/../../Schemes/
 
)




