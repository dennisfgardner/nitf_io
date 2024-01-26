#include "nitf_reader.hpp"

using std::cout;
using std::string;


void print_img_seg_info(nitf::ComponentInfo img_seg_info){
    cout << "NITF Image Segment Information:\n";
    
    string length_of_image_subheader = img_seg_info.getLengthSubheader().toString();
    PRINT_FIELD(length_of_image_subheader);
    
    string length_of_image_segment = img_seg_info.getLengthData().toString();
    PRINT_FIELD(length_of_image_segment);

}
