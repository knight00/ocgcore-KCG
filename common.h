/*
 * Copyright (c) 2009-2015, Argon Sun (Fluorohydride)
 * Copyright (c) 2017-2025, Edoardo Lolletti (edo9300) <edoardo762@gmail.com>
 *
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */
#ifndef COMMON_H_
#define COMMON_H_

#if defined( _MSC_VER) && !defined(__clang_analyzer__)
#pragma warning(disable: 4244)
#define unreachable() __assume(0)
#define NoInline __declspec(noinline)
#define ForceInline __forceinline
#define Assume(cond) __assume(cond)
#else
#if !defined(__forceinline)
#define ForceInline __attribute__((always_inline)) inline
#else
#define ForceInline __forceinline
#endif
#define unreachable() __builtin_unreachable()
#define NoInline __attribute__ ((noinline))
#define Assume(cond) do { if(!(cond)){ unreachable(); } } while(0)
#endif

#if defined(__clang_analyzer__)
#undef NDEBUG
#endif

#include <cassert>
#include <cstdint>
#include "ocgapi_constants.h"

#define TRUE 1
#define FALSE 0

//Locations
//////kdiy//////
#define CARDDATA_PICCODE		1
#define CARDDATA_ALIAS			2
#define CARDDATA_SETCODE		3
#define CARDDATA_TYPE			4
#define CARDDATA_LEVEL			5
#define CARDDATA_ATTRIBUTE		6
#define CARDDATA_RACE			7
#define CARDDATA_ATTACK			8
#define CARDDATA_DEFENSE		9
#define CARDDATA_LSCALE			10
#define CARDDATA_RSCALE			11
#define CARDDATA_LINK_MARKER	12

#define LOCATION_RMZONE   0x2000
#define LOCATION_RSZONE   0x4000
#define LOCATION_FZONE   0x100
#define LOCATION_PZONE   0x200
#define LOCATION_STZONE  0x400
#define LOCATION_MMZONE  0x800
#define LOCATION_EMZONE  0x1000
//Locations redirect
#define LOCATION_DECKBOT	0x10001		//Return to deck bottom
#define LOCATION_DECKSHF	0x20001		//Return to deck and shuffle

//
#define COIN_HEADS  1
#define COIN_TAILS  0

//Flip effect flags
#define NO_FLIP_EFFECT     0x10000

/////kdiy/////////////
#define SCOPE_OCG        0x1
#define SCOPE_TCG        0x2
#define SCOPE_ANIME      0x4
#define SCOPE_ILLEGAL    0x8
#define SCOPE_VIDEO_GAME 0x10
#define SCOPE_CUSTOM     0x20
#define SCOPE_SPEED      0x40
#define SCOPE_PRERELEASE 0x100
#define SCOPE_RUSH       0x200
#define SCOPE_LEGEND     0x400
#define SCOPE_HIDDEN     0x1000
/////zdiy/////
#define SCOPE_ZCG     0x2000
/////zdiy/////
#define SCOPE_OCG_TCG    (SCOPE_OCG | SCOPE_TCG)
#define SCOPE_OFFICIAL   (SCOPE_OCG | SCOPE_TCG | SCOPE_PRERELEASE)
/////kdiy/////////////

//Players
#define PLAYER_SELFDES  5

enum ActivityType : uint8_t {
	ACTIVITY_SUMMON = 1,
	ACTIVITY_NORMALSUMMON = 2,
	ACTIVITY_SPSUMMON = 3,
	ACTIVITY_FLIPSUMMON = 4,
	ACTIVITY_ATTACK = 5,
	ACTIVITY_BATTLE_PHASE = 6,
	ACTIVITY_CHAIN = 7,
};


#endif /* COMMON_H_ */
