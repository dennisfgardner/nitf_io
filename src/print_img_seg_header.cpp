#include "nitf_reader.hpp"

using std::cout;
using std::string;


void print_img_seg_header(nitf::ImageSubheader img_seg_subheader){
    cout << "NITF Image Segment Subheader:\n";
    
    string file_part_type = img_seg_subheader.getFilePartType().toString();
    PRINT_FIELD(file_part_type);

    string image_identifier_one = img_seg_subheader.imageId();
    PRINT_FIELD(image_identifier_one);

    string image_date_and_time = img_seg_subheader.getImageDateAndTime().toString();
    PRINT_FIELD(image_date_and_time);

    string target_identifier = img_seg_subheader.getTargetId().toString();
    PRINT_FIELD(target_identifier);

    string image_identifier_two = img_seg_subheader.getImageTitle().toString();
    PRINT_FIELD(image_identifier_two);

    string image_security_classification = img_seg_subheader.imageSecurityClass();
    PRINT_FIELD(image_security_classification);

    string encryption = img_seg_subheader.getEncrypted().toString();
    PRINT_FIELD(encryption);

    string image_source = img_seg_subheader.getImageSource().toString();
    PRINT_FIELD(image_source);

    size_t number_significant_rows = img_seg_subheader.numRows();
    PRINT_FIELD(number_significant_rows);

    size_t number_significant_cols = img_seg_subheader.numCols();
    PRINT_FIELD(number_significant_cols);

    string pixel_value_type = img_seg_subheader.getPixelValueType().toString();
    PRINT_FIELD(pixel_value_type);

    string image_representation = img_seg_subheader.strImageRepresentation();
    PRINT_FIELD(image_representation);

    string image_category = img_seg_subheader.imageCategory();
    PRINT_FIELD(image_category);

    size_t actual_bits_per_pixel_per_band = img_seg_subheader.actualBitsPerPixel();
    PRINT_FIELD(actual_bits_per_pixel_per_band);

    string pixel_justification = img_seg_subheader.pixelJustification();
    PRINT_FIELD(pixel_justification);

    string image_coordinate_representation = img_seg_subheader.getImageCoordinateSystem().toString();
    PRINT_FIELD(image_coordinate_representation);

    string image_geographic_location = img_seg_subheader.getCornerCoordinates().toString();
    PRINT_FIELD(image_geographic_location);

    string number_image_components = img_seg_subheader.getNumImageComments().toString();
    PRINT_FIELD(number_image_components);

    string image_compression = img_seg_subheader.imageCompressionString();
    PRINT_FIELD(image_compression);

    string compression_rate_code = img_seg_subheader.getCompressionRate().toString();
    PRINT_FIELD(compression_rate_code);

    size_t number_bands = img_seg_subheader.numImageBands();
    PRINT_FIELD(number_bands);

    string number_multispectral_bands = img_seg_subheader.getNumMultispectralImageBands().toString();
    PRINT_FIELD(number_multispectral_bands);

    string image_sync_code = img_seg_subheader.getImageSyncCode().toString();
    PRINT_FIELD(image_sync_code);

    string image_mode = img_seg_subheader.imageMode();
    PRINT_FIELD(image_mode);

    size_t number_blocks_per_row = img_seg_subheader.numBlocksPerRow();
    PRINT_FIELD(number_blocks_per_row);

    size_t number_blocks_per_col = img_seg_subheader.numBlocksPerCol();
    PRINT_FIELD(number_blocks_per_col);

    size_t num_pixels_per_block_horizontal = img_seg_subheader.numPixelsPerHorizBlock();
    PRINT_FIELD(num_pixels_per_block_horizontal);

    size_t num_pixels_per_block_vertical = img_seg_subheader.numPixelsPerVertBlock();
    PRINT_FIELD(num_pixels_per_block_vertical);

    size_t num_bits_per_pixel_per_band = img_seg_subheader.numBitsPerPixel();
    PRINT_FIELD(num_bits_per_pixel_per_band);

    string image_display_level = img_seg_subheader.getImageDisplayLevel().toString();
    PRINT_FIELD(image_display_level);

    string attachment_level = img_seg_subheader.getImageAttachmentLevel().toString();
    PRINT_FIELD(attachment_level);

    string image_location = img_seg_subheader.imageLocation();
    PRINT_FIELD(image_location);

    string image_magnification = img_seg_subheader.getImageMagnification().toString();
    PRINT_FIELD(image_magnification);
}
