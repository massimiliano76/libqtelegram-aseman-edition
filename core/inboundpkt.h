/*
 * Copyright 2013 Vitaly Valtman
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

#ifndef INBOUNDPKT_H
#define INBOUNDPKT_H

#include <QObject>
#include <QLoggingCategory>

#include <openssl/bn.h>
#include "types/dcoption.h"
#include "types/user.h"
#include "types/userprofilephoto.h"
#include "types/filelocation.h"
#include "types/chat.h"
#include "types/dialog.h"
#include "types/peer.h"
#include "types/peernotifysettings.h"
#include "types/audio.h"
#include "types/document.h"
#include "types/message.h"
#include "types/messageaction.h"
#include "types/messagemedia.h"
#include "types/photo.h"
#include "types/photosize.h"
#include "types/video.h"
#include "types/chatparticipant.h"
#include "types/chatparticipants.h"
#include "types/contactsforeignlink.h"
#include "types/contactsmylink.h"
#include "types/geochatmessage.h"
#include "types/contact.h"
#include "types/update.h"
#include "types/contactslink.h"
#include "types/contactstatus.h"
#include "types/importedcontact.h"
#include "types/contactblocked.h"
#include "types/storagefiletype.h"
#include "types/chatfull.h"
#include "types/encryptedmessage.h"
#include "types/updatesstate.h"
#include "types/wallpaper.h"
#include "types/encryptedchat.h"

#include "secret/secretchat.h"

Q_DECLARE_LOGGING_CATEGORY(TG_CORE_INBOUNDPKT)

class InboundPkt
{
public:
    explicit InboundPkt(char* buffer, qint32 len);

    virtual const char *buffer() const;
    virtual qint32 length() const;
    virtual void setInPtr(qint32 *inPtr);
    virtual void setInEnd(qint32 *inEnd);
    virtual qint32 *inPtr();
    virtual qint32 *inEnd();
    virtual void forwardInPtr(qint32 positions);

    virtual qint32 prefetchInt();
    virtual qint32 fetchInt();
    virtual bool fetchBool();
    virtual qint32 *fetchInts(qint32 length);
    virtual double fetchDouble();
    virtual qint64 fetchLong();
    virtual qint32 prefetchStrlen();
    virtual char *fetchStr(qint32 length);
    virtual QByteArray fetchBytes();
    virtual QString fetchQString();
    virtual qint32 fetchBignum (BIGNUM *x);
    virtual qint32 fetchDate();

    virtual DcOption fetchDcOption();
    virtual User fetchUser();
    virtual Chat fetchChat();
    virtual Dialog fetchDialog();
    virtual Peer fetchPeer();
    virtual Message fetchMessage();
    virtual Contact fetchContact();
    virtual Update fetchUpdate();
    virtual ContactsLink fetchContactsLink();
    virtual Photo fetchPhoto();
    virtual PeerNotifySettings fetchPeerNotifySetting();
    virtual ContactStatus fetchContactStatus();
    virtual ImportedContact fetchImportedContact();
    virtual ContactsMyLink fetchContactsMyLink();
    virtual ContactsForeignLink fetchContactsForeignLink();
    virtual ContactBlocked fetchContactBlocked();
    virtual StorageFileType fetchStorageFileType();
    virtual ChatFull fetchChatFull();
    virtual EncryptedMessage fetchEncryptedMessage();
    virtual UpdatesState fetchUpdatesState();
    virtual WallPaper fetchWallPaper();
    virtual UserProfilePhoto fetchUserProfilePhoto();
    virtual EncryptedChat fetchEncryptedChat();
    virtual EncryptedFile fetchEncryptedFile();

protected:
    char *m_buffer;
    qint32 m_length;

    qint32 *m_inPtr;
    qint32 *m_inEnd;

    FileLocation fetchFileLocation();
    UserStatus fetchUserStatus();
    GeoPoint fetchGeoPoint();
    ChatPhoto fetchChatPhoto();
    MessageAction fetchMessageAction();
    PhotoSize fetchPhotoSize();
    MessageMedia fetchMessageMedia();
    Video fetchVideo();
    Document fetchDocument();
    Audio fetchAudio();
    ChatParticipant fetchChatParticipant();
    ChatParticipants fetchChatParticipants();
    GeoChatMessage fetchGeoChatMessage();
    NotifyPeer fetchNotifyPeer();
    SendMessageAction fetchSendMessageAction();
};

#endif // INBOUNDPKT_H
