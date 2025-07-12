#include "module.h"

Module::Module(std::string name, int ects) : ects_(ects), name_(name)
{
}

const std::string &Module::name() const { return name_; }

int Module::ects() const { return ects_; }

std::ostream &operator<<(std::ostream &os, Module &mod)
{
    os << "Module: " << mod.name() << ", ECTS: " << mod.ects() << std::endl;
}