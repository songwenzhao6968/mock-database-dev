# Mock Database

Mock database for transaction record retrieval and aggregation from multiple brokers. 

## Description

### Schema

Transaction ID | UserID | Sector Name | Asset Name | Asset Type | Volume | Volume for buy | Volume for sell | Price | Price for buy | Price for sell | is_buy | Date

Primary Key: Transaction ID

### Supported Query

+ RETRIEVE, COUNT, SUM, AVG, MAX, MIN

+ EXIST

```sqlite
-- Output whether such record exist.
SELECT EXIST(column) FROM table_name WHERE predicates
```

+ AVG_CLOSING_PRICE

```sqlite
-- Output the sum of abs(Price) divided by the sum of abs(Volume) 
SELECT AVG_CLOSING_PRICE(*) FROM table_name WHERE predicates
```

+ COUNT_UNIQUE

```sqlite
-- Output the number of unique values in that column
SELECT COUNT_UNIQUE(column) FROM table_name WHERE predicates
```

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
