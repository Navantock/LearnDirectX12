# Exe
add_executable (D3DSample "main.cpp" "main.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET D3DSample PROPERTY CXX_STANDARD 20)
endif()


set( SRC_FILES
    main.cpp
)

add_executable(  WIN32
    ${HEADER_FILES} 
    ${SRC_FILES}
)

target_link_libraries( D3DSample
    d3d12.lib
    dxgi.lib
    dxguid.lib
)
# TODO: 如有需要，请添加测试并安装目标。
