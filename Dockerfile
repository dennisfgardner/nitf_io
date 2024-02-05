FROM ubuntu:22.04
RUN apt update
RUN apt upgrade -y
RUN apt install -y libssl-dev
RUN apt install -y libcurl4-openssl-dev
RUN apt install -y build-essential
RUN apt install -y cmake
RUN apt install -y python3-pip
RUN apt install -y python3.10-venv
RUN python3 -m pip install -U pip
RUN pip install numpy opencv-python matplotlib simplekml
# build nitro
ENV USER=user
COPY /nitro /setup/nitro
WORKDIR /setup/nitro
RUN cmake -DPYTHON_VERSION=3.10 -S . -B ./build
RUN cmake --build ./build -j8
RUN cmake --build ./build --target install
# build opencv
COPY /opencv /setup/opencv
WORKDIR /setup/opencv
RUN cmake -DBUILD_LIST=core,imgcodecs,imgproc -DCMAKE_CXX_FLAGS="-fpermissive"  -S . -B ./build
RUN cmake --build ./build -j8
RUN cmake --build ./build --target install
WORKDIR /home/nitf_io/