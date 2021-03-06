/*
 * Copyright 2014 Canonical Ltd.
 * Authors:
 *      Roberto Mier
 *      Tiago Herrmann
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

// macro to assert conditions as in debug as in release mode
#define ASSERT(cond) ((!(cond)) ? qt_assert(#cond,__FILE__,__LINE__) : qt_noop())

#define PACKET_BUFFER_SIZE (16384 * 100 + 16)
#define ENCRYPT_BUFFER_INTS 16384
#define DECRYPT_BUFFER_INTS 16384

// These are the the original
#define LIBQTELEGRAM_APP_HASH "de37bcf00f4688de900510f4f87384bb"
#define LIBQTELEGRAM_APP_ID 13682
// These are the telegram-cli credentials
//#define LIBQTELEGRAM_APP_HASH "36722c72256a24c1225de00eb6a1ca74"
//#define LIBQTELEGRAM_APP_ID 2899
// These are my second phone ones
//#define LIBQTELEGRAM_APP_HASH "4b7f87d44de5e0a22248597939c848ae"
//#define LIBQTELEGRAM_APP_ID 11986

#define PRODUCTION_DEFAULT_DC_ID 4
#define PRODUCTION_DEFAULT_DC_HOST "149.154.167.91"
#define PRODUCTION_DEFAULT_DC_PORT 443
#define TEST_DEFAULT_DC_ID 1
#define TEST_DEFAULT_DC_HOST "173.240.5.253"
#define TEST_DEFAULT_DC_PORT 80

#define LIBQTELEGRAM_BUILD "001"
#define LIBQTELEGRAM_VERSION "1.0.0-SNAPSHOT"

#define MAX_RESPONSE_SIZE (1L << 24)

#define MAX_MESSAGE_INTS 1048576

#define MAX_PENDING_ACKS 16

#define MAX_PACKED_SIZE (1 << 24)

#define ACK_TIMEOUT 120000 //120 secs
#define QUERY_TIMEOUT 60000 // 60 secs

#define MAX_QUERY_RESENDS 10

#define LANG_CODE "en"

// divide file bytes into parts >= 128 kbytes. This is the minimum block size to ensurance receiving complete the users
// profile and chat "photoBig" files.
#define BLOCK (16 * 1024)

#define RECONNECT_TIMEOUT 5000 // in case session hasn't connection, try to reconnect every 5 seconds

#define UBUNTU_PHONE_TOKEN_TYPE 5 // used as token type when register and unregister device in telegram servers for push notifications

#define DH_CONFIG_SERVER_RANDOM_LENGTH 256 // length we want to be a server generated random number
#define SHARED_KEY_LENGTH 256 // length for the secret chat generated shared keys

#define LAYER 17 // this value must be consistent with the TL_InvokeWithLayerX header in OutboundPkt.initConnection().

#endif // CONSTANTS_H
