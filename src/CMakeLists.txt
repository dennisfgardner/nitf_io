cmake_minimum_required(VERSION 3.20)
project(nitf_reader)
add_executable(nitf_reader main.cpp print_header.cpp)

target_include_directories(nitf_reader PUBLIC /usr/local/include/)
target_link_directories(nitf_reader PUBLIC /usr/local/lib)
target_link_libraries(
    nitf_reader libcgm-c.a libcli-c++.a libdbi-c++.a libexcept-c++.a
    libio-c++.a libj2k-c.a libjpeg.a liblogging-c++.a libmath-c++.a
    libmath.linear-c++.a libmem-c++.a libmt-c++.a libnitf-c++.a libnitf-c.a
    libnrt-c.a libnumpyutils-c++.a libopenjpeg.a libplugin-c++.a
    libpolygon-c++.a libsio.lite-c++.a libsys-c++.a libstr-c++.a libtiff-c++.a
    libtypes-c++.a libxerces-c.a libxml.lite-c++.a libz.a
)