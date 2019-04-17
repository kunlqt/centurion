# Centurion Database Platform

## Build instructions

### Get Started

### Install docker
Docker is used for building Rocksplicator. Follow the [Docker installation instructions](https://docs.docker.com/engine/installation/) to get Docker running on your system.

### Get Centurion build Docker image

```sh
docker pull vaskomitanov/centurion-devel:latest
```

### Get Centurion source code
```sh
git clone https://github.com/vaskomitanov/centurion.git && cd centurion
```

### Run Centurion build docker container

```sh
docker run -it -w /centurion -v $PWD:/centurion -e HOST_PERMS="$(id -u):$(id -g)" vaskomitanov/centurion-devel bash
```

### While you are inside the build container
```sh
eexport BOOST_ROOT=/root/boost_1_69_0 && mkdir -p build && cd build && cmake .. && make -j
```

## Run instructions
```sh
cd centurionserver && ./centurionserver
```
