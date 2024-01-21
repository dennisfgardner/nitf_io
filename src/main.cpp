#include <string>
#include <iostream>
#include <filesystem>

#include <import/str.h>
#include <import/sys.h>

#include <import/nitf.hpp>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

#define NITF_READER_VERSION_MAJOR 1
#define NITF_READER_VERSION_MINOR 0
#define NITF_READER_VERSION_REVISION 0

int main(int argc, char** argv){

    cout << "NITF Reader version ";
    cout  << NITF_READER_VERSION_MAJOR << "." << NITF_READER_VERSION_MINOR
          << "." << NITF_READER_VERSION_REVISION
          << " built on " << __DATE__ << " at " << __TIME__
          << "\n\tusing NITRO " << NITF_VERSION_MAJOR << "." << NITF_VERSION_MINOR
          << "." << NITF_VERSION_PATCH << "." << NITF_VERSION_BUILD << "\n";

    if (argc != 2){
        cerr << "ERROR: incorrect number of arguments\n";
        cerr << "correct usage: nitf_reader <path_to_nitf_file>" << endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path nitf_filepath(argv[1]);
    cout << "NITF filepath: \n\t" << nitf_filepath << "\n";
    if (!std::filesystem::exists(nitf_filepath)){
        cerr << "ERROR: filepath does not exist" << endl;
        return EXIT_FAILURE;
    }

    nitf::IOHandle handle(nitf_filepath);
    cout << "NITF file opened." << "\n";

    nitf::Version nitf_version = nitf::Reader::getNITFVersion(handle);
    if (IS_NITF20(nitf_version)){
        cout << "NITF file version: 2.0\n";
    } else if (IS_NITF21(nitf_version)){
        cout << "NITF file version: 2.1\n";

    } else {
        cerr << "ERROR: unsupported file" << endl;
        handle.close();
        return EXIT_FAILURE;
    }

    // nitf::Reader reader;
    // nitf::Record record = reader.read(handle);
    handle.close();
    cout << "NITF file closed." << "\n";

    return EXIT_SUCCESS;
}