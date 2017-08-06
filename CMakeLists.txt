PROJECT(final)

# cmake versionsv
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

FIND_PACKAGE(Boost COMPONENTS system program_options REQUIRED)

# cmake modules directory
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

#include compile settings
INCLUDE(compileFlags)

SET( HEADERS
	connection.hpp
	connection_manager.hpp
	header.hpp
	mime_types.hpp
	reply.hpp
	request.hpp
	request_handler.hpp
	request_parser.hpp
	server.hpp
)

SET( SOURCES
	connection.cpp
	connection_manager.cpp
	main.cpp
	mime_types.cpp
	reply.cpp
	request_handler.cpp
	request_parser.cpp
	server.cpp
)

INCLUDE_DIRECTORIES(
    ${Boost_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

ADD_EXECUTABLE(final ${SOURCES} ${HEADERS})

TARGET_LINK_LIBRARIES(
	final
	${Boost_LIBRARIES}
)
