#include "nitf_reader.hpp"

using std::cout;

void print_version_info(){
    cout << "NITF Reader version ";
    cout  << NITF_READER_VERSION_MAJOR << "." << NITF_READER_VERSION_MINOR
          << "." << NITF_READER_VERSION_REVISION
          << " built on " << __DATE__ << " at " << __TIME__ << "\n"
          << "\tusing NITRO " << NITF_VERSION_MAJOR << "." << NITF_VERSION_MINOR
          << "." << NITF_VERSION_PATCH << "." << NITF_VERSION_BUILD << "\n"
          << "\tusing OpenCV "<< cv::getVersionString() << "\n";
}