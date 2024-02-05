# NITF IO

This repo shows examples of reading and writing National Image Transmission Format (NITF) files.
NITF input and output (IO) is done using the [NITRO library](https://github.com/mdaus/nitro).
In one example, the NITF image data is written out to a *.png using the [OpenCV library](https://github.com/opencv/opencv).
NITRO and OpenCV libraries are included as submodules and are under their own licenses.

## NITF Data

NITF data can be obtained from [Sensor Data Management Database](https://www.sdms.afrl.af.mil/index.php).
Specifically, this code was tested on the [WPAFB 2009 dataset](https://www.sdms.afrl.af.mil/index.php?collection=wpafb2009).

## Docker Container

The examples in this repo can be built in a container.
The Dockerfile will build NITRO and OpenCV.

```bash
docker build -t dennisfgardner/nitf_io:1.0 .
```

To build the code in this repo, mount the source and NITFs directories.

```bash
docker run -itv ./src:/home/nitf_io/src -v ./nitfs:/home/nitf_io/nitfs dennisfgardner/nitf_io:1.0 /bin/bash
```

The examples can be build using the following cmake command.

```bash
cmake -S ./src -B ./build
cmake --build ./build
```

## Example #1 Print NITF Header Information

`print_header <nitf_filepath>`

For example,

```bash
./build/print_header ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4
```

## Example #2 Read Image Segment(s) and Write Out as PNG(s)

This is useful to visualize the image segment data.

`write_images <nitf_filepath>`

For example,

```bash
./build/write_images ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4
```

## Example #3 Read In NITF and Write Out Same NITF

This is useful if the initial NITF is compressed and you'd like an uncompressed version.

`round_trip <input_nitf_filepath> <output_nitf_filepath>`

For example,

```bash
./build/round_trip ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4 output.ntf
```

## Memory Leak Checking

I used valgrind to check for memory leaks.

```bash
apt install valgrind

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/print_header ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/write_images ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./build/round_trip ./nitfs/WPAFB-21Oct2009/Data/TRAIN/NITF/20091021203206-01000611-VIS.ntf.r4 output.ntf
```
