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


enum class CommandFlagValue : char {
	None = 0,
	Usage = 1,
	Visibility2 = 2,
	Visibility4 = 4,
	Visibility6 = 6,
	Sync = 8,
	Execute = 16,
	Type = 32,
	Cheat = 64,
};

struct CommandFlag {
	CommandFlagValue value;
};
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
  __declspec(dllimport) void success(std::string const &str="", std::vector<CommandOutputParameter> const &params = {});
  __declspec(dllimport) void error(std::string const &, std::vector<CommandOutputParameter> const &params = {});
  __declspec(dllimport) void addToResultList(std::string const &, Actor const &);
  template <typename T> void set(char const *name, T value);
  void addMessage(
	  std::string const& str) {
	  Call("?addMessage@CommandOutput@@AEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEBV?$vector@VCommandOutputParameter@@V?$allocator@VCommandOutputParameter@@@std@@@3@W4CommandOutputMessageType@@@Z", void,void*, string const&, std::vector<CommandOutputParameter> const&, int)(this,str, {}, 0);
	}
};


enum class OriginType : char {
    Player = 0,
    Block = 1,
    MinecartBlock = 2,
    DevConsole = 3,
    Test = 4,
    AutomationPlayer = 5,
    ClientAutomation = 6,
    DedicatedServer = 7,
    Actor = 8,
    Virtual = 9,
    GameArgument = 10,
    ActorServer = 11
};

class CommandOrigin {
public:
    CommandOrigin(CommandOrigin const&) = delete;
    virtual ~CommandOrigin();
    virtual std::string getRequestId() const = 0;
    virtual std::string getName() const = 0;
    virtual BlockPos getBlockPosition() const = 0;
    virtual Vec3 getWorldPosition() const = 0;
    virtual Level* getLevel() const = 0;
    virtual Dimension* getDimension() const = 0;
    virtual Actor* getEntity() const = 0;
    virtual CommandPermissionLevel getPermissionsLevel() const = 0;
    virtual std::unique_ptr<CommandOrigin> clone() const = 0;
    virtual bool unk1() const = 0;
    virtual bool unk2() const = 0;
    virtual bool hasChatPerms() const = 0;
    virtual bool hasTellPerms() const = 0;
    virtual bool canUseAbility(AbilitiesIndex) const = 0;
    virtual bool isWorldBuilder() const = 0;
    virtual bool canUseCommandsWithoutCheatsEnabled() const = 0;
    virtual bool isSelectorExpansionAllowed() const = 0;
    virtual NetworkIdentifier getSourceId_net() const = 0;
    virtual char getSourceSubId() const = 0;
    virtual CommandOrigin* getOutputReceiver() const = 0;
    virtual OriginType getOriginType() const=0;
    virtual mce::UUID const& getUUID() const = 0;
    virtual void toCommandOriginData_stub() const = 0;
    virtual void handleCommandOutputCallback_stub(void*) = 0;
    virtual void _setUUID(mce::UUID const&) = 0;
};
class Actor;
class HashedString {
	uint64_t hash;
	std::string str;

public:
	std::string const& getString() const { return str; }

	__declspec(dllimport) HashedString(HashedString const& rhs);
	__declspec(dllimport) HashedString(HashedString&& rhs);
	__declspec(dllimport) HashedString(char const* rhs);
	__declspec(dllimport) HashedString(std::string const& rhs);
	__declspec(dllimport) bool operator==(HashedString const& rhs) const;
	__declspec(dllimport) bool operator!=(HashedString const& rhs) const;
};
struct ActorDefinitionIdentifier {
public:
		std::string ns;				// 0
		std::string identifier;		// 32
		std::string event;			// 64
		std::string fullname;		// 96
		HashedString canonicalHash; // 128

	
		inline HashedString const& getCanonicalHash() const { return canonicalHash; }
		inline std::string const& getCanonicalName() const { return canonicalHash.getString(); }
		inline std::string const& getFullName() const { return fullname; }
		inline std::string const& getIdentifier() const { return identifier; }
		inline std::string const& getInitEvent() const { return event; }
		inline std::string const& getNamespace() const { return ns; }
		inline bool isEmpty() const { return ns.empty() && identifier.empty(); }
		inline bool isVanilla() const { return ns == "minecraft"; }
		inline void setIdentifier(std::string const& id) { identifier = id; }
		inline void setInitEvent(std::string const& e) { event = e; }

		__declspec(dllimport) ActorDefinitionIdentifier(ActorDefinitionIdentifier const&);
		__declspec(dllimport) ActorDefinitionIdentifier(ActorDefinitionIdentifier&&);
		__declspec(dllimport) ActorDefinitionIdentifier(std::string, std::string, std::string);
		__declspec(dllimport) ActorDefinitionIdentifier(std::string const&);
		__declspec(dllimport) ActorDefinitionIdentifier(ActorType);
		__declspec(dllimport) ActorDefinitionIdentifier& operator=(ActorDefinitionIdentifier const&);
		__declspec(dllimport) bool operator==(ActorDefinitionIdentifier const&);
	};
	static_assert(offsetof(ActorDefinitionIdentifier, canonicalHash) == 128);



template <typename T> struct InvertableFilter {
  T value;
  bool inverted;
};
class CommandSelectorBase {
public:
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
static_assert(offsetof(CommandSelectorBase, explicitIdSelector) == 165);
template <typename T>
class CommandSelector : public CommandSelectorBase {
public:
	inline CommandSelector() : CommandSelectorBase(std::is_same_v<T, Player>) {}
	__declspec(dllimport) CommandSelectorResults<T> results(CommandOrigin const&) const;
};
template <typename T>
class CommandSelectorResults {
  std::shared_ptr<std::vector<T *>> data;

public:
  auto begin() { return data->begin(); }
  auto end() { return data->end(); }
  auto count() const { return data->size(); }
  auto empty() const { return data->empty(); }
};