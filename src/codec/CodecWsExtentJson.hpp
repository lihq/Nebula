/*******************************************************************************
 * Project:  Nebula
 * @file     CodecWsExtentJson.hpp
 * @brief    WebSocket编解码器
 * @author   Bwar
 * @date:    2016年9月3日
 * @note     WebSocket编解码器，payload部分数据带自定义扩展数据，Extension data
 * 为自定义二进制包头tagMsgHead，Application data为json体。
 * Modify history:
 ******************************************************************************/
#ifndef SRC_CODEC_CODECWSEXTENTJSON_HPP_
#define SRC_CODEC_CODECWSEXTENTJSON_HPP_

#include "Codec.hpp"

namespace neb
{

class CodecWsExtentJson: public Codec
{
public:
    CodecWsExtentJson(E_CODEC_TYPE eCodecType, const std::string& strKey = "That's a lizard.");
    virtual ~CodecWsExtentJson();

    virtual E_CODEC_STATUS Encode(const MsgHead& oMsgHead, const MsgBody& oMsgBody, loss::CBuffer* pBuff);
    virtual E_CODEC_STATUS Decode(loss::CBuffer* pBuff, MsgHead& oMsgHead, MsgBody& oMsgBody);

private:
    uint32 uiBeatCmd;
    uint32 uiBeatSeq;
};

} /* namespace neb */

#endif /* SRC_CODEC_CODECWSEXTENTJSON_HPP_ */
