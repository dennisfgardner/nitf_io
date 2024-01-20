# NITF READER

## Example NITF Data

[WPAFB 2009 DATASET](https://www.sdms.afrl.af.mil/index.php?collection=wpafb2009)

## Build Container

```bash
docker build -t dennisfgardner/nitf_reader:1.5 .
```

## Run Container (with volume mount)

```bash
docker run -itv ./src:/home/nitf_reader/src -v ./nitfs:/home/nitf_reader/nitfs dennisfgardner/nitf_reader:1.5 /bin/bash
```

## Build NITF Reader in Container

```bash
cmake -S ./src -B ./build
cmake --build ./build
```

## Run NITF Reader

```bash
./build/nitf_reader
```
