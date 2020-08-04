/*
#############################################################################################
# Killing Floor 2 (1.8787) SDK
# Generated with TheFeckless UE3 SDK Generator v1.4_Beta-Rev.51
#
=========================================================================================
# # File: IpDrv_functions.h #
=========================================================================================
# # Credits: uNrEaL, Tamimego, SystemFiles, R00T88, _silencer, the1domo, K@N@VEL
# Thanks: HOOAH07, lowHertz
# Forums: www.uc-forum.com, www.gamedeception.net
#############################################################################################
*/

#ifdef _MSC_VER
#pragma pack(push, 0x4)
#endif

/*
#
=========================================================================================
# # Functions #
=========================================================================================
#
*/

// Function IpDrv.InternetLink.ResolveFailed
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AInternetLink::eventResolveFailed() {
    static UFunction* pFnResolveFailed = NULL;

    if (!pFnResolveFailed)
        pFnResolveFailed = (UFunction*)UObject::GObjObjects()->Data[37948];

    AInternetLink_eventResolveFailed_Parms ResolveFailed_Parms;

    this->ProcessEvent(pFnResolveFailed, &ResolveFailed_Parms, NULL);
};

// Function IpDrv.InternetLink.Resolved
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void AInternetLink::eventResolved() {
    static UFunction* pFnResolved = NULL;

    if (!pFnResolved)
        pFnResolved = (UFunction*)UObject::GObjObjects()->Data[37946];

    AInternetLink_eventResolved_Parms Resolved_Parms;

    this->ProcessEvent(pFnResolved, &Resolved_Parms, NULL);
};

// Function IpDrv.InternetLink.GetLocalIP
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::GetLocalIP() {
    static UFunction* pFnGetLocalIP = NULL;

    if (!pFnGetLocalIP)
        pFnGetLocalIP = (UFunction*)UObject::GObjObjects()->Data[37944];

    AInternetLink_execGetLocalIP_Parms GetLocalIP_Parms;

    pFnGetLocalIP->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetLocalIP, &GetLocalIP_Parms, NULL);

    pFnGetLocalIP->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.StringToIpAddr
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::StringToIpAddr() {
    static UFunction* pFnStringToIpAddr = NULL;

    if (!pFnStringToIpAddr)
        pFnStringToIpAddr = (UFunction*)UObject::GObjObjects()->Data[37940];

    AInternetLink_execStringToIpAddr_Parms StringToIpAddr_Parms;

    pFnStringToIpAddr->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnStringToIpAddr, &StringToIpAddr_Parms, NULL);

    pFnStringToIpAddr->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.IpAddrToString
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::IpAddrToString() {
    static UFunction* pFnIpAddrToString = NULL;

    if (!pFnIpAddrToString)
        pFnIpAddrToString = (UFunction*)UObject::GObjObjects()->Data[37937];

    AInternetLink_execIpAddrToString_Parms IpAddrToString_Parms;

    pFnIpAddrToString->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIpAddrToString, &IpAddrToString_Parms, NULL);

    pFnIpAddrToString->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.GetLastError
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::GetLastError() {
    static UFunction* pFnGetLastError = NULL;

    if (!pFnGetLastError)
        pFnGetLastError = (UFunction*)UObject::GObjObjects()->Data[37935];

    AInternetLink_execGetLastError_Parms GetLastError_Parms;

    pFnGetLastError->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetLastError, &GetLastError_Parms, NULL);

    pFnGetLastError->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.Resolve
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::Resolve() {
    static UFunction* pFnResolve = NULL;

    if (!pFnResolve)
        pFnResolve = (UFunction*)UObject::GObjObjects()->Data[37933];

    AInternetLink_execResolve_Parms Resolve_Parms;

    pFnResolve->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnResolve, &Resolve_Parms, NULL);

    pFnResolve->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.ParseURL
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::ParseURL() {
    static UFunction* pFnParseURL = NULL;

    if (!pFnParseURL)
        pFnParseURL = (UFunction*)UObject::GObjObjects()->Data[37926];

    AInternetLink_execParseURL_Parms ParseURL_Parms;

    pFnParseURL->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnParseURL, &ParseURL_Parms, NULL);

    pFnParseURL->FunctionFlags |= 0x400;
};

// Function IpDrv.InternetLink.IsDataPending
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void AInternetLink::IsDataPending() {
    static UFunction* pFnIsDataPending = NULL;

    if (!pFnIsDataPending)
        pFnIsDataPending = (UFunction*)UObject::GObjObjects()->Data[37924];

    AInternetLink_execIsDataPending_Parms IsDataPending_Parms;

    pFnIsDataPending->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIsDataPending, &IsDataPending_Parms, NULL);

    pFnIsDataPending->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.ReceivedBinary
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventReceivedBinary() {
    static UFunction* pFnReceivedBinary = NULL;

    if (!pFnReceivedBinary)
        pFnReceivedBinary = (UFunction*)UObject::GObjObjects()->Data[41535];

    ATcpLink_eventReceivedBinary_Parms ReceivedBinary_Parms;

    this->ProcessEvent(pFnReceivedBinary, &ReceivedBinary_Parms, NULL);
};

// Function IpDrv.TcpLink.ReceivedLine
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventReceivedLine() {
    static UFunction* pFnReceivedLine = NULL;

    if (!pFnReceivedLine)
        pFnReceivedLine = (UFunction*)UObject::GObjObjects()->Data[41533];

    ATcpLink_eventReceivedLine_Parms ReceivedLine_Parms;

    this->ProcessEvent(pFnReceivedLine, &ReceivedLine_Parms, NULL);
};

// Function IpDrv.TcpLink.ReceivedText
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventReceivedText() {
    static UFunction* pFnReceivedText = NULL;

    if (!pFnReceivedText)
        pFnReceivedText = (UFunction*)UObject::GObjObjects()->Data[41531];

    ATcpLink_eventReceivedText_Parms ReceivedText_Parms;

    this->ProcessEvent(pFnReceivedText, &ReceivedText_Parms, NULL);
};

// Function IpDrv.TcpLink.Closed
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventClosed() {
    static UFunction* pFnClosed = NULL;

    if (!pFnClosed) pFnClosed = (UFunction*)UObject::GObjObjects()->Data[41530];

    ATcpLink_eventClosed_Parms Closed_Parms;

    this->ProcessEvent(pFnClosed, &Closed_Parms, NULL);
};

// Function IpDrv.TcpLink.Opened
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventOpened() {
    static UFunction* pFnOpened = NULL;

    if (!pFnOpened) pFnOpened = (UFunction*)UObject::GObjObjects()->Data[41529];

    ATcpLink_eventOpened_Parms Opened_Parms;

    this->ProcessEvent(pFnOpened, &Opened_Parms, NULL);
};

// Function IpDrv.TcpLink.Accepted
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void ATcpLink::eventAccepted() {
    static UFunction* pFnAccepted = NULL;

    if (!pFnAccepted)
        pFnAccepted = (UFunction*)UObject::GObjObjects()->Data[41528];

    ATcpLink_eventAccepted_Parms Accepted_Parms;

    this->ProcessEvent(pFnAccepted, &Accepted_Parms, NULL);
};

// Function IpDrv.TcpLink.ReadBinary
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::ReadBinary() {
    static UFunction* pFnReadBinary = NULL;

    if (!pFnReadBinary)
        pFnReadBinary = (UFunction*)UObject::GObjObjects()->Data[41524];

    ATcpLink_execReadBinary_Parms ReadBinary_Parms;

    pFnReadBinary->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadBinary, &ReadBinary_Parms, NULL);

    pFnReadBinary->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.ReadText
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::ReadText() {
    static UFunction* pFnReadText = NULL;

    if (!pFnReadText)
        pFnReadText = (UFunction*)UObject::GObjObjects()->Data[41521];

    ATcpLink_execReadText_Parms ReadText_Parms;

    pFnReadText->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadText, &ReadText_Parms, NULL);

    pFnReadText->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.SendBinary
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::SendBinary() {
    static UFunction* pFnSendBinary = NULL;

    if (!pFnSendBinary)
        pFnSendBinary = (UFunction*)UObject::GObjObjects()->Data[41517];

    ATcpLink_execSendBinary_Parms SendBinary_Parms;

    pFnSendBinary->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendBinary, &SendBinary_Parms, NULL);

    pFnSendBinary->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.SendText
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::SendText() {
    static UFunction* pFnSendText = NULL;

    if (!pFnSendText)
        pFnSendText = (UFunction*)UObject::GObjObjects()->Data[41514];

    ATcpLink_execSendText_Parms SendText_Parms;

    pFnSendText->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendText, &SendText_Parms, NULL);

    pFnSendText->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.IsConnected
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::IsConnected() {
    static UFunction* pFnIsConnected = NULL;

    if (!pFnIsConnected)
        pFnIsConnected = (UFunction*)UObject::GObjObjects()->Data[41512];

    ATcpLink_execIsConnected_Parms IsConnected_Parms;

    pFnIsConnected->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIsConnected, &IsConnected_Parms, NULL);

    pFnIsConnected->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.Close
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::Close() {
    static UFunction* pFnClose = NULL;

    if (!pFnClose) pFnClose = (UFunction*)UObject::GObjObjects()->Data[41510];

    ATcpLink_execClose_Parms Close_Parms;

    pFnClose->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClose, &Close_Parms, NULL);

    pFnClose->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.Open
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::Open() {
    static UFunction* pFnOpen = NULL;

    if (!pFnOpen) pFnOpen = (UFunction*)UObject::GObjObjects()->Data[41507];

    ATcpLink_execOpen_Parms Open_Parms;

    pFnOpen->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnOpen, &Open_Parms, NULL);

    pFnOpen->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.Listen
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::Listen() {
    static UFunction* pFnListen = NULL;

    if (!pFnListen) pFnListen = (UFunction*)UObject::GObjObjects()->Data[41505];

    ATcpLink_execListen_Parms Listen_Parms;

    pFnListen->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnListen, &Listen_Parms, NULL);

    pFnListen->FunctionFlags |= 0x400;
};

// Function IpDrv.TcpLink.BindPort
// [0x00024400] ( FUNC_Native )
// Parameters infos:

void ATcpLink::BindPort() {
    static UFunction* pFnBindPort = NULL;

    if (!pFnBindPort)
        pFnBindPort = (UFunction*)UObject::GObjObjects()->Data[41501];

    ATcpLink_execBindPort_Parms BindPort_Parms;

    pFnBindPort->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnBindPort, &BindPort_Parms, NULL);

    pFnBindPort->FunctionFlags |= 0x400;
};

// Function IpDrv.McpServiceBase.GetUserAuthURL
// [0x00020002]
// Parameters infos:

void UMcpServiceBase::GetUserAuthURL() {
    static UFunction* pFnGetUserAuthURL = NULL;

    if (!pFnGetUserAuthURL)
        pFnGetUserAuthURL = (UFunction*)UObject::GObjObjects()->Data[37957];

    UMcpServiceBase_execGetUserAuthURL_Parms GetUserAuthURL_Parms;

    this->ProcessEvent(pFnGetUserAuthURL, &GetUserAuthURL_Parms, NULL);
};

// Function IpDrv.McpServiceBase.GetAppAccessURL
// [0x00020002]
// Parameters infos:

void UMcpServiceBase::GetAppAccessURL() {
    static UFunction* pFnGetAppAccessURL = NULL;

    if (!pFnGetAppAccessURL)
        pFnGetAppAccessURL = (UFunction*)UObject::GObjObjects()->Data[37955];

    UMcpServiceBase_execGetAppAccessURL_Parms GetAppAccessURL_Parms;

    this->ProcessEvent(pFnGetAppAccessURL, &GetAppAccessURL_Parms, NULL);
};

// Function IpDrv.McpServiceBase.GetBaseURL
// [0x00020002]
// Parameters infos:

void UMcpServiceBase::GetBaseURL() {
    static UFunction* pFnGetBaseURL = NULL;

    if (!pFnGetBaseURL)
        pFnGetBaseURL = (UFunction*)UObject::GObjObjects()->Data[37953];

    UMcpServiceBase_execGetBaseURL_Parms GetBaseURL_Parms;

    this->ProcessEvent(pFnGetBaseURL, &GetBaseURL_Parms, NULL);
};

// Function IpDrv.McpServiceBase.Init
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UMcpServiceBase::eventInit() {
    static UFunction* pFnInit = NULL;

    if (!pFnInit) pFnInit = (UFunction*)UObject::GObjObjects()->Data[37951];

    UMcpServiceBase_eventInit_Parms Init_Parms;

    this->ProcessEvent(pFnInit, &Init_Parms, NULL);
};

// Function IpDrv.OnlineEventsInterfaceMcp.UploadMatchmakingStats
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineEventsInterfaceMcp::UploadMatchmakingStats() {
    static UFunction* pFnUploadMatchmakingStats = NULL;

    if (!pFnUploadMatchmakingStats)
        pFnUploadMatchmakingStats =
            (UFunction*)UObject::GObjObjects()->Data[40533];

    UOnlineEventsInterfaceMcp_execUploadMatchmakingStats_Parms
        UploadMatchmakingStats_Parms;

    pFnUploadMatchmakingStats->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUploadMatchmakingStats, &UploadMatchmakingStats_Parms,
                       NULL);

    pFnUploadMatchmakingStats->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineEventsInterfaceMcp.UpdatePlaylistPopulation
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineEventsInterfaceMcp::UpdatePlaylistPopulation() {
    static UFunction* pFnUpdatePlaylistPopulation = NULL;

    if (!pFnUpdatePlaylistPopulation)
        pFnUpdatePlaylistPopulation =
            (UFunction*)UObject::GObjObjects()->Data[40529];

    UOnlineEventsInterfaceMcp_execUpdatePlaylistPopulation_Parms
        UpdatePlaylistPopulation_Parms;

    pFnUpdatePlaylistPopulation->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUpdatePlaylistPopulation,
                       &UpdatePlaylistPopulation_Parms, NULL);

    pFnUpdatePlaylistPopulation->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineEventsInterfaceMcp.UploadGameplayEventsData
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineEventsInterfaceMcp::UploadGameplayEventsData() {
    static UFunction* pFnUploadGameplayEventsData = NULL;

    if (!pFnUploadGameplayEventsData)
        pFnUploadGameplayEventsData =
            (UFunction*)UObject::GObjObjects()->Data[40524];

    UOnlineEventsInterfaceMcp_execUploadGameplayEventsData_Parms
        UploadGameplayEventsData_Parms;

    pFnUploadGameplayEventsData->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUploadGameplayEventsData,
                       &UploadGameplayEventsData_Parms, NULL);

    pFnUploadGameplayEventsData->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineEventsInterfaceMcp.UploadPlayerData
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineEventsInterfaceMcp::UploadPlayerData() {
    static UFunction* pFnUploadPlayerData = NULL;

    if (!pFnUploadPlayerData)
        pFnUploadPlayerData = (UFunction*)UObject::GObjObjects()->Data[40518];

    UOnlineEventsInterfaceMcp_execUploadPlayerData_Parms UploadPlayerData_Parms;

    pFnUploadPlayerData->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUploadPlayerData, &UploadPlayerData_Parms, NULL);

    pFnUploadPlayerData->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineNewsInterfaceMcp.GetNews
// [0x00020002]
// Parameters infos:

void UOnlineNewsInterfaceMcp::GetNews() {
    static UFunction* pFnGetNews = NULL;

    if (!pFnGetNews)
        pFnGetNews = (UFunction*)UObject::GObjObjects()->Data[41113];

    UOnlineNewsInterfaceMcp_execGetNews_Parms GetNews_Parms;

    this->ProcessEvent(pFnGetNews, &GetNews_Parms, NULL);
};

// Function IpDrv.OnlineNewsInterfaceMcp.ClearReadNewsCompletedDelegate
// [0x00020002]
// Parameters infos:

void UOnlineNewsInterfaceMcp::ClearReadNewsCompletedDelegate() {
    static UFunction* pFnClearReadNewsCompletedDelegate = NULL;

    if (!pFnClearReadNewsCompletedDelegate)
        pFnClearReadNewsCompletedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41110];

    UOnlineNewsInterfaceMcp_execClearReadNewsCompletedDelegate_Parms
        ClearReadNewsCompletedDelegate_Parms;

    this->ProcessEvent(pFnClearReadNewsCompletedDelegate,
                       &ClearReadNewsCompletedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineNewsInterfaceMcp.AddReadNewsCompletedDelegate
// [0x00020002]
// Parameters infos:

void UOnlineNewsInterfaceMcp::AddReadNewsCompletedDelegate() {
    static UFunction* pFnAddReadNewsCompletedDelegate = NULL;

    if (!pFnAddReadNewsCompletedDelegate)
        pFnAddReadNewsCompletedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41108];

    UOnlineNewsInterfaceMcp_execAddReadNewsCompletedDelegate_Parms
        AddReadNewsCompletedDelegate_Parms;

    this->ProcessEvent(pFnAddReadNewsCompletedDelegate,
                       &AddReadNewsCompletedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineNewsInterfaceMcp.OnReadNewsCompleted
// [0x00120000]
// Parameters infos:

void UOnlineNewsInterfaceMcp::OnReadNewsCompleted() {
    static UFunction* pFnOnReadNewsCompleted = NULL;

    if (!pFnOnReadNewsCompleted)
        pFnOnReadNewsCompleted =
            (UFunction*)UObject::GObjObjects()->Data[41105];

    UOnlineNewsInterfaceMcp_execOnReadNewsCompleted_Parms
        OnReadNewsCompleted_Parms;

    this->ProcessEvent(pFnOnReadNewsCompleted, &OnReadNewsCompleted_Parms,
                       NULL);
};

// Function IpDrv.OnlineNewsInterfaceMcp.ReadNews
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineNewsInterfaceMcp::ReadNews() {
    static UFunction* pFnReadNews = NULL;

    if (!pFnReadNews)
        pFnReadNews = (UFunction*)UObject::GObjObjects()->Data[41101];

    UOnlineNewsInterfaceMcp_execReadNews_Parms ReadNews_Parms;

    pFnReadNews->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadNews, &ReadNews_Parms, NULL);

    pFnReadNews->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadBase.GetUrlForFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadBase::GetUrlForFile() {
    static UFunction* pFnGetUrlForFile = NULL;

    if (!pFnGetUrlForFile)
        pFnGetUrlForFile = (UFunction*)UObject::GObjObjects()->Data[38179];

    UOnlineTitleFileDownloadBase_execGetUrlForFile_Parms GetUrlForFile_Parms;

    pFnGetUrlForFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetUrlForFile, &GetUrlForFile_Parms, NULL);

    pFnGetUrlForFile->FunctionFlags |= 0x400;
};

// Function
// IpDrv.OnlineTitleFileDownloadBase.ClearRequestTitleFileListCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadBase::ClearRequestTitleFileListCompleteDelegate() {
    static UFunction* pFnClearRequestTitleFileListCompleteDelegate = NULL;

    if (!pFnClearRequestTitleFileListCompleteDelegate)
        pFnClearRequestTitleFileListCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[38176];

    UOnlineTitleFileDownloadBase_execClearRequestTitleFileListCompleteDelegate_Parms
        ClearRequestTitleFileListCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearRequestTitleFileListCompleteDelegate,
                       &ClearRequestTitleFileListCompleteDelegate_Parms, NULL);
};

// Function
// IpDrv.OnlineTitleFileDownloadBase.AddRequestTitleFileListCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadBase::AddRequestTitleFileListCompleteDelegate() {
    static UFunction* pFnAddRequestTitleFileListCompleteDelegate = NULL;

    if (!pFnAddRequestTitleFileListCompleteDelegate)
        pFnAddRequestTitleFileListCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[38174];

    UOnlineTitleFileDownloadBase_execAddRequestTitleFileListCompleteDelegate_Parms
        AddRequestTitleFileListCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddRequestTitleFileListCompleteDelegate,
                       &AddRequestTitleFileListCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.OnRequestTitleFileListComplete
// [0x00120000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::OnRequestTitleFileListComplete() {
    static UFunction* pFnOnRequestTitleFileListComplete = NULL;

    if (!pFnOnRequestTitleFileListComplete)
        pFnOnRequestTitleFileListComplete =
            (UFunction*)UObject::GObjObjects()->Data[38170];

    UOnlineTitleFileDownloadBase_execOnRequestTitleFileListComplete_Parms
        OnRequestTitleFileListComplete_Parms;

    this->ProcessEvent(pFnOnRequestTitleFileListComplete,
                       &OnRequestTitleFileListComplete_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.RequestTitleFileList
// [0x00020000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::RequestTitleFileList() {
    static UFunction* pFnRequestTitleFileList = NULL;

    if (!pFnRequestTitleFileList)
        pFnRequestTitleFileList =
            (UFunction*)UObject::GObjObjects()->Data[38168];

    UOnlineTitleFileDownloadBase_execRequestTitleFileList_Parms
        RequestTitleFileList_Parms;

    this->ProcessEvent(pFnRequestTitleFileList, &RequestTitleFileList_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.ClearDownloadedFile
// [0x00020000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::ClearDownloadedFile() {
    static UFunction* pFnClearDownloadedFile = NULL;

    if (!pFnClearDownloadedFile)
        pFnClearDownloadedFile =
            (UFunction*)UObject::GObjObjects()->Data[38165];

    UOnlineTitleFileDownloadBase_execClearDownloadedFile_Parms
        ClearDownloadedFile_Parms;

    this->ProcessEvent(pFnClearDownloadedFile, &ClearDownloadedFile_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.ClearDownloadedFiles
// [0x00020000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::ClearDownloadedFiles() {
    static UFunction* pFnClearDownloadedFiles = NULL;

    if (!pFnClearDownloadedFiles)
        pFnClearDownloadedFiles =
            (UFunction*)UObject::GObjObjects()->Data[38163];

    UOnlineTitleFileDownloadBase_execClearDownloadedFiles_Parms
        ClearDownloadedFiles_Parms;

    this->ProcessEvent(pFnClearDownloadedFiles, &ClearDownloadedFiles_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.GetTitleFileState
// [0x00020000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::GetTitleFileState() {
    static UFunction* pFnGetTitleFileState = NULL;

    if (!pFnGetTitleFileState)
        pFnGetTitleFileState = (UFunction*)UObject::GObjObjects()->Data[38160];

    UOnlineTitleFileDownloadBase_execGetTitleFileState_Parms
        GetTitleFileState_Parms;

    this->ProcessEvent(pFnGetTitleFileState, &GetTitleFileState_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.GetTitleFileContents
// [0x00420000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::GetTitleFileContents() {
    static UFunction* pFnGetTitleFileContents = NULL;

    if (!pFnGetTitleFileContents)
        pFnGetTitleFileContents =
            (UFunction*)UObject::GObjObjects()->Data[38155];

    UOnlineTitleFileDownloadBase_execGetTitleFileContents_Parms
        GetTitleFileContents_Parms;

    this->ProcessEvent(pFnGetTitleFileContents, &GetTitleFileContents_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.ClearReadTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadBase::ClearReadTitleFileCompleteDelegate() {
    static UFunction* pFnClearReadTitleFileCompleteDelegate = NULL;

    if (!pFnClearReadTitleFileCompleteDelegate)
        pFnClearReadTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[38152];

    UOnlineTitleFileDownloadBase_execClearReadTitleFileCompleteDelegate_Parms
        ClearReadTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearReadTitleFileCompleteDelegate,
                       &ClearReadTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.AddReadTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadBase::AddReadTitleFileCompleteDelegate() {
    static UFunction* pFnAddReadTitleFileCompleteDelegate = NULL;

    if (!pFnAddReadTitleFileCompleteDelegate)
        pFnAddReadTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[38150];

    UOnlineTitleFileDownloadBase_execAddReadTitleFileCompleteDelegate_Parms
        AddReadTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddReadTitleFileCompleteDelegate,
                       &AddReadTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.ReadTitleFile
// [0x00024000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::ReadTitleFile() {
    static UFunction* pFnReadTitleFile = NULL;

    if (!pFnReadTitleFile)
        pFnReadTitleFile = (UFunction*)UObject::GObjObjects()->Data[38146];

    UOnlineTitleFileDownloadBase_execReadTitleFile_Parms ReadTitleFile_Parms;

    this->ProcessEvent(pFnReadTitleFile, &ReadTitleFile_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadBase.OnReadTitleFileComplete
// [0x00120000]
// Parameters infos:

void UOnlineTitleFileDownloadBase::OnReadTitleFileComplete() {
    static UFunction* pFnOnReadTitleFileComplete = NULL;

    if (!pFnOnReadTitleFileComplete)
        pFnOnReadTitleFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[38143];

    UOnlineTitleFileDownloadBase_execOnReadTitleFileComplete_Parms
        OnReadTitleFileComplete_Parms;

    this->ProcessEvent(pFnOnReadTitleFileComplete,
                       &OnReadTitleFileComplete_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadMcp::ClearDownloadedFile() {
    static UFunction* pFnClearDownloadedFile = NULL;

    if (!pFnClearDownloadedFile)
        pFnClearDownloadedFile =
            (UFunction*)UObject::GObjObjects()->Data[41323];

    UOnlineTitleFileDownloadMcp_execClearDownloadedFile_Parms
        ClearDownloadedFile_Parms;

    pFnClearDownloadedFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearDownloadedFile, &ClearDownloadedFile_Parms,
                       NULL);

    pFnClearDownloadedFile->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadMcp.ClearDownloadedFiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadMcp::ClearDownloadedFiles() {
    static UFunction* pFnClearDownloadedFiles = NULL;

    if (!pFnClearDownloadedFiles)
        pFnClearDownloadedFiles =
            (UFunction*)UObject::GObjObjects()->Data[41321];

    UOnlineTitleFileDownloadMcp_execClearDownloadedFiles_Parms
        ClearDownloadedFiles_Parms;

    pFnClearDownloadedFiles->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearDownloadedFiles, &ClearDownloadedFiles_Parms,
                       NULL);

    pFnClearDownloadedFiles->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileState
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadMcp::GetTitleFileState() {
    static UFunction* pFnGetTitleFileState = NULL;

    if (!pFnGetTitleFileState)
        pFnGetTitleFileState = (UFunction*)UObject::GObjObjects()->Data[41317];

    UOnlineTitleFileDownloadMcp_execGetTitleFileState_Parms
        GetTitleFileState_Parms;

    this->ProcessEvent(pFnGetTitleFileState, &GetTitleFileState_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadMcp.GetTitleFileContents
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadMcp::GetTitleFileContents() {
    static UFunction* pFnGetTitleFileContents = NULL;

    if (!pFnGetTitleFileContents)
        pFnGetTitleFileContents =
            (UFunction*)UObject::GObjObjects()->Data[41312];

    UOnlineTitleFileDownloadMcp_execGetTitleFileContents_Parms
        GetTitleFileContents_Parms;

    pFnGetTitleFileContents->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileContents, &GetTitleFileContents_Parms,
                       NULL);

    pFnGetTitleFileContents->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadMcp.ReadTitleFile
// [0x00024400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadMcp::ReadTitleFile() {
    static UFunction* pFnReadTitleFile = NULL;

    if (!pFnReadTitleFile)
        pFnReadTitleFile = (UFunction*)UObject::GObjObjects()->Data[41308];

    UOnlineTitleFileDownloadMcp_execReadTitleFile_Parms ReadTitleFile_Parms;

    pFnReadTitleFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadTitleFile, &ReadTitleFile_Parms, NULL);

    pFnReadTitleFile->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadWeb.GetUrlForFile
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadWeb::GetUrlForFile() {
    static UFunction* pFnGetUrlForFile = NULL;

    if (!pFnGetUrlForFile)
        pFnGetUrlForFile = (UFunction*)UObject::GObjObjects()->Data[38239];

    UOnlineTitleFileDownloadWeb_execGetUrlForFile_Parms GetUrlForFile_Parms;

    this->ProcessEvent(pFnGetUrlForFile, &GetUrlForFile_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.OnFileListReceived
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadWeb::OnFileListReceived() {
    static UFunction* pFnOnFileListReceived = NULL;

    if (!pFnOnFileListReceived)
        pFnOnFileListReceived = (UFunction*)UObject::GObjObjects()->Data[38230];

    UOnlineTitleFileDownloadWeb_execOnFileListReceived_Parms
        OnFileListReceived_Parms;

    this->ProcessEvent(pFnOnFileListReceived, &OnFileListReceived_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.RequestTitleFileList
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadWeb::RequestTitleFileList() {
    static UFunction* pFnRequestTitleFileList = NULL;

    if (!pFnRequestTitleFileList)
        pFnRequestTitleFileList =
            (UFunction*)UObject::GObjObjects()->Data[38226];

    UOnlineTitleFileDownloadWeb_execRequestTitleFileList_Parms
        RequestTitleFileList_Parms;

    this->ProcessEvent(pFnRequestTitleFileList, &RequestTitleFileList_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.ClearDownloadedFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::ClearDownloadedFile() {
    static UFunction* pFnClearDownloadedFile = NULL;

    if (!pFnClearDownloadedFile)
        pFnClearDownloadedFile =
            (UFunction*)UObject::GObjObjects()->Data[38223];

    UOnlineTitleFileDownloadWeb_execClearDownloadedFile_Parms
        ClearDownloadedFile_Parms;

    pFnClearDownloadedFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearDownloadedFile, &ClearDownloadedFile_Parms,
                       NULL);

    pFnClearDownloadedFile->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadWeb.ClearDownloadedFiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::ClearDownloadedFiles() {
    static UFunction* pFnClearDownloadedFiles = NULL;

    if (!pFnClearDownloadedFiles)
        pFnClearDownloadedFiles =
            (UFunction*)UObject::GObjObjects()->Data[38221];

    UOnlineTitleFileDownloadWeb_execClearDownloadedFiles_Parms
        ClearDownloadedFiles_Parms;

    pFnClearDownloadedFiles->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearDownloadedFiles, &ClearDownloadedFiles_Parms,
                       NULL);

    pFnClearDownloadedFiles->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadWeb.GetTitleFileState
// [0x00020002]
// Parameters infos:

void UOnlineTitleFileDownloadWeb::GetTitleFileState() {
    static UFunction* pFnGetTitleFileState = NULL;

    if (!pFnGetTitleFileState)
        pFnGetTitleFileState = (UFunction*)UObject::GObjObjects()->Data[38217];

    UOnlineTitleFileDownloadWeb_execGetTitleFileState_Parms
        GetTitleFileState_Parms;

    this->ProcessEvent(pFnGetTitleFileState, &GetTitleFileState_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.GetTitleFileContents
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::GetTitleFileContents() {
    static UFunction* pFnGetTitleFileContents = NULL;

    if (!pFnGetTitleFileContents)
        pFnGetTitleFileContents =
            (UFunction*)UObject::GObjObjects()->Data[38212];

    UOnlineTitleFileDownloadWeb_execGetTitleFileContents_Parms
        GetTitleFileContents_Parms;

    pFnGetTitleFileContents->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileContents, &GetTitleFileContents_Parms,
                       NULL);

    pFnGetTitleFileContents->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadWeb.TriggerDelegates
// [0x00040401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::TriggerDelegates() {
    static UFunction* pFnTriggerDelegates = NULL;

    if (!pFnTriggerDelegates)
        pFnTriggerDelegates = (UFunction*)UObject::GObjObjects()->Data[38209];

    UOnlineTitleFileDownloadWeb_execTriggerDelegates_Parms
        TriggerDelegates_Parms;

    pFnTriggerDelegates->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnTriggerDelegates, &TriggerDelegates_Parms, NULL);

    pFnTriggerDelegates->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineTitleFileDownloadWeb.OnFileDownloadComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::OnFileDownloadComplete() {
    static UFunction* pFnOnFileDownloadComplete = NULL;

    if (!pFnOnFileDownloadComplete)
        pFnOnFileDownloadComplete =
            (UFunction*)UObject::GObjObjects()->Data[38198];

    UOnlineTitleFileDownloadWeb_execOnFileDownloadComplete_Parms
        OnFileDownloadComplete_Parms;

    this->ProcessEvent(pFnOnFileDownloadComplete, &OnFileDownloadComplete_Parms,
                       NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.ReadTitleFile
// [0x00024002]
// Parameters infos:

void UOnlineTitleFileDownloadWeb::ReadTitleFile() {
    static UFunction* pFnReadTitleFile = NULL;

    if (!pFnReadTitleFile)
        pFnReadTitleFile = (UFunction*)UObject::GObjObjects()->Data[38191];

    UOnlineTitleFileDownloadWeb_execReadTitleFile_Parms ReadTitleFile_Parms;

    this->ProcessEvent(pFnReadTitleFile, &ReadTitleFile_Parms, NULL);
};

// Function IpDrv.OnlineTitleFileDownloadWeb.UncompressTitleFileContents
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineTitleFileDownloadWeb::UncompressTitleFileContents() {
    static UFunction* pFnUncompressTitleFileContents = NULL;

    if (!pFnUncompressTitleFileContents)
        pFnUncompressTitleFileContents =
            (UFunction*)UObject::GObjObjects()->Data[38184];

    UOnlineTitleFileDownloadWeb_execUncompressTitleFileContents_Parms
        UncompressTitleFileContents_Parms;

    pFnUncompressTitleFileContents->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUncompressTitleFileContents,
                       &UncompressTitleFileContents_Parms, NULL);

    pFnUncompressTitleFileContents->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.DeleteTitleFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::DeleteTitleFile() {
    static UFunction* pFnDeleteTitleFile = NULL;

    if (!pFnDeleteTitleFile)
        pFnDeleteTitleFile = (UFunction*)UObject::GObjObjects()->Data[41599];

    UTitleFileDownloadCache_execDeleteTitleFile_Parms DeleteTitleFile_Parms;

    pFnDeleteTitleFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDeleteTitleFile, &DeleteTitleFile_Parms, NULL);

    pFnDeleteTitleFile->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.DeleteTitleFiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::DeleteTitleFiles() {
    static UFunction* pFnDeleteTitleFiles = NULL;

    if (!pFnDeleteTitleFiles)
        pFnDeleteTitleFiles = (UFunction*)UObject::GObjObjects()->Data[41596];

    UTitleFileDownloadCache_execDeleteTitleFiles_Parms DeleteTitleFiles_Parms;

    pFnDeleteTitleFiles->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDeleteTitleFiles, &DeleteTitleFiles_Parms, NULL);

    pFnDeleteTitleFiles->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.ClearCachedFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::ClearCachedFile() {
    static UFunction* pFnClearCachedFile = NULL;

    if (!pFnClearCachedFile)
        pFnClearCachedFile = (UFunction*)UObject::GObjObjects()->Data[41593];

    UTitleFileDownloadCache_execClearCachedFile_Parms ClearCachedFile_Parms;

    pFnClearCachedFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearCachedFile, &ClearCachedFile_Parms, NULL);

    pFnClearCachedFile->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.ClearCachedFiles
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::ClearCachedFiles() {
    static UFunction* pFnClearCachedFiles = NULL;

    if (!pFnClearCachedFiles)
        pFnClearCachedFiles = (UFunction*)UObject::GObjObjects()->Data[41591];

    UTitleFileDownloadCache_execClearCachedFiles_Parms ClearCachedFiles_Parms;

    pFnClearCachedFiles->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearCachedFiles, &ClearCachedFiles_Parms, NULL);

    pFnClearCachedFiles->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.GetTitleFileLogicalName
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::GetTitleFileLogicalName() {
    static UFunction* pFnGetTitleFileLogicalName = NULL;

    if (!pFnGetTitleFileLogicalName)
        pFnGetTitleFileLogicalName =
            (UFunction*)UObject::GObjObjects()->Data[41588];

    UTitleFileDownloadCache_execGetTitleFileLogicalName_Parms
        GetTitleFileLogicalName_Parms;

    pFnGetTitleFileLogicalName->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileLogicalName,
                       &GetTitleFileLogicalName_Parms, NULL);

    pFnGetTitleFileLogicalName->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.GetTitleFileHash
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::GetTitleFileHash() {
    static UFunction* pFnGetTitleFileHash = NULL;

    if (!pFnGetTitleFileHash)
        pFnGetTitleFileHash = (UFunction*)UObject::GObjObjects()->Data[41585];

    UTitleFileDownloadCache_execGetTitleFileHash_Parms GetTitleFileHash_Parms;

    pFnGetTitleFileHash->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileHash, &GetTitleFileHash_Parms, NULL);

    pFnGetTitleFileHash->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.GetTitleFileState
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::GetTitleFileState() {
    static UFunction* pFnGetTitleFileState = NULL;

    if (!pFnGetTitleFileState)
        pFnGetTitleFileState = (UFunction*)UObject::GObjObjects()->Data[41582];

    UTitleFileDownloadCache_execGetTitleFileState_Parms GetTitleFileState_Parms;

    pFnGetTitleFileState->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileState, &GetTitleFileState_Parms, NULL);

    pFnGetTitleFileState->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.GetTitleFileContents
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::GetTitleFileContents() {
    static UFunction* pFnGetTitleFileContents = NULL;

    if (!pFnGetTitleFileContents)
        pFnGetTitleFileContents =
            (UFunction*)UObject::GObjObjects()->Data[41577];

    UTitleFileDownloadCache_execGetTitleFileContents_Parms
        GetTitleFileContents_Parms;

    pFnGetTitleFileContents->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetTitleFileContents, &GetTitleFileContents_Parms,
                       NULL);

    pFnGetTitleFileContents->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.ClearSaveTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UTitleFileDownloadCache::ClearSaveTitleFileCompleteDelegate() {
    static UFunction* pFnClearSaveTitleFileCompleteDelegate = NULL;

    if (!pFnClearSaveTitleFileCompleteDelegate)
        pFnClearSaveTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41574];

    UTitleFileDownloadCache_execClearSaveTitleFileCompleteDelegate_Parms
        ClearSaveTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearSaveTitleFileCompleteDelegate,
                       &ClearSaveTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.AddSaveTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UTitleFileDownloadCache::AddSaveTitleFileCompleteDelegate() {
    static UFunction* pFnAddSaveTitleFileCompleteDelegate = NULL;

    if (!pFnAddSaveTitleFileCompleteDelegate)
        pFnAddSaveTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41572];

    UTitleFileDownloadCache_execAddSaveTitleFileCompleteDelegate_Parms
        AddSaveTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddSaveTitleFileCompleteDelegate,
                       &AddSaveTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.OnSaveTitleFileComplete
// [0x00120000]
// Parameters infos:

void UTitleFileDownloadCache::OnSaveTitleFileComplete() {
    static UFunction* pFnOnSaveTitleFileComplete = NULL;

    if (!pFnOnSaveTitleFileComplete)
        pFnOnSaveTitleFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[41569];

    UTitleFileDownloadCache_execOnSaveTitleFileComplete_Parms
        OnSaveTitleFileComplete_Parms;

    this->ProcessEvent(pFnOnSaveTitleFileComplete,
                       &OnSaveTitleFileComplete_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.SaveTitleFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::SaveTitleFile() {
    static UFunction* pFnSaveTitleFile = NULL;

    if (!pFnSaveTitleFile)
        pFnSaveTitleFile = (UFunction*)UObject::GObjObjects()->Data[41563];

    UTitleFileDownloadCache_execSaveTitleFile_Parms SaveTitleFile_Parms;

    pFnSaveTitleFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSaveTitleFile, &SaveTitleFile_Parms, NULL);

    pFnSaveTitleFile->FunctionFlags |= 0x400;
};

// Function IpDrv.TitleFileDownloadCache.ClearLoadTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UTitleFileDownloadCache::ClearLoadTitleFileCompleteDelegate() {
    static UFunction* pFnClearLoadTitleFileCompleteDelegate = NULL;

    if (!pFnClearLoadTitleFileCompleteDelegate)
        pFnClearLoadTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41560];

    UTitleFileDownloadCache_execClearLoadTitleFileCompleteDelegate_Parms
        ClearLoadTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearLoadTitleFileCompleteDelegate,
                       &ClearLoadTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.AddLoadTitleFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UTitleFileDownloadCache::AddLoadTitleFileCompleteDelegate() {
    static UFunction* pFnAddLoadTitleFileCompleteDelegate = NULL;

    if (!pFnAddLoadTitleFileCompleteDelegate)
        pFnAddLoadTitleFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41558];

    UTitleFileDownloadCache_execAddLoadTitleFileCompleteDelegate_Parms
        AddLoadTitleFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddLoadTitleFileCompleteDelegate,
                       &AddLoadTitleFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.OnLoadTitleFileComplete
// [0x00120000]
// Parameters infos:

void UTitleFileDownloadCache::OnLoadTitleFileComplete() {
    static UFunction* pFnOnLoadTitleFileComplete = NULL;

    if (!pFnOnLoadTitleFileComplete)
        pFnOnLoadTitleFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[41555];

    UTitleFileDownloadCache_execOnLoadTitleFileComplete_Parms
        OnLoadTitleFileComplete_Parms;

    this->ProcessEvent(pFnOnLoadTitleFileComplete,
                       &OnLoadTitleFileComplete_Parms, NULL);
};

// Function IpDrv.TitleFileDownloadCache.LoadTitleFile
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UTitleFileDownloadCache::LoadTitleFile() {
    static UFunction* pFnLoadTitleFile = NULL;

    if (!pFnLoadTitleFile)
        pFnLoadTitleFile = (UFunction*)UObject::GObjObjects()->Data[41552];

    UTitleFileDownloadCache_execLoadTitleFile_Parms LoadTitleFile_Parms;

    pFnLoadTitleFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnLoadTitleFile, &LoadTitleFile_Parms, NULL);

    pFnLoadTitleFile->FunctionFlags |= 0x400;
};

// Function IpDrv.McpMessageBase.CacheMessageContents
// [0x00420000]
// Parameters infos:

void UMcpMessageBase::CacheMessageContents() {
    static UFunction* pFnCacheMessageContents = NULL;

    if (!pFnCacheMessageContents)
        pFnCacheMessageContents =
            (UFunction*)UObject::GObjObjects()->Data[39065];

    UMcpMessageBase_execCacheMessageContents_Parms CacheMessageContents_Parms;

    this->ProcessEvent(pFnCacheMessageContents, &CacheMessageContents_Parms,
                       NULL);
};

// Function IpDrv.McpMessageBase.CacheMessage
// [0x00020000]
// Parameters infos:

void UMcpMessageBase::CacheMessage() {
    static UFunction* pFnCacheMessage = NULL;

    if (!pFnCacheMessage)
        pFnCacheMessage = (UFunction*)UObject::GObjObjects()->Data[39063];

    UMcpMessageBase_execCacheMessage_Parms CacheMessage_Parms;

    this->ProcessEvent(pFnCacheMessage, &CacheMessage_Parms, NULL);
};

// Function IpDrv.McpMessageBase.GetMessageContents
// [0x00420000]
// Parameters infos:

void UMcpMessageBase::GetMessageContents() {
    static UFunction* pFnGetMessageContents = NULL;

    if (!pFnGetMessageContents)
        pFnGetMessageContents = (UFunction*)UObject::GObjObjects()->Data[39058];

    UMcpMessageBase_execGetMessageContents_Parms GetMessageContents_Parms;

    this->ProcessEvent(pFnGetMessageContents, &GetMessageContents_Parms, NULL);
};

// Function IpDrv.McpMessageBase.OnQueryMessageContentsComplete
// [0x00120000]
// Parameters infos:

void UMcpMessageBase::OnQueryMessageContentsComplete() {
    static UFunction* pFnOnQueryMessageContentsComplete = NULL;

    if (!pFnOnQueryMessageContentsComplete)
        pFnOnQueryMessageContentsComplete =
            (UFunction*)UObject::GObjObjects()->Data[39054];

    UMcpMessageBase_execOnQueryMessageContentsComplete_Parms
        OnQueryMessageContentsComplete_Parms;

    this->ProcessEvent(pFnOnQueryMessageContentsComplete,
                       &OnQueryMessageContentsComplete_Parms, NULL);
};

// Function IpDrv.McpMessageBase.QueryMessageContents
// [0x00020000]
// Parameters infos:

void UMcpMessageBase::QueryMessageContents() {
    static UFunction* pFnQueryMessageContents = NULL;

    if (!pFnQueryMessageContents)
        pFnQueryMessageContents =
            (UFunction*)UObject::GObjObjects()->Data[39052];

    UMcpMessageBase_execQueryMessageContents_Parms QueryMessageContents_Parms;

    this->ProcessEvent(pFnQueryMessageContents, &QueryMessageContents_Parms,
                       NULL);
};

// Function IpDrv.McpMessageBase.GetMessageList
// [0x00420000]
// Parameters infos:

void UMcpMessageBase::GetMessageList() {
    static UFunction* pFnGetMessageList = NULL;

    if (!pFnGetMessageList)
        pFnGetMessageList = (UFunction*)UObject::GObjObjects()->Data[39049];

    UMcpMessageBase_execGetMessageList_Parms GetMessageList_Parms;

    this->ProcessEvent(pFnGetMessageList, &GetMessageList_Parms, NULL);
};

// Function IpDrv.McpMessageBase.OnQueryMessagesComplete
// [0x00120000]
// Parameters infos:

void UMcpMessageBase::OnQueryMessagesComplete() {
    static UFunction* pFnOnQueryMessagesComplete = NULL;

    if (!pFnOnQueryMessagesComplete)
        pFnOnQueryMessagesComplete =
            (UFunction*)UObject::GObjObjects()->Data[39045];

    UMcpMessageBase_execOnQueryMessagesComplete_Parms
        OnQueryMessagesComplete_Parms;

    this->ProcessEvent(pFnOnQueryMessagesComplete,
                       &OnQueryMessagesComplete_Parms, NULL);
};

// Function IpDrv.McpMessageBase.QueryMessages
// [0x00020000]
// Parameters infos:

void UMcpMessageBase::QueryMessages() {
    static UFunction* pFnQueryMessages = NULL;

    if (!pFnQueryMessages)
        pFnQueryMessages = (UFunction*)UObject::GObjObjects()->Data[39043];

    UMcpMessageBase_execQueryMessages_Parms QueryMessages_Parms;

    this->ProcessEvent(pFnQueryMessages, &QueryMessages_Parms, NULL);
};

// Function IpDrv.McpMessageBase.OnDeleteMessageComplete
// [0x00120000]
// Parameters infos:

void UMcpMessageBase::OnDeleteMessageComplete() {
    static UFunction* pFnOnDeleteMessageComplete = NULL;

    if (!pFnOnDeleteMessageComplete)
        pFnOnDeleteMessageComplete =
            (UFunction*)UObject::GObjObjects()->Data[39039];

    UMcpMessageBase_execOnDeleteMessageComplete_Parms
        OnDeleteMessageComplete_Parms;

    this->ProcessEvent(pFnOnDeleteMessageComplete,
                       &OnDeleteMessageComplete_Parms, NULL);
};

// Function IpDrv.McpMessageBase.DeleteMessage
// [0x00020000]
// Parameters infos:

void UMcpMessageBase::DeleteMessage() {
    static UFunction* pFnDeleteMessage = NULL;

    if (!pFnDeleteMessage)
        pFnDeleteMessage = (UFunction*)UObject::GObjObjects()->Data[39037];

    UMcpMessageBase_execDeleteMessage_Parms DeleteMessage_Parms;

    this->ProcessEvent(pFnDeleteMessage, &DeleteMessage_Parms, NULL);
};

// Function IpDrv.McpMessageBase.OnCreateMessageComplete
// [0x00120000]
// Parameters infos:

void UMcpMessageBase::OnCreateMessageComplete() {
    static UFunction* pFnOnCreateMessageComplete = NULL;

    if (!pFnOnCreateMessageComplete)
        pFnOnCreateMessageComplete =
            (UFunction*)UObject::GObjObjects()->Data[39033];

    UMcpMessageBase_execOnCreateMessageComplete_Parms
        OnCreateMessageComplete_Parms;

    this->ProcessEvent(pFnOnCreateMessageComplete,
                       &OnCreateMessageComplete_Parms, NULL);
};

// Function IpDrv.McpMessageBase.CreateMessage
// [0x00420000]
// Parameters infos:

void UMcpMessageBase::CreateMessage() {
    static UFunction* pFnCreateMessage = NULL;

    if (!pFnCreateMessage)
        pFnCreateMessage = (UFunction*)UObject::GObjObjects()->Data[39023];

    UMcpMessageBase_execCreateMessage_Parms CreateMessage_Parms;

    this->ProcessEvent(pFnCreateMessage, &CreateMessage_Parms, NULL);
};

// Function IpDrv.McpMessageBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpMessageBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[39019];

    UMcpMessageBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpMessageManager.CacheMessageContents
// [0x00420002]
// Parameters infos:

void UMcpMessageManager::CacheMessageContents() {
    static UFunction* pFnCacheMessageContents = NULL;

    if (!pFnCacheMessageContents)
        pFnCacheMessageContents =
            (UFunction*)UObject::GObjObjects()->Data[39209];

    UMcpMessageManager_execCacheMessageContents_Parms
        CacheMessageContents_Parms;

    this->ProcessEvent(pFnCacheMessageContents, &CacheMessageContents_Parms,
                       NULL);
};

// Function IpDrv.McpMessageManager.GetMessageById
// [0x00420002]
// Parameters infos:

void UMcpMessageManager::GetMessageById() {
    static UFunction* pFnGetMessageById = NULL;

    if (!pFnGetMessageById)
        pFnGetMessageById = (UFunction*)UObject::GObjObjects()->Data[39202];

    UMcpMessageManager_execGetMessageById_Parms GetMessageById_Parms;

    this->ProcessEvent(pFnGetMessageById, &GetMessageById_Parms, NULL);
};

// Function IpDrv.McpMessageManager.CacheMessage
// [0x00820002]
// Parameters infos:

void UMcpMessageManager::CacheMessage() {
    static UFunction* pFnCacheMessage = NULL;

    if (!pFnCacheMessage)
        pFnCacheMessage = (UFunction*)UObject::GObjObjects()->Data[39195];

    UMcpMessageManager_execCacheMessage_Parms CacheMessage_Parms;

    this->ProcessEvent(pFnCacheMessage, &CacheMessage_Parms, NULL);
};

// Function IpDrv.McpMessageManager.GetMessageContents
// [0x00420002]
// Parameters infos:

void UMcpMessageManager::GetMessageContents() {
    static UFunction* pFnGetMessageContents = NULL;

    if (!pFnGetMessageContents)
        pFnGetMessageContents = (UFunction*)UObject::GObjObjects()->Data[39188];

    UMcpMessageManager_execGetMessageContents_Parms GetMessageContents_Parms;

    this->ProcessEvent(pFnGetMessageContents, &GetMessageContents_Parms, NULL);
};

// Function IpDrv.McpMessageManager.OnQueryMessageContentsRequestComplete
// [0x00840003] ( FUNC_Final )
// Parameters infos:

void UMcpMessageManager::OnQueryMessageContentsRequestComplete() {
    static UFunction* pFnOnQueryMessageContentsRequestComplete = NULL;

    if (!pFnOnQueryMessageContentsRequestComplete)
        pFnOnQueryMessageContentsRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39179];

    UMcpMessageManager_execOnQueryMessageContentsRequestComplete_Parms
        OnQueryMessageContentsRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryMessageContentsRequestComplete,
                       &OnQueryMessageContentsRequestComplete_Parms, NULL);
};

// Function IpDrv.McpMessageManager.QueryMessageContents
// [0x00020002]
// Parameters infos:

void UMcpMessageManager::QueryMessageContents() {
    static UFunction* pFnQueryMessageContents = NULL;

    if (!pFnQueryMessageContents)
        pFnQueryMessageContents =
            (UFunction*)UObject::GObjObjects()->Data[39175];

    UMcpMessageManager_execQueryMessageContents_Parms
        QueryMessageContents_Parms;

    this->ProcessEvent(pFnQueryMessageContents, &QueryMessageContents_Parms,
                       NULL);
};

// Function IpDrv.McpMessageManager.GetMessageList
// [0x00420002]
// Parameters infos:

void UMcpMessageManager::GetMessageList() {
    static UFunction* pFnGetMessageList = NULL;

    if (!pFnGetMessageList)
        pFnGetMessageList = (UFunction*)UObject::GObjObjects()->Data[39171];

    UMcpMessageManager_execGetMessageList_Parms GetMessageList_Parms;

    this->ProcessEvent(pFnGetMessageList, &GetMessageList_Parms, NULL);
};

// Function IpDrv.McpMessageManager.OnQueryMessagesRequestComplete
// [0x00840003] ( FUNC_Final )
// Parameters infos:

void UMcpMessageManager::OnQueryMessagesRequestComplete() {
    static UFunction* pFnOnQueryMessagesRequestComplete = NULL;

    if (!pFnOnQueryMessagesRequestComplete)
        pFnOnQueryMessagesRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39160];

    UMcpMessageManager_execOnQueryMessagesRequestComplete_Parms
        OnQueryMessagesRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryMessagesRequestComplete,
                       &OnQueryMessagesRequestComplete_Parms, NULL);
};

// Function IpDrv.McpMessageManager.QueryMessages
// [0x00020002]
// Parameters infos:

void UMcpMessageManager::QueryMessages() {
    static UFunction* pFnQueryMessages = NULL;

    if (!pFnQueryMessages)
        pFnQueryMessages = (UFunction*)UObject::GObjObjects()->Data[39156];

    UMcpMessageManager_execQueryMessages_Parms QueryMessages_Parms;

    this->ProcessEvent(pFnQueryMessages, &QueryMessages_Parms, NULL);
};

// Function IpDrv.McpMessageManager.OnDeleteMessageRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpMessageManager::OnDeleteMessageRequestComplete() {
    static UFunction* pFnOnDeleteMessageRequestComplete = NULL;

    if (!pFnOnDeleteMessageRequestComplete)
        pFnOnDeleteMessageRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39149];

    UMcpMessageManager_execOnDeleteMessageRequestComplete_Parms
        OnDeleteMessageRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteMessageRequestComplete,
                       &OnDeleteMessageRequestComplete_Parms, NULL);
};

// Function IpDrv.McpMessageManager.DeleteMessage
// [0x00020002]
// Parameters infos:

void UMcpMessageManager::DeleteMessage() {
    static UFunction* pFnDeleteMessage = NULL;

    if (!pFnDeleteMessage)
        pFnDeleteMessage = (UFunction*)UObject::GObjObjects()->Data[39145];

    UMcpMessageManager_execDeleteMessage_Parms DeleteMessage_Parms;

    this->ProcessEvent(pFnDeleteMessage, &DeleteMessage_Parms, NULL);
};

// Function IpDrv.McpMessageManager.OnCreateMessageRequestComplete
// [0x00820002]
// Parameters infos:

void UMcpMessageManager::OnCreateMessageRequestComplete() {
    static UFunction* pFnOnCreateMessageRequestComplete = NULL;

    if (!pFnOnCreateMessageRequestComplete)
        pFnOnCreateMessageRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39138];

    UMcpMessageManager_execOnCreateMessageRequestComplete_Parms
        OnCreateMessageRequestComplete_Parms;

    this->ProcessEvent(pFnOnCreateMessageRequestComplete,
                       &OnCreateMessageRequestComplete_Parms, NULL);
};

// Function IpDrv.McpMessageManager.CreateMessage
// [0x00C20002]
// Parameters infos:

void UMcpMessageManager::CreateMessage() {
    static UFunction* pFnCreateMessage = NULL;

    if (!pFnCreateMessage)
        pFnCreateMessage = (UFunction*)UObject::GObjObjects()->Data[39123];

    UMcpMessageManager_execCreateMessage_Parms CreateMessage_Parms;

    this->ProcessEvent(pFnCreateMessage, &CreateMessage_Parms, NULL);
};

// Function IpDrv.McpMessageManager.FinishedAsyncUncompression
// [0x00420802] ( FUNC_Event )
// Parameters infos:

void UMcpMessageManager::eventFinishedAsyncUncompression() {
    static UFunction* pFnFinishedAsyncUncompression = NULL;

    if (!pFnFinishedAsyncUncompression)
        pFnFinishedAsyncUncompression =
            (UFunction*)UObject::GObjObjects()->Data[39118];

    UMcpMessageManager_eventFinishedAsyncUncompression_Parms
        FinishedAsyncUncompression_Parms;

    this->ProcessEvent(pFnFinishedAsyncUncompression,
                       &FinishedAsyncUncompression_Parms, NULL);
};

// Function IpDrv.McpMessageManager.StartAsyncUncompression
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMcpMessageManager::StartAsyncUncompression() {
    static UFunction* pFnStartAsyncUncompression = NULL;

    if (!pFnStartAsyncUncompression)
        pFnStartAsyncUncompression =
            (UFunction*)UObject::GObjObjects()->Data[39112];

    UMcpMessageManager_execStartAsyncUncompression_Parms
        StartAsyncUncompression_Parms;

    pFnStartAsyncUncompression->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnStartAsyncUncompression,
                       &StartAsyncUncompression_Parms, NULL);

    pFnStartAsyncUncompression->FunctionFlags |= 0x400;
};

// Function IpDrv.McpMessageManager.StartAsyncCompression
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMcpMessageManager::StartAsyncCompression() {
    static UFunction* pFnStartAsyncCompression = NULL;

    if (!pFnStartAsyncCompression)
        pFnStartAsyncCompression =
            (UFunction*)UObject::GObjObjects()->Data[39106];

    UMcpMessageManager_execStartAsyncCompression_Parms
        StartAsyncCompression_Parms;

    pFnStartAsyncCompression->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnStartAsyncCompression, &StartAsyncCompression_Parms,
                       NULL);

    pFnStartAsyncCompression->FunctionFlags |= 0x400;
};

// Function IpDrv.McpUserCloudFileDownload.ClearAllDelegates
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearAllDelegates() {
    static UFunction* pFnClearAllDelegates = NULL;

    if (!pFnClearAllDelegates)
        pFnClearAllDelegates = (UFunction*)UObject::GObjObjects()->Data[39444];

    UMcpUserCloudFileDownload_execClearAllDelegates_Parms
        ClearAllDelegates_Parms;

    this->ProcessEvent(pFnClearAllDelegates, &ClearAllDelegates_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ClearDeleteUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearDeleteUserFileCompleteDelegate() {
    static UFunction* pFnClearDeleteUserFileCompleteDelegate = NULL;

    if (!pFnClearDeleteUserFileCompleteDelegate)
        pFnClearDeleteUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39441];

    UMcpUserCloudFileDownload_execClearDeleteUserFileCompleteDelegate_Parms
        ClearDeleteUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearDeleteUserFileCompleteDelegate,
                       &ClearDeleteUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.AddDeleteUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::AddDeleteUserFileCompleteDelegate() {
    static UFunction* pFnAddDeleteUserFileCompleteDelegate = NULL;

    if (!pFnAddDeleteUserFileCompleteDelegate)
        pFnAddDeleteUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39439];

    UMcpUserCloudFileDownload_execAddDeleteUserFileCompleteDelegate_Parms
        AddDeleteUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddDeleteUserFileCompleteDelegate,
                       &AddDeleteUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.CallDeleteUserFileCompleteDelegates
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::CallDeleteUserFileCompleteDelegates() {
    static UFunction* pFnCallDeleteUserFileCompleteDelegates = NULL;

    if (!pFnCallDeleteUserFileCompleteDelegates)
        pFnCallDeleteUserFileCompleteDelegates =
            (UFunction*)UObject::GObjObjects()->Data[39433];

    UMcpUserCloudFileDownload_execCallDeleteUserFileCompleteDelegates_Parms
        CallDeleteUserFileCompleteDelegates_Parms;

    this->ProcessEvent(pFnCallDeleteUserFileCompleteDelegates,
                       &CallDeleteUserFileCompleteDelegates_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnDeleteUserFileComplete
// [0x00120000]
// Parameters infos:

void UMcpUserCloudFileDownload::OnDeleteUserFileComplete() {
    static UFunction* pFnOnDeleteUserFileComplete = NULL;

    if (!pFnOnDeleteUserFileComplete)
        pFnOnDeleteUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39429];

    UMcpUserCloudFileDownload_execOnDeleteUserFileComplete_Parms
        OnDeleteUserFileComplete_Parms;

    this->ProcessEvent(pFnOnDeleteUserFileComplete,
                       &OnDeleteUserFileComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnHTTPRequestDeleteUserFileComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::OnHTTPRequestDeleteUserFileComplete() {
    static UFunction* pFnOnHTTPRequestDeleteUserFileComplete = NULL;

    if (!pFnOnHTTPRequestDeleteUserFileComplete)
        pFnOnHTTPRequestDeleteUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39420];

    UMcpUserCloudFileDownload_execOnHTTPRequestDeleteUserFileComplete_Parms
        OnHTTPRequestDeleteUserFileComplete_Parms;

    this->ProcessEvent(pFnOnHTTPRequestDeleteUserFileComplete,
                       &OnHTTPRequestDeleteUserFileComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.DeleteUserFile
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::DeleteUserFile() {
    static UFunction* pFnDeleteUserFile = NULL;

    if (!pFnDeleteUserFile)
        pFnDeleteUserFile = (UFunction*)UObject::GObjObjects()->Data[39410];

    UMcpUserCloudFileDownload_execDeleteUserFile_Parms DeleteUserFile_Parms;

    this->ProcessEvent(pFnDeleteUserFile, &DeleteUserFile_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ClearWriteUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearWriteUserFileCompleteDelegate() {
    static UFunction* pFnClearWriteUserFileCompleteDelegate = NULL;

    if (!pFnClearWriteUserFileCompleteDelegate)
        pFnClearWriteUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39407];

    UMcpUserCloudFileDownload_execClearWriteUserFileCompleteDelegate_Parms
        ClearWriteUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearWriteUserFileCompleteDelegate,
                       &ClearWriteUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.AddWriteUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::AddWriteUserFileCompleteDelegate() {
    static UFunction* pFnAddWriteUserFileCompleteDelegate = NULL;

    if (!pFnAddWriteUserFileCompleteDelegate)
        pFnAddWriteUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39405];

    UMcpUserCloudFileDownload_execAddWriteUserFileCompleteDelegate_Parms
        AddWriteUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddWriteUserFileCompleteDelegate,
                       &AddWriteUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.CallWriteUserFileCompleteDelegates
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::CallWriteUserFileCompleteDelegates() {
    static UFunction* pFnCallWriteUserFileCompleteDelegates = NULL;

    if (!pFnCallWriteUserFileCompleteDelegates)
        pFnCallWriteUserFileCompleteDelegates =
            (UFunction*)UObject::GObjObjects()->Data[39399];

    UMcpUserCloudFileDownload_execCallWriteUserFileCompleteDelegates_Parms
        CallWriteUserFileCompleteDelegates_Parms;

    this->ProcessEvent(pFnCallWriteUserFileCompleteDelegates,
                       &CallWriteUserFileCompleteDelegates_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnWriteUserFileComplete
// [0x00120000]
// Parameters infos:

void UMcpUserCloudFileDownload::OnWriteUserFileComplete() {
    static UFunction* pFnOnWriteUserFileComplete = NULL;

    if (!pFnOnWriteUserFileComplete)
        pFnOnWriteUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39395];

    UMcpUserCloudFileDownload_execOnWriteUserFileComplete_Parms
        OnWriteUserFileComplete_Parms;

    this->ProcessEvent(pFnOnWriteUserFileComplete,
                       &OnWriteUserFileComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnHTTPRequestWriteUserFileComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::OnHTTPRequestWriteUserFileComplete() {
    static UFunction* pFnOnHTTPRequestWriteUserFileComplete = NULL;

    if (!pFnOnHTTPRequestWriteUserFileComplete)
        pFnOnHTTPRequestWriteUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39386];

    UMcpUserCloudFileDownload_execOnHTTPRequestWriteUserFileComplete_Parms
        OnHTTPRequestWriteUserFileComplete_Parms;

    this->ProcessEvent(pFnOnHTTPRequestWriteUserFileComplete,
                       &OnHTTPRequestWriteUserFileComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.GetUserFileIndexForRequest
// [0x00440003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::GetUserFileIndexForRequest() {
    static UFunction* pFnGetUserFileIndexForRequest = NULL;

    if (!pFnGetUserFileIndexForRequest)
        pFnGetUserFileIndexForRequest =
            (UFunction*)UObject::GObjObjects()->Data[39382];

    UMcpUserCloudFileDownload_execGetUserFileIndexForRequest_Parms
        GetUserFileIndexForRequest_Parms;

    this->ProcessEvent(pFnGetUserFileIndexForRequest,
                       &GetUserFileIndexForRequest_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.WriteUserFile
// [0x00420002]
// Parameters infos:

void UMcpUserCloudFileDownload::WriteUserFile() {
    static UFunction* pFnWriteUserFile = NULL;

    if (!pFnWriteUserFile)
        pFnWriteUserFile = (UFunction*)UObject::GObjObjects()->Data[39372];

    UMcpUserCloudFileDownload_execWriteUserFile_Parms WriteUserFile_Parms;

    this->ProcessEvent(pFnWriteUserFile, &WriteUserFile_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ClearReadUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearReadUserFileCompleteDelegate() {
    static UFunction* pFnClearReadUserFileCompleteDelegate = NULL;

    if (!pFnClearReadUserFileCompleteDelegate)
        pFnClearReadUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39369];

    UMcpUserCloudFileDownload_execClearReadUserFileCompleteDelegate_Parms
        ClearReadUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearReadUserFileCompleteDelegate,
                       &ClearReadUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.AddReadUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::AddReadUserFileCompleteDelegate() {
    static UFunction* pFnAddReadUserFileCompleteDelegate = NULL;

    if (!pFnAddReadUserFileCompleteDelegate)
        pFnAddReadUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39367];

    UMcpUserCloudFileDownload_execAddReadUserFileCompleteDelegate_Parms
        AddReadUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddReadUserFileCompleteDelegate,
                       &AddReadUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.CallReadUserFileCompleteDelegates
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::CallReadUserFileCompleteDelegates() {
    static UFunction* pFnCallReadUserFileCompleteDelegates = NULL;

    if (!pFnCallReadUserFileCompleteDelegates)
        pFnCallReadUserFileCompleteDelegates =
            (UFunction*)UObject::GObjObjects()->Data[39361];

    UMcpUserCloudFileDownload_execCallReadUserFileCompleteDelegates_Parms
        CallReadUserFileCompleteDelegates_Parms;

    this->ProcessEvent(pFnCallReadUserFileCompleteDelegates,
                       &CallReadUserFileCompleteDelegates_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnReadUserFileComplete
// [0x00120000]
// Parameters infos:

void UMcpUserCloudFileDownload::OnReadUserFileComplete() {
    static UFunction* pFnOnReadUserFileComplete = NULL;

    if (!pFnOnReadUserFileComplete)
        pFnOnReadUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39357];

    UMcpUserCloudFileDownload_execOnReadUserFileComplete_Parms
        OnReadUserFileComplete_Parms;

    this->ProcessEvent(pFnOnReadUserFileComplete, &OnReadUserFileComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnHTTPRequestReadUserFileComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::OnHTTPRequestReadUserFileComplete() {
    static UFunction* pFnOnHTTPRequestReadUserFileComplete = NULL;

    if (!pFnOnHTTPRequestReadUserFileComplete)
        pFnOnHTTPRequestReadUserFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[39346];

    UMcpUserCloudFileDownload_execOnHTTPRequestReadUserFileComplete_Parms
        OnHTTPRequestReadUserFileComplete_Parms;

    this->ProcessEvent(pFnOnHTTPRequestReadUserFileComplete,
                       &OnHTTPRequestReadUserFileComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ReadUserFile
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ReadUserFile() {
    static UFunction* pFnReadUserFile = NULL;

    if (!pFnReadUserFile)
        pFnReadUserFile = (UFunction*)UObject::GObjObjects()->Data[39338];

    UMcpUserCloudFileDownload_execReadUserFile_Parms ReadUserFile_Parms;

    this->ProcessEvent(pFnReadUserFile, &ReadUserFile_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.GetUserFileList
// [0x00420002]
// Parameters infos:

void UMcpUserCloudFileDownload::GetUserFileList() {
    static UFunction* pFnGetUserFileList = NULL;

    if (!pFnGetUserFileList)
        pFnGetUserFileList = (UFunction*)UObject::GObjObjects()->Data[39332];

    UMcpUserCloudFileDownload_execGetUserFileList_Parms GetUserFileList_Parms;

    this->ProcessEvent(pFnGetUserFileList, &GetUserFileList_Parms, NULL);
};

// Function
// IpDrv.McpUserCloudFileDownload.ClearEnumerateUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearEnumerateUserFileCompleteDelegate() {
    static UFunction* pFnClearEnumerateUserFileCompleteDelegate = NULL;

    if (!pFnClearEnumerateUserFileCompleteDelegate)
        pFnClearEnumerateUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39329];

    UMcpUserCloudFileDownload_execClearEnumerateUserFileCompleteDelegate_Parms
        ClearEnumerateUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearEnumerateUserFileCompleteDelegate,
                       &ClearEnumerateUserFileCompleteDelegate_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.AddEnumerateUserFileCompleteDelegate
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::AddEnumerateUserFileCompleteDelegate() {
    static UFunction* pFnAddEnumerateUserFileCompleteDelegate = NULL;

    if (!pFnAddEnumerateUserFileCompleteDelegate)
        pFnAddEnumerateUserFileCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[39327];

    UMcpUserCloudFileDownload_execAddEnumerateUserFileCompleteDelegate_Parms
        AddEnumerateUserFileCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddEnumerateUserFileCompleteDelegate,
                       &AddEnumerateUserFileCompleteDelegate_Parms, NULL);
};

// Function
// IpDrv.McpUserCloudFileDownload.CallEnumerateUserFileCompleteDelegates
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::CallEnumerateUserFileCompleteDelegates() {
    static UFunction* pFnCallEnumerateUserFileCompleteDelegates = NULL;

    if (!pFnCallEnumerateUserFileCompleteDelegates)
        pFnCallEnumerateUserFileCompleteDelegates =
            (UFunction*)UObject::GObjObjects()->Data[39322];

    UMcpUserCloudFileDownload_execCallEnumerateUserFileCompleteDelegates_Parms
        CallEnumerateUserFileCompleteDelegates_Parms;

    this->ProcessEvent(pFnCallEnumerateUserFileCompleteDelegates,
                       &CallEnumerateUserFileCompleteDelegates_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.OnEnumerateUserFilesComplete
// [0x00120000]
// Parameters infos:

void UMcpUserCloudFileDownload::OnEnumerateUserFilesComplete() {
    static UFunction* pFnOnEnumerateUserFilesComplete = NULL;

    if (!pFnOnEnumerateUserFilesComplete)
        pFnOnEnumerateUserFilesComplete =
            (UFunction*)UObject::GObjObjects()->Data[39319];

    UMcpUserCloudFileDownload_execOnEnumerateUserFilesComplete_Parms
        OnEnumerateUserFilesComplete_Parms;

    this->ProcessEvent(pFnOnEnumerateUserFilesComplete,
                       &OnEnumerateUserFilesComplete_Parms, NULL);
};

// Function
// IpDrv.McpUserCloudFileDownload.OnHTTPRequestEnumerateUserFilesComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpUserCloudFileDownload::OnHTTPRequestEnumerateUserFilesComplete() {
    static UFunction* pFnOnHTTPRequestEnumerateUserFilesComplete = NULL;

    if (!pFnOnHTTPRequestEnumerateUserFilesComplete)
        pFnOnHTTPRequestEnumerateUserFilesComplete =
            (UFunction*)UObject::GObjObjects()->Data[39309];

    UMcpUserCloudFileDownload_execOnHTTPRequestEnumerateUserFilesComplete_Parms
        OnHTTPRequestEnumerateUserFilesComplete_Parms;

    this->ProcessEvent(pFnOnHTTPRequestEnumerateUserFilesComplete,
                       &OnHTTPRequestEnumerateUserFilesComplete_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.EnumerateUserFiles
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::EnumerateUserFiles() {
    static UFunction* pFnEnumerateUserFiles = NULL;

    if (!pFnEnumerateUserFiles)
        pFnEnumerateUserFiles = (UFunction*)UObject::GObjObjects()->Data[39304];

    UMcpUserCloudFileDownload_execEnumerateUserFiles_Parms
        EnumerateUserFiles_Parms;

    this->ProcessEvent(pFnEnumerateUserFiles, &EnumerateUserFiles_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ClearFile
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearFile() {
    static UFunction* pFnClearFile = NULL;

    if (!pFnClearFile)
        pFnClearFile = (UFunction*)UObject::GObjObjects()->Data[39297];

    UMcpUserCloudFileDownload_execClearFile_Parms ClearFile_Parms;

    this->ProcessEvent(pFnClearFile, &ClearFile_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.ClearFiles
// [0x00020002]
// Parameters infos:

void UMcpUserCloudFileDownload::ClearFiles() {
    static UFunction* pFnClearFiles = NULL;

    if (!pFnClearFiles)
        pFnClearFiles = (UFunction*)UObject::GObjObjects()->Data[39291];

    UMcpUserCloudFileDownload_execClearFiles_Parms ClearFiles_Parms;

    this->ProcessEvent(pFnClearFiles, &ClearFiles_Parms, NULL);
};

// Function IpDrv.McpUserCloudFileDownload.GetFileContents
// [0x00420002]
// Parameters infos:

void UMcpUserCloudFileDownload::GetFileContents() {
    static UFunction* pFnGetFileContents = NULL;

    if (!pFnGetFileContents)
        pFnGetFileContents = (UFunction*)UObject::GObjObjects()->Data[39282];

    UMcpUserCloudFileDownload_execGetFileContents_Parms GetFileContents_Parms;

    this->ProcessEvent(pFnGetFileContents, &GetFileContents_Parms, NULL);
};

// Function IpDrv.MeshBeacon.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UMeshBeacon::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[40105];

    UMeshBeacon_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconClient.DebugRender
// [0x00020002]
// Parameters infos:

void UMeshBeaconClient::DebugRender() {
    static UFunction* pFnDebugRender = NULL;

    if (!pFnDebugRender)
        pFnDebugRender = (UFunction*)UObject::GObjObjects()->Data[40173];

    UMeshBeaconClient_execDebugRender_Parms DebugRender_Parms;

    this->ProcessEvent(pFnDebugRender, &DebugRender_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.DumpInfo
// [0x00020002]
// Parameters infos:

void UMeshBeaconClient::DumpInfo() {
    static UFunction* pFnDumpInfo = NULL;

    if (!pFnDumpInfo)
        pFnDumpInfo = (UFunction*)UObject::GObjObjects()->Data[40171];

    UMeshBeaconClient_execDumpInfo_Parms DumpInfo_Parms;

    this->ProcessEvent(pFnDumpInfo, &DumpInfo_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.SendHostNewGameSessionResponse
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconClient::SendHostNewGameSessionResponse() {
    static UFunction* pFnSendHostNewGameSessionResponse = NULL;

    if (!pFnSendHostNewGameSessionResponse)
        pFnSendHostNewGameSessionResponse =
            (UFunction*)UObject::GObjObjects()->Data[40165];

    UMeshBeaconClient_execSendHostNewGameSessionResponse_Parms
        SendHostNewGameSessionResponse_Parms;

    pFnSendHostNewGameSessionResponse->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendHostNewGameSessionResponse,
                       &SendHostNewGameSessionResponse_Parms, NULL);

    pFnSendHostNewGameSessionResponse->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconClient.OnCreateNewSessionRequestReceived
// [0x00520000]
// Parameters infos:

void UMeshBeaconClient::OnCreateNewSessionRequestReceived() {
    static UFunction* pFnOnCreateNewSessionRequestReceived = NULL;

    if (!pFnOnCreateNewSessionRequestReceived)
        pFnOnCreateNewSessionRequestReceived =
            (UFunction*)UObject::GObjObjects()->Data[40160];

    UMeshBeaconClient_execOnCreateNewSessionRequestReceived_Parms
        OnCreateNewSessionRequestReceived_Parms;

    this->ProcessEvent(pFnOnCreateNewSessionRequestReceived,
                       &OnCreateNewSessionRequestReceived_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.OnTravelRequestReceived
// [0x00520000]
// Parameters infos:

void UMeshBeaconClient::OnTravelRequestReceived() {
    static UFunction* pFnOnTravelRequestReceived = NULL;

    if (!pFnOnTravelRequestReceived)
        pFnOnTravelRequestReceived =
            (UFunction*)UObject::GObjObjects()->Data[40156];

    UMeshBeaconClient_execOnTravelRequestReceived_Parms
        OnTravelRequestReceived_Parms;

    this->ProcessEvent(pFnOnTravelRequestReceived,
                       &OnTravelRequestReceived_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestResults
// [0x00520000]
// Parameters infos:

void UMeshBeaconClient::OnReceivedBandwidthTestResults() {
    static UFunction* pFnOnReceivedBandwidthTestResults = NULL;

    if (!pFnOnReceivedBandwidthTestResults)
        pFnOnReceivedBandwidthTestResults =
            (UFunction*)UObject::GObjObjects()->Data[40152];

    UMeshBeaconClient_execOnReceivedBandwidthTestResults_Parms
        OnReceivedBandwidthTestResults_Parms;

    this->ProcessEvent(pFnOnReceivedBandwidthTestResults,
                       &OnReceivedBandwidthTestResults_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.OnReceivedBandwidthTestRequest
// [0x00120000]
// Parameters infos:

void UMeshBeaconClient::OnReceivedBandwidthTestRequest() {
    static UFunction* pFnOnReceivedBandwidthTestRequest = NULL;

    if (!pFnOnReceivedBandwidthTestRequest)
        pFnOnReceivedBandwidthTestRequest =
            (UFunction*)UObject::GObjObjects()->Data[40150];

    UMeshBeaconClient_execOnReceivedBandwidthTestRequest_Parms
        OnReceivedBandwidthTestRequest_Parms;

    this->ProcessEvent(pFnOnReceivedBandwidthTestRequest,
                       &OnReceivedBandwidthTestRequest_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.OnConnectionRequestResult
// [0x00120000]
// Parameters infos:

void UMeshBeaconClient::OnConnectionRequestResult() {
    static UFunction* pFnOnConnectionRequestResult = NULL;

    if (!pFnOnConnectionRequestResult)
        pFnOnConnectionRequestResult =
            (UFunction*)UObject::GObjObjects()->Data[40148];

    UMeshBeaconClient_execOnConnectionRequestResult_Parms
        OnConnectionRequestResult_Parms;

    this->ProcessEvent(pFnOnConnectionRequestResult,
                       &OnConnectionRequestResult_Parms, NULL);
};

// Function IpDrv.MeshBeaconClient.BeginBandwidthTest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconClient::BeginBandwidthTest() {
    static UFunction* pFnBeginBandwidthTest = NULL;

    if (!pFnBeginBandwidthTest)
        pFnBeginBandwidthTest = (UFunction*)UObject::GObjObjects()->Data[40144];

    UMeshBeaconClient_execBeginBandwidthTest_Parms BeginBandwidthTest_Parms;

    pFnBeginBandwidthTest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnBeginBandwidthTest, &BeginBandwidthTest_Parms, NULL);

    pFnBeginBandwidthTest->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconClient.RequestConnection
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconClient::RequestConnection() {
    static UFunction* pFnRequestConnection = NULL;

    if (!pFnRequestConnection)
        pFnRequestConnection = (UFunction*)UObject::GObjObjects()->Data[40139];

    UMeshBeaconClient_execRequestConnection_Parms RequestConnection_Parms;

    pFnRequestConnection->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnRequestConnection, &RequestConnection_Parms, NULL);

    pFnRequestConnection->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconClient.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UMeshBeaconClient::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[40138];

    UMeshBeaconClient_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.DebugRender
// [0x00820002]
// Parameters infos:

void UMeshBeaconHost::DebugRender() {
    static UFunction* pFnDebugRender = NULL;

    if (!pFnDebugRender)
        pFnDebugRender = (UFunction*)UObject::GObjObjects()->Data[40269];

    UMeshBeaconHost_execDebugRender_Parms DebugRender_Parms;

    this->ProcessEvent(pFnDebugRender, &DebugRender_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.DumpConnections
// [0x00820002]
// Parameters infos:

void UMeshBeaconHost::DumpConnections() {
    static UFunction* pFnDumpConnections = NULL;

    if (!pFnDumpConnections)
        pFnDumpConnections = (UFunction*)UObject::GObjObjects()->Data[40265];

    UMeshBeaconHost_execDumpConnections_Parms DumpConnections_Parms;

    this->ProcessEvent(pFnDumpConnections, &DumpConnections_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.OnReceivedClientCreateNewSessionResult
// [0x00520000]
// Parameters infos:

void UMeshBeaconHost::OnReceivedClientCreateNewSessionResult() {
    static UFunction* pFnOnReceivedClientCreateNewSessionResult = NULL;

    if (!pFnOnReceivedClientCreateNewSessionResult)
        pFnOnReceivedClientCreateNewSessionResult =
            (UFunction*)UObject::GObjObjects()->Data[40260];

    UMeshBeaconHost_execOnReceivedClientCreateNewSessionResult_Parms
        OnReceivedClientCreateNewSessionResult_Parms;

    this->ProcessEvent(pFnOnReceivedClientCreateNewSessionResult,
                       &OnReceivedClientCreateNewSessionResult_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.RequestClientCreateNewSession
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::RequestClientCreateNewSession() {
    static UFunction* pFnRequestClientCreateNewSession = NULL;

    if (!pFnRequestClientCreateNewSession)
        pFnRequestClientCreateNewSession =
            (UFunction*)UObject::GObjObjects()->Data[40253];

    UMeshBeaconHost_execRequestClientCreateNewSession_Parms
        RequestClientCreateNewSession_Parms;

    pFnRequestClientCreateNewSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnRequestClientCreateNewSession,
                       &RequestClientCreateNewSession_Parms, NULL);

    pFnRequestClientCreateNewSession->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.TellClientsToTravel
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::TellClientsToTravel() {
    static UFunction* pFnTellClientsToTravel = NULL;

    if (!pFnTellClientsToTravel)
        pFnTellClientsToTravel =
            (UFunction*)UObject::GObjObjects()->Data[40249];

    UMeshBeaconHost_execTellClientsToTravel_Parms TellClientsToTravel_Parms;

    pFnTellClientsToTravel->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnTellClientsToTravel, &TellClientsToTravel_Parms,
                       NULL);

    pFnTellClientsToTravel->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.OnAllPendingPlayersConnected
// [0x00120000]
// Parameters infos:

void UMeshBeaconHost::OnAllPendingPlayersConnected() {
    static UFunction* pFnOnAllPendingPlayersConnected = NULL;

    if (!pFnOnAllPendingPlayersConnected)
        pFnOnAllPendingPlayersConnected =
            (UFunction*)UObject::GObjObjects()->Data[40248];

    UMeshBeaconHost_execOnAllPendingPlayersConnected_Parms
        OnAllPendingPlayersConnected_Parms;

    this->ProcessEvent(pFnOnAllPendingPlayersConnected,
                       &OnAllPendingPlayersConnected_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.AllPlayersConnected
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::AllPlayersConnected() {
    static UFunction* pFnAllPlayersConnected = NULL;

    if (!pFnAllPlayersConnected)
        pFnAllPlayersConnected =
            (UFunction*)UObject::GObjObjects()->Data[40244];

    UMeshBeaconHost_execAllPlayersConnected_Parms AllPlayersConnected_Parms;

    pFnAllPlayersConnected->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAllPlayersConnected, &AllPlayersConnected_Parms,
                       NULL);

    pFnAllPlayersConnected->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.GetConnectionIndexForPlayer
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::GetConnectionIndexForPlayer() {
    static UFunction* pFnGetConnectionIndexForPlayer = NULL;

    if (!pFnGetConnectionIndexForPlayer)
        pFnGetConnectionIndexForPlayer =
            (UFunction*)UObject::GObjObjects()->Data[40241];

    UMeshBeaconHost_execGetConnectionIndexForPlayer_Parms
        GetConnectionIndexForPlayer_Parms;

    pFnGetConnectionIndexForPlayer->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetConnectionIndexForPlayer,
                       &GetConnectionIndexForPlayer_Parms, NULL);

    pFnGetConnectionIndexForPlayer->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.SetPendingPlayerConnections
// [0x00420002]
// Parameters infos:

void UMeshBeaconHost::SetPendingPlayerConnections() {
    static UFunction* pFnSetPendingPlayerConnections = NULL;

    if (!pFnSetPendingPlayerConnections)
        pFnSetPendingPlayerConnections =
            (UFunction*)UObject::GObjObjects()->Data[40238];

    UMeshBeaconHost_execSetPendingPlayerConnections_Parms
        SetPendingPlayerConnections_Parms;

    this->ProcessEvent(pFnSetPendingPlayerConnections,
                       &SetPendingPlayerConnections_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.OnFinishedBandwidthTest
// [0x00520000]
// Parameters infos:

void UMeshBeaconHost::OnFinishedBandwidthTest() {
    static UFunction* pFnOnFinishedBandwidthTest = NULL;

    if (!pFnOnFinishedBandwidthTest)
        pFnOnFinishedBandwidthTest =
            (UFunction*)UObject::GObjObjects()->Data[40233];

    UMeshBeaconHost_execOnFinishedBandwidthTest_Parms
        OnFinishedBandwidthTest_Parms;

    this->ProcessEvent(pFnOnFinishedBandwidthTest,
                       &OnFinishedBandwidthTest_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.OnStartedBandwidthTest
// [0x00120000]
// Parameters infos:

void UMeshBeaconHost::OnStartedBandwidthTest() {
    static UFunction* pFnOnStartedBandwidthTest = NULL;

    if (!pFnOnStartedBandwidthTest)
        pFnOnStartedBandwidthTest =
            (UFunction*)UObject::GObjObjects()->Data[40230];

    UMeshBeaconHost_execOnStartedBandwidthTest_Parms
        OnStartedBandwidthTest_Parms;

    this->ProcessEvent(pFnOnStartedBandwidthTest, &OnStartedBandwidthTest_Parms,
                       NULL);
};

// Function IpDrv.MeshBeaconHost.OnReceivedClientConnectionRequest
// [0x00520000]
// Parameters infos:

void UMeshBeaconHost::OnReceivedClientConnectionRequest() {
    static UFunction* pFnOnReceivedClientConnectionRequest = NULL;

    if (!pFnOnReceivedClientConnectionRequest)
        pFnOnReceivedClientConnectionRequest =
            (UFunction*)UObject::GObjObjects()->Data[40228];

    UMeshBeaconHost_execOnReceivedClientConnectionRequest_Parms
        OnReceivedClientConnectionRequest_Parms;

    this->ProcessEvent(pFnOnReceivedClientConnectionRequest,
                       &OnReceivedClientConnectionRequest_Parms, NULL);
};

// Function IpDrv.MeshBeaconHost.AllowBandwidthTesting
// [0x00020002]
// Parameters infos:

void UMeshBeaconHost::AllowBandwidthTesting() {
    static UFunction* pFnAllowBandwidthTesting = NULL;

    if (!pFnAllowBandwidthTesting)
        pFnAllowBandwidthTesting =
            (UFunction*)UObject::GObjObjects()->Data[40226];

    UMeshBeaconHost_execAllowBandwidthTesting_Parms AllowBandwidthTesting_Parms;

    this->ProcessEvent(pFnAllowBandwidthTesting, &AllowBandwidthTesting_Parms,
                       NULL);
};

// Function IpDrv.MeshBeaconHost.CancelPendingBandwidthTests
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::CancelPendingBandwidthTests() {
    static UFunction* pFnCancelPendingBandwidthTests = NULL;

    if (!pFnCancelPendingBandwidthTests)
        pFnCancelPendingBandwidthTests =
            (UFunction*)UObject::GObjObjects()->Data[40225];

    UMeshBeaconHost_execCancelPendingBandwidthTests_Parms
        CancelPendingBandwidthTests_Parms;

    pFnCancelPendingBandwidthTests->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnCancelPendingBandwidthTests,
                       &CancelPendingBandwidthTests_Parms, NULL);

    pFnCancelPendingBandwidthTests->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.HasPendingBandwidthTest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::HasPendingBandwidthTest() {
    static UFunction* pFnHasPendingBandwidthTest = NULL;

    if (!pFnHasPendingBandwidthTest)
        pFnHasPendingBandwidthTest =
            (UFunction*)UObject::GObjObjects()->Data[40223];

    UMeshBeaconHost_execHasPendingBandwidthTest_Parms
        HasPendingBandwidthTest_Parms;

    pFnHasPendingBandwidthTest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnHasPendingBandwidthTest,
                       &HasPendingBandwidthTest_Parms, NULL);

    pFnHasPendingBandwidthTest->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.CancelInProgressBandwidthTests
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::CancelInProgressBandwidthTests() {
    static UFunction* pFnCancelInProgressBandwidthTests = NULL;

    if (!pFnCancelInProgressBandwidthTests)
        pFnCancelInProgressBandwidthTests =
            (UFunction*)UObject::GObjObjects()->Data[40222];

    UMeshBeaconHost_execCancelInProgressBandwidthTests_Parms
        CancelInProgressBandwidthTests_Parms;

    pFnCancelInProgressBandwidthTests->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnCancelInProgressBandwidthTests,
                       &CancelInProgressBandwidthTests_Parms, NULL);

    pFnCancelInProgressBandwidthTests->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.HasInProgressBandwidthTest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::HasInProgressBandwidthTest() {
    static UFunction* pFnHasInProgressBandwidthTest = NULL;

    if (!pFnHasInProgressBandwidthTest)
        pFnHasInProgressBandwidthTest =
            (UFunction*)UObject::GObjObjects()->Data[40220];

    UMeshBeaconHost_execHasInProgressBandwidthTest_Parms
        HasInProgressBandwidthTest_Parms;

    pFnHasInProgressBandwidthTest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnHasInProgressBandwidthTest,
                       &HasInProgressBandwidthTest_Parms, NULL);

    pFnHasInProgressBandwidthTest->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.RequestClientBandwidthTest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::RequestClientBandwidthTest() {
    static UFunction* pFnRequestClientBandwidthTest = NULL;

    if (!pFnRequestClientBandwidthTest)
        pFnRequestClientBandwidthTest =
            (UFunction*)UObject::GObjObjects()->Data[40215];

    UMeshBeaconHost_execRequestClientBandwidthTest_Parms
        RequestClientBandwidthTest_Parms;

    pFnRequestClientBandwidthTest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnRequestClientBandwidthTest,
                       &RequestClientBandwidthTest_Parms, NULL);

    pFnRequestClientBandwidthTest->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[40214];

    UMeshBeaconHost_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.MeshBeaconHost.InitHostBeacon
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UMeshBeaconHost::InitHostBeacon() {
    static UFunction* pFnInitHostBeacon = NULL;

    if (!pFnInitHostBeacon)
        pFnInitHostBeacon = (UFunction*)UObject::GObjObjects()->Data[40211];

    UMeshBeaconHost_execInitHostBeacon_Parms InitHostBeacon_Parms;

    pFnInitHostBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnInitHostBeacon, &InitHostBeacon_Parms, NULL);

    pFnInitHostBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers
// [0x00420002]
// Parameters infos:

void UOnlineSubsystemCommonImpl::GetRegisteredPlayers() {
    static UFunction* pFnGetRegisteredPlayers = NULL;

    if (!pFnGetRegisteredPlayers)
        pFnGetRegisteredPlayers =
            (UFunction*)UObject::GObjObjects()->Data[41297];

    UOnlineSubsystemCommonImpl_execGetRegisteredPlayers_Parms
        GetRegisteredPlayers_Parms;

    this->ProcessEvent(pFnGetRegisteredPlayers, &GetRegisteredPlayers_Parms,
                       NULL);
};

// Function IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineSubsystemCommonImpl::IsPlayerInSession() {
    static UFunction* pFnIsPlayerInSession = NULL;

    if (!pFnIsPlayerInSession)
        pFnIsPlayerInSession = (UFunction*)UObject::GObjObjects()->Data[41293];

    UOnlineSubsystemCommonImpl_execIsPlayerInSession_Parms
        IsPlayerInSession_Parms;

    pFnIsPlayerInSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIsPlayerInSession, &IsPlayerInSession_Parms, NULL);

    pFnIsPlayerInSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex
// [0x00020800] ( FUNC_Event )
// Parameters infos:

void UOnlineSubsystemCommonImpl::eventGetPlayerNicknameFromIndex() {
    static UFunction* pFnGetPlayerNicknameFromIndex = NULL;

    if (!pFnGetPlayerNicknameFromIndex)
        pFnGetPlayerNicknameFromIndex =
            (UFunction*)UObject::GObjObjects()->Data[41290];

    UOnlineSubsystemCommonImpl_eventGetPlayerNicknameFromIndex_Parms
        GetPlayerNicknameFromIndex_Parms;

    this->ProcessEvent(pFnGetPlayerNicknameFromIndex,
                       &GetPlayerNicknameFromIndex_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.GetServerAddr
// [0x00420000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::GetServerAddr() {
    static UFunction* pFnGetServerAddr = NULL;

    if (!pFnGetServerAddr)
        pFnGetServerAddr = (UFunction*)UObject::GObjObjects()->Data[40501];

    UOnlineAuthInterfaceImpl_execGetServerAddr_Parms GetServerAddr_Parms;

    this->ProcessEvent(pFnGetServerAddr, &GetServerAddr_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.GetServerUniqueId
// [0x00420000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::GetServerUniqueId() {
    static UFunction* pFnGetServerUniqueId = NULL;

    if (!pFnGetServerUniqueId)
        pFnGetServerUniqueId = (UFunction*)UObject::GObjObjects()->Data[40498];

    UOnlineAuthInterfaceImpl_execGetServerUniqueId_Parms
        GetServerUniqueId_Parms;

    this->ProcessEvent(pFnGetServerUniqueId, &GetServerUniqueId_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.FindLocalServerAuthSession
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::FindLocalServerAuthSession() {
    static UFunction* pFnFindLocalServerAuthSession = NULL;

    if (!pFnFindLocalServerAuthSession)
        pFnFindLocalServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40494];

    UOnlineAuthInterfaceImpl_execFindLocalServerAuthSession_Parms
        FindLocalServerAuthSession_Parms;

    pFnFindLocalServerAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFindLocalServerAuthSession,
                       &FindLocalServerAuthSession_Parms, NULL);

    pFnFindLocalServerAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.FindServerAuthSession
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::FindServerAuthSession() {
    static UFunction* pFnFindServerAuthSession = NULL;

    if (!pFnFindServerAuthSession)
        pFnFindServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40490];

    UOnlineAuthInterfaceImpl_execFindServerAuthSession_Parms
        FindServerAuthSession_Parms;

    pFnFindServerAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFindServerAuthSession, &FindServerAuthSession_Parms,
                       NULL);

    pFnFindServerAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.FindLocalClientAuthSession
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::FindLocalClientAuthSession() {
    static UFunction* pFnFindLocalClientAuthSession = NULL;

    if (!pFnFindLocalClientAuthSession)
        pFnFindLocalClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40486];

    UOnlineAuthInterfaceImpl_execFindLocalClientAuthSession_Parms
        FindLocalClientAuthSession_Parms;

    pFnFindLocalClientAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFindLocalClientAuthSession,
                       &FindLocalClientAuthSession_Parms, NULL);

    pFnFindLocalClientAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.FindClientAuthSession
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::FindClientAuthSession() {
    static UFunction* pFnFindClientAuthSession = NULL;

    if (!pFnFindClientAuthSession)
        pFnFindClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40482];

    UOnlineAuthInterfaceImpl_execFindClientAuthSession_Parms
        FindClientAuthSession_Parms;

    pFnFindClientAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFindClientAuthSession, &FindClientAuthSession_Parms,
                       NULL);

    pFnFindClientAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.AllLocalServerAuthSessions
// [0x00420404] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::AllLocalServerAuthSessions() {
    static UFunction* pFnAllLocalServerAuthSessions = NULL;

    if (!pFnAllLocalServerAuthSessions)
        pFnAllLocalServerAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40480];

    UOnlineAuthInterfaceImpl_execAllLocalServerAuthSessions_Parms
        AllLocalServerAuthSessions_Parms;

    pFnAllLocalServerAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAllLocalServerAuthSessions,
                       &AllLocalServerAuthSessions_Parms, NULL);

    pFnAllLocalServerAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.AllServerAuthSessions
// [0x00420404] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::AllServerAuthSessions() {
    static UFunction* pFnAllServerAuthSessions = NULL;

    if (!pFnAllServerAuthSessions)
        pFnAllServerAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40478];

    UOnlineAuthInterfaceImpl_execAllServerAuthSessions_Parms
        AllServerAuthSessions_Parms;

    pFnAllServerAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAllServerAuthSessions, &AllServerAuthSessions_Parms,
                       NULL);

    pFnAllServerAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.AllLocalClientAuthSessions
// [0x00420404] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::AllLocalClientAuthSessions() {
    static UFunction* pFnAllLocalClientAuthSessions = NULL;

    if (!pFnAllLocalClientAuthSessions)
        pFnAllLocalClientAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40476];

    UOnlineAuthInterfaceImpl_execAllLocalClientAuthSessions_Parms
        AllLocalClientAuthSessions_Parms;

    pFnAllLocalClientAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAllLocalClientAuthSessions,
                       &AllLocalClientAuthSessions_Parms, NULL);

    pFnAllLocalClientAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.AllClientAuthSessions
// [0x00420404] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::AllClientAuthSessions() {
    static UFunction* pFnAllClientAuthSessions = NULL;

    if (!pFnAllClientAuthSessions)
        pFnAllClientAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40474];

    UOnlineAuthInterfaceImpl_execAllClientAuthSessions_Parms
        AllClientAuthSessions_Parms;

    pFnAllClientAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAllClientAuthSessions, &AllClientAuthSessions_Parms,
                       NULL);

    pFnAllClientAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndAllRemoteServerAuthSessions
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndAllRemoteServerAuthSessions() {
    static UFunction* pFnEndAllRemoteServerAuthSessions = NULL;

    if (!pFnEndAllRemoteServerAuthSessions)
        pFnEndAllRemoteServerAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40473];

    UOnlineAuthInterfaceImpl_execEndAllRemoteServerAuthSessions_Parms
        EndAllRemoteServerAuthSessions_Parms;

    pFnEndAllRemoteServerAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndAllRemoteServerAuthSessions,
                       &EndAllRemoteServerAuthSessions_Parms, NULL);

    pFnEndAllRemoteServerAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndAllLocalServerAuthSessions
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndAllLocalServerAuthSessions() {
    static UFunction* pFnEndAllLocalServerAuthSessions = NULL;

    if (!pFnEndAllLocalServerAuthSessions)
        pFnEndAllLocalServerAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40472];

    UOnlineAuthInterfaceImpl_execEndAllLocalServerAuthSessions_Parms
        EndAllLocalServerAuthSessions_Parms;

    pFnEndAllLocalServerAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndAllLocalServerAuthSessions,
                       &EndAllLocalServerAuthSessions_Parms, NULL);

    pFnEndAllLocalServerAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndRemoteServerAuthSession
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndRemoteServerAuthSession() {
    static UFunction* pFnEndRemoteServerAuthSession = NULL;

    if (!pFnEndRemoteServerAuthSession)
        pFnEndRemoteServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40469];

    UOnlineAuthInterfaceImpl_execEndRemoteServerAuthSession_Parms
        EndRemoteServerAuthSession_Parms;

    pFnEndRemoteServerAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndRemoteServerAuthSession,
                       &EndRemoteServerAuthSession_Parms, NULL);

    pFnEndRemoteServerAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndLocalServerAuthSession
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndLocalServerAuthSession() {
    static UFunction* pFnEndLocalServerAuthSession = NULL;

    if (!pFnEndLocalServerAuthSession)
        pFnEndLocalServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40466];

    UOnlineAuthInterfaceImpl_execEndLocalServerAuthSession_Parms
        EndLocalServerAuthSession_Parms;

    pFnEndLocalServerAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndLocalServerAuthSession,
                       &EndLocalServerAuthSession_Parms, NULL);

    pFnEndLocalServerAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.VerifyServerAuthSession
// [0x00020000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::VerifyServerAuthSession() {
    static UFunction* pFnVerifyServerAuthSession = NULL;

    if (!pFnVerifyServerAuthSession)
        pFnVerifyServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40461];

    UOnlineAuthInterfaceImpl_execVerifyServerAuthSession_Parms
        VerifyServerAuthSession_Parms;

    this->ProcessEvent(pFnVerifyServerAuthSession,
                       &VerifyServerAuthSession_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.CreateServerAuthSession
// [0x00420000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::CreateServerAuthSession() {
    static UFunction* pFnCreateServerAuthSession = NULL;

    if (!pFnCreateServerAuthSession)
        pFnCreateServerAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40455];

    UOnlineAuthInterfaceImpl_execCreateServerAuthSession_Parms
        CreateServerAuthSession_Parms;

    this->ProcessEvent(pFnCreateServerAuthSession,
                       &CreateServerAuthSession_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndAllRemoteClientAuthSessions
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndAllRemoteClientAuthSessions() {
    static UFunction* pFnEndAllRemoteClientAuthSessions = NULL;

    if (!pFnEndAllRemoteClientAuthSessions)
        pFnEndAllRemoteClientAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40454];

    UOnlineAuthInterfaceImpl_execEndAllRemoteClientAuthSessions_Parms
        EndAllRemoteClientAuthSessions_Parms;

    pFnEndAllRemoteClientAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndAllRemoteClientAuthSessions,
                       &EndAllRemoteClientAuthSessions_Parms, NULL);

    pFnEndAllRemoteClientAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndAllLocalClientAuthSessions
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndAllLocalClientAuthSessions() {
    static UFunction* pFnEndAllLocalClientAuthSessions = NULL;

    if (!pFnEndAllLocalClientAuthSessions)
        pFnEndAllLocalClientAuthSessions =
            (UFunction*)UObject::GObjObjects()->Data[40453];

    UOnlineAuthInterfaceImpl_execEndAllLocalClientAuthSessions_Parms
        EndAllLocalClientAuthSessions_Parms;

    pFnEndAllLocalClientAuthSessions->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndAllLocalClientAuthSessions,
                       &EndAllLocalClientAuthSessions_Parms, NULL);

    pFnEndAllLocalClientAuthSessions->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndRemoteClientAuthSession
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndRemoteClientAuthSession() {
    static UFunction* pFnEndRemoteClientAuthSession = NULL;

    if (!pFnEndRemoteClientAuthSession)
        pFnEndRemoteClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40450];

    UOnlineAuthInterfaceImpl_execEndRemoteClientAuthSession_Parms
        EndRemoteClientAuthSession_Parms;

    pFnEndRemoteClientAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndRemoteClientAuthSession,
                       &EndRemoteClientAuthSession_Parms, NULL);

    pFnEndRemoteClientAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.EndLocalClientAuthSession
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::EndLocalClientAuthSession() {
    static UFunction* pFnEndLocalClientAuthSession = NULL;

    if (!pFnEndLocalClientAuthSession)
        pFnEndLocalClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40446];

    UOnlineAuthInterfaceImpl_execEndLocalClientAuthSession_Parms
        EndLocalClientAuthSession_Parms;

    pFnEndLocalClientAuthSession->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndLocalClientAuthSession,
                       &EndLocalClientAuthSession_Parms, NULL);

    pFnEndLocalClientAuthSession->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.VerifyClientAuthSession
// [0x00020000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::VerifyClientAuthSession() {
    static UFunction* pFnVerifyClientAuthSession = NULL;

    if (!pFnVerifyClientAuthSession)
        pFnVerifyClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40440];

    UOnlineAuthInterfaceImpl_execVerifyClientAuthSession_Parms
        VerifyClientAuthSession_Parms;

    this->ProcessEvent(pFnVerifyClientAuthSession,
                       &VerifyClientAuthSession_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.CreateClientAuthSession
// [0x00420000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::CreateClientAuthSession() {
    static UFunction* pFnCreateClientAuthSession = NULL;

    if (!pFnCreateClientAuthSession)
        pFnCreateClientAuthSession =
            (UFunction*)UObject::GObjObjects()->Data[40433];

    UOnlineAuthInterfaceImpl_execCreateClientAuthSession_Parms
        CreateClientAuthSession_Parms;

    this->ProcessEvent(pFnCreateClientAuthSession,
                       &CreateClientAuthSession_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendServerAuthRetryRequest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendServerAuthRetryRequest() {
    static UFunction* pFnSendServerAuthRetryRequest = NULL;

    if (!pFnSendServerAuthRetryRequest)
        pFnSendServerAuthRetryRequest =
            (UFunction*)UObject::GObjObjects()->Data[40431];

    UOnlineAuthInterfaceImpl_execSendServerAuthRetryRequest_Parms
        SendServerAuthRetryRequest_Parms;

    pFnSendServerAuthRetryRequest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendServerAuthRetryRequest,
                       &SendServerAuthRetryRequest_Parms, NULL);

    pFnSendServerAuthRetryRequest->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendClientAuthEndSessionRequest
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendClientAuthEndSessionRequest() {
    static UFunction* pFnSendClientAuthEndSessionRequest = NULL;

    if (!pFnSendClientAuthEndSessionRequest)
        pFnSendClientAuthEndSessionRequest =
            (UFunction*)UObject::GObjObjects()->Data[40428];

    UOnlineAuthInterfaceImpl_execSendClientAuthEndSessionRequest_Parms
        SendClientAuthEndSessionRequest_Parms;

    pFnSendClientAuthEndSessionRequest->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendClientAuthEndSessionRequest,
                       &SendClientAuthEndSessionRequest_Parms, NULL);

    pFnSendClientAuthEndSessionRequest->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendServerAuthResponse
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendServerAuthResponse() {
    static UFunction* pFnSendServerAuthResponse = NULL;

    if (!pFnSendServerAuthResponse)
        pFnSendServerAuthResponse =
            (UFunction*)UObject::GObjObjects()->Data[40424];

    UOnlineAuthInterfaceImpl_execSendServerAuthResponse_Parms
        SendServerAuthResponse_Parms;

    pFnSendServerAuthResponse->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendServerAuthResponse, &SendServerAuthResponse_Parms,
                       NULL);

    pFnSendServerAuthResponse->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendClientAuthResponse
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendClientAuthResponse() {
    static UFunction* pFnSendClientAuthResponse = NULL;

    if (!pFnSendClientAuthResponse)
        pFnSendClientAuthResponse =
            (UFunction*)UObject::GObjObjects()->Data[40421];

    UOnlineAuthInterfaceImpl_execSendClientAuthResponse_Parms
        SendClientAuthResponse_Parms;

    pFnSendClientAuthResponse->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSendClientAuthResponse, &SendClientAuthResponse_Parms,
                       NULL);

    pFnSendClientAuthResponse->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendServerAuthRequest
// [0x00020000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendServerAuthRequest() {
    static UFunction* pFnSendServerAuthRequest = NULL;

    if (!pFnSendServerAuthRequest)
        pFnSendServerAuthRequest =
            (UFunction*)UObject::GObjObjects()->Data[40418];

    UOnlineAuthInterfaceImpl_execSendServerAuthRequest_Parms
        SendServerAuthRequest_Parms;

    this->ProcessEvent(pFnSendServerAuthRequest, &SendServerAuthRequest_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.SendClientAuthRequest
// [0x00020000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::SendClientAuthRequest() {
    static UFunction* pFnSendClientAuthRequest = NULL;

    if (!pFnSendClientAuthRequest)
        pFnSendClientAuthRequest =
            (UFunction*)UObject::GObjObjects()->Data[40414];

    UOnlineAuthInterfaceImpl_execSendClientAuthRequest_Parms
        SendClientAuthRequest_Parms;

    this->ProcessEvent(pFnSendClientAuthRequest, &SendClientAuthRequest_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearServerConnectionCloseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearServerConnectionCloseDelegate() {
    static UFunction* pFnClearServerConnectionCloseDelegate = NULL;

    if (!pFnClearServerConnectionCloseDelegate)
        pFnClearServerConnectionCloseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40411];

    UOnlineAuthInterfaceImpl_execClearServerConnectionCloseDelegate_Parms
        ClearServerConnectionCloseDelegate_Parms;

    this->ProcessEvent(pFnClearServerConnectionCloseDelegate,
                       &ClearServerConnectionCloseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddServerConnectionCloseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddServerConnectionCloseDelegate() {
    static UFunction* pFnAddServerConnectionCloseDelegate = NULL;

    if (!pFnAddServerConnectionCloseDelegate)
        pFnAddServerConnectionCloseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40409];

    UOnlineAuthInterfaceImpl_execAddServerConnectionCloseDelegate_Parms
        AddServerConnectionCloseDelegate_Parms;

    this->ProcessEvent(pFnAddServerConnectionCloseDelegate,
                       &AddServerConnectionCloseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnServerConnectionClose
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnServerConnectionClose() {
    static UFunction* pFnOnServerConnectionClose = NULL;

    if (!pFnOnServerConnectionClose)
        pFnOnServerConnectionClose =
            (UFunction*)UObject::GObjObjects()->Data[40407];

    UOnlineAuthInterfaceImpl_execOnServerConnectionClose_Parms
        OnServerConnectionClose_Parms;

    this->ProcessEvent(pFnOnServerConnectionClose,
                       &OnServerConnectionClose_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearClientConnectionCloseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearClientConnectionCloseDelegate() {
    static UFunction* pFnClearClientConnectionCloseDelegate = NULL;

    if (!pFnClearClientConnectionCloseDelegate)
        pFnClearClientConnectionCloseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40404];

    UOnlineAuthInterfaceImpl_execClearClientConnectionCloseDelegate_Parms
        ClearClientConnectionCloseDelegate_Parms;

    this->ProcessEvent(pFnClearClientConnectionCloseDelegate,
                       &ClearClientConnectionCloseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddClientConnectionCloseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddClientConnectionCloseDelegate() {
    static UFunction* pFnAddClientConnectionCloseDelegate = NULL;

    if (!pFnAddClientConnectionCloseDelegate)
        pFnAddClientConnectionCloseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40402];

    UOnlineAuthInterfaceImpl_execAddClientConnectionCloseDelegate_Parms
        AddClientConnectionCloseDelegate_Parms;

    this->ProcessEvent(pFnAddClientConnectionCloseDelegate,
                       &AddClientConnectionCloseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnClientConnectionClose
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnClientConnectionClose() {
    static UFunction* pFnOnClientConnectionClose = NULL;

    if (!pFnOnClientConnectionClose)
        pFnOnClientConnectionClose =
            (UFunction*)UObject::GObjObjects()->Data[40400];

    UOnlineAuthInterfaceImpl_execOnClientConnectionClose_Parms
        OnClientConnectionClose_Parms;

    this->ProcessEvent(pFnOnClientConnectionClose,
                       &OnClientConnectionClose_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearServerAuthRetryRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearServerAuthRetryRequestDelegate() {
    static UFunction* pFnClearServerAuthRetryRequestDelegate = NULL;

    if (!pFnClearServerAuthRetryRequestDelegate)
        pFnClearServerAuthRetryRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40397];

    UOnlineAuthInterfaceImpl_execClearServerAuthRetryRequestDelegate_Parms
        ClearServerAuthRetryRequestDelegate_Parms;

    this->ProcessEvent(pFnClearServerAuthRetryRequestDelegate,
                       &ClearServerAuthRetryRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddServerAuthRetryRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddServerAuthRetryRequestDelegate() {
    static UFunction* pFnAddServerAuthRetryRequestDelegate = NULL;

    if (!pFnAddServerAuthRetryRequestDelegate)
        pFnAddServerAuthRetryRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40395];

    UOnlineAuthInterfaceImpl_execAddServerAuthRetryRequestDelegate_Parms
        AddServerAuthRetryRequestDelegate_Parms;

    this->ProcessEvent(pFnAddServerAuthRetryRequestDelegate,
                       &AddServerAuthRetryRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnServerAuthRetryRequest
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnServerAuthRetryRequest() {
    static UFunction* pFnOnServerAuthRetryRequest = NULL;

    if (!pFnOnServerAuthRetryRequest)
        pFnOnServerAuthRetryRequest =
            (UFunction*)UObject::GObjObjects()->Data[40393];

    UOnlineAuthInterfaceImpl_execOnServerAuthRetryRequest_Parms
        OnServerAuthRetryRequest_Parms;

    this->ProcessEvent(pFnOnServerAuthRetryRequest,
                       &OnServerAuthRetryRequest_Parms, NULL);
};

// Function
// IpDrv.OnlineAuthInterfaceImpl.ClearClientAuthEndSessionRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearClientAuthEndSessionRequestDelegate() {
    static UFunction* pFnClearClientAuthEndSessionRequestDelegate = NULL;

    if (!pFnClearClientAuthEndSessionRequestDelegate)
        pFnClearClientAuthEndSessionRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40390];

    UOnlineAuthInterfaceImpl_execClearClientAuthEndSessionRequestDelegate_Parms
        ClearClientAuthEndSessionRequestDelegate_Parms;

    this->ProcessEvent(pFnClearClientAuthEndSessionRequestDelegate,
                       &ClearClientAuthEndSessionRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddClientAuthEndSessionRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddClientAuthEndSessionRequestDelegate() {
    static UFunction* pFnAddClientAuthEndSessionRequestDelegate = NULL;

    if (!pFnAddClientAuthEndSessionRequestDelegate)
        pFnAddClientAuthEndSessionRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40388];

    UOnlineAuthInterfaceImpl_execAddClientAuthEndSessionRequestDelegate_Parms
        AddClientAuthEndSessionRequestDelegate_Parms;

    this->ProcessEvent(pFnAddClientAuthEndSessionRequestDelegate,
                       &AddClientAuthEndSessionRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnClientAuthEndSessionRequest
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnClientAuthEndSessionRequest() {
    static UFunction* pFnOnClientAuthEndSessionRequest = NULL;

    if (!pFnOnClientAuthEndSessionRequest)
        pFnOnClientAuthEndSessionRequest =
            (UFunction*)UObject::GObjObjects()->Data[40386];

    UOnlineAuthInterfaceImpl_execOnClientAuthEndSessionRequest_Parms
        OnClientAuthEndSessionRequest_Parms;

    this->ProcessEvent(pFnOnClientAuthEndSessionRequest,
                       &OnClientAuthEndSessionRequest_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearServerAuthCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearServerAuthCompleteDelegate() {
    static UFunction* pFnClearServerAuthCompleteDelegate = NULL;

    if (!pFnClearServerAuthCompleteDelegate)
        pFnClearServerAuthCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40383];

    UOnlineAuthInterfaceImpl_execClearServerAuthCompleteDelegate_Parms
        ClearServerAuthCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearServerAuthCompleteDelegate,
                       &ClearServerAuthCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddServerAuthCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddServerAuthCompleteDelegate() {
    static UFunction* pFnAddServerAuthCompleteDelegate = NULL;

    if (!pFnAddServerAuthCompleteDelegate)
        pFnAddServerAuthCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40381];

    UOnlineAuthInterfaceImpl_execAddServerAuthCompleteDelegate_Parms
        AddServerAuthCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddServerAuthCompleteDelegate,
                       &AddServerAuthCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnServerAuthComplete
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnServerAuthComplete() {
    static UFunction* pFnOnServerAuthComplete = NULL;

    if (!pFnOnServerAuthComplete)
        pFnOnServerAuthComplete =
            (UFunction*)UObject::GObjObjects()->Data[40376];

    UOnlineAuthInterfaceImpl_execOnServerAuthComplete_Parms
        OnServerAuthComplete_Parms;

    this->ProcessEvent(pFnOnServerAuthComplete, &OnServerAuthComplete_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearClientAuthCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearClientAuthCompleteDelegate() {
    static UFunction* pFnClearClientAuthCompleteDelegate = NULL;

    if (!pFnClearClientAuthCompleteDelegate)
        pFnClearClientAuthCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40373];

    UOnlineAuthInterfaceImpl_execClearClientAuthCompleteDelegate_Parms
        ClearClientAuthCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearClientAuthCompleteDelegate,
                       &ClearClientAuthCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddClientAuthCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddClientAuthCompleteDelegate() {
    static UFunction* pFnAddClientAuthCompleteDelegate = NULL;

    if (!pFnAddClientAuthCompleteDelegate)
        pFnAddClientAuthCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40371];

    UOnlineAuthInterfaceImpl_execAddClientAuthCompleteDelegate_Parms
        AddClientAuthCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddClientAuthCompleteDelegate,
                       &AddClientAuthCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnClientAuthComplete
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnClientAuthComplete() {
    static UFunction* pFnOnClientAuthComplete = NULL;

    if (!pFnOnClientAuthComplete)
        pFnOnClientAuthComplete =
            (UFunction*)UObject::GObjObjects()->Data[40366];

    UOnlineAuthInterfaceImpl_execOnClientAuthComplete_Parms
        OnClientAuthComplete_Parms;

    this->ProcessEvent(pFnOnClientAuthComplete, &OnClientAuthComplete_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearServerAuthResponseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearServerAuthResponseDelegate() {
    static UFunction* pFnClearServerAuthResponseDelegate = NULL;

    if (!pFnClearServerAuthResponseDelegate)
        pFnClearServerAuthResponseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40363];

    UOnlineAuthInterfaceImpl_execClearServerAuthResponseDelegate_Parms
        ClearServerAuthResponseDelegate_Parms;

    this->ProcessEvent(pFnClearServerAuthResponseDelegate,
                       &ClearServerAuthResponseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddServerAuthResponseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddServerAuthResponseDelegate() {
    static UFunction* pFnAddServerAuthResponseDelegate = NULL;

    if (!pFnAddServerAuthResponseDelegate)
        pFnAddServerAuthResponseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40361];

    UOnlineAuthInterfaceImpl_execAddServerAuthResponseDelegate_Parms
        AddServerAuthResponseDelegate_Parms;

    this->ProcessEvent(pFnAddServerAuthResponseDelegate,
                       &AddServerAuthResponseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnServerAuthResponse
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnServerAuthResponse() {
    static UFunction* pFnOnServerAuthResponse = NULL;

    if (!pFnOnServerAuthResponse)
        pFnOnServerAuthResponse =
            (UFunction*)UObject::GObjObjects()->Data[40357];

    UOnlineAuthInterfaceImpl_execOnServerAuthResponse_Parms
        OnServerAuthResponse_Parms;

    this->ProcessEvent(pFnOnServerAuthResponse, &OnServerAuthResponse_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearClientAuthResponseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearClientAuthResponseDelegate() {
    static UFunction* pFnClearClientAuthResponseDelegate = NULL;

    if (!pFnClearClientAuthResponseDelegate)
        pFnClearClientAuthResponseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40354];

    UOnlineAuthInterfaceImpl_execClearClientAuthResponseDelegate_Parms
        ClearClientAuthResponseDelegate_Parms;

    this->ProcessEvent(pFnClearClientAuthResponseDelegate,
                       &ClearClientAuthResponseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddClientAuthResponseDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddClientAuthResponseDelegate() {
    static UFunction* pFnAddClientAuthResponseDelegate = NULL;

    if (!pFnAddClientAuthResponseDelegate)
        pFnAddClientAuthResponseDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40352];

    UOnlineAuthInterfaceImpl_execAddClientAuthResponseDelegate_Parms
        AddClientAuthResponseDelegate_Parms;

    this->ProcessEvent(pFnAddClientAuthResponseDelegate,
                       &AddClientAuthResponseDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnClientAuthResponse
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnClientAuthResponse() {
    static UFunction* pFnOnClientAuthResponse = NULL;

    if (!pFnOnClientAuthResponse)
        pFnOnClientAuthResponse =
            (UFunction*)UObject::GObjObjects()->Data[40348];

    UOnlineAuthInterfaceImpl_execOnClientAuthResponse_Parms
        OnClientAuthResponse_Parms;

    this->ProcessEvent(pFnOnClientAuthResponse, &OnClientAuthResponse_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearServerAuthRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearServerAuthRequestDelegate() {
    static UFunction* pFnClearServerAuthRequestDelegate = NULL;

    if (!pFnClearServerAuthRequestDelegate)
        pFnClearServerAuthRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40345];

    UOnlineAuthInterfaceImpl_execClearServerAuthRequestDelegate_Parms
        ClearServerAuthRequestDelegate_Parms;

    this->ProcessEvent(pFnClearServerAuthRequestDelegate,
                       &ClearServerAuthRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddServerAuthRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddServerAuthRequestDelegate() {
    static UFunction* pFnAddServerAuthRequestDelegate = NULL;

    if (!pFnAddServerAuthRequestDelegate)
        pFnAddServerAuthRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40343];

    UOnlineAuthInterfaceImpl_execAddServerAuthRequestDelegate_Parms
        AddServerAuthRequestDelegate_Parms;

    this->ProcessEvent(pFnAddServerAuthRequestDelegate,
                       &AddServerAuthRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnServerAuthRequest
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnServerAuthRequest() {
    static UFunction* pFnOnServerAuthRequest = NULL;

    if (!pFnOnServerAuthRequest)
        pFnOnServerAuthRequest =
            (UFunction*)UObject::GObjObjects()->Data[40338];

    UOnlineAuthInterfaceImpl_execOnServerAuthRequest_Parms
        OnServerAuthRequest_Parms;

    this->ProcessEvent(pFnOnServerAuthRequest, &OnServerAuthRequest_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearClientAuthRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearClientAuthRequestDelegate() {
    static UFunction* pFnClearClientAuthRequestDelegate = NULL;

    if (!pFnClearClientAuthRequestDelegate)
        pFnClearClientAuthRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40335];

    UOnlineAuthInterfaceImpl_execClearClientAuthRequestDelegate_Parms
        ClearClientAuthRequestDelegate_Parms;

    this->ProcessEvent(pFnClearClientAuthRequestDelegate,
                       &ClearClientAuthRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddClientAuthRequestDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddClientAuthRequestDelegate() {
    static UFunction* pFnAddClientAuthRequestDelegate = NULL;

    if (!pFnAddClientAuthRequestDelegate)
        pFnAddClientAuthRequestDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40333];

    UOnlineAuthInterfaceImpl_execAddClientAuthRequestDelegate_Parms
        AddClientAuthRequestDelegate_Parms;

    this->ProcessEvent(pFnAddClientAuthRequestDelegate,
                       &AddClientAuthRequestDelegate_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnClientAuthRequest
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnClientAuthRequest() {
    static UFunction* pFnOnClientAuthRequest = NULL;

    if (!pFnOnClientAuthRequest)
        pFnOnClientAuthRequest =
            (UFunction*)UObject::GObjObjects()->Data[40328];

    UOnlineAuthInterfaceImpl_execOnClientAuthRequest_Parms
        OnClientAuthRequest_Parms;

    this->ProcessEvent(pFnOnClientAuthRequest, &OnClientAuthRequest_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.ClearAuthReadyDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::ClearAuthReadyDelegate() {
    static UFunction* pFnClearAuthReadyDelegate = NULL;

    if (!pFnClearAuthReadyDelegate)
        pFnClearAuthReadyDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40325];

    UOnlineAuthInterfaceImpl_execClearAuthReadyDelegate_Parms
        ClearAuthReadyDelegate_Parms;

    this->ProcessEvent(pFnClearAuthReadyDelegate, &ClearAuthReadyDelegate_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.AddAuthReadyDelegate
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::AddAuthReadyDelegate() {
    static UFunction* pFnAddAuthReadyDelegate = NULL;

    if (!pFnAddAuthReadyDelegate)
        pFnAddAuthReadyDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40323];

    UOnlineAuthInterfaceImpl_execAddAuthReadyDelegate_Parms
        AddAuthReadyDelegate_Parms;

    this->ProcessEvent(pFnAddAuthReadyDelegate, &AddAuthReadyDelegate_Parms,
                       NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.OnAuthReady
// [0x00120000]
// Parameters infos:

void UOnlineAuthInterfaceImpl::OnAuthReady() {
    static UFunction* pFnOnAuthReady = NULL;

    if (!pFnOnAuthReady)
        pFnOnAuthReady = (UFunction*)UObject::GObjObjects()->Data[40322];

    UOnlineAuthInterfaceImpl_execOnAuthReady_Parms OnAuthReady_Parms;

    this->ProcessEvent(pFnOnAuthReady, &OnAuthReady_Parms, NULL);
};

// Function IpDrv.OnlineAuthInterfaceImpl.IsReady
// [0x00020002]
// Parameters infos:

void UOnlineAuthInterfaceImpl::IsReady() {
    static UFunction* pFnIsReady = NULL;

    if (!pFnIsReady)
        pFnIsReady = (UFunction*)UObject::GObjObjects()->Data[40320];

    UOnlineAuthInterfaceImpl_execIsReady_Parms IsReady_Parms;

    this->ProcessEvent(pFnIsReady, &IsReady_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearOnlineDelegates
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearOnlineDelegates() {
    static UFunction* pFnClearOnlineDelegates = NULL;

    if (!pFnClearOnlineDelegates)
        pFnClearOnlineDelegates =
            (UFunction*)UObject::GObjObjects()->Data[41037];

    UOnlineGameInterfaceImpl_execClearOnlineDelegates_Parms
        ClearOnlineDelegates_Parms;

    this->ProcessEvent(pFnClearOnlineDelegates, &ClearOnlineDelegates_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RemoveSearchResultFromFavorites
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RemoveSearchResultFromFavorites() {
    static UFunction* pFnRemoveSearchResultFromFavorites = NULL;

    if (!pFnRemoveSearchResultFromFavorites)
        pFnRemoveSearchResultFromFavorites =
            (UFunction*)UObject::GObjObjects()->Data[41034];

    UOnlineGameInterfaceImpl_execRemoveSearchResultFromFavorites_Parms
        RemoveSearchResultFromFavorites_Parms;

    this->ProcessEvent(pFnRemoveSearchResultFromFavorites,
                       &RemoveSearchResultFromFavorites_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearGetPlayerListCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearGetPlayerListCompleteDelegate() {
    static UFunction* pFnClearGetPlayerListCompleteDelegate = NULL;

    if (!pFnClearGetPlayerListCompleteDelegate)
        pFnClearGetPlayerListCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41032];

    UOnlineGameInterfaceImpl_execClearGetPlayerListCompleteDelegate_Parms
        ClearGetPlayerListCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearGetPlayerListCompleteDelegate,
                       &ClearGetPlayerListCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddGetPlayerListCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddGetPlayerListCompleteDelegate() {
    static UFunction* pFnAddGetPlayerListCompleteDelegate = NULL;

    if (!pFnAddGetPlayerListCompleteDelegate)
        pFnAddGetPlayerListCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41030];

    UOnlineGameInterfaceImpl_execAddGetPlayerListCompleteDelegate_Parms
        AddGetPlayerListCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddGetPlayerListCompleteDelegate,
                       &AddGetPlayerListCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnGetPlayerListComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnGetPlayerListComplete() {
    static UFunction* pFnOnGetPlayerListComplete = NULL;

    if (!pFnOnGetPlayerListComplete)
        pFnOnGetPlayerListComplete =
            (UFunction*)UObject::GObjObjects()->Data[41027];

    UOnlineGameInterfaceImpl_execOnGetPlayerListComplete_Parms
        OnGetPlayerListComplete_Parms;

    this->ProcessEvent(pFnOnGetPlayerListComplete,
                       &OnGetPlayerListComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.IsSearchResultInFavoritesList
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::IsSearchResultInFavoritesList() {
    static UFunction* pFnIsSearchResultInFavoritesList = NULL;

    if (!pFnIsSearchResultInFavoritesList)
        pFnIsSearchResultInFavoritesList =
            (UFunction*)UObject::GObjObjects()->Data[41024];

    UOnlineGameInterfaceImpl_execIsSearchResultInFavoritesList_Parms
        IsSearchResultInFavoritesList_Parms;

    this->ProcessEvent(pFnIsSearchResultInFavoritesList,
                       &IsSearchResultInFavoritesList_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddSearchResultToFavorites
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddSearchResultToFavorites() {
    static UFunction* pFnAddSearchResultToFavorites = NULL;

    if (!pFnAddSearchResultToFavorites)
        pFnAddSearchResultToFavorites =
            (UFunction*)UObject::GObjObjects()->Data[41021];

    UOnlineGameInterfaceImpl_execAddSearchResultToFavorites_Parms
        AddSearchResultToFavorites_Parms;

    this->ProcessEvent(pFnAddSearchResultToFavorites,
                       &AddSearchResultToFavorites_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SetMatchmakingTypeMode
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::SetMatchmakingTypeMode() {
    static UFunction* pFnSetMatchmakingTypeMode = NULL;

    if (!pFnSetMatchmakingTypeMode)
        pFnSetMatchmakingTypeMode =
            (UFunction*)UObject::GObjObjects()->Data[41019];

    UOnlineGameInterfaceImpl_execSetMatchmakingTypeMode_Parms
        SetMatchmakingTypeMode_Parms;

    this->ProcessEvent(pFnSetMatchmakingTypeMode, &SetMatchmakingTypeMode_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RunBandwidthTest
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RunBandwidthTest() {
    static UFunction* pFnRunBandwidthTest = NULL;

    if (!pFnRunBandwidthTest)
        pFnRunBandwidthTest = (UFunction*)UObject::GObjObjects()->Data[41018];

    UOnlineGameInterfaceImpl_execRunBandwidthTest_Parms RunBandwidthTest_Parms;

    this->ProcessEvent(pFnRunBandwidthTest, &RunBandwidthTest_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.IsAllowedToNetworkHost
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::IsAllowedToNetworkHost() {
    static UFunction* pFnIsAllowedToNetworkHost = NULL;

    if (!pFnIsAllowedToNetworkHost)
        pFnIsAllowedToNetworkHost =
            (UFunction*)UObject::GObjObjects()->Data[41016];

    UOnlineGameInterfaceImpl_execIsAllowedToNetworkHost_Parms
        IsAllowedToNetworkHost_Parms;

    this->ProcessEvent(pFnIsAllowedToNetworkHost, &IsAllowedToNetworkHost_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearGetRoomIdFromTitleServiceDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearGetRoomIdFromTitleServiceDelegate() {
    static UFunction* pFnClearGetRoomIdFromTitleServiceDelegate = NULL;

    if (!pFnClearGetRoomIdFromTitleServiceDelegate)
        pFnClearGetRoomIdFromTitleServiceDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41014];

    UOnlineGameInterfaceImpl_execClearGetRoomIdFromTitleServiceDelegate_Parms
        ClearGetRoomIdFromTitleServiceDelegate_Parms;

    this->ProcessEvent(pFnClearGetRoomIdFromTitleServiceDelegate,
                       &ClearGetRoomIdFromTitleServiceDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddGetRoomIdFromTitleServiceDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddGetRoomIdFromTitleServiceDelegate() {
    static UFunction* pFnAddGetRoomIdFromTitleServiceDelegate = NULL;

    if (!pFnAddGetRoomIdFromTitleServiceDelegate)
        pFnAddGetRoomIdFromTitleServiceDelegate =
            (UFunction*)UObject::GObjObjects()->Data[41012];

    UOnlineGameInterfaceImpl_execAddGetRoomIdFromTitleServiceDelegate_Parms
        AddGetRoomIdFromTitleServiceDelegate_Parms;

    this->ProcessEvent(pFnAddGetRoomIdFromTitleServiceDelegate,
                       &AddGetRoomIdFromTitleServiceDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetRoomIdFromSessionId
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetRoomIdFromSessionId() {
    static UFunction* pFnGetRoomIdFromSessionId = NULL;

    if (!pFnGetRoomIdFromSessionId)
        pFnGetRoomIdFromSessionId =
            (UFunction*)UObject::GObjObjects()->Data[41010];

    UOnlineGameInterfaceImpl_execGetRoomIdFromSessionId_Parms
        GetRoomIdFromSessionId_Parms;

    this->ProcessEvent(pFnGetRoomIdFromSessionId, &GetRoomIdFromSessionId_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetRoomIdFromTitleService
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetRoomIdFromTitleService() {
    static UFunction* pFnGetRoomIdFromTitleService = NULL;

    if (!pFnGetRoomIdFromTitleService)
        pFnGetRoomIdFromTitleService =
            (UFunction*)UObject::GObjObjects()->Data[41008];

    UOnlineGameInterfaceImpl_execGetRoomIdFromTitleService_Parms
        GetRoomIdFromTitleService_Parms;

    this->ProcessEvent(pFnGetRoomIdFromTitleService,
                       &GetRoomIdFromTitleService_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnGetRoomIdFromTitleService
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnGetRoomIdFromTitleService() {
    static UFunction* pFnOnGetRoomIdFromTitleService = NULL;

    if (!pFnOnGetRoomIdFromTitleService)
        pFnOnGetRoomIdFromTitleService =
            (UFunction*)UObject::GObjObjects()->Data[41006];

    UOnlineGameInterfaceImpl_execOnGetRoomIdFromTitleService_Parms
        OnGetRoomIdFromTitleService_Parms;

    this->ProcessEvent(pFnOnGetRoomIdFromTitleService,
                       &OnGetRoomIdFromTitleService_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetRoomId
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetRoomId() {
    static UFunction* pFnGetRoomId = NULL;

    if (!pFnGetRoomId)
        pFnGetRoomId = (UFunction*)UObject::GObjObjects()->Data[41004];

    UOnlineGameInterfaceImpl_execGetRoomId_Parms GetRoomId_Parms;

    this->ProcessEvent(pFnGetRoomId, &GetRoomId_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SendPlayerList
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::SendPlayerList() {
    static UFunction* pFnSendPlayerList = NULL;

    if (!pFnSendPlayerList)
        pFnSendPlayerList = (UFunction*)UObject::GObjObjects()->Data[41000];

    UOnlineGameInterfaceImpl_execSendPlayerList_Parms SendPlayerList_Parms;

    this->ProcessEvent(pFnSendPlayerList, &SendPlayerList_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearGetNumberOfCurrentPlayersCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::
    ClearGetNumberOfCurrentPlayersCompleteDelegate() {
    static UFunction* pFnClearGetNumberOfCurrentPlayersCompleteDelegate = NULL;

    if (!pFnClearGetNumberOfCurrentPlayersCompleteDelegate)
        pFnClearGetNumberOfCurrentPlayersCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40998];

    UOnlineGameInterfaceImpl_execClearGetNumberOfCurrentPlayersCompleteDelegate_Parms
        ClearGetNumberOfCurrentPlayersCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearGetNumberOfCurrentPlayersCompleteDelegate,
                       &ClearGetNumberOfCurrentPlayersCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddGetNumberOfCurrentPlayersCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddGetNumberOfCurrentPlayersCompleteDelegate() {
    static UFunction* pFnAddGetNumberOfCurrentPlayersCompleteDelegate = NULL;

    if (!pFnAddGetNumberOfCurrentPlayersCompleteDelegate)
        pFnAddGetNumberOfCurrentPlayersCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40996];

    UOnlineGameInterfaceImpl_execAddGetNumberOfCurrentPlayersCompleteDelegate_Parms
        AddGetNumberOfCurrentPlayersCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddGetNumberOfCurrentPlayersCompleteDelegate,
                       &AddGetNumberOfCurrentPlayersCompleteDelegate_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnGetNumberOfCurrentPlayersComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnGetNumberOfCurrentPlayersComplete() {
    static UFunction* pFnOnGetNumberOfCurrentPlayersComplete = NULL;

    if (!pFnOnGetNumberOfCurrentPlayersComplete)
        pFnOnGetNumberOfCurrentPlayersComplete =
            (UFunction*)UObject::GObjObjects()->Data[40994];

    UOnlineGameInterfaceImpl_execOnGetNumberOfCurrentPlayersComplete_Parms
        OnGetNumberOfCurrentPlayersComplete_Parms;

    this->ProcessEvent(pFnOnGetNumberOfCurrentPlayersComplete,
                       &OnGetNumberOfCurrentPlayersComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetNumberOfCurrentPlayersCached
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetNumberOfCurrentPlayersCached() {
    static UFunction* pFnGetNumberOfCurrentPlayersCached = NULL;

    if (!pFnGetNumberOfCurrentPlayersCached)
        pFnGetNumberOfCurrentPlayersCached =
            (UFunction*)UObject::GObjObjects()->Data[40992];

    UOnlineGameInterfaceImpl_execGetNumberOfCurrentPlayersCached_Parms
        GetNumberOfCurrentPlayersCached_Parms;

    this->ProcessEvent(pFnGetNumberOfCurrentPlayersCached,
                       &GetNumberOfCurrentPlayersCached_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetNumberOfCurrentPlayers
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetNumberOfCurrentPlayers() {
    static UFunction* pFnGetNumberOfCurrentPlayers = NULL;

    if (!pFnGetNumberOfCurrentPlayers)
        pFnGetNumberOfCurrentPlayers =
            (UFunction*)UObject::GObjObjects()->Data[40990];

    UOnlineGameInterfaceImpl_execGetNumberOfCurrentPlayers_Parms
        GetNumberOfCurrentPlayers_Parms;

    this->ProcessEvent(pFnGetNumberOfCurrentPlayers,
                       &GetNumberOfCurrentPlayers_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearQosStatusChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearQosStatusChangedDelegate() {
    static UFunction* pFnClearQosStatusChangedDelegate = NULL;

    if (!pFnClearQosStatusChangedDelegate)
        pFnClearQosStatusChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40988];

    UOnlineGameInterfaceImpl_execClearQosStatusChangedDelegate_Parms
        ClearQosStatusChangedDelegate_Parms;

    this->ProcessEvent(pFnClearQosStatusChangedDelegate,
                       &ClearQosStatusChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddQosStatusChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddQosStatusChangedDelegate() {
    static UFunction* pFnAddQosStatusChangedDelegate = NULL;

    if (!pFnAddQosStatusChangedDelegate)
        pFnAddQosStatusChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40986];

    UOnlineGameInterfaceImpl_execAddQosStatusChangedDelegate_Parms
        AddQosStatusChangedDelegate_Parms;

    this->ProcessEvent(pFnAddQosStatusChangedDelegate,
                       &AddQosStatusChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnQosStatusChanged
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnQosStatusChanged() {
    static UFunction* pFnOnQosStatusChanged = NULL;

    if (!pFnOnQosStatusChanged)
        pFnOnQosStatusChanged = (UFunction*)UObject::GObjObjects()->Data[40983];

    UOnlineGameInterfaceImpl_execOnQosStatusChanged_Parms
        OnQosStatusChanged_Parms;

    this->ProcessEvent(pFnOnQosStatusChanged, &OnQosStatusChanged_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.BindSessionGuidToSearch
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::BindSessionGuidToSearch() {
    static UFunction* pFnBindSessionGuidToSearch = NULL;

    if (!pFnBindSessionGuidToSearch)
        pFnBindSessionGuidToSearch =
            (UFunction*)UObject::GObjObjects()->Data[40978];

    UOnlineGameInterfaceImpl_execBindSessionGuidToSearch_Parms
        BindSessionGuidToSearch_Parms;

    this->ProcessEvent(pFnBindSessionGuidToSearch,
                       &BindSessionGuidToSearch_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.BindPlatformSpecificSessionToSearch
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::BindPlatformSpecificSessionToSearch() {
    static UFunction* pFnBindPlatformSpecificSessionToSearch = NULL;

    if (!pFnBindPlatformSpecificSessionToSearch)
        pFnBindPlatformSpecificSessionToSearch =
            (UFunction*)UObject::GObjObjects()->Data[40973];

    UOnlineGameInterfaceImpl_execBindPlatformSpecificSessionToSearch_Parms
        BindPlatformSpecificSessionToSearch_Parms;

    pFnBindPlatformSpecificSessionToSearch->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnBindPlatformSpecificSessionToSearch,
                       &BindPlatformSpecificSessionToSearch_Parms, NULL);

    pFnBindPlatformSpecificSessionToSearch->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ReadSessionGuidBySessionName
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ReadSessionGuidBySessionName() {
    static UFunction* pFnReadSessionGuidBySessionName = NULL;

    if (!pFnReadSessionGuidBySessionName)
        pFnReadSessionGuidBySessionName =
            (UFunction*)UObject::GObjObjects()->Data[40969];

    UOnlineGameInterfaceImpl_execReadSessionGuidBySessionName_Parms
        ReadSessionGuidBySessionName_Parms;

    this->ProcessEvent(pFnReadSessionGuidBySessionName,
                       &ReadSessionGuidBySessionName_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfoBySessionName
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::ReadPlatformSpecificSessionInfoBySessionName() {
    static UFunction* pFnReadPlatformSpecificSessionInfoBySessionName = NULL;

    if (!pFnReadPlatformSpecificSessionInfoBySessionName)
        pFnReadPlatformSpecificSessionInfoBySessionName =
            (UFunction*)UObject::GObjObjects()->Data[40965];

    UOnlineGameInterfaceImpl_execReadPlatformSpecificSessionInfoBySessionName_Parms
        ReadPlatformSpecificSessionInfoBySessionName_Parms;

    pFnReadPlatformSpecificSessionInfoBySessionName->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadPlatformSpecificSessionInfoBySessionName,
                       &ReadPlatformSpecificSessionInfoBySessionName_Parms,
                       NULL);

    pFnReadPlatformSpecificSessionInfoBySessionName->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ReadPlatformSpecificSessionInfo
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::ReadPlatformSpecificSessionInfo() {
    static UFunction* pFnReadPlatformSpecificSessionInfo = NULL;

    if (!pFnReadPlatformSpecificSessionInfo)
        pFnReadPlatformSpecificSessionInfo =
            (UFunction*)UObject::GObjObjects()->Data[40961];

    UOnlineGameInterfaceImpl_execReadPlatformSpecificSessionInfo_Parms
        ReadPlatformSpecificSessionInfo_Parms;

    pFnReadPlatformSpecificSessionInfo->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnReadPlatformSpecificSessionInfo,
                       &ReadPlatformSpecificSessionInfo_Parms, NULL);

    pFnReadPlatformSpecificSessionInfo->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.QueryNonAdvertisedData
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::QueryNonAdvertisedData() {
    static UFunction* pFnQueryNonAdvertisedData = NULL;

    if (!pFnQueryNonAdvertisedData)
        pFnQueryNonAdvertisedData =
            (UFunction*)UObject::GObjObjects()->Data[40957];

    UOnlineGameInterfaceImpl_execQueryNonAdvertisedData_Parms
        QueryNonAdvertisedData_Parms;

    this->ProcessEvent(pFnQueryNonAdvertisedData, &QueryNonAdvertisedData_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearJoinMigratedOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearJoinMigratedOnlineGameCompleteDelegate() {
    static UFunction* pFnClearJoinMigratedOnlineGameCompleteDelegate = NULL;

    if (!pFnClearJoinMigratedOnlineGameCompleteDelegate)
        pFnClearJoinMigratedOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40954];

    UOnlineGameInterfaceImpl_execClearJoinMigratedOnlineGameCompleteDelegate_Parms
        ClearJoinMigratedOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearJoinMigratedOnlineGameCompleteDelegate,
                       &ClearJoinMigratedOnlineGameCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddJoinMigratedOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddJoinMigratedOnlineGameCompleteDelegate() {
    static UFunction* pFnAddJoinMigratedOnlineGameCompleteDelegate = NULL;

    if (!pFnAddJoinMigratedOnlineGameCompleteDelegate)
        pFnAddJoinMigratedOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40952];

    UOnlineGameInterfaceImpl_execAddJoinMigratedOnlineGameCompleteDelegate_Parms
        AddJoinMigratedOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddJoinMigratedOnlineGameCompleteDelegate,
                       &AddJoinMigratedOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnJoinMigratedOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnJoinMigratedOnlineGameComplete() {
    static UFunction* pFnOnJoinMigratedOnlineGameComplete = NULL;

    if (!pFnOnJoinMigratedOnlineGameComplete)
        pFnOnJoinMigratedOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40949];

    UOnlineGameInterfaceImpl_execOnJoinMigratedOnlineGameComplete_Parms
        OnJoinMigratedOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnJoinMigratedOnlineGameComplete,
                       &OnJoinMigratedOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.JoinMigratedOnlineGame
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::JoinMigratedOnlineGame() {
    static UFunction* pFnJoinMigratedOnlineGame = NULL;

    if (!pFnJoinMigratedOnlineGame)
        pFnJoinMigratedOnlineGame =
            (UFunction*)UObject::GObjObjects()->Data[40944];

    UOnlineGameInterfaceImpl_execJoinMigratedOnlineGame_Parms
        JoinMigratedOnlineGame_Parms;

    this->ProcessEvent(pFnJoinMigratedOnlineGame, &JoinMigratedOnlineGame_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearMigrateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearMigrateOnlineGameCompleteDelegate() {
    static UFunction* pFnClearMigrateOnlineGameCompleteDelegate = NULL;

    if (!pFnClearMigrateOnlineGameCompleteDelegate)
        pFnClearMigrateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40941];

    UOnlineGameInterfaceImpl_execClearMigrateOnlineGameCompleteDelegate_Parms
        ClearMigrateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearMigrateOnlineGameCompleteDelegate,
                       &ClearMigrateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddMigrateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddMigrateOnlineGameCompleteDelegate() {
    static UFunction* pFnAddMigrateOnlineGameCompleteDelegate = NULL;

    if (!pFnAddMigrateOnlineGameCompleteDelegate)
        pFnAddMigrateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40939];

    UOnlineGameInterfaceImpl_execAddMigrateOnlineGameCompleteDelegate_Parms
        AddMigrateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddMigrateOnlineGameCompleteDelegate,
                       &AddMigrateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnMigrateOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnMigrateOnlineGameComplete() {
    static UFunction* pFnOnMigrateOnlineGameComplete = NULL;

    if (!pFnOnMigrateOnlineGameComplete)
        pFnOnMigrateOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40936];

    UOnlineGameInterfaceImpl_execOnMigrateOnlineGameComplete_Parms
        OnMigrateOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnMigrateOnlineGameComplete,
                       &OnMigrateOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.MigrateOnlineGame
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::MigrateOnlineGame() {
    static UFunction* pFnMigrateOnlineGame = NULL;

    if (!pFnMigrateOnlineGame)
        pFnMigrateOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40932];

    UOnlineGameInterfaceImpl_execMigrateOnlineGame_Parms
        MigrateOnlineGame_Parms;

    this->ProcessEvent(pFnMigrateOnlineGame, &MigrateOnlineGame_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearRecalculateSkillRatingCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearRecalculateSkillRatingCompleteDelegate() {
    static UFunction* pFnClearRecalculateSkillRatingCompleteDelegate = NULL;

    if (!pFnClearRecalculateSkillRatingCompleteDelegate)
        pFnClearRecalculateSkillRatingCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40930];

    UOnlineGameInterfaceImpl_execClearRecalculateSkillRatingCompleteDelegate_Parms
        ClearRecalculateSkillRatingCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearRecalculateSkillRatingCompleteDelegate,
                       &ClearRecalculateSkillRatingCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddRecalculateSkillRatingCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddRecalculateSkillRatingCompleteDelegate() {
    static UFunction* pFnAddRecalculateSkillRatingCompleteDelegate = NULL;

    if (!pFnAddRecalculateSkillRatingCompleteDelegate)
        pFnAddRecalculateSkillRatingCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40928];

    UOnlineGameInterfaceImpl_execAddRecalculateSkillRatingCompleteDelegate_Parms
        AddRecalculateSkillRatingCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddRecalculateSkillRatingCompleteDelegate,
                       &AddRecalculateSkillRatingCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnRecalculateSkillRatingComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnRecalculateSkillRatingComplete() {
    static UFunction* pFnOnRecalculateSkillRatingComplete = NULL;

    if (!pFnOnRecalculateSkillRatingComplete)
        pFnOnRecalculateSkillRatingComplete =
            (UFunction*)UObject::GObjObjects()->Data[40925];

    UOnlineGameInterfaceImpl_execOnRecalculateSkillRatingComplete_Parms
        OnRecalculateSkillRatingComplete_Parms;

    this->ProcessEvent(pFnOnRecalculateSkillRatingComplete,
                       &OnRecalculateSkillRatingComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RecalculateSkillRating
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RecalculateSkillRating() {
    static UFunction* pFnRecalculateSkillRating = NULL;

    if (!pFnRecalculateSkillRating)
        pFnRecalculateSkillRating =
            (UFunction*)UObject::GObjObjects()->Data[40920];

    UOnlineGameInterfaceImpl_execRecalculateSkillRating_Parms
        RecalculateSkillRating_Parms;

    this->ProcessEvent(pFnRecalculateSkillRating, &RecalculateSkillRating_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SetPendingMembersToInvite
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::SetPendingMembersToInvite() {
    static UFunction* pFnSetPendingMembersToInvite = NULL;

    if (!pFnSetPendingMembersToInvite)
        pFnSetPendingMembersToInvite =
            (UFunction*)UObject::GObjObjects()->Data[40917];

    UOnlineGameInterfaceImpl_execSetPendingMembersToInvite_Parms
        SetPendingMembersToInvite_Parms;

    this->ProcessEvent(pFnSetPendingMembersToInvite,
                       &SetPendingMembersToInvite_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ResetPendingMembersToInvite
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ResetPendingMembersToInvite() {
    static UFunction* pFnResetPendingMembersToInvite = NULL;

    if (!pFnResetPendingMembersToInvite)
        pFnResetPendingMembersToInvite =
            (UFunction*)UObject::GObjObjects()->Data[40916];

    UOnlineGameInterfaceImpl_execResetPendingMembersToInvite_Parms
        ResetPendingMembersToInvite_Parms;

    this->ProcessEvent(pFnResetPendingMembersToInvite,
                       &ResetPendingMembersToInvite_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetPendingMembersToInvite
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetPendingMembersToInvite() {
    static UFunction* pFnGetPendingMembersToInvite = NULL;

    if (!pFnGetPendingMembersToInvite)
        pFnGetPendingMembersToInvite =
            (UFunction*)UObject::GObjObjects()->Data[40913];

    UOnlineGameInterfaceImpl_execGetPendingMembersToInvite_Parms
        GetPendingMembersToInvite_Parms;

    this->ProcessEvent(pFnGetPendingMembersToInvite,
                       &GetPendingMembersToInvite_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearPlayTogetherStartedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearPlayTogetherStartedDelegate() {
    static UFunction* pFnClearPlayTogetherStartedDelegate = NULL;

    if (!pFnClearPlayTogetherStartedDelegate)
        pFnClearPlayTogetherStartedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40910];

    UOnlineGameInterfaceImpl_execClearPlayTogetherStartedDelegate_Parms
        ClearPlayTogetherStartedDelegate_Parms;

    this->ProcessEvent(pFnClearPlayTogetherStartedDelegate,
                       &ClearPlayTogetherStartedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddPlayTogetherStartedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddPlayTogetherStartedDelegate() {
    static UFunction* pFnAddPlayTogetherStartedDelegate = NULL;

    if (!pFnAddPlayTogetherStartedDelegate)
        pFnAddPlayTogetherStartedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40907];

    UOnlineGameInterfaceImpl_execAddPlayTogetherStartedDelegate_Parms
        AddPlayTogetherStartedDelegate_Parms;

    this->ProcessEvent(pFnAddPlayTogetherStartedDelegate,
                       &AddPlayTogetherStartedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnPlayTogetherStarted
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnPlayTogetherStarted() {
    static UFunction* pFnOnPlayTogetherStarted = NULL;

    if (!pFnOnPlayTogetherStarted)
        pFnOnPlayTogetherStarted =
            (UFunction*)UObject::GObjObjects()->Data[40906];

    UOnlineGameInterfaceImpl_execOnPlayTogetherStarted_Parms
        OnPlayTogetherStarted_Parms;

    this->ProcessEvent(pFnOnPlayTogetherStarted, &OnPlayTogetherStarted_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AcceptGameInvite
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AcceptGameInvite() {
    static UFunction* pFnAcceptGameInvite = NULL;

    if (!pFnAcceptGameInvite)
        pFnAcceptGameInvite = (UFunction*)UObject::GObjObjects()->Data[40901];

    UOnlineGameInterfaceImpl_execAcceptGameInvite_Parms AcceptGameInvite_Parms;

    this->ProcessEvent(pFnAcceptGameInvite, &AcceptGameInvite_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearGameInviteAcceptedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearGameInviteAcceptedDelegate() {
    static UFunction* pFnClearGameInviteAcceptedDelegate = NULL;

    if (!pFnClearGameInviteAcceptedDelegate)
        pFnClearGameInviteAcceptedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40898];

    UOnlineGameInterfaceImpl_execClearGameInviteAcceptedDelegate_Parms
        ClearGameInviteAcceptedDelegate_Parms;

    this->ProcessEvent(pFnClearGameInviteAcceptedDelegate,
                       &ClearGameInviteAcceptedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddGameInviteAcceptedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddGameInviteAcceptedDelegate() {
    static UFunction* pFnAddGameInviteAcceptedDelegate = NULL;

    if (!pFnAddGameInviteAcceptedDelegate)
        pFnAddGameInviteAcceptedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40895];

    UOnlineGameInterfaceImpl_execAddGameInviteAcceptedDelegate_Parms
        AddGameInviteAcceptedDelegate_Parms;

    this->ProcessEvent(pFnAddGameInviteAcceptedDelegate,
                       &AddGameInviteAcceptedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnGameInviteAccepted
// [0x00520000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnGameInviteAccepted() {
    static UFunction* pFnOnGameInviteAccepted = NULL;

    if (!pFnOnGameInviteAccepted)
        pFnOnGameInviteAccepted =
            (UFunction*)UObject::GObjObjects()->Data[40892];

    UOnlineGameInterfaceImpl_execOnGameInviteAccepted_Parms
        OnGameInviteAccepted_Parms;

    this->ProcessEvent(pFnOnGameInviteAccepted, &OnGameInviteAccepted_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetArbitratedPlayers
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetArbitratedPlayers() {
    static UFunction* pFnGetArbitratedPlayers = NULL;

    if (!pFnGetArbitratedPlayers)
        pFnGetArbitratedPlayers =
            (UFunction*)UObject::GObjObjects()->Data[40888];

    UOnlineGameInterfaceImpl_execGetArbitratedPlayers_Parms
        GetArbitratedPlayers_Parms;

    this->ProcessEvent(pFnGetArbitratedPlayers, &GetArbitratedPlayers_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearArbitrationRegistrationCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearArbitrationRegistrationCompleteDelegate() {
    static UFunction* pFnClearArbitrationRegistrationCompleteDelegate = NULL;

    if (!pFnClearArbitrationRegistrationCompleteDelegate)
        pFnClearArbitrationRegistrationCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40886];

    UOnlineGameInterfaceImpl_execClearArbitrationRegistrationCompleteDelegate_Parms
        ClearArbitrationRegistrationCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearArbitrationRegistrationCompleteDelegate,
                       &ClearArbitrationRegistrationCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddArbitrationRegistrationCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddArbitrationRegistrationCompleteDelegate() {
    static UFunction* pFnAddArbitrationRegistrationCompleteDelegate = NULL;

    if (!pFnAddArbitrationRegistrationCompleteDelegate)
        pFnAddArbitrationRegistrationCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40884];

    UOnlineGameInterfaceImpl_execAddArbitrationRegistrationCompleteDelegate_Parms
        AddArbitrationRegistrationCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddArbitrationRegistrationCompleteDelegate,
                       &AddArbitrationRegistrationCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnArbitrationRegistrationComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnArbitrationRegistrationComplete() {
    static UFunction* pFnOnArbitrationRegistrationComplete = NULL;

    if (!pFnOnArbitrationRegistrationComplete)
        pFnOnArbitrationRegistrationComplete =
            (UFunction*)UObject::GObjObjects()->Data[40881];

    UOnlineGameInterfaceImpl_execOnArbitrationRegistrationComplete_Parms
        OnArbitrationRegistrationComplete_Parms;

    this->ProcessEvent(pFnOnArbitrationRegistrationComplete,
                       &OnArbitrationRegistrationComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RegisterForArbitration
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RegisterForArbitration() {
    static UFunction* pFnRegisterForArbitration = NULL;

    if (!pFnRegisterForArbitration)
        pFnRegisterForArbitration =
            (UFunction*)UObject::GObjObjects()->Data[40878];

    UOnlineGameInterfaceImpl_execRegisterForArbitration_Parms
        RegisterForArbitration_Parms;

    this->ProcessEvent(pFnRegisterForArbitration, &RegisterForArbitration_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearEndOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearEndOnlineGameCompleteDelegate() {
    static UFunction* pFnClearEndOnlineGameCompleteDelegate = NULL;

    if (!pFnClearEndOnlineGameCompleteDelegate)
        pFnClearEndOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40875];

    UOnlineGameInterfaceImpl_execClearEndOnlineGameCompleteDelegate_Parms
        ClearEndOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearEndOnlineGameCompleteDelegate,
                       &ClearEndOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddEndOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddEndOnlineGameCompleteDelegate() {
    static UFunction* pFnAddEndOnlineGameCompleteDelegate = NULL;

    if (!pFnAddEndOnlineGameCompleteDelegate)
        pFnAddEndOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40873];

    UOnlineGameInterfaceImpl_execAddEndOnlineGameCompleteDelegate_Parms
        AddEndOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddEndOnlineGameCompleteDelegate,
                       &AddEndOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnEndOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnEndOnlineGameComplete() {
    static UFunction* pFnOnEndOnlineGameComplete = NULL;

    if (!pFnOnEndOnlineGameComplete)
        pFnOnEndOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40870];

    UOnlineGameInterfaceImpl_execOnEndOnlineGameComplete_Parms
        OnEndOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnEndOnlineGameComplete,
                       &OnEndOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.EndOnlineGame
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::EndOnlineGame() {
    static UFunction* pFnEndOnlineGame = NULL;

    if (!pFnEndOnlineGame)
        pFnEndOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40867];

    UOnlineGameInterfaceImpl_execEndOnlineGame_Parms EndOnlineGame_Parms;

    pFnEndOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEndOnlineGame, &EndOnlineGame_Parms, NULL);

    pFnEndOnlineGame->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearStartOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearStartOnlineGameCompleteDelegate() {
    static UFunction* pFnClearStartOnlineGameCompleteDelegate = NULL;

    if (!pFnClearStartOnlineGameCompleteDelegate)
        pFnClearStartOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40864];

    UOnlineGameInterfaceImpl_execClearStartOnlineGameCompleteDelegate_Parms
        ClearStartOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearStartOnlineGameCompleteDelegate,
                       &ClearStartOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddStartOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddStartOnlineGameCompleteDelegate() {
    static UFunction* pFnAddStartOnlineGameCompleteDelegate = NULL;

    if (!pFnAddStartOnlineGameCompleteDelegate)
        pFnAddStartOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40862];

    UOnlineGameInterfaceImpl_execAddStartOnlineGameCompleteDelegate_Parms
        AddStartOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddStartOnlineGameCompleteDelegate,
                       &AddStartOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnStartOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnStartOnlineGameComplete() {
    static UFunction* pFnOnStartOnlineGameComplete = NULL;

    if (!pFnOnStartOnlineGameComplete)
        pFnOnStartOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40859];

    UOnlineGameInterfaceImpl_execOnStartOnlineGameComplete_Parms
        OnStartOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnStartOnlineGameComplete,
                       &OnStartOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.StartOnlineGame
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::StartOnlineGame() {
    static UFunction* pFnStartOnlineGame = NULL;

    if (!pFnStartOnlineGame)
        pFnStartOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40856];

    UOnlineGameInterfaceImpl_execStartOnlineGame_Parms StartOnlineGame_Parms;

    pFnStartOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnStartOnlineGame, &StartOnlineGame_Parms, NULL);

    pFnStartOnlineGame->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.RetrieveGameSettingsForIP
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RetrieveGameSettingsForIP() {
    static UFunction* pFnRetrieveGameSettingsForIP = NULL;

    if (!pFnRetrieveGameSettingsForIP)
        pFnRetrieveGameSettingsForIP =
            (UFunction*)UObject::GObjObjects()->Data[40854];

    UOnlineGameInterfaceImpl_execRetrieveGameSettingsForIP_Parms
        RetrieveGameSettingsForIP_Parms;

    this->ProcessEvent(pFnRetrieveGameSettingsForIP,
                       &RetrieveGameSettingsForIP_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearOnRetrieveGameSettingsForIPDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearOnRetrieveGameSettingsForIPDelegate() {
    static UFunction* pFnClearOnRetrieveGameSettingsForIPDelegate = NULL;

    if (!pFnClearOnRetrieveGameSettingsForIPDelegate)
        pFnClearOnRetrieveGameSettingsForIPDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40852];

    UOnlineGameInterfaceImpl_execClearOnRetrieveGameSettingsForIPDelegate_Parms
        ClearOnRetrieveGameSettingsForIPDelegate_Parms;

    this->ProcessEvent(pFnClearOnRetrieveGameSettingsForIPDelegate,
                       &ClearOnRetrieveGameSettingsForIPDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddOnRetrieveGameSettingsForIPDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddOnRetrieveGameSettingsForIPDelegate() {
    static UFunction* pFnAddOnRetrieveGameSettingsForIPDelegate = NULL;

    if (!pFnAddOnRetrieveGameSettingsForIPDelegate)
        pFnAddOnRetrieveGameSettingsForIPDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40850];

    UOnlineGameInterfaceImpl_execAddOnRetrieveGameSettingsForIPDelegate_Parms
        AddOnRetrieveGameSettingsForIPDelegate_Parms;

    this->ProcessEvent(pFnAddOnRetrieveGameSettingsForIPDelegate,
                       &AddOnRetrieveGameSettingsForIPDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnRetrievedGameSettingsForIP
// [0x00520000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnRetrievedGameSettingsForIP() {
    static UFunction* pFnOnRetrievedGameSettingsForIP = NULL;

    if (!pFnOnRetrievedGameSettingsForIP)
        pFnOnRetrievedGameSettingsForIP =
            (UFunction*)UObject::GObjObjects()->Data[40847];

    UOnlineGameInterfaceImpl_execOnRetrievedGameSettingsForIP_Parms
        OnRetrievedGameSettingsForIP_Parms;

    this->ProcessEvent(pFnOnRetrievedGameSettingsForIP,
                       &OnRetrievedGameSettingsForIP_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearUnregisterPlayerCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearUnregisterPlayerCompleteDelegate() {
    static UFunction* pFnClearUnregisterPlayerCompleteDelegate = NULL;

    if (!pFnClearUnregisterPlayerCompleteDelegate)
        pFnClearUnregisterPlayerCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40845];

    UOnlineGameInterfaceImpl_execClearUnregisterPlayerCompleteDelegate_Parms
        ClearUnregisterPlayerCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearUnregisterPlayerCompleteDelegate,
                       &ClearUnregisterPlayerCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddUnregisterPlayerCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddUnregisterPlayerCompleteDelegate() {
    static UFunction* pFnAddUnregisterPlayerCompleteDelegate = NULL;

    if (!pFnAddUnregisterPlayerCompleteDelegate)
        pFnAddUnregisterPlayerCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40843];

    UOnlineGameInterfaceImpl_execAddUnregisterPlayerCompleteDelegate_Parms
        AddUnregisterPlayerCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddUnregisterPlayerCompleteDelegate,
                       &AddUnregisterPlayerCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnUnregisterPlayerComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnUnregisterPlayerComplete() {
    static UFunction* pFnOnUnregisterPlayerComplete = NULL;

    if (!pFnOnUnregisterPlayerComplete)
        pFnOnUnregisterPlayerComplete =
            (UFunction*)UObject::GObjObjects()->Data[40839];

    UOnlineGameInterfaceImpl_execOnUnregisterPlayerComplete_Parms
        OnUnregisterPlayerComplete_Parms;

    this->ProcessEvent(pFnOnUnregisterPlayerComplete,
                       &OnUnregisterPlayerComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.UnregisterPlayers
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::UnregisterPlayers() {
    static UFunction* pFnUnregisterPlayers = NULL;

    if (!pFnUnregisterPlayers)
        pFnUnregisterPlayers = (UFunction*)UObject::GObjObjects()->Data[40834];

    UOnlineGameInterfaceImpl_execUnregisterPlayers_Parms
        UnregisterPlayers_Parms;

    this->ProcessEvent(pFnUnregisterPlayers, &UnregisterPlayers_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.UnregisterPlayer
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::UnregisterPlayer() {
    static UFunction* pFnUnregisterPlayer = NULL;

    if (!pFnUnregisterPlayer)
        pFnUnregisterPlayer = (UFunction*)UObject::GObjObjects()->Data[40830];

    UOnlineGameInterfaceImpl_execUnregisterPlayer_Parms UnregisterPlayer_Parms;

    this->ProcessEvent(pFnUnregisterPlayer, &UnregisterPlayer_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearRegisterPlayerCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearRegisterPlayerCompleteDelegate() {
    static UFunction* pFnClearRegisterPlayerCompleteDelegate = NULL;

    if (!pFnClearRegisterPlayerCompleteDelegate)
        pFnClearRegisterPlayerCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40828];

    UOnlineGameInterfaceImpl_execClearRegisterPlayerCompleteDelegate_Parms
        ClearRegisterPlayerCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearRegisterPlayerCompleteDelegate,
                       &ClearRegisterPlayerCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddRegisterPlayerCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddRegisterPlayerCompleteDelegate() {
    static UFunction* pFnAddRegisterPlayerCompleteDelegate = NULL;

    if (!pFnAddRegisterPlayerCompleteDelegate)
        pFnAddRegisterPlayerCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40826];

    UOnlineGameInterfaceImpl_execAddRegisterPlayerCompleteDelegate_Parms
        AddRegisterPlayerCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddRegisterPlayerCompleteDelegate,
                       &AddRegisterPlayerCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnRegisterPlayerComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnRegisterPlayerComplete() {
    static UFunction* pFnOnRegisterPlayerComplete = NULL;

    if (!pFnOnRegisterPlayerComplete)
        pFnOnRegisterPlayerComplete =
            (UFunction*)UObject::GObjObjects()->Data[40822];

    UOnlineGameInterfaceImpl_execOnRegisterPlayerComplete_Parms
        OnRegisterPlayerComplete_Parms;

    this->ProcessEvent(pFnOnRegisterPlayerComplete,
                       &OnRegisterPlayerComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RegisterPlayers
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RegisterPlayers() {
    static UFunction* pFnRegisterPlayers = NULL;

    if (!pFnRegisterPlayers)
        pFnRegisterPlayers = (UFunction*)UObject::GObjObjects()->Data[40817];

    UOnlineGameInterfaceImpl_execRegisterPlayers_Parms RegisterPlayers_Parms;

    this->ProcessEvent(pFnRegisterPlayers, &RegisterPlayers_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.RegisterPlayer
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::RegisterPlayer() {
    static UFunction* pFnRegisterPlayer = NULL;

    if (!pFnRegisterPlayer)
        pFnRegisterPlayer = (UFunction*)UObject::GObjObjects()->Data[40812];

    UOnlineGameInterfaceImpl_execRegisterPlayer_Parms RegisterPlayer_Parms;

    this->ProcessEvent(pFnRegisterPlayer, &RegisterPlayer_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetResolvedConnectString
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::GetResolvedConnectString() {
    static UFunction* pFnGetResolvedConnectString = NULL;

    if (!pFnGetResolvedConnectString)
        pFnGetResolvedConnectString =
            (UFunction*)UObject::GObjObjects()->Data[40808];

    UOnlineGameInterfaceImpl_execGetResolvedConnectString_Parms
        GetResolvedConnectString_Parms;

    pFnGetResolvedConnectString->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetResolvedConnectString,
                       &GetResolvedConnectString_Parms, NULL);

    pFnGetResolvedConnectString->FunctionFlags |= 0x400;
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearQuerySessionsForUserCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearQuerySessionsForUserCompleteDelegate() {
    static UFunction* pFnClearQuerySessionsForUserCompleteDelegate = NULL;

    if (!pFnClearQuerySessionsForUserCompleteDelegate)
        pFnClearQuerySessionsForUserCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40806];

    UOnlineGameInterfaceImpl_execClearQuerySessionsForUserCompleteDelegate_Parms
        ClearQuerySessionsForUserCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearQuerySessionsForUserCompleteDelegate,
                       &ClearQuerySessionsForUserCompleteDelegate_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddQuerySessionsForUserCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddQuerySessionsForUserCompleteDelegate() {
    static UFunction* pFnAddQuerySessionsForUserCompleteDelegate = NULL;

    if (!pFnAddQuerySessionsForUserCompleteDelegate)
        pFnAddQuerySessionsForUserCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40804];

    UOnlineGameInterfaceImpl_execAddQuerySessionsForUserCompleteDelegate_Parms
        AddQuerySessionsForUserCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddQuerySessionsForUserCompleteDelegate,
                       &AddQuerySessionsForUserCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnQuerySessionsForUserComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnQuerySessionsForUserComplete() {
    static UFunction* pFnOnQuerySessionsForUserComplete = NULL;

    if (!pFnOnQuerySessionsForUserComplete)
        pFnOnQuerySessionsForUserComplete =
            (UFunction*)UObject::GObjObjects()->Data[40801];

    UOnlineGameInterfaceImpl_execOnQuerySessionsForUserComplete_Parms
        OnQuerySessionsForUserComplete_Parms;

    this->ProcessEvent(pFnOnQuerySessionsForUserComplete,
                       &OnQuerySessionsForUserComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.QuerySessionsByKeyword
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::QuerySessionsByKeyword() {
    static UFunction* pFnQuerySessionsByKeyword = NULL;

    if (!pFnQuerySessionsByKeyword)
        pFnQuerySessionsByKeyword =
            (UFunction*)UObject::GObjObjects()->Data[40796];

    UOnlineGameInterfaceImpl_execQuerySessionsByKeyword_Parms
        QuerySessionsByKeyword_Parms;

    this->ProcessEvent(pFnQuerySessionsByKeyword, &QuerySessionsByKeyword_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.QuerySessionsForUser
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::QuerySessionsForUser() {
    static UFunction* pFnQuerySessionsForUser = NULL;

    if (!pFnQuerySessionsForUser)
        pFnQuerySessionsForUser =
            (UFunction*)UObject::GObjObjects()->Data[40793];

    UOnlineGameInterfaceImpl_execQuerySessionsForUser_Parms
        QuerySessionsForUser_Parms;

    this->ProcessEvent(pFnQuerySessionsForUser, &QuerySessionsForUser_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.LeaveAllOnlineSessions
// [0x00024000]
// Parameters infos:

void UOnlineGameInterfaceImpl::LeaveAllOnlineSessions() {
    static UFunction* pFnLeaveAllOnlineSessions = NULL;

    if (!pFnLeaveAllOnlineSessions)
        pFnLeaveAllOnlineSessions =
            (UFunction*)UObject::GObjObjects()->Data[40791];

    UOnlineGameInterfaceImpl_execLeaveAllOnlineSessions_Parms
        LeaveAllOnlineSessions_Parms;

    this->ProcessEvent(pFnLeaveAllOnlineSessions, &LeaveAllOnlineSessions_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.LeaveOnlineSession
// [0x00024002]
// Parameters infos:

void UOnlineGameInterfaceImpl::LeaveOnlineSession() {
    static UFunction* pFnLeaveOnlineSession = NULL;

    if (!pFnLeaveOnlineSession)
        pFnLeaveOnlineSession = (UFunction*)UObject::GObjObjects()->Data[40786];

    UOnlineGameInterfaceImpl_execLeaveOnlineSession_Parms
        LeaveOnlineSession_Parms;

    this->ProcessEvent(pFnLeaveOnlineSession, &LeaveOnlineSession_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearMatchStatusChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearMatchStatusChangedDelegate() {
    static UFunction* pFnClearMatchStatusChangedDelegate = NULL;

    if (!pFnClearMatchStatusChangedDelegate)
        pFnClearMatchStatusChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40784];

    UOnlineGameInterfaceImpl_execClearMatchStatusChangedDelegate_Parms
        ClearMatchStatusChangedDelegate_Parms;

    this->ProcessEvent(pFnClearMatchStatusChangedDelegate,
                       &ClearMatchStatusChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddMatchStatusChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddMatchStatusChangedDelegate() {
    static UFunction* pFnAddMatchStatusChangedDelegate = NULL;

    if (!pFnAddMatchStatusChangedDelegate)
        pFnAddMatchStatusChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40782];

    UOnlineGameInterfaceImpl_execAddMatchStatusChangedDelegate_Parms
        AddMatchStatusChangedDelegate_Parms;

    this->ProcessEvent(pFnAddMatchStatusChangedDelegate,
                       &AddMatchStatusChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnMatchStatusChanged
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnMatchStatusChanged() {
    static UFunction* pFnOnMatchStatusChanged = NULL;

    if (!pFnOnMatchStatusChanged)
        pFnOnMatchStatusChanged =
            (UFunction*)UObject::GObjObjects()->Data[40779];

    UOnlineGameInterfaceImpl_execOnMatchStatusChanged_Parms
        OnMatchStatusChanged_Parms;

    this->ProcessEvent(pFnOnMatchStatusChanged, &OnMatchStatusChanged_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearGamePlayersChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearGamePlayersChangedDelegate() {
    static UFunction* pFnClearGamePlayersChangedDelegate = NULL;

    if (!pFnClearGamePlayersChangedDelegate)
        pFnClearGamePlayersChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40777];

    UOnlineGameInterfaceImpl_execClearGamePlayersChangedDelegate_Parms
        ClearGamePlayersChangedDelegate_Parms;

    this->ProcessEvent(pFnClearGamePlayersChangedDelegate,
                       &ClearGamePlayersChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddGamePlayersChangedDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddGamePlayersChangedDelegate() {
    static UFunction* pFnAddGamePlayersChangedDelegate = NULL;

    if (!pFnAddGamePlayersChangedDelegate)
        pFnAddGamePlayersChangedDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40775];

    UOnlineGameInterfaceImpl_execAddGamePlayersChangedDelegate_Parms
        AddGamePlayersChangedDelegate_Parms;

    this->ProcessEvent(pFnAddGamePlayersChangedDelegate,
                       &AddGamePlayersChangedDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnGamePlayersChanged
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnGamePlayersChanged() {
    static UFunction* pFnOnGamePlayersChanged = NULL;

    if (!pFnOnGamePlayersChanged)
        pFnOnGamePlayersChanged =
            (UFunction*)UObject::GObjObjects()->Data[40771];

    UOnlineGameInterfaceImpl_execOnGamePlayersChanged_Parms
        OnGamePlayersChanged_Parms;

    this->ProcessEvent(pFnOnGamePlayersChanged, &OnGamePlayersChanged_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearUpdateSessionPropertiesCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearUpdateSessionPropertiesCompleteDelegate() {
    static UFunction* pFnClearUpdateSessionPropertiesCompleteDelegate = NULL;

    if (!pFnClearUpdateSessionPropertiesCompleteDelegate)
        pFnClearUpdateSessionPropertiesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40769];

    UOnlineGameInterfaceImpl_execClearUpdateSessionPropertiesCompleteDelegate_Parms
        ClearUpdateSessionPropertiesCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearUpdateSessionPropertiesCompleteDelegate,
                       &ClearUpdateSessionPropertiesCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddUpdateSessionPropertiesCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddUpdateSessionPropertiesCompleteDelegate() {
    static UFunction* pFnAddUpdateSessionPropertiesCompleteDelegate = NULL;

    if (!pFnAddUpdateSessionPropertiesCompleteDelegate)
        pFnAddUpdateSessionPropertiesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40767];

    UOnlineGameInterfaceImpl_execAddUpdateSessionPropertiesCompleteDelegate_Parms
        AddUpdateSessionPropertiesCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddUpdateSessionPropertiesCompleteDelegate,
                       &AddUpdateSessionPropertiesCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnUpdateSessionPropertiesComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnUpdateSessionPropertiesComplete() {
    static UFunction* pFnOnUpdateSessionPropertiesComplete = NULL;

    if (!pFnOnUpdateSessionPropertiesComplete)
        pFnOnUpdateSessionPropertiesComplete =
            (UFunction*)UObject::GObjObjects()->Data[40764];

    UOnlineGameInterfaceImpl_execOnUpdateSessionPropertiesComplete_Parms
        OnUpdateSessionPropertiesComplete_Parms;

    this->ProcessEvent(pFnOnUpdateSessionPropertiesComplete,
                       &OnUpdateSessionPropertiesComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.UpdateSessionProperties
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::UpdateSessionProperties() {
    static UFunction* pFnUpdateSessionProperties = NULL;

    if (!pFnUpdateSessionProperties)
        pFnUpdateSessionProperties =
            (UFunction*)UObject::GObjObjects()->Data[40760];

    UOnlineGameInterfaceImpl_execUpdateSessionProperties_Parms
        UpdateSessionProperties_Parms;

    this->ProcessEvent(pFnUpdateSessionProperties,
                       &UpdateSessionProperties_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.DeleteCustomMemberProperty
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::DeleteCustomMemberProperty() {
    static UFunction* pFnDeleteCustomMemberProperty = NULL;

    if (!pFnDeleteCustomMemberProperty)
        pFnDeleteCustomMemberProperty =
            (UFunction*)UObject::GObjObjects()->Data[40756];

    UOnlineGameInterfaceImpl_execDeleteCustomMemberProperty_Parms
        DeleteCustomMemberProperty_Parms;

    this->ProcessEvent(pFnDeleteCustomMemberProperty,
                       &DeleteCustomMemberProperty_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SetCustomMemberProperty
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::SetCustomMemberProperty() {
    static UFunction* pFnSetCustomMemberProperty = NULL;

    if (!pFnSetCustomMemberProperty)
        pFnSetCustomMemberProperty =
            (UFunction*)UObject::GObjObjects()->Data[40751];

    UOnlineGameInterfaceImpl_execSetCustomMemberProperty_Parms
        SetCustomMemberProperty_Parms;

    this->ProcessEvent(pFnSetCustomMemberProperty,
                       &SetCustomMemberProperty_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.DeleteCustomSessionProperty
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::DeleteCustomSessionProperty() {
    static UFunction* pFnDeleteCustomSessionProperty = NULL;

    if (!pFnDeleteCustomSessionProperty)
        pFnDeleteCustomSessionProperty =
            (UFunction*)UObject::GObjObjects()->Data[40747];

    UOnlineGameInterfaceImpl_execDeleteCustomSessionProperty_Parms
        DeleteCustomSessionProperty_Parms;

    this->ProcessEvent(pFnDeleteCustomSessionProperty,
                       &DeleteCustomSessionProperty_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SetCustomSessionProperty
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::SetCustomSessionProperty() {
    static UFunction* pFnSetCustomSessionProperty = NULL;

    if (!pFnSetCustomSessionProperty)
        pFnSetCustomSessionProperty =
            (UFunction*)UObject::GObjObjects()->Data[40742];

    UOnlineGameInterfaceImpl_execSetCustomSessionProperty_Parms
        SetCustomSessionProperty_Parms;

    this->ProcessEvent(pFnSetCustomSessionProperty,
                       &SetCustomSessionProperty_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearDeleteMatchTicketCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearDeleteMatchTicketCompleteDelegate() {
    static UFunction* pFnClearDeleteMatchTicketCompleteDelegate = NULL;

    if (!pFnClearDeleteMatchTicketCompleteDelegate)
        pFnClearDeleteMatchTicketCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40740];

    UOnlineGameInterfaceImpl_execClearDeleteMatchTicketCompleteDelegate_Parms
        ClearDeleteMatchTicketCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearDeleteMatchTicketCompleteDelegate,
                       &ClearDeleteMatchTicketCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddDeleteMatchTicketCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddDeleteMatchTicketCompleteDelegate() {
    static UFunction* pFnAddDeleteMatchTicketCompleteDelegate = NULL;

    if (!pFnAddDeleteMatchTicketCompleteDelegate)
        pFnAddDeleteMatchTicketCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40738];

    UOnlineGameInterfaceImpl_execAddDeleteMatchTicketCompleteDelegate_Parms
        AddDeleteMatchTicketCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddDeleteMatchTicketCompleteDelegate,
                       &AddDeleteMatchTicketCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnDeleteMatchTicketComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnDeleteMatchTicketComplete() {
    static UFunction* pFnOnDeleteMatchTicketComplete = NULL;

    if (!pFnOnDeleteMatchTicketComplete)
        pFnOnDeleteMatchTicketComplete =
            (UFunction*)UObject::GObjObjects()->Data[40735];

    UOnlineGameInterfaceImpl_execOnDeleteMatchTicketComplete_Parms
        OnDeleteMatchTicketComplete_Parms;

    this->ProcessEvent(pFnOnDeleteMatchTicketComplete,
                       &OnDeleteMatchTicketComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.DeleteMatchTicketWithHopper
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::DeleteMatchTicketWithHopper() {
    static UFunction* pFnDeleteMatchTicketWithHopper = NULL;

    if (!pFnDeleteMatchTicketWithHopper)
        pFnDeleteMatchTicketWithHopper =
            (UFunction*)UObject::GObjObjects()->Data[40730];

    UOnlineGameInterfaceImpl_execDeleteMatchTicketWithHopper_Parms
        DeleteMatchTicketWithHopper_Parms;

    this->ProcessEvent(pFnDeleteMatchTicketWithHopper,
                       &DeleteMatchTicketWithHopper_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.DeleteMatchTicket
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::DeleteMatchTicket() {
    static UFunction* pFnDeleteMatchTicket = NULL;

    if (!pFnDeleteMatchTicket)
        pFnDeleteMatchTicket = (UFunction*)UObject::GObjObjects()->Data[40726];

    UOnlineGameInterfaceImpl_execDeleteMatchTicket_Parms
        DeleteMatchTicket_Parms;

    this->ProcessEvent(pFnDeleteMatchTicket, &DeleteMatchTicket_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearQueryMatchmakingForSessionCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::
    ClearQueryMatchmakingForSessionCompleteDelegate() {
    static UFunction* pFnClearQueryMatchmakingForSessionCompleteDelegate = NULL;

    if (!pFnClearQueryMatchmakingForSessionCompleteDelegate)
        pFnClearQueryMatchmakingForSessionCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40724];

    UOnlineGameInterfaceImpl_execClearQueryMatchmakingForSessionCompleteDelegate_Parms
        ClearQueryMatchmakingForSessionCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearQueryMatchmakingForSessionCompleteDelegate,
                       &ClearQueryMatchmakingForSessionCompleteDelegate_Parms,
                       NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddQueryMatchmakingForSessionCompleteDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddQueryMatchmakingForSessionCompleteDelegate() {
    static UFunction* pFnAddQueryMatchmakingForSessionCompleteDelegate = NULL;

    if (!pFnAddQueryMatchmakingForSessionCompleteDelegate)
        pFnAddQueryMatchmakingForSessionCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40722];

    UOnlineGameInterfaceImpl_execAddQueryMatchmakingForSessionCompleteDelegate_Parms
        AddQueryMatchmakingForSessionCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddQueryMatchmakingForSessionCompleteDelegate,
                       &AddQueryMatchmakingForSessionCompleteDelegate_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnQueryMatchmakingForSessionComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnQueryMatchmakingForSessionComplete() {
    static UFunction* pFnOnQueryMatchmakingForSessionComplete = NULL;

    if (!pFnOnQueryMatchmakingForSessionComplete)
        pFnOnQueryMatchmakingForSessionComplete =
            (UFunction*)UObject::GObjObjects()->Data[40719];

    UOnlineGameInterfaceImpl_execOnQueryMatchmakingForSessionComplete_Parms
        OnQueryMatchmakingForSessionComplete_Parms;

    this->ProcessEvent(pFnOnQueryMatchmakingForSessionComplete,
                       &OnQueryMatchmakingForSessionComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.QueryMatchmakingForSessionWithHopper
// [0x00024002]
// Parameters infos:

void UOnlineGameInterfaceImpl::QueryMatchmakingForSessionWithHopper() {
    static UFunction* pFnQueryMatchmakingForSessionWithHopper = NULL;

    if (!pFnQueryMatchmakingForSessionWithHopper)
        pFnQueryMatchmakingForSessionWithHopper =
            (UFunction*)UObject::GObjObjects()->Data[40712];

    UOnlineGameInterfaceImpl_execQueryMatchmakingForSessionWithHopper_Parms
        QueryMatchmakingForSessionWithHopper_Parms;

    this->ProcessEvent(pFnQueryMatchmakingForSessionWithHopper,
                       &QueryMatchmakingForSessionWithHopper_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.QueryMatchmakingForSession
// [0x00024002]
// Parameters infos:

void UOnlineGameInterfaceImpl::QueryMatchmakingForSession() {
    static UFunction* pFnQueryMatchmakingForSession = NULL;

    if (!pFnQueryMatchmakingForSession)
        pFnQueryMatchmakingForSession =
            (UFunction*)UObject::GObjObjects()->Data[40706];

    UOnlineGameInterfaceImpl_execQueryMatchmakingForSession_Parms
        QueryMatchmakingForSession_Parms;

    this->ProcessEvent(pFnQueryMatchmakingForSession,
                       &QueryMatchmakingForSession_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearMultiplayerSessionChangeDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearMultiplayerSessionChangeDelegate() {
    static UFunction* pFnClearMultiplayerSessionChangeDelegate = NULL;

    if (!pFnClearMultiplayerSessionChangeDelegate)
        pFnClearMultiplayerSessionChangeDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40704];

    UOnlineGameInterfaceImpl_execClearMultiplayerSessionChangeDelegate_Parms
        ClearMultiplayerSessionChangeDelegate_Parms;

    this->ProcessEvent(pFnClearMultiplayerSessionChangeDelegate,
                       &ClearMultiplayerSessionChangeDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddMultiplayerSessionChangeDelegate
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddMultiplayerSessionChangeDelegate() {
    static UFunction* pFnAddMultiplayerSessionChangeDelegate = NULL;

    if (!pFnAddMultiplayerSessionChangeDelegate)
        pFnAddMultiplayerSessionChangeDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40702];

    UOnlineGameInterfaceImpl_execAddMultiplayerSessionChangeDelegate_Parms
        AddMultiplayerSessionChangeDelegate_Parms;

    this->ProcessEvent(pFnAddMultiplayerSessionChangeDelegate,
                       &AddMultiplayerSessionChangeDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnMultiplayerSessionChange
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnMultiplayerSessionChange() {
    static UFunction* pFnOnMultiplayerSessionChange = NULL;

    if (!pFnOnMultiplayerSessionChange)
        pFnOnMultiplayerSessionChange =
            (UFunction*)UObject::GObjObjects()->Data[40699];

    UOnlineGameInterfaceImpl_execOnMultiplayerSessionChange_Parms
        OnMultiplayerSessionChange_Parms;

    this->ProcessEvent(pFnOnMultiplayerSessionChange,
                       &OnMultiplayerSessionChange_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearJoinOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearJoinOnlineGameCompleteDelegate() {
    static UFunction* pFnClearJoinOnlineGameCompleteDelegate = NULL;

    if (!pFnClearJoinOnlineGameCompleteDelegate)
        pFnClearJoinOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40696];

    UOnlineGameInterfaceImpl_execClearJoinOnlineGameCompleteDelegate_Parms
        ClearJoinOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearJoinOnlineGameCompleteDelegate,
                       &ClearJoinOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddJoinOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddJoinOnlineGameCompleteDelegate() {
    static UFunction* pFnAddJoinOnlineGameCompleteDelegate = NULL;

    if (!pFnAddJoinOnlineGameCompleteDelegate)
        pFnAddJoinOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40694];

    UOnlineGameInterfaceImpl_execAddJoinOnlineGameCompleteDelegate_Parms
        AddJoinOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddJoinOnlineGameCompleteDelegate,
                       &AddJoinOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnJoinOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnJoinOnlineGameComplete() {
    static UFunction* pFnOnJoinOnlineGameComplete = NULL;

    if (!pFnOnJoinOnlineGameComplete)
        pFnOnJoinOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40691];

    UOnlineGameInterfaceImpl_execOnJoinOnlineGameComplete_Parms
        OnJoinOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnJoinOnlineGameComplete,
                       &OnJoinOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.IsCurrentRoomOwner
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::IsCurrentRoomOwner() {
    static UFunction* pFnIsCurrentRoomOwner = NULL;

    if (!pFnIsCurrentRoomOwner)
        pFnIsCurrentRoomOwner = (UFunction*)UObject::GObjObjects()->Data[40689];

    UOnlineGameInterfaceImpl_execIsCurrentRoomOwner_Parms
        IsCurrentRoomOwner_Parms;

    this->ProcessEvent(pFnIsCurrentRoomOwner, &IsCurrentRoomOwner_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.SetRankedReadyStatus
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::SetRankedReadyStatus() {
    static UFunction* pFnSetRankedReadyStatus = NULL;

    if (!pFnSetRankedReadyStatus)
        pFnSetRankedReadyStatus =
            (UFunction*)UObject::GObjObjects()->Data[40686];

    UOnlineGameInterfaceImpl_execSetRankedReadyStatus_Parms
        SetRankedReadyStatus_Parms;

    this->ProcessEvent(pFnSetRankedReadyStatus, &SetRankedReadyStatus_Parms,
                       NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.IsJoinOperationInProgress
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::IsJoinOperationInProgress() {
    static UFunction* pFnIsJoinOperationInProgress = NULL;

    if (!pFnIsJoinOperationInProgress)
        pFnIsJoinOperationInProgress =
            (UFunction*)UObject::GObjObjects()->Data[40684];

    UOnlineGameInterfaceImpl_execIsJoinOperationInProgress_Parms
        IsJoinOperationInProgress_Parms;

    this->ProcessEvent(pFnIsJoinOperationInProgress,
                       &IsJoinOperationInProgress_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.JoinOnlineGameByMatchingParams
// [0x00420000]
// Parameters infos:

void UOnlineGameInterfaceImpl::JoinOnlineGameByMatchingParams() {
    static UFunction* pFnJoinOnlineGameByMatchingParams = NULL;

    if (!pFnJoinOnlineGameByMatchingParams)
        pFnJoinOnlineGameByMatchingParams =
            (UFunction*)UObject::GObjObjects()->Data[40680];

    UOnlineGameInterfaceImpl_execJoinOnlineGameByMatchingParams_Parms
        JoinOnlineGameByMatchingParams_Parms;

    this->ProcessEvent(pFnJoinOnlineGameByMatchingParams,
                       &JoinOnlineGameByMatchingParams_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.JoinOnlineGameBySessionHandle
// [0x00020000]
// Parameters infos:

void UOnlineGameInterfaceImpl::JoinOnlineGameBySessionHandle() {
    static UFunction* pFnJoinOnlineGameBySessionHandle = NULL;

    if (!pFnJoinOnlineGameBySessionHandle)
        pFnJoinOnlineGameBySessionHandle =
            (UFunction*)UObject::GObjObjects()->Data[40675];

    UOnlineGameInterfaceImpl_execJoinOnlineGameBySessionHandle_Parms
        JoinOnlineGameBySessionHandle_Parms;

    this->ProcessEvent(pFnJoinOnlineGameBySessionHandle,
                       &JoinOnlineGameBySessionHandle_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.JoinOnlineGame
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::JoinOnlineGame() {
    static UFunction* pFnJoinOnlineGame = NULL;

    if (!pFnJoinOnlineGame)
        pFnJoinOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40670];

    UOnlineGameInterfaceImpl_execJoinOnlineGame_Parms JoinOnlineGame_Parms;

    pFnJoinOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnJoinOnlineGame, &JoinOnlineGame_Parms, NULL);

    pFnJoinOnlineGame->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.FreeSearchResults
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::FreeSearchResults() {
    static UFunction* pFnFreeSearchResults = NULL;

    if (!pFnFreeSearchResults)
        pFnFreeSearchResults = (UFunction*)UObject::GObjObjects()->Data[40667];

    UOnlineGameInterfaceImpl_execFreeSearchResults_Parms
        FreeSearchResults_Parms;

    pFnFreeSearchResults->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFreeSearchResults, &FreeSearchResults_Parms, NULL);

    pFnFreeSearchResults->FunctionFlags |= 0x400;
};

// Function
// IpDrv.OnlineGameInterfaceImpl.ClearCancelFindOnlineGamesCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearCancelFindOnlineGamesCompleteDelegate() {
    static UFunction* pFnClearCancelFindOnlineGamesCompleteDelegate = NULL;

    if (!pFnClearCancelFindOnlineGamesCompleteDelegate)
        pFnClearCancelFindOnlineGamesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40664];

    UOnlineGameInterfaceImpl_execClearCancelFindOnlineGamesCompleteDelegate_Parms
        ClearCancelFindOnlineGamesCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearCancelFindOnlineGamesCompleteDelegate,
                       &ClearCancelFindOnlineGamesCompleteDelegate_Parms, NULL);
};

// Function
// IpDrv.OnlineGameInterfaceImpl.AddCancelFindOnlineGamesCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddCancelFindOnlineGamesCompleteDelegate() {
    static UFunction* pFnAddCancelFindOnlineGamesCompleteDelegate = NULL;

    if (!pFnAddCancelFindOnlineGamesCompleteDelegate)
        pFnAddCancelFindOnlineGamesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40662];

    UOnlineGameInterfaceImpl_execAddCancelFindOnlineGamesCompleteDelegate_Parms
        AddCancelFindOnlineGamesCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddCancelFindOnlineGamesCompleteDelegate,
                       &AddCancelFindOnlineGamesCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnCancelFindOnlineGamesComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnCancelFindOnlineGamesComplete() {
    static UFunction* pFnOnCancelFindOnlineGamesComplete = NULL;

    if (!pFnOnCancelFindOnlineGamesComplete)
        pFnOnCancelFindOnlineGamesComplete =
            (UFunction*)UObject::GObjObjects()->Data[40660];

    UOnlineGameInterfaceImpl_execOnCancelFindOnlineGamesComplete_Parms
        OnCancelFindOnlineGamesComplete_Parms;

    this->ProcessEvent(pFnOnCancelFindOnlineGamesComplete,
                       &OnCancelFindOnlineGamesComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.CancelFindOnlineGames
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::CancelFindOnlineGames() {
    static UFunction* pFnCancelFindOnlineGames = NULL;

    if (!pFnCancelFindOnlineGames)
        pFnCancelFindOnlineGames =
            (UFunction*)UObject::GObjObjects()->Data[40658];

    UOnlineGameInterfaceImpl_execCancelFindOnlineGames_Parms
        CancelFindOnlineGames_Parms;

    pFnCancelFindOnlineGames->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnCancelFindOnlineGames, &CancelFindOnlineGames_Parms,
                       NULL);

    pFnCancelFindOnlineGames->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearFindOnlineGamesCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearFindOnlineGamesCompleteDelegate() {
    static UFunction* pFnClearFindOnlineGamesCompleteDelegate = NULL;

    if (!pFnClearFindOnlineGamesCompleteDelegate)
        pFnClearFindOnlineGamesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40655];

    UOnlineGameInterfaceImpl_execClearFindOnlineGamesCompleteDelegate_Parms
        ClearFindOnlineGamesCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearFindOnlineGamesCompleteDelegate,
                       &ClearFindOnlineGamesCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddFindOnlineGamesCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddFindOnlineGamesCompleteDelegate() {
    static UFunction* pFnAddFindOnlineGamesCompleteDelegate = NULL;

    if (!pFnAddFindOnlineGamesCompleteDelegate)
        pFnAddFindOnlineGamesCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40653];

    UOnlineGameInterfaceImpl_execAddFindOnlineGamesCompleteDelegate_Parms
        AddFindOnlineGamesCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddFindOnlineGamesCompleteDelegate,
                       &AddFindOnlineGamesCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.FindOnlineGames
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::FindOnlineGames() {
    static UFunction* pFnFindOnlineGames = NULL;

    if (!pFnFindOnlineGames)
        pFnFindOnlineGames = (UFunction*)UObject::GObjObjects()->Data[40649];

    UOnlineGameInterfaceImpl_execFindOnlineGames_Parms FindOnlineGames_Parms;

    pFnFindOnlineGames->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFindOnlineGames, &FindOnlineGames_Parms, NULL);

    pFnFindOnlineGames->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearDestroyOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearDestroyOnlineGameCompleteDelegate() {
    static UFunction* pFnClearDestroyOnlineGameCompleteDelegate = NULL;

    if (!pFnClearDestroyOnlineGameCompleteDelegate)
        pFnClearDestroyOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40646];

    UOnlineGameInterfaceImpl_execClearDestroyOnlineGameCompleteDelegate_Parms
        ClearDestroyOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearDestroyOnlineGameCompleteDelegate,
                       &ClearDestroyOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddDestroyOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddDestroyOnlineGameCompleteDelegate() {
    static UFunction* pFnAddDestroyOnlineGameCompleteDelegate = NULL;

    if (!pFnAddDestroyOnlineGameCompleteDelegate)
        pFnAddDestroyOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40644];

    UOnlineGameInterfaceImpl_execAddDestroyOnlineGameCompleteDelegate_Parms
        AddDestroyOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddDestroyOnlineGameCompleteDelegate,
                       &AddDestroyOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnDestroyOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnDestroyOnlineGameComplete() {
    static UFunction* pFnOnDestroyOnlineGameComplete = NULL;

    if (!pFnOnDestroyOnlineGameComplete)
        pFnOnDestroyOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40641];

    UOnlineGameInterfaceImpl_execOnDestroyOnlineGameComplete_Parms
        OnDestroyOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnDestroyOnlineGameComplete,
                       &OnDestroyOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.DestroyOnlineGame
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::DestroyOnlineGame() {
    static UFunction* pFnDestroyOnlineGame = NULL;

    if (!pFnDestroyOnlineGame)
        pFnDestroyOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40638];

    UOnlineGameInterfaceImpl_execDestroyOnlineGame_Parms
        DestroyOnlineGame_Parms;

    pFnDestroyOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyOnlineGame, &DestroyOnlineGame_Parms, NULL);

    pFnDestroyOnlineGame->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearUpdateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearUpdateOnlineGameCompleteDelegate() {
    static UFunction* pFnClearUpdateOnlineGameCompleteDelegate = NULL;

    if (!pFnClearUpdateOnlineGameCompleteDelegate)
        pFnClearUpdateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40635];

    UOnlineGameInterfaceImpl_execClearUpdateOnlineGameCompleteDelegate_Parms
        ClearUpdateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearUpdateOnlineGameCompleteDelegate,
                       &ClearUpdateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddUpdateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddUpdateOnlineGameCompleteDelegate() {
    static UFunction* pFnAddUpdateOnlineGameCompleteDelegate = NULL;

    if (!pFnAddUpdateOnlineGameCompleteDelegate)
        pFnAddUpdateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40633];

    UOnlineGameInterfaceImpl_execAddUpdateOnlineGameCompleteDelegate_Parms
        AddUpdateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddUpdateOnlineGameCompleteDelegate,
                       &AddUpdateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnUpdateOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnUpdateOnlineGameComplete() {
    static UFunction* pFnOnUpdateOnlineGameComplete = NULL;

    if (!pFnOnUpdateOnlineGameComplete)
        pFnOnUpdateOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40630];

    UOnlineGameInterfaceImpl_execOnUpdateOnlineGameComplete_Parms
        OnUpdateOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnUpdateOnlineGameComplete,
                       &OnUpdateOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.UpdateOnlineGame
// [0x00024000]
// Parameters infos:

void UOnlineGameInterfaceImpl::UpdateOnlineGame() {
    static UFunction* pFnUpdateOnlineGame = NULL;

    if (!pFnUpdateOnlineGame)
        pFnUpdateOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40625];

    UOnlineGameInterfaceImpl_execUpdateOnlineGame_Parms UpdateOnlineGame_Parms;

    this->ProcessEvent(pFnUpdateOnlineGame, &UpdateOnlineGame_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.ClearCreateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::ClearCreateOnlineGameCompleteDelegate() {
    static UFunction* pFnClearCreateOnlineGameCompleteDelegate = NULL;

    if (!pFnClearCreateOnlineGameCompleteDelegate)
        pFnClearCreateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40622];

    UOnlineGameInterfaceImpl_execClearCreateOnlineGameCompleteDelegate_Parms
        ClearCreateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnClearCreateOnlineGameCompleteDelegate,
                       &ClearCreateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.AddCreateOnlineGameCompleteDelegate
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::AddCreateOnlineGameCompleteDelegate() {
    static UFunction* pFnAddCreateOnlineGameCompleteDelegate = NULL;

    if (!pFnAddCreateOnlineGameCompleteDelegate)
        pFnAddCreateOnlineGameCompleteDelegate =
            (UFunction*)UObject::GObjObjects()->Data[40620];

    UOnlineGameInterfaceImpl_execAddCreateOnlineGameCompleteDelegate_Parms
        AddCreateOnlineGameCompleteDelegate_Parms;

    this->ProcessEvent(pFnAddCreateOnlineGameCompleteDelegate,
                       &AddCreateOnlineGameCompleteDelegate_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnCreateOnlineGameComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnCreateOnlineGameComplete() {
    static UFunction* pFnOnCreateOnlineGameComplete = NULL;

    if (!pFnOnCreateOnlineGameComplete)
        pFnOnCreateOnlineGameComplete =
            (UFunction*)UObject::GObjObjects()->Data[40617];

    UOnlineGameInterfaceImpl_execOnCreateOnlineGameComplete_Parms
        OnCreateOnlineGameComplete_Parms;

    this->ProcessEvent(pFnOnCreateOnlineGameComplete,
                       &OnCreateOnlineGameComplete_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.CreateOnlineGame
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::CreateOnlineGame() {
    static UFunction* pFnCreateOnlineGame = NULL;

    if (!pFnCreateOnlineGame)
        pFnCreateOnlineGame = (UFunction*)UObject::GObjObjects()->Data[40612];

    UOnlineGameInterfaceImpl_execCreateOnlineGame_Parms CreateOnlineGame_Parms;

    pFnCreateOnlineGame->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnCreateOnlineGame, &CreateOnlineGame_Parms, NULL);

    pFnCreateOnlineGame->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.GetGameServerRemoteAddress
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlineGameInterfaceImpl::GetGameServerRemoteAddress() {
    static UFunction* pFnGetGameServerRemoteAddress = NULL;

    if (!pFnGetGameServerRemoteAddress)
        pFnGetGameServerRemoteAddress =
            (UFunction*)UObject::GObjObjects()->Data[40609];

    UOnlineGameInterfaceImpl_execGetGameServerRemoteAddress_Parms
        GetGameServerRemoteAddress_Parms;

    pFnGetGameServerRemoteAddress->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetGameServerRemoteAddress,
                       &GetGameServerRemoteAddress_Parms, NULL);

    pFnGetGameServerRemoteAddress->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlineGameInterfaceImpl.GetGameSearch
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetGameSearch() {
    static UFunction* pFnGetGameSearch = NULL;

    if (!pFnGetGameSearch)
        pFnGetGameSearch = (UFunction*)UObject::GObjObjects()->Data[40607];

    UOnlineGameInterfaceImpl_execGetGameSearch_Parms GetGameSearch_Parms;

    this->ProcessEvent(pFnGetGameSearch, &GetGameSearch_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.GetGameSettings
// [0x00020002]
// Parameters infos:

void UOnlineGameInterfaceImpl::GetGameSettings() {
    static UFunction* pFnGetGameSettings = NULL;

    if (!pFnGetGameSettings)
        pFnGetGameSettings = (UFunction*)UObject::GObjObjects()->Data[40604];

    UOnlineGameInterfaceImpl_execGetGameSettings_Parms GetGameSettings_Parms;

    this->ProcessEvent(pFnGetGameSettings, &GetGameSettings_Parms, NULL);
};

// Function IpDrv.OnlineGameInterfaceImpl.OnFindOnlineGamesComplete
// [0x00120000]
// Parameters infos:

void UOnlineGameInterfaceImpl::OnFindOnlineGamesComplete() {
    static UFunction* pFnOnFindOnlineGamesComplete = NULL;

    if (!pFnOnFindOnlineGamesComplete)
        pFnOnFindOnlineGamesComplete =
            (UFunction*)UObject::GObjObjects()->Data[40602];

    UOnlineGameInterfaceImpl_execOnFindOnlineGamesComplete_Parms
        OnFindOnlineGamesComplete_Parms;

    this->ProcessEvent(pFnOnFindOnlineGamesComplete,
                       &OnFindOnlineGamesComplete_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.ParseDataCenterId
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlinePlaylistManager::ParseDataCenterId() {
    static UFunction* pFnParseDataCenterId = NULL;

    if (!pFnParseDataCenterId)
        pFnParseDataCenterId = (UFunction*)UObject::GObjObjects()->Data[41276];

    UOnlinePlaylistManager_execParseDataCenterId_Parms ParseDataCenterId_Parms;

    pFnParseDataCenterId->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnParseDataCenterId, &ParseDataCenterId_Parms, NULL);

    pFnParseDataCenterId->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlinePlaylistManager.OnReadDataCenterIdComplete
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::OnReadDataCenterIdComplete() {
    static UFunction* pFnOnReadDataCenterIdComplete = NULL;

    if (!pFnOnReadDataCenterIdComplete)
        pFnOnReadDataCenterIdComplete =
            (UFunction*)UObject::GObjObjects()->Data[41271];

    UOnlinePlaylistManager_execOnReadDataCenterIdComplete_Parms
        OnReadDataCenterIdComplete_Parms;

    this->ProcessEvent(pFnOnReadDataCenterIdComplete,
                       &OnReadDataCenterIdComplete_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.ReadDataCenterId
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::ReadDataCenterId() {
    static UFunction* pFnReadDataCenterId = NULL;

    if (!pFnReadDataCenterId)
        pFnReadDataCenterId = (UFunction*)UObject::GObjObjects()->Data[41269];

    UOnlinePlaylistManager_execReadDataCenterId_Parms ReadDataCenterId_Parms;

    this->ProcessEvent(pFnReadDataCenterId, &ReadDataCenterId_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.SendPlaylistPopulationUpdate
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UOnlinePlaylistManager::eventSendPlaylistPopulationUpdate() {
    static UFunction* pFnSendPlaylistPopulationUpdate = NULL;

    if (!pFnSendPlaylistPopulationUpdate)
        pFnSendPlaylistPopulationUpdate =
            (UFunction*)UObject::GObjObjects()->Data[41265];

    UOnlinePlaylistManager_eventSendPlaylistPopulationUpdate_Parms
        SendPlaylistPopulationUpdate_Parms;

    this->ProcessEvent(pFnSendPlaylistPopulationUpdate,
                       &SendPlaylistPopulationUpdate_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetPopulationInfoFromPlaylist
// [0x00420002]
// Parameters infos:

void UOnlinePlaylistManager::GetPopulationInfoFromPlaylist() {
    static UFunction* pFnGetPopulationInfoFromPlaylist = NULL;

    if (!pFnGetPopulationInfoFromPlaylist)
        pFnGetPopulationInfoFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41260];

    UOnlinePlaylistManager_execGetPopulationInfoFromPlaylist_Parms
        GetPopulationInfoFromPlaylist_Parms;

    this->ProcessEvent(pFnGetPopulationInfoFromPlaylist,
                       &GetPopulationInfoFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.ParsePlaylistPopulationData
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UOnlinePlaylistManager::ParsePlaylistPopulationData() {
    static UFunction* pFnParsePlaylistPopulationData = NULL;

    if (!pFnParsePlaylistPopulationData)
        pFnParsePlaylistPopulationData =
            (UFunction*)UObject::GObjObjects()->Data[41257];

    UOnlinePlaylistManager_execParsePlaylistPopulationData_Parms
        ParsePlaylistPopulationData_Parms;

    pFnParsePlaylistPopulationData->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnParsePlaylistPopulationData,
                       &ParsePlaylistPopulationData_Parms, NULL);

    pFnParsePlaylistPopulationData->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlinePlaylistManager.OnPlaylistPopulationDataUpdated
// [0x00120000]
// Parameters infos:

void UOnlinePlaylistManager::OnPlaylistPopulationDataUpdated() {
    static UFunction* pFnOnPlaylistPopulationDataUpdated = NULL;

    if (!pFnOnPlaylistPopulationDataUpdated)
        pFnOnPlaylistPopulationDataUpdated =
            (UFunction*)UObject::GObjObjects()->Data[41256];

    UOnlinePlaylistManager_execOnPlaylistPopulationDataUpdated_Parms
        OnPlaylistPopulationDataUpdated_Parms;

    this->ProcessEvent(pFnOnPlaylistPopulationDataUpdated,
                       &OnPlaylistPopulationDataUpdated_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.OnReadPlaylistPopulationComplete
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::OnReadPlaylistPopulationComplete() {
    static UFunction* pFnOnReadPlaylistPopulationComplete = NULL;

    if (!pFnOnReadPlaylistPopulationComplete)
        pFnOnReadPlaylistPopulationComplete =
            (UFunction*)UObject::GObjObjects()->Data[41251];

    UOnlinePlaylistManager_execOnReadPlaylistPopulationComplete_Parms
        OnReadPlaylistPopulationComplete_Parms;

    this->ProcessEvent(pFnOnReadPlaylistPopulationComplete,
                       &OnReadPlaylistPopulationComplete_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.ReadPlaylistPopulation
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::ReadPlaylistPopulation() {
    static UFunction* pFnReadPlaylistPopulation = NULL;

    if (!pFnReadPlaylistPopulation)
        pFnReadPlaylistPopulation =
            (UFunction*)UObject::GObjObjects()->Data[41249];

    UOnlinePlaylistManager_execReadPlaylistPopulation_Parms
        ReadPlaylistPopulation_Parms;

    this->ProcessEvent(pFnReadPlaylistPopulation, &ReadPlaylistPopulation_Parms,
                       NULL);
};

// Function IpDrv.OnlinePlaylistManager.Reset
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::Reset() {
    static UFunction* pFnReset = NULL;

    if (!pFnReset) pFnReset = (UFunction*)UObject::GObjObjects()->Data[41247];

    UOnlinePlaylistManager_execReset_Parms Reset_Parms;

    this->ProcessEvent(pFnReset, &Reset_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetContentIdsFromPlaylist
// [0x00420002]
// Parameters infos:

void UOnlinePlaylistManager::GetContentIdsFromPlaylist() {
    static UFunction* pFnGetContentIdsFromPlaylist = NULL;

    if (!pFnGetContentIdsFromPlaylist)
        pFnGetContentIdsFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41242];

    UOnlinePlaylistManager_execGetContentIdsFromPlaylist_Parms
        GetContentIdsFromPlaylist_Parms;

    this->ProcessEvent(pFnGetContentIdsFromPlaylist,
                       &GetContentIdsFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetInventorySwapFromPlaylist
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::GetInventorySwapFromPlaylist() {
    static UFunction* pFnGetInventorySwapFromPlaylist = NULL;

    if (!pFnGetInventorySwapFromPlaylist)
        pFnGetInventorySwapFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41236];

    UOnlinePlaylistManager_execGetInventorySwapFromPlaylist_Parms
        GetInventorySwapFromPlaylist_Parms;

    this->ProcessEvent(pFnGetInventorySwapFromPlaylist,
                       &GetInventorySwapFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetMapCycleFromPlaylist
// [0x00420002]
// Parameters infos:

void UOnlinePlaylistManager::GetMapCycleFromPlaylist() {
    static UFunction* pFnGetMapCycleFromPlaylist = NULL;

    if (!pFnGetMapCycleFromPlaylist)
        pFnGetMapCycleFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41231];

    UOnlinePlaylistManager_execGetMapCycleFromPlaylist_Parms
        GetMapCycleFromPlaylist_Parms;

    this->ProcessEvent(pFnGetMapCycleFromPlaylist,
                       &GetMapCycleFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetUrlFromPlaylist
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::GetUrlFromPlaylist() {
    static UFunction* pFnGetUrlFromPlaylist = NULL;

    if (!pFnGetUrlFromPlaylist)
        pFnGetUrlFromPlaylist = (UFunction*)UObject::GObjObjects()->Data[41227];

    UOnlinePlaylistManager_execGetUrlFromPlaylist_Parms
        GetUrlFromPlaylist_Parms;

    this->ProcessEvent(pFnGetUrlFromPlaylist, &GetUrlFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetMatchType
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::GetMatchType() {
    static UFunction* pFnGetMatchType = NULL;

    if (!pFnGetMatchType)
        pFnGetMatchType = (UFunction*)UObject::GObjObjects()->Data[41223];

    UOnlinePlaylistManager_execGetMatchType_Parms GetMatchType_Parms;

    this->ProcessEvent(pFnGetMatchType, &GetMatchType_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.IsPlaylistArbitrated
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::IsPlaylistArbitrated() {
    static UFunction* pFnIsPlaylistArbitrated = NULL;

    if (!pFnIsPlaylistArbitrated)
        pFnIsPlaylistArbitrated =
            (UFunction*)UObject::GObjObjects()->Data[41219];

    UOnlinePlaylistManager_execIsPlaylistArbitrated_Parms
        IsPlaylistArbitrated_Parms;

    this->ProcessEvent(pFnIsPlaylistArbitrated, &IsPlaylistArbitrated_Parms,
                       NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetLoadBalanceIdFromPlaylist
// [0x00420002]
// Parameters infos:

void UOnlinePlaylistManager::GetLoadBalanceIdFromPlaylist() {
    static UFunction* pFnGetLoadBalanceIdFromPlaylist = NULL;

    if (!pFnGetLoadBalanceIdFromPlaylist)
        pFnGetLoadBalanceIdFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41215];

    UOnlinePlaylistManager_execGetLoadBalanceIdFromPlaylist_Parms
        GetLoadBalanceIdFromPlaylist_Parms;

    this->ProcessEvent(pFnGetLoadBalanceIdFromPlaylist,
                       &GetLoadBalanceIdFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetTeamInfoFromPlaylist
// [0x00420002]
// Parameters infos:

void UOnlinePlaylistManager::GetTeamInfoFromPlaylist() {
    static UFunction* pFnGetTeamInfoFromPlaylist = NULL;

    if (!pFnGetTeamInfoFromPlaylist)
        pFnGetTeamInfoFromPlaylist =
            (UFunction*)UObject::GObjObjects()->Data[41209];

    UOnlinePlaylistManager_execGetTeamInfoFromPlaylist_Parms
        GetTeamInfoFromPlaylist_Parms;

    this->ProcessEvent(pFnGetTeamInfoFromPlaylist,
                       &GetTeamInfoFromPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.PlaylistSupportsDedicatedServers
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::PlaylistSupportsDedicatedServers() {
    static UFunction* pFnPlaylistSupportsDedicatedServers = NULL;

    if (!pFnPlaylistSupportsDedicatedServers)
        pFnPlaylistSupportsDedicatedServers =
            (UFunction*)UObject::GObjObjects()->Data[41205];

    UOnlinePlaylistManager_execPlaylistSupportsDedicatedServers_Parms
        PlaylistSupportsDedicatedServers_Parms;

    this->ProcessEvent(pFnPlaylistSupportsDedicatedServers,
                       &PlaylistSupportsDedicatedServers_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.HasAnyGameSettings
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::HasAnyGameSettings() {
    static UFunction* pFnHasAnyGameSettings = NULL;

    if (!pFnHasAnyGameSettings)
        pFnHasAnyGameSettings = (UFunction*)UObject::GObjObjects()->Data[41200];

    UOnlinePlaylistManager_execHasAnyGameSettings_Parms
        HasAnyGameSettings_Parms;

    this->ProcessEvent(pFnHasAnyGameSettings, &HasAnyGameSettings_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.GetGameSettings
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::GetGameSettings() {
    static UFunction* pFnGetGameSettings = NULL;

    if (!pFnGetGameSettings)
        pFnGetGameSettings = (UFunction*)UObject::GObjObjects()->Data[41194];

    UOnlinePlaylistManager_execGetGameSettings_Parms GetGameSettings_Parms;

    this->ProcessEvent(pFnGetGameSettings, &GetGameSettings_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.FinalizePlaylistObjects
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlinePlaylistManager::FinalizePlaylistObjects() {
    static UFunction* pFnFinalizePlaylistObjects = NULL;

    if (!pFnFinalizePlaylistObjects)
        pFnFinalizePlaylistObjects =
            (UFunction*)UObject::GObjObjects()->Data[41193];

    UOnlinePlaylistManager_execFinalizePlaylistObjects_Parms
        FinalizePlaylistObjects_Parms;

    pFnFinalizePlaylistObjects->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFinalizePlaylistObjects,
                       &FinalizePlaylistObjects_Parms, NULL);

    pFnFinalizePlaylistObjects->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlinePlaylistManager.OnReadTitleFileComplete
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::OnReadTitleFileComplete() {
    static UFunction* pFnOnReadTitleFileComplete = NULL;

    if (!pFnOnReadTitleFileComplete)
        pFnOnReadTitleFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[41188];

    UOnlinePlaylistManager_execOnReadTitleFileComplete_Parms
        OnReadTitleFileComplete_Parms;

    this->ProcessEvent(pFnOnReadTitleFileComplete,
                       &OnReadTitleFileComplete_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.ShouldRefreshPlaylists
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlinePlaylistManager::ShouldRefreshPlaylists() {
    static UFunction* pFnShouldRefreshPlaylists = NULL;

    if (!pFnShouldRefreshPlaylists)
        pFnShouldRefreshPlaylists =
            (UFunction*)UObject::GObjObjects()->Data[41186];

    UOnlinePlaylistManager_execShouldRefreshPlaylists_Parms
        ShouldRefreshPlaylists_Parms;

    pFnShouldRefreshPlaylists->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnShouldRefreshPlaylists, &ShouldRefreshPlaylists_Parms,
                       NULL);

    pFnShouldRefreshPlaylists->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlinePlaylistManager.DetermineFilesToDownload
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UOnlinePlaylistManager::DetermineFilesToDownload() {
    static UFunction* pFnDetermineFilesToDownload = NULL;

    if (!pFnDetermineFilesToDownload)
        pFnDetermineFilesToDownload =
            (UFunction*)UObject::GObjObjects()->Data[41185];

    UOnlinePlaylistManager_execDetermineFilesToDownload_Parms
        DetermineFilesToDownload_Parms;

    pFnDetermineFilesToDownload->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDetermineFilesToDownload,
                       &DetermineFilesToDownload_Parms, NULL);

    pFnDetermineFilesToDownload->FunctionFlags |= 0x400;
};

// Function IpDrv.OnlinePlaylistManager.DownloadPlaylist
// [0x00020002]
// Parameters infos:

void UOnlinePlaylistManager::DownloadPlaylist() {
    static UFunction* pFnDownloadPlaylist = NULL;

    if (!pFnDownloadPlaylist)
        pFnDownloadPlaylist = (UFunction*)UObject::GObjObjects()->Data[41182];

    UOnlinePlaylistManager_execDownloadPlaylist_Parms DownloadPlaylist_Parms;

    this->ProcessEvent(pFnDownloadPlaylist, &DownloadPlaylist_Parms, NULL);
};

// Function IpDrv.OnlinePlaylistManager.OnReadPlaylistComplete
// [0x00120000]
// Parameters infos:

void UOnlinePlaylistManager::OnReadPlaylistComplete() {
    static UFunction* pFnOnReadPlaylistComplete = NULL;

    if (!pFnOnReadPlaylistComplete)
        pFnOnReadPlaylistComplete =
            (UFunction*)UObject::GObjObjects()->Data[41180];

    UOnlinePlaylistManager_execOnReadPlaylistComplete_Parms
        OnReadPlaylistComplete_Parms;

    this->ProcessEvent(pFnOnReadPlaylistComplete, &OnReadPlaylistComplete_Parms,
                       NULL);
};

// Function IpDrv.PartyBeacon.OnDestroyComplete
// [0x00120000]
// Parameters infos:

void UPartyBeacon::OnDestroyComplete() {
    static UFunction* pFnOnDestroyComplete = NULL;

    if (!pFnOnDestroyComplete)
        pFnOnDestroyComplete = (UFunction*)UObject::GObjObjects()->Data[41351];

    UPartyBeacon_execOnDestroyComplete_Parms OnDestroyComplete_Parms;

    this->ProcessEvent(pFnOnDestroyComplete, &OnDestroyComplete_Parms, NULL);
};

// Function IpDrv.PartyBeacon.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UPartyBeacon::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[41350];

    UPartyBeacon_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconClient.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UPartyBeaconClient::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[41393];

    UPartyBeaconClient_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconClient.CancelReservation
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconClient::CancelReservation() {
    static UFunction* pFnCancelReservation = NULL;

    if (!pFnCancelReservation)
        pFnCancelReservation = (UFunction*)UObject::GObjObjects()->Data[41390];

    UPartyBeaconClient_execCancelReservation_Parms CancelReservation_Parms;

    pFnCancelReservation->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnCancelReservation, &CancelReservation_Parms, NULL);

    pFnCancelReservation->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconClient.RequestReservationUpdate
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconClient::RequestReservationUpdate() {
    static UFunction* pFnRequestReservationUpdate = NULL;

    if (!pFnRequestReservationUpdate)
        pFnRequestReservationUpdate =
            (UFunction*)UObject::GObjObjects()->Data[41384];

    UPartyBeaconClient_execRequestReservationUpdate_Parms
        RequestReservationUpdate_Parms;

    pFnRequestReservationUpdate->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnRequestReservationUpdate,
                       &RequestReservationUpdate_Parms, NULL);

    pFnRequestReservationUpdate->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconClient.RequestReservation
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconClient::RequestReservation() {
    static UFunction* pFnRequestReservation = NULL;

    if (!pFnRequestReservation)
        pFnRequestReservation = (UFunction*)UObject::GObjObjects()->Data[41378];

    UPartyBeaconClient_execRequestReservation_Parms RequestReservation_Parms;

    pFnRequestReservation->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnRequestReservation, &RequestReservation_Parms, NULL);

    pFnRequestReservation->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconClient.OnHostHasCancelled
// [0x00120000]
// Parameters infos:

void UPartyBeaconClient::OnHostHasCancelled() {
    static UFunction* pFnOnHostHasCancelled = NULL;

    if (!pFnOnHostHasCancelled)
        pFnOnHostHasCancelled = (UFunction*)UObject::GObjObjects()->Data[41377];

    UPartyBeaconClient_execOnHostHasCancelled_Parms OnHostHasCancelled_Parms;

    this->ProcessEvent(pFnOnHostHasCancelled, &OnHostHasCancelled_Parms, NULL);
};

// Function IpDrv.PartyBeaconClient.OnHostIsReady
// [0x00120000]
// Parameters infos:

void UPartyBeaconClient::OnHostIsReady() {
    static UFunction* pFnOnHostIsReady = NULL;

    if (!pFnOnHostIsReady)
        pFnOnHostIsReady = (UFunction*)UObject::GObjObjects()->Data[41376];

    UPartyBeaconClient_execOnHostIsReady_Parms OnHostIsReady_Parms;

    this->ProcessEvent(pFnOnHostIsReady, &OnHostIsReady_Parms, NULL);
};

// Function IpDrv.PartyBeaconClient.OnTravelRequestReceived
// [0x00120000]
// Parameters infos:

void UPartyBeaconClient::OnTravelRequestReceived() {
    static UFunction* pFnOnTravelRequestReceived = NULL;

    if (!pFnOnTravelRequestReceived)
        pFnOnTravelRequestReceived =
            (UFunction*)UObject::GObjObjects()->Data[41372];

    UPartyBeaconClient_execOnTravelRequestReceived_Parms
        OnTravelRequestReceived_Parms;

    this->ProcessEvent(pFnOnTravelRequestReceived,
                       &OnTravelRequestReceived_Parms, NULL);
};

// Function IpDrv.PartyBeaconClient.OnReservationCountUpdated
// [0x00120000]
// Parameters infos:

void UPartyBeaconClient::OnReservationCountUpdated() {
    static UFunction* pFnOnReservationCountUpdated = NULL;

    if (!pFnOnReservationCountUpdated)
        pFnOnReservationCountUpdated =
            (UFunction*)UObject::GObjObjects()->Data[41370];

    UPartyBeaconClient_execOnReservationCountUpdated_Parms
        OnReservationCountUpdated_Parms;

    this->ProcessEvent(pFnOnReservationCountUpdated,
                       &OnReservationCountUpdated_Parms, NULL);
};

// Function IpDrv.PartyBeaconClient.OnReservationRequestComplete
// [0x00120000]
// Parameters infos:

void UPartyBeaconClient::OnReservationRequestComplete() {
    static UFunction* pFnOnReservationRequestComplete = NULL;

    if (!pFnOnReservationRequestComplete)
        pFnOnReservationRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[41368];

    UPartyBeaconClient_execOnReservationRequestComplete_Parms
        OnReservationRequestComplete_Parms;

    this->ProcessEvent(pFnOnReservationRequestComplete,
                       &OnReservationRequestComplete_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.DumpReservations
// [0x00820002]
// Parameters infos:

void UPartyBeaconHost::DumpReservations() {
    static UFunction* pFnDumpReservations = NULL;

    if (!pFnDumpReservations)
        pFnDumpReservations = (UFunction*)UObject::GObjObjects()->Data[41489];

    UPartyBeaconHost_execDumpReservations_Parms DumpReservations_Parms;

    this->ProcessEvent(pFnDumpReservations, &DumpReservations_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.GetMaxAvailableTeamSize
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::GetMaxAvailableTeamSize() {
    static UFunction* pFnGetMaxAvailableTeamSize = NULL;

    if (!pFnGetMaxAvailableTeamSize)
        pFnGetMaxAvailableTeamSize =
            (UFunction*)UObject::GObjObjects()->Data[41487];

    UPartyBeaconHost_execGetMaxAvailableTeamSize_Parms
        GetMaxAvailableTeamSize_Parms;

    pFnGetMaxAvailableTeamSize->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetMaxAvailableTeamSize,
                       &GetMaxAvailableTeamSize_Parms, NULL);

    pFnGetMaxAvailableTeamSize->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.GetPartyLeaders
// [0x00420002]
// Parameters infos:

void UPartyBeaconHost::GetPartyLeaders() {
    static UFunction* pFnGetPartyLeaders = NULL;

    if (!pFnGetPartyLeaders)
        pFnGetPartyLeaders = (UFunction*)UObject::GObjObjects()->Data[41483];

    UPartyBeaconHost_execGetPartyLeaders_Parms GetPartyLeaders_Parms;

    this->ProcessEvent(pFnGetPartyLeaders, &GetPartyLeaders_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.GetPlayers
// [0x00C20002]
// Parameters infos:

void UPartyBeaconHost::GetPlayers() {
    static UFunction* pFnGetPlayers = NULL;

    if (!pFnGetPlayers)
        pFnGetPlayers = (UFunction*)UObject::GObjObjects()->Data[41477];

    UPartyBeaconHost_execGetPlayers_Parms GetPlayers_Parms;

    this->ProcessEvent(pFnGetPlayers, &GetPlayers_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.AppendReservationSkillsToSearch
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::AppendReservationSkillsToSearch() {
    static UFunction* pFnAppendReservationSkillsToSearch = NULL;

    if (!pFnAppendReservationSkillsToSearch)
        pFnAppendReservationSkillsToSearch =
            (UFunction*)UObject::GObjObjects()->Data[41475];

    UPartyBeaconHost_execAppendReservationSkillsToSearch_Parms
        AppendReservationSkillsToSearch_Parms;

    pFnAppendReservationSkillsToSearch->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAppendReservationSkillsToSearch,
                       &AppendReservationSkillsToSearch_Parms, NULL);

    pFnAppendReservationSkillsToSearch->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.UnregisterParty
// [0x00820802] ( FUNC_Event )
// Parameters infos:

void UPartyBeaconHost::eventUnregisterParty() {
    static UFunction* pFnUnregisterParty = NULL;

    if (!pFnUnregisterParty)
        pFnUnregisterParty = (UFunction*)UObject::GObjObjects()->Data[41469];

    UPartyBeaconHost_eventUnregisterParty_Parms UnregisterParty_Parms;

    this->ProcessEvent(pFnUnregisterParty, &UnregisterParty_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.UnregisterPartyMembers
// [0x00820802] ( FUNC_Event )
// Parameters infos:

void UPartyBeaconHost::eventUnregisterPartyMembers() {
    static UFunction* pFnUnregisterPartyMembers = NULL;

    if (!pFnUnregisterPartyMembers)
        pFnUnregisterPartyMembers =
            (UFunction*)UObject::GObjObjects()->Data[41464];

    UPartyBeaconHost_eventUnregisterPartyMembers_Parms
        UnregisterPartyMembers_Parms;

    this->ProcessEvent(pFnUnregisterPartyMembers, &UnregisterPartyMembers_Parms,
                       NULL);
};

// Function IpDrv.PartyBeaconHost.RegisterPartyMembers
// [0x00820802] ( FUNC_Event )
// Parameters infos:

void UPartyBeaconHost::eventRegisterPartyMembers() {
    static UFunction* pFnRegisterPartyMembers = NULL;

    if (!pFnRegisterPartyMembers)
        pFnRegisterPartyMembers =
            (UFunction*)UObject::GObjObjects()->Data[41456];

    UPartyBeaconHost_eventRegisterPartyMembers_Parms RegisterPartyMembers_Parms;

    this->ProcessEvent(pFnRegisterPartyMembers, &RegisterPartyMembers_Parms,
                       NULL);
};

// Function IpDrv.PartyBeaconHost.AreReservationsFull
// [0x00020002]
// Parameters infos:

void UPartyBeaconHost::AreReservationsFull() {
    static UFunction* pFnAreReservationsFull = NULL;

    if (!pFnAreReservationsFull)
        pFnAreReservationsFull =
            (UFunction*)UObject::GObjObjects()->Data[41454];

    UPartyBeaconHost_execAreReservationsFull_Parms AreReservationsFull_Parms;

    this->ProcessEvent(pFnAreReservationsFull, &AreReservationsFull_Parms,
                       NULL);
};

// Function IpDrv.PartyBeaconHost.TellClientsHostHasCancelled
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::TellClientsHostHasCancelled() {
    static UFunction* pFnTellClientsHostHasCancelled = NULL;

    if (!pFnTellClientsHostHasCancelled)
        pFnTellClientsHostHasCancelled =
            (UFunction*)UObject::GObjObjects()->Data[41453];

    UPartyBeaconHost_execTellClientsHostHasCancelled_Parms
        TellClientsHostHasCancelled_Parms;

    pFnTellClientsHostHasCancelled->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnTellClientsHostHasCancelled,
                       &TellClientsHostHasCancelled_Parms, NULL);

    pFnTellClientsHostHasCancelled->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.TellClientsHostIsReady
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::TellClientsHostIsReady() {
    static UFunction* pFnTellClientsHostIsReady = NULL;

    if (!pFnTellClientsHostIsReady)
        pFnTellClientsHostIsReady =
            (UFunction*)UObject::GObjObjects()->Data[41452];

    UPartyBeaconHost_execTellClientsHostIsReady_Parms
        TellClientsHostIsReady_Parms;

    pFnTellClientsHostIsReady->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnTellClientsHostIsReady, &TellClientsHostIsReady_Parms,
                       NULL);

    pFnTellClientsHostIsReady->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.TellClientsToTravel
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::TellClientsToTravel() {
    static UFunction* pFnTellClientsToTravel = NULL;

    if (!pFnTellClientsToTravel)
        pFnTellClientsToTravel =
            (UFunction*)UObject::GObjObjects()->Data[41448];

    UPartyBeaconHost_execTellClientsToTravel_Parms TellClientsToTravel_Parms;

    pFnTellClientsToTravel->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnTellClientsToTravel, &TellClientsToTravel_Parms,
                       NULL);

    pFnTellClientsToTravel->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.DestroyBeacon
// [0x00020C00] ( FUNC_Event | FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::eventDestroyBeacon() {
    static UFunction* pFnDestroyBeacon = NULL;

    if (!pFnDestroyBeacon)
        pFnDestroyBeacon = (UFunction*)UObject::GObjObjects()->Data[41447];

    UPartyBeaconHost_eventDestroyBeacon_Parms DestroyBeacon_Parms;

    pFnDestroyBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDestroyBeacon, &DestroyBeacon_Parms, NULL);

    pFnDestroyBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.OnClientCancellationReceived
// [0x00120000]
// Parameters infos:

void UPartyBeaconHost::OnClientCancellationReceived() {
    static UFunction* pFnOnClientCancellationReceived = NULL;

    if (!pFnOnClientCancellationReceived)
        pFnOnClientCancellationReceived =
            (UFunction*)UObject::GObjObjects()->Data[41445];

    UPartyBeaconHost_execOnClientCancellationReceived_Parms
        OnClientCancellationReceived_Parms;

    this->ProcessEvent(pFnOnClientCancellationReceived,
                       &OnClientCancellationReceived_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.OnReservationsFull
// [0x00120000]
// Parameters infos:

void UPartyBeaconHost::OnReservationsFull() {
    static UFunction* pFnOnReservationsFull = NULL;

    if (!pFnOnReservationsFull)
        pFnOnReservationsFull = (UFunction*)UObject::GObjObjects()->Data[41444];

    UPartyBeaconHost_execOnReservationsFull_Parms OnReservationsFull_Parms;

    this->ProcessEvent(pFnOnReservationsFull, &OnReservationsFull_Parms, NULL);
};

// Function IpDrv.PartyBeaconHost.OnReservationChange
// [0x00120000]
// Parameters infos:

void UPartyBeaconHost::OnReservationChange() {
    static UFunction* pFnOnReservationChange = NULL;

    if (!pFnOnReservationChange)
        pFnOnReservationChange =
            (UFunction*)UObject::GObjObjects()->Data[41443];

    UPartyBeaconHost_execOnReservationChange_Parms OnReservationChange_Parms;

    this->ProcessEvent(pFnOnReservationChange, &OnReservationChange_Parms,
                       NULL);
};

// Function IpDrv.PartyBeaconHost.HandlePlayerLogout
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::HandlePlayerLogout() {
    static UFunction* pFnHandlePlayerLogout = NULL;

    if (!pFnHandlePlayerLogout)
        pFnHandlePlayerLogout = (UFunction*)UObject::GObjObjects()->Data[41440];

    UPartyBeaconHost_execHandlePlayerLogout_Parms HandlePlayerLogout_Parms;

    pFnHandlePlayerLogout->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnHandlePlayerLogout, &HandlePlayerLogout_Parms, NULL);

    pFnHandlePlayerLogout->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.GetExistingReservation
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::GetExistingReservation() {
    static UFunction* pFnGetExistingReservation = NULL;

    if (!pFnGetExistingReservation)
        pFnGetExistingReservation =
            (UFunction*)UObject::GObjObjects()->Data[41437];

    UPartyBeaconHost_execGetExistingReservation_Parms
        GetExistingReservation_Parms;

    pFnGetExistingReservation->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetExistingReservation, &GetExistingReservation_Parms,
                       NULL);

    pFnGetExistingReservation->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.UpdatePartyReservationEntry
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::UpdatePartyReservationEntry() {
    static UFunction* pFnUpdatePartyReservationEntry = NULL;

    if (!pFnUpdatePartyReservationEntry)
        pFnUpdatePartyReservationEntry =
            (UFunction*)UObject::GObjObjects()->Data[41432];

    UPartyBeaconHost_execUpdatePartyReservationEntry_Parms
        UpdatePartyReservationEntry_Parms;

    pFnUpdatePartyReservationEntry->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnUpdatePartyReservationEntry,
                       &UpdatePartyReservationEntry_Parms, NULL);

    pFnUpdatePartyReservationEntry->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.AddPartyReservationEntry
// [0x00420400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::AddPartyReservationEntry() {
    static UFunction* pFnAddPartyReservationEntry = NULL;

    if (!pFnAddPartyReservationEntry)
        pFnAddPartyReservationEntry =
            (UFunction*)UObject::GObjObjects()->Data[41425];

    UPartyBeaconHost_execAddPartyReservationEntry_Parms
        AddPartyReservationEntry_Parms;

    pFnAddPartyReservationEntry->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAddPartyReservationEntry,
                       &AddPartyReservationEntry_Parms, NULL);

    pFnAddPartyReservationEntry->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.InitHostBeacon
// [0x00024400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::InitHostBeacon() {
    static UFunction* pFnInitHostBeacon = NULL;

    if (!pFnInitHostBeacon)
        pFnInitHostBeacon = (UFunction*)UObject::GObjObjects()->Data[41418];

    UPartyBeaconHost_execInitHostBeacon_Parms InitHostBeacon_Parms;

    pFnInitHostBeacon->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnInitHostBeacon, &InitHostBeacon_Parms, NULL);

    pFnInitHostBeacon->FunctionFlags |= 0x400;
};

// Function IpDrv.PartyBeaconHost.PauseReservationRequests
// [0x00020400] ( FUNC_Native )
// Parameters infos:

void UPartyBeaconHost::PauseReservationRequests() {
    static UFunction* pFnPauseReservationRequests = NULL;

    if (!pFnPauseReservationRequests)
        pFnPauseReservationRequests =
            (UFunction*)UObject::GObjObjects()->Data[41416];

    UPartyBeaconHost_execPauseReservationRequests_Parms
        PauseReservationRequests_Parms;

    pFnPauseReservationRequests->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnPauseReservationRequests,
                       &PauseReservationRequests_Parms, NULL);

    pFnPauseReservationRequests->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetHexDigit
// [0x00020002]
// Parameters infos:

void UWebRequest::GetHexDigit() {
    static UFunction* pFnGetHexDigit = NULL;

    if (!pFnGetHexDigit)
        pFnGetHexDigit = (UFunction*)UObject::GObjObjects()->Data[41731];

    UWebRequest_execGetHexDigit_Parms GetHexDigit_Parms;

    this->ProcessEvent(pFnGetHexDigit, &GetHexDigit_Parms, NULL);
};

// Function IpDrv.WebRequest.DecodeFormData
// [0x00020002]
// Parameters infos:

void UWebRequest::DecodeFormData() {
    static UFunction* pFnDecodeFormData = NULL;

    if (!pFnDecodeFormData)
        pFnDecodeFormData = (UFunction*)UObject::GObjObjects()->Data[41722];

    UWebRequest_execDecodeFormData_Parms DecodeFormData_Parms;

    this->ProcessEvent(pFnDecodeFormData, &DecodeFormData_Parms, NULL);
};

// Function IpDrv.WebRequest.ProcessHeaderString
// [0x00020002]
// Parameters infos:

void UWebRequest::ProcessHeaderString() {
    static UFunction* pFnProcessHeaderString = NULL;

    if (!pFnProcessHeaderString)
        pFnProcessHeaderString =
            (UFunction*)UObject::GObjObjects()->Data[41719];

    UWebRequest_execProcessHeaderString_Parms ProcessHeaderString_Parms;

    this->ProcessEvent(pFnProcessHeaderString, &ProcessHeaderString_Parms,
                       NULL);
};

// Function IpDrv.WebRequest.Dump
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::Dump() {
    static UFunction* pFnDump = NULL;

    if (!pFnDump) pFnDump = (UFunction*)UObject::GObjObjects()->Data[41718];

    UWebRequest_execDump_Parms Dump_Parms;

    pFnDump->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDump, &Dump_Parms, NULL);

    pFnDump->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetVariables
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetVariables() {
    static UFunction* pFnGetVariables = NULL;

    if (!pFnGetVariables)
        pFnGetVariables = (UFunction*)UObject::GObjObjects()->Data[41715];

    UWebRequest_execGetVariables_Parms GetVariables_Parms;

    pFnGetVariables->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetVariables, &GetVariables_Parms, NULL);

    pFnGetVariables->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetVariableNumber
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetVariableNumber() {
    static UFunction* pFnGetVariableNumber = NULL;

    if (!pFnGetVariableNumber)
        pFnGetVariableNumber = (UFunction*)UObject::GObjObjects()->Data[37896];

    UWebRequest_execGetVariableNumber_Parms GetVariableNumber_Parms;

    pFnGetVariableNumber->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetVariableNumber, &GetVariableNumber_Parms, NULL);

    pFnGetVariableNumber->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetVariableCount
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetVariableCount() {
    static UFunction* pFnGetVariableCount = NULL;

    if (!pFnGetVariableCount)
        pFnGetVariableCount = (UFunction*)UObject::GObjObjects()->Data[37894];

    UWebRequest_execGetVariableCount_Parms GetVariableCount_Parms;

    pFnGetVariableCount->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetVariableCount, &GetVariableCount_Parms, NULL);

    pFnGetVariableCount->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetVariable
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetVariable() {
    static UFunction* pFnGetVariable = NULL;

    if (!pFnGetVariable)
        pFnGetVariable = (UFunction*)UObject::GObjObjects()->Data[37892];

    UWebRequest_execGetVariable_Parms GetVariable_Parms;

    pFnGetVariable->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetVariable, &GetVariable_Parms, NULL);

    pFnGetVariable->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.AddVariable
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::AddVariable() {
    static UFunction* pFnAddVariable = NULL;

    if (!pFnAddVariable)
        pFnAddVariable = (UFunction*)UObject::GObjObjects()->Data[41706];

    UWebRequest_execAddVariable_Parms AddVariable_Parms;

    pFnAddVariable->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAddVariable, &AddVariable_Parms, NULL);

    pFnAddVariable->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetHeaders
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetHeaders() {
    static UFunction* pFnGetHeaders = NULL;

    if (!pFnGetHeaders)
        pFnGetHeaders = (UFunction*)UObject::GObjObjects()->Data[41703];

    UWebRequest_execGetHeaders_Parms GetHeaders_Parms;

    pFnGetHeaders->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetHeaders, &GetHeaders_Parms, NULL);

    pFnGetHeaders->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.GetHeader
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::GetHeader() {
    static UFunction* pFnGetHeader = NULL;

    if (!pFnGetHeader)
        pFnGetHeader = (UFunction*)UObject::GObjObjects()->Data[41699];

    UWebRequest_execGetHeader_Parms GetHeader_Parms;

    pFnGetHeader->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetHeader, &GetHeader_Parms, NULL);

    pFnGetHeader->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.AddHeader
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::AddHeader() {
    static UFunction* pFnAddHeader = NULL;

    if (!pFnAddHeader)
        pFnAddHeader = (UFunction*)UObject::GObjObjects()->Data[41696];

    UWebRequest_execAddHeader_Parms AddHeader_Parms;

    pFnAddHeader->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnAddHeader, &AddHeader_Parms, NULL);

    pFnAddHeader->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.EncodeBase64
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::EncodeBase64() {
    static UFunction* pFnEncodeBase64 = NULL;

    if (!pFnEncodeBase64)
        pFnEncodeBase64 = (UFunction*)UObject::GObjObjects()->Data[41693];

    UWebRequest_execEncodeBase64_Parms EncodeBase64_Parms;

    pFnEncodeBase64->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnEncodeBase64, &EncodeBase64_Parms, NULL);

    pFnEncodeBase64->FunctionFlags |= 0x400;
};

// Function IpDrv.WebRequest.DecodeBase64
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebRequest::DecodeBase64() {
    static UFunction* pFnDecodeBase64 = NULL;

    if (!pFnDecodeBase64)
        pFnDecodeBase64 = (UFunction*)UObject::GObjObjects()->Data[41690];

    UWebRequest_execDecodeBase64_Parms DecodeBase64_Parms;

    pFnDecodeBase64->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDecodeBase64, &DecodeBase64_Parms, NULL);

    pFnDecodeBase64->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.SentResponse
// [0x00020002]
// Parameters infos:

void UWebResponse::SentResponse() {
    static UFunction* pFnSentResponse = NULL;

    if (!pFnSentResponse)
        pFnSentResponse = (UFunction*)UObject::GObjObjects()->Data[41790];

    UWebResponse_execSentResponse_Parms SentResponse_Parms;

    this->ProcessEvent(pFnSentResponse, &SentResponse_Parms, NULL);
};

// Function IpDrv.WebResponse.SentText
// [0x00020002]
// Parameters infos:

void UWebResponse::SentText() {
    static UFunction* pFnSentText = NULL;

    if (!pFnSentText)
        pFnSentText = (UFunction*)UObject::GObjObjects()->Data[41788];

    UWebResponse_execSentText_Parms SentText_Parms;

    this->ProcessEvent(pFnSentText, &SentText_Parms, NULL);
};

// Function IpDrv.WebResponse.Redirect
// [0x00020002]
// Parameters infos:

void UWebResponse::Redirect() {
    static UFunction* pFnRedirect = NULL;

    if (!pFnRedirect)
        pFnRedirect = (UFunction*)UObject::GObjObjects()->Data[41786];

    UWebResponse_execRedirect_Parms Redirect_Parms;

    this->ProcessEvent(pFnRedirect, &Redirect_Parms, NULL);
};

// Function IpDrv.WebResponse.SendStandardHeaders
// [0x00024002]
// Parameters infos:

void UWebResponse::SendStandardHeaders() {
    static UFunction* pFnSendStandardHeaders = NULL;

    if (!pFnSendStandardHeaders)
        pFnSendStandardHeaders =
            (UFunction*)UObject::GObjObjects()->Data[41783];

    UWebResponse_execSendStandardHeaders_Parms SendStandardHeaders_Parms;

    this->ProcessEvent(pFnSendStandardHeaders, &SendStandardHeaders_Parms,
                       NULL);
};

// Function IpDrv.WebResponse.HTTPError
// [0x00024002]
// Parameters infos:

void UWebResponse::HTTPError() {
    static UFunction* pFnHTTPError = NULL;

    if (!pFnHTTPError)
        pFnHTTPError = (UFunction*)UObject::GObjObjects()->Data[41780];

    UWebResponse_execHTTPError_Parms HTTPError_Parms;

    this->ProcessEvent(pFnHTTPError, &HTTPError_Parms, NULL);
};

// Function IpDrv.WebResponse.SendHeaders
// [0x00020002]
// Parameters infos:

void UWebResponse::SendHeaders() {
    static UFunction* pFnSendHeaders = NULL;

    if (!pFnSendHeaders)
        pFnSendHeaders = (UFunction*)UObject::GObjObjects()->Data[41778];

    UWebResponse_execSendHeaders_Parms SendHeaders_Parms;

    this->ProcessEvent(pFnSendHeaders, &SendHeaders_Parms, NULL);
};

// Function IpDrv.WebResponse.AddHeader
// [0x00024002]
// Parameters infos:

void UWebResponse::AddHeader() {
    static UFunction* pFnAddHeader = NULL;

    if (!pFnAddHeader)
        pFnAddHeader = (UFunction*)UObject::GObjObjects()->Data[41771];

    UWebResponse_execAddHeader_Parms AddHeader_Parms;

    this->ProcessEvent(pFnAddHeader, &AddHeader_Parms, NULL);
};

// Function IpDrv.WebResponse.HTTPHeader
// [0x00020002]
// Parameters infos:

void UWebResponse::HTTPHeader() {
    static UFunction* pFnHTTPHeader = NULL;

    if (!pFnHTTPHeader)
        pFnHTTPHeader = (UFunction*)UObject::GObjObjects()->Data[41769];

    UWebResponse_execHTTPHeader_Parms HTTPHeader_Parms;

    this->ProcessEvent(pFnHTTPHeader, &HTTPHeader_Parms, NULL);
};

// Function IpDrv.WebResponse.HttpResponse
// [0x00020002]
// Parameters infos:

void UWebResponse::HttpResponse() {
    static UFunction* pFnHttpResponse = NULL;

    if (!pFnHttpResponse)
        pFnHttpResponse = (UFunction*)UObject::GObjObjects()->Data[41767];

    UWebResponse_execHttpResponse_Parms HttpResponse_Parms;

    this->ProcessEvent(pFnHttpResponse, &HttpResponse_Parms, NULL);
};

// Function IpDrv.WebResponse.FailAuthentication
// [0x00020002]
// Parameters infos:

void UWebResponse::FailAuthentication() {
    static UFunction* pFnFailAuthentication = NULL;

    if (!pFnFailAuthentication)
        pFnFailAuthentication = (UFunction*)UObject::GObjObjects()->Data[41765];

    UWebResponse_execFailAuthentication_Parms FailAuthentication_Parms;

    this->ProcessEvent(pFnFailAuthentication, &FailAuthentication_Parms, NULL);
};

// Function IpDrv.WebResponse.SendCachedFile
// [0x00024002]
// Parameters infos:

void UWebResponse::SendCachedFile() {
    static UFunction* pFnSendCachedFile = NULL;

    if (!pFnSendCachedFile)
        pFnSendCachedFile = (UFunction*)UObject::GObjObjects()->Data[41761];

    UWebResponse_execSendCachedFile_Parms SendCachedFile_Parms;

    this->ProcessEvent(pFnSendCachedFile, &SendCachedFile_Parms, NULL);
};

// Function IpDrv.WebResponse.SendBinary
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UWebResponse::eventSendBinary() {
    static UFunction* pFnSendBinary = NULL;

    if (!pFnSendBinary)
        pFnSendBinary = (UFunction*)UObject::GObjObjects()->Data[41758];

    UWebResponse_eventSendBinary_Parms SendBinary_Parms;

    this->ProcessEvent(pFnSendBinary, &SendBinary_Parms, NULL);
};

// Function IpDrv.WebResponse.SendText
// [0x00024802] ( FUNC_Event )
// Parameters infos:

void UWebResponse::eventSendText() {
    static UFunction* pFnSendText = NULL;

    if (!pFnSendText)
        pFnSendText = (UFunction*)UObject::GObjObjects()->Data[41755];

    UWebResponse_eventSendText_Parms SendText_Parms;

    this->ProcessEvent(pFnSendText, &SendText_Parms, NULL);
};

// Function IpDrv.WebResponse.Dump
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::Dump() {
    static UFunction* pFnDump = NULL;

    if (!pFnDump) pFnDump = (UFunction*)UObject::GObjObjects()->Data[41754];

    UWebResponse_execDump_Parms Dump_Parms;

    pFnDump->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnDump, &Dump_Parms, NULL);

    pFnDump->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.GetHTTPExpiration
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::GetHTTPExpiration() {
    static UFunction* pFnGetHTTPExpiration = NULL;

    if (!pFnGetHTTPExpiration)
        pFnGetHTTPExpiration = (UFunction*)UObject::GObjObjects()->Data[41751];

    UWebResponse_execGetHTTPExpiration_Parms GetHTTPExpiration_Parms;

    pFnGetHTTPExpiration->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetHTTPExpiration, &GetHTTPExpiration_Parms, NULL);

    pFnGetHTTPExpiration->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.LoadParsedUHTM
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::LoadParsedUHTM() {
    static UFunction* pFnLoadParsedUHTM = NULL;

    if (!pFnLoadParsedUHTM)
        pFnLoadParsedUHTM = (UFunction*)UObject::GObjObjects()->Data[41748];

    UWebResponse_execLoadParsedUHTM_Parms LoadParsedUHTM_Parms;

    pFnLoadParsedUHTM->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnLoadParsedUHTM, &LoadParsedUHTM_Parms, NULL);

    pFnLoadParsedUHTM->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.IncludeBinaryFile
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::IncludeBinaryFile() {
    static UFunction* pFnIncludeBinaryFile = NULL;

    if (!pFnIncludeBinaryFile)
        pFnIncludeBinaryFile = (UFunction*)UObject::GObjObjects()->Data[37909];

    UWebResponse_execIncludeBinaryFile_Parms IncludeBinaryFile_Parms;

    pFnIncludeBinaryFile->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIncludeBinaryFile, &IncludeBinaryFile_Parms, NULL);

    pFnIncludeBinaryFile->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.IncludeUHTM
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::IncludeUHTM() {
    static UFunction* pFnIncludeUHTM = NULL;

    if (!pFnIncludeUHTM)
        pFnIncludeUHTM = (UFunction*)UObject::GObjObjects()->Data[37899];

    UWebResponse_execIncludeUHTM_Parms IncludeUHTM_Parms;

    pFnIncludeUHTM->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnIncludeUHTM, &IncludeUHTM_Parms, NULL);

    pFnIncludeUHTM->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.ClearSubst
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::ClearSubst() {
    static UFunction* pFnClearSubst = NULL;

    if (!pFnClearSubst)
        pFnClearSubst = (UFunction*)UObject::GObjObjects()->Data[41745];

    UWebResponse_execClearSubst_Parms ClearSubst_Parms;

    pFnClearSubst->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnClearSubst, &ClearSubst_Parms, NULL);

    pFnClearSubst->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.Subst
// [0x00024401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::Subst() {
    static UFunction* pFnSubst = NULL;

    if (!pFnSubst) pFnSubst = (UFunction*)UObject::GObjObjects()->Data[37898];

    UWebResponse_execSubst_Parms Subst_Parms;

    pFnSubst->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnSubst, &Subst_Parms, NULL);

    pFnSubst->FunctionFlags |= 0x400;
};

// Function IpDrv.WebResponse.FileExists
// [0x00020401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UWebResponse::FileExists() {
    static UFunction* pFnFileExists = NULL;

    if (!pFnFileExists)
        pFnFileExists = (UFunction*)UObject::GObjObjects()->Data[37907];

    UWebResponse_execFileExists_Parms FileExists_Parms;

    pFnFileExists->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnFileExists, &FileExists_Parms, NULL);

    pFnFileExists->FunctionFlags |= 0x400;
};

// Function IpDrv.UIDataStore_OnlinePlaylists.GetMatchTypeForPlaylistId
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUIDataStore_OnlinePlaylists::eventGetMatchTypeForPlaylistId() {
    static UFunction* pFnGetMatchTypeForPlaylistId = NULL;

    if (!pFnGetMatchTypeForPlaylistId)
        pFnGetMatchTypeForPlaylistId =
            (UFunction*)UObject::GObjObjects()->Data[41638];

    UUIDataStore_OnlinePlaylists_eventGetMatchTypeForPlaylistId_Parms
        GetMatchTypeForPlaylistId_Parms;

    this->ProcessEvent(pFnGetMatchTypeForPlaylistId,
                       &GetMatchTypeForPlaylistId_Parms, NULL);
};

// Function IpDrv.UIDataStore_OnlinePlaylists.GetOnlinePlaylistProvider
// [0x00426002]
// Parameters infos:

void UUIDataStore_OnlinePlaylists::GetOnlinePlaylistProvider() {
    static UFunction* pFnGetOnlinePlaylistProvider = NULL;

    if (!pFnGetOnlinePlaylistProvider)
        pFnGetOnlinePlaylistProvider =
            (UFunction*)UObject::GObjObjects()->Data[41629];

    UUIDataStore_OnlinePlaylists_execGetOnlinePlaylistProvider_Parms
        GetOnlinePlaylistProvider_Parms;

    this->ProcessEvent(pFnGetOnlinePlaylistProvider,
                       &GetOnlinePlaylistProvider_Parms, NULL);
};

// Function IpDrv.UIDataStore_OnlinePlaylists.GetPlaylistProvider
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UUIDataStore_OnlinePlaylists::GetPlaylistProvider() {
    static UFunction* pFnGetPlaylistProvider = NULL;

    if (!pFnGetPlaylistProvider)
        pFnGetPlaylistProvider =
            (UFunction*)UObject::GObjObjects()->Data[41624];

    UUIDataStore_OnlinePlaylists_execGetPlaylistProvider_Parms
        GetPlaylistProvider_Parms;

    pFnGetPlaylistProvider->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetPlaylistProvider, &GetPlaylistProvider_Parms,
                       NULL);

    pFnGetPlaylistProvider->FunctionFlags |= 0x400;
};

// Function IpDrv.UIDataStore_OnlinePlaylists.GetResourceProviders
// [0x00420401] ( FUNC_Final | FUNC_Native )
// Parameters infos:

void UUIDataStore_OnlinePlaylists::GetResourceProviders() {
    static UFunction* pFnGetResourceProviders = NULL;

    if (!pFnGetResourceProviders)
        pFnGetResourceProviders =
            (UFunction*)UObject::GObjObjects()->Data[41619];

    UUIDataStore_OnlinePlaylists_execGetResourceProviders_Parms
        GetResourceProviders_Parms;

    pFnGetResourceProviders->FunctionFlags |= ~0x400;

    this->ProcessEvent(pFnGetResourceProviders, &GetResourceProviders_Parms,
                       NULL);

    pFnGetResourceProviders->FunctionFlags |= 0x400;
};

// Function IpDrv.UIDataStore_OnlinePlaylists.Init
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UUIDataStore_OnlinePlaylists::eventInit() {
    static UFunction* pFnInit = NULL;

    if (!pFnInit) pFnInit = (UFunction*)UObject::GObjObjects()->Data[41617];

    UUIDataStore_OnlinePlaylists_eventInit_Parms Init_Parms;

    this->ProcessEvent(pFnInit, &Init_Parms, NULL);
};

// Function IpDrv.WebApplication.PostQuery
// [0x00020000]
// Parameters infos:

void UWebApplication::PostQuery() {
    static UFunction* pFnPostQuery = NULL;

    if (!pFnPostQuery)
        pFnPostQuery = (UFunction*)UObject::GObjObjects()->Data[37878];

    UWebApplication_execPostQuery_Parms PostQuery_Parms;

    this->ProcessEvent(pFnPostQuery, &PostQuery_Parms, NULL);
};

// Function IpDrv.WebApplication.Query
// [0x00020000]
// Parameters infos:

void UWebApplication::Query() {
    static UFunction* pFnQuery = NULL;

    if (!pFnQuery) pFnQuery = (UFunction*)UObject::GObjObjects()->Data[37875];

    UWebApplication_execQuery_Parms Query_Parms;

    this->ProcessEvent(pFnQuery, &Query_Parms, NULL);
};

// Function IpDrv.WebApplication.PreQuery
// [0x00020002]
// Parameters infos:

void UWebApplication::PreQuery() {
    static UFunction* pFnPreQuery = NULL;

    if (!pFnPreQuery)
        pFnPreQuery = (UFunction*)UObject::GObjObjects()->Data[37871];

    UWebApplication_execPreQuery_Parms PreQuery_Parms;

    this->ProcessEvent(pFnPreQuery, &PreQuery_Parms, NULL);
};

// Function IpDrv.WebApplication.CleanupApp
// [0x00020002]
// Parameters infos:

void UWebApplication::CleanupApp() {
    static UFunction* pFnCleanupApp = NULL;

    if (!pFnCleanupApp)
        pFnCleanupApp = (UFunction*)UObject::GObjObjects()->Data[37870];

    UWebApplication_execCleanupApp_Parms CleanupApp_Parms;

    this->ProcessEvent(pFnCleanupApp, &CleanupApp_Parms, NULL);
};

// Function IpDrv.WebApplication.Cleanup
// [0x00020001] ( FUNC_Final )
// Parameters infos:

void UWebApplication::Cleanup() {
    static UFunction* pFnCleanup = NULL;

    if (!pFnCleanup)
        pFnCleanup = (UFunction*)UObject::GObjObjects()->Data[37869];

    UWebApplication_execCleanup_Parms Cleanup_Parms;

    this->ProcessEvent(pFnCleanup, &Cleanup_Parms, NULL);
};

// Function IpDrv.WebApplication.Init
// [0x00020000]
// Parameters infos:

void UWebApplication::Init() {
    static UFunction* pFnInit = NULL;

    if (!pFnInit) pFnInit = (UFunction*)UObject::GObjObjects()->Data[37868];

    UWebApplication_execInit_Parms Init_Parms;

    this->ProcessEvent(pFnInit, &Init_Parms, NULL);
};

// Function IpDrv.WebServer.GetApplication
// [0x00420002]
// Parameters infos:

void AWebServer::GetApplication() {
    static UFunction* pFnGetApplication = NULL;

    if (!pFnGetApplication)
        pFnGetApplication = (UFunction*)UObject::GObjObjects()->Data[41681];

    AWebServer_execGetApplication_Parms GetApplication_Parms;

    this->ProcessEvent(pFnGetApplication, &GetApplication_Parms, NULL);
};

// Function IpDrv.WebServer.LostChild
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebServer::eventLostChild() {
    static UFunction* pFnLostChild = NULL;

    if (!pFnLostChild)
        pFnLostChild = (UFunction*)UObject::GObjObjects()->Data[41811];

    AWebServer_eventLostChild_Parms LostChild_Parms;

    this->ProcessEvent(pFnLostChild, &LostChild_Parms, NULL);
};

// Function IpDrv.WebServer.GainedChild
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebServer::eventGainedChild() {
    static UFunction* pFnGainedChild = NULL;

    if (!pFnGainedChild)
        pFnGainedChild = (UFunction*)UObject::GObjObjects()->Data[41809];

    AWebServer_eventGainedChild_Parms GainedChild_Parms;

    this->ProcessEvent(pFnGainedChild, &GainedChild_Parms, NULL);
};

// Function IpDrv.WebServer.Destroyed
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebServer::eventDestroyed() {
    static UFunction* pFnDestroyed = NULL;

    if (!pFnDestroyed)
        pFnDestroyed = (UFunction*)UObject::GObjObjects()->Data[41807];

    AWebServer_eventDestroyed_Parms Destroyed_Parms;

    this->ProcessEvent(pFnDestroyed, &Destroyed_Parms, NULL);
};

// Function IpDrv.WebServer.PostBeginPlay
// [0x00820002]
// Parameters infos:

void AWebServer::PostBeginPlay() {
    static UFunction* pFnPostBeginPlay = NULL;

    if (!pFnPostBeginPlay)
        pFnPostBeginPlay = (UFunction*)UObject::GObjObjects()->Data[41802];

    AWebServer_execPostBeginPlay_Parms PostBeginPlay_Parms;

    this->ProcessEvent(pFnPostBeginPlay, &PostBeginPlay_Parms, NULL);
};

// Function IpDrv.HelloWeb.Query
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UHelloWeb::eventQuery() {
    static UFunction* pFnQuery = NULL;

    if (!pFnQuery) pFnQuery = (UFunction*)UObject::GObjObjects()->Data[37885];

    UHelloWeb_eventQuery_Parms Query_Parms;

    this->ProcessEvent(pFnQuery, &Query_Parms, NULL);
};

// Function IpDrv.HelloWeb.Init
// [0x00020002]
// Parameters infos:

void UHelloWeb::Init() {
    static UFunction* pFnInit = NULL;

    if (!pFnInit) pFnInit = (UFunction*)UObject::GObjObjects()->Data[37884];

    UHelloWeb_execInit_Parms Init_Parms;

    this->ProcessEvent(pFnInit, &Init_Parms, NULL);
};

// Function IpDrv.ImageServer.Query
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void UImageServer::eventQuery() {
    static UFunction* pFnQuery = NULL;

    if (!pFnQuery) pFnQuery = (UFunction*)UObject::GObjObjects()->Data[37903];

    UImageServer_eventQuery_Parms Query_Parms;

    this->ProcessEvent(pFnQuery, &Query_Parms, NULL);
};

// Function IpDrv.McpServiceConfig.GetUserAuthTicket
// [0x00020000]
// Parameters infos:

void UMcpServiceConfig::GetUserAuthTicket() {
    static UFunction* pFnGetUserAuthTicket = NULL;

    if (!pFnGetUserAuthTicket)
        pFnGetUserAuthTicket = (UFunction*)UObject::GObjObjects()->Data[37962];

    UMcpServiceConfig_execGetUserAuthTicket_Parms GetUserAuthTicket_Parms;

    this->ProcessEvent(pFnGetUserAuthTicket, &GetUserAuthTicket_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.UpdateChallengeUserReward
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::UpdateChallengeUserReward() {
    static UFunction* pFnUpdateChallengeUserReward = NULL;

    if (!pFnUpdateChallengeUserReward)
        pFnUpdateChallengeUserReward =
            (UFunction*)UObject::GObjObjects()->Data[38111];

    UMcpClashMobBase_execUpdateChallengeUserReward_Parms
        UpdateChallengeUserReward_Parms;

    this->ProcessEvent(pFnUpdateChallengeUserReward,
                       &UpdateChallengeUserReward_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.OnUpdateChallengeUserRewardComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnUpdateChallengeUserRewardComplete() {
    static UFunction* pFnOnUpdateChallengeUserRewardComplete = NULL;

    if (!pFnOnUpdateChallengeUserRewardComplete)
        pFnOnUpdateChallengeUserRewardComplete =
            (UFunction*)UObject::GObjObjects()->Data[38106];

    UMcpClashMobBase_execOnUpdateChallengeUserRewardComplete_Parms
        OnUpdateChallengeUserRewardComplete_Parms;

    this->ProcessEvent(pFnOnUpdateChallengeUserRewardComplete,
                       &OnUpdateChallengeUserRewardComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.UpdateChallengeUserProgress
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::UpdateChallengeUserProgress() {
    static UFunction* pFnUpdateChallengeUserProgress = NULL;

    if (!pFnUpdateChallengeUserProgress)
        pFnUpdateChallengeUserProgress =
            (UFunction*)UObject::GObjObjects()->Data[38101];

    UMcpClashMobBase_execUpdateChallengeUserProgress_Parms
        UpdateChallengeUserProgress_Parms;

    this->ProcessEvent(pFnUpdateChallengeUserProgress,
                       &UpdateChallengeUserProgress_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.OnUpdateChallengeUserProgressComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnUpdateChallengeUserProgressComplete() {
    static UFunction* pFnOnUpdateChallengeUserProgressComplete = NULL;

    if (!pFnOnUpdateChallengeUserProgressComplete)
        pFnOnUpdateChallengeUserProgressComplete =
            (UFunction*)UObject::GObjObjects()->Data[38096];

    UMcpClashMobBase_execOnUpdateChallengeUserProgressComplete_Parms
        OnUpdateChallengeUserProgressComplete_Parms;

    this->ProcessEvent(pFnOnUpdateChallengeUserProgressComplete,
                       &OnUpdateChallengeUserProgressComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.GetChallengeUserStatus
// [0x00420000]
// Parameters infos:

void UMcpClashMobBase::GetChallengeUserStatus() {
    static UFunction* pFnGetChallengeUserStatus = NULL;

    if (!pFnGetChallengeUserStatus)
        pFnGetChallengeUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38092];

    UMcpClashMobBase_execGetChallengeUserStatus_Parms
        GetChallengeUserStatus_Parms;

    this->ProcessEvent(pFnGetChallengeUserStatus, &GetChallengeUserStatus_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobBase.QueryChallengeMultiUserStatus
// [0x00420000]
// Parameters infos:

void UMcpClashMobBase::QueryChallengeMultiUserStatus() {
    static UFunction* pFnQueryChallengeMultiUserStatus = NULL;

    if (!pFnQueryChallengeMultiUserStatus)
        pFnQueryChallengeMultiUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38087];

    UMcpClashMobBase_execQueryChallengeMultiUserStatus_Parms
        QueryChallengeMultiUserStatus_Parms;

    this->ProcessEvent(pFnQueryChallengeMultiUserStatus,
                       &QueryChallengeMultiUserStatus_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.QueryChallengeUserStatus
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::QueryChallengeUserStatus() {
    static UFunction* pFnQueryChallengeUserStatus = NULL;

    if (!pFnQueryChallengeUserStatus)
        pFnQueryChallengeUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38084];

    UMcpClashMobBase_execQueryChallengeUserStatus_Parms
        QueryChallengeUserStatus_Parms;

    this->ProcessEvent(pFnQueryChallengeUserStatus,
                       &QueryChallengeUserStatus_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.OnQueryChallengeUserStatusComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnQueryChallengeUserStatusComplete() {
    static UFunction* pFnOnQueryChallengeUserStatusComplete = NULL;

    if (!pFnOnQueryChallengeUserStatusComplete)
        pFnOnQueryChallengeUserStatusComplete =
            (UFunction*)UObject::GObjObjects()->Data[38079];

    UMcpClashMobBase_execOnQueryChallengeUserStatusComplete_Parms
        OnQueryChallengeUserStatusComplete_Parms;

    this->ProcessEvent(pFnOnQueryChallengeUserStatusComplete,
                       &OnQueryChallengeUserStatusComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.AcceptChallenge
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::AcceptChallenge() {
    static UFunction* pFnAcceptChallenge = NULL;

    if (!pFnAcceptChallenge)
        pFnAcceptChallenge = (UFunction*)UObject::GObjObjects()->Data[38076];

    UMcpClashMobBase_execAcceptChallenge_Parms AcceptChallenge_Parms;

    this->ProcessEvent(pFnAcceptChallenge, &AcceptChallenge_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.OnAcceptChallengeComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnAcceptChallengeComplete() {
    static UFunction* pFnOnAcceptChallengeComplete = NULL;

    if (!pFnOnAcceptChallengeComplete)
        pFnOnAcceptChallengeComplete =
            (UFunction*)UObject::GObjObjects()->Data[38071];

    UMcpClashMobBase_execOnAcceptChallengeComplete_Parms
        OnAcceptChallengeComplete_Parms;

    this->ProcessEvent(pFnOnAcceptChallengeComplete,
                       &OnAcceptChallengeComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.DeleteCachedChallengeFile
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::DeleteCachedChallengeFile() {
    static UFunction* pFnDeleteCachedChallengeFile = NULL;

    if (!pFnDeleteCachedChallengeFile)
        pFnDeleteCachedChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38068];

    UMcpClashMobBase_execDeleteCachedChallengeFile_Parms
        DeleteCachedChallengeFile_Parms;

    this->ProcessEvent(pFnDeleteCachedChallengeFile,
                       &DeleteCachedChallengeFile_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.ClearCachedChallengeFile
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::ClearCachedChallengeFile() {
    static UFunction* pFnClearCachedChallengeFile = NULL;

    if (!pFnClearCachedChallengeFile)
        pFnClearCachedChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38065];

    UMcpClashMobBase_execClearCachedChallengeFile_Parms
        ClearCachedChallengeFile_Parms;

    this->ProcessEvent(pFnClearCachedChallengeFile,
                       &ClearCachedChallengeFile_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.GetChallengeFileContents
// [0x00420000]
// Parameters infos:

void UMcpClashMobBase::GetChallengeFileContents() {
    static UFunction* pFnGetChallengeFileContents = NULL;

    if (!pFnGetChallengeFileContents)
        pFnGetChallengeFileContents =
            (UFunction*)UObject::GObjObjects()->Data[38060];

    UMcpClashMobBase_execGetChallengeFileContents_Parms
        GetChallengeFileContents_Parms;

    this->ProcessEvent(pFnGetChallengeFileContents,
                       &GetChallengeFileContents_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.DownloadChallengeFile
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::DownloadChallengeFile() {
    static UFunction* pFnDownloadChallengeFile = NULL;

    if (!pFnDownloadChallengeFile)
        pFnDownloadChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38057];

    UMcpClashMobBase_execDownloadChallengeFile_Parms
        DownloadChallengeFile_Parms;

    this->ProcessEvent(pFnDownloadChallengeFile, &DownloadChallengeFile_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobBase.GetChallengeFileList
// [0x00420000]
// Parameters infos:

void UMcpClashMobBase::GetChallengeFileList() {
    static UFunction* pFnGetChallengeFileList = NULL;

    if (!pFnGetChallengeFileList)
        pFnGetChallengeFileList =
            (UFunction*)UObject::GObjObjects()->Data[38053];

    UMcpClashMobBase_execGetChallengeFileList_Parms GetChallengeFileList_Parms;

    this->ProcessEvent(pFnGetChallengeFileList, &GetChallengeFileList_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobBase.OnDownloadChallengeFileComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnDownloadChallengeFileComplete() {
    static UFunction* pFnOnDownloadChallengeFileComplete = NULL;

    if (!pFnOnDownloadChallengeFileComplete)
        pFnOnDownloadChallengeFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[38047];

    UMcpClashMobBase_execOnDownloadChallengeFileComplete_Parms
        OnDownloadChallengeFileComplete_Parms;

    this->ProcessEvent(pFnOnDownloadChallengeFileComplete,
                       &OnDownloadChallengeFileComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.GetChallengeList
// [0x00420000]
// Parameters infos:

void UMcpClashMobBase::GetChallengeList() {
    static UFunction* pFnGetChallengeList = NULL;

    if (!pFnGetChallengeList)
        pFnGetChallengeList = (UFunction*)UObject::GObjObjects()->Data[38044];

    UMcpClashMobBase_execGetChallengeList_Parms GetChallengeList_Parms;

    this->ProcessEvent(pFnGetChallengeList, &GetChallengeList_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.QueryChallengeList
// [0x00020000]
// Parameters infos:

void UMcpClashMobBase::QueryChallengeList() {
    static UFunction* pFnQueryChallengeList = NULL;

    if (!pFnQueryChallengeList)
        pFnQueryChallengeList = (UFunction*)UObject::GObjObjects()->Data[38043];

    UMcpClashMobBase_execQueryChallengeList_Parms QueryChallengeList_Parms;

    this->ProcessEvent(pFnQueryChallengeList, &QueryChallengeList_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.OnQueryChallengeListComplete
// [0x00120000]
// Parameters infos:

void UMcpClashMobBase::OnQueryChallengeListComplete() {
    static UFunction* pFnOnQueryChallengeListComplete = NULL;

    if (!pFnOnQueryChallengeListComplete)
        pFnOnQueryChallengeListComplete =
            (UFunction*)UObject::GObjObjects()->Data[38040];

    UMcpClashMobBase_execOnQueryChallengeListComplete_Parms
        OnQueryChallengeListComplete_Parms;

    this->ProcessEvent(pFnOnQueryChallengeListComplete,
                       &OnQueryChallengeListComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[38036];

    UMcpClashMobBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpClashMobFileDownload.GetUrlForFile
// [0x00020002]
// Parameters infos:

void UMcpClashMobFileDownload::GetUrlForFile() {
    static UFunction* pFnGetUrlForFile = NULL;

    if (!pFnGetUrlForFile)
        pFnGetUrlForFile = (UFunction*)UObject::GObjObjects()->Data[38244];

    UMcpClashMobFileDownload_execGetUrlForFile_Parms GetUrlForFile_Parms;

    this->ProcessEvent(pFnGetUrlForFile, &GetUrlForFile_Parms, NULL);
};

// Function
// IpDrv.McpClashMobManager.OnUpdateChallengeUserRewardHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnUpdateChallengeUserRewardHTTPRequestComplete() {
    static UFunction* pFnOnUpdateChallengeUserRewardHTTPRequestComplete = NULL;

    if (!pFnOnUpdateChallengeUserRewardHTTPRequestComplete)
        pFnOnUpdateChallengeUserRewardHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38447];

    UMcpClashMobManager_execOnUpdateChallengeUserRewardHTTPRequestComplete_Parms
        OnUpdateChallengeUserRewardHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnUpdateChallengeUserRewardHTTPRequestComplete,
                       &OnUpdateChallengeUserRewardHTTPRequestComplete_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobManager.UpdateChallengeUserReward
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::UpdateChallengeUserReward() {
    static UFunction* pFnUpdateChallengeUserReward = NULL;

    if (!pFnUpdateChallengeUserReward)
        pFnUpdateChallengeUserReward =
            (UFunction*)UObject::GObjObjects()->Data[38437];

    UMcpClashMobManager_execUpdateChallengeUserReward_Parms
        UpdateChallengeUserReward_Parms;

    this->ProcessEvent(pFnUpdateChallengeUserReward,
                       &UpdateChallengeUserReward_Parms, NULL);
};

// Function
// IpDrv.McpClashMobManager.OnUpdateChallengeUserProgressHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnUpdateChallengeUserProgressHTTPRequestComplete() {
    static UFunction* pFnOnUpdateChallengeUserProgressHTTPRequestComplete =
        NULL;

    if (!pFnOnUpdateChallengeUserProgressHTTPRequestComplete)
        pFnOnUpdateChallengeUserProgressHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38427];

    UMcpClashMobManager_execOnUpdateChallengeUserProgressHTTPRequestComplete_Parms
        OnUpdateChallengeUserProgressHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnUpdateChallengeUserProgressHTTPRequestComplete,
                       &OnUpdateChallengeUserProgressHTTPRequestComplete_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobManager.UpdateChallengeUserProgress
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::UpdateChallengeUserProgress() {
    static UFunction* pFnUpdateChallengeUserProgress = NULL;

    if (!pFnUpdateChallengeUserProgress)
        pFnUpdateChallengeUserProgress =
            (UFunction*)UObject::GObjObjects()->Data[38416];

    UMcpClashMobManager_execUpdateChallengeUserProgress_Parms
        UpdateChallengeUserProgress_Parms;

    this->ProcessEvent(pFnUpdateChallengeUserProgress,
                       &UpdateChallengeUserProgress_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.GetChallengeUserStatus
// [0x00C20002]
// Parameters infos:

void UMcpClashMobManager::GetChallengeUserStatus() {
    static UFunction* pFnGetChallengeUserStatus = NULL;

    if (!pFnGetChallengeUserStatus)
        pFnGetChallengeUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38410];

    UMcpClashMobManager_execGetChallengeUserStatus_Parms
        GetChallengeUserStatus_Parms;

    this->ProcessEvent(pFnGetChallengeUserStatus, &GetChallengeUserStatus_Parms,
                       NULL);
};

// Function
// IpDrv.McpClashMobManager.OnQueryChallengeMultiStatusHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnQueryChallengeMultiStatusHTTPRequestComplete() {
    static UFunction* pFnOnQueryChallengeMultiStatusHTTPRequestComplete = NULL;

    if (!pFnOnQueryChallengeMultiStatusHTTPRequestComplete)
        pFnOnQueryChallengeMultiStatusHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38397];

    UMcpClashMobManager_execOnQueryChallengeMultiStatusHTTPRequestComplete_Parms
        OnQueryChallengeMultiStatusHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryChallengeMultiStatusHTTPRequestComplete,
                       &OnQueryChallengeMultiStatusHTTPRequestComplete_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobManager.QueryChallengeMultiUserStatus
// [0x00420002]
// Parameters infos:

void UMcpClashMobManager::QueryChallengeMultiUserStatus() {
    static UFunction* pFnQueryChallengeMultiUserStatus = NULL;

    if (!pFnQueryChallengeMultiUserStatus)
        pFnQueryChallengeMultiUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38384];

    UMcpClashMobManager_execQueryChallengeMultiUserStatus_Parms
        QueryChallengeMultiUserStatus_Parms;

    this->ProcessEvent(pFnQueryChallengeMultiUserStatus,
                       &QueryChallengeMultiUserStatus_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.OnQueryChallengeStatusHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnQueryChallengeStatusHTTPRequestComplete() {
    static UFunction* pFnOnQueryChallengeStatusHTTPRequestComplete = NULL;

    if (!pFnOnQueryChallengeStatusHTTPRequestComplete)
        pFnOnQueryChallengeStatusHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38372];

    UMcpClashMobManager_execOnQueryChallengeStatusHTTPRequestComplete_Parms
        OnQueryChallengeStatusHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryChallengeStatusHTTPRequestComplete,
                       &OnQueryChallengeStatusHTTPRequestComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.QueryChallengeUserStatus
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::QueryChallengeUserStatus() {
    static UFunction* pFnQueryChallengeUserStatus = NULL;

    if (!pFnQueryChallengeUserStatus)
        pFnQueryChallengeUserStatus =
            (UFunction*)UObject::GObjObjects()->Data[38363];

    UMcpClashMobManager_execQueryChallengeUserStatus_Parms
        QueryChallengeUserStatus_Parms;

    this->ProcessEvent(pFnQueryChallengeUserStatus,
                       &QueryChallengeUserStatus_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.OnAcceptChallengeHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnAcceptChallengeHTTPRequestComplete() {
    static UFunction* pFnOnAcceptChallengeHTTPRequestComplete = NULL;

    if (!pFnOnAcceptChallengeHTTPRequestComplete)
        pFnOnAcceptChallengeHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38353];

    UMcpClashMobManager_execOnAcceptChallengeHTTPRequestComplete_Parms
        OnAcceptChallengeHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnAcceptChallengeHTTPRequestComplete,
                       &OnAcceptChallengeHTTPRequestComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.AcceptChallenge
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::AcceptChallenge() {
    static UFunction* pFnAcceptChallenge = NULL;

    if (!pFnAcceptChallenge)
        pFnAcceptChallenge = (UFunction*)UObject::GObjObjects()->Data[38344];

    UMcpClashMobManager_execAcceptChallenge_Parms AcceptChallenge_Parms;

    this->ProcessEvent(pFnAcceptChallenge, &AcceptChallenge_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.DeleteCachedChallengeFile
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::DeleteCachedChallengeFile() {
    static UFunction* pFnDeleteCachedChallengeFile = NULL;

    if (!pFnDeleteCachedChallengeFile)
        pFnDeleteCachedChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38339];

    UMcpClashMobManager_execDeleteCachedChallengeFile_Parms
        DeleteCachedChallengeFile_Parms;

    this->ProcessEvent(pFnDeleteCachedChallengeFile,
                       &DeleteCachedChallengeFile_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.ClearCachedChallengeFile
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::ClearCachedChallengeFile() {
    static UFunction* pFnClearCachedChallengeFile = NULL;

    if (!pFnClearCachedChallengeFile)
        pFnClearCachedChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38334];

    UMcpClashMobManager_execClearCachedChallengeFile_Parms
        ClearCachedChallengeFile_Parms;

    this->ProcessEvent(pFnClearCachedChallengeFile,
                       &ClearCachedChallengeFile_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.GetChallengeFileContents
// [0x00420002]
// Parameters infos:

void UMcpClashMobManager::GetChallengeFileContents() {
    static UFunction* pFnGetChallengeFileContents = NULL;

    if (!pFnGetChallengeFileContents)
        pFnGetChallengeFileContents =
            (UFunction*)UObject::GObjObjects()->Data[38327];

    UMcpClashMobManager_execGetChallengeFileContents_Parms
        GetChallengeFileContents_Parms;

    this->ProcessEvent(pFnGetChallengeFileContents,
                       &GetChallengeFileContents_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.OnDownloadMcpFileComplete
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::OnDownloadMcpFileComplete() {
    static UFunction* pFnOnDownloadMcpFileComplete = NULL;

    if (!pFnOnDownloadMcpFileComplete)
        pFnOnDownloadMcpFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[38319];

    UMcpClashMobManager_execOnDownloadMcpFileComplete_Parms
        OnDownloadMcpFileComplete_Parms;

    this->ProcessEvent(pFnOnDownloadMcpFileComplete,
                       &OnDownloadMcpFileComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.OnLoadCachedFileComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnLoadCachedFileComplete() {
    static UFunction* pFnOnLoadCachedFileComplete = NULL;

    if (!pFnOnLoadCachedFileComplete)
        pFnOnLoadCachedFileComplete =
            (UFunction*)UObject::GObjObjects()->Data[38308];

    UMcpClashMobManager_execOnLoadCachedFileComplete_Parms
        OnLoadCachedFileComplete_Parms;

    this->ProcessEvent(pFnOnLoadCachedFileComplete,
                       &OnLoadCachedFileComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.DownloadChallengeFile
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::DownloadChallengeFile() {
    static UFunction* pFnDownloadChallengeFile = NULL;

    if (!pFnDownloadChallengeFile)
        pFnDownloadChallengeFile =
            (UFunction*)UObject::GObjObjects()->Data[38301];

    UMcpClashMobManager_execDownloadChallengeFile_Parms
        DownloadChallengeFile_Parms;

    this->ProcessEvent(pFnDownloadChallengeFile, &DownloadChallengeFile_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobManager.GetChallengeFileList
// [0x00420002]
// Parameters infos:

void UMcpClashMobManager::GetChallengeFileList() {
    static UFunction* pFnGetChallengeFileList = NULL;

    if (!pFnGetChallengeFileList)
        pFnGetChallengeFileList =
            (UFunction*)UObject::GObjObjects()->Data[38296];

    UMcpClashMobManager_execGetChallengeFileList_Parms
        GetChallengeFileList_Parms;

    this->ProcessEvent(pFnGetChallengeFileList, &GetChallengeFileList_Parms,
                       NULL);
};

// Function IpDrv.McpClashMobManager.GetChallengeList
// [0x00420002]
// Parameters infos:

void UMcpClashMobManager::GetChallengeList() {
    static UFunction* pFnGetChallengeList = NULL;

    if (!pFnGetChallengeList)
        pFnGetChallengeList = (UFunction*)UObject::GObjObjects()->Data[38293];

    UMcpClashMobManager_execGetChallengeList_Parms GetChallengeList_Parms;

    this->ProcessEvent(pFnGetChallengeList, &GetChallengeList_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.OnQueryChallengeListHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpClashMobManager::OnQueryChallengeListHTTPRequestComplete() {
    static UFunction* pFnOnQueryChallengeListHTTPRequestComplete = NULL;

    if (!pFnOnQueryChallengeListHTTPRequestComplete)
        pFnOnQueryChallengeListHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38286];

    UMcpClashMobManager_execOnQueryChallengeListHTTPRequestComplete_Parms
        OnQueryChallengeListHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryChallengeListHTTPRequestComplete,
                       &OnQueryChallengeListHTTPRequestComplete_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.QueryChallengeList
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::QueryChallengeList() {
    static UFunction* pFnQueryChallengeList = NULL;

    if (!pFnQueryChallengeList)
        pFnQueryChallengeList = (UFunction*)UObject::GObjObjects()->Data[38282];

    UMcpClashMobManager_execQueryChallengeList_Parms QueryChallengeList_Parms;

    this->ProcessEvent(pFnQueryChallengeList, &QueryChallengeList_Parms, NULL);
};

// Function IpDrv.McpClashMobManager.Init
// [0x00020002]
// Parameters infos:

void UMcpClashMobManager::Init() {
    static UFunction* pFnInit = NULL;

    if (!pFnInit) pFnInit = (UFunction*)UObject::GObjObjects()->Data[38281];

    UMcpClashMobManager_execInit_Parms Init_Parms;

    this->ProcessEvent(pFnInit, &Init_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnAcceptGroupInviteComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnAcceptGroupInviteComplete() {
    static UFunction* pFnOnAcceptGroupInviteComplete = NULL;

    if (!pFnOnAcceptGroupInviteComplete)
        pFnOnAcceptGroupInviteComplete =
            (UFunction*)UObject::GObjObjects()->Data[38550];

    UMcpGroupsBase_execOnAcceptGroupInviteComplete_Parms
        OnAcceptGroupInviteComplete_Parms;

    this->ProcessEvent(pFnOnAcceptGroupInviteComplete,
                       &OnAcceptGroupInviteComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.AcceptGroupInvite
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::AcceptGroupInvite() {
    static UFunction* pFnAcceptGroupInvite = NULL;

    if (!pFnAcceptGroupInvite)
        pFnAcceptGroupInvite = (UFunction*)UObject::GObjObjects()->Data[38546];

    UMcpGroupsBase_execAcceptGroupInvite_Parms AcceptGroupInvite_Parms;

    this->ProcessEvent(pFnAcceptGroupInvite, &AcceptGroupInvite_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.GetGroupInviteList
// [0x00420000]
// Parameters infos:

void UMcpGroupsBase::GetGroupInviteList() {
    static UFunction* pFnGetGroupInviteList = NULL;

    if (!pFnGetGroupInviteList)
        pFnGetGroupInviteList = (UFunction*)UObject::GObjObjects()->Data[38543];

    UMcpGroupsBase_execGetGroupInviteList_Parms GetGroupInviteList_Parms;

    this->ProcessEvent(pFnGetGroupInviteList, &GetGroupInviteList_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnQueryGroupInvitesComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnQueryGroupInvitesComplete() {
    static UFunction* pFnOnQueryGroupInvitesComplete = NULL;

    if (!pFnOnQueryGroupInvitesComplete)
        pFnOnQueryGroupInvitesComplete =
            (UFunction*)UObject::GObjObjects()->Data[38540];

    UMcpGroupsBase_execOnQueryGroupInvitesComplete_Parms
        OnQueryGroupInvitesComplete_Parms;

    this->ProcessEvent(pFnOnQueryGroupInvitesComplete,
                       &OnQueryGroupInvitesComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.QueryGroupInvites
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::QueryGroupInvites() {
    static UFunction* pFnQueryGroupInvites = NULL;

    if (!pFnQueryGroupInvites)
        pFnQueryGroupInvites = (UFunction*)UObject::GObjObjects()->Data[38538];

    UMcpGroupsBase_execQueryGroupInvites_Parms QueryGroupInvites_Parms;

    this->ProcessEvent(pFnQueryGroupInvites, &QueryGroupInvites_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnDeleteAllGroupsComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnDeleteAllGroupsComplete() {
    static UFunction* pFnOnDeleteAllGroupsComplete = NULL;

    if (!pFnOnDeleteAllGroupsComplete)
        pFnOnDeleteAllGroupsComplete =
            (UFunction*)UObject::GObjObjects()->Data[38534];

    UMcpGroupsBase_execOnDeleteAllGroupsComplete_Parms
        OnDeleteAllGroupsComplete_Parms;

    this->ProcessEvent(pFnOnDeleteAllGroupsComplete,
                       &OnDeleteAllGroupsComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.DeleteAllGroups
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::DeleteAllGroups() {
    static UFunction* pFnDeleteAllGroups = NULL;

    if (!pFnDeleteAllGroups)
        pFnDeleteAllGroups = (UFunction*)UObject::GObjObjects()->Data[38532];

    UMcpGroupsBase_execDeleteAllGroups_Parms DeleteAllGroups_Parms;

    this->ProcessEvent(pFnDeleteAllGroups, &DeleteAllGroups_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnRemoveGroupMembersComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnRemoveGroupMembersComplete() {
    static UFunction* pFnOnRemoveGroupMembersComplete = NULL;

    if (!pFnOnRemoveGroupMembersComplete)
        pFnOnRemoveGroupMembersComplete =
            (UFunction*)UObject::GObjObjects()->Data[38528];

    UMcpGroupsBase_execOnRemoveGroupMembersComplete_Parms
        OnRemoveGroupMembersComplete_Parms;

    this->ProcessEvent(pFnOnRemoveGroupMembersComplete,
                       &OnRemoveGroupMembersComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.RemoveGroupMembers
// [0x00420000]
// Parameters infos:

void UMcpGroupsBase::RemoveGroupMembers() {
    static UFunction* pFnRemoveGroupMembers = NULL;

    if (!pFnRemoveGroupMembers)
        pFnRemoveGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38523];

    UMcpGroupsBase_execRemoveGroupMembers_Parms RemoveGroupMembers_Parms;

    this->ProcessEvent(pFnRemoveGroupMembers, &RemoveGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnAddGroupMembersComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnAddGroupMembersComplete() {
    static UFunction* pFnOnAddGroupMembersComplete = NULL;

    if (!pFnOnAddGroupMembersComplete)
        pFnOnAddGroupMembersComplete =
            (UFunction*)UObject::GObjObjects()->Data[38519];

    UMcpGroupsBase_execOnAddGroupMembersComplete_Parms
        OnAddGroupMembersComplete_Parms;

    this->ProcessEvent(pFnOnAddGroupMembersComplete,
                       &OnAddGroupMembersComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.AddGroupMembers
// [0x00420000]
// Parameters infos:

void UMcpGroupsBase::AddGroupMembers() {
    static UFunction* pFnAddGroupMembers = NULL;

    if (!pFnAddGroupMembers)
        pFnAddGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38513];

    UMcpGroupsBase_execAddGroupMembers_Parms AddGroupMembers_Parms;

    this->ProcessEvent(pFnAddGroupMembers, &AddGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.GetGroupMembers
// [0x00420000]
// Parameters infos:

void UMcpGroupsBase::GetGroupMembers() {
    static UFunction* pFnGetGroupMembers = NULL;

    if (!pFnGetGroupMembers)
        pFnGetGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38509];

    UMcpGroupsBase_execGetGroupMembers_Parms GetGroupMembers_Parms;

    this->ProcessEvent(pFnGetGroupMembers, &GetGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnQueryGroupMembersComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnQueryGroupMembersComplete() {
    static UFunction* pFnOnQueryGroupMembersComplete = NULL;

    if (!pFnOnQueryGroupMembersComplete)
        pFnOnQueryGroupMembersComplete =
            (UFunction*)UObject::GObjObjects()->Data[38505];

    UMcpGroupsBase_execOnQueryGroupMembersComplete_Parms
        OnQueryGroupMembersComplete_Parms;

    this->ProcessEvent(pFnOnQueryGroupMembersComplete,
                       &OnQueryGroupMembersComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.QueryGroupMembers
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::QueryGroupMembers() {
    static UFunction* pFnQueryGroupMembers = NULL;

    if (!pFnQueryGroupMembers)
        pFnQueryGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38502];

    UMcpGroupsBase_execQueryGroupMembers_Parms QueryGroupMembers_Parms;

    this->ProcessEvent(pFnQueryGroupMembers, &QueryGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.GetGroupList
// [0x00420000]
// Parameters infos:

void UMcpGroupsBase::GetGroupList() {
    static UFunction* pFnGetGroupList = NULL;

    if (!pFnGetGroupList)
        pFnGetGroupList = (UFunction*)UObject::GObjObjects()->Data[38499];

    UMcpGroupsBase_execGetGroupList_Parms GetGroupList_Parms;

    this->ProcessEvent(pFnGetGroupList, &GetGroupList_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnQueryGroupsComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnQueryGroupsComplete() {
    static UFunction* pFnOnQueryGroupsComplete = NULL;

    if (!pFnOnQueryGroupsComplete)
        pFnOnQueryGroupsComplete =
            (UFunction*)UObject::GObjObjects()->Data[38495];

    UMcpGroupsBase_execOnQueryGroupsComplete_Parms OnQueryGroupsComplete_Parms;

    this->ProcessEvent(pFnOnQueryGroupsComplete, &OnQueryGroupsComplete_Parms,
                       NULL);
};

// Function IpDrv.McpGroupsBase.QueryGroups
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::QueryGroups() {
    static UFunction* pFnQueryGroups = NULL;

    if (!pFnQueryGroups)
        pFnQueryGroups = (UFunction*)UObject::GObjObjects()->Data[38493];

    UMcpGroupsBase_execQueryGroups_Parms QueryGroups_Parms;

    this->ProcessEvent(pFnQueryGroups, &QueryGroups_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnDeleteGroupComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnDeleteGroupComplete() {
    static UFunction* pFnOnDeleteGroupComplete = NULL;

    if (!pFnOnDeleteGroupComplete)
        pFnOnDeleteGroupComplete =
            (UFunction*)UObject::GObjObjects()->Data[38489];

    UMcpGroupsBase_execOnDeleteGroupComplete_Parms OnDeleteGroupComplete_Parms;

    this->ProcessEvent(pFnOnDeleteGroupComplete, &OnDeleteGroupComplete_Parms,
                       NULL);
};

// Function IpDrv.McpGroupsBase.DeleteGroup
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::DeleteGroup() {
    static UFunction* pFnDeleteGroup = NULL;

    if (!pFnDeleteGroup)
        pFnDeleteGroup = (UFunction*)UObject::GObjObjects()->Data[38486];

    UMcpGroupsBase_execDeleteGroup_Parms DeleteGroup_Parms;

    this->ProcessEvent(pFnDeleteGroup, &DeleteGroup_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.OnCreateGroupComplete
// [0x00120000]
// Parameters infos:

void UMcpGroupsBase::OnCreateGroupComplete() {
    static UFunction* pFnOnCreateGroupComplete = NULL;

    if (!pFnOnCreateGroupComplete)
        pFnOnCreateGroupComplete =
            (UFunction*)UObject::GObjObjects()->Data[38482];

    UMcpGroupsBase_execOnCreateGroupComplete_Parms OnCreateGroupComplete_Parms;

    this->ProcessEvent(pFnOnCreateGroupComplete, &OnCreateGroupComplete_Parms,
                       NULL);
};

// Function IpDrv.McpGroupsBase.CreateGroup
// [0x00020000]
// Parameters infos:

void UMcpGroupsBase::CreateGroup() {
    static UFunction* pFnCreateGroup = NULL;

    if (!pFnCreateGroup)
        pFnCreateGroup = (UFunction*)UObject::GObjObjects()->Data[38479];

    UMcpGroupsBase_execCreateGroup_Parms CreateGroup_Parms;

    this->ProcessEvent(pFnCreateGroup, &CreateGroup_Parms, NULL);
};

// Function IpDrv.McpGroupsBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpGroupsBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[38475];

    UMcpGroupsBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.CacheGroupMember
// [0x00820002]
// Parameters infos:

void UMcpGroupsManager::CacheGroupMember() {
    static UFunction* pFnCacheGroupMember = NULL;

    if (!pFnCacheGroupMember)
        pFnCacheGroupMember = (UFunction*)UObject::GObjObjects()->Data[38716];

    UMcpGroupsManager_execCacheGroupMember_Parms CacheGroupMember_Parms;

    this->ProcessEvent(pFnCacheGroupMember, &CacheGroupMember_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.CacheGroup
// [0x00820002]
// Parameters infos:

void UMcpGroupsManager::CacheGroup() {
    static UFunction* pFnCacheGroup = NULL;

    if (!pFnCacheGroup)
        pFnCacheGroup = (UFunction*)UObject::GObjObjects()->Data[38708];

    UMcpGroupsManager_execCacheGroup_Parms CacheGroup_Parms;

    this->ProcessEvent(pFnCacheGroup, &CacheGroup_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnAcceptGroupInviteRequestComplete
// [0x00120002]
// Parameters infos:

void UMcpGroupsManager::OnAcceptGroupInviteRequestComplete() {
    static UFunction* pFnOnAcceptGroupInviteRequestComplete = NULL;

    if (!pFnOnAcceptGroupInviteRequestComplete)
        pFnOnAcceptGroupInviteRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38701];

    UMcpGroupsManager_execOnAcceptGroupInviteRequestComplete_Parms
        OnAcceptGroupInviteRequestComplete_Parms;

    this->ProcessEvent(pFnOnAcceptGroupInviteRequestComplete,
                       &OnAcceptGroupInviteRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.AcceptGroupInvite
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::AcceptGroupInvite() {
    static UFunction* pFnAcceptGroupInvite = NULL;

    if (!pFnAcceptGroupInvite)
        pFnAcceptGroupInvite = (UFunction*)UObject::GObjObjects()->Data[38695];

    UMcpGroupsManager_execAcceptGroupInvite_Parms AcceptGroupInvite_Parms;

    this->ProcessEvent(pFnAcceptGroupInvite, &AcceptGroupInvite_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnDeleteAllGroupsRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::OnDeleteAllGroupsRequestComplete() {
    static UFunction* pFnOnDeleteAllGroupsRequestComplete = NULL;

    if (!pFnOnDeleteAllGroupsRequestComplete)
        pFnOnDeleteAllGroupsRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38688];

    UMcpGroupsManager_execOnDeleteAllGroupsRequestComplete_Parms
        OnDeleteAllGroupsRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteAllGroupsRequestComplete,
                       &OnDeleteAllGroupsRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.DeleteAllGroups
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::DeleteAllGroups() {
    static UFunction* pFnDeleteAllGroups = NULL;

    if (!pFnDeleteAllGroups)
        pFnDeleteAllGroups = (UFunction*)UObject::GObjObjects()->Data[38684];

    UMcpGroupsManager_execDeleteAllGroups_Parms DeleteAllGroups_Parms;

    this->ProcessEvent(pFnDeleteAllGroups, &DeleteAllGroups_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnRemoveGroupMembersRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::OnRemoveGroupMembersRequestComplete() {
    static UFunction* pFnOnRemoveGroupMembersRequestComplete = NULL;

    if (!pFnOnRemoveGroupMembersRequestComplete)
        pFnOnRemoveGroupMembersRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38677];

    UMcpGroupsManager_execOnRemoveGroupMembersRequestComplete_Parms
        OnRemoveGroupMembersRequestComplete_Parms;

    this->ProcessEvent(pFnOnRemoveGroupMembersRequestComplete,
                       &OnRemoveGroupMembersRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.RemoveGroupMembers
// [0x00420002]
// Parameters infos:

void UMcpGroupsManager::RemoveGroupMembers() {
    static UFunction* pFnRemoveGroupMembers = NULL;

    if (!pFnRemoveGroupMembers)
        pFnRemoveGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38668];

    UMcpGroupsManager_execRemoveGroupMembers_Parms RemoveGroupMembers_Parms;

    this->ProcessEvent(pFnRemoveGroupMembers, &RemoveGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnAddGroupMembersRequestComplete
// [0x00120002]
// Parameters infos:

void UMcpGroupsManager::OnAddGroupMembersRequestComplete() {
    static UFunction* pFnOnAddGroupMembersRequestComplete = NULL;

    if (!pFnOnAddGroupMembersRequestComplete)
        pFnOnAddGroupMembersRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38661];

    UMcpGroupsManager_execOnAddGroupMembersRequestComplete_Parms
        OnAddGroupMembersRequestComplete_Parms;

    this->ProcessEvent(pFnOnAddGroupMembersRequestComplete,
                       &OnAddGroupMembersRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.AddGroupMembers
// [0x00420002]
// Parameters infos:

void UMcpGroupsManager::AddGroupMembers() {
    static UFunction* pFnAddGroupMembers = NULL;

    if (!pFnAddGroupMembers)
        pFnAddGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38651];

    UMcpGroupsManager_execAddGroupMembers_Parms AddGroupMembers_Parms;

    this->ProcessEvent(pFnAddGroupMembers, &AddGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.GetGroupMembers
// [0x00C20002]
// Parameters infos:

void UMcpGroupsManager::GetGroupMembers() {
    static UFunction* pFnGetGroupMembers = NULL;

    if (!pFnGetGroupMembers)
        pFnGetGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38644];

    UMcpGroupsManager_execGetGroupMembers_Parms GetGroupMembers_Parms;

    this->ProcessEvent(pFnGetGroupMembers, &GetGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnQueryGroupMembersRequestComplete
// [0x00120002]
// Parameters infos:

void UMcpGroupsManager::OnQueryGroupMembersRequestComplete() {
    static UFunction* pFnOnQueryGroupMembersRequestComplete = NULL;

    if (!pFnOnQueryGroupMembersRequestComplete)
        pFnOnQueryGroupMembersRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38632];

    UMcpGroupsManager_execOnQueryGroupMembersRequestComplete_Parms
        OnQueryGroupMembersRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryGroupMembersRequestComplete,
                       &OnQueryGroupMembersRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.QueryGroupMembers
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::QueryGroupMembers() {
    static UFunction* pFnQueryGroupMembers = NULL;

    if (!pFnQueryGroupMembers)
        pFnQueryGroupMembers = (UFunction*)UObject::GObjObjects()->Data[38627];

    UMcpGroupsManager_execQueryGroupMembers_Parms QueryGroupMembers_Parms;

    this->ProcessEvent(pFnQueryGroupMembers, &QueryGroupMembers_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.GetGroupList
// [0x00420002]
// Parameters infos:

void UMcpGroupsManager::GetGroupList() {
    static UFunction* pFnGetGroupList = NULL;

    if (!pFnGetGroupList)
        pFnGetGroupList = (UFunction*)UObject::GObjObjects()->Data[38623];

    UMcpGroupsManager_execGetGroupList_Parms GetGroupList_Parms;

    this->ProcessEvent(pFnGetGroupList, &GetGroupList_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnQueryGroupsRequestComplete
// [0x00920002]
// Parameters infos:

void UMcpGroupsManager::OnQueryGroupsRequestComplete() {
    static UFunction* pFnOnQueryGroupsRequestComplete = NULL;

    if (!pFnOnQueryGroupsRequestComplete)
        pFnOnQueryGroupsRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38612];

    UMcpGroupsManager_execOnQueryGroupsRequestComplete_Parms
        OnQueryGroupsRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryGroupsRequestComplete,
                       &OnQueryGroupsRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.QueryGroups
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::QueryGroups() {
    static UFunction* pFnQueryGroups = NULL;

    if (!pFnQueryGroups)
        pFnQueryGroups = (UFunction*)UObject::GObjObjects()->Data[38608];

    UMcpGroupsManager_execQueryGroups_Parms QueryGroups_Parms;

    this->ProcessEvent(pFnQueryGroups, &QueryGroups_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnDeleteGroupRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::OnDeleteGroupRequestComplete() {
    static UFunction* pFnOnDeleteGroupRequestComplete = NULL;

    if (!pFnOnDeleteGroupRequestComplete)
        pFnOnDeleteGroupRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38601];

    UMcpGroupsManager_execOnDeleteGroupRequestComplete_Parms
        OnDeleteGroupRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteGroupRequestComplete,
                       &OnDeleteGroupRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.DeleteGroup
// [0x00020002]
// Parameters infos:

void UMcpGroupsManager::DeleteGroup() {
    static UFunction* pFnDeleteGroup = NULL;

    if (!pFnDeleteGroup)
        pFnDeleteGroup = (UFunction*)UObject::GObjObjects()->Data[38596];

    UMcpGroupsManager_execDeleteGroup_Parms DeleteGroup_Parms;

    this->ProcessEvent(pFnDeleteGroup, &DeleteGroup_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.OnCreateGroupRequestComplete
// [0x00820002]
// Parameters infos:

void UMcpGroupsManager::OnCreateGroupRequestComplete() {
    static UFunction* pFnOnCreateGroupRequestComplete = NULL;

    if (!pFnOnCreateGroupRequestComplete)
        pFnOnCreateGroupRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38587];

    UMcpGroupsManager_execOnCreateGroupRequestComplete_Parms
        OnCreateGroupRequestComplete_Parms;

    this->ProcessEvent(pFnOnCreateGroupRequestComplete,
                       &OnCreateGroupRequestComplete_Parms, NULL);
};

// Function IpDrv.McpGroupsManager.CreateGroup
// [0x00820002]
// Parameters infos:

void UMcpGroupsManager::CreateGroup() {
    static UFunction* pFnCreateGroup = NULL;

    if (!pFnCreateGroup)
        pFnCreateGroup = (UFunction*)UObject::GObjObjects()->Data[38581];

    UMcpGroupsManager_execCreateGroup_Parms CreateGroup_Parms;

    this->ProcessEvent(pFnCreateGroup, &CreateGroup_Parms, NULL);
};

// Function IpDrv.McpIdMappingBase.GetIdMappings
// [0x00420000]
// Parameters infos:

void UMcpIdMappingBase::GetIdMappings() {
    static UFunction* pFnGetIdMappings = NULL;

    if (!pFnGetIdMappings)
        pFnGetIdMappings = (UFunction*)UObject::GObjObjects()->Data[38757];

    UMcpIdMappingBase_execGetIdMappings_Parms GetIdMappings_Parms;

    this->ProcessEvent(pFnGetIdMappings, &GetIdMappings_Parms, NULL);
};

// Function IpDrv.McpIdMappingBase.OnQueryMappingsComplete
// [0x00120000]
// Parameters infos:

void UMcpIdMappingBase::OnQueryMappingsComplete() {
    static UFunction* pFnOnQueryMappingsComplete = NULL;

    if (!pFnOnQueryMappingsComplete)
        pFnOnQueryMappingsComplete =
            (UFunction*)UObject::GObjObjects()->Data[38753];

    UMcpIdMappingBase_execOnQueryMappingsComplete_Parms
        OnQueryMappingsComplete_Parms;

    this->ProcessEvent(pFnOnQueryMappingsComplete,
                       &OnQueryMappingsComplete_Parms, NULL);
};

// Function IpDrv.McpIdMappingBase.QueryMappings
// [0x00420000]
// Parameters infos:

void UMcpIdMappingBase::QueryMappings() {
    static UFunction* pFnQueryMappings = NULL;

    if (!pFnQueryMappings)
        pFnQueryMappings = (UFunction*)UObject::GObjObjects()->Data[38749];

    UMcpIdMappingBase_execQueryMappings_Parms QueryMappings_Parms;

    this->ProcessEvent(pFnQueryMappings, &QueryMappings_Parms, NULL);
};

// Function IpDrv.McpIdMappingBase.OnAddMappingComplete
// [0x00120000]
// Parameters infos:

void UMcpIdMappingBase::OnAddMappingComplete() {
    static UFunction* pFnOnAddMappingComplete = NULL;

    if (!pFnOnAddMappingComplete)
        pFnOnAddMappingComplete =
            (UFunction*)UObject::GObjObjects()->Data[38743];

    UMcpIdMappingBase_execOnAddMappingComplete_Parms OnAddMappingComplete_Parms;

    this->ProcessEvent(pFnOnAddMappingComplete, &OnAddMappingComplete_Parms,
                       NULL);
};

// Function IpDrv.McpIdMappingBase.AddMapping
// [0x00020000]
// Parameters infos:

void UMcpIdMappingBase::AddMapping() {
    static UFunction* pFnAddMapping = NULL;

    if (!pFnAddMapping)
        pFnAddMapping = (UFunction*)UObject::GObjObjects()->Data[38739];

    UMcpIdMappingBase_execAddMapping_Parms AddMapping_Parms;

    this->ProcessEvent(pFnAddMapping, &AddMapping_Parms, NULL);
};

// Function IpDrv.McpIdMappingBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpIdMappingBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[38735];

    UMcpIdMappingBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpIdMappingManager.GetIdMappings
// [0x00420002]
// Parameters infos:

void UMcpIdMappingManager::GetIdMappings() {
    static UFunction* pFnGetIdMappings = NULL;

    if (!pFnGetIdMappings)
        pFnGetIdMappings = (UFunction*)UObject::GObjObjects()->Data[38818];

    UMcpIdMappingManager_execGetIdMappings_Parms GetIdMappings_Parms;

    this->ProcessEvent(pFnGetIdMappings, &GetIdMappings_Parms, NULL);
};

// Function IpDrv.McpIdMappingManager.OnQueryMappingsRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpIdMappingManager::OnQueryMappingsRequestComplete() {
    static UFunction* pFnOnQueryMappingsRequestComplete = NULL;

    if (!pFnOnQueryMappingsRequestComplete)
        pFnOnQueryMappingsRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38803];

    UMcpIdMappingManager_execOnQueryMappingsRequestComplete_Parms
        OnQueryMappingsRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryMappingsRequestComplete,
                       &OnQueryMappingsRequestComplete_Parms, NULL);
};

// Function IpDrv.McpIdMappingManager.QueryMappings
// [0x00420002]
// Parameters infos:

void UMcpIdMappingManager::QueryMappings() {
    static UFunction* pFnQueryMappings = NULL;

    if (!pFnQueryMappings)
        pFnQueryMappings = (UFunction*)UObject::GObjObjects()->Data[38793];

    UMcpIdMappingManager_execQueryMappings_Parms QueryMappings_Parms;

    this->ProcessEvent(pFnQueryMappings, &QueryMappings_Parms, NULL);
};

// Function IpDrv.McpIdMappingManager.OnAddMappingRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpIdMappingManager::OnAddMappingRequestComplete() {
    static UFunction* pFnOnAddMappingRequestComplete = NULL;

    if (!pFnOnAddMappingRequestComplete)
        pFnOnAddMappingRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38786];

    UMcpIdMappingManager_execOnAddMappingRequestComplete_Parms
        OnAddMappingRequestComplete_Parms;

    this->ProcessEvent(pFnOnAddMappingRequestComplete,
                       &OnAddMappingRequestComplete_Parms, NULL);
};

// Function IpDrv.McpIdMappingManager.AddMapping
// [0x00020002]
// Parameters infos:

void UMcpIdMappingManager::AddMapping() {
    static UFunction* pFnAddMapping = NULL;

    if (!pFnAddMapping)
        pFnAddMapping = (UFunction*)UObject::GObjObjects()->Data[38779];

    UMcpIdMappingManager_execAddMapping_Parms AddMapping_Parms;

    this->ProcessEvent(pFnAddMapping, &AddMapping_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.OnDeleteValueComplete
// [0x00120000]
// Parameters infos:

void UMcpManagedValueManagerBase::OnDeleteValueComplete() {
    static UFunction* pFnOnDeleteValueComplete = NULL;

    if (!pFnOnDeleteValueComplete)
        pFnOnDeleteValueComplete =
            (UFunction*)UObject::GObjObjects()->Data[38885];

    UMcpManagedValueManagerBase_execOnDeleteValueComplete_Parms
        OnDeleteValueComplete_Parms;

    this->ProcessEvent(pFnOnDeleteValueComplete, &OnDeleteValueComplete_Parms,
                       NULL);
};

// Function IpDrv.McpManagedValueManagerBase.DeleteValue
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::DeleteValue() {
    static UFunction* pFnDeleteValue = NULL;

    if (!pFnDeleteValue)
        pFnDeleteValue = (UFunction*)UObject::GObjObjects()->Data[38881];

    UMcpManagedValueManagerBase_execDeleteValue_Parms DeleteValue_Parms;

    this->ProcessEvent(pFnDeleteValue, &DeleteValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.OnUpdateValueComplete
// [0x00120000]
// Parameters infos:

void UMcpManagedValueManagerBase::OnUpdateValueComplete() {
    static UFunction* pFnOnUpdateValueComplete = NULL;

    if (!pFnOnUpdateValueComplete)
        pFnOnUpdateValueComplete =
            (UFunction*)UObject::GObjObjects()->Data[38874];

    UMcpManagedValueManagerBase_execOnUpdateValueComplete_Parms
        OnUpdateValueComplete_Parms;

    this->ProcessEvent(pFnOnUpdateValueComplete, &OnUpdateValueComplete_Parms,
                       NULL);
};

// Function IpDrv.McpManagedValueManagerBase.UpdateValue
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::UpdateValue() {
    static UFunction* pFnUpdateValue = NULL;

    if (!pFnUpdateValue)
        pFnUpdateValue = (UFunction*)UObject::GObjObjects()->Data[38869];

    UMcpManagedValueManagerBase_execUpdateValue_Parms UpdateValue_Parms;

    this->ProcessEvent(pFnUpdateValue, &UpdateValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.GetValue
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::GetValue() {
    static UFunction* pFnGetValue = NULL;

    if (!pFnGetValue)
        pFnGetValue = (UFunction*)UObject::GObjObjects()->Data[38864];

    UMcpManagedValueManagerBase_execGetValue_Parms GetValue_Parms;

    this->ProcessEvent(pFnGetValue, &GetValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.GetValues
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::GetValues() {
    static UFunction* pFnGetValues = NULL;

    if (!pFnGetValues)
        pFnGetValues = (UFunction*)UObject::GObjObjects()->Data[38859];

    UMcpManagedValueManagerBase_execGetValues_Parms GetValues_Parms;

    this->ProcessEvent(pFnGetValues, &GetValues_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.OnReadSaveSlotComplete
// [0x00120000]
// Parameters infos:

void UMcpManagedValueManagerBase::OnReadSaveSlotComplete() {
    static UFunction* pFnOnReadSaveSlotComplete = NULL;

    if (!pFnOnReadSaveSlotComplete)
        pFnOnReadSaveSlotComplete =
            (UFunction*)UObject::GObjObjects()->Data[38854];

    UMcpManagedValueManagerBase_execOnReadSaveSlotComplete_Parms
        OnReadSaveSlotComplete_Parms;

    this->ProcessEvent(pFnOnReadSaveSlotComplete, &OnReadSaveSlotComplete_Parms,
                       NULL);
};

// Function IpDrv.McpManagedValueManagerBase.ReadSaveSlot
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::ReadSaveSlot() {
    static UFunction* pFnReadSaveSlot = NULL;

    if (!pFnReadSaveSlot)
        pFnReadSaveSlot = (UFunction*)UObject::GObjObjects()->Data[38851];

    UMcpManagedValueManagerBase_execReadSaveSlot_Parms ReadSaveSlot_Parms;

    this->ProcessEvent(pFnReadSaveSlot, &ReadSaveSlot_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.OnCreateSaveSlotComplete
// [0x00120000]
// Parameters infos:

void UMcpManagedValueManagerBase::OnCreateSaveSlotComplete() {
    static UFunction* pFnOnCreateSaveSlotComplete = NULL;

    if (!pFnOnCreateSaveSlotComplete)
        pFnOnCreateSaveSlotComplete =
            (UFunction*)UObject::GObjObjects()->Data[38846];

    UMcpManagedValueManagerBase_execOnCreateSaveSlotComplete_Parms
        OnCreateSaveSlotComplete_Parms;

    this->ProcessEvent(pFnOnCreateSaveSlotComplete,
                       &OnCreateSaveSlotComplete_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.CreateSaveSlot
// [0x00020000]
// Parameters infos:

void UMcpManagedValueManagerBase::CreateSaveSlot() {
    static UFunction* pFnCreateSaveSlot = NULL;

    if (!pFnCreateSaveSlot)
        pFnCreateSaveSlot = (UFunction*)UObject::GObjObjects()->Data[38843];

    UMcpManagedValueManagerBase_execCreateSaveSlot_Parms CreateSaveSlot_Parms;

    this->ProcessEvent(pFnCreateSaveSlot, &CreateSaveSlot_Parms, NULL);
};

// Function IpDrv.McpManagedValueManagerBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpManagedValueManagerBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[38839];

    UMcpManagedValueManagerBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.OnDeleteValueRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::OnDeleteValueRequestComplete() {
    static UFunction* pFnOnDeleteValueRequestComplete = NULL;

    if (!pFnOnDeleteValueRequestComplete)
        pFnOnDeleteValueRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38993];

    UMcpManagedValueManager_execOnDeleteValueRequestComplete_Parms
        OnDeleteValueRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteValueRequestComplete,
                       &OnDeleteValueRequestComplete_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.DeleteValue
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::DeleteValue() {
    static UFunction* pFnDeleteValue = NULL;

    if (!pFnDeleteValue)
        pFnDeleteValue = (UFunction*)UObject::GObjObjects()->Data[38986];

    UMcpManagedValueManager_execDeleteValue_Parms DeleteValue_Parms;

    this->ProcessEvent(pFnDeleteValue, &DeleteValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.OnUpdateValueRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::OnUpdateValueRequestComplete() {
    static UFunction* pFnOnUpdateValueRequestComplete = NULL;

    if (!pFnOnUpdateValueRequestComplete)
        pFnOnUpdateValueRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38978];

    UMcpManagedValueManager_execOnUpdateValueRequestComplete_Parms
        OnUpdateValueRequestComplete_Parms;

    this->ProcessEvent(pFnOnUpdateValueRequestComplete,
                       &OnUpdateValueRequestComplete_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.UpdateValue
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::UpdateValue() {
    static UFunction* pFnUpdateValue = NULL;

    if (!pFnUpdateValue)
        pFnUpdateValue = (UFunction*)UObject::GObjObjects()->Data[38970];

    UMcpManagedValueManager_execUpdateValue_Parms UpdateValue_Parms;

    this->ProcessEvent(pFnUpdateValue, &UpdateValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.GetValue
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::GetValue() {
    static UFunction* pFnGetValue = NULL;

    if (!pFnGetValue)
        pFnGetValue = (UFunction*)UObject::GObjObjects()->Data[38962];

    UMcpManagedValueManager_execGetValue_Parms GetValue_Parms;

    this->ProcessEvent(pFnGetValue, &GetValue_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.GetValues
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::GetValues() {
    static UFunction* pFnGetValues = NULL;

    if (!pFnGetValues)
        pFnGetValues = (UFunction*)UObject::GObjObjects()->Data[38954];

    UMcpManagedValueManager_execGetValues_Parms GetValues_Parms;

    this->ProcessEvent(pFnGetValues, &GetValues_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.OnReadSaveSlotRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::OnReadSaveSlotRequestComplete() {
    static UFunction* pFnOnReadSaveSlotRequestComplete = NULL;

    if (!pFnOnReadSaveSlotRequestComplete)
        pFnOnReadSaveSlotRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38947];

    UMcpManagedValueManager_execOnReadSaveSlotRequestComplete_Parms
        OnReadSaveSlotRequestComplete_Parms;

    this->ProcessEvent(pFnOnReadSaveSlotRequestComplete,
                       &OnReadSaveSlotRequestComplete_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.ReadSaveSlot
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::ReadSaveSlot() {
    static UFunction* pFnReadSaveSlot = NULL;

    if (!pFnReadSaveSlot)
        pFnReadSaveSlot = (UFunction*)UObject::GObjObjects()->Data[38941];

    UMcpManagedValueManager_execReadSaveSlot_Parms ReadSaveSlot_Parms;

    this->ProcessEvent(pFnReadSaveSlot, &ReadSaveSlot_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.ParseValuesForSaveSlot
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::ParseValuesForSaveSlot() {
    static UFunction* pFnParseValuesForSaveSlot = NULL;

    if (!pFnParseValuesForSaveSlot)
        pFnParseValuesForSaveSlot =
            (UFunction*)UObject::GObjObjects()->Data[38931];

    UMcpManagedValueManager_execParseValuesForSaveSlot_Parms
        ParseValuesForSaveSlot_Parms;

    this->ProcessEvent(pFnParseValuesForSaveSlot, &ParseValuesForSaveSlot_Parms,
                       NULL);
};

// Function IpDrv.McpManagedValueManager.FindSaveSlotIndex
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::FindSaveSlotIndex() {
    static UFunction* pFnFindSaveSlotIndex = NULL;

    if (!pFnFindSaveSlotIndex)
        pFnFindSaveSlotIndex = (UFunction*)UObject::GObjObjects()->Data[38926];

    UMcpManagedValueManager_execFindSaveSlotIndex_Parms FindSaveSlotIndex_Parms;

    this->ProcessEvent(pFnFindSaveSlotIndex, &FindSaveSlotIndex_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.OnCreateSaveSlotRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::OnCreateSaveSlotRequestComplete() {
    static UFunction* pFnOnCreateSaveSlotRequestComplete = NULL;

    if (!pFnOnCreateSaveSlotRequestComplete)
        pFnOnCreateSaveSlotRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[38919];

    UMcpManagedValueManager_execOnCreateSaveSlotRequestComplete_Parms
        OnCreateSaveSlotRequestComplete_Parms;

    this->ProcessEvent(pFnOnCreateSaveSlotRequestComplete,
                       &OnCreateSaveSlotRequestComplete_Parms, NULL);
};

// Function IpDrv.McpManagedValueManager.CreateSaveSlot
// [0x00020002]
// Parameters infos:

void UMcpManagedValueManager::CreateSaveSlot() {
    static UFunction* pFnCreateSaveSlot = NULL;

    if (!pFnCreateSaveSlot)
        pFnCreateSaveSlot = (UFunction*)UObject::GObjObjects()->Data[38913];

    UMcpManagedValueManager_execCreateSaveSlot_Parms CreateSaveSlot_Parms;

    this->ProcessEvent(pFnCreateSaveSlot, &CreateSaveSlot_Parms, NULL);
};

// Function IpDrv.McpServerTimeBase.GetLastServerTime
// [0x00020000]
// Parameters infos:

void UMcpServerTimeBase::GetLastServerTime() {
    static UFunction* pFnGetLastServerTime = NULL;

    if (!pFnGetLastServerTime)
        pFnGetLastServerTime = (UFunction*)UObject::GObjObjects()->Data[39228];

    UMcpServerTimeBase_execGetLastServerTime_Parms GetLastServerTime_Parms;

    this->ProcessEvent(pFnGetLastServerTime, &GetLastServerTime_Parms, NULL);
};

// Function IpDrv.McpServerTimeBase.OnQueryServerTimeComplete
// [0x00120000]
// Parameters infos:

void UMcpServerTimeBase::OnQueryServerTimeComplete() {
    static UFunction* pFnOnQueryServerTimeComplete = NULL;

    if (!pFnOnQueryServerTimeComplete)
        pFnOnQueryServerTimeComplete =
            (UFunction*)UObject::GObjObjects()->Data[39224];

    UMcpServerTimeBase_execOnQueryServerTimeComplete_Parms
        OnQueryServerTimeComplete_Parms;

    this->ProcessEvent(pFnOnQueryServerTimeComplete,
                       &OnQueryServerTimeComplete_Parms, NULL);
};

// Function IpDrv.McpServerTimeBase.QueryServerTime
// [0x00020000]
// Parameters infos:

void UMcpServerTimeBase::QueryServerTime() {
    static UFunction* pFnQueryServerTime = NULL;

    if (!pFnQueryServerTime)
        pFnQueryServerTime = (UFunction*)UObject::GObjObjects()->Data[39223];

    UMcpServerTimeBase_execQueryServerTime_Parms QueryServerTime_Parms;

    this->ProcessEvent(pFnQueryServerTime, &QueryServerTime_Parms, NULL);
};

// Function IpDrv.McpServerTimeBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpServerTimeBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[39219];

    UMcpServerTimeBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpServerTimeManager.GetLastServerTime
// [0x00020002]
// Parameters infos:

void UMcpServerTimeManager::GetLastServerTime() {
    static UFunction* pFnGetLastServerTime = NULL;

    if (!pFnGetLastServerTime)
        pFnGetLastServerTime = (UFunction*)UObject::GObjObjects()->Data[39248];

    UMcpServerTimeManager_execGetLastServerTime_Parms GetLastServerTime_Parms;

    this->ProcessEvent(pFnGetLastServerTime, &GetLastServerTime_Parms, NULL);
};

// Function IpDrv.McpServerTimeManager.OnQueryServerTimeHTTPRequestComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UMcpServerTimeManager::OnQueryServerTimeHTTPRequestComplete() {
    static UFunction* pFnOnQueryServerTimeHTTPRequestComplete = NULL;

    if (!pFnOnQueryServerTimeHTTPRequestComplete)
        pFnOnQueryServerTimeHTTPRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39239];

    UMcpServerTimeManager_execOnQueryServerTimeHTTPRequestComplete_Parms
        OnQueryServerTimeHTTPRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryServerTimeHTTPRequestComplete,
                       &OnQueryServerTimeHTTPRequestComplete_Parms, NULL);
};

// Function IpDrv.McpServerTimeManager.QueryServerTime
// [0x00020002]
// Parameters infos:

void UMcpServerTimeManager::QueryServerTime() {
    static UFunction* pFnQueryServerTime = NULL;

    if (!pFnQueryServerTime)
        pFnQueryServerTime = (UFunction*)UObject::GObjObjects()->Data[39235];

    UMcpServerTimeManager_execQueryServerTime_Parms QueryServerTime_Parms;

    this->ProcessEvent(pFnQueryServerTime, &QueryServerTime_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnRecordIapComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnRecordIapComplete() {
    static UFunction* pFnOnRecordIapComplete = NULL;

    if (!pFnOnRecordIapComplete)
        pFnOnRecordIapComplete =
            (UFunction*)UObject::GObjObjects()->Data[39603];

    UMcpUserInventoryBase_execOnRecordIapComplete_Parms
        OnRecordIapComplete_Parms;

    this->ProcessEvent(pFnOnRecordIapComplete, &OnRecordIapComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryBase.RecordIap
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::RecordIap() {
    static UFunction* pFnRecordIap = NULL;

    if (!pFnRecordIap)
        pFnRecordIap = (UFunction*)UObject::GObjObjects()->Data[39599];

    UMcpUserInventoryBase_execRecordIap_Parms RecordIap_Parms;

    this->ProcessEvent(pFnRecordIap, &RecordIap_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnDeleteItemComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnDeleteItemComplete() {
    static UFunction* pFnOnDeleteItemComplete = NULL;

    if (!pFnOnDeleteItemComplete)
        pFnOnDeleteItemComplete =
            (UFunction*)UObject::GObjObjects()->Data[39593];

    UMcpUserInventoryBase_execOnDeleteItemComplete_Parms
        OnDeleteItemComplete_Parms;

    this->ProcessEvent(pFnOnDeleteItemComplete, &OnDeleteItemComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryBase.DeleteItem
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::DeleteItem() {
    static UFunction* pFnDeleteItem = NULL;

    if (!pFnDeleteItem)
        pFnDeleteItem = (UFunction*)UObject::GObjObjects()->Data[39588];

    UMcpUserInventoryBase_execDeleteItem_Parms DeleteItem_Parms;

    this->ProcessEvent(pFnDeleteItem, &DeleteItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnConsumeItemComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnConsumeItemComplete() {
    static UFunction* pFnOnConsumeItemComplete = NULL;

    if (!pFnOnConsumeItemComplete)
        pFnOnConsumeItemComplete =
            (UFunction*)UObject::GObjObjects()->Data[39580];

    UMcpUserInventoryBase_execOnConsumeItemComplete_Parms
        OnConsumeItemComplete_Parms;

    this->ProcessEvent(pFnOnConsumeItemComplete, &OnConsumeItemComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryBase.ConsumeItem
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::ConsumeItem() {
    static UFunction* pFnConsumeItem = NULL;

    if (!pFnConsumeItem)
        pFnConsumeItem = (UFunction*)UObject::GObjObjects()->Data[39574];

    UMcpUserInventoryBase_execConsumeItem_Parms ConsumeItem_Parms;

    this->ProcessEvent(pFnConsumeItem, &ConsumeItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnEarnItemComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnEarnItemComplete() {
    static UFunction* pFnOnEarnItemComplete = NULL;

    if (!pFnOnEarnItemComplete)
        pFnOnEarnItemComplete = (UFunction*)UObject::GObjObjects()->Data[39566];

    UMcpUserInventoryBase_execOnEarnItemComplete_Parms OnEarnItemComplete_Parms;

    this->ProcessEvent(pFnOnEarnItemComplete, &OnEarnItemComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.EarnItem
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::EarnItem() {
    static UFunction* pFnEarnItem = NULL;

    if (!pFnEarnItem)
        pFnEarnItem = (UFunction*)UObject::GObjObjects()->Data[39560];

    UMcpUserInventoryBase_execEarnItem_Parms EarnItem_Parms;

    this->ProcessEvent(pFnEarnItem, &EarnItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnSellItemComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnSellItemComplete() {
    static UFunction* pFnOnSellItemComplete = NULL;

    if (!pFnOnSellItemComplete)
        pFnOnSellItemComplete = (UFunction*)UObject::GObjObjects()->Data[39552];

    UMcpUserInventoryBase_execOnSellItemComplete_Parms OnSellItemComplete_Parms;

    this->ProcessEvent(pFnOnSellItemComplete, &OnSellItemComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.SellItem
// [0x00424000]
// Parameters infos:

void UMcpUserInventoryBase::SellItem() {
    static UFunction* pFnSellItem = NULL;

    if (!pFnSellItem)
        pFnSellItem = (UFunction*)UObject::GObjObjects()->Data[39544];

    UMcpUserInventoryBase_execSellItem_Parms SellItem_Parms;

    this->ProcessEvent(pFnSellItem, &SellItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnPurchaseItemComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnPurchaseItemComplete() {
    static UFunction* pFnOnPurchaseItemComplete = NULL;

    if (!pFnOnPurchaseItemComplete)
        pFnOnPurchaseItemComplete =
            (UFunction*)UObject::GObjObjects()->Data[39536];

    UMcpUserInventoryBase_execOnPurchaseItemComplete_Parms
        OnPurchaseItemComplete_Parms;

    this->ProcessEvent(pFnOnPurchaseItemComplete, &OnPurchaseItemComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryBase.PurchaseItem
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::PurchaseItem() {
    static UFunction* pFnPurchaseItem = NULL;

    if (!pFnPurchaseItem)
        pFnPurchaseItem = (UFunction*)UObject::GObjObjects()->Data[39527];

    UMcpUserInventoryBase_execPurchaseItem_Parms PurchaseItem_Parms;

    this->ProcessEvent(pFnPurchaseItem, &PurchaseItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.GetInventoryItem
// [0x00420000]
// Parameters infos:

void UMcpUserInventoryBase::GetInventoryItem() {
    static UFunction* pFnGetInventoryItem = NULL;

    if (!pFnGetInventoryItem)
        pFnGetInventoryItem = (UFunction*)UObject::GObjObjects()->Data[39521];

    UMcpUserInventoryBase_execGetInventoryItem_Parms GetInventoryItem_Parms;

    this->ProcessEvent(pFnGetInventoryItem, &GetInventoryItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.GetInventoryItems
// [0x00420000]
// Parameters infos:

void UMcpUserInventoryBase::GetInventoryItems() {
    static UFunction* pFnGetInventoryItems = NULL;

    if (!pFnGetInventoryItems)
        pFnGetInventoryItems = (UFunction*)UObject::GObjObjects()->Data[39516];

    UMcpUserInventoryBase_execGetInventoryItems_Parms GetInventoryItems_Parms;

    this->ProcessEvent(pFnGetInventoryItems, &GetInventoryItems_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnQueryInventoryItemsComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnQueryInventoryItemsComplete() {
    static UFunction* pFnOnQueryInventoryItemsComplete = NULL;

    if (!pFnOnQueryInventoryItemsComplete)
        pFnOnQueryInventoryItemsComplete =
            (UFunction*)UObject::GObjObjects()->Data[39511];

    UMcpUserInventoryBase_execOnQueryInventoryItemsComplete_Parms
        OnQueryInventoryItemsComplete_Parms;

    this->ProcessEvent(pFnOnQueryInventoryItemsComplete,
                       &OnQueryInventoryItemsComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.QueryInventoryItems
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::QueryInventoryItems() {
    static UFunction* pFnQueryInventoryItems = NULL;

    if (!pFnQueryInventoryItems)
        pFnQueryInventoryItems =
            (UFunction*)UObject::GObjObjects()->Data[39508];

    UMcpUserInventoryBase_execQueryInventoryItems_Parms
        QueryInventoryItems_Parms;

    this->ProcessEvent(pFnQueryInventoryItems, &QueryInventoryItems_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryBase.OnQuerySaveSlotListComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnQuerySaveSlotListComplete() {
    static UFunction* pFnOnQuerySaveSlotListComplete = NULL;

    if (!pFnOnQuerySaveSlotListComplete)
        pFnOnQuerySaveSlotListComplete =
            (UFunction*)UObject::GObjObjects()->Data[39504];

    UMcpUserInventoryBase_execOnQuerySaveSlotListComplete_Parms
        OnQuerySaveSlotListComplete_Parms;

    this->ProcessEvent(pFnOnQuerySaveSlotListComplete,
                       &OnQuerySaveSlotListComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.GetSaveSlotList
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::GetSaveSlotList() {
    static UFunction* pFnGetSaveSlotList = NULL;

    if (!pFnGetSaveSlotList)
        pFnGetSaveSlotList = (UFunction*)UObject::GObjObjects()->Data[39500];

    UMcpUserInventoryBase_execGetSaveSlotList_Parms GetSaveSlotList_Parms;

    this->ProcessEvent(pFnGetSaveSlotList, &GetSaveSlotList_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.QuerySaveSlotList
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::QuerySaveSlotList() {
    static UFunction* pFnQuerySaveSlotList = NULL;

    if (!pFnQuerySaveSlotList)
        pFnQuerySaveSlotList = (UFunction*)UObject::GObjObjects()->Data[39498];

    UMcpUserInventoryBase_execQuerySaveSlotList_Parms QuerySaveSlotList_Parms;

    this->ProcessEvent(pFnQuerySaveSlotList, &QuerySaveSlotList_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnDeleteSaveSlotComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnDeleteSaveSlotComplete() {
    static UFunction* pFnOnDeleteSaveSlotComplete = NULL;

    if (!pFnOnDeleteSaveSlotComplete)
        pFnOnDeleteSaveSlotComplete =
            (UFunction*)UObject::GObjObjects()->Data[39493];

    UMcpUserInventoryBase_execOnDeleteSaveSlotComplete_Parms
        OnDeleteSaveSlotComplete_Parms;

    this->ProcessEvent(pFnOnDeleteSaveSlotComplete,
                       &OnDeleteSaveSlotComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.DeleteSaveSlot
// [0x00020000]
// Parameters infos:

void UMcpUserInventoryBase::DeleteSaveSlot() {
    static UFunction* pFnDeleteSaveSlot = NULL;

    if (!pFnDeleteSaveSlot)
        pFnDeleteSaveSlot = (UFunction*)UObject::GObjObjects()->Data[39490];

    UMcpUserInventoryBase_execDeleteSaveSlot_Parms DeleteSaveSlot_Parms;

    this->ProcessEvent(pFnDeleteSaveSlot, &DeleteSaveSlot_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.OnCreateSaveSlotComplete
// [0x00120000]
// Parameters infos:

void UMcpUserInventoryBase::OnCreateSaveSlotComplete() {
    static UFunction* pFnOnCreateSaveSlotComplete = NULL;

    if (!pFnOnCreateSaveSlotComplete)
        pFnOnCreateSaveSlotComplete =
            (UFunction*)UObject::GObjObjects()->Data[39485];

    UMcpUserInventoryBase_execOnCreateSaveSlotComplete_Parms
        OnCreateSaveSlotComplete_Parms;

    this->ProcessEvent(pFnOnCreateSaveSlotComplete,
                       &OnCreateSaveSlotComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.CreateSaveSlot
// [0x00024000]
// Parameters infos:

void UMcpUserInventoryBase::CreateSaveSlot() {
    static UFunction* pFnCreateSaveSlot = NULL;

    if (!pFnCreateSaveSlot)
        pFnCreateSaveSlot = (UFunction*)UObject::GObjObjects()->Data[39481];

    UMcpUserInventoryBase_execCreateSaveSlot_Parms CreateSaveSlot_Parms;

    this->ProcessEvent(pFnCreateSaveSlot, &CreateSaveSlot_Parms, NULL);
};

// Function IpDrv.McpUserInventoryBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpUserInventoryBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[39477];

    UMcpUserInventoryBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnRecordIapRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnRecordIapRequestComplete() {
    static UFunction* pFnOnRecordIapRequestComplete = NULL;

    if (!pFnOnRecordIapRequestComplete)
        pFnOnRecordIapRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39878];

    UMcpUserInventoryManager_execOnRecordIapRequestComplete_Parms
        OnRecordIapRequestComplete_Parms;

    this->ProcessEvent(pFnOnRecordIapRequestComplete,
                       &OnRecordIapRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.RecordIap
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::RecordIap() {
    static UFunction* pFnRecordIap = NULL;

    if (!pFnRecordIap)
        pFnRecordIap = (UFunction*)UObject::GObjObjects()->Data[39870];

    UMcpUserInventoryManager_execRecordIap_Parms RecordIap_Parms;

    this->ProcessEvent(pFnRecordIap, &RecordIap_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnDeleteItemRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnDeleteItemRequestComplete() {
    static UFunction* pFnOnDeleteItemRequestComplete = NULL;

    if (!pFnOnDeleteItemRequestComplete)
        pFnOnDeleteItemRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39862];

    UMcpUserInventoryManager_execOnDeleteItemRequestComplete_Parms
        OnDeleteItemRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteItemRequestComplete,
                       &OnDeleteItemRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.DeleteItem
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::DeleteItem() {
    static UFunction* pFnDeleteItem = NULL;

    if (!pFnDeleteItem)
        pFnDeleteItem = (UFunction*)UObject::GObjObjects()->Data[39853];

    UMcpUserInventoryManager_execDeleteItem_Parms DeleteItem_Parms;

    this->ProcessEvent(pFnDeleteItem, &DeleteItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnConsumeItemRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnConsumeItemRequestComplete() {
    static UFunction* pFnOnConsumeItemRequestComplete = NULL;

    if (!pFnOnConsumeItemRequestComplete)
        pFnOnConsumeItemRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39844];

    UMcpUserInventoryManager_execOnConsumeItemRequestComplete_Parms
        OnConsumeItemRequestComplete_Parms;

    this->ProcessEvent(pFnOnConsumeItemRequestComplete,
                       &OnConsumeItemRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.ConsumeItem
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::ConsumeItem() {
    static UFunction* pFnConsumeItem = NULL;

    if (!pFnConsumeItem)
        pFnConsumeItem = (UFunction*)UObject::GObjObjects()->Data[39834];

    UMcpUserInventoryManager_execConsumeItem_Parms ConsumeItem_Parms;

    this->ProcessEvent(pFnConsumeItem, &ConsumeItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnEarnItemRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnEarnItemRequestComplete() {
    static UFunction* pFnOnEarnItemRequestComplete = NULL;

    if (!pFnOnEarnItemRequestComplete)
        pFnOnEarnItemRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39825];

    UMcpUserInventoryManager_execOnEarnItemRequestComplete_Parms
        OnEarnItemRequestComplete_Parms;

    this->ProcessEvent(pFnOnEarnItemRequestComplete,
                       &OnEarnItemRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.EarnItem
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::EarnItem() {
    static UFunction* pFnEarnItem = NULL;

    if (!pFnEarnItem)
        pFnEarnItem = (UFunction*)UObject::GObjObjects()->Data[39815];

    UMcpUserInventoryManager_execEarnItem_Parms EarnItem_Parms;

    this->ProcessEvent(pFnEarnItem, &EarnItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnSellItemRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnSellItemRequestComplete() {
    static UFunction* pFnOnSellItemRequestComplete = NULL;

    if (!pFnOnSellItemRequestComplete)
        pFnOnSellItemRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39803];

    UMcpUserInventoryManager_execOnSellItemRequestComplete_Parms
        OnSellItemRequestComplete_Parms;

    this->ProcessEvent(pFnOnSellItemRequestComplete,
                       &OnSellItemRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.SellItem
// [0x00424002]
// Parameters infos:

void UMcpUserInventoryManager::SellItem() {
    static UFunction* pFnSellItem = NULL;

    if (!pFnSellItem)
        pFnSellItem = (UFunction*)UObject::GObjObjects()->Data[39789];

    UMcpUserInventoryManager_execSellItem_Parms SellItem_Parms;

    this->ProcessEvent(pFnSellItem, &SellItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnPurchaseItemRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnPurchaseItemRequestComplete() {
    static UFunction* pFnOnPurchaseItemRequestComplete = NULL;

    if (!pFnOnPurchaseItemRequestComplete)
        pFnOnPurchaseItemRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39777];

    UMcpUserInventoryManager_execOnPurchaseItemRequestComplete_Parms
        OnPurchaseItemRequestComplete_Parms;

    this->ProcessEvent(pFnOnPurchaseItemRequestComplete,
                       &OnPurchaseItemRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.PurchaseItem
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::PurchaseItem() {
    static UFunction* pFnPurchaseItem = NULL;

    if (!pFnPurchaseItem)
        pFnPurchaseItem = (UFunction*)UObject::GObjObjects()->Data[39762];

    UMcpUserInventoryManager_execPurchaseItem_Parms PurchaseItem_Parms;

    this->ProcessEvent(pFnPurchaseItem, &PurchaseItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.FindItemRequest
// [0x00420002]
// Parameters infos:

void UMcpUserInventoryManager::FindItemRequest() {
    static UFunction* pFnFindItemRequest = NULL;

    if (!pFnFindItemRequest)
        pFnFindItemRequest = (UFunction*)UObject::GObjObjects()->Data[39754];

    UMcpUserInventoryManager_execFindItemRequest_Parms FindItemRequest_Parms;

    this->ProcessEvent(pFnFindItemRequest, &FindItemRequest_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.FindSaveSlotRequest
// [0x00420002]
// Parameters infos:

void UMcpUserInventoryManager::FindSaveSlotRequest() {
    static UFunction* pFnFindSaveSlotRequest = NULL;

    if (!pFnFindSaveSlotRequest)
        pFnFindSaveSlotRequest =
            (UFunction*)UObject::GObjObjects()->Data[39747];

    UMcpUserInventoryManager_execFindSaveSlotRequest_Parms
        FindSaveSlotRequest_Parms;

    this->ProcessEvent(pFnFindSaveSlotRequest, &FindSaveSlotRequest_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryManager.FindSaveSlotIndex
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::FindSaveSlotIndex() {
    static UFunction* pFnFindSaveSlotIndex = NULL;

    if (!pFnFindSaveSlotIndex)
        pFnFindSaveSlotIndex = (UFunction*)UObject::GObjObjects()->Data[39742];

    UMcpUserInventoryManager_execFindSaveSlotIndex_Parms
        FindSaveSlotIndex_Parms;

    this->ProcessEvent(pFnFindSaveSlotIndex, &FindSaveSlotIndex_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.ParseSaveSlotList
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::ParseSaveSlotList() {
    static UFunction* pFnParseSaveSlotList = NULL;

    if (!pFnParseSaveSlotList)
        pFnParseSaveSlotList = (UFunction*)UObject::GObjObjects()->Data[39735];

    UMcpUserInventoryManager_execParseSaveSlotList_Parms
        ParseSaveSlotList_Parms;

    this->ProcessEvent(pFnParseSaveSlotList, &ParseSaveSlotList_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.ParseInventoryForSaveSlot
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::ParseInventoryForSaveSlot() {
    static UFunction* pFnParseInventoryForSaveSlot = NULL;

    if (!pFnParseInventoryForSaveSlot)
        pFnParseInventoryForSaveSlot =
            (UFunction*)UObject::GObjObjects()->Data[39717];

    UMcpUserInventoryManager_execParseInventoryForSaveSlot_Parms
        ParseInventoryForSaveSlot_Parms;

    this->ProcessEvent(pFnParseInventoryForSaveSlot,
                       &ParseInventoryForSaveSlot_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.GetInventoryItem
// [0x00420002]
// Parameters infos:

void UMcpUserInventoryManager::GetInventoryItem() {
    static UFunction* pFnGetInventoryItem = NULL;

    if (!pFnGetInventoryItem)
        pFnGetInventoryItem = (UFunction*)UObject::GObjObjects()->Data[39709];

    UMcpUserInventoryManager_execGetInventoryItem_Parms GetInventoryItem_Parms;

    this->ProcessEvent(pFnGetInventoryItem, &GetInventoryItem_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.GetInventoryItems
// [0x00420002]
// Parameters infos:

void UMcpUserInventoryManager::GetInventoryItems() {
    static UFunction* pFnGetInventoryItems = NULL;

    if (!pFnGetInventoryItems)
        pFnGetInventoryItems = (UFunction*)UObject::GObjObjects()->Data[39703];

    UMcpUserInventoryManager_execGetInventoryItems_Parms
        GetInventoryItems_Parms;

    this->ProcessEvent(pFnGetInventoryItems, &GetInventoryItems_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnQueryInventoryItemsRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnQueryInventoryItemsRequestComplete() {
    static UFunction* pFnOnQueryInventoryItemsRequestComplete = NULL;

    if (!pFnOnQueryInventoryItemsRequestComplete)
        pFnOnQueryInventoryItemsRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39695];

    UMcpUserInventoryManager_execOnQueryInventoryItemsRequestComplete_Parms
        OnQueryInventoryItemsRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryInventoryItemsRequestComplete,
                       &OnQueryInventoryItemsRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.QueryInventoryItems
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::QueryInventoryItems() {
    static UFunction* pFnQueryInventoryItems = NULL;

    if (!pFnQueryInventoryItems)
        pFnQueryInventoryItems =
            (UFunction*)UObject::GObjObjects()->Data[39688];

    UMcpUserInventoryManager_execQueryInventoryItems_Parms
        QueryInventoryItems_Parms;

    this->ProcessEvent(pFnQueryInventoryItems, &QueryInventoryItems_Parms,
                       NULL);
};

// Function IpDrv.McpUserInventoryManager.GetSaveSlotList
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::GetSaveSlotList() {
    static UFunction* pFnGetSaveSlotList = NULL;

    if (!pFnGetSaveSlotList)
        pFnGetSaveSlotList = (UFunction*)UObject::GObjObjects()->Data[39681];

    UMcpUserInventoryManager_execGetSaveSlotList_Parms GetSaveSlotList_Parms;

    this->ProcessEvent(pFnGetSaveSlotList, &GetSaveSlotList_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnQuerySaveSlotListRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnQuerySaveSlotListRequestComplete() {
    static UFunction* pFnOnQuerySaveSlotListRequestComplete = NULL;

    if (!pFnOnQuerySaveSlotListRequestComplete)
        pFnOnQuerySaveSlotListRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39674];

    UMcpUserInventoryManager_execOnQuerySaveSlotListRequestComplete_Parms
        OnQuerySaveSlotListRequestComplete_Parms;

    this->ProcessEvent(pFnOnQuerySaveSlotListRequestComplete,
                       &OnQuerySaveSlotListRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.QuerySaveSlotList
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::QuerySaveSlotList() {
    static UFunction* pFnQuerySaveSlotList = NULL;

    if (!pFnQuerySaveSlotList)
        pFnQuerySaveSlotList = (UFunction*)UObject::GObjObjects()->Data[39668];

    UMcpUserInventoryManager_execQuerySaveSlotList_Parms
        QuerySaveSlotList_Parms;

    this->ProcessEvent(pFnQuerySaveSlotList, &QuerySaveSlotList_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnDeleteSaveSlotRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnDeleteSaveSlotRequestComplete() {
    static UFunction* pFnOnDeleteSaveSlotRequestComplete = NULL;

    if (!pFnOnDeleteSaveSlotRequestComplete)
        pFnOnDeleteSaveSlotRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39661];

    UMcpUserInventoryManager_execOnDeleteSaveSlotRequestComplete_Parms
        OnDeleteSaveSlotRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteSaveSlotRequestComplete,
                       &OnDeleteSaveSlotRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.DeleteSaveSlot
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::DeleteSaveSlot() {
    static UFunction* pFnDeleteSaveSlot = NULL;

    if (!pFnDeleteSaveSlot)
        pFnDeleteSaveSlot = (UFunction*)UObject::GObjObjects()->Data[39654];

    UMcpUserInventoryManager_execDeleteSaveSlot_Parms DeleteSaveSlot_Parms;

    this->ProcessEvent(pFnDeleteSaveSlot, &DeleteSaveSlot_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.OnCreateSaveSlotRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserInventoryManager::OnCreateSaveSlotRequestComplete() {
    static UFunction* pFnOnCreateSaveSlotRequestComplete = NULL;

    if (!pFnOnCreateSaveSlotRequestComplete)
        pFnOnCreateSaveSlotRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39646];

    UMcpUserInventoryManager_execOnCreateSaveSlotRequestComplete_Parms
        OnCreateSaveSlotRequestComplete_Parms;

    this->ProcessEvent(pFnOnCreateSaveSlotRequestComplete,
                       &OnCreateSaveSlotRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserInventoryManager.CreateSaveSlot
// [0x00024002]
// Parameters infos:

void UMcpUserInventoryManager::CreateSaveSlot() {
    static UFunction* pFnCreateSaveSlot = NULL;

    if (!pFnCreateSaveSlot)
        pFnCreateSaveSlot = (UFunction*)UObject::GObjObjects()->Data[39638];

    UMcpUserInventoryManager_execCreateSaveSlot_Parms CreateSaveSlot_Parms;

    this->ProcessEvent(pFnCreateSaveSlot, &CreateSaveSlot_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.OnDeleteUserComplete
// [0x00120000]
// Parameters infos:

void UMcpUserManagerBase::OnDeleteUserComplete() {
    static UFunction* pFnOnDeleteUserComplete = NULL;

    if (!pFnOnDeleteUserComplete)
        pFnOnDeleteUserComplete =
            (UFunction*)UObject::GObjObjects()->Data[39946];

    UMcpUserManagerBase_execOnDeleteUserComplete_Parms
        OnDeleteUserComplete_Parms;

    this->ProcessEvent(pFnOnDeleteUserComplete, &OnDeleteUserComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.DeleteUser
// [0x00020000]
// Parameters infos:

void UMcpUserManagerBase::DeleteUser() {
    static UFunction* pFnDeleteUser = NULL;

    if (!pFnDeleteUser)
        pFnDeleteUser = (UFunction*)UObject::GObjObjects()->Data[39944];

    UMcpUserManagerBase_execDeleteUser_Parms DeleteUser_Parms;

    this->ProcessEvent(pFnDeleteUser, &DeleteUser_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.GetUser
// [0x00420000]
// Parameters infos:

void UMcpUserManagerBase::GetUser() {
    static UFunction* pFnGetUser = NULL;

    if (!pFnGetUser)
        pFnGetUser = (UFunction*)UObject::GObjObjects()->Data[39940];

    UMcpUserManagerBase_execGetUser_Parms GetUser_Parms;

    this->ProcessEvent(pFnGetUser, &GetUser_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.GetUsers
// [0x00420000]
// Parameters infos:

void UMcpUserManagerBase::GetUsers() {
    static UFunction* pFnGetUsers = NULL;

    if (!pFnGetUsers)
        pFnGetUsers = (UFunction*)UObject::GObjObjects()->Data[39937];

    UMcpUserManagerBase_execGetUsers_Parms GetUsers_Parms;

    this->ProcessEvent(pFnGetUsers, &GetUsers_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.OnQueryUsersComplete
// [0x00120000]
// Parameters infos:

void UMcpUserManagerBase::OnQueryUsersComplete() {
    static UFunction* pFnOnQueryUsersComplete = NULL;

    if (!pFnOnQueryUsersComplete)
        pFnOnQueryUsersComplete =
            (UFunction*)UObject::GObjObjects()->Data[39934];

    UMcpUserManagerBase_execOnQueryUsersComplete_Parms
        OnQueryUsersComplete_Parms;

    this->ProcessEvent(pFnOnQueryUsersComplete, &OnQueryUsersComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.QueryUsers
// [0x00420000]
// Parameters infos:

void UMcpUserManagerBase::QueryUsers() {
    static UFunction* pFnQueryUsers = NULL;

    if (!pFnQueryUsers)
        pFnQueryUsers = (UFunction*)UObject::GObjObjects()->Data[39931];

    UMcpUserManagerBase_execQueryUsers_Parms QueryUsers_Parms;

    this->ProcessEvent(pFnQueryUsers, &QueryUsers_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.QueryUser
// [0x00024000]
// Parameters infos:

void UMcpUserManagerBase::QueryUser() {
    static UFunction* pFnQueryUser = NULL;

    if (!pFnQueryUser)
        pFnQueryUser = (UFunction*)UObject::GObjObjects()->Data[39928];

    UMcpUserManagerBase_execQueryUser_Parms QueryUser_Parms;

    this->ProcessEvent(pFnQueryUser, &QueryUser_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.OnAuthenticateUserComplete
// [0x00120000]
// Parameters infos:

void UMcpUserManagerBase::OnAuthenticateUserComplete() {
    static UFunction* pFnOnAuthenticateUserComplete = NULL;

    if (!pFnOnAuthenticateUserComplete)
        pFnOnAuthenticateUserComplete =
            (UFunction*)UObject::GObjObjects()->Data[39923];

    UMcpUserManagerBase_execOnAuthenticateUserComplete_Parms
        OnAuthenticateUserComplete_Parms;

    this->ProcessEvent(pFnOnAuthenticateUserComplete,
                       &OnAuthenticateUserComplete_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.AuthenticateUserMcp
// [0x00020000]
// Parameters infos:

void UMcpUserManagerBase::AuthenticateUserMcp() {
    static UFunction* pFnAuthenticateUserMcp = NULL;

    if (!pFnAuthenticateUserMcp)
        pFnAuthenticateUserMcp =
            (UFunction*)UObject::GObjObjects()->Data[39919];

    UMcpUserManagerBase_execAuthenticateUserMcp_Parms AuthenticateUserMcp_Parms;

    this->ProcessEvent(pFnAuthenticateUserMcp, &AuthenticateUserMcp_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.AuthenticateUserFacebook
// [0x00020000]
// Parameters infos:

void UMcpUserManagerBase::AuthenticateUserFacebook() {
    static UFunction* pFnAuthenticateUserFacebook = NULL;

    if (!pFnAuthenticateUserFacebook)
        pFnAuthenticateUserFacebook =
            (UFunction*)UObject::GObjObjects()->Data[39915];

    UMcpUserManagerBase_execAuthenticateUserFacebook_Parms
        AuthenticateUserFacebook_Parms;

    this->ProcessEvent(pFnAuthenticateUserFacebook,
                       &AuthenticateUserFacebook_Parms, NULL);
};

// Function IpDrv.McpUserManagerBase.OnRegisterUserComplete
// [0x00120000]
// Parameters infos:

void UMcpUserManagerBase::OnRegisterUserComplete() {
    static UFunction* pFnOnRegisterUserComplete = NULL;

    if (!pFnOnRegisterUserComplete)
        pFnOnRegisterUserComplete =
            (UFunction*)UObject::GObjObjects()->Data[39911];

    UMcpUserManagerBase_execOnRegisterUserComplete_Parms
        OnRegisterUserComplete_Parms;

    this->ProcessEvent(pFnOnRegisterUserComplete, &OnRegisterUserComplete_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.RegisterUserFacebook
// [0x00020000]
// Parameters infos:

void UMcpUserManagerBase::RegisterUserFacebook() {
    static UFunction* pFnRegisterUserFacebook = NULL;

    if (!pFnRegisterUserFacebook)
        pFnRegisterUserFacebook =
            (UFunction*)UObject::GObjObjects()->Data[39908];

    UMcpUserManagerBase_execRegisterUserFacebook_Parms
        RegisterUserFacebook_Parms;

    this->ProcessEvent(pFnRegisterUserFacebook, &RegisterUserFacebook_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.RegisterUserGenerated
// [0x00020000]
// Parameters infos:

void UMcpUserManagerBase::RegisterUserGenerated() {
    static UFunction* pFnRegisterUserGenerated = NULL;

    if (!pFnRegisterUserGenerated)
        pFnRegisterUserGenerated =
            (UFunction*)UObject::GObjObjects()->Data[39907];

    UMcpUserManagerBase_execRegisterUserGenerated_Parms
        RegisterUserGenerated_Parms;

    this->ProcessEvent(pFnRegisterUserGenerated, &RegisterUserGenerated_Parms,
                       NULL);
};

// Function IpDrv.McpUserManagerBase.CreateInstance
// [0x00022003] ( FUNC_Final )
// Parameters infos:

void UMcpUserManagerBase::CreateInstance() {
    static UFunction* pFnCreateInstance = NULL;

    if (!pFnCreateInstance)
        pFnCreateInstance = (UFunction*)UObject::GObjObjects()->Data[39903];

    UMcpUserManagerBase_execCreateInstance_Parms CreateInstance_Parms;

    this->ProcessEvent(pFnCreateInstance, &CreateInstance_Parms, NULL);
};

// Function IpDrv.McpUserManager.OnDeleteUserRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserManager::OnDeleteUserRequestComplete() {
    static UFunction* pFnOnDeleteUserRequestComplete = NULL;

    if (!pFnOnDeleteUserRequestComplete)
        pFnOnDeleteUserRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[40068];

    UMcpUserManager_execOnDeleteUserRequestComplete_Parms
        OnDeleteUserRequestComplete_Parms;

    this->ProcessEvent(pFnOnDeleteUserRequestComplete,
                       &OnDeleteUserRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserManager.DeleteUser
// [0x00020002]
// Parameters infos:

void UMcpUserManager::DeleteUser() {
    static UFunction* pFnDeleteUser = NULL;

    if (!pFnDeleteUser)
        pFnDeleteUser = (UFunction*)UObject::GObjObjects()->Data[40063];

    UMcpUserManager_execDeleteUser_Parms DeleteUser_Parms;

    this->ProcessEvent(pFnDeleteUser, &DeleteUser_Parms, NULL);
};

// Function IpDrv.McpUserManager.GetUser
// [0x00420002]
// Parameters infos:

void UMcpUserManager::GetUser() {
    static UFunction* pFnGetUser = NULL;

    if (!pFnGetUser)
        pFnGetUser = (UFunction*)UObject::GObjObjects()->Data[40058];

    UMcpUserManager_execGetUser_Parms GetUser_Parms;

    this->ProcessEvent(pFnGetUser, &GetUser_Parms, NULL);
};

// Function IpDrv.McpUserManager.GetUsers
// [0x00420002]
// Parameters infos:

void UMcpUserManager::GetUsers() {
    static UFunction* pFnGetUsers = NULL;

    if (!pFnGetUsers)
        pFnGetUsers = (UFunction*)UObject::GObjObjects()->Data[40055];

    UMcpUserManager_execGetUsers_Parms GetUsers_Parms;

    this->ProcessEvent(pFnGetUsers, &GetUsers_Parms, NULL);
};

// Function IpDrv.McpUserManager.OnQueryUsersRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserManager::OnQueryUsersRequestComplete() {
    static UFunction* pFnOnQueryUsersRequestComplete = NULL;

    if (!pFnOnQueryUsersRequestComplete)
        pFnOnQueryUsersRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[40048];

    UMcpUserManager_execOnQueryUsersRequestComplete_Parms
        OnQueryUsersRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryUsersRequestComplete,
                       &OnQueryUsersRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserManager.ParseUsers
// [0x00080002]
// Parameters infos:

void UMcpUserManager::ParseUsers() {
    static UFunction* pFnParseUsers = NULL;

    if (!pFnParseUsers)
        pFnParseUsers = (UFunction*)UObject::GObjObjects()->Data[40042];

    UMcpUserManager_execParseUsers_Parms ParseUsers_Parms;

    this->ProcessEvent(pFnParseUsers, &ParseUsers_Parms, NULL);
};

// Function IpDrv.McpUserManager.QueryUsers
// [0x00420002]
// Parameters infos:

void UMcpUserManager::QueryUsers() {
    static UFunction* pFnQueryUsers = NULL;

    if (!pFnQueryUsers)
        pFnQueryUsers = (UFunction*)UObject::GObjObjects()->Data[40034];

    UMcpUserManager_execQueryUsers_Parms QueryUsers_Parms;

    this->ProcessEvent(pFnQueryUsers, &QueryUsers_Parms, NULL);
};

// Function IpDrv.McpUserManager.OnQueryUserRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserManager::OnQueryUserRequestComplete() {
    static UFunction* pFnOnQueryUserRequestComplete = NULL;

    if (!pFnOnQueryUserRequestComplete)
        pFnOnQueryUserRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[40026];

    UMcpUserManager_execOnQueryUserRequestComplete_Parms
        OnQueryUserRequestComplete_Parms;

    this->ProcessEvent(pFnOnQueryUserRequestComplete,
                       &OnQueryUserRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserManager.QueryUser
// [0x00024002]
// Parameters infos:

void UMcpUserManager::QueryUser() {
    static UFunction* pFnQueryUser = NULL;

    if (!pFnQueryUser)
        pFnQueryUser = (UFunction*)UObject::GObjObjects()->Data[40020];

    UMcpUserManager_execQueryUser_Parms QueryUser_Parms;

    this->ProcessEvent(pFnQueryUser, &QueryUser_Parms, NULL);
};

// Function IpDrv.McpUserManager.OnAuthenticateUserRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserManager::OnAuthenticateUserRequestComplete() {
    static UFunction* pFnOnAuthenticateUserRequestComplete = NULL;

    if (!pFnOnAuthenticateUserRequestComplete)
        pFnOnAuthenticateUserRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[40010];

    UMcpUserManager_execOnAuthenticateUserRequestComplete_Parms
        OnAuthenticateUserRequestComplete_Parms;

    this->ProcessEvent(pFnOnAuthenticateUserRequestComplete,
                       &OnAuthenticateUserRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserManager.AuthenticateUserMcp
// [0x00020002]
// Parameters infos:

void UMcpUserManager::AuthenticateUserMcp() {
    static UFunction* pFnAuthenticateUserMcp = NULL;

    if (!pFnAuthenticateUserMcp)
        pFnAuthenticateUserMcp =
            (UFunction*)UObject::GObjObjects()->Data[40003];

    UMcpUserManager_execAuthenticateUserMcp_Parms AuthenticateUserMcp_Parms;

    this->ProcessEvent(pFnAuthenticateUserMcp, &AuthenticateUserMcp_Parms,
                       NULL);
};

// Function IpDrv.McpUserManager.AuthenticateUserFacebook
// [0x00020002]
// Parameters infos:

void UMcpUserManager::AuthenticateUserFacebook() {
    static UFunction* pFnAuthenticateUserFacebook = NULL;

    if (!pFnAuthenticateUserFacebook)
        pFnAuthenticateUserFacebook =
            (UFunction*)UObject::GObjObjects()->Data[39996];

    UMcpUserManager_execAuthenticateUserFacebook_Parms
        AuthenticateUserFacebook_Parms;

    this->ProcessEvent(pFnAuthenticateUserFacebook,
                       &AuthenticateUserFacebook_Parms, NULL);
};

// Function IpDrv.McpUserManager.OnRegisterUserRequestComplete
// [0x00020002]
// Parameters infos:

void UMcpUserManager::OnRegisterUserRequestComplete() {
    static UFunction* pFnOnRegisterUserRequestComplete = NULL;

    if (!pFnOnRegisterUserRequestComplete)
        pFnOnRegisterUserRequestComplete =
            (UFunction*)UObject::GObjObjects()->Data[39987];

    UMcpUserManager_execOnRegisterUserRequestComplete_Parms
        OnRegisterUserRequestComplete_Parms;

    this->ProcessEvent(pFnOnRegisterUserRequestComplete,
                       &OnRegisterUserRequestComplete_Parms, NULL);
};

// Function IpDrv.McpUserManager.ParseUser
// [0x00080002]
// Parameters infos:

void UMcpUserManager::ParseUser() {
    static UFunction* pFnParseUser = NULL;

    if (!pFnParseUser)
        pFnParseUser = (UFunction*)UObject::GObjObjects()->Data[39981];

    UMcpUserManager_execParseUser_Parms ParseUser_Parms;

    this->ProcessEvent(pFnParseUser, &ParseUser_Parms, NULL);
};

// Function IpDrv.McpUserManager.RegisterUserFacebook
// [0x00020002]
// Parameters infos:

void UMcpUserManager::RegisterUserFacebook() {
    static UFunction* pFnRegisterUserFacebook = NULL;

    if (!pFnRegisterUserFacebook)
        pFnRegisterUserFacebook =
            (UFunction*)UObject::GObjObjects()->Data[39975];

    UMcpUserManager_execRegisterUserFacebook_Parms RegisterUserFacebook_Parms;

    this->ProcessEvent(pFnRegisterUserFacebook, &RegisterUserFacebook_Parms,
                       NULL);
};

// Function IpDrv.McpUserManager.RegisterUserGenerated
// [0x00020002]
// Parameters infos:

void UMcpUserManager::RegisterUserGenerated() {
    static UFunction* pFnRegisterUserGenerated = NULL;

    if (!pFnRegisterUserGenerated)
        pFnRegisterUserGenerated =
            (UFunction*)UObject::GObjObjects()->Data[39971];

    UMcpUserManager_execRegisterUserGenerated_Parms RegisterUserGenerated_Parms;

    this->ProcessEvent(pFnRegisterUserGenerated, &RegisterUserGenerated_Parms,
                       NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.DebugDraw
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::DebugDraw() {
    static UFunction* pFnDebugDraw = NULL;

    if (!pFnDebugDraw)
        pFnDebugDraw = (UFunction*)UObject::GObjObjects()->Data[41081];

    UOnlineImageDownloaderWeb_execDebugDraw_Parms DebugDraw_Parms;

    this->ProcessEvent(pFnDebugDraw, &DebugDraw_Parms, NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.OnDownloadComplete
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UOnlineImageDownloaderWeb::OnDownloadComplete() {
    static UFunction* pFnOnDownloadComplete = NULL;

    if (!pFnOnDownloadComplete)
        pFnOnDownloadComplete = (UFunction*)UObject::GObjObjects()->Data[41074];

    UOnlineImageDownloaderWeb_execOnDownloadComplete_Parms
        OnDownloadComplete_Parms;

    this->ProcessEvent(pFnOnDownloadComplete, &OnDownloadComplete_Parms, NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.DownloadNextImage
// [0x00040003] ( FUNC_Final )
// Parameters infos:

void UOnlineImageDownloaderWeb::DownloadNextImage() {
    static UFunction* pFnDownloadNextImage = NULL;

    if (!pFnDownloadNextImage)
        pFnDownloadNextImage = (UFunction*)UObject::GObjObjects()->Data[41071];

    UOnlineImageDownloaderWeb_execDownloadNextImage_Parms
        DownloadNextImage_Parms;

    this->ProcessEvent(pFnDownloadNextImage, &DownloadNextImage_Parms, NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.ClearAllDownloads
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::ClearAllDownloads() {
    static UFunction* pFnClearAllDownloads = NULL;

    if (!pFnClearAllDownloads)
        pFnClearAllDownloads = (UFunction*)UObject::GObjObjects()->Data[41070];

    UOnlineImageDownloaderWeb_execClearAllDownloads_Parms
        ClearAllDownloads_Parms;

    this->ProcessEvent(pFnClearAllDownloads, &ClearAllDownloads_Parms, NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.ClearDownloads
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::ClearDownloads() {
    static UFunction* pFnClearDownloads = NULL;

    if (!pFnClearDownloads)
        pFnClearDownloads = (UFunction*)UObject::GObjObjects()->Data[41066];

    UOnlineImageDownloaderWeb_execClearDownloads_Parms ClearDownloads_Parms;

    this->ProcessEvent(pFnClearDownloads, &ClearDownloads_Parms, NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.GetNumPendingDownloads
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::GetNumPendingDownloads() {
    static UFunction* pFnGetNumPendingDownloads = NULL;

    if (!pFnGetNumPendingDownloads)
        pFnGetNumPendingDownloads =
            (UFunction*)UObject::GObjObjects()->Data[41062];

    UOnlineImageDownloaderWeb_execGetNumPendingDownloads_Parms
        GetNumPendingDownloads_Parms;

    this->ProcessEvent(pFnGetNumPendingDownloads, &GetNumPendingDownloads_Parms,
                       NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.RequestOnlineImages
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::RequestOnlineImages() {
    static UFunction* pFnRequestOnlineImages = NULL;

    if (!pFnRequestOnlineImages)
        pFnRequestOnlineImages =
            (UFunction*)UObject::GObjObjects()->Data[41056];

    UOnlineImageDownloaderWeb_execRequestOnlineImages_Parms
        RequestOnlineImages_Parms;

    this->ProcessEvent(pFnRequestOnlineImages, &RequestOnlineImages_Parms,
                       NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.GetOnlineImageTexture
// [0x00020002]
// Parameters infos:

void UOnlineImageDownloaderWeb::GetOnlineImageTexture() {
    static UFunction* pFnGetOnlineImageTexture = NULL;

    if (!pFnGetOnlineImageTexture)
        pFnGetOnlineImageTexture =
            (UFunction*)UObject::GObjObjects()->Data[41052];

    UOnlineImageDownloaderWeb_execGetOnlineImageTexture_Parms
        GetOnlineImageTexture_Parms;

    this->ProcessEvent(pFnGetOnlineImageTexture, &GetOnlineImageTexture_Parms,
                       NULL);
};

// Function IpDrv.OnlineImageDownloaderWeb.OnOnlineImageDownloaded
// [0x00120000]
// Parameters infos:

void UOnlineImageDownloaderWeb::OnOnlineImageDownloaded() {
    static UFunction* pFnOnOnlineImageDownloaded = NULL;

    if (!pFnOnOnlineImageDownloaded)
        pFnOnOnlineImageDownloaded =
            (UFunction*)UObject::GObjObjects()->Data[41050];

    UOnlineImageDownloaderWeb_execOnOnlineImageDownloaded_Parms
        OnOnlineImageDownloaded_Parms;

    this->ProcessEvent(pFnOnOnlineImageDownloaded,
                       &OnOnlineImageDownloaded_Parms, NULL);
};

// Function IpDrv.WebConnection.IsHanging
// [0x00020003] ( FUNC_Final )
// Parameters infos:

void AWebConnection::IsHanging() {
    static UFunction* pFnIsHanging = NULL;

    if (!pFnIsHanging)
        pFnIsHanging = (UFunction*)UObject::GObjObjects()->Data[41674];

    AWebConnection_execIsHanging_Parms IsHanging_Parms;

    this->ProcessEvent(pFnIsHanging, &IsHanging_Parms, NULL);
};

// Function IpDrv.WebConnection.Cleanup
// [0x00020002]
// Parameters infos:

void AWebConnection::Cleanup() {
    static UFunction* pFnCleanup = NULL;

    if (!pFnCleanup)
        pFnCleanup = (UFunction*)UObject::GObjObjects()->Data[41673];

    AWebConnection_execCleanup_Parms Cleanup_Parms;

    this->ProcessEvent(pFnCleanup, &Cleanup_Parms, NULL);
};

// Function IpDrv.WebConnection.CheckRawBytes
// [0x00020002]
// Parameters infos:

void AWebConnection::CheckRawBytes() {
    static UFunction* pFnCheckRawBytes = NULL;

    if (!pFnCheckRawBytes)
        pFnCheckRawBytes = (UFunction*)UObject::GObjObjects()->Data[41672];

    AWebConnection_execCheckRawBytes_Parms CheckRawBytes_Parms;

    this->ProcessEvent(pFnCheckRawBytes, &CheckRawBytes_Parms, NULL);
};

// Function IpDrv.WebConnection.EndOfHeaders
// [0x00020002]
// Parameters infos:

void AWebConnection::EndOfHeaders() {
    static UFunction* pFnEndOfHeaders = NULL;

    if (!pFnEndOfHeaders)
        pFnEndOfHeaders = (UFunction*)UObject::GObjObjects()->Data[41671];

    AWebConnection_execEndOfHeaders_Parms EndOfHeaders_Parms;

    this->ProcessEvent(pFnEndOfHeaders, &EndOfHeaders_Parms, NULL);
};

// Function IpDrv.WebConnection.CreateResponseObject
// [0x00020002]
// Parameters infos:

void AWebConnection::CreateResponseObject() {
    static UFunction* pFnCreateResponseObject = NULL;

    if (!pFnCreateResponseObject)
        pFnCreateResponseObject =
            (UFunction*)UObject::GObjObjects()->Data[41669];

    AWebConnection_execCreateResponseObject_Parms CreateResponseObject_Parms;

    this->ProcessEvent(pFnCreateResponseObject, &CreateResponseObject_Parms,
                       NULL);
};

// Function IpDrv.WebConnection.ProcessPost
// [0x00020002]
// Parameters infos:

void AWebConnection::ProcessPost() {
    static UFunction* pFnProcessPost = NULL;

    if (!pFnProcessPost)
        pFnProcessPost = (UFunction*)UObject::GObjObjects()->Data[41666];

    AWebConnection_execProcessPost_Parms ProcessPost_Parms;

    this->ProcessEvent(pFnProcessPost, &ProcessPost_Parms, NULL);
};

// Function IpDrv.WebConnection.ProcessGet
// [0x00020002]
// Parameters infos:

void AWebConnection::ProcessGet() {
    static UFunction* pFnProcessGet = NULL;

    if (!pFnProcessGet)
        pFnProcessGet = (UFunction*)UObject::GObjObjects()->Data[41663];

    AWebConnection_execProcessGet_Parms ProcessGet_Parms;

    this->ProcessEvent(pFnProcessGet, &ProcessGet_Parms, NULL);
};

// Function IpDrv.WebConnection.ProcessHead
// [0x00020002]
// Parameters infos:

void AWebConnection::ProcessHead() {
    static UFunction* pFnProcessHead = NULL;

    if (!pFnProcessHead)
        pFnProcessHead = (UFunction*)UObject::GObjObjects()->Data[41661];

    AWebConnection_execProcessHead_Parms ProcessHead_Parms;

    this->ProcessEvent(pFnProcessHead, &ProcessHead_Parms, NULL);
};

// Function IpDrv.WebConnection.ReceivedLine
// [0x00020002]
// Parameters infos:

void AWebConnection::ReceivedLine() {
    static UFunction* pFnReceivedLine = NULL;

    if (!pFnReceivedLine)
        pFnReceivedLine = (UFunction*)UObject::GObjObjects()->Data[41659];

    AWebConnection_execReceivedLine_Parms ReceivedLine_Parms;

    this->ProcessEvent(pFnReceivedLine, &ReceivedLine_Parms, NULL);
};

// Function IpDrv.WebConnection.ReceivedText
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebConnection::eventReceivedText() {
    static UFunction* pFnReceivedText = NULL;

    if (!pFnReceivedText)
        pFnReceivedText = (UFunction*)UObject::GObjObjects()->Data[41655];

    AWebConnection_eventReceivedText_Parms ReceivedText_Parms;

    this->ProcessEvent(pFnReceivedText, &ReceivedText_Parms, NULL);
};

// Function IpDrv.WebConnection.Timer
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebConnection::eventTimer() {
    static UFunction* pFnTimer = NULL;

    if (!pFnTimer) pFnTimer = (UFunction*)UObject::GObjObjects()->Data[41654];

    AWebConnection_eventTimer_Parms Timer_Parms;

    this->ProcessEvent(pFnTimer, &Timer_Parms, NULL);
};

// Function IpDrv.WebConnection.Closed
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebConnection::eventClosed() {
    static UFunction* pFnClosed = NULL;

    if (!pFnClosed) pFnClosed = (UFunction*)UObject::GObjObjects()->Data[41653];

    AWebConnection_eventClosed_Parms Closed_Parms;

    this->ProcessEvent(pFnClosed, &Closed_Parms, NULL);
};

// Function IpDrv.WebConnection.Accepted
// [0x00020802] ( FUNC_Event )
// Parameters infos:

void AWebConnection::eventAccepted() {
    static UFunction* pFnAccepted = NULL;

    if (!pFnAccepted)
        pFnAccepted = (UFunction*)UObject::GObjObjects()->Data[41652];

    AWebConnection_eventAccepted_Parms Accepted_Parms;

    this->ProcessEvent(pFnAccepted, &Accepted_Parms, NULL);
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif