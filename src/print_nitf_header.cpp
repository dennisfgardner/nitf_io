#include "nitf_reader.hpp"

using std::cout;
using std::string;


void print_nitf_header(nitf::FileHeader file_header){
    cout << "NITF Header Information:\n";

    string file_profile_name = file_header.fileHeader();
    PRINT_FIELD(file_profile_name);

    string file_version = file_header.fileVersion();
    PRINT_FIELD(file_version);

    string complexity_level = file_header.getComplianceLevel().toString();
    PRINT_FIELD(complexity_level);

    string standard_type = file_header.getSystemType().toString();
    PRINT_FIELD(standard_type);

    string originating_station_ID = file_header.getOriginStationID().toString();
    PRINT_FIELD(originating_station_ID);

    string file_date_and_time = file_header.getFileDateTime().toString();
    PRINT_FIELD(file_date_and_time);

    string file_title = file_header.getFileTitle().toString();
    PRINT_FIELD(file_title);

    string file_security_classification = file_header.classification();
    PRINT_FIELD(file_security_classification);

    string encryption = file_header.getEncrypted().toString();
    PRINT_FIELD(encryption);

    string originators_name = file_header.getOriginatorName().toString();
    PRINT_FIELD(originators_name);

    string file_length = file_header.getFileLength().toString();
    PRINT_FIELD(file_length);

    string nitf_file_header_length = file_header.getHeaderLength().toString();
    PRINT_FIELD(nitf_file_header_length);

    string number_of_image_segments = file_header.getNumImages().toString();
    PRINT_FIELD(number_of_image_segments);

    string number_of_graphic_segments = file_header.getNumGraphics().toString();
    PRINT_FIELD(number_of_graphic_segments);

    string number_of_text_segments = file_header.getNumTexts().toString();
    PRINT_FIELD(number_of_text_segments);

    string number_of_data_segment_extensions = file_header.getNumDataExtensions().toString();
    PRINT_FIELD(number_of_data_segment_extensions);

    string number_of_reserved_extension_segments = file_header.getNumReservedExtensions().toString();
    PRINT_FIELD(number_of_reserved_extension_segments);
}

