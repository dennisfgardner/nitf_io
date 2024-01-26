#include "nitf_reader.hpp"
#include <opencv2/opencv.hpp>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

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
    nitf::FileHeader file_header = record.getHeader();
    print_nitf_header(file_header);

    int num_img_segs = std::stoi(file_header.getNumImages().toString());
    cout << "Number of Images: " << num_img_segs << "\n";
    for (int i = 0; i < num_img_segs; ++i){
        cout << "Current Image Segment: " << i << "\n";
        nitf::ComponentInfo img_seg_info = file_header.getImageInfo(i);
        print_img_seg_info(img_seg_info);
    }

    nitf::List image_segments = record.getImages();
    for (nitf::ImageSegment img_seg : image_segments){
        nitf::ImageSubheader img_seg_sub_hdr = img_seg.getSubheader();
        print_img_seg_header(img_seg_sub_hdr);

    }

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