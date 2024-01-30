#ifndef NITF_READER_HEADER
#define NITF_READER_HEADER

#include <string>
#include <iostream>
#include <filesystem>

#include <import/nitf.hpp>
#include <opencv2/opencv.hpp>

#define NITF_READER_VERSION_MAJOR 1
#define NITF_READER_VERSION_MINOR 0
#define NITF_READER_VERSION_REVISION 0

#define PRINT_FIELD(x) cout << "\t" << (#x) << ": " << (x) << "\n"

void print_nitf_header(nitf::FileHeader);
void print_img_seg_info(nitf::ComponentInfo);
void print_img_seg_header(nitf::ImageSubheader);

// helper functions
void print_version_info();



#endif