#include <iostream>
#include <string>

#include <import/str.h>
#include <import/sys.h>

#include <import/nitf.hpp>

using std::cout;
using std::string;

int main(){
    cout << "Hello World!\n";

    string nitf_filepath = "./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r5";
    nitf::Version ver = nitf::Reader::getNITFVersion(nitf_filepath);
    cout << ver << std::endl;

    cout << "opening file" << "\n";
    nitf::IOHandle handle(nitf_filepath);
    nitf::Reader reader;
    nitf::Record record = reader.read(handle);

    return EXIT_SUCCESS;
}