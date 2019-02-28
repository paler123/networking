#include "network.hpp"
#include <catch2/catch.hpp>

namespace
{
using namespace networking::broker;

TEST_CASE("master correctly updated on insertion", "[Network]")
{
  Network sut{};
  REQUIRE(sut.add(Network::Node{"1", 1}));
  REQUIRE(sut.add(Network::Node{"2", 3}));
  REQUIRE(!sut.add(Network::Node{"3", 2}));
}

TEST_CASE("throws when trying to insert same node twice", "[Network]")
{
  Network sut{};
  sut.add(Network::Node{"1", 2});
  REQUIRE_THROWS_AS(sut.add(Network::Node{"1", 5}), std::logic_error);
}

TEST_CASE("correctly updates master on insertion and removal")
{
  Network sut{};
  sut.add(Network::Node{"1", 1});
  sut.add(Network::Node{"2", 3});
  sut.add(Network::Node{"3", 2});

  REQUIRE(sut.get_master() == "2");

  auto new_master = sut.remove_node("2");
  REQUIRE(*new_master == "3");
  REQUIRE(sut.get_master() == "3");

  REQUIRE(!sut.remove_node("1"));

  REQUIRE(!sut.remove_node("3"));
}

TEST_CASE("throws on removal of nonexistant node", "[Network]")
{
  Network sut{};
  sut.add(Network::Node{"1", 1});

  REQUIRE_THROWS_AS(sut.remove_node("2"), std::logic_error);
}

}
