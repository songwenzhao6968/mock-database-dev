# Mock Database

Mock database implemention and example, for a distributed private database management system for privacy-preserving and information retrieval and aggregation from multiple parties.

## Installation

### Dependencies

- CMake >= 3.12, GNU G++ >= 6.0 or Clang++ >= 5.0 
### Compilation

```shell script
mkdir build && cd build
cmake ..
make
```

## Usage

- Interactive mode

```shell script
./mockdb_client <JSON configuration file location>
# example: ./mockdb_client ../example/data/config.json
```

- Batch processing mode

```shell script
./mockdb_client <JSON configuration file location> <SQL file location>
# example: ./mockdb_client ../example/data/config.json ../example/data/client/query.sql
```
