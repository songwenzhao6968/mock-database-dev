//
// Created by Xiaoyuan Liu on 11/5/20.
// Edited by Songwen Zhao on 11/01/22.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "client.h"

int main(int argc, char* argv[]) {
    // deal with arguments
    std::vector<std::string> args;
    for (int i=1; i<argc; ++i) args.emplace_back(argv[i]);
    // parse config
    if (argc != 2 && argc != 3) {
        std::cerr << "Wrong argument number, exiting." << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream config_json_fstream(args[0]);
    json config;
    config_json_fstream >> config;
    if (argc == 2) {
        start_interactive_client(config);
    } else {  // argc == 3
        std::ifstream batched_sql(args[1]);
        process_batch_sql(config, batched_sql);
        batched_sql.close();
    }
    config_json_fstream.close();
    return 0;
}
//./mockdb_client ../example/data/config.json