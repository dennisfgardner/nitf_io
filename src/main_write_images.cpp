#include "nitf_reader.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;


int main(int argc, char** argv){

    print_version_info();

    if (argc != 2){
        cerr << "ERROR: incorrect number of arguments\n";
        cerr << "correct usage: write_images <path_to_nitf_file>" << endl;
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

    nitf::Reader reader;
    nitf::Version nitf_version = reader.getNITFVersion(handle);
    if (IS_NITF20(nitf_version)){
        cout << "NITF file version: 2.0\n";
    } else if (IS_NITF21(nitf_version)){
        cout << "NITF file version: 2.1\n";

    } else {
        cerr << "ERROR: unsupported file" << endl;
        handle.close();
        return EXIT_FAILURE;
    }

    nitf::Record record = reader.read(handle);
    nitf::List image_segments = record.getImages();

    int img_cnt = 0;
    for (nitf::ImageSegment img_seg : image_segments){

        nitf::ImageSubheader img_seg_sub_hdr = img_seg.getSubheader();
        nitf::SubWindow sub_window(img_seg_sub_hdr);
        size_t abpp = img_seg_sub_hdr.actualBitsPerPixel();

        nitf::ImageReader img_reader = reader.newImageReader(img_cnt);

        nitf::BufferList<std::byte> data = img_reader.read(sub_window, abpp);

        cv::Mat img(sub_window.getNumRows(), sub_window.getNumCols(), CV_8UC1, data[0]);
        string output_filename = "output";
        output_filename += std::to_string(img_cnt);
        output_filename += ".png";
        cv::imwrite(output_filename, img);
        img_cnt++;
    }


    handle.close();
    cout << "NITF file closed." << "\n";

    return EXIT_SUCCESS;
}