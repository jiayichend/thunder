/*******************************************************************************
 * Project:  Net
 * @file     CmdBeat.cpp
 * @brief 
 * @author   cjy
 * @date:    2019年11月5日
 * @note
 * Modify history:
 ******************************************************************************/
#include "CmdBeat.hpp"

namespace net
{

CmdBeat::CmdBeat()
{
}

CmdBeat::~CmdBeat()
{
}

bool CmdBeat::AnyMessage(
                const tagMsgShell& stMsgShell,
                const MsgHead& oInMsgHead,
                const MsgBody& oInMsgBody)
{
    bool bResult = false;
    MsgHead oOutMsgHead = oInMsgHead;
    MsgBody oOutMsgBody = oInMsgBody;
    oOutMsgHead.set_cmd(oInMsgHead.cmd() + 1);
    GetLabor()->SendTo(stMsgShell, oOutMsgHead, oOutMsgBody);
    return(bResult);
}

} /* namespace net */
