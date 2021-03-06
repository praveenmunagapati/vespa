// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include <vespa/vespalib/stllike/string.h>
#include <map>

namespace vespalib {

class Stash;

namespace eval {

struct BinaryOperation;

/**
 * Enumeration of all different aggregators that are allowed to be
 * used in tensor reduce expressions.
 **/
enum class Aggr { AVG, COUNT, PROD, SUM, MAX, MIN };

/**
 * Utiliy class used to map between aggregator enum value and symbolic
 * name. For example Aggr::AVG <-> "avg".
 **/
class AggrNames {
private:
    static const AggrNames _instance;
    std::map<vespalib::string,Aggr> _name_aggr_map;
    std::map<Aggr,vespalib::string> _aggr_name_map;
    void add(Aggr aggr, const vespalib::string &name);
    AggrNames();
public:
    static const vespalib::string *name_of(Aggr aggr);
    static const Aggr *from_name(const vespalib::string &name);
};

/**
 * Interface defining a general purpose aggregator that can be re-used
 * to aggregate multiple groups of values. Each number group is
 * aggregated by calling 'first' once, followed by any number of calls
 * to 'next', before finally calling 'result' to obtain the
 * aggregation result. The 'create' function acts as a factory able to
 * create Aggregator instances for all known aggregator enum values
 * defined above.
 **/
struct Aggregator {
    virtual void first(double value) = 0;
    virtual void next(double value) = 0;
    virtual double result() const = 0;
    virtual ~Aggregator();
    static Aggregator &create(Aggr aggr, Stash &stash);
};

} // namespace vespalib::eval
} // namespace vespalib
