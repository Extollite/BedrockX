#pragma once
#include"../Core.h"
#include <string>
#include <type_traits>

class CommandRegistry;
class CommandOrigin;
class CommandOutput;
class Actor;
class Player;

template <typename T> class CommandSelectorResults;


class CommandOutputParameter {
	std::string str;
	int type;

public:
	__declspec(dllimport) CommandOutputParameter(std::string const&);
	__declspec(dllimport) CommandOutputParameter(int);
	__declspec(dllimport) CommandOutputParameter(BlockPos);
	__declspec(dllimport) CommandOutputParameter(std::vector<Player const*> const&);
	__declspec(dllimport) CommandOutputParameter(std::vector<std::string> const&);

	inline CommandOutputParameter(std::string str, int type) : str(str), type(type) {}
};
class CommandOutput {
public:
  __declspec(dllimport) void success(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  __declspec(dllimport) void error(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  __declspec(dllimport) void addToResultList(std::string const &, Actor const &);
  template <typename T> void set(char const *name, T value);
};

class CommandOrigin;
class Actor;
class ActorDefinitionIdentifier;



template <typename T> class CommandSelector : public CommandSelectorBase {
public:
  inline CommandSelector() : CommandSelectorBase(std::is_same_v<T, Player>) {}
  __declspec(dllimport) CommandSelectorResults<T> results(CommandOrigin const &) const;
};
template <typename T> struct InvertableFilter {
  T value;
  bool inverted;
};
class CommandSelectorBase {
  uint32_t version;                                                                     // 0
  uint32_t type;                                                                        // 4
  uint32_t order;                                                                       // 8
  std::vector<InvertableFilter<std::string>> namefilters;                               // 16
  std::vector<InvertableFilter<ActorDefinitionIdentifier>> typefilter2;                 // 40
  std::vector<InvertableFilter<std::string>> tagfilters;                                // 64
  std::vector<std::function<bool(CommandOrigin const &, Actor const &)>> customfilters; // 88
  char position[16];                                                             // 112
  BlockPos box;                                                                         // 128
  float radiusMin;                                                                      // 140
  float radiusMax;                                                                      // 144 = 0x7f7fffff (float max)
  uint64_t resultCount;                                                                 // 152 = 0xFFFFFFFF
  bool includeDeadPlayers;                                                              // 160
  bool flag161;                                                                         // 161
  bool flag162;                                                                         // 162
  bool flag163;                                                                         // 163
  bool playerOnly;                                                                      // 164
  bool explicitIdSelector;                                                              // 165

public:
  inline bool isExplicitIdSelector() const { return explicitIdSelector; }
  inline void addNameFilter(InvertableFilter<std::string> const &filter) { namefilters.emplace_back(filter); }
  inline void addTagFilter(InvertableFilter<std::string> const &filter) {
    if (isExplicitIdSelector()) explicitIdSelector = false;
    tagfilters.emplace_back(filter);
  }
  inline void setIncludeDeadPlayers(bool value) { includeDeadPlayers = value; }
  inline void setResultCount(uint64_t value) { resultCount = value; }

  __declspec(dllimport) void addFilter(std::function<bool(CommandOrigin const &, Actor const &)>);
  __declspec(dllimport) void addTypeFilter(InvertableFilter<std::string> const &);
  __declspec(dllimport) CommandSelectorBase();
  __declspec(dllimport) void setBox(BlockPos);
  __declspec(dllimport) void setRadiusMin(float);
  __declspec(dllimport) void setRadiusMax(float);
  __declspec(dllimport) bool compile(CommandOrigin const &, std::string &);

protected:
  __declspec(dllimport) CommandSelectorBase(bool isPlayer);
};
static_assert(sizeof(CommandSelectorBase) == 166);
template <typename T>
class CommandSelectorResults {
  std::shared_ptr<std::vector<T *>> data;

public:
  auto begin() { return data->begin(); }
  auto end() { return data->end(); }
  auto count() const { return data->size(); }
  auto empty() const { return data->empty(); }
};