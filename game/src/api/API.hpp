#include <memory>
#include <vector>

#pragma once

#include <optional>

#include "AchievementProgressType.hpp"
#include "UserIdType.hpp"
#include "UserId.hpp"
#include "AchievementProgress.hpp"
#include "AchievementUnlockType.hpp"
#include "AchievementUnlock.hpp"
#include "ReportStats.hpp"
#include "AchievementData.hpp"
#include "Achievement.hpp"
#include "Color.hpp"
#include "DiceType.hpp"
#include "Dice.hpp"
#include "UserStats.hpp"
#include "UserData.hpp"
#include "DieRoll.hpp"
#include "GameErrorType.hpp"
#include "GameError.hpp"
#include "RedirectType.hpp"
#include "Redirect.hpp"
#include "RefetchPlayerType.hpp"
#include "RefetchPlayer.hpp"
#include "Room.hpp"
#include "RoomList.hpp"
#include "Player.hpp"
#include "IGameState.hpp"
#include "ServerPlayer.hpp"
#include "GameStateType.hpp"
#include "GameState.hpp"
#include "WelcomeMsgType.hpp"
#include "WelcomeMsg.hpp"
#include "RestartMsgType.hpp"
#include "RestartMsg.hpp"
#include "SpectatorsMsgType.hpp"
#include "SpectatorsMsg.hpp"
#include "WinMsgType.hpp"
#include "WinMsg.hpp"
#include "RollMsgType.hpp"
#include "RollMsg.hpp"
#include "RollAgainMsgType.hpp"
#include "RollAgainMsg.hpp"
#include "JoinMsgType.hpp"
#include "JoinMsg.hpp"
#include "DisconnectMsgType.hpp"
#include "DisconnectMsg.hpp"
#include "ReconnectMsgType.hpp"
#include "ReconnectMsg.hpp"
#include "KickMsgType.hpp"
#include "KickMsg.hpp"
#include "ChatMsgType.hpp"
#include "ChatMsg.hpp"
#include "UpdateTurnMsgType.hpp"
#include "UpdateTurnMsg.hpp"
#include "UpdateNameMsgType.hpp"
#include "UpdateNameMsg.hpp"
#include "UpdateMsgType.hpp"
#include "UpdateMsg.hpp"
namespace API {
    using Integer = double;
}
