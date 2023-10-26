#include "../location_access.hpp"
#include "../logic.hpp"
#include "../entrance.hpp"

using namespace Logic;
using namespace Settings;

void AreaTable_Init_GerudoValley() {
  areaTable[GERUDO_VALLEY] = Area("Gerudo Valley", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&BugRock, {[]{return BugRock || IsChild;}}),
                }, {
                  //Locations
                  LocationAccess(GV_GS_SMALL_BRIDGE, {[]{return IsChild && HookshotOrBoomerang && AtNight && CanGetNightTimeGS;}}),
                }, {
                  //Exits
                  Entrance(HYRULE_FIELD,      {[]{return true;}}),
                  Entrance(GV_UPPER_STREAM,   {[]{return true;}}),
                  Entrance(GV_CRATE_LEDGE,    {[]{return IsChild || CanUse(LONGSHOT);}}),
                  Entrance(GV_GROTTO_LEDGE,   {[]{return true;}}),
                  Entrance(GV_FORTRESS_SIDE,  {[]{return (IsAdult && (CanRideEpona || CanUse(LONGSHOT) || GerudoFortress.Is(GERUDOFORTRESS_OPEN) || CarpenterRescue)) || (IsChild && CanUse(HOOKSHOT));}}),
  });

  areaTable[GV_UPPER_STREAM] = Area("GV Upper Stream", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&GossipStoneFairy, {[]{return GossipStoneFairy || CanSummonGossipFairy;}}),
                  EventAccess(&BeanPlantFairy,   {[]{return BeanPlantFairy   || (CanPlantBean(GV_UPPER_STREAM) && CanPlay(SongOfStorms));}}),
                }, {
                  //Locations
                  LocationAccess(GV_WATERFALL_FREESTANDING_POH, {[]{return true;}}),
                  LocationAccess(GV_GS_BEAN_PATCH,              {[]{return CanPlantBugs && CanChildAttack;}}),
                  LocationAccess(GV_COW,                        {[]{return IsChild && CanPlay(EponasSong);}}),
                  LocationAccess(GV_GOSSIP_STONE,               {[]{return true;}}),
                }, {
                  //Exits
                  Entrance(GV_LOWER_STREAM, {[]{return true;}}),
  });

  areaTable[GV_LOWER_STREAM] = Area("GV Lower Stream", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(LAKE_HYLIA, {[]{return true;}}),
  });

  areaTable[GV_GROTTO_LEDGE] = Area("GV Grotto Ledge", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GV_LOWER_STREAM,   {[]{return true;}}),
                  Entrance(GV_OCTOROK_GROTTO, {[]{return CanUse(SILVER_GAUNTLETS);}}),
                  Entrance(GV_CRATE_LEDGE,    {[]{return CanUse(LONGSHOT);}}),
  });

  areaTable[GV_CRATE_LEDGE] = Area("GV Crate Ledge", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(GV_CRATE_FREESTANDING_POH, {[]{return true;}}),
                }, {
                  //Exits
                  Entrance(GV_LOWER_STREAM, {[]{return true;}}),
  });

  areaTable[GV_FORTRESS_SIDE] = Area("GV Fortress Side", "Gerudo Valley", GERUDO_VALLEY, DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&BrokenSwordAccess, {[]{return IsAdult && (PoachersSawAccess || PoachersSaw);}}),
                }, {
                  //Locations                                       
                  LocationAccess(GV_CHEST,          {[]{return IsAdult && CanUse(MEGATON_HAMMER);}}),
                  LocationAccess(GV_TRADE_SAW,      {[]{return IsAdult && PoachersSaw;}}),
                  LocationAccess(GV_GS_BEHIND_TENT, {[]{return IsAdult && HookshotOrBoomerang && AtNight && CanGetNightTimeGS;}}),
                  LocationAccess(GV_GS_PILLAR,      {[]{return IsAdult && HookshotOrBoomerang && AtNight && CanGetNightTimeGS;}}),
                }, {
                  //Exits
                  Entrance(GERUDO_FORTRESS,   {[]{return true;}}),
                  Entrance(GV_UPPER_STREAM,   {[]{return true;}}),
                  Entrance(GERUDO_VALLEY,     {[]{return IsChild || CanRideEpona || CanUse(LONGSHOT) || GerudoFortress.Is(GERUDOFORTRESS_OPEN) || CarpenterRescue;}}),
                  Entrance(GV_CARPENTER_TENT, {[]{return IsAdult;}}),
                  Entrance(GV_STORMS_GROTTO,  {[]{return IsAdult && CanOpenStormGrotto;}}),
                  Entrance(GV_CRATE_LEDGE, {[]{return false;}}),
  });

  areaTable[GV_CARPENTER_TENT] = Area("GV Carpenter Tent", "GV Carpenter Tent", NONE, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GV_FORTRESS_SIDE, {[]{return true;}}),
  });

  areaTable[GV_OCTOROK_GROTTO] = Area("GV Octorok Grotto", "GV Octorok Grotto", NONE, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GV_GROTTO_LEDGE, {[]{return true;}}),
  });

  areaTable[GV_STORMS_GROTTO] = Area("GV Storms Grotto", "GV Storms Grotto", NONE, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(GV_DEKU_SCRUB_GROTTO_REAR,  {[]{return CanStunDeku;}}),
                  LocationAccess(GV_DEKU_SCRUB_GROTTO_FRONT, {[]{return CanStunDeku;}}),
                }, {
                  //Exits
                  Entrance(GV_FORTRESS_SIDE, {[]{return true;}}),
  });

  areaTable[GERUDO_FORTRESS] = Area("Gerudo Fortress", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  //EventAccess(&CarpenterRescue, {[]{return CanFinishGerudoFortress;}}),
                  EventAccess(&GF_GateOpen,     {[]{return IsAdult && GerudoToken;}}),
                  EventAccess(&GtG_GateOpen,    {[]{return GtG_GateOpen || (IsAdult && GerudoToken);}}), 
                }, {
                  //Locations
                  //LocationAccess(GF_CHEST,              {[]{return CanUse(HOVER_BOOTS) || (IsAdult && CanUse(SCARECROW)) || CanUse(LONGSHOT);}}),
                  LocationAccess(GF_HBA_1000_POINTS,    {[]{return GerudoToken && CanRideEpona && Bow && AtDay;}}),
                  LocationAccess(GF_HBA_1500_POINTS,    {[]{return GerudoToken && CanRideEpona && Bow && AtDay;}}),
                  //LocationAccess(GF_NORTH_F1_CARPENTER, {[]{return  IsAdult || KokiriSword || CanUse(MASTER_SWORD) || CanUse(BIGGORON_SWORD);}}),
                  //LocationAccess(GF_NORTH_F2_CARPENTER, {[]{return (IsAdult || KokiriSword || CanUse(MASTER_SWORD) || CanUse(BIGGORON_SWORD)) && (GerudoToken || CanUse(BOW) || CanUse(HOOKSHOT) || CanUse(HOVER_BOOTS) || LogicGerudoKitchen);}}),
                  //LocationAccess(GF_SOUTH_F1_CARPENTER, {[]{return  IsAdult || KokiriSword || CanUse(MASTER_SWORD) || CanUse(BIGGORON_SWORD);}}),
                  //LocationAccess(GF_SOUTH_F2_CARPENTER, {[]{return  IsAdult || KokiriSword || CanUse(MASTER_SWORD) || CanUse(BIGGORON_SWORD);}}),
                  //LocationAccess(GF_GERUDO_MEMBERSHIP_CARD,       {[]{return CanFinishGerudoFortress;}}),
                  LocationAccess(GF_GS_ARCHERY_RANGE,   {[]{return IsAdult && HookshotOrBoomerang && GerudoToken && AtNight && CanGetNightTimeGS;}}),
                }, {
                  //Exits
                  Entrance(GV_FORTRESS_SIDE,                 {[]{return true;}}),
                  Entrance(TH_1_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_2_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_4_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_KITCHEN_HALLWAY,               {[]{return true;}}),
                  Entrance(GF_ENTRANCES_BEHIND_CRATES,       {[]{return true;}}),
                  Entrance(GF_ROOF_ENTRANCE_CLUSTER,         {[]{return LogicGFJump || CanUse(HOVER_BOOTS);}}),
                  Entrance(GF_KITCHEN_ROOF_ACCESS,           {[]{return GerudoToken && CanUse(LONGSHOT);}}),
                  //can ask the Gerudo on the path to HBA to throw you in jail
                  Entrance(GF_BREAK_ROOM_ENTRANCE,           {[]{return CanUse(HOOKSHOT);}}),
                  Entrance(GF_OUTSIDE_GATE,                  {[]{return GF_GateOpen;}}),
                  Entrance(GERUDO_TRAINING_GROUNDS_ENTRYWAY, {[]{return GtG_GateOpen && (IsAdult || ShuffleDungeonEntrances);}}), //Shouldn't this just be GtG_GateOpen?
  });

 // Needs to be a separate region to disambiguate the 1 torch jail and kitchen entrances
 areaTable[GF_ENTRANCES_BEHIND_CRATES] = Area("GF Entrances Behind Crates", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GERUDO_FORTRESS,                  {[]{return true;}}),
                  Entrance(TH_1_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_KITCHEN_HALLWAY,               {[]{return true;}}),
                  Entrance(GF_ROOF_ENTRANCE_CLUSTER,         {[]{return CanUse(LONGSHOT);}}),
                  Entrance(GF_STORMS_GROTTO,                 {[]{return IsAdult && CanOpenStormGrotto;}}), //Not there as child
  });
  
 areaTable[GF_ROOF_ENTRANCE_CLUSTER] = Area("GF Roof Entrance Cluster", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(TH_4_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_2_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(TH_KITCHEN_REAR,                  {[]{return true;}}),
                  Entrance(GF_ENTRANCES_BEHIND_CRATES,       {[]{return true;}}),
                  Entrance(GF_KITCHEN_ROOF_ACCESS,           {[]{return LogicGFJump && IsAdult;}}),
  });

 areaTable[GF_KITCHEN_ROOF_ACCESS] = Area("GF Kitchen Roof Access", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(GF_GS_TOP_FLOOR,            {[]{return (IsAdult && AtNight && CanGetNightTimeGS && (CanUseProjectile || CanJumpslash || CanUse(DINS_FIRE))) || 
                                                             Here(GF_3_TORCH_JAIL_EXTERIOR, []{return IsAdult && AtNight && CanGetNightTimeGS && CanUse(LONGSHOT);});}}),
        }, {
                  //Exits
                  Entrance(TH_KITCHEN_REAR,                  {[]{return true;}}),
                  Entrance(GF_3_TORCH_JAIL_EXTERIOR,         {[]{return true;}}),
                  Entrance(GF_CHEST_ROOF,                    {[]{return IsAdult && (CanUse(HOVER_BOOTS) || CanUse(SCARECROW) || CanUse(LONGSHOT));}}),
  });

 areaTable[GF_3_TORCH_JAIL_EXTERIOR] = Area("GF 3 Torch Jail Exterior", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(TH_3_TORCH_JAIL,                  {[]{return true;}}),
                  Entrance(GF_ROOF_ENTRANCE_CLUSTER,         {[]{return true;}}),
  });

 areaTable[GF_CHEST_ROOF] = Area("GF Chest Roof", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(GF_CHEST,                   {[]{return true;}}),
         }, {
                  //Exits
                  Entrance(GF_KITCHEN_ROOF_ACCESS,           {[]{return true;}}),
                  Entrance(GF_BREAK_ROOM_ENTRANCE,           {[]{return true;}}),
  });

 areaTable[GF_BREAK_ROOM_ENTRANCE] = Area("GF Break Room Entrance", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GERUDO_FORTRESS,           {[]{return true;}}),
                  Entrance(TH_BREAK_ROOM,             {[]{return true;}}),
  });

  areaTable[GF_BALCONY] = Area("GF Balcony", "Gerudo Fortress", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  //LocationAccess(GF_ABOVE_JAIL_CRATE, {[]{return IsAdult && CanBreakCrate;}}),
      }, {
                  //Exits
                  Entrance(TH_HALL_TO_BALCONY,        {[]{return true;}}),
                  Entrance(GERUDO_FORTRESS,           {[]{return true;}}),
                  Entrance(GF_CHEST_ROOF,             {[]{return CanUse(LONGSHOT);}}),
                  Entrance(GF_BREAK_ROOM_ENTRANCE,    {[]{return true;}}), //damage multiplier != 'ohko' or CanUse(NAYRUS_LOVE)
  });
 // THESE NEED DOING Å´Å´Å´Å´
 // https://github.com/fenhl/OoT-Randomizer/blob/321290e9feec5ffc2d7a0be51f64911305f0bd2a/data/World/Overworld.json#L753C12-L753C12
 // TH_1_TORCH_JAIL, TH_2_TORCH_JAIL, TH_3_TORCH_JAIL, TH_4_TORCH_JAIL, TH_KITCHEN_HALLWAY, TH_KITCHEN_FRONT, TH_KITCHEN_REAR, TH_BREAK_ROOM, TH_HALL_TO_BALCONY
 // with the logic/locations/exits from that page translated to this randomizer's format
 // exits first, do crates/pots/carpenters last
  areaTable[TH_1_TORCH_JAIL] = Area("TH 1 Torch Jail", "Thieves' Hideout", GERUDO_FORTRESS, NO_DAY_NIGHT_CYCLE, {}, {
      }, {
                  //Exits
                  Entrance(GERUDO_FORTRESS,                   {[]{return true;}}),
                  Entrance(TH_1_TORCH_JAIL,                   {[]{return true;}}),

  });
  
  areaTable[GF_OUTSIDE_GATE] = Area("GF Outside Gate", "Gerudo Fortress", NONE, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&GF_GateOpen, {[]{return IsAdult && GerudoToken && (ShuffleGerudoToken || ShuffleOverworldEntrances /*|| ShuffleSpecialIndoorEntrances*/);}}),
                }, {}, {
                  //Exits
                  Entrance(GERUDO_FORTRESS,         {[]{return (IsAdult && (Hookshot || !ShuffleOverworldEntrances)) || GF_GateOpen;}}),
                  Entrance(WASTELAND_NEAR_FORTRESS, {[]{return true;}}),
  });

  areaTable[GF_STORMS_GROTTO] = Area("GF Storms Grotto", "GF Storms Grotto", NONE, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&FreeFairies, {[]{return true;}}),
                }, {}, {
                  //Exits
                  Entrance(GERUDO_FORTRESS, {[]{return true;}}),
  });

  areaTable[WASTELAND_NEAR_FORTRESS] = Area("Wasteland Near Fortress", "Haunted Wasteland", HAUNTED_WASTELAND, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(GF_OUTSIDE_GATE,   {[]{return true;}}),
                  Entrance(HAUNTED_WASTELAND, {[]{return CanUse(HOVER_BOOTS) || CanUse(LONGSHOT) || LogicWastelandCrossing;}}),
  });

  areaTable[HAUNTED_WASTELAND] = Area("Haunted Wasteland", "Haunted Wasteland", HAUNTED_WASTELAND, NO_DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&FairyPot, {[]{return true;}}),
                  EventAccess(&NutPot,   {[]{return true;}}),
                }, {
                  //Locations
                  LocationAccess(WASTELAND_CHEST,            {[]{return HasFireSource;}}),
                  LocationAccess(WASTELAND_BOMBCHU_SALESMAN, {[]{return AdultsWallet && (IsAdult || Sticks || KokiriSword);}}),
                  LocationAccess(WASTELAND_GS,               {[]{return HookshotOrBoomerang;}}),
                }, {
                  //Exits
                  Entrance(WASTELAND_NEAR_COLOSSUS, {[]{return LogicLensWasteland || CanUse(LENS_OF_TRUTH);}}),
                  Entrance(WASTELAND_NEAR_FORTRESS, {[]{return CanUse(HOVER_BOOTS) || CanUse(LONGSHOT) || LogicWastelandCrossing;}}),
  });

  areaTable[WASTELAND_NEAR_COLOSSUS] = Area("Wasteland Near Colossus", "Haunted Wasteland", NONE, NO_DAY_NIGHT_CYCLE, {}, {}, {
                  //Exits
                  Entrance(DESERT_COLOSSUS,   {[]{return true;}}),
                  Entrance(HAUNTED_WASTELAND, {[]{return LogicReverseWasteland || false;}}),
  });

  areaTable[DESERT_COLOSSUS] = Area("Desert Colossus", "Desert Colossus", DESERT_COLOSSUS, DAY_NIGHT_CYCLE, {
                  //Events
                  EventAccess(&FairyPond, {[]{return FairyPond || CanPlay(SongOfStorms);}}),
                  EventAccess(&BugRock,   {[]{return true;}}),
                }, {
                  //Locations
                  LocationAccess(COLOSSUS_FREESTANDING_POH, {[]{return IsAdult && CanPlantBean(DESERT_COLOSSUS);}}),
                  LocationAccess(COLOSSUS_GS_BEAN_PATCH,    {[]{return CanPlantBugs && CanChildAttack;}}),
                  LocationAccess(COLOSSUS_GS_TREE,          {[]{return IsAdult && HookshotOrBoomerang && AtNight && CanGetNightTimeGS;}}),
                  LocationAccess(COLOSSUS_GS_HILL,          {[]{return IsAdult && AtNight && (CanPlantBean(DESERT_COLOSSUS) || CanUse(LONGSHOT) || (LogicColossusGS && CanUse(HOOKSHOT))) && CanGetNightTimeGS;}}),
                  LocationAccess(COLOSSUS_GOSSIP_STONE,     {[]{return true;}}),
                }, {
                  //Exits
                  Entrance(COLOSSUS_GREAT_FAIRY_FOUNTAIN, {[]{return HasExplosives;}}),
                  Entrance(SPIRIT_TEMPLE_ENTRYWAY,        {[]{return true;}}),
                  Entrance(WASTELAND_NEAR_COLOSSUS,       {[]{return true;}}),
                  Entrance(COLOSSUS_GROTTO,               {[]{return CanUse(SILVER_GAUNTLETS);}}),
  });

  areaTable[DESERT_COLOSSUS_FROM_SPIRIT_ENTRYWAY] = Area("Desert Colossus From Spirit Entryway", "Desert Colossus", DESERT_COLOSSUS, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(SHEIK_AT_COLOSSUS, {[]{return true;}}),
                }, {
                  //Exist
                  Entrance(DESERT_COLOSSUS, {[]{return true;}}),
  });

  areaTable[COLOSSUS_GREAT_FAIRY_FOUNTAIN] = Area("Colossus Great Fairy Fountain", "Colossus Great Fairy Fountain", NONE, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(COLOSSUS_GREAT_FAIRY_REWARD, {[]{return CanPlay(ZeldasLullaby);}}),
                }, {
                  //Exits
                  Entrance(DESERT_COLOSSUS, {[]{return true;}}),
  });

  areaTable[COLOSSUS_GROTTO] = Area("Colossus Grotto", "Colossus Grotto", NONE, NO_DAY_NIGHT_CYCLE, {}, {
                  //Locations
                  LocationAccess(COLOSSUS_DEKU_SCRUB_GROTTO_REAR,  {[]{return CanStunDeku;}}),
                  LocationAccess(COLOSSUS_DEKU_SCRUB_GROTTO_FRONT, {[]{return CanStunDeku;}}),
                }, {
                  //Exits
                  Entrance(DESERT_COLOSSUS, {[]{return true;}}),
  });
}
