cmake_minimum_required(VERSION 3.20)
project(nitf_reader)

# dependencies
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# print header executable
add_executable(
    print_header
    main_print_header.cpp
    print_nitf_header.cpp
    print_img_seg_info.cpp
    print_img_seg_header.cpp
    helpers.cpp
)
target_link_libraries( print_header ${OpenCV_LIBS} )
target_include_directories(print_header PUBLIC /usr/local/include/)
target_link_directories(print_header PUBLIC /usr/local/lib)
target_link_libraries(
    print_header libcgm-c.a libcli-c++.a libdbi-c++.a libexcept-c++.a
    libio-c++.a libj2k-c.a libjpeg.a liblogging-c++.a libmath-c++.a
    libmath.linear-c++.a libmem-c++.a libmt-c++.a libnitf-c++.a libnitf-c.a
    libnrt-c.a libnumpyutils-c++.a libopenjpeg.a libplugin-c++.a
    libpolygon-c++.a libsio.lite-c++.a libsys-c++.a libstr-c++.a libtiff-c++.a
    libtypes-c++.a libxerces-c.a libxml.lite-c++.a libz.a
)

# write out image segments
add_executable(
    write_images
    main_write_images.cpp
    print_nitf_header.cpp
    print_img_seg_info.cpp
    print_img_seg_header.cpp
    helpers.cpp
)
target_link_libraries( write_images ${OpenCV_LIBS} )
target_include_directories(write_images PUBLIC /usr/local/include/)
target_link_directories(write_images PUBLIC /usr/local/lib)
target_link_libraries(
    write_images libcgm-c.a libcli-c++.a libdbi-c++.a libexcept-c++.a
    libio-c++.a libj2k-c.a libjpeg.a liblogging-c++.a libmath-c++.a
    libmath.linear-c++.a libmem-c++.a libmt-c++.a libnitf-c++.a libnitf-c.a
    libnrt-c.a libnumpyutils-c++.a libopenjpeg.a libplugin-c++.a
    libpolygon-c++.a libsio.lite-c++.a libsys-c++.a libstr-c++.a libtiff-c++.a
    libtypes-c++.a libxerces-c.a libxml.lite-c++.a libz.a
)

# round tripping
# TODO