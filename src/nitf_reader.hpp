#ifndef NITF_READER_HEADER
#define NITF_READER_HEADER

#include <string>
#include <iostream>
#include <filesystem>

#include <import/nitf.hpp>

#define PRINT_FIELD(x) cout << "\t" << (#x) << ": " << (x) << "\n"

void print_nitf_header(nitf::FileHeader);
void print_img_seg_info(nitf::ComponentInfo);
void print_img_seg_header(nitf::ImageSubheader);


#endif