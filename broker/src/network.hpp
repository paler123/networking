#pragma once

#include "tools/bidir_multimap.hpp"
#include <optional>
#include <string>

namespace networking::broker
{

struct Network {

  struct Node {
    std::string id;
    int prio;
  };
  template <typename T>
  using IsNode = std::enable_if_t<std::is_same_v<Node, std::decay_t<T>>>;

  template<typename T, typename = IsNode<T>>
  bool add(T&& node)
  {
    bool replaces_master = is_new_master(node.prio);
    auto inserted = nodes.left.insert({std::forward<std::string>(node.id), node.prio});
    // update prio if node already registered
    if (!inserted.second)
      throw std::logic_error("can't update node's priority");
    return replaces_master;
  }
  std::string get_master() const;
  std::optional<std::string> remove_node(std::string const & id);

private:
  bool is_new_master(int new_node_prio) const;
  containers::bidir_multimap<std::string, int> nodes;
};

}
