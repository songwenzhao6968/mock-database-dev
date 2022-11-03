//
// Created by Xiaoyuan Liu on 11/21/20.
// Edited by Songwen Zhao on 11/01/22.
//

#ifndef MULTIPARTY_DATABASE_PROVIDER_H
#define MULTIPARTY_DATABASE_PROVIDER_H

#include "database.h"

class Servers;  // client's view of the servers from data providers

enum ProviderType {
    BASIC_PROVIDER,
    LOCAL_PROVIDER,
    REMOTE_PROVIDER
};

class Provider {
public:
    ProviderType type;
    std::string name;
    Servers* servers;  // detect Providers on the same host
    Provider(std::string name, json& provider_config);
    virtual ~Provider();
    virtual std::string runQuery(const Query& q, bool is_master)=0;
};

class LocalProvider: public Provider {
public:
    std::unordered_map<std::string, Table*> managed_tables;
    Database db; // one provider has one database
    LocalProvider(std::string name, json& provider_config);
    ~LocalProvider() override;
    std::string runQuery(const Query& q, bool is_master) override;
};

#endif //MULTIPARTY_DATABASE_PROVIDER_H
