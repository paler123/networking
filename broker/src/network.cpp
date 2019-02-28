#include "network.hpp"

namespace networking::broker
{

std::string Network::get_master() const
{
  return nodes.right.rbegin()->second;
}

std::optional<std::string> Network::remove_node(std::string const & id)
{
  auto found = nodes.left.find(id);
  if (found == nodes.left.end())
    throw std::logic_error("trying to remove not existant node");
  bool was_master = found == nodes.project_left(std::prev(nodes.right.end()));
  nodes.left.erase(found);
  if (was_master && !nodes.empty())
    return get_master();
  return {};
}


bool Network::is_new_master(int new_node_prio) const
{
  return nodes.empty() || new_node_prio > nodes.right.rbegin()->first;
}

}

