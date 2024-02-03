#include "nitf_reader.hpp"

using std::cout;
using std::cerr;
using std::endl;


int main(int argc, char **argv){

    print_version_info();

    if (argc != 3){
        cerr << "ERROR: incorrect number of arguments\n";
        cerr << "correct usage: round_trip <path_to_input_nitf> <path_to_output_nitf>" << endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path input_nitf_filepath(argv[1]);
    cout << "Input NITF filepath: \n\t" << input_nitf_filepath << "\n";
    if (!std::filesystem::exists(input_nitf_filepath)){
        cerr << "ERROR: input NITF does not exist" << endl;
        return EXIT_FAILURE;
    }

    std::filesystem::path output_nitf_filepath(argv[2]);
    cout << "Output NITF filepath: \n\t" << output_nitf_filepath << "\n";
    if (std::filesystem::exists(output_nitf_filepath)){
        cerr << "ERROR: output NITF already exists" << endl;
        return EXIT_FAILURE;
    }

    nitf::IOHandle input_handle(input_nitf_filepath);
    cout << "NITF file opened." << "\n";

    nitf::Reader reader;
    nitf::Version nitf_version = reader.getNITFVersion(input_handle);
    if (IS_NITF20(nitf_version)){
        cout << "NITF file version: 2.0\n";
    } else if (IS_NITF21(nitf_version)){
        cout << "NITF file version: 2.1\n";

    } else {
        cerr << "ERROR: unsupported file" << endl;
        input_handle.close();
        return EXIT_FAILURE;
    }

    // make of copy of the input and write it out
    nitf::Record record = reader.read(input_handle);
    nitf::Writer writer;
    nitf::IOHandle output_handle(output_nitf_filepath, NITF_ACCESS_WRITEONLY, NITF_CREATE);
    writer.prepare(output_handle, record);
    writer.setWriteHandlers(input_handle, record);
    writer.write();
    output_handle.close();
    cout << "NITF output file closed." << "\n";
    input_handle.close();
    cout << "NITF input file closed." << "\n";
    return EXIT_SUCCESS;
}
