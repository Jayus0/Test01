cmake_minimum_required(VERSION 3.22)
project(DK)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../) #可执行文件生成在builder目录的上一层

include_directories(/usr/local/include)#yaml库头文件路径

add_executable(DK src/main.cpp include/dk.h src/dk.cpp include/dklog.h src/dklog.cpp include/communication.h src/communication.cpp src/HttpCommunication.cpp include/HttpCommunication.h src/UDPCommunication.cpp include/UDPCommunication.h src/TCPCommunication.cpp include/TCPCommunication.h src/DataAcquisition.cpp include/DataAcquisition.h src/RadarDataAcquisition.cpp include/RadarDataAcquisition.h)

target_include_directories(DK PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(DK /usr/local/lib/libyaml-cpp.a)#yaml库文件路径

