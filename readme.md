# Multiparty Database

Distributed private database management system for privacy-preserving and information retrieval and aggregation from multiple parties.

## Installation

### Dependencies

- CMake >= 3.12, GNU G++ >= 6.0 or Clang++ >= 5.0 
   (Clang++ is claimed to provide better performance for SEAL)

- antlr4 (used for SQL parser)
```shell script
# install antlr4
sudo pacman -S antlr4 antlr4-runtime          # on archlinux
sudo apt install libantlr4-runtime-dev antlr4 # on ubuntu
brew install antlr@4 antlr4-cpp-runtime       # on macOS
```

- Microsoft SEAL (for detailed instructions, see [this link](https://github.com/microsoft/SEAL#building-microsoft-seal))

```shell script
# update SEAL
git submodule update --init --recursive lib/SEAL
cd lib/SEAL
# compile details: alternatively use
# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=~/mylibs -DCMAKE_C_COMPILER=$(which clang) -DCMAKE_CXX_COMPILER=$(which clang++)
# for more, see the Microsoft SEAL instruction
cmake -S . -B build
cmake --build build
sudo cmake --install build
```



### Compilation

```shell script
# 1. build from cmake
mkdir build && cd build
# Note: if SEAL is not installed with sudo, run:
# export CMAKE_PREFIX_PATH=$HOME/mylibs:$CMAKE_PREFIX_PATH
cmake .. -DCMAKE_BUILD_TYPE=Release # use =Debug if debugging is needed
make  # or use: 'make -j' to compile faster
```


### Testing
Upon compiling the project, in addition to `mdb_client`, several testing exectuables will be generated. Run these executables to verify that the project's components are working correctly.
```shell script
./mdb_test # Tests utils, database, json dependency
./mdb_test_exetree # Tests execution tree
./mdb_test_protocol_sim # Probabilistically tests simulation of protocol
./mdb_test_seal # Tests MS Seal library's correctness
```
The tests are written with the [Catch2](https://github.com/catchorg/Catch2/tree/v2.x) testing framework. The tests are passing if running each executable generates output similar to below.
```shell script
> ./mdb_test
===============================================================================
All tests passed (29 assertions in 10 test cases)
```
*Note*: All testing executables except for `mdb_test` currently run without Catch2. They will be converted to use the framework in the near future.

## Usage

- Interactive mode

```shell script
./mdb_client <JSON configuration file location>
# example: ./mdb_client ../example/2p_retrieval/data/config.json
```

- Batch processing mode

```shell script
./mdb_client <JSON configuration file location> <SQL file location>
# example: ./mdb_client ../example/2p_retrieval/data/config.json ../example/2p_retrieval/data/client/query.sql 
```

## Example

- 2P Secure Aggregation with only equality checks

```shell script
./mdb_client ../example/2p_aggregation/data/config.json \
  ../example/2p_aggregation/data/client/simple_query.sql \
  | tee example_1_result.txt
```

- CTI

```shell script
# download the dataset
git submodule update --init --recursive example/cti
# query how many records are from the specific organizations
./mdb_client ../example/cti/config.json ../example/cti/queries/org_stat.sql
# check the existence of specific IOC using the shorten hash value
./mdb_client ../example/cti/config.json ../example/cti/queries/single_address.sql
# check the existence of specific IOC using the exact hash value
./mdb_client ../example/cti/config.json ../example/cti/queries/single_address_precise.sql
# use OR operator to check multiple IOC at once (optimized order)
./mdb_client ../example/cti/config.json ../example/cti/queries/batch_address_8_opt.sql
# use OR operator to check multiple IOC at once
./mdb_client ../example/cti/config.json ../example/cti/queries/batch_address_8.sql
```

## Contributing to this Repository

To contribute to this repository, please submit your changes as either
* A fork of this repository
* A branch on this repository if you have been added as a contributor

Once you feel your changes are ready, please follow the instructions and check the boxes laid out in the pull request template.
