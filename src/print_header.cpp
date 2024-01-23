#include "nitf_reader.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


#define PRINT_FIELD(x) cout << "\t" << (#x) << ": " << (x) << "\n"


void print_header(nitf::FileHeader file_header){
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
}

