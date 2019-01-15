#include "DATA.h"
std::map<std::string, boost::shared_ptr<IDna> > Data::s_sequencekey;
std::map<std::string, boost::shared_ptr<IDna> > Data::s_sequencename;
std::map<boost::shared_ptr<IDna>, std::string> Data::s_status;
