#pragma once

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/multiset_of.hpp>

namespace networking::containers
{
template <typename Id, typename Prio>
using bidir_multimap = boost::bimap<boost::bimaps::unordered_set_of<Id>, boost::bimaps::multiset_of<Prio>>;
}
